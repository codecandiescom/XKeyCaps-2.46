/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Sun type 3 keyboard.
 */

static const struct key_geometry sun3_geom_row0 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {14, 7}, {14, 7}, {14, 7}, {14, 7}, {14, 7}, {7, 7}, {7, 7},
 {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun3_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun3_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun3_geom_row3 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun3_geom_row4 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {12, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun3_geom_row5 [] = {
 {18, 0}, {9, 7}, {10, 7}, {65, 7}, {10, 7}, {11, 7}
};

static const struct keyboard_row_geometry sun3_geom_rows [] = {
  ROW (sun3_geom_row0, 7),
  ROW (sun3_geom_row1, 7),
  ROW (sun3_geom_row2, 7),
  ROW (sun3_geom_row3, 7),
  ROW (sun3_geom_row4, 7),
  ROW (sun3_geom_row5, 7),
};

static const struct keyboard_geometry sun3_geom = {
  sizeof (sun3_geom_rows) / sizeof (struct keyboard_row_geometry),
  sun3_geom_rows, 6, 3, 3
};
