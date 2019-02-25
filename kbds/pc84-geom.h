/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of original 84 key PC/AT-style
 * keyboards.
 * by Ken Rose <kenr@vmlabs.com>
 */

static const struct key_geometry pc84_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc84_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc84_geom_row3 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {15, 0}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc84_geom_row4 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {19, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc84_geom_row5 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {8, 0},
 {69, 7}, {8, 0},
 {10, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc84_geom_rows [] = {
  ROW (pc84_geom_row1, 7),
  ROW (pc84_geom_row2, 7),
  ROW (pc84_geom_row3, 7),
  ROW (pc84_geom_row4, 7),
  ROW (pc84_geom_row5, 7),
};

static const struct keyboard_geometry pc84_geom = {
  sizeof (pc84_geom_rows) / sizeof (struct keyboard_row_geometry),
  pc84_geom_rows, 5, 3, 3
};
