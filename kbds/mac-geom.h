/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Apple Extended Keyboard II.
 * By John Knox <johnx@exlog.com> and Chris Jones, Baker Hughes
 * Inteq DEAP Support, Aberdeen.
 */

static const struct key_geometry mac_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry mac_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry mac_geom_row3 [] = {
 {11, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0},
 {9, 14}, {4, 0}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry mac_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {38, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry mac_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {20, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry mac_geom_row6 [] = {
 {10, 7}, {8, 7}, {11, 7}, {48, 7}, {11, 7}, {8, 7}, {10, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry mac_geom_rows [] = {
  ROW (mac_geom_row0, 7),
  EMPTYROW (5),
  ROW (mac_geom_row2, 7),
  ROW (mac_geom_row3, 7),
  ROW (mac_geom_row4, 7),
  ROW (mac_geom_row5, 7),
  ROW (mac_geom_row6, 7),
};

static const struct keyboard_geometry mac_geom = {
  sizeof (mac_geom_rows) / sizeof (struct keyboard_row_geometry),
  mac_geom_rows, 6, 3, 3
};
