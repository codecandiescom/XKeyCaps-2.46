/* xkeycaps, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Tecra 500CDT laptop, and may
 * be suitable for many others (Cesar Crusius 1997)
 */

static const struct key_geometry tecra500_geom_row0 [] = {
    {15, 10}, {18, 10}, {18, 10}, {18, 10}, {18, 10}, {18, 10},
    {18, 10}, {18, 10}, {18, 10}, {18, 10}, {18, 10}, {18, 10},
    {18, 10}, {3, 0}, {18, 10}, {15, 10}};

static const struct key_geometry tecra500_geom_row2 [] = {
    {5,0}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18},
    {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18},
    {18,18}, {31,18}, {15,18}};

static const struct key_geometry tecra500_geom_row3 [] = {
    {14,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18},
    {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18},
    {18,18}, {22,18}, {15,18}};

static const struct key_geometry tecra500_geom_row4 [] = {
    {17,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18},
    {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {37,18},
    {15,18}};

static const struct key_geometry tecra500_geom_row5 [] = {
    {27,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18},
    {18,18}, {18,18}, {18,18}, {18,18}, {27,18}, {18,18},
    {15,18}};

static const struct key_geometry tecra500_geom_row6 [] = {
    {19,18}, {19,18}, {19,18}, {105,18}, {18,18}, {18,18},
    {18,18}, {18,18}, {18,18}, {15,18}};

static const struct keyboard_row_geometry tecra500_geom_rows [] = {
    ROW (tecra500_geom_row0, 18),
    ROW (tecra500_geom_row2, 18),
    ROW (tecra500_geom_row3, 18),
    ROW (tecra500_geom_row4, 18),
    ROW (tecra500_geom_row5, 18),
    ROW (tecra500_geom_row6, 18),
};

static const struct keyboard_geometry tecra500_geom = {
  sizeof (tecra500_geom_rows) / sizeof (struct keyboard_row_geometry),
  tecra500_geom_rows, 2, 3, 3
};
