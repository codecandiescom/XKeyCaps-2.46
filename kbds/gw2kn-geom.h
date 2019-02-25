/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Gateway 2000 keyboard for
 * Windows 95.  It is identical to the Microsoft "Natural" keyboard, except
 * without the ergonomic split down the middle.
 * By Barry Warsaw <bwarsaw@cnri.reston.va.us>
 */

static const struct key_geometry gw2kn_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0}, 
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0}, 
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0}, 
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry gw2kn_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry gw2kn_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry gw2kn_geom_row4 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {17, 7}, {29, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry gw2kn_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {20, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry gw2kn_geom_row6 [] = {
 {9, 7}, {9, 7}, {9, 7}, {43, 7},
 {9, 7}, {9, 7}, {9, 7}, {9, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry gw2kn_geom_rows [] = {
  ROW (gw2kn_geom_row0, 7),
  EMPTYROW (5),
  ROW (gw2kn_geom_row2, 7),
  ROW (gw2kn_geom_row3, 7),
  ROW (gw2kn_geom_row4, 7),
  ROW (gw2kn_geom_row5, 7),
  ROW (gw2kn_geom_row6, 7),
};

static const struct keyboard_geometry gw2kn_geom = {
  sizeof (gw2kn_geom_rows) / sizeof (struct keyboard_row_geometry),
  gw2kn_geom_rows, 6, 3, 3
};
