/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a "Linux CoolKeyboard" 107 key
 * AT PC-style keyboard.
 * By John Gotts <jgotts@linuxsavvy.com>
 */

static const struct key_geometry cc107_geom_row0 [] = {
 {7, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry cc107_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry cc107_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 14}, {4, 0}, {7, 7}, {7, 7}, {7, 7},
 {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry cc107_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 0}, {4, 0}, {7, 7}, {7, 7}, {7, 7}, {4,0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry cc107_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {12, 7}, {7, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry cc107_geom_row6 [] = {
 {9, 7}, {9, 7},
 {9, 7}, {42, 7}, {9, 7}, {9, 7},
 {9, 7}, {9, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry cc107_geom_rows [] = {
  ROW (cc107_geom_row0, 7),
  EMPTYROW (5),
  ROW (cc107_geom_row2, 7),
  ROW (cc107_geom_row3, 7),
  ROW (cc107_geom_row4, 7),
  ROW (cc107_geom_row5, 7),
  ROW (cc107_geom_row6, 7),
};

static const struct keyboard_geometry cc107_geom = {
  sizeof (cc107_geom_rows) / sizeof (struct keyboard_row_geometry),
  cc107_geom_rows, 6, 3, 3
};
