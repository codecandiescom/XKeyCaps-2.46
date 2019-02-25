/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Apple Standard ADB keyboard
 * for X11R6 server on NetBSD/mac68k.  By Ken Nakata <kenn@remus.rutgers.edu>.
 */

static const struct key_geometry macstd_geom_row0 [] = {
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {10, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry macstd_geom_row1 [] = {
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry macstd_geom_row2 [] = {
 {13, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {11, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry macstd_geom_row3 [] = {
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {15, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry macstd_geom_row4 [] = {
 {7, 7}, {7, 7}, {13, 7}, {7, 7}, {32, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry macstd_geom_rows [] = {
ROW (macstd_geom_row0, 7),
ROW (macstd_geom_row1, 7),
ROW (macstd_geom_row2, 7),
ROW (macstd_geom_row3, 7),
ROW (macstd_geom_row4, 7),

};

static const struct keyboard_geometry macstd_geom = {
  sizeof (macstd_geom_rows) / sizeof (struct keyboard_row_geometry),
  macstd_geom_rows, 6, 3, 3
};
