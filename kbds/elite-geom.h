/* xkeycaps, Copyright (c) 1997 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Midwest Micro
 * Elite soundbook multimedia notebook keyboard layout.
 * By Garst R. Reese <reese@isn.net>
 */

static const struct key_geometry elite_geom_row1 [] = {
 {16, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}
};

static const struct key_geometry elite_geom_row2 [] = {
 {13, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {13, 10}, {8, 10}
};

static const struct key_geometry elite_geom_row3 [] = {
 {8, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {8, 10}, {8, 10}
};

static const struct key_geometry elite_geom_row4 [] = {
 {12, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {14, 10}, {8, 10}
};

static const struct key_geometry elite_geom_row5 [] = {
 {16, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {12, 10},
 {8, 10}, {8,10}
};

static const struct key_geometry elite_geom_row6 [] = {
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {50, 10},
 {10, 10}, {10, 10}, {10, 10}, 
 {8, 10}, {8, 10}, {8, 10}
};


static const struct keyboard_row_geometry elite_geom_rows [] = {
  ROW (elite_geom_row1, 8),
  ROW (elite_geom_row2, 10),
  ROW (elite_geom_row3, 10),
  ROW (elite_geom_row4, 10),
  ROW (elite_geom_row5, 10),
  ROW (elite_geom_row6, 10)
};

static const struct keyboard_geometry elite_geom = {
  sizeof (elite_geom_rows) / sizeof (struct keyboard_row_geometry), 
  elite_geom_rows, 6, 4, 4
};

