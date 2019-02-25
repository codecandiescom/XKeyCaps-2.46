/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a Northgate OmniKey Ultra
 * keyboard (part number: 560,0020, vendor code: 777, rev 6.04, 18 June 91).
 * By John A. Martin <jam@acm.org>
 */

static const struct key_geometry omniultra_geom_row0 [] = {
 { 7, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7},
 {10, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7},
 {11, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7}
};

static const struct key_geometry omniultra_geom_row2 [] = {
 { 7, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7},
 { 7, 7}, { 7, 7}, { 7, 7}, {14, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7}
};

static const struct key_geometry omniultra_geom_row3 [] = {
 { 7, 7}, { 7, 7},
 { 3, 0},
 {10, 7}, { 7, 7}, { 7, 7}, { 7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, { 7, 7}, {11,14},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, { 7, 7}
};

static const struct key_geometry omniultra_geom_row4 [] = {
 { 7, 7}, { 7, 7},
 { 3, 0},
 {12, 7}, { 7, 7}, { 7, 7}, {7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, { 7, 7}, {7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, {16, 0},
 {3, 0},
 { 7, 7}, { 7, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7}, {7, 7}
};

static const struct key_geometry omniultra_geom_row5 [] = {
 { 7, 7}, { 7, 7},
 { 3, 0},
 {15, 7}, { 7, 7}, { 7, 7}, {7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, { 7, 7}, {7, 7}, {7, 7},
 { 7, 7}, {13, 7}, { 7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, { 7, 7},
 { 3,0},
 { 7, 7}, { 7, 7}, { 7, 7}, {7, 14}
};

static const struct key_geometry omniultra_geom_row6 [] = {
 { 7, 7}, { 7, 7},
 { 3, 0},
 {10, 7}, { 7, 7}, {10, 7}, {50,7},
 {10, 7}, { 7, 7}, {11, 7},
 { 3, 0},
 {10, 7}, {11, 7},
 { 3, 0},
 {14, 7}, { 7, 7}
};

static const struct keyboard_row_geometry omniultra_geom_rows [] = {
  ROW (omniultra_geom_row0, 7),
  EMPTYROW (3),
  ROW (omniultra_geom_row2, 7),
  ROW (omniultra_geom_row3, 7),
  ROW (omniultra_geom_row4, 7),
  ROW (omniultra_geom_row5, 7),
  ROW (omniultra_geom_row6, 7),
};

static const struct keyboard_geometry omniultra_geom = {
  sizeof (omniultra_geom_rows) / sizeof (struct keyboard_row_geometry),
  omniultra_geom_rows, 6, 3, 3
};
