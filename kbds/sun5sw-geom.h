/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Sun type 5 Swedish keyboard.
 * By Magnus Hammerin <magnush@isy.liu.se>
 */

static const struct key_geometry sun5sw_geom_row0 [] = {
 {14, 7}, {4, 0},
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun5sw_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun5sw_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0}, {8, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry sun5sw_geom_row3 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {8, 0}, {29, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun5sw_geom_row4 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {19, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry sun5sw_geom_row5 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {11, 7}, {7, 7}, {7, 7}, {59, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry sun5sw_geom_rows [] = {
  ROW (sun5sw_geom_row0, 7),
  EMPTYROW (7),
  ROW (sun5sw_geom_row1, 7),
  ROW (sun5sw_geom_row2, 7),
  ROW (sun5sw_geom_row3, 7),
  ROW (sun5sw_geom_row4, 7),
  ROW (sun5sw_geom_row5, 7),
};

static const struct keyboard_geometry sun5sw_geom = {
  sizeof (sun5sw_geom_rows) / sizeof (struct keyboard_row_geometry),
  sun5sw_geom_rows, 6, 3, 3
};
