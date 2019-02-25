/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Tektronix XP20 keyboard,
 * _TEK_KEYBOARD_TYPE = "ibm101" (101-key North American Keyboard)
 *
 * By Joe English <joe@trystero.art.com>.
 */

static const struct key_geometry tek101_geom_row0 [] = {
 {7, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek101_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek101_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 14}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry tek101_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {43, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek101_geom_row5 [] = {
 {15, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {20, 7}, {10, 0},
 {7, 7}, {10, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry tek101_geom_row6 [] = {
 {12, 7}, {7, 0},
 {11, 7}, {47, 7}, {11, 7}, {7, 0},
 {10, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry tek101_geom_rows [] = {
  ROW (tek101_geom_row0, 7),
  EMPTYROW (5),
  ROW (tek101_geom_row2, 7),
  ROW (tek101_geom_row3, 7),
  ROW (tek101_geom_row4, 7),
  ROW (tek101_geom_row5, 7),
  ROW (tek101_geom_row6, 7),
};

static const struct keyboard_geometry tek101_geom = {
  sizeof (tek101_geom_rows) / sizeof (struct keyboard_row_geometry),
  tek101_geom_rows, 6, 3, 3
};
