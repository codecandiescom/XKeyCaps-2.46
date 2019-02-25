/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the DEC LK421 keyboard.
 * By Tom Ivar Helbekkmo <tih@barsoom.nhh.no>
 *
 * The LK421 is really an LK401 that has been shrunk by removing the keypads,
 * and having them doubled on normal keys through the use of a new "Extend"
 * modifier that's local to the keyboard; it is not "visible" to the X clients.
 *
 * This file displays two images of the keyboard, the "normal" one on top,
 * and one containing only the "extended" keyboard at the bottom.  This is 
 * necessary because each key has two keycodes...
 */

static const struct key_geometry lk421_geom_row0 [] = {
 {1, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry lk421_geom_row1 [] = {
 {1, 0}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {18, 7}
};

static const struct key_geometry lk421_geom_row2 [] = {
 {1, 0}, {14, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry lk421_geom_row3 [] = {
 {18, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {17, 7}
};

static const struct key_geometry lk421_geom_row4 [] = {
 {21, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {21, 7}
};

static const struct key_geometry lk421_geom_row5 [] = {
 {8, 0}, {7, 7}, {14, 7}, {49, 7}, {14, 7}, {14, 7}
};

static const struct key_geometry lk421_geom_row7 [] = {
 {1, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry lk421_geom_row8 [] = {
 {46, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry lk421_geom_row9 [] = {
 {50, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry lk421_geom_row10 [] = {
 {53, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 0}, {17, 7}
};

static const struct key_geometry lk421_geom_row11 [] = {
 {56, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {21, 7}
};

static const struct key_geometry lk421_geom_row12 [] = {
 {1, 0}, {7, 7}, {21, 0}, {49, 0}
};

static const struct keyboard_row_geometry lk421_geom_rows [] = {
  ROW (lk421_geom_row0, 7),
  ROW (lk421_geom_row1, 7),
  ROW (lk421_geom_row2, 7),
  ROW (lk421_geom_row3, 7),
  ROW (lk421_geom_row4, 7),
  ROW (lk421_geom_row5, 7),
  EMPTYROW (7),
  ROW (lk421_geom_row7, 7),
  ROW (lk421_geom_row8, 7),
  ROW (lk421_geom_row9, 7),
  ROW (lk421_geom_row10, 7),
  ROW (lk421_geom_row11, 7),
  ROW (lk421_geom_row12, 7),
};

static const struct keyboard_geometry lk421_geom = {
  sizeof (lk421_geom_rows) / sizeof (struct keyboard_row_geometry),
  lk421_geom_rows, 6, 3, 3
};
