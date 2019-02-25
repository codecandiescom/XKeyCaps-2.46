/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1996, 1997
 *  Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

#include <X11/cursorfont.h>
#include <X11/Intrinsic.h>
#include "KbdWidget.h"
#include "KeyWidgetP.h"
#include <stdio.h>

#undef MAX
#undef MIN
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

static void KeyRealize P((Widget, XtValueMask *, XSetWindowAttributes *));
static void KeyExpose P((Widget, XEvent *, Region));
static void KeyInitialize P((Widget, Widget, ArgList, Cardinal*));

static void KeyHighlightProc P((KeyWidget));
static void KeyDehighlightProc P((KeyWidget));

#define XtNgutterWidth  "gutterWidth"
#define XtCGutterWidth  "GutterWidth"
#define XtNkeycapColor  "keycapColor"
#define XtNkeycodeColor "keycodeColor"
#define XtNkeycapFont   "keycapFont"
#define XtNkeycodeFont  "keycodeFont"
#define XtNcursorFont   "cursorFont"

#ifndef CURSORFONT
#define CURSORFONT "cursor"
#endif

static XtResource key_resources [] = {
  { XtNhighlight, XtCBackground, XtRPixel, sizeof (String),
      XtOffset (KeyWidget, key.highlight_pixel), XtRString,
      XtDefaultBackground },
  { XtNgutterWidth, XtCGutterWidth, XtRInt, sizeof (int),
      XtOffset (KeyWidget, key.gutter_width), XtRString, "3" },
  { XtNkeycapColor, XtCForeground, XtRPixel, sizeof (String),
      XtOffset (KeyWidget, key.keycap_pixel), XtRString,
      XtDefaultForeground },
  { XtNkeycodeColor, XtCForeground, XtRPixel, sizeof (String),
      XtOffset (KeyWidget, key.keycode_pixel), XtRString,
      XtDefaultForeground },
  { XtNkeycapFont, XtCFont, XtRFontStruct, sizeof (String),
      XtOffset (KeyWidget, key.keycap_font),
      XtRString, "*-helvetica-bold-r-*-*-*-100-*-*-*-*-*-*" },
  { XtNkeycodeFont, XtCFont, XtRFontStruct, sizeof (String),
      XtOffset (KeyWidget, key.keycode_font),
      XtRString, "*-courier-medium-r-*-*-*-100-*-*-*-*-*-*" },
  { XtNcursorFont, XtCFont, XtRFontStruct, sizeof (String),
      XtOffset (KeyWidget, key.cursor_font),
      XtRString, CURSORFONT }
};

KeyClassRec keyClassRec = {
    { /*
       * 	core fields
       */
    /* superclass		*/	&widgetClassRec,
    /* class_name		*/	"Key",
    /* widget_size		*/	sizeof (KeyRec),
    /* class_initialize		*/	NULL,
    /* class_part_initialize	*/	NULL,
    /* class_inited		*/	FALSE,
    /* initialize		*/	KeyInitialize,
    /* initialize_hook		*/	NULL,
    /* realize			*/	KeyRealize,
    /* actions			*/	NULL,
    /* num_actions		*/	0,
    /* resources		*/	key_resources,
    /* resource_count		*/	XtNumber (key_resources),
    /* xrm_class		*/	NULLQUARK,
    /* compress_motion		*/	TRUE,
    /* compress_exposure	*/	TRUE,
    /* compress_enterleave	*/	TRUE,
    /* visible_interest		*/	FALSE,
    /* destroy			*/	NULL,
    /* resize			*/	XtInheritResize,
    /* expose			*/	KeyExpose,
    /* set_values		*/	NULL,
    /* set_values_hook		*/	NULL,
    /* set_values_almost	*/	XtInheritSetValuesAlmost,
    /* get_values_hook		*/	NULL,
    /* accept_focus		*/	XtInheritAcceptFocus,
    /* version			*/	XtVersion,
    /* callback_private		*/	NULL,
    /* tm_table			*/	NULL,
    /* query_geometry		*/	XtInheritQueryGeometry,
    /* display_accelerator	*/	XtInheritDisplayAccelerator,
    /* extension		*/	NULL
    },
    { /*
       * 	key_class fields
       */
    /* highlight_key		*/	KeyHighlightProc,
    /* dehighlight_key		*/	KeyDehighlightProc
    }
};

WidgetClass keyWidgetClass = (WidgetClass) &keyClassRec;

static void 
#ifdef __STDC__
KeyInitialize (Widget w1, Widget w2, ArgList av, Cardinal *ac)
#else /* ! __STDC__ */
KeyInitialize (w1, w2, av, ac)
     Widget w1, w2;
     ArgList av;
     Cardinal ac;
#endif /* ! __STDC__ */
{
  KeyWidget new = (KeyWidget) w2;

  if (new->core.width <= 0) new->core.width = 3;
  if (new->core.height <= 0) new->core.height = 3;
  /* Initialize the non-resource slots */
  new->key.x = 0;
  new->key.y = 0;
  new->key.highlighted_p = 0;
  new->key.key_highlighted = 0;
  new->key.mouse_highlighted = 0;
  new->key.modifier_bits = 0;
  new->key.auto_repeat_p = 0;
  new->key.width = 0;
  new->key.height = 0;
  new->key.keysym_1 = 0;
  new->key.keysym_2 = 0;
  new->key.keysym_3 = 0;
  new->key.keycode = 0;
  new->key.default_mods = 0;
  memset (new->key.default_keysyms, 0, sizeof (new->key.default_keysyms));
}


static void
#ifdef __STDC__
KeyRealize (Widget gw, XtValueMask *valuemaskp, XSetWindowAttributes *attr)
#else /* ! __STDC__ */
KeyRealize (gw, valuemaskp, attr)
     Widget gw;
     XtValueMask *valuemaskp;
     XSetWindowAttributes *attr;
#endif /* ! __STDC__ */
{
  char *b, buf [255];
  const char *k1, *k2, *k3;
  XGCValues gcvalues;
  KeyWidget w = (KeyWidget) gw;
  XtCreateWindow ((Widget) w, InputOutput, (Visual *)CopyFromParent,
		  *valuemaskp, attr);
  gcvalues.foreground = w->key.keycap_pixel;
  gcvalues.font = w->key.keycap_font->fid;
  w->key.keycap_gc  = XtGetGC (gw, (unsigned) GCFont|GCForeground, &gcvalues);
  gcvalues.font = w->key.cursor_font->fid;
  w->key.cursor_gc = XtGetGC (gw, (unsigned) GCFont|GCForeground, &gcvalues);
  gcvalues.foreground = w->key.keycode_pixel;
  gcvalues.font = w->key.keycode_font->fid;
  w->key.keycode_gc = XtGetGC (gw, (unsigned) GCFont|GCForeground, &gcvalues);

  k1 = w->key.keysym_1;
  k2 = w->key.keysym_2;
  k3 = w->key.keysym_3;
  if (k1 && !*k1) k1 = 0;
  if (k2 && !*k2) k2 = 0;
  if (k3 && !*k3) k3 = 0;
  b = buf;
  b[0] = 0;
  if (k1)
    {
      int i = strlen (k1);
      strncpy (buf, k1, i+1);
      /* This is the kludge that makes "Caps " "Lock" concat as "CapsLock" */
      if (i > 1 && (buf [i-1] == ' ' || buf [i-1] == '-'))
	buf [i-1] = 0, i--;
      else if (i > 0 && (k2 || k3))
	buf [i] = ' ', buf [i+1] = 0, i++;
      b = buf+i;
    }
  if (k2)
    {
      int i = strlen (k2);
      strncpy (b, k2, i+1);
      b += i;
      if (k3) *b++ = ' ', *b++ = 0;
    }
  if (k3)
    strcpy (b, k3);

  b = buf;
  if (b[0] == ' ' && b[1] == 0) b = "space";
  w->key.key_name = XtNewString (b);
}


static void draw_key P((KeyWidget));

static void
#ifdef __STDC__
KeyExpose (Widget gw, XEvent *e, Region r)
#else /* ! __STDC__ */
KeyExpose (gw, e, r)
     Widget gw;
     XEvent *e;
     Region r;
#endif /* ! __STDC__ */
{
  draw_key ((KeyWidget) gw);
}


static int 
#ifdef __STDC__
string_width (unsigned char *string, XFontStruct *font)
#else /* ! __STDC__ */
string_width (string, font)
     unsigned char *string;
     XFontStruct *font;
#endif /* ! __STDC__ */
{
  int size = 0;
  if (!font) return 0;
  for (; *string; string++)
    if (font->per_char)
      size += font->per_char [(*string) - font->min_char_or_byte2].width;
    else
      size += font->max_bounds.width;
  return size;
}


static void
#ifdef __STDC__
draw_key (KeyWidget w)
#else /* ! __STDC__ */
draw_key (w)
     KeyWidget w;
#endif /* ! __STDC__ */
{
  Display *dpy = XtDisplay (w);
  Window window = XtWindow (w);
  XFontStruct *keycap_font  = w->key.keycap_font;
  XFontStruct *keycode_font = w->key.keycode_font;
  XFontStruct *cursor_font  = w->key.cursor_font;
  GC keycap_gc  = w->key.keycap_gc;
  GC keycode_gc = w->key.keycode_gc;
  GC cursor_gc  = w->key.cursor_gc;
  const char *k1 = w->key.keysym_1;
  const char *k2 = w->key.keysym_2;
  const char *k3 = w->key.keysym_3;
  unsigned char *uk1, *uk2, *uk3;
  XFontStruct *k1_font = cursor_font;
  XFontStruct *k2_font = cursor_font;
  XFontStruct *k3_font = cursor_font;
  GC k1_gc = cursor_gc;
  GC k2_gc = cursor_gc;
  GC k3_gc = cursor_gc;
  int inner_margin = 2;
  int x, y;

  char left[2], right[2], up[2], down[2];
  left[1] = right[1] = up[1] = down[1] = 0;
  left[0] = XC_sb_left_arrow; right[0] = XC_sb_right_arrow;
  up[0] = XC_sb_up_arrow; down[0] = XC_sb_down_arrow;

  if (k1 && !*k1) k1 = 0;
  if (k2 && !*k2) k2 = 0;
  if (k3 && !*k3) k3 = 0;

  if      (string_equal (k1, "leftArrow"))  k1 = left;
  else if (string_equal (k1, "rightArrow")) k1 = right;
  else if (string_equal (k1, "upArrow"))    k1 = up;
  else if (string_equal (k1, "downArrow"))  k1 = down;
  else k1_font = keycap_font, k1_gc = keycap_gc;

  if      (string_equal (k2, "leftArrow"))  k2 = left;
  else if (string_equal (k2, "rightArrow")) k2 = right;
  else if (string_equal (k2, "upArrow"))    k2 = up;
  else if (string_equal (k2, "downArrow"))  k2 = down;
  else k2_font = keycap_font, k2_gc = keycap_gc;

  if      (string_equal (k3, "leftArrow"))  k3 = left;
  else if (string_equal (k3, "rightArrow")) k3 = right;
  else if (string_equal (k3, "upArrow"))    k3 = up;
  else if (string_equal (k3, "downArrow"))  k3 = down;
  else k3_font = keycap_font, k3_gc = keycap_gc;

  uk1 = (unsigned char *) k1;
  uk2 = (unsigned char *) k2;
  uk3 = (unsigned char *) k3;

#define PERCHAR(font,c) \
  (font->per_char \
   ? &font->per_char[(c) - font->min_char_or_byte2] \
   : &font->max_bounds)

#define STRHEIGHT(font, var) \
  (font == cursor_font && var != NULL ? PERCHAR (font, var[0])->ascent : font->ascent)

#define MAXSTRHEIGHT(font, font2, var) \
  MAX (font->ascent, \
       (font2 == cursor_font \
	? PERCHAR (font2, var[0])->ascent \
	: font2->ascent))

  XClearWindow (dpy, window);
  x = y = 0;
  if (k1)
    {
      x = inner_margin - PERCHAR (k1_font, uk1[0])->lbearing;
      y = inner_margin + STRHEIGHT (k1_font, uk1);
      XDrawString (dpy, window, k1_gc, x, y, k1, strlen (k1));
    }
  if (k2)
    {
      x = inner_margin - PERCHAR (k2_font, uk2[0])->lbearing;
      y = inner_margin
	+ (k1 ? MAXSTRHEIGHT (keycap_font, k2_font, uk1)
	   : keycap_font->ascent)
	  + STRHEIGHT (k2_font, uk2);
/*      if (y + STRHEIGHT (k2_font, uk2) < w->core.height) */
	XDrawString (dpy, window, k2_gc, x, y, k2, strlen (k2));
    }
  if (k3)
    {
      int i = strlen (k3) - 1;
      x = w->core.width - (w->core.border_width * 2
			   + string_width (uk3, k3_font)
			   + (PERCHAR (k3_font, uk3[i])->width -
			      PERCHAR (k3_font, uk3[i])->rbearing));
      y = inner_margin + STRHEIGHT (k3_font, uk3);
      if (k1 == 0 || x >= string_width (uk1, k1_font))
	XDrawString (dpy, window, k3_gc, x, y, k3, strlen (k3));
    }

  if (w->key.keycode)
    {
      unsigned char buf [100];
      sprintf ((char *) buf, "%02X", w->key.keycode);
      x = w->core.width - (w->core.border_width * 2
			   + string_width (buf, keycode_font));
      y = w->core.height - (w->core.border_width * 2 + keycode_font->descent);
      if ((x >= inner_margin) &&
	  (y - keycode_font->ascent >= inner_margin) &&
	  (y > ((STRHEIGHT (k1_font, uk1) * 3) / 2)
	   ? (k2 == 0 || x >= string_width (uk2, k2_font))
	   : (k1 == 0 || x >= string_width (uk1, k1_font))))
	XDrawString (dpy, window, keycode_gc, x, y,
		     (char *) buf, strlen ((char *) buf));
    }
#undef PERCHAR
#undef STRHEIGHT
#undef MAXSTRHEIGHT
}



void
#ifdef __STDC__
KeyHighlight (KeyWidget keyw)
#else /* ! __STDC__ */
KeyHighlight (keyw)
     KeyWidget keyw;
#endif /* ! __STDC__ */
{
  if (keyw->key.highlighted_p) return;
  ((KeyWidgetClass) keyw->core.widget_class)->key_class.highlight_key (keyw);
  keyw->key.highlighted_p = 1;
}

void
#ifdef __STDC__
KeyDehighlight (KeyWidget keyw)
#else /* ! __STDC__ */
KeyDehighlight (keyw)
     KeyWidget keyw;
#endif /* ! __STDC__ */
{
  if (! keyw->key.highlighted_p) return;
  ((KeyWidgetClass) keyw->core.widget_class)->key_class.dehighlight_key (keyw);
  keyw->key.highlighted_p = 0;
}


#include <X11/bitmaps/gray>

/* This is a little sleazy: we're caching a pixmap in global space instead 
   of caching it per-display, which means if someone were to include this
   widget-set in an application that used multiple displays (not bloody 
   likely!) this would have to be fixed.  But the alternative is adding
   a new slot and resource to each and every key, which isn't worth it.
 */
static Pixmap highlight_pixmap = 0;

static Pixmap
#ifdef __STDC__
make_highlight_pixmap (KeyWidget w)
#else /* ! __STDC__ */
make_highlight_pixmap (w)
     KeyWidget w;
#endif /* ! __STDC__ */
{
  return XCreatePixmapFromBitmapData
    (XtDisplay (w), XtWindow (w), gray_bits, gray_width, gray_height,
     w->key.keycap_pixel, w->core.background_pixel,
     DefaultDepthOfScreen (DefaultScreenOfDisplay (XtDisplay (w))));
}


#ifdef LOSE_LIKE_Xt	/* Doing this the Xt way is just too damn slow... */

static void
#ifdef __STDC__
KeyHighlightProc (KeyWidget w)
#else /* ! __STDC__ */
KeyHighlightProc (w)
     KeyWidget w;
#endif /* ! __STDC__ */
{
  Arg av [2];
  int ac = 0;
  w->key.background_pixel = w->core.background_pixel;
  if (w->key.background_pixel == w->key.highlight_pixel)
    {
      if (! highlight_pixmap) highlight_pixmap = make_hilight_pixmap (w);
      XtSetArg (av[ac], XtNbackgroundPixmap, highlight_pixmap);
    }
  else
    XtSetArg (av[ac], XtNbackground, w->key.highlight_pixel);
  ac++;
  XtSetValues (w, av, ac);
}


static void
#ifdef __STDC__
KeyDehighlightProc (KeyWidget keyw)
#else /* ! __STDC__ */
KeyDehighlightProc (keyw)
     KeyWidget keyw;
#endif /* ! __STDC__ */
{
  Arg av [2];
  int ac = 0;
  if (highlight_pixmap)
    XtSetArg (av[ac], XtNbackgroundPixmap, XtUnspecifiedPixmap);
  else
    XtSetArg (av[ac], XtNbackground, keyw->key.background_pixel);
  ac++;
  XtSetValues (keyw, av, ac);
}


#else /* !LOSE_LIKE_Xt */

static void
#ifdef __STDC__
KeyHighlightProc (KeyWidget w)
#else /* ! __STDC__ */
KeyHighlightProc (w)
     KeyWidget w;
#endif /* ! __STDC__ */
{
  w->key.background_pixel = w->core.background_pixel;
  if (w->key.background_pixel == w->key.highlight_pixel)
    {
      if (! highlight_pixmap) highlight_pixmap = make_highlight_pixmap (w);
      XSetWindowBackgroundPixmap (XtDisplay (w), XtWindow (w), highlight_pixmap);
    }
  else
    XSetWindowBackground (XtDisplay (w), XtWindow (w), w->key.highlight_pixel);
  draw_key (w);
}


static void
#ifdef __STDC__
KeyDehighlightProc (KeyWidget w)
#else /* ! __STDC__ */
KeyDehighlightProc (w)
     KeyWidget w;
#endif /* ! __STDC__ */
{
  XSetWindowBackground (XtDisplay (w), XtWindow (w), w->key.background_pixel);
  draw_key (w);
}

#endif /* !LOSE_LIKE_Xt */
