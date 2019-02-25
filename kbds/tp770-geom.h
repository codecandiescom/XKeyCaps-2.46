/* xkeycaps, Copyright (c) 1998, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the IBM ThinkPad 770ED keyboard.
 * By Jamie Zawinski <jwz@jwz.org>
 */

static const struct key_geometry tp770_geom_row0 [] = {
  {13, 10},{114, 0},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10}
};

static const struct key_geometry tp770_geom_row1 [] = {
  {13, 10},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10},
};

static const struct key_geometry tp770_geom_row2 [] = {
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{28, 14}
};

static const struct key_geometry tp770_geom_row3 [] = {
  {20, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{22, 14}
};

static const struct key_geometry tp770_geom_row4 [] = {
  {25, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{31, 14}
};

static const struct key_geometry tp770_geom_row5 [] = {
  {32, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{38, 14}
};

static const struct key_geometry tp770_geom_row6 [] = {
  {14, 14},{22, 14},{22, 14},{71, 14},{22, 14},{22, 14},{13, 0},{12, 10}
};

static const struct key_geometry tp770_geom_row7 [] = {
  {174, 0},{12, 10},{12, 10},{12, 10}
};

static const struct keyboard_row_geometry tp770_geom_rows [] = {
  ROW (tp770_geom_row0, 10),
  ROW (tp770_geom_row1, 10),
  EMPTYROW (3),
  ROW (tp770_geom_row2, 14),
  ROW (tp770_geom_row3, 14),
  ROW (tp770_geom_row4, 14),
  ROW (tp770_geom_row5, 14),
  ROW (tp770_geom_row6, 10),
  ROW (tp770_geom_row7, 10),
};

static const struct keyboard_geometry tp770_geom = {
  sizeof (tp770_geom_rows) / sizeof (struct keyboard_row_geometry),
  tp770_geom_rows, 3, 3, 3
};
