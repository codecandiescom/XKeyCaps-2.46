/* xkeycaps, Copyright (c) 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Tektronix VT200 keyboard.
 * By Juergen Stuber <juergen.stuber@mpi-sb.mpg.de>.
 */

static const struct key_geometry tek200_geom_row0 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {14, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek200_geom_row2 [] = {
 {6, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {10, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek200_geom_row3 [] = {
 {6, 0}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {1, 0},
 {7, 14}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek200_geom_row4 [] = {
 {7, 7}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {19, 0},
 {7, 7}, {12, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry tek200_geom_row5 [] = {
 {15, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {15, 7}, {6, 0},
 {7, 7}, {7, 7}, {7, 7}, {5, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry tek200_geom_row6 [] = {
 {6, 0}, {10, 7}, {69, 7}, {54, 0}, {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry tek200_geom_rows [] = {
  ROW (tek200_geom_row0, 7),
  EMPTYROW (4),
  ROW (tek200_geom_row2, 7),
  ROW (tek200_geom_row3, 7),
  ROW (tek200_geom_row4, 7),
  ROW (tek200_geom_row5, 7),
  ROW (tek200_geom_row6, 7),
};

static const struct keyboard_geometry tek200_geom = {
  sizeof (tek200_geom_rows) / sizeof (struct keyboard_row_geometry),
  tek200_geom_rows, 6, 3, 3
};
