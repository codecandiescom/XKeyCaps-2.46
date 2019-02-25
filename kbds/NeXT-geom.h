/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the NeXTstation non-ADB
 * keyboard for the co-Xist 3.0 X server.  By Eric Benson <eb@NeXT.com>.
 */

static const struct key_geometry NeXT_geom_row0 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {10, 7}, {25, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry NeXT_geom_row1 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {25, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry NeXT_geom_row2 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {11, 7}, {25, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry NeXT_geom_row3 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {15, 7}, {9, 0},
 {7, 7}, {9, 0}, {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry NeXT_geom_row4 [] = {
 {10, 7}, {10, 7}, {61, 7}, {10, 7}, {10, 7}, {2, 0},
 {7, 7}, {7, 7}, {7, 7}, {2, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry NeXT_geom_rows [] = {
ROW (NeXT_geom_row0, 7),
ROW (NeXT_geom_row1, 7),
ROW (NeXT_geom_row2, 7),
ROW (NeXT_geom_row3, 7),
ROW (NeXT_geom_row4, 7),

};

static const struct keyboard_geometry NeXT_geom = {
  sizeof (NeXT_geom_rows) / sizeof (struct keyboard_row_geometry),
  NeXT_geom_rows, 6, 3, 3
};
