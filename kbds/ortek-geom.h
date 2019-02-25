/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file contains the keycaps layout of a 107-key Ortek "Enhanced Keyboard"
 * This is based on the file "pc104-geom.h"        
 * Unfortunately, the extra 3 keys don't work in X.
 * By Mike Hicks <hick0088@tc.umn.edu>
 */

static const struct key_geometry ortek_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ortek_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ortek_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry ortek_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {20, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ortek_geom_row5 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {13, 7}, {7, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry ortek_geom_row6 [] = {
 {11, 7}, {10, 7},
 {9, 7}, {36, 7}, {9, 7}, {10, 7}, {10, 7},
 {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry ortek_geom_rows [] = {
  ROW (ortek_geom_row0, 7),
  EMPTYROW (5),
  ROW (ortek_geom_row2, 7),
  ROW (ortek_geom_row3, 7),
  ROW (ortek_geom_row4, 7),
  ROW (ortek_geom_row5, 7),
  ROW (ortek_geom_row6, 7),
};

static const struct keyboard_geometry ortek_geom = {
  sizeof (ortek_geom_rows) / sizeof (struct keyboard_row_geometry),
  ortek_geom_rows, 6, 3, 3
};
