/* xkeycaps, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a Brazilian ABNT2 107 key PC
 * keyboard.  This is based on file "pc101-geom.h".
 * By Andre Gerhard <andre@lme.usp.br> - 05/12/98
 */

static const struct key_geometry pc107_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc107_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc107_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0}, {9, 14},
 {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc107_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {38, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc107_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {13, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc107_geom_row6 [] = {
 {11, 7}, {10, 7},
 {9, 7}, {36, 7}, {9, 7}, {10, 7}, {10, 7},
 {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc107_geom_rows [] = {
  ROW (pc107_geom_row0, 7),
  EMPTYROW (5),
  ROW (pc107_geom_row2, 7),
  ROW (pc107_geom_row3, 7),
  ROW (pc107_geom_row4, 7),
  ROW (pc107_geom_row5, 7),
  ROW (pc107_geom_row6, 7),
};

static const struct keyboard_geometry pc107_geom = {
  sizeof (pc107_geom_rows) / sizeof (struct keyboard_row_geometry),
  pc107_geom_rows, 6, 3, 3
};
