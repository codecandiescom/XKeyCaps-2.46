/* xkeycaps, Copyright (c) 1994, 1997 Jamie Zawinski <jwz@jwz.org>
 *
 * file for the layout of the GVC Windows 95 keyboard (I think they use it for
 * all models) in the U.S. sold as ARM notebooks (model ARM 753CD was used for
 * creating these files.)
 *
 * by R.Back <back@picard.mathematik.uni-wuerzburg.de>
 */

static const struct key_geometry gvc_row1 [] = {
 {19, 12}, 
 {1,0},  
 {15, 12}, {15, 12}, {15, 12}, {15, 12}, {15, 12},
 {15, 12}, {15, 12}, {15, 12}, {15, 12}, {15, 12}, {15, 12},
 {15, 12}, {17, 12}, {17, 12}, {17, 12}, {17, 12}
};

static const struct key_geometry gvc_row2 [] = {
 {24, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {28, 18}, {18, 18}
};

static const struct key_geometry gvc_row3 [] = {
 {15, 18}, {1,0}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}
};

static const struct key_geometry gvc_row4 [] = {
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {34, 18}, {18,18}
};

static const struct key_geometry gvc_row5 [] = {
 {28, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18},
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {24, 18},
 {18, 18}, {18, 18}
};

static const struct key_geometry gvc_row6 [] = {
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {70, 18}, 
 {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}, {18, 18}
};

static const struct keyboard_row_geometry gvc_rows [] = {
  ROW (gvc_row1, 12),
  ROW (gvc_row2, 18),
  ROW (gvc_row3, 18),
  ROW (gvc_row4, 18),
  ROW (gvc_row5, 18),
  ROW (gvc_row6, 18),
};

static const struct keyboard_geometry gvc_geom = {
  sizeof (gvc_rows) / sizeof (struct keyboard_row_geometry),
  gvc_rows, 3, 1, 1
};
