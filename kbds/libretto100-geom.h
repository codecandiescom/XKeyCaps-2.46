/* xkeycaps, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Toshiba Libretto
 * 100CT/2.1 (model no. PA1254EA).
 *
 * david arnold <d@pobox.com> september 1999 
 */

static const struct key_geometry libretto100_geom_row0 [] = {
    {11, 06}, {11, 06}, {11, 06}, {11, 06}, {11, 06}, {11, 06},
    {11, 06}, {11, 06}, {11, 06}, {11, 06}, {11, 06}, {11, 06},
    {11, 06}, {12, 06}, {11, 06}, {11, 06}, {11, 06}};

static const struct key_geometry libretto100_geom_row1 [] = {
    {4,0},
    {14,12}, {14,12}, {14,12}, {14,12}, {14,12}, {14,12},
    {14,12}, {14,12}, {14,12}, {14,12}, {14,12}, {14,12},
    {16,12}};

static const struct key_geometry libretto100_geom_row2 [] = {
    {12,12}, {14,12}, {14,12}, {14,12}, {14,12}, {14,12},
    {14,12}, {14,12}, {14,12}, {14,12}, {14,12}, {12,12},
    {12,12}, {12,12}};

static const struct key_geometry libretto100_geom_row3 [] = {
    {15,12}, {14,12}, {14,12}, {14,12}, {14,12}, {14,12},
    {14,12}, {14,12}, {14,12}, {14,12}, {13,12}, {13,12},
    {21,12}};

static const struct key_geometry libretto100_geom_row4 [] = {
    {23,12}, {14,12}, {14,12}, {14,12}, {14,12}, {14,12}, {14,12},
    {14,12}, {14,12}, {13,12}, {13,12}, {13,12}, {14,12}};

static const struct key_geometry libretto100_geom_row5 [] = {
    {13,12}, {13,12}, {13,12}, {69,12}, {13,12}, {13,12},
    {13,12}, {14,12}, {13,12}, {14,12}};

static const struct keyboard_row_geometry libretto100_geom_rows [] = {
    ROW (libretto100_geom_row0, 06),
    ROW (libretto100_geom_row1, 12),
    ROW (libretto100_geom_row2, 12),
    ROW (libretto100_geom_row3, 12),
    ROW (libretto100_geom_row4, 12),
    ROW (libretto100_geom_row5, 12),
};

static const struct keyboard_geometry libretto100_geom = {
  sizeof (libretto100_geom_rows) / sizeof (struct keyboard_row_geometry),
  libretto100_geom_rows, 4, 3, 3
};
