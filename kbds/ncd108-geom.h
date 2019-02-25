/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the NCD N108 and VT220 keyboards.
 */

static const struct key_geometry ncd108_geom_row0 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {8, 7}, {16, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ncd108_geom_row2 [] = {
 {5, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {12, 0},
 {8, 7}, {8, 7}, {8, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ncd108_geom_row3 [] = {
 {5, 0}, {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0}, {8, 14}, {8, 0}, {8, 7},
 {8, 7}, {8, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ncd108_geom_row4 [] = {
 {7, 7}, {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {24, 0},
 {8, 7}, {15, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ncd108_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 7}, {10, 0},
 {8, 7}, {8, 7}, {8, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry ncd108_geom_row6 [] = {
 {7, 0}, {13, 7}, {7, 7}, {47, 7}, {7, 7}, {13, 7}, {56, 0},
 {14, 7}, {7, 7}
};

static const struct key_geometry ncd220_geom_row6 [] = {
 {9, 0}, {16, 7}, {64, 7}, {61, 0}, {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry ncd108_geom_rows [] = {
  ROW (ncd108_geom_row0, 7),
  EMPTYROW (7),
  ROW (ncd108_geom_row2, 7),
  ROW (ncd108_geom_row3, 7),
  ROW (ncd108_geom_row4, 7),
  ROW (ncd108_geom_row5, 7),
  ROW (ncd108_geom_row6, 7),
};

static const struct keyboard_row_geometry ncd220_geom_rows [] = {
  ROW (ncd108_geom_row0, 7),
  EMPTYROW (7),
  ROW (ncd108_geom_row2, 7),
  ROW (ncd108_geom_row3, 7),
  ROW (ncd108_geom_row4, 7),
  ROW (ncd108_geom_row5, 7),
  ROW (ncd220_geom_row6, 7),
};

static const struct keyboard_geometry ncd108_geom = {
  sizeof (ncd108_geom_rows) / sizeof (struct keyboard_row_geometry),
  ncd108_geom_rows, 6, 3, 3
};

static const struct keyboard_geometry ncd220_geom = {
  sizeof (ncd220_geom_rows) / sizeof (struct keyboard_row_geometry),
  ncd220_geom_rows, 6, 3, 3
};
