/* xkeycaps, Copyright (c) 1997, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Micron 
 * Transport Trek2 notebook keyboard layout.
 * By Alan Ho <alanho@princeton.edu>
 */

static const struct key_geometry trek_geom_row1 [] = {
 {16, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}
};

static const struct key_geometry trek_geom_row2 [] = {
{8,10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {8, 10}, {8, 10}
};

static const struct key_geometry trek_geom_row3 [] = {
 {8, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {8, 10}, {8, 10}
};

static const struct key_geometry trek_geom_row4 [] = {
 {12, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {14, 10}, {8, 10}
};

static const struct key_geometry trek_geom_row5 [] = {
 {16, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {12, 10},
 {8, 10}, {8,10}
};

static const struct key_geometry trek_geom_row6 [] = {
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {50, 10},
 {10, 10}, {10, 10}, {10, 10}, 
 {8, 10}, {8, 10}, {8, 10}
};


static const struct keyboard_row_geometry trek_geom_rows [] = {
  ROW (trek_geom_row1, 8),
  ROW (trek_geom_row2, 10),
  ROW (trek_geom_row3, 10),
  ROW (trek_geom_row4, 10),
  ROW (trek_geom_row5, 10),
  ROW (trek_geom_row6, 10)
};

static const struct keyboard_geometry trek_geom = {
  sizeof (trek_geom_rows) / sizeof (struct keyboard_row_geometry), 
  trek_geom_rows, 6, 4, 4
};

