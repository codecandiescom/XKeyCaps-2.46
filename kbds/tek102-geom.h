/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Tektronix X358 keyboard,
 * _TEK_KEYBOARD_TYPE = "TEK102" (102-key German Keyboard)
 *
 * By Christoph Tietz <tietz@gmd.de>.
 */

static const struct key_geometry tek102_geom_row0 [] = {
 {7, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek102_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek102_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0}, {9, 14}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry tek102_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {36, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek102_geom_row5 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {18, 7}, {10, 0},
 {7, 7}, {10, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry tek102_geom_row6 [] = {
 {12, 7}, {7, 0},
 {11, 7}, {47, 7}, {11, 7}, {7, 0},
 {10, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry tek102_geom_rows [] = {
  ROW (tek102_geom_row0, 7),
  EMPTYROW (5),
  ROW (tek102_geom_row2, 7),
  ROW (tek102_geom_row3, 7),
  ROW (tek102_geom_row4, 7),
  ROW (tek102_geom_row5, 7),
  ROW (tek102_geom_row6, 7),
};

static const struct keyboard_geometry tek102_geom = {
  sizeof (tek102_geom_rows) / sizeof (struct keyboard_row_geometry),
  tek102_geom_rows, 6, 3, 3
};
