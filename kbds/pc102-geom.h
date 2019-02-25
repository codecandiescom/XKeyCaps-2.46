/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of a generic 102 key PC keyboard,
 * like the NCD X terminal N102 keyboard.
 * By Pekka Nikander <pnr@innopoli.ajk.tele.fi>
 */

static const struct key_geometry pc102_geom_row0 [] = {
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {15, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_geom_row3 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {9, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc102_geom_row4 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {38, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_geom_row5 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {20, 7}, {11, 0},
 {7, 7}, {11, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc102_geom_row6 [] = {
 {11, 7}, {7, 0},
 {11, 7}, {48, 7}, {11, 7}, {7, 0},
 {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc102_geom_rows [] = {
  ROW (pc102_geom_row0, 7),
  EMPTYROW (5),
  ROW (pc102_geom_row2, 7),
  ROW (pc102_geom_row3, 7),
  ROW (pc102_geom_row4, 7),
  ROW (pc102_geom_row5, 7),
  ROW (pc102_geom_row6, 7),
};

static const struct keyboard_geometry pc102_geom = {
  sizeof (pc102_geom_rows) / sizeof (struct keyboard_row_geometry),
  pc102_geom_rows, 6, 3, 3
};
