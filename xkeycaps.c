/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1995, 1996, 1997, 1998 
 * Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

#include "version.h"

#include <stdio.h>
#include <ctype.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>
#include <X11/Xaw/Simple.h>
#include <X11/Xaw/Paned.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Box.h>
#include <X11/Xmu/Error.h>

#include "KbdWidgetP.h"
#include "KeyWidgetP.h"

#include "xkeycaps.h"

char *progname;
char *short_version;

#ifdef __STDC__
# define P(x)x
#else /* !__STDC__ */
# define P(x)()
#endif


static char *xkeycapsDefaults[] = {
# include "XKeyCaps_ad.h"
 0
};


static XrmOptionDescRec options [] = {
  { "-foreground",	"*Foreground",			XrmoptionSepArg, 0 },
  { "-background",	"*Background",			XrmoptionSepArg, 0 },
  { "-fg",		"*Foreground",			XrmoptionSepArg, 0 },
  { "-bg",		"*Background",			XrmoptionSepArg, 0 },
  { "-gutterwidth",	"*Keyboard.Key.gutterWidth",	XrmoptionSepArg, 0 },
  { "-gw",		"*Keyboard.Key.gutterWidth",	XrmoptionSepArg, 0 },
  { "-font",		"*Keyboard.Key.keycapFont",	XrmoptionSepArg, 0 },
  { "-fn",		"*Keyboard.Key.keycapFont",	XrmoptionSepArg, 0 },
#ifdef HAVE_XTRAP
  { "-xtrap",		"*useXTrap",			XrmoptionNoArg, "on" },
  { "-use-xtrap",	"*useXTrap",			XrmoptionNoArg, "on" },
  { "-use_xtrap",	"*useXTrap",			XrmoptionNoArg, "on" },
  { "-no-xtrap",	"*useXTrap",			XrmoptionNoArg,"off" },
  { "-no_xtrap",	"*useXTrap",			XrmoptionNoArg,"off" },
#endif
  { "-keyboard",	"*Keyboard.keyboard",		XrmoptionSepArg, 0 },
  { "-kbd",		"*Keyboard.keyboard",		XrmoptionSepArg, 0 }
};



static KeyboardWidget make_keyboard P((Widget box, Widget box2,
				       struct info_labels *info,
				       const char *name));
static void maybe_relabel_window P((KeyboardWidget keyboard));
static KeyboardWidget xkeycaps_main_loop P((KeyboardWidget keyboard,
					    XtAppContext app));


Window XSendEvent_BadWindow = 0;

static int
#ifdef __STDC__
xkeycaps_error_handler (Display *dpy, XErrorEvent *error)
#else /* ! __STDC__ */
xkeycaps_error_handler (dpy, error)
     Display *dpy;
     XErrorEvent *error;
#endif /* ! __STDC__ */
{
  switch (error->request_code)
    {
    case X_GetKeyboardMapping:
      return 0;
    case X_SendEvent:
      if (error->error_code == BadWindow && !XSendEvent_BadWindow)
	XSendEvent_BadWindow = error->resourceid;
      else
	XmuPrintDefaultErrorMessage (dpy, error, stderr);
      return 0;
    default:
      XmuPrintDefaultErrorMessage (dpy, error, stderr);
      exit (-1);
    }
}


static KeyboardWidget
#ifdef __STDC__
make_keyboard (Widget box, Widget box2, struct info_labels *info,
	       const char *name)
#else /* ! __STDC__ */
make_keyboard (box, box2, info, name)
     Widget box, box2;
     struct info_labels *info;
     const char *name;
#endif /* ! __STDC__ */
{
  Arg av[20];
  int ac = 0;
  KeyboardWidget keyboard;
  XtSetArg (av[ac], XtNfromVert, box2); ac++;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainRight); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainBottom); ac++;
  if (name) XtSetArg (av[ac], "keyboard", name), ac++;
  keyboard = (KeyboardWidget)
    XtCreateManagedWidget ("keyboard", keyboardWidgetClass, box, av, ac);
  keyboard->keyboard.label_widgets = info;
  keyboard->keyboard.key_menus = make_key_menus ((KeyboardWidget *) &keyboard);
  return keyboard;
}


static void
#ifdef __STDC__
maybe_relabel_window (KeyboardWidget keyboard)
#else /* ! __STDC__ */
maybe_relabel_window (keyboard)
     KeyboardWidget keyboard;
#endif /* ! __STDC__ */
{
  /* If the user hasn't specified the -title option, set the window title
     to be something more informative.
   */
  Widget toplevel = (Widget) keyboard;
  char buf1 [100], buf2 [100];
  XrmValue value;
  char *type;
  XrmDatabase db = XtDatabase (XtDisplay (keyboard));
  char *name, *class;
  while (XtParent (toplevel)) toplevel = XtParent (toplevel);
  XtGetApplicationNameAndClass (XtDisplay (keyboard), &name, &class);
  sprintf (buf1, "%s.title", name);
  sprintf (buf2, "%s.Title", class);
  if (XrmGetResource (db, buf1, buf2, &type, &value)) return;
  sprintf (buf1, "%s; %s%s%s keyboard", class,
	   keyboard->keyboard.vendor,
	   (keyboard->keyboard.kbd_style ? " " : ""),
	   keyboard->keyboard.kbd_style);
  XStoreName (XtDisplay (toplevel), XtWindow (toplevel), buf1);
}


/* Kludge to tell the main loop to reset some variables... */
KeyboardWidget new_kbd_selected = 0;

void
#ifdef __STDC__
replace_keyboard (KeyboardWidget keyboard, const char *name)
#else /* ! __STDC__ */
replace_keyboard (keyboard, name)
     KeyboardWidget keyboard;
     const char *name;
#endif /* ! __STDC__ */
{
  /* Doing this seems to leak about 8k each time, but I really don't care. */
  Widget box, box2;
  KeyboardWidget new_kbd;
  Widget toplevel;
  Arg av[20];
  int ac = 0;
  toplevel = box = XtParent (keyboard);
  while (XtParent (toplevel)) toplevel = XtParent (toplevel);
  box2 = 0;
  XtSetArg (av[ac], XtNfromVert, &box2); ac++;
  XtGetValues ((Widget) keyboard, av, ac);
  /*  if (! box2) abort ();*  #### wtf? */
  new_kbd = make_keyboard (box, box2, keyboard->keyboard.label_widgets, name);
  XtUnmanageChild ((Widget) keyboard);
  XtDestroyWidget ((Widget) keyboard);
  new_kbd_selected = new_kbd; /* kludge... */
  XtSetKeyboardFocus (toplevel, (Widget) new_kbd);
  maybe_relabel_window (new_kbd);
}


void
#ifdef __STDC__
xkeycaps_DispatchEvent_hook (KeyboardWidget keyboard, XEvent *event)
#else /* ! __STDC__ */
xkeycaps_DispatchEvent_hook (keyboard, event)
     KeyboardWidget keyboard;
     XEvent *event;
#endif /* ! __STDC__ */
{
  /* MappingNotify and KeymapNotify events don't have an associated
     window, so there's no way to register an event-handler function
     for one of these with Xt.  Lose, lose.
   */
  if (event->xany.type == KeymapNotify)
    keyboard_handle_keymap_notify ((Widget) keyboard, 0, event, 0);
  else if (event->xany.type == MappingNotify)
    keyboard_handle_mapping_notify ((Widget) keyboard, 0, event, 0);
}


static KeyboardWidget
#ifdef __STDC__
xkeycaps_main_loop (KeyboardWidget keyboard, XtAppContext app)
#else /* ! __STDC__ */
xkeycaps_main_loop (keyboard, app)
     KeyboardWidget keyboard;
     XtAppContext app;
#endif /* ! __STDC__ */
{
  XEvent event;
  while (1)
    {
      XtAppNextEvent (app, &event);
      xkeycaps_DispatchEvent_hook (keyboard, &event);
      XtDispatchEvent (&event);

      /* Kludge to prevent us from using a freed keyboard...
	 I think we had actually been allocating the second one out
	 of the *same space* as the first one and not losing?? */
      if (new_kbd_selected)
	return new_kbd_selected;
    }
}

int
#ifdef __STDC__
main (int argc, char **argv)
#else /* ! __STDC__ */
main (argc, argv)
     int argc;
     char **argv;
#endif /* ! __STDC__ */
{
  char *class = "XKeyCaps";
  XtAppContext app;
  Widget toplevel, box, box2, buttons;
  struct info_labels *info;
  KeyboardWidget keyboard = 0;
  Arg av [20];
  int ac = 0;
  char version_buf [255];

  {
    int index;
    int i2 = strlen (version) - 3;
    char *v2 = (char *) malloc (i2);
    memcpy (v2, version+4, i2);
    version = v2;
    for (index = 0;; index++)
      if (!strncmp ("Copyright (c)", version+index, 13)) break;
    for (v2 = version+index+13; *v2; v2++)
      if (*v2 == '(') *v2 = '<';
      else if (*v2 == ')') *v2 = '>';
    memcpy (version_buf, version, i2 = index);
    version_buf [index] = '\251';
    strcpy (version_buf + index + 1, version + index + 13);
    for (;; index++)
      if (isdigit(version[index]) && isdigit(version[index+1]) &&
	  isdigit(version[index+2]) && isdigit(version[index+3]) &&
	  version[index+4] != ',')
	break;
    short_version = (char *) malloc(i2 + 14 + strlen (version + index) + 1);
    memcpy (short_version, version, i2 + 14);
    strcpy (short_version +         i2 + 14, version + index);
  }

  toplevel = XtAppInitialize (&app, class, options, XtNumber (options),
			      &argc, argv, xkeycapsDefaults, NULL, 0);

  XtGetApplicationNameAndClass (XtDisplay (toplevel), &progname, &class);

  if (argc > 1)
    {
      int ok = (!strcmp (argv[1], "-help") ||
		!strcmp (argv[1], "--help") ||
		!strcmp (argv[1], "-version") ||
		!strcmp (argv[1], "--version") ||
		!strcmp (argv[1], "-v") ||
		!strcmp (argv[1], "-h"));
      FILE *out = (ok ? stdout : stderr);
      if (!ok)
	fprintf (out, "%s: unknown option %s\n", progname, argv [1]);

      fprintf (out, "\n%s\n", short_version);
      fprintf (out, "\n\
	Use the -keyboard (or -kbd) option to specify a keyboard,\n\
	or use the `Select Keyboard' dialog box.  Use the -help\n\
	option to list recognised arguments to -kbd.  See the man\n\
	page for more details.\n\n\
	For updates, check http://www.jwz.org/xkeycaps/\n\n");

      if (!ok)
	{
	  exit(-1);
	}
      else
	{
	  fprintf(out, "Recognised keyboard names:\n\n");
	  print_kbd_choices();
	  exit(0);
	}
    }

  create_icon_pixmaps (XtDisplay (toplevel));

  ac = 0;
  box = XtCreateManagedWidget ("vertical", panedWidgetClass, toplevel, av, ac);
  ac = 0;
  XtSetArg (av[ac], XtNorientation, "horizontal"); ac++;
  box2 = XtCreateManagedWidget ("horizontal", panedWidgetClass, box, av, ac);
  buttons = make_command_widgets (box2, (Widget *) &keyboard);
  info = make_info_widget (box2, buttons);

  keyboard = make_keyboard (box, box2, info, 0);

  XtAddEventHandler ((Widget) keyboard, KeymapStateMask, False,
		     keyboard_handle_keymap_notify, 0);
  XtAddEventHandler ((Widget) keyboard, 0, True,
		     keyboard_handle_mapping_notify, 0);
  XtRealizeWidget (toplevel);

  XtSetKeyboardFocus (toplevel, (Widget) keyboard);
  maybe_relabel_window (keyboard);
  XSetErrorHandler (xkeycaps_error_handler);

  message (keyboard, "");
  message2 (keyboard, version_buf);

  if (choose_kbd_dubious_p)
    pop_up_kbd_dbox (toplevel, (void *) &keyboard, 0);

#ifdef HAVE_XTRAP
  if (keyboard->keyboard.trap_data)
    xkeycaps_xtrap_main_loop (keyboard, app);
  else
#endif
    while (1)
      keyboard = xkeycaps_main_loop (keyboard, app);
}
