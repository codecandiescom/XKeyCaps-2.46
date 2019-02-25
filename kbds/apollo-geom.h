/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of an HP Apollo-thingy type 
 * keyboard.  By Mick J Hellstrom <mickh@rd.scitec.com.au>              
 */

static const struct key_geometry apollo_geom_row0 [] =
{
	{7, 7}, {7, 7}, {7, 7}, {7, 0},
	{10, 7}, {11, 7}, {10, 7}, {11, 7}, {10, 7}, {7, 0},
	{10, 7}, {11, 7}, {10, 7}, {11, 7}, {10, 7}, {3, 0},
	{7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry apollo_geom_row1 [] =
{
	{7, 7}, {7, 7}, {7, 7}, {10, 0},
	{7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {9, 7}
};

static const struct key_geometry apollo_geom_row2 [] =
{
	{7, 7}, {7, 7}, {7, 7}, {10, 0},
	{10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {6, 0}, {7, 7}, {11, 0},
	{7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry apollo_geom_row3 [] =
{
	{7, 7}, {7, 7}, {7, 7}, {5, 0},
	{7, 7}, {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 7}, {7, 7}, {11, 0},
	{7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry apollo_geom_row4 [] =
{
	{7, 7}, {7, 7}, {7, 7}, {5, 0},
	{7, 7}, {14, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {14, 7}, {7, 7}, {11, 0},
	{7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry apollo_geom_row5 [] =
{
	{7, 7}, {7, 7}, {7, 7}, {36, 0},
	{55, 7}, {37, 0},
	{14, 7}, {7, 7}
};

static const struct keyboard_row_geometry apollo_geom_rows [] = {
  ROW (apollo_geom_row0, 7),
  ROW (apollo_geom_row1, 7),
  ROW (apollo_geom_row2, 7),
  ROW (apollo_geom_row3, 7),
  ROW (apollo_geom_row4, 7),
  ROW (apollo_geom_row5, 7),
};

static const struct keyboard_geometry apollo_geom = {
  sizeof (apollo_geom_rows) / sizeof (struct keyboard_row_geometry),
  apollo_geom_rows, 6, 3, 3
};
