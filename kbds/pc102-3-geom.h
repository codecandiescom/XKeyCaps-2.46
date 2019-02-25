/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a "Chicony KB-5312"
 * 102 key PC-style keyboard.
 * This differs from 'pc101-2' in a new key in the bottom-left corner 
 * (between Z and left shift in the UK layout)
 * By Ben Harris <bjh21@cam.ac.uk>
 */

static const struct key_geometry pc102_3_geom_row0 [] = {
 {7, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_3_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_3_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 14}, {4, 0}, {7, 7}, {7, 7}, {7, 7},
 {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc102_3_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {15, 0}, {29, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_3_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {19, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc102_3_geom_row6 [] = {
 {11, 7}, {7, 0},
 {11, 7}, {48, 7}, {11, 7}, {7, 0},
 {10, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc102_3_geom_rows [] = {
  ROW (pc102_3_geom_row0, 7),
  EMPTYROW (5),
  ROW (pc102_3_geom_row2, 7),
  ROW (pc102_3_geom_row3, 7),
  ROW (pc102_3_geom_row4, 7),
  ROW (pc102_3_geom_row5, 7),
  ROW (pc102_3_geom_row6, 7),
};

static const struct keyboard_geometry pc102_3_geom = {
  sizeof (pc102_3_geom_rows) / sizeof (struct keyboard_row_geometry),
  pc102_3_geom_rows, 6, 3, 3
};
