/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the SONY laptop workstation
 * NWS1250 keyboard.  By Pavel Rosendorf <prf@jprix.che.wisc.edu>
 */

static const struct key_geometry nws1250_geom_row0 [] = {
 {8, 8}, {6, 0},
 {9, 8}, {9, 8}, {9, 8}, {9, 8}, {9, 8}, {3, 0},
 {9, 8}, {9, 8}, {9, 8}, {9, 8}, {9, 8}
};

static const struct key_geometry nws1250_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}
};

static const struct key_geometry nws1250_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {8, 7}
};

static const struct key_geometry nws1250_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {13, 7}
};

static const struct key_geometry nws1250_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 7}
};

static const struct key_geometry nws1250_geom_row6 [] = {
 {9, 7}, {7, 7}, {7, 7}, {9, 7}, {31, 7}, {9, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {9, 7}
};

static const struct keyboard_row_geometry nws1250_geom_rows [] = {
  ROW (nws1250_geom_row0, 7),
  EMPTYROW (3),
  ROW (nws1250_geom_row2, 7),
  ROW (nws1250_geom_row3, 7),
  ROW (nws1250_geom_row4, 7),
  ROW (nws1250_geom_row5, 7),
  ROW (nws1250_geom_row6, 7),
};

static const struct keyboard_geometry nws1250_geom = {
  sizeof (nws1250_geom_rows) / sizeof (struct keyboard_row_geometry),
  nws1250_geom_rows, 6, 3, 3
};
