/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the HCL eXceed PC X-server 
 * keyboard.
 */

static const struct key_geometry hclpc_geom_row0 [] = {
 {7, 7}, {6, 0},
 {6, 7}, {6, 7}, {6, 7}, {6, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {6, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {6, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}
};

static const struct key_geometry hclpc_geom_row2 [] = {
 {8, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7},
 {6, 7}, {6, 7}, {6, 7}, {6, 7}, {11, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {6, 7}
};

static const struct key_geometry hclpc_geom_row3 [] = {
 {11, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7},
 {6, 7}, {6, 7}, {6, 7}, {6, 7}, {8, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {6, 14}
};

static const struct key_geometry hclpc_geom_row4 [] = {
 {13, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7},
 {6, 7}, {6, 7}, {6, 7}, {12, 7}, {3, 0},
 {6, 0}, {6, 0}, {6, 0}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}
};

static const struct key_geometry hclpc_geom_row5 [] = {
 {16, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7}, {6, 7},
 {6, 7}, {6, 7}, {15, 7}, {9, 0},
 {6, 7}, {9, 0},
 {6, 7}, {6, 7}, {6, 7}, {6, 14}
};

static const struct key_geometry hclpc_geom_row6 [] = {
 {9, 7}, {6, 0},
 {8, 7}, {45, 7}, {8, 7}, {6, 0},
 {9, 7}, {3, 0},
 {6, 7}, {6, 7}, {6, 7}, {3, 0},
 {12, 7}, {6, 7}
};

static const struct key_geometry hclpc_geom_row8 [] = {
 {115, 0}, {6, 7}, {6, 7}, {6, 7}, {6, 14}
};

static const struct key_geometry hclpc_geom_row9 [] = {
 {115, 0}, {6, 7}, {6, 7}, {6, 7}
};

static const struct key_geometry hclpc_geom_row10 [] = {
 {115, 0}, {6, 7}, {6, 7}, {6, 7}, {6, 14}
};

static const struct key_geometry hclpc_geom_row11 [] = {
 {115, 0}, {12, 7}, {6, 7}
};

static const struct keyboard_row_geometry hclpc_geom_rows [] = {
  ROW (hclpc_geom_row0, 7),
  EMPTYROW (3),
  ROW (hclpc_geom_row2, 7),
  ROW (hclpc_geom_row3, 7),
  ROW (hclpc_geom_row4, 7),
  ROW (hclpc_geom_row5, 7),
  ROW (hclpc_geom_row6, 7),
  EMPTYROW (3),
  ROW (hclpc_geom_row8, 7),
  ROW (hclpc_geom_row9, 7),
  ROW (hclpc_geom_row10, 7),
  ROW (hclpc_geom_row11, 7),
};

static const struct keyboard_geometry hclpc_geom = {
  sizeof (hclpc_geom_rows) / sizeof (struct keyboard_row_geometry),
  hclpc_geom_rows, 6, 3, 3
};
