/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Soft Key "Butterfly"
 * keyboard.
 * The actual shape of the keyboard resembles the MS "natural keyboard".
 */

static const struct key_geometry butterfly_geom_row0 [] = {
 {32, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {30, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry butterfly_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry butterfly_geom_row3 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry butterfly_geom_row4 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {20, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry butterfly_geom_row5 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 14}, {4, 0},
 {15, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {20, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry butterfly_geom_row6 [] = {
 {7, 7}, {7, 7}, {7, 7}, {11, 0},
 {10, 7}, {10, 7}, {10, 7}, {7, 7}, {35, 7},
 {7, 7}, {7, 7}, {7, 7}, {11, 7}, {10, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct key_geometry butterfly_geom_row8 [] = {
 {78, 0}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry butterfly_geom_row9 [] = {
 {78, 0}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry butterfly_geom_row10 [] = {
 {78, 0}, {7, 7}, {7, 7}, {7, 7}
};

static const struct keyboard_row_geometry butterfly_geom_rows [] = {
  ROW (butterfly_geom_row0, 7),
  EMPTYROW (5),
  ROW (butterfly_geom_row2, 7),
  ROW (butterfly_geom_row3, 7),
  ROW (butterfly_geom_row4, 7),
  ROW (butterfly_geom_row5, 7),
  ROW (butterfly_geom_row6, 7),
  EMPTYROW (5),
  ROW (butterfly_geom_row8, 7),
  ROW (butterfly_geom_row9, 7),
  ROW (butterfly_geom_row10, 7),
};

static const struct keyboard_geometry butterfly_geom = {
  sizeof (butterfly_geom_rows) / sizeof (struct keyboard_row_geometry),
  butterfly_geom_rows, 6, 2, 2
};
