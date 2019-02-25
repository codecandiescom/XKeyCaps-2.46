/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the layout of a "JETYO EBK-1024" 102 key PC-style
 * keyboard. By Volker Bosch <volker@ytei.faveve.uni-stuttgart.de>.
 */

static const struct key_geometry pc102_2_geom_row0 [] = {
 {8, 7}, {0, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_2_geom_row2 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_2_geom_row3 [] = {
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 0},
 {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc102_2_geom_row4 [] = {
 {14, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {14, 7}, {27, 0},		
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry pc102_2_geom_row5 [] = {
 {17, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {18, 7}, {10, 0},
 {7, 7}, {10, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry pc102_2_geom_row6 [] = {
 {10, 7}, {7, 7}, {9, 7}, {53, 7}, {9, 7}, {7, 7}, {10, 7}, {3, 0},
 {7,7}, {7,7}, {7, 7}, {3, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry pc102_2_geom_rows [] = {
  ROW (pc102_2_geom_row0, 7),
  EMPTYROW (5),
  ROW (pc102_2_geom_row2, 7),
  ROW (pc102_2_geom_row3, 7),
  ROW (pc102_2_geom_row4, 7),
  ROW (pc102_2_geom_row5, 7),
  ROW (pc102_2_geom_row6, 7)
};

static const struct keyboard_geometry pc102_2_geom = {
 sizeof (pc102_2_geom_rows) / sizeof (struct keyboard_row_geometry),
   pc102_2_geom_rows, 6, 3, 3
};
