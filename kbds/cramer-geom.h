/* xkeycaps, Copyright (c) 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the "Interfaces by Cramer"
 * Floating Arms keyboard (formerly the Workplace Designs keyboard.)
 * This is a split keyboard where the two pieces attach to the arms of
 * your chair, instead of sitting on a desk.
 *
 * Keyboard's home page:
 *   http://www.ergointerfaces.com/
 *
 * Typing injury FAQ: 
 *   http://www.tifaq.org/keyboards/adjustable-split-keyboards.html
 */

static const struct key_geometry cramer_geom_row0 [] = {
 {7, 7}, {7, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {47, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
};

static const struct key_geometry cramer_geom_row1 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {33, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7},
 {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
};

static const struct key_geometry cramer_geom_row2 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {43, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 7},
 {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 14},
};

static const struct key_geometry cramer_geom_row3 [] = {
 {11, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {42, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7},
 {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7},
};

static const struct key_geometry cramer_geom_row4 [] = {
 {14, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {43, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {7, 7},
 {10, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14},
};

static const struct key_geometry cramer_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {35, 7},
 {3, 0},
 {35, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {10, 0},
 {14, 7}, {7, 7},
};

static const struct key_geometry cramer_geom_row6 [] = {
 {103, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
};

static const struct keyboard_row_geometry cramer_geom_rows [] = {
  ROW (cramer_geom_row0, 7),
  ROW (cramer_geom_row1, 7),
  ROW (cramer_geom_row2, 7),
  ROW (cramer_geom_row3, 7),
  ROW (cramer_geom_row4, 7),
  ROW (cramer_geom_row5, 7),
  ROW (cramer_geom_row6, 7),
};

static const struct keyboard_geometry cramer_geom = {
  sizeof (cramer_geom_rows) / sizeof (struct keyboard_row_geometry),
  cramer_geom_rows, 6, 3, 3
};
