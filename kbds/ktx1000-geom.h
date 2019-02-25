/* xkeycaps, Copyright (c) 1991, ..., 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file specifies the geometry of a keyboard that comes
 * with a KTX 1000 laptop as distributed by Edge <http://www.edge.net.au/>.
 * File edited by Neil Zanella <nzanella@ganymede.cs.mun.ca>.
 */

static const struct key_geometry ktx1000_row1 [] = {
 {15, 10}, {16, 10}, {16, 10}, {16, 10}, {16, 10}, {16, 10},
 {16, 10}, {16, 10}, {16, 10}, {16, 10}, {16, 10}, {16, 10},
 {16, 10}, {16, 10}, {16, 10}, {16, 10}, {16, 10}
};

static const struct key_geometry ktx1000_row2 [] = {
 {11, 0}, /* this corresponds to an empty space on the kbd */
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {28, 18}, {16, 18},
};

static const struct key_geometry ktx1000_row3 [] = {
 {21, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {16, 18}
};

static const struct key_geometry ktx1000_row4 [] = {
 {24, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {33, 18}, {16,18}
};

static const struct key_geometry ktx1000_row5 [] = {
 {33, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {26, 18},
 {16, 18}, {16, 18}
};

static const struct key_geometry ktx1000_row6 [] = {
 {16, 18}, {16, 18}, {16, 18}, {16, 18}, {16, 18}, {79, 18},
 {16, 18}, {16, 18}, {16, 18}, {16, 18}, {16, 18}, {16, 18},
 {16, 18}
};

static const struct keyboard_row_geometry ktx1000_rows [] = {
  ROW (ktx1000_row1, 10),
  ROW (ktx1000_row2, 18),
  ROW (ktx1000_row3, 18),
  ROW (ktx1000_row4, 18),
  ROW (ktx1000_row5, 18),
  ROW (ktx1000_row6, 18),
};

/* The following is not documented in the file defining.txt. */
/* What exactly does this do and do I have to have it here?  */

static const struct keyboard_geometry ktx1000_geom = {
  sizeof (ktx1000_rows) / sizeof (struct keyboard_row_geometry),
  ktx1000_rows, 3, 1, 1
};
