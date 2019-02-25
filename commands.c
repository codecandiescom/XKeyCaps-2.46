/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1997, 1998
 * by Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

#if defined(__STDC__) && defined(__unix)
#include <unistd.h>
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>

#ifndef NO_UNAME
# include <sys/utsname.h>
#endif

#include <X11/X.h>
#include <X11/Xos.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>

#include <X11/StringDefs.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>

#include <X11/Xmu/WinUtil.h>
#include <X11/Xmu/Error.h>

#include <X11/Xaw/Simple.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/Paned.h>
#include <X11/Xaw/List.h>
#include <X11/Xaw/Viewport.h>
#include <X11/Xaw/Dialog.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Toggle.h>
#include <X11/Xaw/SimpleMenu.h>
#include <X11/Xaw/SmeBSB.h>
#include <X11/Xaw/MenuButton.h>
#include <X11/Xaw/Scrollbar.h>

#ifdef XAWBUG
/* At some point it seemed like the Toggle widget (really, the Command widget)
   didn't provide a GetValues-hook to access the "state" property, so we had
   to access that slot directly.  Well, this isn't the case with MIT R5 pl25,
   or with OpenWindows 3.0, so let's try living without it now.
 */
# include <X11/IntrinsicP.h>
# include <X11/CoreP.h>
# include <X11/Xaw/SimpleP.h>
# include <X11/Xaw/CommandP.h>
#endif /* XAWBUG */

#include "KbdWidgetP.h"
#include "KeyWidgetP.h"

#include "xkeycaps.h"

#include "kbddef.h"

#include "vroot.h"	/* This is standard in R5 but not R4 */

#ifndef NO_PWD
#include <pwd.h>
#endif

/* We can only do Vendor keysyms in X11r5, because earlier versions 
   didn't provide any way to map over the contents of an xrm database.
 */
#ifdef XtSpecificationRelease
# if XtSpecificationRelease >= 5
#  define DO_VENDOR_KEYSYMS
# endif
#endif



static int y_or_n_p P((KeyboardWidget widget,
		       char *name, char *name0, char *name1, char *name2));

static int y_or_n_p_with_args P((KeyboardWidget,
				 char *name,
				 char *name0, char *name1, char *name2,
				 char *arg0, char *arg1, char *arg2,
				 char *arg3, char *arg4, char *arg5));

static Widget make_button P((Widget parent, char *name, char *string,
			     Widget left, Widget top, XtCallbackProc callback,
			     XtPointer data, char *menu_name));


struct key_menus {
  Widget popup;
  Widget popup_kids [10];
  struct edit_key_box *edit_key_box;
  struct select_kbd_box *select_kbd_box;
};

#ifndef isupper
# define isupper(c)  ((c) >= 'A' && (c) <= 'Z')
#endif
#ifndef _tolower
# define _tolower(c)  ((c) - 'A' + 'a')
#endif

int
#ifdef __STDC__
string_equal (const char *s1, const char *s2)
#else /* ! __STDC__ */
string_equal (s1, s2)
     const char *s1, *s2;
#endif /* ! __STDC__ */
{
  if (s1 == s2) return 1;
  if (!s1 || !s2) return 0;
  while (*s1 && *s2)
    {
      if ((isupper (*s1) ? _tolower (*s1) : *s1) !=
	   (isupper (*s2) ? _tolower (*s2) : *s2))
	 return 0;
       s1++, s2++;
     }
  return ((*s1 || *s2) ? 0 : 1);
}




static Widget
#ifdef __STDC__
make_button (Widget parent,
	     char *name, char *string,
	     Widget left, Widget top,
	     XtCallbackProc callback,
	     XtPointer data,
	     char *menu_name)
#else /* ! __STDC__ */
make_button (parent, name, string, left, top, callback, data, menu_name)
     Widget parent;
     char *name, *string;
     Widget left, top;
     XtCallbackProc callback;
     XtPointer data;
     char *menu_name;
#endif /* ! __STDC__ */
{
  Widget w = make_label_1 (parent, name, string, left, top,
			   (menu_name
			    ? menuButtonWidgetClass
			    : commandWidgetClass),
			   callback, data);
  if (menu_name)
    {
      Arg av [10];
      int ac = 0;
      XtSetArg (av [ac], XtNmenuName, menu_name); ac++;
      XtSetValues (w, av, ac);
    }
  return w;
}


static Widget
#ifdef __STDC__
make_toggle (Widget parent, char *name, Widget left, Widget top, int state,
	     XtCallbackProc callback,
	     XtPointer data, char *label, Widget radio_group,
	     XtPointer radio_data)
#else /* ! __STDC__ */
make_toggle (parent, name, left, top, state, callback, data, label,
	     radio_group, radio_data)
     Widget parent;
     char *name;
     Widget left, top;
     int state;
     void (*callback) ();
     XtPointer data;
     char *label;
     Widget radio_group;
     XtPointer radio_data;
#endif /* ! __STDC__ */
{
  Arg av [20];
  int ac = 0;
  Widget w;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainTop); ac++;
  XtSetArg (av[ac], XtNjustify, XtJustifyLeft); ac++;
  XtSetArg (av[ac], XtNstate, (state ? True : False)); ac++;
  if (left) XtSetArg (av[ac], XtNfromHoriz, left),  ac++;
  if (top) XtSetArg (av[ac], XtNfromVert, top),  ac++;
  if (label) XtSetArg (av[ac], XtNlabel, label),  ac++;
  if (radio_group) XtSetArg (av[ac], XtNradioGroup, radio_group),  ac++;
  if (radio_data) XtSetArg (av[ac], XtNradioData, radio_data),  ac++;
  w = XtCreateManagedWidget (name, toggleWidgetClass, parent, av, ac);
  if (callback) XtAddCallback (w, XtNcallback, callback, data);
  return w;
}




static void
#ifdef __STDC__
button_quit (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
button_quit (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  exit (0);
}


static int modify_keyboard_modifiers P((KeyboardWidget, XModifierKeymap *));
static int modify_keyboard P((KeyboardWidget, int first_keycode,
			      int keysyms_per_keycode, KeySym *keysyms,
			      int num_codes, XModifierKeymap *modmap));

static void
#ifdef __STDC__
button_restore (Widget button, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
button_restore (button, client_data, call_data)
     Widget button;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = *((KeyboardWidget *) client_data);
  KeySym *keysyms;
  KeyCode lowest = 255, highest = 0;
  XModifierKeymap *modmap;
  int per_code = widget->keyboard.default_keysyms_per_code;
  int i, j, k;

  if (0 != y_or_n_p (widget, "restoreQuery", "yes", "no", 0))
    {
      message (widget, "Aborted.");
      return;
    }
  keysyms = (KeySym *) calloc (sizeof (KeySym), per_code * 256);
  modmap = XNewModifiermap (2); /* It'll grow */
  memset (modmap->modifiermap, 0, modmap->max_keypermod * 8);

  for (i = 0; i < widget->keyboard.nrows; i++)
    {
      struct KeyWidget_row *row = &widget->keyboard.rows [i];
      for (j = 0; j < row->nkeys; j++)
	{
	  KeyWidget key = row->keys [j];
	  if (key->key.keycode)
	    {
	      if (key->key.keycode < lowest)
		lowest = key->key.keycode;
	      if (key->key.keycode > highest)
		highest = key->key.keycode;
	      for (k = 0; k < per_code; k++)
		keysyms [key->key.keycode * per_code + k] =
		  key->key.default_keysyms [k];
	      if (key->key.default_mods)
		for (k = 0; k < 8; k++)
		  if (key->key.default_mods & (1<<k))
		    modmap = XInsertModifiermapEntry (modmap,
						      key->key.keycode,
						      k);
	    }
	}
    }
  if (highest <= lowest) exit (-69); /* can't happen */

  if (! modify_keyboard (widget, lowest, per_code,
			 keysyms + (lowest * per_code),
			 highest - lowest, modmap))
    message (widget, "Keyboard restored to default state.");
  XFreeModifiermap (modmap);
  free (keysyms);
}


static FILE *
#ifdef __STDC__
open_output_file(KeyboardWidget widget, char **name)
#else /* ! __STDC__ */
open_output_file(widget, name)
     KeyboardWidget widget;
     char **name;
#endif /* ! __STDC__ */
{
  const char *home = getenv("HOME");
  const char *base = ".xmodmap";
  int L = strlen(home) + strlen(base) + 2;
  char *target = 0;
  struct stat st;
  FILE *out = 0;

#ifndef NO_UNAME
  struct utsname uts;
  if (uname (&uts) >= 0)
    L += strlen(uts.nodename) + 1;
  else
    uts.nodename[0] = 0;
#endif

  target = (char *) malloc(L+1);
  strcpy(target, home);
  if (target[strlen(target)-1] != '/')
    strcat(target, "/");

  strcat(target, base);

#ifndef NO_UNAME
  if (uts.nodename)
    {
      strcat(target, "-");
      strcat(target, uts.nodename);
    }
#endif

  if (!stat(target, &st))
    {
      char *t2;
      if (y_or_n_p_with_args(widget,
			     "overwriteQuery",
			     "ok", "cancel", 0,
			     target, 0, 0, 0, 0, 0))
	goto DONE;

      t2 = (char *) malloc (strlen(target) + 10);
      strcpy (t2, target);
      strcat (t2, ".BAK");
      rename (target, t2);
      free (t2);
    }

  out = fopen(target, "w");
 DONE:
  *name = 0;
  if (out)
    *name = target;
  else
    free (target);
  return out;
}


void
#ifdef __STDC__
make_long_kbd_name (const char *vendor, const char *kbd_style, char *buf)
#else /* ! __STDC__ */
make_long_kbd_name (vendor, kbd_style, buf)
	const char *vendor;
	const char *kbd_style;
	char *buf;
#endif /* ! __STDC__ */
{
  strcpy(buf, (vendor ? vendor : ""));
  if (kbd_style && *kbd_style)
    {
      strcat(buf, " ");
      strcat(buf, kbd_style);
    }
}


static char *bit_names[] = { "Shift", "Lock", "Control", "Mod1",
			      "Mod2", "Mod3", "Mod4", "Mod5" };

static void
#ifdef __STDC__
button_write (Widget button, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
button_write (button, client_data, call_data)
     Widget button;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  char *filename = 0;
  FILE *out;
  KeyboardWidget widget = *((KeyboardWidget *) client_data);
  XModifierKeymap *current_modmap, *default_modmap;
  int per_code = widget->keyboard.default_keysyms_per_code;
  struct { KeyWidget key; int count; char *names[8]; }
     all [256], differences [256];
  int all_count = 0, diff_count = 0;
  KeySym *keysyms;
  int count, i, j, k;
  int partial = y_or_n_p (widget, "writeQuery", "full", "partial", "abort");
  time_t now = time ((time_t *) 0);
#ifdef NO_PWD
  char *userid = 0;
#else
  struct passwd *pw = (struct passwd *) getpwuid (getuid ());
  char *userid = (pw ? pw->pw_name : 0);
#endif
  KeyCode added [8][255];
  KeyCode subtracted [8][255];
  int added_count, subtracted_count;
  int cmkpm, dmkpm;
  int any_mod_changes = 0;

  if (partial >= 2)
    {
      message (widget, "Aborted.");
      return;
    }

  current_modmap = XGetModifierMapping (XtDisplay (widget));
  default_modmap = XNewModifiermap (2); /* It'll grow */
  memset (default_modmap->modifiermap, 0, default_modmap->max_keypermod * 8);

  out = open_output_file(widget, &filename);
  if (!out) return;

  for (i = 0; i < widget->keyboard.nrows; i++)
    {
      struct KeyWidget_row *row = &widget->keyboard.rows [i];
      for (j = 0; j < row->nkeys; j++)
	{
	  KeyWidget key = row->keys [j];
	  if (key->key.keycode)
	    {
	      unsigned long bits = key->key.modifier_bits;
	      keysyms = XGetKeyboardMapping (XtDisplay (widget),
					     key->key.keycode,
					     1, &count);
	      if (! keysyms) count = 0;
	      all [all_count].key = key;
	      for (; count > 0; count--)
		if (keysyms [count-1]) break;
	      if (count == 0)
		{
		  all [all_count].names [0] = "NoSymbol";
		  count = 1;
		}
	      else
		for (k = 0; k < count; k++)
		  {
		    char *str = "NoSymbol";
		    if (keysyms [k])
		      {
			str = XKeysymToString (keysyms [k]);
			if (! str)
			  {
			    /* core leak, but this shouldn't ever happen
			       unless there's a bug in libX11.a, or the
			       user did something stupid with xmodmap.
			     */
			    str = (char *) malloc (255);
			    sprintf (str, "0x%02X", (int) keysyms [k]);
			  }
		      }
		    all [all_count].names [k] = str;
		  }
	      all [all_count].count = count;
	      if (! keysyms) count = 0;
	      if (count > per_code ||
		  ((!partial) && (bits != key->key.default_mods)) ||
		  (count > 0 && keysyms[0] != key->key.default_keysyms[0]) ||
		  (count > 1 && keysyms[1] != key->key.default_keysyms[1]) ||
		  (count > 2 && keysyms[2] != key->key.default_keysyms[2]) ||
		  (count > 3 && keysyms[3] != key->key.default_keysyms[3]) ||
		  (count > 4 && keysyms[4] != key->key.default_keysyms[4]) ||
		  (count > 5 && keysyms[5] != key->key.default_keysyms[5]) ||
		  (count > 6 && keysyms[6] != key->key.default_keysyms[6]) ||
		  (count > 7 && keysyms[7] != key->key.default_keysyms[7]))
		differences [diff_count++] = all [all_count];
	      all_count++;
	      for (k = 0; k < 8; k++)
		{
		  if (key->key.default_mods & (1<<k))
		    default_modmap =
		      XInsertModifiermapEntry (default_modmap,
					       key->key.keycode, k);
		  if (bits & (1<<k))
		    current_modmap =
		      XInsertModifiermapEntry (current_modmap,
					       key->key.keycode, k);
		}
	      if (keysyms) XFree ((char *) keysyms);
	    }
	}
    }

  /* I'd just like to take this moment to point out that C has all
     the expressive power of two dixie cups and a string.
   */
  cmkpm = current_modmap->max_keypermod;
  dmkpm = default_modmap->max_keypermod;
  memset (added, 0, sizeof (added));
  memset (subtracted, 0, sizeof (subtracted));

  for (i = 0; i < 8; i++)
    {
      KeyCode kc1, kc2 = 0;
      added_count = subtracted_count = 0;
      if (partial)
	{
	  for (j = 0; j < cmkpm; j++)
	    {
	      kc1 = current_modmap->modifiermap [i * cmkpm + j];
	      if (!kc1) continue;
	      for (k = 0; k < dmkpm; k++)
		{
		  kc2 = default_modmap->modifiermap [i * dmkpm + k];
		  if (kc1 == kc2) break;
		}
	      if (kc1 != kc2) added [i][added_count++] = kc1;
	    }
	  for (j = 0; j < dmkpm; j++)
	    {
	      kc1 = default_modmap->modifiermap [i * dmkpm + j];
	      if (!kc1) continue;
	      for (k = 0; k < cmkpm; k++)
		{
		  kc2 = current_modmap->modifiermap [i * cmkpm + k];
		  if (kc1 == kc2) break;
		}
	      if (kc1 != kc2) subtracted [i][subtracted_count++] = kc1;
	    }
	  if (added_count || subtracted_count) any_mod_changes = 1;
	}
      else
	{
	  for (j = 0; j < cmkpm; j++)
	    {
	      kc1 = current_modmap->modifiermap [i * cmkpm + j];
	      if (kc1)
		added [i][added_count++] = kc1;
	    }
	}
    }

  {
    char *t;
    char s[1024];
    make_long_kbd_name(widget->keyboard.vendor, widget->keyboard.kbd_style, s);
    fprintf (out, "!\n! This is an `xmodmap' input file for %s%s keyboards.\n",
	     ((strlen(s) > 40) ? "\n!   " : ""), s);

    t = ctime (&now);
    t [strlen (t) - 1] = 0; /* bastards */
    fprintf (out, "! Automatically generated on %s", t);
  }
  if (userid)
    fprintf (out, " by %s", userid);
  fprintf (out, " with\n! %s.\n", short_version);
  fprintf (out, "! http://www.jwz.org/xkeycaps/\n");
  fprintf (out, "!\n");

  if (partial && any_mod_changes)
    {
      fprintf (out, "! This file presupposes that the keyboard is in the ");
      fprintf (out,
	       "default state, and\n! may malfunction if it is not.\n!\n");
    }
  else if (! partial)
    {
      if (diff_count)
	fprintf (out, "! This file makes the following changes:\n!\n");
      else
	fprintf (out, "! This file encodes the default state.\n!\n");
    }

  /* If we're going to write out "remove" commands, do it before writing
     out any "keycode" statements, since xmodmap is so lame.  We only
     generate "remove" statements in "partial" mode.
     http://catalog.com/hopkins/images/smegmas.gif
   */
  any_mod_changes = 0;
  if (partial)
    for (i = 0; i < 8; i++)
      {
	char *str;
	KeySym ks;
	if (subtracted [i][0])
	  {
	    fprintf (out, "remove %-8s=", bit_names [i]);
	    for (j = 0; j < sizeof (subtracted [0]); j++)
	      {
		KeyWidget kw;
		if (! subtracted [i][j]) break;
		any_mod_changes = 1;
		/* note: we don't use the *current* keysym corresponding to the
		   keycode being removed here, but the *default* one...
		 */
		kw = keycode_to_key (widget, subtracted [i][j]);
		ks = kw->key.default_keysyms [0];
		str = XKeysymToString (ks);
		if (str)
		  fprintf (out, " %s", str);
		else
		  fprintf (out, " 0x%04X", subtracted [i][j]);
	      }
	    fprintf (out, "\n");
	  }
      }
  if (any_mod_changes) fprintf (out, "\n");

  /* Write out the differences.  This happens in both "partial" and "full"
     modes, but in "full" mode it's in the form of a descriptive comment
     instead of xmodmap commands.
   */
  for (i = 0; i < diff_count; i++)
    {
      if (partial)
	fprintf (out, "keycode 0x%02X =\t", differences[i].key->key.keycode);
      else
	fprintf (out, "! The \"%s\" key generates ",
		differences[i].key->key.key_name);
      for (j = 0; j < differences[i].count; j++)
	{
	  fprintf (out, "%s", differences[i].names[j]);
	  if (j+1 == differences[i].count) continue;
	  if (partial)
	    {
	      fprintf (out, "\t");
	      if (strlen (differences[i].names[j]) < 8) putchar ('\t');
	    }
	  else
	    {
	      if (j+1 == differences[i].count-1)
		fprintf (out, "%s", (j == 0) ? " and " : ", and ");
	      else
		fprintf (out, ", ");
	    }
	}
      /* write the diffs of the modifier bits in the full-mode comment. */
      if (!partial &&
	  differences[i].key->key.default_mods !=
	  differences[i].key->key.modifier_bits)
	{
	  unsigned long bits = differences[i].key->key.modifier_bits;
	  int this_mod_count = 0;
	  if (! bits)
	    fprintf (out, ", and has no modifiers\n");
	  else
	    {
	      fprintf (out, ", and the ");
	      for (k = 0; k < 8; k++)
		{
		  if (bits & (1<<k))
		    {
		      if (this_mod_count++) fprintf (out, "/");
		      fprintf (out, "%s", bit_names [k]);
		    }
		}
	      fprintf (out, " modifier%s\n", (this_mod_count>1 ? "s" : ""));
	    }
	}
      else
	fprintf (out, "\n");
    }

  /* In "full" mode, write out all the "keycode" commands.  This is the
     first actual xmodmap command text in full mode.
   */
  if (!partial)
    {
      fprintf (out, "\n");
      for (i = 0; i < all_count; i++)
	{
	  fprintf (out, "keycode 0x%02X =\t", all [i].key->key.keycode);
	  for (j = 0; j < all[i].count; j++)
	    {
	      fprintf (out, "%s", all[i].names[j]);
	      if (j == all[i].count - 1) continue;
	      fprintf (out, "\t");
	      if (strlen (all[i].names[j]) < 8) fprintf (out, "\t");
	    }
	  fprintf (out, "\n");
	}
      fprintf (out, "\n");
      fprintf (out, "clear Shift\nclear Lock\nclear Control\nclear Mod1\n");
      fprintf (out, "clear Mod2\nclear Mod3\nclear Mod4\nclear Mod5\n");
    }

  /* In partial mode, write out any "add" commands.  This is after any
     "keycode" commands have already been output (and any "remove" commands
     before them.)  In full mode, the "add" commands are the whole story.
   */
  fprintf (out, "\n");
  for (i = 0; i < 8; i++)
    {
      char *str;
      KeySym ks;
      if (added [i][0])
	{
	  fprintf (out, "add    %-8s=", bit_names [i]);
	  for (j = 0; j < sizeof (added [0]); j++)
	    {
	      if (! added [i][j]) break;
	      ks = XKeycodeToKeysym (XtDisplay (widget), added [i][j], 0);
	      str = XKeysymToString (ks);
	      if (str)
		fprintf (out, " %s", str);
	      else
		fprintf (out, " 0x%04X", added [i][j]);
	    }
	  fprintf (out, "\n");
	}
    }
  fclose (out);
  y_or_n_p_with_args (widget, "wroteFileMessage",
		      "ok", 0, 0,
		      (filename ? filename : "???"), 0, 0, 0, 0, 0);
  if (filename) free (filename);
}


static Window
#ifdef __STDC__
lowest_window (Display *dpy, Window window, Window limit, int x, int y)
#else /* ! __STDC__ */
lowest_window (dpy, window, limit, x, y)
     Display *dpy;
     Window window, limit;
     int x, y;
#endif /* ! __STDC__ */
{
  XWindowAttributes xgwa;
  XGetWindowAttributes (dpy, window, &xgwa);

  /* Ignore all windows which are not at or below `limit'.  This prevents
     us from assigning focus to windows which are part of the WM decoration,
     since `limit' is the result of XmuClientWindow() -- it limits us to
     descending the tree of the client proper.
   */
  if (window == limit) limit = 0;

  if (xgwa.x <= x &&
      xgwa.y <= y &&
      xgwa.x + xgwa.width > x &&
      xgwa.y + xgwa.height > y)
    {
      Window root, parent, *kids;
      unsigned int nkids;
      if (!XQueryTree (dpy, window, &root, &parent, &kids, &nkids))
	abort ();

      if (kids)
	{
	  unsigned int i;
	  Window kid = 0;
	  for (i = 0; i < nkids; i++)
	    {
	      kid = lowest_window (dpy, kids[i], limit,
				   x - xgwa.x, y - xgwa.y);
	      if (kid) break;
	    }
	  XFree ((char *)kids);
	  if (kid) return kid;
	}
      /* Don't accept windows outside of the client tree. */
      if (limit) return 0;
      /* Don't accept windows which don't take KeyPress. */
      if (! (xgwa.all_event_masks & KeyPressMask)) return 0;
      return window;
    }
  else
    return 0;
}

static void
#ifdef __STDC__
button_pick_window (Widget button, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
button_pick_window (button, client_data, call_data)
     Widget button;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget keyboard = *((KeyboardWidget *) client_data);
  Widget topmost, target;
  Display *dpy = XtDisplay (keyboard);
  Window root = RootWindowOfScreen (keyboard->core.screen);
  Window window = 0;
  Window wm_window;
  int click_x = 0, click_y = 0;
  int buttons = 0;
  int once = 0;
  XEvent event;

  message (keyboard, "Please select the window to type at:");

  if (XGrabPointer (dpy, root, False, ButtonPressMask | ButtonReleaseMask,
		    GrabModeSync, GrabModeAsync, root,
		    keyboard->keyboard.select_cursor, CurrentTime))
    {
      XBell (dpy, 0);
      message (keyboard, "Grab failed.");
      return;
    }
  
  while (window == 0 || buttons != 0)
    {
      /* allow one more event */
      XAllowEvents (dpy, SyncPointer, CurrentTime);
      XWindowEvent (dpy, root, ButtonPressMask|ButtonReleaseMask, &event);
      switch (event.type)
	{
	case ButtonPress:
	  once = 1;
	  if (window == 0 && event.xbutton.subwindow)
	    {
	      window = event.xbutton.subwindow; /* window selected */
	      click_x = event.xbutton.x;
	      click_y = event.xbutton.y;
	    }
	  buttons++;
	  break;
	case ButtonRelease:
	  if (buttons > 0) buttons--;
	  break;
	}
    }
  XUngrabPointer(dpy, CurrentTime);
  XSync (dpy, 0);

  wm_window = window;
  if (window && window != root) window = XmuClientWindow (dpy, window);
  topmost = (Widget) keyboard;
  while (XtParent (topmost)) topmost = XtParent (topmost);
  target = XtWindowToWidget (XtDisplay (topmost), window);
  if (window == XtWindow (topmost)) target = topmost;
  if (target || window == root) window = 0;
  if (window)
    {
      char buf [255];
      char buf2 [100];
      char *string1 = 0, *string2 = 0, *string3 = 0;
      char *name;
      XClassHint classhint;

      Window lowest = lowest_window (dpy, wm_window, window, click_x, click_y);
      if (! lowest)
	{
	  /* Maybe they clicked in the wrong place in the app.  Let's try
	     again by picking the exact center of the frame and looking
	     there for something that accepts keyboard input.
	   */
	  XWindowAttributes xgwa;
	  XGetWindowAttributes (dpy, wm_window, &xgwa);
	  lowest = lowest_window (dpy, wm_window, window,
				  xgwa.x + (xgwa.width / 2),
				  xgwa.y + (xgwa.height / 2));
	  if (! lowest)
	    {
	      /* Still couldn't find one; give up. */
	      XBell (dpy, 0);
	      message (keyboard,
		       "No window there that accepts keyboard input!");
	      goto done;
	    }
	}

      classhint.res_name = classhint.res_class = 0;
      if (! XGetClassHint (dpy, window, &classhint))
	classhint.res_name = classhint.res_class = 0;

      string1 = classhint.res_name;
      string2 = classhint.res_class;
      XFetchName (dpy, window, &string3);
      name = string3;
      if (string2 && string3 && string_equal (string2, string3)) string3 = 0;
      if (string1 && string3 && string_equal (string1, string3)) string3 = 0;
      if (string1 && string2 && string_equal (string1, string2)) string2 = 0;
      if (!string2) string2 = string3, string3 = 0;
      if (!string1) string1 = string2, string2 = 0;
      if (string1 && string2 && string3)
	sprintf (buf2, "%s / %s / %s", string1, string2, string3);
      else if (string1 && string2)
	sprintf (buf2, "%s / %s", string1, string2);
      else if (string1)
	sprintf (buf2, "%s", string1);
      else
	sprintf (buf2, "unnamed");

      if (window == lowest)
	sprintf (buf, "Keyboard focus locked on window 0x%X (%s)",
		 (int) window, buf2);
      else
	sprintf (buf, "Keyboard focus locked on window 0x%X <- 0x%X (%s)",
		 (int) lowest, (int) window, buf2);
      message (keyboard, buf);

      if (!classhint.res_class)
	;
      else if (string_equal (classhint.res_class, "xterm"))
	message2 (keyboard,
	      "Remember to select \"Allow SendEvents\" from the XTerm menu.");
      else if (string_equal (classhint.res_class, "cmdtool") ||
	       string_equal (classhint.res_class, "shelltool") ||
	       string_equal (classhint.res_class, "textedit"))
	message2 (keyboard,
 "Did you remember to use the -defeateventsecurity option when launching it?");

      if (classhint.res_name) XFree (classhint.res_name);
      if (classhint.res_class) XFree (classhint.res_class);
      if (name) XFree (name);
      window = lowest;
    }
  else
    message (keyboard, "Keyboard-focus cleared.");
  
 done:
  keyboard->keyboard.target_window = window;
}



static int
#ifdef __STDC__
modify_keyboard_modifiers (KeyboardWidget widget, XModifierKeymap *modmap)
#else /* ! __STDC__ */
modify_keyboard_modifiers (widget, modmap)
     KeyboardWidget widget;
     XModifierKeymap *modmap;
#endif /* ! __STDC__ */
{
  Display *display = XtDisplay ((Widget) widget);
  int retries, timeout;
  char buf [255];
  for (retries = 4, timeout = 2; retries > 0; retries--, timeout *= 2)
    {
      int result;
      result = XSetModifierMapping (display, modmap);
      switch (result)
	{
	case MappingSuccess:
	  mappingNotify_event_expected = 1;
	  return 0;
	case MappingBusy:
	  sprintf (buf, "please release all keys withing %d seconds", timeout);
	  /* Calling message() doesn't work because exposes don't get
	     processed while we're sleeping.
	   */
	  message (widget, buf);
	  fprintf (stderr, "%s: %s\n", progname, buf);
	  XSync (display, 0);
	  sleep (timeout);
	  continue;
	case MappingFailed:
	  message (widget, "XSetModifierMapping() failed");
	  XBell (display, 0);
	  return -1;
	default:
	  sprintf (buf, "unknown return code %d from XSetModifierMapping()",
		   result);
	  message (widget, buf);
	  XBell (display, 0);
	  return -1;
	}
    }
  sprintf (buf, "XSetModifierMapping() failed");
  message (widget, buf);
  XBell (display, 0);
  return -1;
}


/* We install this as an error handler around the call to
   XChangeKeyboardMapping(), so that we can trap errors that that
   operation generates.  Gotta love this 1960's condition system...
 */
static int XChangeKeyboardMapping_error = 0;

static int
#ifdef __STDC__
modify_keyboard_error_handler (Display *dpy, XErrorEvent *error)
#else /* ! __STDC__ */
modify_keyboard_error_handler (dpy, error)
     Display *dpy;
     XErrorEvent *error;
#endif /* ! __STDC__ */
{
  switch (error->request_code)
    {
    case X_ChangeKeyboardMapping:
      XChangeKeyboardMapping_error = 1;
      return 0;
    default:
      XmuPrintDefaultErrorMessage (dpy, error, stderr);
      exit (-1);
    }
}

static int
#ifdef __STDC__
modify_keyboard (KeyboardWidget widget, int first_keycode,
		 int keysyms_per_keycode, KeySym *keysyms,
		 int num_codes, XModifierKeymap *modmap)
#else /* ! __STDC__ */
modify_keyboard (widget, first_keycode, keysyms_per_keycode, keysyms,
		 num_codes, modmap)
     KeyboardWidget widget;
     int first_keycode;
     int keysyms_per_keycode;
     KeySym *keysyms;
     int num_codes;
     XModifierKeymap *modmap;
#endif /* ! __STDC__ */
{
  Display *display = XtDisplay ((Widget) widget);
  XErrorHandler old_handler;
  if (keysyms_per_keycode == 0) keysyms_per_keycode = 1;
  XSync (display, 0);
  mappingNotify_event_expected = 1;
  XChangeKeyboardMapping_error = 0;
  old_handler = XSetErrorHandler (modify_keyboard_error_handler);
  XChangeKeyboardMapping (display, first_keycode, keysyms_per_keycode,
			  keysyms, num_codes);
  /* Is there a race condition here?  Are we guarenteed that by calling
     XSync() we will get back an error generated by the previously-sent
     request?
   */
  XSync (XtDisplay ((Widget) widget), 0);
  XSetErrorHandler (old_handler);
  if (XChangeKeyboardMapping_error)
    {
      mappingNotify_event_expected = 0;
      message (widget, "XChangeKeyboardMapping() failed.");
      XBell (display, 0);
      return -1;
    }
  if (modmap)
    return modify_keyboard_modifiers (widget, modmap);
  return 0;
}


static void
#ifdef __STDC__
restore_key_default (Widget parent, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
restore_key_default (parent, client_data, call_data)
     Widget parent;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = (KeyboardWidget) client_data;
  KeyWidget key = widget->keyboard.key_under_mouse;
  KeySym *keysyms = key->key.default_keysyms;
  int per_code = widget->keyboard.default_keysyms_per_code;
  KeyCode code = key->key.keycode;
  unsigned long bits = key->key.default_mods;
  XModifierKeymap *modmap;
  int i, error;

  if (! code)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }

  modmap = XGetModifierMapping (XtDisplay (widget));
  for (i = 0; i < 8; i++)
    if (bits & (1<<i))
      modmap = XInsertModifiermapEntry (modmap, code, i);
    else
      modmap = XDeleteModifiermapEntry (modmap, code, i);

  XSync (XtDisplay (widget), 0);
  error = modify_keyboard (widget, code, per_code, keysyms, 1, modmap);
  XFreeModifiermap (modmap);

  if (! error)
    {
      char *k, buf [255], buf2 [255], *b = buf;
      for (i = 0; i < per_code; i++)
	{
	  if (i) *b++ = ',', *b++ = ' ';
	  k = XKeysymToString (keysyms [i]);
	  if (keysyms [i] && !k)
	    {
	      sprintf (b, "0x%04X", (int) keysyms [i]);
	      k = b;
	    }
	  else
	    {
	      if (! k) k = "NoSymbol";
	      strcpy (b, k);
	    }
	  b += strlen (k);
	}
      sprintf (buf2, "KeyCode 0x%02X restored to default state (%s)", 
	       key->key.keycode, buf);
      message (widget, buf2);
    }
  XSync (XtDisplay (widget), 0);
}


static void
#ifdef __STDC__
swap_key (Widget parent, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
swap_key (parent, client_data, call_data)
     Widget parent;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = (KeyboardWidget) client_data;
  XModifierKeymap *modmap = XGetModifierMapping (XtDisplay (widget));
  KeyWidget source_key = widget->keyboard.key_under_mouse;
  KeyWidget target_key;
  KeySym *source_keysyms;
  KeySym *target_keysyms;
  int source_count, target_count;
  unsigned long source_bits = source_key->key.modifier_bits;
  unsigned long target_bits;
  KeyCode source_code = source_key->key.keycode;
  KeyCode target_code;
  char buf [255];
  int i, error;

  if (source_key->key.keycode == 0)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }

  sprintf (buf, "Click on the key to swap with 0x%02X (%s)",
	   source_key->key.keycode,
	   source_key->key.key_name);
  target_key = prompt_for_key (widget, buf);
  if (! target_key) return;

  target_bits = target_key->key.modifier_bits;
  target_code = target_key->key.keycode;
  
  if (target_code == 0)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }

  if (source_code == target_code)
    {
      XBell (XtDisplay (widget), 0);
      message (widget, "Those keys are the same!");
      return;
    }

  for (i = 0; i < 8; i++)
    {
      if (source_bits & (1<<i))
	modmap = XInsertModifiermapEntry (modmap, target_code, i);
      else
	modmap = XDeleteModifiermapEntry (modmap, target_code, i);

      if (target_bits & (1<<i))
	modmap = XInsertModifiermapEntry (modmap, source_code, i);
      else
	modmap = XDeleteModifiermapEntry (modmap, source_code, i);
    }

  source_keysyms = XGetKeyboardMapping (XtDisplay (widget), source_code,
					1, &source_count);
  target_keysyms = XGetKeyboardMapping (XtDisplay (widget), target_code,
					1, &target_count);

  error = modify_keyboard (widget, target_code,
			   source_count, source_keysyms, 1, modmap);
  if (error) return;
  error = modify_keyboard (widget, source_code,
			   target_count, target_keysyms, 1, 0);
  if (error) return;

  sprintf (buf, "Keys 0x%02x (%s) and 0x%02x (%s) swapped.",
	   source_key->key.keycode, source_key->key.key_name,
	   target_key->key.keycode, target_key->key.key_name);
  message (widget, buf);

  if (source_keysyms) XFree ((char *) source_keysyms);
  if (target_keysyms) XFree ((char *) target_keysyms);
  if (modmap) XFreeModifiermap (modmap);
}


static void
#ifdef __STDC__
clone_key (Widget parent, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
clone_key (parent, client_data, call_data)
     Widget parent;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = (KeyboardWidget) client_data;
  XModifierKeymap *modmap = XGetModifierMapping (XtDisplay (widget));
  KeyWidget source_key = widget->keyboard.key_under_mouse;
  KeyWidget target_key;
  KeySym *source_keysyms;
  int source_count;
  unsigned long source_bits = source_key->key.modifier_bits;
  KeyCode source_code = source_key->key.keycode;
  KeyCode target_code;
  char buf [255];
  int i, error;

  if (source_key->key.keycode == 0)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }

  sprintf (buf, "Click on the key to turn into a copy of 0x%02X (%s)",
	   source_key->key.keycode,
	   source_key->key.key_name);
  target_key = prompt_for_key (widget, buf);
  if (! target_key) return;

  target_code = target_key->key.keycode;
  
  if (target_code == 0)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }

  if (source_code == target_code)
    {
      XBell (XtDisplay (widget), 0);
      message (widget, "Those keys are the same!");
      return;
    }
  for (i = 0; i < 8; i++)
    {
      if (source_bits & (1<<i))
	modmap = XInsertModifiermapEntry (modmap, target_code, i);
      else
	modmap = XDeleteModifiermapEntry (modmap, target_code, i);
    }

  source_keysyms = XGetKeyboardMapping (XtDisplay (widget), source_code,
					1, &source_count);
  error = modify_keyboard (widget, target_code,
			   source_count, source_keysyms, 1, modmap);
  if (source_keysyms) XFree ((char *) source_keysyms);
  if (modmap) XFreeModifiermap (modmap);
  if (error) return;

  sprintf (buf, "Keys 0x%02x (%s) and 0x%02x (%s) are now the same.",
	   source_key->key.keycode, source_key->key.key_name,
	   target_key->key.keycode, target_key->key.key_name);
  message (widget, buf);
}



static void
#ifdef __STDC__
disable_key (Widget parent, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
disable_key (parent, client_data, call_data)
     Widget parent;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = (KeyboardWidget) client_data;
  KeyWidget key = widget->keyboard.key_under_mouse;
  KeyCode code = key->key.keycode;
  KeySym keysym = 0;
  int i, error;
  char buf [255];
  XModifierKeymap *modmap = XGetModifierMapping (XtDisplay (widget));
  if (code == 0)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }
  for (i = 0; i < 8; i++)
    modmap = XDeleteModifiermapEntry (modmap, code, i);
  error = modify_keyboard (widget, code, 1, &keysym, 1, modmap);
  XFreeModifiermap (modmap);
  if (! error)
    {
      sprintf (buf, "KeyCode 0x%02X (%s) disabled.", key->key.keycode,
	       key->key.key_name);
      message (widget, buf);
    }
  XSync (XtDisplay (widget), 0);
}



static struct edit_key_box * make_edit_key_dbox P((KeyboardWidget));
static struct select_kbd_box * make_select_kbd_dbox P((KeyboardWidget));
static void pop_up_key_dbox P((Widget, XtPointer, XtPointer));


struct key_menus *
#ifdef __STDC__
make_key_menus (KeyboardWidget *kbd)
#else /* ! __STDC__ */
make_key_menus (kbd)
     KeyboardWidget *kbd;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = *kbd;
  Arg av [20];
  int ac = 0, i = 0;
  Widget menu, item;
  struct key_menus *key_menus = (struct key_menus *)
    malloc (sizeof (struct key_menus));
  memset (key_menus->popup_kids, 0, sizeof (key_menus->popup_kids));

  XawSimpleMenuAddGlobalActions (XtWidgetToApplicationContext((Widget)widget));

  XtSetArg (av[ac], XtNlabel, "keyMenu"); ac++;
  menu = XtCreatePopupShell ("keyMenu", simpleMenuWidgetClass,
			     (Widget) widget, av, ac);
  XtAddCallback (menu, XtNpopupCallback, key_menu_pre_popup_hook,
		 (XtPointer) widget);
  key_menus->popup = menu;
  ac = 0;
  item = XtCreateManagedWidget ("editKeysyms", smeBSBObjectClass, menu, av,ac);
  XtAddCallback (item, XtNcallback, pop_up_key_dbox, (XtPointer) widget);
  key_menus->popup_kids [i++] = item;

  item = XtCreateManagedWidget ("swapKey", smeBSBObjectClass, menu, av, ac);
  XtAddCallback (item, XtNcallback, swap_key, (XtPointer) widget);
  key_menus->popup_kids [i++] = item;

  item = XtCreateManagedWidget ("cloneKey", smeBSBObjectClass, menu, av, ac);
  XtAddCallback (item, XtNcallback, clone_key, (XtPointer) widget);
  key_menus->popup_kids [i++] = item;

  item = XtCreateManagedWidget ("disableKey", smeBSBObjectClass, menu, av, ac);
  XtAddCallback (item, XtNcallback, disable_key, (XtPointer) widget);
  key_menus->popup_kids [i++] = item;

  item = XtCreateManagedWidget ("restoreKey", smeBSBObjectClass, menu, av, ac);
  XtAddCallback (item, XtNcallback, restore_key_default, (XtPointer) widget);
  key_menus->popup_kids [i++] = item;

  key_menus->edit_key_box = make_edit_key_dbox (widget);
  key_menus->select_kbd_box = make_select_kbd_dbox (widget);
  return key_menus;
}

void
#ifdef __STDC__
sensitize_menu (KeyboardWidget widget, Widget menu, Bool sensitive)
#else /* ! __STDC__ */
sensitize_menu (widget, menu, sensitive)
     KeyboardWidget widget;
     Widget menu;
     Bool sensitive;
#endif /* ! __STDC__ */
{
  Arg av [10];
  int ac = 0, i = 0;
  struct key_menus *key_menus = widget->keyboard.key_menus;
  if (menu != key_menus->popup) return;
  XtSetArg (av [ac], XtNsensitive, sensitive); ac++;
  for (i = 0; i < sizeof (key_menus->popup_kids); i++)
    if (! key_menus->popup_kids [i]) return;
    else XtSetValues (key_menus->popup_kids [i], av, ac);
}



Widget
#ifdef __STDC__
make_command_widgets (Widget parent, Widget *kbd)
#else /* ! __STDC__ */
make_command_widgets (parent, kbd)
     Widget parent;
     Widget *kbd;
#endif /* ! __STDC__ */
{
  Widget box, top;
  Arg av [20];
  int ac = 0;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainTop); ac++;
  box = XtCreateManagedWidget ("buttons", formWidgetClass, parent, av, ac);
  top = 0;
  top = make_button (box, "quit", NULL, 0, top, button_quit, kbd, 0);
  top = make_button (box, "keyboard", NULL, 0, top, pop_up_kbd_dbox, kbd, 0);
  top = make_button (box, "focus", NULL, 0, top, button_pick_window, kbd, 0);
  top = make_button (box, "restore", NULL, 0, top, button_restore, kbd, 0);
  top = make_button (box, "write", NULL, 0, top, button_write, kbd, 0);

  return box;
}



/* These are used to compute the default sizes of the windows.  Hack hack.
 */
#define LONGEST_KEYSYM_NAME "Greek_upsilonaccentdieresis"
#define MEDIUM_LENGTH_KEYSYM_NAME "Greek_IOTAdiaresis"

struct keyset_names {
  const char *name;	/* The name of this keyset (for the dialog box) */
  unsigned int number;	/* The top two bytes of corresponding keysym values */
}

static all_keyset_names[] = {
  { "Latin1",		0x00 },
  { "Latin2",		0x01 },
  { "Latin3",		0x02 },
  { "Latin4",		0x03 },
  { "Katakana",		0x04 },
  { "Arabic",		0x05 },
  { "Cyrillic",		0x06 },
  { "Greek",		0x07 },
  { "Technical",	0x08 },
  { "Special",		0x09 },
  { "Publishing",	0x0A },
  { "APL",		0x0B },
  { "Hebrew",		0x0C },
  { "Thai",		0x0D },
  { "Korean",		0x0E },
  { "ISO",		0xFE },	/* "ISO 9995 Function and Modifier Keys" */
  { "Keyboard",		0xFF },
#ifdef DO_VENDOR_KEYSYMS
  { "Vendor",	      0xFFFF }, /* special-case hack */
#endif
  { 0, 0 }
};

static char **keysym_name_buffer = 0;
static int keysym_name_buffer_size = 0;

static void
#ifdef __STDC__
ensure_keysym_name_buffer (int size)
#else /* ! __STDC__ */
ensure_keysym_name_buffer (size)
     int size;
#endif /* ! __STDC__ */
{
  if (keysym_name_buffer_size >= size)
    return;
  if (keysym_name_buffer) free ((char *) keysym_name_buffer);
  keysym_name_buffer_size = size;
  keysym_name_buffer = (char **) malloc (sizeof (char *) * size);
}


#ifdef DO_VENDOR_KEYSYMS
struct vendor_keysym {
  char *name;
  KeySym keysym;
  int index;
};

static struct vendor_keysym *vendor_keysyms = 0;
static int n_vendor_keysyms = 0;

static XrmDatabase vendor_keysym_db = 0;

static Bool
#ifdef __STDC__
init_vendor_keysyms_mapper (XrmDatabase *db,
			    XrmBindingList bindings,
			    XrmQuarkList quarks,
			    XrmRepresentation *type,
			    XrmValue *value,
			    XPointer closure)
#else /* ! __STDC__ */
init_vendor_keysyms_mapper (db, bindings, quarks, type, value, closure)
     XrmDatabase *db;
     XrmBindingList bindings;
     XrmQuarkList quarks;
     XrmRepresentation *type;
     XrmValue *value;
     XPointer closure;
#endif /* ! __STDC__ */
{
  KeySym keysym;
  char c;
  int i;
  int *count = (int *) closure;
  if (quarks [1]) /* should only be one level deep. */
    abort ();

  if (! value->addr || value->size <= 1)
    return False;

  keysym = 0;
  for (i = 0; i < value->size - 1; i++)
    {
      c = ((char *) value->addr) [i];
      if ('0' <= c && c <= '9') keysym = (keysym<<4)+c-'0';
      else if ('a' <= c && c <= 'z') keysym = (keysym<<4)+c-'a'+10;
      else if ('A' <= c && c <= 'Z') keysym = (keysym<<4)+c-'A'+10;
      else
	{
	  fprintf (stderr, "%s: unparsable entry in XKeysymDB: \"%s: %s\"\n",
		   progname, XrmQuarkToString (quarks [0]),
		   (char *) value->addr);
	  return False;
	}
    }
  
  if (n_vendor_keysyms <= *count)
    {
      n_vendor_keysyms *= 2;
      vendor_keysyms = (struct vendor_keysym *)
	realloc (vendor_keysyms, sizeof (struct vendor_keysym) *
		 n_vendor_keysyms);
    }
  vendor_keysyms [*count].index = -1; /* we fill this in later */
  vendor_keysyms [*count].keysym = keysym;
  vendor_keysyms [*count].name = (char *) XrmQuarkToString (quarks [0]);
  (*count)++;
  return False;
}


static int
#ifdef __STDC__
sort_vendor_keysyms_1 (int left, int right)
#else /* ! __STDC__ */
sort_vendor_keysyms_1 (left, right)
     int left, right;
#endif /* ! __STDC__ */
{
  int L = left, R = right, middle;
  struct vendor_keysym swap;
  KeySym pivot = vendor_keysyms [left].keysym;
  while (L < R)
    {
      while (vendor_keysyms [L].keysym <= pivot && L <= right)
	L++;
      while (vendor_keysyms [R].keysym > pivot && R >= left)
	R--;
      if (L < R)
	{
	  swap = vendor_keysyms [L];
	  vendor_keysyms [L] = vendor_keysyms [R];
	  vendor_keysyms [R] = swap;
	}
    }
  middle = R;
  swap = vendor_keysyms [left];
  vendor_keysyms [left] = vendor_keysyms [middle];
  vendor_keysyms [middle] = swap;
  if (left < middle - 1)
    middle = sort_vendor_keysyms_1 (left, middle - 1);
  if (middle + 1 < right)
    middle = sort_vendor_keysyms_1 (middle + 1, right);
  return middle;
}


static void
sort_vendor_keysyms P((void))
{
  int i;
  sort_vendor_keysyms_1 (0, n_vendor_keysyms - 1);
  for (i = 0; i < n_vendor_keysyms; i++)
    {
      if (i > 0 && vendor_keysyms [i].keysym < vendor_keysyms [i-1].keysym)
	abort ();
      vendor_keysyms [i].index = i;
    }
}


#ifndef NO_XInitKeysymDB
extern XrmDatabase _XInitKeysymDB P((void));
#endif

static void
#ifdef __STDC__
init_vendor_keysyms (KeyboardWidget widget)
#else /* ! __STDC__ */
init_vendor_keysyms (widget)
     KeyboardWidget widget;
#endif /* ! __STDC__ */
{
  static int done = 0;
  int count = 0;
  XrmName name = { 0 };
  XrmClass class = { 0 };

  if (done) return;
  done = 1;

  if (! vendor_keysym_db)
    {
      char *dbname = (char *) getenv ("XKEYSYMDB");
#ifdef KEYSYMDB
      if (! dbname) dbname = KEYSYMDB;
#endif /*  KEYSYMDB */

#ifdef NO_XInitKeysymDB
      if (dbname)
	vendor_keysym_db = XrmGetFileDatabase (dbname);
#else  /* we have _XInitKeysymDB(), so let Xlib be clever for us. */
      vendor_keysym_db = _XInitKeysymDB ();
#endif /* _XInitKeysymDB */

      if (! vendor_keysym_db) /* still don't have it... */
	{
	  if (dbname)
	    y_or_n_p_with_args (widget, "noKeysymDBError", "ok", 0, 0,
				dbname, 0, 0, 0, 0, 0);
	  else
	    y_or_n_p (widget, "unknownKeysymDBError", "ok", 0, 0);
	  return;
	}
    }

  n_vendor_keysyms = 255; /* probably not more than this; it's realloc'd. */
  vendor_keysyms = (struct vendor_keysym *)
    malloc (n_vendor_keysyms * sizeof (struct vendor_keysym));

  XrmEnumerateDatabase (vendor_keysym_db, &name, &class,
			XrmEnumOneLevel, init_vendor_keysyms_mapper,
			(XtPointer) &count);

  if (count < n_vendor_keysyms) /* might as well shrink it */
    {
      n_vendor_keysyms = count;
      vendor_keysyms = (struct vendor_keysym *)
	realloc (vendor_keysyms, count * sizeof (struct vendor_keysym));
    }
  else if (! count)
    {
      free ((char *) vendor_keysyms);
      n_vendor_keysyms = 0;
      vendor_keysyms = 0;
      return;
    }
  /* Hash order isn't very pretty; sort them by keysym numeric value. */
  sort_vendor_keysyms ();
}

static void
#ifdef __STDC__
fill_keysym_name_buffer_with_vendor_keysyms (KeyboardWidget keyboard)
#else /* ! __STDC__ */
fill_keysym_name_buffer_with_vendor_keysyms (keyboard)
     KeyboardWidget keyboard;
#endif /* ! __STDC__ */
{
  int i;
  if (! vendor_keysyms) init_vendor_keysyms (keyboard);
  ensure_keysym_name_buffer (n_vendor_keysyms + 1);
  for (i = 0; i < n_vendor_keysyms; i++)
    keysym_name_buffer [i] = vendor_keysyms [i].name;
  keysym_name_buffer [i] = 0;
}


static int
#ifdef __STDC__
vendor_keysym_to_small_index (KeyboardWidget keyboard, KeySym keysym)
#else /* ! __STDC__ */
vendor_keysym_to_small_index (keyboard, keysym)
     KeyboardWidget keyboard;
     KeySym keysym;
#endif /* ! __STDC__ */
{
  int i;
  char buf [255];
  if (! vendor_keysyms) init_vendor_keysyms (keyboard);
  for (i = 0; i < n_vendor_keysyms; i++)
    if (keysym == vendor_keysyms [i].keysym)
      return vendor_keysyms [i].index;
  sprintf (buf, "Unrecognised vendor keysym 0x%08X.", (int) keysym);
  XBell (XtDisplay ((Widget) keyboard), 0);
  message (keyboard, buf);
  fprintf (stderr, "%s: %s\n", progname, buf);
  return 0;
}

#endif /* DO_VENDOR_KEYSYMS */


struct edit_key_box {
  KeyboardWidget keyboard;
  Widget shell;
  Widget label;
  Widget keysym_buttons [8];
  Widget mod_buttons [8];
  Widget keyset_list, keysym_list;
  Widget autorepeat_widget;
  int autorepeat;
};


static void
#ifdef __STDC__
keyset_list_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
keyset_list_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  XawListReturnStruct *lr = (XawListReturnStruct *) call_data;
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  int set = 0;
  int i, j = 0;
  int set_start = 0;

  set = -1;
  for (i = 0; i < sizeof(all_keyset_names)/sizeof(*all_keyset_names); i++)
    if (lr->list_index == i)
      {
	set = all_keyset_names[i].number;
	break;
      }

  if (set != 0) set_start = 1; /* Latin1 is the only set that has NoSymbol */

#ifdef DO_VENDOR_KEYSYMS
  if (set == 0xFFFF)	/* FFFF means "vendor keysym" */
    fill_keysym_name_buffer_with_vendor_keysyms (box->keyboard);
  else
#endif
  if (set == -1)
    {
      ensure_keysym_name_buffer (256);
      keysym_name_buffer [0] = 0;
    }
  else
    {
      ensure_keysym_name_buffer (256);
      for (i = set_start; i < 256; i++)
	{
	  char *name = XKeysymToString ((set << 8) | i);
	  if (! name && i == 0) name = "NoSymbol";
	  if (name)
	    keysym_name_buffer [j++] = name;
	}
      keysym_name_buffer [j++] = 0;
    }
  XawListChange (box->keysym_list, keysym_name_buffer, 0, 0, True);
}


static void
#ifdef __STDC__
keysym_list_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
keysym_list_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  XawListReturnStruct *lr = (XawListReturnStruct *) call_data;
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  int i = (int) XawToggleGetCurrent (box->keysym_buttons [0]);
  if (i > 0)
    {
      Widget button = box->keysym_buttons [i-1];
      /* If the string is wider than the parent of the button, setting the
	 label will leave it at the size it was before.  So, first stretch
	 it to the max width, and then let SetValues (maybe) resize it
	 smaller.  What a piece of junk. */
      XtResizeWidget (button,
		      XtParent (button)->core.width,
		      button->core.height,
		      button->core.border_width);
      XtVaSetValues (button, XtNlabel, lr->string, 0);
    }
}


static void
#ifdef __STDC__
autorepeat_button_cb (Widget widget, XtPointer client_data,
		      XtPointer call_data)
#else /* ! __STDC__ */
autorepeat_button_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  Arg av [10];
  int ac = 0;
  box->autorepeat = !box->autorepeat;
  XtSetArg (av [ac], XtNlabel, (box->autorepeat ? "Yes" : "No")); ac++;
  XtSetValues (widget, av, ac);
}


static void
#ifdef __STDC__
abort_button_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
abort_button_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  XtPopdown (box->shell);
  message (box->keyboard, "Aborted.");
}


static int stop_the_insanity P((KeyboardWidget,
				int keycode, KeySym *keysyms, int count,
				unsigned long modbits,
				XModifierKeymap *modmap));


static void
#ifdef __STDC__
ok_button_cb (Widget button, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
ok_button_cb (button, client_data, call_data)
     Widget button;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  KeyboardWidget widget = box->keyboard;
  KeyWidget key = widget->keyboard.key_under_mouse;
  KeyCode code = key->key.keycode;
  KeySym keysyms [8];
  int keysym_count;
  unsigned long modbits = 0;
  XModifierKeymap *modmap = XGetModifierMapping (XtDisplay (widget));
  int i, error;
  Arg av [10];
  int ac = 0;
  char *str;

  ac = 0;
  XtSetArg (av [ac], XtNlabel, &str); ac++;
  for (i = 0; i < 8; i++)
    {
      XtGetValues (box->keysym_buttons [i], av, ac);
      if (str && !strcmp (str, "NoSymbol")) str = 0;
      if (! str)
	keysyms [i] = 0;
      else
	{
	  keysyms [i] = XStringToKeysym (str);
	  if (! keysyms [i])
	    fprintf (stderr,
		     "%s: ERROR: XStringToKeysym(\"%s\") returned 0\n",
		     progname, str);
	}
    }
  for (keysym_count = 8; keysym_count > 0; keysym_count--)
    if (keysyms [keysym_count-1]) break;

  for (i = 0; i < 8; i++)
    {
#ifndef XAWBUG
      Boolean state = 0;
      XtVaGetValues (box->mod_buttons[i], XtNstate, &state, NULL);
#else /* XAWBUG */
      int state = ((CommandWidget) (box->mod_buttons [i]))->command.set;
#endif
      modbits |= ((!!state) << i);
      if (state)
	modmap = XInsertModifiermapEntry (modmap, code, i);
      else
	modmap = XDeleteModifiermapEntry (modmap, code, i);
    }

  if (stop_the_insanity (widget, code, keysyms, keysym_count, modbits, modmap))
    return;

  XSync (XtDisplay (widget), 0);
  error = modify_keyboard (widget, code, keysym_count,
			   keysyms, 1, modmap);
  XFreeModifiermap (modmap);

  if (!error && box->autorepeat != key->key.auto_repeat_p)
    {
      XKeyboardControl values;
      values.key = key->key.keycode;
      values.auto_repeat_mode =
	(box->autorepeat ? AutoRepeatModeOn : AutoRepeatModeOff);
      XChangeKeyboardControl (XtDisplay (widget), KBKey | KBAutoRepeatMode,
			      &values);
    }

  XtPopdown (box->shell);

  if (! error) message (box->keyboard, "Modified.");
}


static void
#ifdef __STDC__
move_scrollbar (Widget list, float percent)
#else /* ! __STDC__ */
move_scrollbar (list, percent)
     Widget list;
     float percent;
#endif /* ! __STDC__ */
{
  Widget vp = XtParent (list);
  Widget scrollbar = XtNameToWidget (vp, "vertical");
  float visible_fraction = (((float) vp->core.height) /
			    ((float) list->core.height));
  if (visible_fraction < 1.0)
    percent -= (visible_fraction / 2.0);
  XawScrollbarSetThumb (scrollbar, 0.0, -1.0);
  XtCallCallbacks (scrollbar, XtNjumpProc, (XtPointer) &percent);
}


static void
#ifdef __STDC__
keysym_button_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
keysym_button_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  KeyboardWidget keyboard = box->keyboard;
  char *keysym_name = 0;
  KeySym real_keysym;
  int list_index = 0;
  int keyset = 0, keysym = 0, index = 0, list_size = 0;
  Arg av[10];
  int ac = 0;
  int i;

  if (call_data == 0)	/* we're being toggled off */
    return;

  XtSetArg (av[ac], XtNlabel, &keysym_name); ac++;
  XtGetValues (widget, av, ac);
  real_keysym = XStringToKeysym (keysym_name);
  /* Get the one that's in the list */
  keysym_name = XKeysymToString (real_keysym);

  if (real_keysym > 0xFFFF)
    {
#ifdef DO_VENDOR_KEYSYMS
      int i;
      keysym = 0;
      for (i = 0; i < sizeof(all_keyset_names)/sizeof(*all_keyset_names); i++)
	if (!strcmp(all_keyset_names[i].name, "Vendor"))
	  {
	    keysym = i;
	    break;
	  }
      if (keysym == 0) abort();
      keysym = vendor_keysym_to_small_index (keyboard, real_keysym);
#else
      XBell (XtDisplay (keyboard), 0);
      message (keyboard,
	       "XKeyCaps was compiled without support for Vendor keysyms.");
      message2 (keyboard, "Consider upgrading to X11r5...");
      keyset = 0;
      keysym = 0;
#endif
    }
  else
    {
      keyset = (real_keysym >> 8);
      keysym = (real_keysym & 0xff);
    }

  list_size = (sizeof (all_keyset_names) / sizeof (all_keyset_names[0]));

  list_index = -1;
  for (i = 0; i < sizeof(all_keyset_names)/sizeof(*all_keyset_names); i++)
    if (all_keyset_names[i].number == keyset)
      {
	list_index = i;
	break;
      }

  if (list_index < 0)
    {
      XawListUnhighlight(box->keyset_list);
      move_scrollbar (box->keyset_list, 0.0);
    }
  else
    {
      XawListHighlight (box->keyset_list, list_index);
      move_scrollbar (box->keyset_list,
		      (((float) list_index) / ((float) list_size)));
    }
  keyset_list_cb (box->keyset_list, box,
		  XawListShowCurrent (box->keyset_list));

  index = 256;
  for (list_size = 0; list_size < 256; list_size++)
    if (keysym_name_buffer [list_size] == keysym_name)
      index = list_size;
    else if (! keysym_name_buffer [list_size])
      break;
  if (! keysym_name) index = 0;
  if (index < 256)
    {
      XawListHighlight (box->keysym_list, index);
      move_scrollbar (box->keysym_list,
		      (((float) index) / ((float) list_size)));
    }
  else
    {
      XawListUnhighlight (box->keysym_list);
    }
}


static void
#ifdef __STDC__
undo_button_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
undo_button_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct edit_key_box *box = (struct edit_key_box *) client_data;
  KeyboardWidget keyboard = box->keyboard;
  KeyWidget key = keyboard->keyboard.key_under_mouse;
  KeySym *keysyms;
  int syms_per_code = 0;
  char buf [255];
  Arg av[20];
  int ac = 0;
  int i;

  keysyms = XGetKeyboardMapping (XtDisplay (widget), key->key.keycode,
				 1, &syms_per_code);

  sprintf (buf, "Definition of key 0x%02X (%s)", key->key.keycode,
	   key->key.key_name);
  XtSetArg (av[ac], XtNlabel, buf); ac++;
  XtSetValues (box->label, av, ac);
  ac = 0;

  for (i = 0; i < syms_per_code; i++)
    {
      char *sym;
      char buf [255];
      if (!keysyms || !keysyms[i])
	sym = "NoSymbol";
      else
	sym = XKeysymToString (keysyms [i]);
      if (! sym)
	{
	  sprintf (buf, "0x%04X", (int) keysyms [i]);
	  sym = buf;
	}
      ac = 0;
      XtSetArg (av[ac], XtNlabel, sym); ac++;
      XtSetValues (box->keysym_buttons [i], av, ac);
    }
  if (keysyms) XFree ((char *) keysyms);
  ac = 0;
  XtSetArg (av[ac], XtNlabel, "NoSymbol"); ac++;
  for (; i < 8; i++)
    XtSetValues (box->keysym_buttons [i], av, ac);

  for (i = 0; i < 8; i++)
    {
      ac = 0;
      XtSetArg (av[ac], XtNstate,
		((key->key.modifier_bits & 1<<i) ? True : False)); ac++;
      XtSetValues (box->mod_buttons [i], av, ac);
    }

  XawToggleSetCurrent (box->keysym_buttons [0], (XtPointer) 1);
  keysym_button_cb (box->keysym_buttons [0], box, (void *) 1);
  box->autorepeat = !key->key.auto_repeat_p;
  autorepeat_button_cb (box->autorepeat_widget, box, 0);
}


static struct edit_key_box *
#ifdef __STDC__
make_edit_key_dbox (KeyboardWidget widget)
#else /* ! __STDC__ */
make_edit_key_dbox (widget)
     KeyboardWidget widget;
#endif /* ! __STDC__ */
{
  struct edit_key_box *box = (struct edit_key_box *)
    malloc (sizeof (struct edit_key_box));
  Arg av [20];
  int ac = 0;
  Widget toplevel, box1, box2;
  Widget keysym_box, button_box, keyset_box, keyset_syms_box, mod_box;
  Widget line_box, prev, prev_tog;
  Widget set_list, sym_list;
  Widget set_vp, sym_vp;

  toplevel = XtCreatePopupShell ("editKey", transientShellWidgetClass,
				 (Widget) widget, av, ac);
  box1 = XtCreateManagedWidget ("vertical", panedWidgetClass, toplevel, av,ac);
  box->label = make_label (box1, "label", 0, 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNorientation, "horizontal"); ac++;
  box2 = XtCreateManagedWidget ("horizontal", panedWidgetClass, box1, av, ac);

  ac = 0;
  keysym_box = XtCreateManagedWidget ("keysymBox", formWidgetClass, box2,
				      av, ac);
  prev = make_label (keysym_box, "symsOfCode", 0, 0, 0);
  prev = make_label (keysym_box, "spacer", "", 0, prev);
  ac = 0;
  prev_tog = 0;
  line_box = prev;
#define TOG(var, name, index) \
   { ac = 0; \
     XtSetArg (av[ac], XtNorientation, "horizontal"); ac++; \
     XtSetArg (av [ac], XtNfromVert, line_box); ac++; \
     XtSetArg (av[ac], XtNtop, XtChainTop); ac++; \
     XtSetArg (av[ac], XtNbottom, XtChainTop); ac++; \
     line_box = XtCreateManagedWidget ("keysymLine", boxWidgetClass, \
				       keysym_box, av, ac); \
     var = make_label (line_box, name, 0, 0, prev); \
     if (index) \
       var = make_toggle (line_box, "keysymValue" ,var, prev, 0, \
			  keysym_button_cb, box, MEDIUM_LENGTH_KEYSYM_NAME, \
			  prev_tog, (XtPointer) index); \
     else \
       var = make_button (line_box, "autoRepeatValue", "Yes", var, prev, \
			  autorepeat_button_cb, box, 0); \
       prev_tog = prev = var; }
  TOG (box->keysym_buttons [0], "keysym1", 1);
  TOG (box->keysym_buttons [1], "keysym2", 2);
  TOG (box->keysym_buttons [2], "keysym3", 3);
  TOG (box->keysym_buttons [3], "keysym4", 4);
  TOG (box->keysym_buttons [4], "keysym5", 5);
  TOG (box->keysym_buttons [5], "keysym6", 6);
  TOG (box->keysym_buttons [6], "keysym7", 7);
  TOG (box->keysym_buttons [7], "keysym8", 8);
  prev = prev_tog = 0;
  line_box = make_label (keysym_box, "spacer2", "", 0, line_box);
  TOG (box->autorepeat_widget, "autoRepeat", 0);
#undef TOG

  ac = 0;
  mod_box = XtCreateManagedWidget ("modifierBox", formWidgetClass,
				   box2, av, ac);
  prev = make_label (mod_box, "modifiers", 0, 0, 0);
  prev = make_label (mod_box, "spacer", "", 0, prev);
#define TOG(var, name) \
   { var = make_toggle (mod_box, name, 0, prev, 0, 0, 0, 0, 0, 0); \
     prev = var; }
  TOG (box->mod_buttons [0], "modShift");
  TOG (box->mod_buttons [1], "modLock");
  TOG (box->mod_buttons [2], "modControl");
  TOG (box->mod_buttons [3], "mod1");
  TOG (box->mod_buttons [4], "mod2");
  TOG (box->mod_buttons [5], "mod3");
  TOG (box->mod_buttons [6], "mod4");
  TOG (box->mod_buttons [7], "mod5");
#undef TOG

  ac = 0;
  keyset_box = XtCreateManagedWidget("keysetBox", formWidgetClass,
				     box2, av, ac);
  prev = make_label (keyset_box, "allKeySets", 0, 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNfromVert, prev); ac++;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainRight); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainBottom); ac++;
  set_vp = XtCreateManagedWidget ("keysetsVp", viewportWidgetClass,
				  keyset_box, av, ac);
  ac = 0;
  {
    static const char *list[sizeof(all_keyset_names) /
			    sizeof(*all_keyset_names)];
    int i = 0;
    for (i = 0; i < sizeof(list)/sizeof(*list); i++)
      list[i] = all_keyset_names[i].name;
    XtSetArg (av[ac], XtNlist, list); ac++;
  }

  set_list = XtCreateManagedWidget ("keysets", listWidgetClass, set_vp,av,ac);
  XtAddCallback (set_list, XtNcallback, keyset_list_cb, (XtPointer) box);

  /* Gag!  These lists won't size themselves correctly. */
  XtVaSetValues (set_list, XtNwidth, set_list->core.width + 20, 0);

  ac = 0;
  keyset_syms_box = XtCreateManagedWidget ("keysetSymsBox", formWidgetClass,
					   box2, av, ac);
  prev = make_label (keyset_syms_box, "keySymsOfSet", 0, 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNfromVert, prev); ac++;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainRight); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainBottom); ac++;
  sym_vp = XtCreateManagedWidget ("keysymsVp", viewportWidgetClass,
				  keyset_syms_box, av, ac);
  ensure_keysym_name_buffer (256);

#if 0
  memcpy (keysym_name_buffer, all_keyset_names, sizeof (all_keyset_names));
#endif

  keysym_name_buffer [0] = LONGEST_KEYSYM_NAME;
  keysym_name_buffer [1] = 0;

  ac = 0;
  XtSetArg (av[ac], XtNlist, keysym_name_buffer); ac++;
  sym_list = XtCreateManagedWidget ("keysyms", listWidgetClass, sym_vp,av,ac);
  XtAddCallback (sym_list, XtNcallback, keysym_list_cb, (XtPointer) box);

  /* Gag!  These lists won't size themselves correctly. */
  XtVaSetValues (sym_list, XtNwidth, sym_list->core.width + 20, 0);

  ac = 0;
  XtSetArg (av[ac], XtNskipAdjust, True); ac++;
  button_box = XtCreateManagedWidget ("buttons", boxWidgetClass, box1, av, ac);

  prev = make_button (button_box, "undo",  0,    0, 0, undo_button_cb, box, 0);
  prev = make_button (button_box, "abort", 0, prev, 0, abort_button_cb, box,0);
  prev = make_button (button_box, "ok",    0, prev, 0, ok_button_cb, box, 0);

  box->keyboard = widget;
  box->shell = toplevel;
  box->keyset_list = set_list;
  box->keysym_list = sym_list;
  return box;
}

static void
#ifdef __STDC__
pop_up_key_dbox (Widget parent, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
pop_up_key_dbox  (parent, client_data, call_data)
     Widget parent;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = (KeyboardWidget) client_data;
  struct edit_key_box *edit_key_box =
    widget->keyboard.key_menus->edit_key_box;

  if (widget->keyboard.key_under_mouse->key.keycode == 0)
    {
      y_or_n_p (widget, "magicKeyError", "ok", 0, 0);
      return;
    }

  {
    Widget topmost = parent;
    int x, y, w, h;
    XtRealizeWidget (edit_key_box->shell);
    w = edit_key_box->shell->core.width;
    h = edit_key_box->shell->core.height;
    while (topmost->core.parent)
      topmost = topmost->core.parent;
    if (topmost->core.width < w) x = topmost->core.x;
    else x = topmost->core.x + ((topmost->core.width - w) / 2);
    if (topmost->core.height < h) y = topmost->core.y;
    else y = topmost->core.y + ((topmost->core.height - h) / 2);
    XtMoveWidget (edit_key_box->shell, x, y);
  }
  XtPopup (edit_key_box->shell, XtGrabNonexclusive);
  undo_button_cb (edit_key_box->shell, edit_key_box, 0);
}



static struct keyboard_set {
  int kbd_index;
  const char *vendor;
  char *type;
  char **maps;		/* short names of maps */
  char **full_maps;	/* long names (vendor+kbd+map) */
  int map_count;
} *keyboard_sets;

int keyboard_set_count;
int vendor_count;
static char const **vendors;
static char **keyboard_types;	/* compared to keyboard_sets[i].type[j] */
static char *longest_type;	/* longest of all keyboard_sets[i].type */
static char *longest_map;	/* longest of all keyboard_sets[i].maps[j] */

struct select_kbd_box {
  KeyboardWidget keyboard;
  Widget shell;
  Widget label;
  Widget label2;
  Widget icon;
  Widget vendor_list, keyboard_list, keymap_list;
  struct keyboard_set *set;
  const char *map;
};


static char *default_maps[] = { "default", 0 };

static void
make_kbd_lists P((void))
{
  int kbd_count = 0;
  int i, j;

  i = 0;
  vendor_count = 0;
  while (all_kbds[i].vendor)
    {
      const char *v = all_kbds[i].vendor;
      vendor_count++;
      i++;
      while (all_kbds[i].vendor &&
	     !strcmp(v, all_kbds[i].vendor))
	i++;
    }

  vendors = (const char **) malloc (sizeof(*vendors) * (vendor_count+1));
  i = 0;
  j = 0;
  while (all_kbds[i].vendor)
    {
      const char *v = all_kbds[i].vendor;
      vendors[j++] = v;
      i++;
      while (all_kbds[i].vendor &&
	     !strcmp(v, all_kbds[i].vendor))
	i++;
    }
  vendors[j] = 0;


  for (kbd_count = 0; all_kbds [kbd_count].short_name; kbd_count++)
    ;
  keyboard_sets = (struct keyboard_set *)
    malloc (sizeof (struct keyboard_set) * kbd_count);
  longest_type = 0;
  longest_map = 0;
  
  i = 0;
  j = 0;
  while (i < kbd_count)
    {
      char last_style [255];
      char full [255];

      char *tail;
      strcpy (last_style, all_kbds[i].kbd_style);
      make_long_kbd_name (all_kbds[i].vendor, last_style, full);

      tail = (char *) strchr (last_style, '(');
      if (tail) *tail = 0;

      tail = (char *) strchr (full, '(');
      keyboard_sets [j].kbd_index = i;
      keyboard_sets [j].map_count = 0;
      keyboard_sets [j].vendor = all_kbds[i].vendor;

      if (tail)
	{
	  int L;
	  int count = 0;
	  int k;

	  /* Edit out the parens (but not the trailing space) */
	  *tail = 0;
	  tail++;
	  tail [strlen (tail) - 1] = 0;

	  L = strlen (full);
	  count = 0;
	  while (1)
	    {
	      char name[255];
	      make_long_kbd_name(all_kbds[i+count].vendor,
				 all_kbds[i+count].kbd_style,
				 name);
	      if (strlen (name) < L ||
		  !!strncmp (full, name, L))
		break;
	      count++;
	    }

	  keyboard_sets [j].maps = (char **)
	    malloc (sizeof (char *) * (count+1));
	  keyboard_sets [j].full_maps = (char **)
	    malloc (sizeof (char *) * (count+1));
	  for (k = 0; k < count; k++)
	    {
	      char full[255];
	      const char *map;
	      char *map_name = 0;
	      int ML;
	      make_long_kbd_name(all_kbds [i+k].vendor,
				 all_kbds [i+k].kbd_style,
				 full);
	      map = strchr(full, '(');
	      if (!map) abort();
	      map++;
	      ML = strlen (map);
	      map_name = (char *) malloc (ML);
	      memcpy (map_name, map, ML);
	      map_name [--ML] = 0;
	      keyboard_sets [j].maps[k] = map_name;
	      keyboard_sets [j].full_maps[k] = strdup(full);
	      if (!longest_map || strlen (longest_map) < ML)
		longest_map = keyboard_sets [j].maps[k];
	    }
	  keyboard_sets [j].maps[k] = 0;
	  i += count;
	  keyboard_sets [j].map_count = count;
	}
      else
	{
	  keyboard_sets [j].maps = default_maps;
	  keyboard_sets [j].full_maps = (char **) malloc (sizeof (char *) * 2);
	  keyboard_sets [j].full_maps [0] = strdup(full);
	  keyboard_sets [j].full_maps [1] = 0;
	  keyboard_sets [j].map_count = 1;
	  i++;
	}

      keyboard_sets [j].type = (char *) malloc (strlen (last_style) + 1);
      memcpy (keyboard_sets [j].type, last_style, strlen (last_style) + 1);

      if (!longest_type ||
	  strlen (longest_type) < strlen(keyboard_sets [j].type))
	longest_type = keyboard_sets [j].type;

      j++;
    }
  keyboard_set_count = j;

  {
    int max = 0;
    keyboard_types = (char **) malloc (sizeof (char *) * (j + 1));
    for (i = 0; i < j; i++)
      {
	keyboard_types [i] = keyboard_sets [i].type;
	if (keyboard_sets [i].map_count > max)
	  max = keyboard_sets [i].map_count;
      }
    keyboard_types[i] = 0;
  }
}

static void
#ifdef __STDC__
kbd_abort_button_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
kbd_abort_button_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct select_kbd_box *box = (struct select_kbd_box *) client_data;
  Widget shell = box->shell;
  XtPopdown (shell);
}

static void
#ifdef __STDC__
kbd_ok_button_cb (Widget button, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
kbd_ok_button_cb (button, client_data, call_data)
     Widget button;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  struct select_kbd_box *box = (struct select_kbd_box *) client_data;
  KeyboardWidget kbd = box->keyboard;
  const char *map = box->map;
  kbd_abort_button_cb (button, client_data, call_data);
  replace_keyboard (kbd, map);
}

static void
#ifdef __STDC__
keymap_list_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
keymap_list_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  XawListReturnStruct *lr = (XawListReturnStruct *) call_data;
  struct select_kbd_box *box = (struct select_kbd_box *) client_data;
  struct keyboard_set *set = box->set;
  box->map = set->full_maps [lr->list_index];
}

static int current_vendor_offset = 0;

static void
#ifdef __STDC__
keyboard_list_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
keyboard_list_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  XawListReturnStruct *lr = (XawListReturnStruct *) call_data;
  struct select_kbd_box *box = (struct select_kbd_box *) client_data;
  int kbd = lr->list_index + current_vendor_offset;
  int map = 0;
  int i = 0;

  while (strcmp (keyboard_sets [i].type, keyboard_types [kbd]))
    i++;
  box->set = &keyboard_sets [i];
  XawListChange (box->keymap_list, (char **) box->set->maps, 0, 0, True);
  for (i = 0; i < box->set->map_count; i++)
    {
      char buf[255];
      make_long_kbd_name(box->keyboard->keyboard.vendor,
			 box->keyboard->keyboard.kbd_style,
			 buf);
      if (!strcmp (box->set->full_maps[i], buf))
	{
	  map = i;
	  break;
	}
    }
  XawListHighlight (box->keymap_list, map);
  lr->list_index = map;
  keymap_list_cb (widget, client_data, call_data);
  move_scrollbar (box->keymap_list,
		  (((float) map) / ((float) box->set->map_count)));
  {
    int w, h;
    Pixmap p = get_keyboard_icon (XtDisplay (widget),
				  &all_kbds [box->set->kbd_index], &w, &h);
    XtVaSetValues (box->icon, XtNbitmap, p, XtNheight, h, 0);
  }
}


static void
#ifdef __STDC__
vendor_list_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
vendor_list_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  XawListReturnStruct *lr = (XawListReturnStruct *) call_data;
  struct select_kbd_box *box = (struct select_kbd_box *) client_data;
  int vendor = lr->list_index;
  const char *v = vendors[vendor];
  static char *list[255];
  int kbd;
  int i, j;

  for (i = 0; i < keyboard_set_count; i++)
    if (!strcmp(v, keyboard_sets[i].vendor))
      break;

  current_vendor_offset = i;

  j = 0;
  while (keyboard_sets[i].type &&
	 !strcmp(v, keyboard_sets[i].vendor))
    list[j++] = keyboard_sets[i++].type;
  list [j] = 0;

  kbd = 0;
  if (box->set)
    {
      char *s1 = strdup (box->keyboard->keyboard.kbd_style);
      char *s2 = strchr (s1, '(');
      if (s2) *s2 = 0;
      for (i = 0; list[i]; i++)
	if (!strcmp (s1, list[i]))
	  {
	    kbd = i;
	    break;
	  }
      free (s1);
    }

  XawListChange (box->keyboard_list, list, 0, 0, True);
  XawListHighlight (box->keyboard_list, kbd);
  lr->list_index = kbd;

  keyboard_list_cb (widget, client_data, call_data);
}


static struct select_kbd_box *
#ifdef __STDC__
make_select_kbd_dbox (KeyboardWidget widget)
#else /* ! __STDC__ */
make_select_kbd_dbox (widget)
     KeyboardWidget widget;
#endif /* ! __STDC__ */
{
  struct select_kbd_box *box = (struct select_kbd_box *)
    malloc (sizeof (struct select_kbd_box));
  Arg av [20];
  int ac = 0;
  Widget toplevel, box1, box2;
  Widget button_box, vendor_box, keyboard_box, keymap_box;
  Widget prev;
  Widget vendor_list, kbd_list, map_list;
  Widget vendor_vp, kbd_vp, map_vp;

  make_kbd_lists ();

  toplevel = XtCreatePopupShell ("selectKbd", transientShellWidgetClass,
				 XtParent ((Widget) widget), av, ac);
  box1 = XtCreateManagedWidget ("vertical", panedWidgetClass, toplevel, av,ac);
  box->label = make_label (box1, "label", 0, 0, 0);
  box->label2 = make_label (box1, "label2", "", 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNorientation, "horizontal"); ac++;
  box2 = XtCreateManagedWidget ("horizontal", panedWidgetClass, box1, av, ac);

  ac = 0;
  vendor_box = XtCreateManagedWidget ("vendorBox", formWidgetClass,
					box2, av, ac);
  prev = make_label (vendor_box, "vendors", 0, 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNfromVert, prev); ac++;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainRight); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainBottom); ac++;
  vendor_vp = XtCreateManagedWidget ("vendorsVp", viewportWidgetClass,
				     vendor_box, av, ac);
  ac = 0;
  XtSetArg (av[ac], XtNlist, vendors); ac++;
  vendor_list = XtCreateManagedWidget ("vendorsList", listWidgetClass,
				       vendor_vp, av, ac);
  XtAddCallback (vendor_list, XtNcallback, vendor_list_cb, (XtPointer) box);

  /* Gag!  These lists won't size themselves correctly. */
  XtVaSetValues (vendor_list, XtNwidth, vendor_list->core.width + 20, 0);

  ac = 0;
  keyboard_box = XtCreateManagedWidget ("keyboardBox", formWidgetClass,
					box2, av, ac);
  prev = make_label (keyboard_box, "keyboards", 0, 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNfromVert, prev); ac++;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainRight); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainBottom); ac++;
  kbd_vp = XtCreateManagedWidget ("keyboardsVp", viewportWidgetClass,
				  keyboard_box, av, ac);
  ac = 0;


  {
    static char *dummy[2];
    dummy[0] = longest_type;
    dummy[1] = 0;
    ac = 0;
    XtSetArg (av[ac], XtNlist, dummy); ac++;
    kbd_list = XtCreateManagedWidget ("keyboardsList", listWidgetClass, kbd_vp,
				      av, ac);
    XtAddCallback (kbd_list, XtNcallback, keyboard_list_cb, (XtPointer) box);

    /* Gag!  These lists won't size themselves correctly. */
    XtVaSetValues (kbd_list, XtNwidth, kbd_list->core.width + 20, 0);
  }

  ac = 0;
  keymap_box = XtCreateManagedWidget ("keymapBox", formWidgetClass,
				      box2, av, ac);
  prev = make_label (keymap_box, "keymaps", 0, 0, 0);
  ac = 0;
  XtSetArg (av[ac], XtNfromVert, prev); ac++;
  XtSetArg (av[ac], XtNleft, XtChainLeft); ac++;
  XtSetArg (av[ac], XtNright, XtChainRight); ac++;
  XtSetArg (av[ac], XtNtop, XtChainTop); ac++;
  XtSetArg (av[ac], XtNbottom, XtChainBottom); ac++;
  map_vp = XtCreateManagedWidget ("keymapsVp", viewportWidgetClass,
				  keymap_box, av, ac);
  {
    static char *dummy[2];
    dummy[0] = longest_map;
    dummy[1] = 0;
    ac = 0;
    XtSetArg (av[ac], XtNlist, dummy); ac++;
    map_list = XtCreateManagedWidget ("keymapsList", listWidgetClass, map_vp,
				      av, ac);
    XtAddCallback (map_list, XtNcallback, keymap_list_cb, (XtPointer) box);

    /* Gag!  These lists won't size themselves correctly. */
    XtVaSetValues (map_list, XtNwidth, map_list->core.width + 20, 0);
  }
  ac = 0;
  XtSetArg (av[ac], XtNskipAdjust, True); ac++;
  button_box = XtCreateManagedWidget ("buttons", boxWidgetClass, box1, av, ac);

  prev = make_button (button_box, "abort", 0, prev, 0, kbd_abort_button_cb,
		      box, 0);
  prev = make_button (button_box, "ok",    0, prev, 0, kbd_ok_button_cb,
		      box, 0);
  prev = make_label (button_box, "spacer", "", 0, prev);
  box->icon = make_label (button_box, "kbd_icon", 0, prev, 0);

  box->keyboard = 0;
  box->shell = toplevel;
  box->vendor_list = vendor_list;
  box->keyboard_list = kbd_list;
  box->keymap_list = map_list;
  box->set = 0;
  box->map = 0;
  return box;
}

void
#ifdef __STDC__
pop_up_kbd_dbox (Widget parent, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
pop_up_kbd_dbox (parent, client_data, call_data)
     Widget parent;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  KeyboardWidget widget = *((KeyboardWidget *) client_data);
  struct select_kbd_box *select_kbd_box =
    widget->keyboard.key_menus->select_kbd_box;

  select_kbd_box->keyboard = widget;
  XtVaSetValues (select_kbd_box->label2, XtNlabel, choose_kbd_message, 0);
  choose_kbd_dubious_p = 0;
  choose_kbd_message [0] = 0;

  {
    Widget topmost = parent;
    int x, y, w, h;
    XtRealizeWidget (select_kbd_box->shell);
    /* #### It'd be nice to wait here until it was mapped... */
    w = select_kbd_box->shell->core.width;
    h = select_kbd_box->shell->core.height;
    while (topmost->core.parent)
      topmost = topmost->core.parent;
    if (topmost->core.width < w) x = topmost->core.x;
    else x = topmost->core.x + ((topmost->core.width - w) / 2);
    if (topmost->core.height < h) y = topmost->core.y;
    else y = topmost->core.y + ((topmost->core.height - h) / 2);
    XtMoveWidget (select_kbd_box->shell, x, y);
  }

  {
    XawListReturnStruct lr;
    int this_vendor = 0;
    int this_kbd = 0;
    int this_vendor_start = 0;
    int i, j;
    char buf[255];
    const char *last_vendor = 0;

    make_long_kbd_name(widget->keyboard.vendor,
		       widget->keyboard.kbd_style,
		       buf);
    for (i = 0; i <= keyboard_set_count; i++)
      {
	if (last_vendor && !!strcmp(last_vendor, keyboard_sets[i].vendor))
	  {
	    this_vendor_start = i;
	    this_vendor++;
	    this_kbd = 0;
	  }
	last_vendor = keyboard_sets[i].vendor;

	for (j = 0; j < keyboard_sets[i].map_count; j++)
	  if (!strcmp (keyboard_sets[i].full_maps[j], buf))
	    {
	      this_kbd = i - this_vendor_start;
	      goto out;
	    }
      }
  out:
    lr.list_index = this_vendor;
    XawListHighlight (select_kbd_box->vendor_list, this_vendor);
    move_scrollbar (select_kbd_box->vendor_list,
		    (((float) this_vendor) / ((float) vendor_count)));
    vendor_list_cb ((Widget) widget,
		    (void *) select_kbd_box,
		    (void *) &lr);

    lr.list_index = this_kbd;
    XawListHighlight (select_kbd_box->keyboard_list, this_kbd);
/*    move_scrollbar (select_kbd_box->keyboard_list,
		     (((float) this_kbd) / ((float) keyboard_set_count)));
 */
    keyboard_list_cb ((Widget) widget,
		      (void *) select_kbd_box,
		      (void *) &lr);
  }
  XtPopup (select_kbd_box->shell, XtGrabNonexclusive);
}



static void
#ifdef __STDC__
yorn_button_cb (Widget widget, XtPointer client_data, XtPointer call_data)
#else /* ! __STDC__ */
yorn_button_cb (widget, client_data, call_data)
     Widget widget;
     XtPointer client_data, call_data;
#endif /* ! __STDC__ */
{
  *((int *) client_data) = 1;
}


static int
#ifdef __STDC__
y_or_n_p_with_args (KeyboardWidget widget,
		    char *name,
		    char *name0, char *name1, char *name2,
		    char *arg0, char *arg1, char *arg2, char *arg3,
		    char *arg4, char *arg5)
#else /* ! __STDC__ */
y_or_n_p_with_args (widget, name,
		    name0, name1, name2,
		    arg0, arg1, arg2, arg3, arg4, arg5)
     KeyboardWidget widget;
     char *name;
     char *name0, *name1, *name2;
     char *arg0, *arg1, *arg2, *arg3, *arg4, *arg5;
#endif /* ! __STDC__ */
{
  XtAppContext app = XtWidgetToApplicationContext ((Widget) widget);
  Widget topmost = (Widget) widget;
  Widget label;
  XEvent event;
  int x, y, w, h;
  Arg av [10];
  int ac = 0;
  Widget shell, box1, box2, prev;
  int ans [3];

  shell = XtCreatePopupShell (name, transientShellWidgetClass,
			      (Widget) widget, av, ac);
  box1 = XtCreateManagedWidget ("paned", panedWidgetClass, shell, av, ac);
  label = make_label (box1, "label", 0, 0, 0);
  if (arg0)  /* format into the label if desired. */
    {
      char *old_string;
      char new_string [4000];
      ac = 0;
      XtSetArg (av [ac], XtNlabel, &old_string); ac++;
      XtGetValues (label, av, ac);
      if (!strcmp (old_string, XtName (label)))
	strcpy (new_string, "ERROR: RESOURCES ARE NOT INSTALLED CORRECTLY");
      else
	sprintf (new_string, old_string, arg0, arg1, arg2, arg3, arg4, arg5);
      ac = 0;
      XtSetArg (av [ac], XtNlabel, new_string); ac++;
      XtSetValues (label, av, ac);
    }
  ac = 0;
  XtSetArg (av[ac], XtNorientation, "horizontal"); ac++;
  box2 = XtCreateManagedWidget ("buttons", boxWidgetClass, box1, av, ac);
  prev = 0;
  if (name0) prev = make_button (box2,name0,0,prev,0,yorn_button_cb,&ans[0],0);
  if (name1) prev = make_button (box2,name1,0,prev,0,yorn_button_cb,&ans[1],0);
  if (name2) prev = make_button (box2,name2,0,prev,0,yorn_button_cb,&ans[2],0);
  XtRealizeWidget (shell);
  w = shell->core.width;
  h = shell->core.height;
  while (topmost->core.parent)
    topmost = topmost->core.parent;
  if (topmost->core.width < w) x = topmost->core.x;
  else x = topmost->core.x + ((topmost->core.width - w) / 2);
  if (topmost->core.height < h) y = topmost->core.y;
  else y = topmost->core.y + ((topmost->core.height - h) / 2);
  XtMoveWidget (shell, x, y);

  XtPopup (shell, XtGrabNonexclusive);
  memset (ans, 0, sizeof (ans));
  while (! (ans[0] || ans[1] || ans[2]))
    {
      XtAppNextEvent (app, &event);
      if (event.xany.type == KeymapNotify)
	keyboard_handle_keymap_notify ((Widget) widget, 0, &event, 0);
      else if (event.xany.type == MappingNotify)
	keyboard_handle_mapping_notify ((Widget) widget, 0, &event, 0);
      XtDispatchEvent (&event);
    }
  XtPopdown (shell);
  XtDestroyWidget (shell);
  if (ans[0]) return 0;
  if (ans[1]) return 1;
  if (ans[2]) return 2;
  exit (-69);
}

static int
#ifdef __STDC__
y_or_n_p (KeyboardWidget widget,
	  char *name, char *name0, char *name1, char *name2)
#else /* ! __STDC__ */
y_or_n_p (widget, name, name0, name1, name2)
     KeyboardWidget widget;
     char *name, *name0, *name1, *name2;
#endif /* ! __STDC__ */
{
  return y_or_n_p_with_args (widget, name, name0, name1, name2, 0,0,0,0,0,0);
}


KeyWidget
#ifdef __STDC__
prompt_for_key (KeyboardWidget keyboard, char *msg)
#else /* ! __STDC__ */
prompt_for_key (keyboard, msg)
     KeyboardWidget keyboard;
     char *msg;
#endif /* ! __STDC__ */
{
  XtAppContext app = XtWidgetToApplicationContext ((Widget) keyboard);
  KeyWidget key;
  XEvent event;
  message (keyboard, msg);

  if (XGrabPointer (XtDisplay (keyboard), XtWindow (keyboard), True,
		    ButtonPressMask | ButtonReleaseMask,
		    GrabModeAsync, GrabModeAsync, 0,
		    keyboard->keyboard.select_cursor,
		    CurrentTime))
    {
      XBell (XtDisplay (keyboard), 0);
      message (keyboard, "Grab failed.");
      return 0;
    }
  
  while (1)
    {
      XtAppNextEvent (app, &event);

      if (event.xany.type == ButtonPress)
	{
	  XUngrabPointer (XtDisplay (keyboard), CurrentTime);
	  if ((key = keyboard->keyboard.key_under_mouse))
	    return key;
	  XBell (XtDisplay (keyboard), 0);
	  message (keyboard, "You must click on a key.");
	  return 0;
	}
      else if (event.xany.type == ButtonRelease ||
	       event.xany.type == KeyPress ||
	       event.xany.type == KeyRelease)
	{
	  XUngrabPointer (XtDisplay (keyboard), CurrentTime);
	  XBell (XtDisplay (keyboard), 0);
	  XPutBackEvent (XtDisplay (keyboard), &event);
	  message (keyboard, "Aborted.");
	  return 0;
	}
      else
	{
	  if (event.xany.type == KeymapNotify)
	    keyboard_handle_keymap_notify ((Widget) keyboard, 0, &event, 0);
	  else if (event.xany.type == MappingNotify)
	    keyboard_handle_mapping_notify ((Widget) keyboard, 0, &event, 0);
	  XtDispatchEvent (&event);
	}
    }
}


/* What a mess the X keyboard model is... */

#include <X11/keysym.h>

static char *
#ifdef __STDC__
index_to_name (int index)
#else /* ! __STDC__ */
index_to_name (index)
     int index;
#endif /* ! __STDC__ */
{
  return (index == ShiftMapIndex ? "Shift" :
	  index == LockMapIndex ? "Lock" :
	  index == ControlMapIndex ? "Control" :
	  index == Mod1MapIndex ? "1" :
	  index == Mod2MapIndex ? "2" :
	  index == Mod3MapIndex ? "3" :
	  index == Mod4MapIndex ? "4" :
	  index == Mod5MapIndex ? "5" :
	  "???");
}

static char *
#ifdef __STDC__
keysym_to_name (KeySym keysym)
#else /* ! __STDC__ */
keysym_to_name (keysym)
     KeySym keysym;
#endif /* ! __STDC__ */
{
  char *n = XKeysymToString (keysym);
  if (! n) /* ought not happen, but does if XKeysymDB isn't installed right */
    {
      n = (char *) malloc (20); /* leaks! */
      sprintf (n, "Unknown-KeySym-0x%X", (int) keysym);
    }
  return n;
}

static int 
#ifdef __STDC__
stop_the_insanity (KeyboardWidget widget,
		   int keycode,
		   KeySym *keysyms,
		   int count,
		   unsigned long modbits,
		   XModifierKeymap *modmap)
#else /* ! __STDC__ */
stop_the_insanity (widget, keycode, keysyms, count, modbits, modmap)
     KeyboardWidget widget;
     int keycode;
     KeySym *keysyms;
     int count;
     unsigned long modbits;
     XModifierKeymap *modmap;
#endif /* ! __STDC__ */
{
  int i;
  KeySym type = 0;		/* The canonical modifier keysym on this key */
  KeySym basic_keysym = 0;	/* The non-canonical version */
  KeySym companion = 0;		/* The "other" version of this key */

  /* Check that the keysyms that are attached to this key are compatible:
     It is incorrect to put Control_[LR] and Meta_[LR] on the same key.
   */
  {
    KeySym conflict = 0;
    KeySym nonmod = 0;
    for (i = 0; i < count && !conflict; i++)
      switch ((int) keysyms [i])
	{
#define check(k)				\
	case k:					\
	  if (type && type != k)		\
	    conflict = keysyms [i];		\
	  else					\
	    type = k,				\
	    basic_keysym = keysyms[i];		\
	  break
	case XK_Meta_R:    check (XK_Meta_L);
	case XK_Super_R:   check (XK_Super_L);
	case XK_Hyper_R:   check (XK_Hyper_L);
	case XK_Alt_R:     check (XK_Alt_L);
	case XK_Control_R: check (XK_Control_L);
	case XK_Shift_R:   check (XK_Shift_L);
	check (XK_Shift_Lock);
	check (XK_Caps_Lock);
	check (XK_Mode_switch);
#undef check
	default:
	  nonmod = keysyms [i];
	  break;
	}

    switch ((int) basic_keysym)
      {
      case XK_Meta_L:    companion = XK_Meta_R;    break;
      case XK_Super_L:   companion = XK_Super_R;   break;
      case XK_Hyper_L:   companion = XK_Hyper_R;   break;
      case XK_Alt_L:     companion = XK_Alt_R;     break;
      case XK_Control_L: companion = XK_Control_R; break;
      case XK_Shift_L:   companion = XK_Shift_R;   break;
      case XK_Meta_R:    companion = XK_Meta_L;    break;
      case XK_Super_R:   companion = XK_Super_L;   break;
      case XK_Hyper_R:   companion = XK_Hyper_L;   break;
      case XK_Alt_R:     companion = XK_Alt_L;     break;
      case XK_Control_R: companion = XK_Control_L; break;
      case XK_Shift_R:   companion = XK_Shift_L;   break;
      }

    if (nonmod && type)	/* all modifier syms and non-mod syms conflict. */
      {
	conflict = type;
	type = nonmod;
      }
    if (conflict)
      return (y_or_n_p_with_args (widget, "keysymConflictWarning",
				  "ok", "cancel", 0,
				  keysym_to_name (type),
				  keysym_to_name (conflict),
				  0, 0, 0, 0));
  }


  /* Check that the modifier bits are compatible with the keysyms:
     It is incorrect to put ModControl on a key with any keysym other
     than Control_L or Control_R.
   */
  {
    int losing = 0;
    int bad_index = 0;
    if (modbits & ControlMask && type != XK_Control_L)
      losing = 1, bad_index = ControlMapIndex;
    else if (modbits & ShiftMask && type != XK_Shift_L)
      losing = 1, bad_index = ShiftMapIndex;
    else if (modbits & LockMask && type != XK_Caps_Lock &&
				   type != XK_Shift_Lock)
      losing = 1, bad_index = LockMapIndex;

    if (losing)
      return (y_or_n_p_with_args (widget, "badModifiersWarning",
				  "ok", "cancel", 0,
				  index_to_name (bad_index),
				  (bad_index == ShiftMapIndex ? "Shift_L" :
				   bad_index == LockMapIndex ? "Caps_Lock" :
				   bad_index == ControlMapIndex ? "Control_L" :
				   "<<INTERNAL ERROR>>"),
				  (bad_index == ShiftMapIndex ? "Shift_R" :
				   bad_index == LockMapIndex ? "Shift_Lock" :
				   bad_index == ControlMapIndex ? "Control_R" :
				   "<<INTERNAL ERROR>>"),
				  index_to_name (bad_index),
				  0, 0));
  }

  /* Do the opposite check - the previous code checked for the case of
     attaching ModControl to Meta_L, but this checks for attaching Mod1
     to Control_L. */
  if ((type == XK_Shift_L || type == XK_Control_L ||
       type == XK_Shift_Lock || type == XK_Caps_Lock) &&
      (modbits & (~ (ShiftMask | LockMask | ControlMask))))
    return (y_or_n_p_with_args (widget, "badModifiersWarning2",
				"ok", "cancel", 0,
				keysym_to_name (basic_keysym),
				(type == XK_Shift_L ? "Shift" :
				 type == XK_Control_L ? "Control" :
				 type == XK_Shift_Lock ? "Lock" :
				 type == XK_Caps_Lock ? "Lock" :
				 "<<INTERNAL ERROR>>"),
				(type == XK_Shift_L ? "Shift" :
				 type == XK_Control_L ? "Control" :
				 type == XK_Shift_Lock ? "Shift_Lock" :
				 type == XK_Caps_Lock ? "Caps_Lock" :
				 "<<INTERNAL ERROR>>"),
				0, 0, 0));

  /* Check that the key is generating at most one modifier bit.
     The behavior of more than one modifier bit is undefined.
     If this is a modifier keysym, warn if it has no modifier bits
     at all (which has defined behavior, and may be what is desired,
     but which novices are likely to do by accident.)
   */
  {
    int bitcount = 0;
    int i;
    for (i = 0; i < 8; i++)
      if (modbits & (1<<i)) bitcount++;
    if (bitcount > 1)
      return (y_or_n_p (widget, "multipleModifiersWarning",
			"ok", "cancel", 0));
    else if (bitcount == 0 && type != 0)
      return (y_or_n_p_with_args (widget, "noModifiersWarning",
				  "ok", "cancel", 0,
				  keysym_to_name (type), 0, 0, 0, 0, 0));
  }


  /* Check that some other (incompatible) key is not generating the same
     modifiers as this key. */
  {
    Display *dpy = XtDisplay ((Widget) widget);

    unsigned long conflict_code = 0;
    KeySym conflict_sym = 0;
    int conflict_bit = 0;
    int this_bit = 0;

    int modifier_index, modifier_key;
    int mkpm = modmap->max_keypermod;

    for (modifier_index = 0; modifier_index < 8; modifier_index++)
      /* Ignore modifier bits which this key does not generate. */
      if ((1 << modifier_index) & modbits)
	for (modifier_key = 0; modifier_key < mkpm; modifier_key++)
	  {
	    int column;
	    KeySym last_sym = 0;
	    for (column = 0; column < 4; column += 2)
	      {
		KeyCode code2 = modmap->modifiermap [modifier_index * mkpm
						     + modifier_key];
		KeySym sym = (code2
			      ? XKeycodeToKeysym (dpy, code2, column)
			      : 0);
		KeySym this = 0;
		if (!sym) continue;
		if (sym == last_sym) continue;
		last_sym = sym;
		switch ((int) sym)
		  {
		  case XK_Meta_R:    this = XK_Meta_L; break;
		  case XK_Super_R:   this = XK_Super_R; break;
		  case XK_Hyper_R:   this = XK_Hyper_L; break;
		  case XK_Alt_R:     this = XK_Alt_L; break;
		  case XK_Control_R: this = XK_Control_L; break;
		  case XK_Shift_R:   this = XK_Shift_L; break;
		  default:           this = sym; break;
		  }

		if (this != type &&		/* conflicting keysyms */
		    /* but ignore conflicts with the previous version of
		       this very key! */
		    code2 != keycode)
		  {
		    conflict_code = code2;
		    conflict_sym = sym;
		    conflict_bit = modifier_index;
		    goto DONE;
		  }
	      }
	  }
  DONE:
    if (conflict_code)
      {
	KeyWidget kw = keycode_to_key (widget, conflict_code);
	return (y_or_n_p_with_args (widget, "modifiersConflictWarning",
				    "ok", "cancel", 0,
				    keysym_to_name (basic_keysym),
				    index_to_name (conflict_bit),
				    (char *) conflict_code,
				    (kw ? kw->key.key_name : "???"),
				    keysym_to_name (conflict_sym),
				    0));
      }


    /* Check that the semantically equivalent keys do not generate
       different modifier bits than this one. */

    conflict_sym = 0;
    conflict_bit = 0;
    conflict_code = 0;

    for (modifier_index = 0; modifier_index < 8; modifier_index++)
      /* Ignore modifier bits which this key generates. */
      if ((1 << modifier_index) & modbits)
	this_bit = modifier_index;
      else if (conflict_code)
	;
      else
	for (modifier_key = 0; modifier_key < mkpm; modifier_key++)
	  {
	    int column;
	    for (column = 0; column < 4; column += 2)
	      {
		KeyCode code2 = modmap->modifiermap [modifier_index * mkpm
						     + modifier_key];
		KeySym sym = (code2
			      ? XKeycodeToKeysym (dpy, code2, column)
			      : 0);
		if (sym &&
		    !conflict_code &&
		    (sym == basic_keysym || sym == companion) &&
		    code2 != keycode)
		  {
		    conflict_code = code2;
		    conflict_sym = sym;
		    conflict_bit = modifier_index;
		    /* keep going to find this_bit */
		    break;
		  }
	      }
	  }

    if (conflict_code)
      {
	KeyWidget kw = keycode_to_key (widget, conflict_code);
	return (y_or_n_p_with_args (widget, "modifiersConflictWarning2",
				    "ok", "cancel", 0,
				    keysym_to_name (basic_keysym),
				    index_to_name (this_bit),
				    (char *) conflict_code,
				    (kw ? kw->key.key_name : "???"),
				    keysym_to_name (conflict_sym),
				    index_to_name (conflict_bit)
				    ));
      }
  }

  /* Should we also issue a message along the lines of

       This key is not normally a `chording' key (that is, a key that is
       held down to modify some other keypress.)  It is unlikely that
       attaching a modifier to it will do anything sensible.  If you want
       this to be a {Control,Shift,Lock,Meta} key, change its keysym to
       ***_L or ***_R.

     That wouldn't be appropriate for the default layout of the OpenWound
     keyboard, which attaches modifiers to random function keys (I imagine
     this has something to do with drag-and-drop, but I don't know how it
     works.)

     Actually maybe a different message would be appropriate for Multi_key,
     since people sometimes misinterpret the description of that key as being
     a modifier key, when in fact it's a prefix key and shouldn't have any
     modifier bits on it.

   */

  return 0;
}
