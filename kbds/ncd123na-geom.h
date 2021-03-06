/* xkeycaps, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the NCD-123NA keyboard.
 * By Vladimir Alexiev <vladimir@cs.ualberta.ca>.
 * Based on the NCD123-UX keyboard by John Palmieri <palmieri@math.mit.edu>.
 */

static const struct key_geometry ncd123na_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry ncd123na_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};


static const struct keyboard_row_geometry ncd123na_geom_rows [] = {
  ROW (ncd123_geom_row0, 7),
  EMPTYROW (7),
  ROW (ncd123na_geom_row1, 7),
  ROW (ncd123na_geom_row2, 7),
  ROW (ncd123_geom_row3, 7),
  ROW (ncd123_geom_row4, 7),
  ROW (ncd123_geom_row5, 7),
};

static const struct keyboard_geometry ncd123na_geom = {
  sizeof (ncd123na_geom_rows) / sizeof (struct keyboard_row_geometry),
  ncd123na_geom_rows, 6, 3, 3
};

