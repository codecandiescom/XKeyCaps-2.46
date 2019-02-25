/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a generic 105 key PC keyboard,
 * like all of those Taiwan Win95 enhanced keyboards
 * by Lorenzo Maria Catucci <lorenzo@info.utovrm.it>
 */

static const struct key_geometry pc105_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc105_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc105_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {9, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc105_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {38, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc105_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {20, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc105_geom_row6 [] = {
 {9, 7}, {9, 7},
 {9, 7}, {43, 7}, {9, 7}, {9, 7},
 {9, 7}, {9, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc105_geom_rows [] = {
  ROW (pc105_geom_row0, 7),
  EMPTYROW (5),
  ROW (pc105_geom_row2, 7),
  ROW (pc105_geom_row3, 7),
  ROW (pc105_geom_row4, 7),
  ROW (pc105_geom_row5, 7),
  ROW (pc105_geom_row6, 7),
};

static const struct keyboard_geometry pc105_geom = {
  sizeof (pc105_geom_rows) / sizeof (struct keyboard_row_geometry),
  pc105_geom_rows, 6, 3, 3
};
