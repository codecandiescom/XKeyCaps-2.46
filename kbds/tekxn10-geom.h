/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the 
 * Tektronix XN10/XN11 keyboard.
 * By Kristian Ejvind (Kristian.Ejvind@sth.frontec.se)
 */

static const struct key_geometry tekxn10_geom_row0 [] = {
 {3, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {8, 0},
 {7, 7}, {14, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tekxn10_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, 
 {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tekxn10_geom_row3 [] = {
 {7, 7}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0},
 {7, 14}, {13, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tekxn10_geom_row4 [] = {
 {2, 0}, {7, 7}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {27, 0},
 {6, 6}, {15, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tekxn10_geom_row5 [] = {
 {2, 0}, {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {18, 0},
 {6, 6}, {6, 0}, {6, 6}, {9, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry tekxn10_geom_row6 [] = {
 {10, 0}, {14, 7}, {64, 7}, {7, 7}, {35, 0}, {6, 6}, {15, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry tekxn10_geom_rows [] = {
  ROW (tekxn10_geom_row0, 7),
  EMPTYROW (2),
  ROW (tekxn10_geom_row2, 7),
  ROW (tekxn10_geom_row3, 7),
  ROW (tekxn10_geom_row4, 7),
  ROW (tekxn10_geom_row5, 7),
  ROW (tekxn10_geom_row6, 7),
};

static const struct keyboard_geometry tekxn10_geom = {
  sizeof (tekxn10_geom_rows) / sizeof (struct keyboard_row_geometry),
  tekxn10_geom_rows, 6, 3, 3
};
