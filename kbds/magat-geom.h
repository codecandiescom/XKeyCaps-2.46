/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the MIPS Magnum AT/US keyboard.
 * By Michael Elbel <me@pcs.com>
 */

static const struct key_geometry magat_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry magat_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry magat_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry magat_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 7}, {29, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry magat_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {20, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry magat_geom_row6 [] = {
 {11, 7}, {7, 0},
 {11, 7}, {48, 7}, {11, 7}, {7, 0},
 {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry magat_geom_rows [] = {
  ROW (magat_geom_row0, 7),
  EMPTYROW (5),
  ROW (magat_geom_row2, 7),
  ROW (magat_geom_row3, 7),
  ROW (magat_geom_row4, 7),
  ROW (magat_geom_row5, 7),
  ROW (magat_geom_row6, 7),
};

static const struct keyboard_geometry magat_geom = {
  sizeof (magat_geom_rows) / sizeof (struct keyboard_row_geometry),
  magat_geom_rows, 6, 3, 3
};
