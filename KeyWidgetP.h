/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1996
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

#ifndef _KeyWidgetP_H_
#define _KeyWidgetP_H_

#include <X11/StringDefs.h>
#include <X11/IntrinsicP.h>
#include <X11/cursorfont.h>
#include "KeyWidget.h"
#include "xkeycaps.h"

typedef struct {
  void (* highlight_key) P((KeyWidget));
  void (* dehighlight_key) P((KeyWidget));
} KeyClassPart;

/* Full class record declaration */
typedef struct _KeyClassRec {
    CoreClassPart	core_class;
    KeyClassPart	key_class;
} KeyClassRec;

extern KeyClassRec keyClassRec;

/* New fields for the Key widget record */
typedef struct {
  int gutter_width;
  Pixel highlight_pixel, background_pixel;
  Pixel keycap_pixel, keycode_pixel;
  XFontStruct *keycap_font, *keycode_font, *cursor_font;
  GC keycap_gc, keycode_gc, cursor_gc;
  String key_name;
  int highlighted_p;		/* Whether it's drawn highlighted now */
  unsigned short x, y;		/* Position in keyboard units */
  int key_highlighted;		/* Whether this key (the real one) is down
				 * This is duplicated in kbd->key_state_vector
				 */
  int mouse_highlighted;	/* Whether a button is depressed on this */
  unsigned long modifier_bits;	/* Which modifiers this key CURRENTLY sets */
  int auto_repeat_p;		/* Whether this key autorepeats */

  /* These slots are initialized when a keyboard is selected, and are not
     changed at run-time.  They are copies of what came from the various
     keyboard definition files. */

  unsigned short width;	 /* Width of the key in some arbitrary units */
  unsigned short height; /* Height of the key in some arbitrary units */

  const char *keysym_1;
  const char *keysym_2;
  const char *keysym_3;

  KeyCode keycode;		/* This never changes */
  KeySym default_keysyms[8];	/* This never changes */
  unsigned long default_mods;	/* never changes, unlike modifier_bits slot */

} KeyPart;

typedef struct _KeyRec {		/* full instance record */
    CorePart core;
    KeyPart key;
} KeyRec;


struct KeyWidget_row {			/* like keyboard_row_geometry,
					   but of KeyWidgets. */
  unsigned int nkeys;
  unsigned int height;
  KeyWidget *keys;
};

#endif /* _KeyWidgetP_H_ */
