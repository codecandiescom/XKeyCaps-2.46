/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of your basic 104 key PC-style
 * keyboard.  This is based on file "pc101-geom.h", as modified by Steven
 * Winikoff, 1997/04/23.
 */

static const struct key_geometry pc104_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc104_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc104_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc104_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 7}, {29, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc104_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {20, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc104_geom_row6 [] = {
 {11, 7}, {10, 7},
 {9, 7}, {36, 7}, {9, 7}, {10, 7}, {10, 7},
 {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc104_geom_rows [] = {
  ROW (pc104_geom_row0, 7),
  EMPTYROW (5),
  ROW (pc104_geom_row2, 7),
  ROW (pc104_geom_row3, 7),
  ROW (pc104_geom_row4, 7),
  ROW (pc104_geom_row5, 7),
  ROW (pc104_geom_row6, 7),
};

static const struct keyboard_geometry pc104_geom = {
  sizeof (pc104_geom_rows) / sizeof (struct keyboard_row_geometry),
  pc104_geom_rows, 6, 3, 3
};
