/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Cherry ErgoPlus keyboards 
 * with German layout.  
 * By Berthold Gunreben <gunreben@wvwx01.wifak.uni-wuerzburg.de>
 *
 */

static const struct key_geometry chergo_geom_row0 [] = {
 {7, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry  chergo_geom_row1 [] = {
 {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {13, 7}, {3, 0},
 {7, 7}, {7, 7}
};

static const struct key_geometry chergo_geom_row2 [] = {
 {7, 7}, {3, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0}, {8, 14}, {3, 0},
 {7, 7}, {7, 7}
};

static const struct key_geometry chergo_geom_row3 [] = {
 {7, 7}, {3, 0},
 {11, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 0},
 {7, 7}, {7, 7}
};

static const struct key_geometry chergo_geom_row4 [] = {
 {7, 7}, {3, 0},
 {8, 7}, {7,7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {11, 7}, {11, 0},
 {7, 7}
};

static const struct key_geometry chergo_geom_row5 [] = {
 {7, 7}, {3, 0},
 {10, 7}, {3, 0}, 
 {10, 7}, {24, 7}, {2, 0}, {24, 7}, {10, 7}, {3, 0}, {10, 7},
 {4, 0}, {7, 7}, {7, 7}, {7, 7}
};

static const struct keyboard_row_geometry chergo_geom_rows [] = {
  ROW (chergo_geom_row0, 7),
  EMPTYROW (7),
  ROW (chergo_geom_row1, 7),
  ROW (chergo_geom_row2, 7),
  ROW (chergo_geom_row3, 7),
  ROW (chergo_geom_row4, 7),
  ROW (chergo_geom_row5, 7),
};

static const struct keyboard_geometry chergo_geom = {
  sizeof (chergo_geom_rows) / sizeof (struct keyboard_row_geometry),
  chergo_geom_rows, 6, 3, 3
};
