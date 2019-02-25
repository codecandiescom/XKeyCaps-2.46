/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the TI explorer Lisp Machine
 * keyboard.
 */

static const struct key_geometry explorer_geom_row0 [] = {
 {14, 7}, {3, 0},
 {9, 7}, {9, 7}, {9, 7}, {9, 7}, {2, 0},
 {8, 7}, {8, 7}, {8, 7}, {8, 7}, {2, 0},
 {9, 7}, {9, 7}, {9, 7}, {9, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry explorer_geom_row2 [] = {
 {14, 7}, {3, 0},
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, 
 {7, 7}, {7, 7}, {8, 7}, {7, 7}, {7, 7}, {7, 7}, {29, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry explorer_geom_row3 [] = {
 {14, 7}, {3, 0},
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry explorer_geom_row4 [] = {
 {14, 7}, {3, 0},
 {14, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {10, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry explorer_geom_row5 [] = {
 {17, 0},
 {7, 7}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {11, 7}, {10, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry explorer_geom_row6 [] = {
 {7, 7}, {7, 7}, {3, 0},
 {12, 7}, {12, 7}, {56, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {29, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry explorer_geom_rows [] = {
  ROW (explorer_geom_row0, 7),
  EMPTYROW (4),
  ROW (explorer_geom_row2, 7),
  ROW (explorer_geom_row3, 7),
  ROW (explorer_geom_row4, 7),
  ROW (explorer_geom_row5, 7),
  ROW (explorer_geom_row6, 7),
};

static const struct keyboard_geometry explorer_geom = {
  sizeof (explorer_geom_rows) / sizeof (struct keyboard_row_geometry),
  explorer_geom_rows, 5, 3, 3
};
