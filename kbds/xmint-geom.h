/* xkeycaps, Copyright (c) 1994 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Takaoka Xmint X Terminal.
 * By Christian Goetze <c-goetze@u-aizu.ac.jp>
 */

static const struct key_geometry xmint_geom_row0 [] = {
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}
};

static const struct key_geometry xmint_geom_row2 [] = {
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}
};

static const struct key_geometry xmint_geom_row3 [] = {
 {14, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {16, 10},
};

static const struct key_geometry xmint_geom_row4 [] = {
 {18, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {22, 10}
};

static const struct key_geometry xmint_geom_row5 [] = {
 {22, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10},
 {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {18, 10},
 {10, 10}
};

static const struct key_geometry xmint_geom_row6 [] = {
 {15, 10}, {15, 10}, {15, 10}, {60, 10}, {15, 10}, {15, 10}, {15, 10}
};

static const struct keyboard_row_geometry xmint_geom_rows [] = {
  ROW (xmint_geom_row0, 10),
  EMPTYROW (3),
  ROW (xmint_geom_row2, 10),
  ROW (xmint_geom_row3, 10),
  ROW (xmint_geom_row4, 10),
  ROW (xmint_geom_row5, 10),
  ROW (xmint_geom_row6, 10),
};

static const struct keyboard_geometry xmint_geom = {
  sizeof (xmint_geom_rows) / sizeof (struct keyboard_row_geometry),
  xmint_geom_rows, 6, 4, 4
};
