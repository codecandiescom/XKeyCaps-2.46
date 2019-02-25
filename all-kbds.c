/* xkeycaps, Copyright (c) 1993, 1997 Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

/* This is only in its own .c file to help incremental linking performance. */


/* Make sure all possible keysyms get defined. */
#undef  XK_MISCELLANY
#define XK_MISCELLANY
#undef  XK_XKB_KEYS
#define XK_XKB_KEYS
#undef  XK_3270
#define XK_3270
#undef  XK_LATIN1
#define XK_LATIN1
#undef  XK_LATIN2
#define XK_LATIN2
#undef  XK_LATIN3
#define XK_LATIN3
#undef  XK_LATIN4
#define XK_LATIN4
#undef  XK_ARABIC
#define XK_ARABIC
#undef  XK_KATAKANA
#define XK_KATAKANA
#undef  XK_CYRILLIC
#define XK_CYRILLIC
#undef  XK_GREEK
#define XK_GREEK
#undef  XK_TECHNICAL
#define XK_TECHNICAL
#undef  XK_SPECIAL
#define XK_SPECIAL
#undef  XK_PUBLISHING
#define XK_PUBLISHING
#undef  XK_APL
#define XK_APL
#undef  XK_HEBREW
#define XK_HEBREW
#undef  XK_THAI
#define XK_THAI
#undef  XK_KOREAN
#define XK_KOREAN

#include <X11/keysymdef.h>

#ifdef __hpux
# include <X11/HPkeysym.h>
#endif

#if defined(AIX) && !defined(ps2)
# include <X11/aix_keysym.h>
#endif

#include "keysym-compat.h"

#include "kbddef.h"


#undef countof
#define countof(x) (sizeof((x)) / sizeof(*(x)))

#define DEFKBD(short, vendor, style, server_id, geom, caps, codes, map)	\
	{ (short), (vendor), (style), (server_id),			\
	  (geom), (caps), (codes), (map),				\
	  countof((caps)), countof((codes)), countof((map))		\
	}

#include "all-kbds.h"		/* first include it for the #includes... */
#define KBD DEFKBD

const struct keyboard_instance all_kbds [] = {
#include "all-kbds.h"		/* then include it for the KBD calls. */
  { 0 }
};
