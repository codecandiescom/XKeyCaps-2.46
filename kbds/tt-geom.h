/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Atari TT (USA) keyboard
 * By Mats Wichmann <mats@alruna.com>
 */

static const struct key_geometry tt_geom_row0 [] = {
 {31, 10}, {31, 10}, {31, 10}, {31, 10}, {31, 10}, {31, 10}, {31, 10},
 {31, 10}, {31, 10}, {31, 10}
};

static const struct key_geometry tt_geom_row2 [] = {
 {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20},
 {30, 20}, {7, 0},
 {30, 20}, {30, 20}, {7, 0},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}
};

static const struct key_geometry tt_geom_row3 [] = {
 {30, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 0},
 {20, 20}, {7, 0},
 {20, 20}, {20, 20}, {20, 20}, {7, 0},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}
};

static const struct key_geometry tt_geom_row4 [] = {
 {35, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {35, 20}, {20, 20}, {7, 0},
 {20, 20}, {20, 20}, {20, 20}, {7, 0},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}
};

static const struct key_geometry tt_geom_row5 [] = {
#if 0
  /* Non-US Atari keyboards have, instead of a wide left-shift key,
     a narrower left-shift and an additional "standard" key */
 {25, 20}, {20, 20},
#else
 {45, 20},
#endif
 {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20}, {20, 20},
 {20, 20}, {20, 20}, {20, 20}, {20, 20}, {30, 20}, {109, 0}, {20, 20},
 {20, 20}, {20, 20}, {20, 40}
};

static const struct key_geometry tt_geom_row6 [] = {
 {23, 0}, {30, 20}, {180, 20}, {30, 20}, {121, 0}, {40, 20}, {20, 20}
};

static const struct keyboard_row_geometry tt_geom_rows [] = {
  ROW (tt_geom_row0, 10),
  EMPTYROW (15),
  ROW (tt_geom_row2, 20),
  ROW (tt_geom_row3, 20),
  ROW (tt_geom_row4, 20),
  ROW (tt_geom_row5, 20),
  ROW (tt_geom_row6, 20),
};

static const struct keyboard_geometry tt_geom = {
  sizeof (tt_geom_rows) / sizeof (struct keyboard_row_geometry),
  tt_geom_rows, 2, 3, 3
};
