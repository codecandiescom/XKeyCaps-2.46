/* xkeycaps, Copyright (c) 1991-1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a 96-key german non-A1000
 * Amiga keyboard, with keys cut out of the left shift and the return key.
 * By Peter Remmers <pitti@tfh-berlin.de>
 */

static const struct key_geometry amiga96_geom_row0 [] = {
 {8, 8}, {4, 0},
 {10, 8}, {10, 8}, {10, 8}, {10, 8}, {10, 8}, {4, 0},
 {10, 8}, {10, 8}, {10, 8}, {10, 8}, {10, 8}
};

static const struct key_geometry amiga96_geom_row2 [] = {
 {12, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {4, 0}, {12, 8}, {12, 8}, {4, 0},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}
};

static const struct key_geometry amiga96_geom_row3 [] = {
 {16, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {2, 0}, {10, 16},
 {32, 0}, {8, 8}, {8, 8}, {8, 8}, {8, 8}
};

static const struct key_geometry amiga96_geom_row4 [] = {
 {10, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {22,0}, {8, 8}, {12,0},
 {8, 8}, {8, 8}, {8, 8}, {8, 8} 
};

static const struct key_geometry amiga96_geom_row5 [] = {
 {14, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {22, 8},
 {4, 0}, {8, 8}, {8, 8}, {8, 8},
 {4, 0}, {8, 8}, {8, 8}, {8, 8}, {8, 16}
};

static const struct key_geometry amiga96_geom_row6 [] = {
 {6, 0}, {10, 8}, {10, 8}, {72, 8}, {10, 8}, {10, 8},
 {38, 0}, {16, 8}, {8, 8}
};

static const struct keyboard_row_geometry amiga96_geom_rows [] = {
  ROW (amiga96_geom_row0, 8),
  EMPTYROW (4),
  ROW (amiga96_geom_row2, 8),
  ROW (amiga96_geom_row3, 8),
  ROW (amiga96_geom_row4, 8),
  ROW (amiga96_geom_row5, 8),
  ROW (amiga96_geom_row6, 8),
};

static const struct keyboard_geometry amiga96_geom = {
  sizeof (amiga96_geom_rows) / sizeof (struct keyboard_row_geometry),
  amiga96_geom_rows, 6, 3, 3
};
