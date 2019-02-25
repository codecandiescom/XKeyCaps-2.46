/* xkeycaps, Copyright (c) 1998, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Compaq Presario 1655
 * keyboard.
 * By Hans Huebner <hans@huebner.org>
 */

static const struct key_geometry presario_geom_row1 [] = {
  {16, 10},
  {12, 10},{12, 10},{12, 10},{12, 10},
  {12, 10},{12, 10},{12, 10},{12, 10},
  {12, 10},{12, 10},{12, 10},{12, 10},
  {12, 10},{12, 10},{12, 10},{13, 10},
};

static const struct key_geometry presario_geom_row2 [] = {
  {13, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {17, 14},{11, 14}
};

static const struct key_geometry presario_geom_row3 [] = {
  {18, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {12, 14},{11, 14}
};

static const struct key_geometry presario_geom_row4 [] = {
  {22, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {22, 14},{11, 14}
};

static const struct key_geometry presario_geom_row5 [] = {
  {28, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {14, 14},{14, 14},{14, 14},{14, 14},{14, 14},
  {30, 14},{11, 14}
};

static const struct key_geometry presario_geom_row6 [] = {
  {14, 14}, {14, 14}, {14, 14}, {14, 14}, {12, 14},
  {56, 14}, {14, 14}, {14, 14}, {11, 14}, {11, 14},
  {13, 0},{11, 10}
};

static const struct key_geometry presario_geom_row7 [] = {
  {176, 0},{11, 10},{11, 10},{11, 10}
};

static const struct keyboard_row_geometry presario_geom_rows [] = {
  ROW (presario_geom_row1, 10),
  ROW (presario_geom_row2, 14),
  ROW (presario_geom_row3, 14),
  ROW (presario_geom_row4, 14),
  ROW (presario_geom_row5, 14),
  ROW (presario_geom_row6, 10),
  ROW (presario_geom_row7, 10),
};

static const struct keyboard_geometry presario_geom = {
  sizeof (presario_geom_rows) / sizeof (struct keyboard_row_geometry),
  presario_geom_rows, 3, 3, 3
};
