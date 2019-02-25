/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the layout of the Happy Hacking Keyboard by PFU ltd. 
 * By Christoph Berg <cb@fsinfo.cs.uni-sb.de> 990821.
 *
 * This keyboard is designes to match close the Sun type 5 keyboard, thanks for
 * the authors of hhbkl-geom.h, from which I copied most of this file. 
 * 
 * The HHKB has only 60 keys, but features a Fn-key, with which most of the
 * other PC style keys can be emulated.
 *
 * I only added support for the keyboard mode where the "Delete" key geneates
 * the "BackSpace" keysym, which is probably the best mode. (Jumper 1 set
 * to 1; 0 is factory default.)
 *
 * DIP switch 2 selects Meta or Windows keys, the latter appear on the far
 * right bottom in xkeycaps.
 */

/* "virtual" keys while Fn pressed */
static const struct key_geometry hhbk_geom_row0 [] = {
 {7, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry hhbk_geom_row1 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry hhbk_geom_row2 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7},
 {4, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, /* Fn keys */
 /* {4, 0}, {7, 7} BS key if DIP switch 0 off */
};

static const struct key_geometry hhbk_geom_row3 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {15, 7},
 {7, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}	/* Fn keys */
};

static const struct key_geometry hhbk_geom_row4 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {12, 7}, {7, 7},
 {10, 0}, {7, 7}, {7, 7}, {7, 7}	/* Fn keys */
};

static const struct key_geometry hhbk_geom_row5 [] = {
 {11, 0}, {7, 7}, {10, 7}, {42, 7}, {10, 7}, {7, 7},
 {22, 0}, {10, 7}, {10, 7}, {10, 7}	/* Fn keys: caps lock, windows */
};

static const struct keyboard_row_geometry hhbk_geom_rows [] = {
  ROW (hhbk_geom_row0, 7),
  EMPTYROW (4),
  ROW (hhbk_geom_row1, 7),
  ROW (hhbk_geom_row2, 7),
  ROW (hhbk_geom_row3, 7),
  ROW (hhbk_geom_row4, 7),
  ROW (hhbk_geom_row5, 7),
};

static const struct keyboard_geometry hhkb_geom = {
  sizeof (hhbk_geom_rows) / sizeof (struct keyboard_row_geometry),
  hhbk_geom_rows, 6, 3, 3
};
