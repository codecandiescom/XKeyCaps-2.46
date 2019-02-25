/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Sun UK type 5 keyboard.
 * By Jeremy Prior (jez@howell.com), 16th Aug 1995
 * Based on Sun Swiss-French Type 5 Keyboard,
 * by Philippe A. Kipfer (Philippe.Kipfer@di.epfl.ch), dec.1993.
 */

static const struct key_geometry sun5uk_geom_row0 [] = {
 {14, 7}, {4, 0},
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun5uk_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun5uk_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0}, {9, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry sun5uk_geom_row3 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {38, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun5uk_geom_row4 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {18,7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry sun5uk_geom_row5 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {11, 7}, {7, 7}, {7, 7}, {59, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};


static const struct keyboard_row_geometry sun5uk_geom_rows [] = {
  ROW (sun5uk_geom_row0, 7),
  EMPTYROW (7),
  ROW (sun5uk_geom_row1, 7),
  ROW (sun5uk_geom_row2, 7),
  ROW (sun5uk_geom_row3, 7),
  ROW (sun5uk_geom_row4, 7),
  ROW (sun5uk_geom_row5, 7),
};


static const struct keyboard_geometry sun5uk_geom = {
  sizeof (sun5uk_geom_rows) / sizeof (struct keyboard_row_geometry),
  sun5uk_geom_rows, 6, 3, 3
};
