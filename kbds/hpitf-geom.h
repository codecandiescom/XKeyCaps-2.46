/* xkeycaps, Copyright (c) 1991, 1992 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the HP 300, 400, and 700 
 * series keyboards.  By Dave Brooks <dbrooks@inel.gov>.
 */

static const struct key_geometry hpitf_geom_row0 [] = {
 {8, 7}, {8, 7}, {2, 0},
 {9, 7}, {9, 7}, {9, 7}, {9, 7}, {7, 7}, {7, 7}, {9, 7}, {9, 7}, {9, 7},
 {9, 7}, {2, 0},
 {8, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry hpitf_geom_row2 [] = {
 {9, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {12, 7}, {2, 0},
 {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry hpitf_geom_row3 [] = {
 {14, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {2, 0},
 {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry hpitf_geom_row4 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {2, 0},
 {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry hpitf_geom_row5 [] = {
 {7, 7}, {11, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {11, 7}, {1, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry hpitf_geom_row6 [] = {
 {7, 7}, {11, 0},
 {7, 7}, {56, 7}, {7, 7}, {12, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry hpitf_geom_rows [] = {
  ROW (hpitf_geom_row0, 7),
  EMPTYROW (3),
  ROW (hpitf_geom_row2, 7),
  ROW (hpitf_geom_row3, 7),
  ROW (hpitf_geom_row4, 7),
  ROW (hpitf_geom_row5, 7),
  ROW (hpitf_geom_row6, 7),
};

static const struct keyboard_geometry hpitf_geom = {
  sizeof (hpitf_geom_rows) / sizeof (struct keyboard_row_geometry),
  hpitf_geom_rows, 6, 3, 3
};
