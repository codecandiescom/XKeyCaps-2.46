/* xkeycaps, Copyright (c) 1994 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the pyhsical layout of the Sun type 4 Swedish keyboard.
 * By Torbj|rn Lindgren <tl@cd.chalmers.se>.
 */

static const struct key_geometry sun4sw_geom_row0 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun4sw_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun4sw_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {8, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry sun4sw_geom_row3 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry sun4sw_geom_row4 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {12, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry sun4sw_geom_row5 [] = {
 {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {63, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry sun4sw_geom_rows [] = {
  ROW (sun4sw_geom_row0, 7),
  ROW (sun4sw_geom_row1, 7),
  ROW (sun4sw_geom_row2, 7),
  ROW (sun4sw_geom_row3, 7),
  ROW (sun4sw_geom_row4, 7),
  ROW (sun4sw_geom_row5, 7),
};

static const struct keyboard_geometry sun4sw_geom = {
  sizeof (sun4sw_geom_rows) / sizeof (struct keyboard_row_geometry),
  sun4sw_geom_rows, 6, 3, 3
};
