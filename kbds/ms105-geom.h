/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Microsoft "Natural"
   keyboard (part 58221).
 */

static const struct key_geometry ms105_geom_row0 [] = {
 {3, 0}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {17, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ms105_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 7}, {10, 0},
 {11, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ms105_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {13, 7}, {10, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0}, {7, 14},
 {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry ms105_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {10, 0},
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {39, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ms105_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {10, 0},
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {16, 7}, {16, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry ms105_geom_row6 [] = {
 {12, 7}, {12, 7}, {12, 7}, {38, 7},
 {10, 7}, {10, 7}, {10, 7}, {11, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry ms105_geom_rows [] = {
  ROW (ms105_geom_row0, 7),
  EMPTYROW (5),
  ROW (ms105_geom_row2, 7),
  ROW (ms105_geom_row3, 7),
  ROW (ms105_geom_row4, 7),
  ROW (ms105_geom_row5, 7),
  ROW (ms105_geom_row6, 7),
};

static const struct keyboard_geometry ms105_geom = {
  sizeof (ms105_geom_rows) / sizeof (struct keyboard_row_geometry),
  ms105_geom_rows, 6, 3, 3
};
