/* xkeycaps, Copyright (c) 1994, 1995, 1996 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Texas Instruments
 * TravelMate 4000M multimedia notebook keyboard layout.
 * By Kenneth E. Harker <iago@cs.dartmouth.edu>
 */

static const struct key_geometry tm4000m_geom_row1 [] = {
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8},
 {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}
};

static const struct key_geometry tm4000m_geom_row2 [] = {
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {14, 10}
};

static const struct key_geometry tm4000m_geom_row3 [] = {
 {14, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10},
};

static const struct key_geometry tm4000m_geom_row4 [] = {
 {18, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {16, 10}
};

static const struct key_geometry tm4000m_geom_row5 [] = {
 {22, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {22, 10}
};

static const struct key_geometry tm4000m_geom_row6a [] = {
 {16, 10}, {10, 10}, {10, 10}, {58, 10}, {10, 10}, {10, 5}, {10, 5}, 
 {10, 5}, {10, 5}
};

static const struct key_geometry tm4000m_geom_row6b [] = {
  {104, 0}, {10, 5}, {10, 5}, {10, 5}, {10, 5}
};

static const struct keyboard_row_geometry tm4000m_geom_rows [] = {
  ROW (tm4000m_geom_row1, 8),
  ROW (tm4000m_geom_row2, 10),
  ROW (tm4000m_geom_row3, 10),
  ROW (tm4000m_geom_row4, 10),
  ROW (tm4000m_geom_row5, 10),
  ROW (tm4000m_geom_row6a, 10),
  EMPTYROW(5),
  ROW (tm4000m_geom_row6b, 10)
};

static const struct keyboard_geometry tm4000m_geom = {
  sizeof (tm4000m_geom_rows) / sizeof (struct keyboard_row_geometry), 
  tm4000m_geom_rows, 6, 4, 4
};

