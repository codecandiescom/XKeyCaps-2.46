/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Kinesis Model 120 Keyboard.
 */

static const struct key_geometry kinesis_geom_row0 [] = {
  { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 },
  { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 },
  { 4, 6 }, { 1, 0 }, { 4, 6 },
  { 35, 0 },
  { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 },
  { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 }, { 4, 6 }, { 1, 0 },
  { 4, 6 }, { 1, 0 }, { 4, 6 }
};

static const struct key_geometry kinesis_geom_row2 [] = {
  { 9, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 },
  { 35, 0 },
  { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 9, 7 }
};

static const struct key_geometry kinesis_geom_row3 [] = {
  { 9, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 },
  { 35, 0 },
  { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 9, 7 }
};

static const struct key_geometry kinesis_geom_row4 [] = {
  { 9, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 },
  { 35, 0 },
  { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 9, 7 }
};

static const struct key_geometry kinesis_geom_row5 [] = {
  { 9, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 },
  { 35, 0 },
  { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 9, 7 }
};

static const struct key_geometry kinesis_geom_row6 [] = {
  { 9, 0 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 0 },
  { 35, 0 },
  { 7, 0 }, { 7, 7 }, { 7, 7 }, { 7, 7 }, { 7, 7 }
};

static const struct key_geometry kinesis_geom_row7 [] = {
  { 35, 0 }, { 7, 0 }, { 7, 7 }, { 7, 7 },
  { 11, 0 },
  { 7, 7 }, { 7, 7 }
};

static const struct key_geometry kinesis_geom_row8 [] = {
  { 35, 0 }, { 7, 14 }, { 7, 14 }, { 7, 7 },
  { 11, 0 },
  { 7, 7 }, { 7, 14 }, { 7, 14 }
};

static const struct key_geometry kinesis_geom_row9 [] = {
  { 35, 0 }, { 7, 0 }, { 7, 0 }, { 7, 7 },
  { 11, 0 },
  { 7, 7 }
};

static const struct keyboard_row_geometry kinesis_geom_rows [] = {
  ROW (kinesis_geom_row0, 7),
  EMPTYROW (2),
  ROW (kinesis_geom_row2, 7),
  ROW (kinesis_geom_row3, 7),
  ROW (kinesis_geom_row4, 7),
  ROW (kinesis_geom_row5, 7),
  ROW (kinesis_geom_row6, 7),
  ROW (kinesis_geom_row7, 7),
  ROW (kinesis_geom_row8, 7),
  ROW (kinesis_geom_row9, 7),
};

static const struct keyboard_geometry kinesis_geom = {
  sizeof (kinesis_geom_rows) / sizeof (struct keyboard_row_geometry),
  kinesis_geom_rows, 6, 3, 3
};
