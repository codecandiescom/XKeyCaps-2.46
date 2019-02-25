/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Northgate OmniKey 102P
 * keyboard model (part number: KYBD102P; vendor code: 20017; rev 1.0.)
 * By Jeffrey Templon <templon@studbolt.physast.uga.edu>.
 */

static const struct key_geometry omni102_geom_row0 [] = {
  { 7, 7}, {7, 7},
  { 5, 0},
  { 7, 7},
  {98, 0}, { 3, 0},
  { 7, 7}, { 7, 7}, {7, 7}
};

static const struct key_geometry omni102_geom_row2 [] = {
 { 7, 7}, { 7, 7},
 { 5, 0},
 { 7, 7}, { 7, 7}, {7, 7}, { 7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, {7, 7}, { 7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, {7, 7}, {14, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, {7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, {7, 7}, { 7, 7}
};

static const struct key_geometry omni102_geom_row3 [] = {
 { 7, 7}, { 7, 7},
 { 5, 0},
 {10, 7}, { 7, 7}, {7, 7}, { 7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, {7, 7}, { 7, 7}, {7, 7},
 { 7, 7}, { 7, 7}, {7, 7}, {11,14},
 { 3, 0},
 { 7, 7}, { 7, 7}, {7, 7},
 { 3, 0},
 { 7, 7}, { 7, 7}, {7, 7}, { 7, 7}
};

static const struct key_geometry omni102_geom_row4 [] = {
 { 7, 7}, {7, 7},
 { 5, 0},
 {12, 7}, {7, 7}, { 7, 7}, {7, 7}, {7, 7},
 { 7, 7}, {7, 7}, { 7, 7}, {7, 7}, {7, 7},
 { 7, 7}, {7, 7},
 {16, 0}, {3, 0}, {21, 0}, {3, 0},
 { 7, 7}, {7, 7}, { 7, 7}, {7, 7}
};

static const struct key_geometry omni102_geom_row5 [] = {
 { 7, 7}, {7, 7},
 { 5, 0},
 {15, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 { 7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 { 7, 7}, {13,7}, {7, 7},
 { 3, 0}, { 7,0},
 { 7, 7},
 { 7, 0}, { 3,0},
 { 7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry omni102_geom_row6 [] = {
 { 7, 7}, {7, 7},
 { 5, 0},
 { 9, 7}, {7, 7}, {9, 7}, {52,7}, {7, 7},
 { 7, 7}, {7, 7}, {7, 7},
 { 3, 0},
 { 7, 7}, {7, 7}, {7, 7},
 { 3, 0},
 {14, 7}, {7, 7},
 { 7, 0}
};

static const struct keyboard_row_geometry omni102_geom_rows [] = {
  ROW (omni102_geom_row0, 7),
  EMPTYROW (5),
  ROW (omni102_geom_row2, 7),
  ROW (omni102_geom_row3, 7),
  ROW (omni102_geom_row4, 7),
  ROW (omni102_geom_row5, 7),
  ROW (omni102_geom_row6, 7),
};

static const struct keyboard_geometry omni102_geom = {
  sizeof (omni102_geom_rows) / sizeof (struct keyboard_row_geometry),
  omni102_geom_rows, 6, 3, 3
};
