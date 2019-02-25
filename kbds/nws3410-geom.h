/* xkeycaps, Copyright (c) 1994 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the SONY NET WORK STATION
 * NWS-3410 keyboard (keyboard model NWP-411A).
 * By Dirk Jablonowski <jablonowski@zrz.TU-Berlin.de>
 */

static const struct key_geometry nws3410_geom_row0 [] = {
 {14, 0},
 {9, 8}, {9, 8}, {9, 8}, {9, 8}, {9, 8}, {3, 0},
 {9, 8}, {9, 8}, {9, 8}, {9, 8}, {9, 8}
};

static const struct key_geometry nws3410_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry nws3410_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {8, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry nws3410_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {13, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry nws3410_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry nws3410_geom_row6 [] = {
 {12, 7}, {7, 7}, {11, 7}, {42, 7}, {10, 7}, {7, 7}, {7, 7},
 {13, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct keyboard_row_geometry nws3410_geom_rows [] = {
  ROW (nws3410_geom_row0, 7),
  EMPTYROW (3),
  ROW (nws3410_geom_row2, 7),
  ROW (nws3410_geom_row3, 7),
  ROW (nws3410_geom_row4, 7),
  ROW (nws3410_geom_row5, 7),
  ROW (nws3410_geom_row6, 7),
};

static const struct keyboard_geometry nws3410_geom = {
  sizeof (nws3410_geom_rows) / sizeof (struct keyboard_row_geometry),
  nws3410_geom_rows, 6, 3, 3
};
