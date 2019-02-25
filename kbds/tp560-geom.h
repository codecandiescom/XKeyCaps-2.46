/* xkeycaps, Copyright (c) 1998, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the IBM ThinkPad 560 keyboard.
 * By Lucien Saviot <saviot@jumilhac.univ-lyon1.fr>
 */

static const struct key_geometry tp560_geom_row0 [] = {
  {13, 10},{114, 0},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10}
};

static const struct key_geometry tp560_geom_row1 [] = {
  {13, 10},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10},{13, 10},{5, 0},
  {13, 10},{13, 10},{13, 10},
};

static const struct key_geometry tp560_geom_row2 [] = {
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{28, 14}
};

static const struct key_geometry tp560_geom_row3 [] = {
  {20, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{5, 0},{17, 28}
};

static const struct key_geometry tp560_geom_row4 [] = {
  {25, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14}
};

static const struct key_geometry tp560_geom_row5 [] = {
  {18, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{38, 14}
};

static const struct key_geometry tp560_geom_row6 [] = {
  {14, 14},{22, 14},{22, 14},{71, 14},{22, 14},{22, 14},{13, 0},{12, 10}
};

static const struct key_geometry tp560_geom_row7 [] = {
  {174, 0},{12, 10},{12, 10},{12, 10}
};

static const struct keyboard_row_geometry tp560_geom_rows [] = {
  ROW (tp560_geom_row0, 10),
  ROW (tp560_geom_row1, 10),
  EMPTYROW (3),
  ROW (tp560_geom_row2, 14),
  ROW (tp560_geom_row3, 14),
  ROW (tp560_geom_row4, 14),
  ROW (tp560_geom_row5, 14),
  ROW (tp560_geom_row6, 10),
  ROW (tp560_geom_row7, 10),
};

static const struct keyboard_geometry tp560_geom = {
  sizeof (tp560_geom_rows) / sizeof (struct keyboard_row_geometry),
  tp560_geom_rows, 3, 3, 3
};
