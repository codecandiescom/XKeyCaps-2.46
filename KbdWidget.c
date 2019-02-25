/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1995, 1996, 1997 
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

#include <stdio.h>
#include "KbdWidgetP.h"
#include "KeyWidgetP.h"
#include <X11/Shell.h>	/* for XtNiconPixmap */
#include "xkeycaps.h"
#include "kbddef.h"

#undef MAX
#undef MIN
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

static void KbdResize P((Widget));
static void KbdRealize P((Widget, Mask *, XSetWindowAttributes *));
static void KbdInitialize P((Widget, Widget, ArgList, Cardinal*));
static void ChangeManaged P((Widget));
static XtGeometryResult GeometryManager P((Widget w,
					   XtWidgetGeometry *request,
					   XtWidgetGeometry *reply));
static XtGeometryResult PreferredSize P((Widget w,
					 XtWidgetGeometry *request,
					 XtWidgetGeometry *preferred));
static void make_key_widgets P((KeyboardWidget widget,
				const struct keyboard_instance *kbd));
static void set_icon_pixmap P((KeyboardWidget keyboard,
			       const struct keyboard_instance *kbd));


static XtResource keyboard_resources [] = {
  { "keyboard", "Keyboard", XtRString, sizeof (String),
      XtOffset (KeyboardWidget, keyboard.kbd_name), XtRString, "" },
#ifdef HAVE_XTRAP
  {  "useXTrap", "UseXTrap", XtRBoolean, sizeof (XtRBoolean),
       XtOffset (KeyboardWidget, keyboard.use_xtrap), XtRImmediate, False },
#endif
  { "selectCursor", "Cursor", XtRCursor, sizeof (Cursor),
      XtOffset (KeyboardWidget, keyboard.select_cursor), XtRString,
      "crosshair" }
};

XtActionsRec keyboard_actions [] = {
  {"HighlightKey",	highlight_key_action},
  {"UnhighlightKey",	unhighlight_key_action},
  {"ToggleKey",		toggle_key_action},
  {"SimulateKeyPress",	simulate_KeyPress_action},
  {"SimulateKeyRelease",simulate_KeyRelease_action},
  {"TrackKey",		track_key_action},
  {"UntrackKey",	untrack_key_action},
  {"DescribeKey",	describe_key_action}
};


char keyboard_default_translations[] = "\
<Motion>:	DescribeKey(mouse, unlessTracking)	\n\
\
<KeyDown>:	HighlightKey()				\
		DescribeKey(unlessMod)			\
		DescribeKey(displayed)			\
		SimulateKeyPress()			\n\
\
<KeyUp>:	UnhighlightKey()			\
		DescribeKey(displayed)			\
		SimulateKeyRelease()			\n\
\
<Btn1Down>:	HighlightKey(unlessMod)			\
		ToggleKey(ifMod)			\
		TrackKey(unlessMod)			\
		SimulateKeyPress(ifHighlighted)		\
		SimulateKeyRelease(unlessHighlighted)	\n\
\
<Btn1Up>:	UntrackKey(highlighted)			\
		SimulateKeyRelease(highlighted, unlessMod) \
		UnhighlightKey(highlighted, unlessMod)	\n\
\
<Btn3Down>:	XawPositionSimpleMenu(keyMenu)		\
		MenuPopup(keyMenu)			\n\
";

KeyboardClassRec keyboardClassRec = {
    { /*
       *	core_class fields
       */
    /* superclass		*/	(WidgetClass)&compositeClassRec,
    /* class_name		*/	"Keyboard",
    /* widget_size		*/	sizeof (KeyboardRec),
    /* class_initialize		*/	NULL,
    /* class_part_initialize	*/	NULL,
    /* class_inited		*/	FALSE,
    /* initialize		*/	KbdInitialize,
    /* initialize_hook		*/	NULL,
    /* realize			*/	KbdRealize,
    /* actions			*/	keyboard_actions,
    /* num_actions		*/	XtNumber (keyboard_actions),
    /* resources		*/	keyboard_resources,
    /* resource_count		*/	XtNumber (keyboard_resources),
    /* xrm_class		*/	NULLQUARK,
    /* compress_motion		*/	TRUE,
    /* compress_exposure	*/	TRUE,
    /* compress_enterleave	*/	TRUE,
    /* visible_interest		*/	FALSE,
    /* destroy			*/	NULL,
    /* resize			*/	KbdResize,
    /* expose			*/	NULL,
    /* set_values		*/	NULL,
    /* set_values_hook		*/	NULL,
    /* set_values_almost	*/	XtInheritSetValuesAlmost,
    /* get_values_hook		*/	NULL,
    /* accept_focus		*/	NULL,
    /* version			*/	XtVersion,
    /* callback_private		*/	NULL,
    /* tm_table			*/	keyboard_default_translations,
    /* query_geometry		*/	PreferredSize,
    /* display_accelerator	*/	NULL,
    /* extension		*/	NULL
    },
    { /*
       *	composite_class fields
       */
    /* geometry_manager		*/	GeometryManager,
    /* change_managed		*/	ChangeManaged,
    /* insert_child		*/	XtInheritInsertChild,
    /* delete_child		*/	XtInheritDeleteChild,
    /* extension		*/	NULL
    }
};

WidgetClass keyboardWidgetClass = (WidgetClass) &keyboardClassRec;

static void 
#ifdef __STDC__
KbdInitialize (Widget r, Widget n, ArgList al, Cardinal *ac)
#else /* ! __STDC__ */
KbdInitialize (r, n, al, ac)
     Widget r, n;
     ArgList al;
     Cardinal *ac;
#endif /* ! __STDC__ */
{
  KeyboardWidget new = (KeyboardWidget) n;
  const struct keyboard_instance *kbd =
    choose_kbd (XtDisplay (new), new->keyboard.kbd_name);

  new->keyboard.short_name = kbd->short_name;
  new->keyboard.vendor = kbd->vendor;
  new->keyboard.kbd_style = kbd->kbd_style;
  new->keyboard.default_scale = kbd->keyboard_geometry->default_scale;
  new->keyboard.horiz_border = kbd->keyboard_geometry->horiz_border;
  new->keyboard.vert_border = kbd->keyboard_geometry->vert_border;

  /* Initialize the non-resource slots */
  new->keyboard.key_under_mouse = 0;
  new->keyboard.mouse_highlighted_key = 0;
  new->keyboard.documented_key = 0;
  new->keyboard.tracking_key = 0;
  new->keyboard.target_window = 0;
  new->keyboard.nrows = 0;
  new->keyboard.rows = 0;
  memset (new->keyboard.key_state_vector, 0,
	  sizeof (new->keyboard.key_state_vector));

  make_key_widgets (new, kbd);
  init_modifier_mapping (new);
  set_icon_pixmap (new, kbd);
}

static void
#ifdef __STDC__
do_layout (KeyboardWidget parent)
#else /* ! __STDC__ */
do_layout (parent)
     KeyboardWidget parent;
#endif /* ! __STDC__ */
{
  int i, j;
  int width = parent->core.width;
  int height = parent->core.height;
  int max_width = (parent->keyboard.max_width
		   + (parent->keyboard.horiz_border * 2));
  int max_height = (parent->keyboard.max_height
		    + (parent->keyboard.vert_border * 2));
  float x_scale = (float) width / (float) max_width;
  float y_scale = (float) height / (float) max_height;
  int x_off, y_off;

  if (x_scale < 1) x_scale = 1;
  if (y_scale < 1) y_scale = 1;

  /* Be square */
  if (x_scale < y_scale) y_scale = x_scale;
  else if (y_scale < x_scale) x_scale = y_scale;

  x_off = ((((float) width) - (max_width * x_scale)) / 2
	   + parent->keyboard.horiz_border * x_scale);
  y_off = ((((float) height) - (max_height * y_scale)) / 2
	   + parent->keyboard.vert_border * y_scale);
    
  if (XtWindow (parent))
    XUnmapSubwindows (XtDisplay (parent), XtWindow (parent)); /* sleazy */

  for (i = 0; i < parent->keyboard.nrows; i++)
    {
      for (j = 0; j < parent->keyboard.rows[i].nkeys; j++)
	{
	  int off;
	  KeyWidget child = parent->keyboard.rows[i].keys[j];
	  if (! child) continue;
	  off = child->core.border_width * 2 + child->key.gutter_width;
	  XtMoveWidget ((Widget) child,
			(int) (x_off + child->key.x * x_scale),
			(int) (y_off + child->key.y * y_scale));
	  XtResizeWidget ((Widget) child,
			  MAX (1, (int) (child->key.width * x_scale - off)),
			  MAX (1, (int) (child->key.height * y_scale - off)),
			  child->core.border_width);
	}
    }

  if (XtWindow (parent))
    XMapSubwindows (XtDisplay (parent), XtWindow (parent)); /* yzaels */

  parent->keyboard.x_scale = x_scale;
  parent->keyboard.y_scale = y_scale;
}


static void
#ifdef __STDC__
KbdResize (Widget w)
#else /* ! __STDC__ */
KbdResize (w)
     Widget w;
#endif /* ! __STDC__ */
{
    do_layout ((KeyboardWidget) w);
}


static XtGeometryResult
#ifdef __STDC__
PreferredSize (Widget w,
	       XtWidgetGeometry *request,
	       XtWidgetGeometry *preferred)
#else /* ! __STDC__ */
PreferredSize (w, request, preferred)
     Widget w;
     XtWidgetGeometry *request, *preferred;
#endif /* ! __STDC__ */
{
  return XtGeometryYes;
}

static XtGeometryResult
#ifdef __STDC__
GeometryManager (Widget w, XtWidgetGeometry *request, XtWidgetGeometry *reply)
#else /* ! __STDC__ */
GeometryManager (w, request, reply)
     Widget w;
     XtWidgetGeometry *request, *reply;
#endif /* ! __STDC__ */
{
  return XtGeometryNo;
}


static void
#ifdef __STDC__
ChangeManaged (Widget ww)
#else /* ! __STDC__ */
ChangeManaged (ww)
     Widget ww;
#endif /* ! __STDC__ */
{
  KeyboardWidget w = (KeyboardWidget) ww;
    if (w->core.width <= 0 || w->core.height <= 0)
      {
	int default_scale = w->keyboard.default_scale;
	int horiz = (w->keyboard.horiz_border * 2) + 1;
	int vert = (w->keyboard.vert_border * 2) + 1;
	w->core.width  = (w->keyboard.max_width + horiz) * default_scale;
	w->core.height = (w->keyboard.max_height + vert) * default_scale;
      }
    do_layout (w);
}


static void
#ifdef __STDC__
KbdRealize (Widget widget, Mask *value_mask, XSetWindowAttributes *attributes)
#else /* ! __STDC__ */
KbdRealize (widget, value_mask, attributes)
    Widget widget;
    Mask *value_mask;
    XSetWindowAttributes *attributes;
#endif /* ! __STDC__ */
{
  XtAppContext app = XtWidgetToApplicationContext (widget);
  XtAppAddActionHook (app, keyboard_track_motion_hook, (XtPointer) widget);
  if (widget->core.width == 0) widget->core.width = 10;
  if (widget->core.height == 0) widget->core.height = 10;
  XtCreateWindow (widget, (unsigned int) InputOutput,
		  (Visual *) CopyFromParent, *value_mask, attributes);
#ifdef HAVE_XTRAP
  xkeycaps_xtrap_open_connection ((KeyboardWidget) widget);
#endif
}


static void
#ifdef __STDC__
make_key_widgets (KeyboardWidget widget, const struct keyboard_instance *kbd)
#else /* ! __STDC__ */
make_key_widgets (widget, kbd)
     KeyboardWidget widget;
     const struct keyboard_instance *kbd;
#endif /* ! __STDC__ */
{
  Arg av [20];
  int ac;
  int i, j;
  int x, y;
  int max_syms = 0;
  int default_scale = widget->keyboard.default_scale;
  int nrows = kbd->keyboard_geometry->nrows;

  const struct key_strings *strings = kbd->key_strings;
  int nstrings = kbd->key_strings_count;
  const KeyCode *keycodes = kbd->keycodes;
  int ncodes = kbd->keycodes_count;
  const struct default_keycode_map *keysyms = kbd->default_keycode_map;
  int nsyms = kbd->default_keycode_map_count;

  int index = 0;

  if (nstrings != ncodes)
    fprintf (stderr, "%s: DATA ERROR: %d keycaps vs %d keycodes\n\
	There must be the same number of entries in %s-caps.h and\n\
	%s-codes.h.  There must be one for each actual key on the\n\
	keyboard, left to right, top to bottom.\n",
	     progname, nstrings, ncodes,
	     widget->keyboard.short_name,
	     widget->keyboard.short_name);

  /* Can't assert (nstrings == nsyms), because there might be more or
     less entries in the keymap than the number of keys, depending on
     the bogusness of the vendor's default map ("ghost" keycodes, keys
     that generate none or more than one keycode, etc.) */

  /* Check that the keymap doesn't have duplicates. */
  for (i = 0; i < nsyms; i++)
    for (j = i + 1; j < nsyms; j++)
      if (keysyms [j].keycode == keysyms [i].keycode)
	fprintf (stderr, "%s: DATA ERROR:\
 duplicate entry for keycode %3d (0x%02X) in %s-map.h.\n",
		 progname, keysyms [i].keycode, keysyms [i].keycode,
		 widget->keyboard.short_name);

  widget->keyboard.x_scale = widget->keyboard.y_scale = default_scale;
  ac = 0;
  XtSetArg (av[ac], XtNwidth, 10); ac++;
  XtSetArg (av[ac], XtNheight, 10); ac++;

  widget->keyboard.nrows = nrows;
  widget->keyboard.rows =
    (struct KeyWidget_row *) calloc (nrows, sizeof (struct KeyWidget_row));

  widget->keyboard.max_width = x = 0;
  widget->keyboard.max_height = y = 0;

  for (i = 0; i < nrows; i++)
    {
      int jo = 0;
      struct KeyWidget_row *row = &widget->keyboard.rows [i];
      row->nkeys = kbd->keyboard_geometry->rows [i].nkeys;
      row->height = kbd->keyboard_geometry->rows [i].height;
      row->keys = (KeyWidget *) calloc (row->nkeys, sizeof (KeyWidget));

      for (j = 0; j < row->nkeys; j++)
	{
	  KeyWidget kw = 0;
	  const struct key_geometry *key =
	    &kbd->keyboard_geometry->rows[i].keys[j];
	  const struct key_strings *ss;
	  KeyCode kk;
	  int place_holder_p = (key->height == 0);

	  if (! place_holder_p)
	    {
	      int ks_count;
	      int a = 0;
	      const char *wname;

	      if (index >= nstrings || index >= ncodes)
		{
		  fprintf (stderr, "%s: DATA ERROR:\
 reached end of caps/codes tables with keys left over at %d (%d,%d)\n",
			   progname, index - 1, j, i);
		  goto bugout;
		}

	      ss = &strings [index];
	      kk = keycodes [index];
	      index++;

	      wname = (ss->keysym_1 ? ss->keysym_1 :
		       ss->keysym_2 ? ss->keysym_2 :
		       ss->keysym_3 ? ss->keysym_3 : "blank");

	      kw = (KeyWidget) XtCreateManagedWidget (wname, keyWidgetClass,
						      (Widget) widget, av, ac);
	      kw->key.x = x;
	      kw->key.y = y;
	      kw->key.width  = key->width;
	      kw->key.height = key->height;
	      kw->key.keysym_1 = ss->keysym_1;
	      kw->key.keysym_2 = ss->keysym_2;
	      kw->key.keysym_3 = ss->keysym_3;
	      kw->key.keycode = kk;

	      /* Find the default keymap entry for this key */
	      if (kk != 0)
		for (a = 0; a < nsyms; a++)
		  if (keysyms[a].keycode == kk)
		    break;
	      if (kk == 0 || a >= nsyms)
		{
		  if (kk)
		    fprintf (stderr,
	"%s: DATA ERROR: couldn't find keymap entry for keycode %d (0x%02X)\n\
	on key `%s' at (%d,%d)\n",
			     progname, kk, kk,
			     wname, j, i);
		  kw->key.default_mods = 0;
		  memset (kw->key.default_keysyms, 0,
			  sizeof (keysyms[a].keysyms));
		}
	      else
		{
		  kw->key.default_mods = keysyms[a].default_mods;
		  memcpy (kw->key.default_keysyms,
			  keysyms[a].keysyms,
			  sizeof (keysyms[a].keysyms));

		  if (kw->key.default_mods != 0 &&
		      kw->key.default_mods != ShiftMask &&
		      kw->key.default_mods != LockMask &&
		      kw->key.default_mods != ControlMask &&
		      kw->key.default_mods != Mod1Mask &&
		      kw->key.default_mods != Mod2Mask &&
		      kw->key.default_mods != Mod3Mask &&
		      kw->key.default_mods != Mod4Mask &&
		      kw->key.default_mods != Mod5Mask)
		    {
		      fprintf (stderr,
      "%s: DATA ERROR: bogus modifier bits (0x%02X) for keycode %d (0x%02X)\n",
			       progname, (int) kw->key.default_mods,
			       keysyms[a].keycode, keysyms[a].keycode);
		    }
		}

	      /* Count up the keysyms on this key */
	      for (ks_count = 7;
		   ks_count && !kw->key.default_keysyms [ks_count];
		   ks_count--)
		;
	      if (ks_count > max_syms)
		max_syms = ks_count;

	      row->keys [jo++] = kw;
	    }
	  x += key->width;
	}

    bugout:

      row->nkeys = jo; /* less than j if there were "place-holder" keys */

      if (x > widget->keyboard.max_width)
	widget->keyboard.max_width = x;
      x = 0;
      y += row->height;
      if (y > widget->keyboard.max_height)
	widget->keyboard.max_height = y;
    }
  widget->keyboard.default_keysyms_per_code = max_syms + 1;
}


static struct icon
{
  const struct keyboard_geometry *geom;
  Pixmap pixmap, /* pixmap2, */ mask;
  int width;
  int height;
} *all_icons;
static int nicons;
static int max_icon_width;

static struct icon *
#ifdef __STDC__
find_icon (const struct keyboard_geometry *geom)
#else /* ! __STDC__ */
find_icon (geom)
     const struct keyboard_geometry *geom;
#endif /* ! __STDC__ */
{
  struct icon *i;
  for (i = all_icons; i->geom; i++)
    if (i->geom == geom) break;
  return (i->geom ? i : 0);
}

static GC draw_gc, erase_gc, mask_draw_gc, mask_erase_gc /*, invert_gc */;
static unsigned long gc_mask;
static XGCValues gc_values;

static void
#ifdef __STDC__
create_icon_pixmap (Display *dpy, const struct keyboard_geometry *geom)
#else /* ! __STDC__ */
create_icon_pixmap (dpy, geom)
     Display *dpy;
     const struct keyboard_geometry *geom;
#endif /* ! __STDC__ */
{
  int scale = 3;
  Pixmap pixmap, /* pixmap2, */ mask;
  int key_size = geom->rows[3].height; /* 4th row is a good bet */
  int icon_width = 0, icon_height = 0;
  int i, j;
  int kx, ky;
  int nrows = geom->nrows;
  Screen *screen = DefaultScreenOfDisplay (dpy);
  Window window = RootWindowOfScreen (screen);

  if (find_icon (geom))	/* already got one */
    return;

  for (i = 0; i < nrows; i++)
    {
      int ww = 0;
      if (i > 3 && geom->rows[i].nkeys == 0)
	break;	/* this is the "second" image of the keyboard */
      for (j = 0; j < geom->rows[i].nkeys; j++)
	ww += geom->rows[i].keys[j].width;
      icon_height += geom->rows[i].height;
      if (ww > icon_width) icon_width = ww;
    }
  nrows = i;
  icon_width  = (icon_width  * scale / key_size) + scale + scale;
  icon_height = (icon_height * scale / key_size) + scale + scale;
  
  pixmap  = XCreatePixmap (dpy, window, icon_width, icon_height, 1);
/*  pixmap2 = XCreatePixmap (dpy, window, icon_width, icon_height, 1); */
  mask    = XCreatePixmap (dpy, window, icon_width, icon_height, 1);
  
  if (! draw_gc)
    {
      /* It seems that 1 means "foreground" and 0 means "background" in both
	 WM icon bitmaps, and in in Athena SmeBSB buttons.  This holds true
	 on a mono NCD X terminal with NCDwm and whitepixel=1, and on a color
	 Sparc with MIT R5, mwm, and whitepixel=0.

         It would be nice if the non-key part of the icon were black (fg) for
	 the benefit of WMs which ignore the ICON_MASK, but in the menu it
	 looks better as white.
       */
      gc_mask = GCFunction | GCForeground;
      gc_values.function = GXcopy;
      gc_values.foreground = 1;  /* not {White,Black}PixelOfScreen (screen) */
      erase_gc = XCreateGC (dpy, pixmap, gc_mask, &gc_values);
      gc_values.foreground = 0;  /* not {Black,White}PixelOfScreen (screen) */
      draw_gc = XCreateGC (dpy, pixmap, gc_mask, &gc_values);
      gc_values.foreground = 1;
      mask_draw_gc = XCreateGC (dpy, mask, gc_mask, &gc_values);
      gc_values.foreground = 0;
      mask_erase_gc = XCreateGC (dpy, mask, gc_mask, &gc_values);
/*      gc_values.function = GXcopyInverted;
      invert_gc = XCreateGC (dpy, pixmap2, gc_mask, &gc_values); */
    }

  XFillRectangle (dpy, pixmap, erase_gc, 0, 0, icon_width, icon_height);
  XFillRectangle (dpy, pixmap, draw_gc, 1, 1, icon_width-2, icon_height-2);
  XFillRectangle (dpy, mask, mask_erase_gc, 0, 0, icon_width, icon_height);

  ky = 0;
  for (i = 0; i < nrows; i++)
    {
      kx = 0;
      for (j = 0; j < geom->rows[i].nkeys; j++)
	{
	  const struct key_geometry *key = &geom->rows[i].keys[j];
	  int x, y, x2, y2, w, h;

	  x = (kx * scale / key_size) + scale;
	  y = (ky * scale / key_size) + scale;
	  x2 = ((kx + key->width)  * scale / key_size) + scale;
	  y2 = ((ky + key->height) * scale / key_size) + scale;
	  w = x2-x-1; if (w<0) w=1;
	  h = y2-y-1; if (h<0) h=1;
	  if (key->height != 0)
	    {
	      XFillRectangle (dpy, pixmap, erase_gc, x-1, y-1, w+2, h+2);
	      XFillRectangle (dpy, pixmap, draw_gc, x, y, w, h);
	      XFillRectangle (dpy, mask, mask_draw_gc, x-1, y-1, w+2, h+2);
	    }
	  kx += key->width;
	}
      ky += geom->rows[i].height;
    }
/*  XCopyArea (dpy, pixmap, pixmap2, invert_gc, 0, 0, icon_width, icon_height,
	     0, 0);*/

  if (icon_width > max_icon_width)
    max_icon_width = icon_width;
  all_icons [nicons].geom = geom;
  all_icons [nicons].pixmap = pixmap;
/*  all_icons [nicons].pixmap2 = pixmap2; */
  all_icons [nicons].mask = mask;
  all_icons [nicons].width = icon_width;
  all_icons [nicons].height = icon_height;
  nicons++;
}

void
#ifdef __STDC__
create_icon_pixmaps (Display *dpy)
#else /* ! __STDC__ */
create_icon_pixmaps (dpy)
     Display *dpy;
#endif /* ! __STDC__ */
{
  int kbd_count = 0;
  while (all_kbds [kbd_count++].short_name)
    ;
  all_icons = (struct icon *) calloc (kbd_count, sizeof (struct icon));
  kbd_count--;
  max_icon_width = 0;
  draw_gc = 0;
  nicons = 0;
}

static void
#ifdef __STDC__
set_icon_pixmap (KeyboardWidget keyboard, const struct keyboard_instance *kbd)
#else /* ! __STDC__ */
set_icon_pixmap (keyboard, kbd)
     KeyboardWidget keyboard;
     const struct keyboard_instance *kbd;
#endif /* ! __STDC__ */
{
  Arg av [5];
  int ac;
  Widget shell = XtParent (keyboard);
  struct icon *icon = find_icon (kbd->keyboard_geometry);
  if (! icon) /* not in the cache */
    {
      create_icon_pixmap (XtDisplay (keyboard), kbd->keyboard_geometry);
      icon = find_icon (kbd->keyboard_geometry);
      if (! icon) abort ();
    }
  while (XtParent (shell))
    shell = XtParent (shell);
  ac = 0;
  XtSetArg (av [ac], XtNiconPixmap, icon->pixmap); ac++;
  XtSetArg (av [ac], XtNiconMask, icon->mask); ac++;
  XtSetValues (shell, av, ac);
}

Pixmap
#ifdef __STDC__
get_keyboard_icon (Display *dpy, const struct keyboard_instance *kbd,
		   int *wP, int *hP)
#else /* ! __STDC__ */
get_keyboard_icon (dpy, kbd, wP, hP)
     Display *dpy;
     const struct keyboard_instance *kbd;
     int *wP, *hP;
#endif /* ! __STDC__ */
{
  struct icon *i = find_icon (kbd->keyboard_geometry);
  if (!i) /* not in the cache */
    {
      create_icon_pixmap (dpy, kbd->keyboard_geometry);
      i = find_icon (kbd->keyboard_geometry);
      if (!i) abort ();
    }
  *wP = i->width;
/*  if (max_icon_width > *wP)
    *wP = max_icon_width; */
  *hP = i->height;
  return i->pixmap;
}
