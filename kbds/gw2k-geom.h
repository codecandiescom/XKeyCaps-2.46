/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the physical layout of the Gateway 2000
 * AnyKey programmable PC keyboard.
 * By Jarrod Smith <jsmith@scripps.edu>
 *
 * Important notes about this keyboard:
 * 
 * In order for all the keysyms to work properly, the programmable ROM
 * inside the keyboard may need to be reset to factory default by pressing
 * <Ctrl>-<Alt>-<Suspnd Macro>
 * even if you have NEVER programmed anything into the keyboard!  If you
 * have programmed macros in that you don't want to lose, you should be
 * able to save them by using the DOS utility that came with the keyboard
 * BEFORE you reset the ROM.
 * 
 * I couldn't get xmodmap to get the BackSpace keysym working right for my
 * keyboard until I did this.  It would let me change the keysym for my
 * backspace key from Delete to BackSpace which is what I wanted it to do,
 * but I have no clue what the BackSpace keysym was doing!  Certainly not
 * Backspacing!!!  It worked on the command-line, but in some X apps it
 * would give me the <+/-> character, and in others, nothing...   weird.
 * 
 * Also, there are four diagonal cursor keys on this keyboard (up-left,
 * up-right, down-left, down-right) which each generate two keycodes per
 * keypress event.   I didn't know what to do about this in the
 * gw2k-codes.h file, so I just put in the first keycode that gets
 * generated (see the comments in row4 and row6 in that file).  Also, I
 * didn't know what to put in the gw2k-caps.h file since there are no
 * diagonal arrow keycaps to put on the keys, so again, I put the keycap
 * that corresponds to the first keycode generated (I tried putting both
 * on, but it looked funny to me) and "shifted" the arrows to differentiate
 * them from the normal up and down keys.
 */

static const struct key_geometry gw2k_geom_row0 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {3, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry gw2k_geom_row1 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry gw2k_geom_row2 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {7, 7}, {11, 14}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry gw2k_geom_row3 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {12, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {7, 7}, {16, 0}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}
};

static const struct key_geometry gw2k_geom_row4 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {16, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
 {7, 7}, {7, 7}, {19, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {7, 14}
};

static const struct key_geometry gw2k_geom_row5 [] = {
 {7, 7}, {7, 7}, {4, 0},
 {10, 7}, {7, 7}, {10, 7}, {51, 7}, {10, 7}, {7, 7}, {10, 7}, {4, 0},
 {7, 7}, {7, 7}, {7, 7}, {4, 0},
 {14, 7}, {7, 7}
};

static const struct keyboard_row_geometry gw2k_geom_rows [] = {
  ROW (gw2k_geom_row0, 7),
  EMPTYROW (5),
  ROW (gw2k_geom_row1, 7),
  ROW (gw2k_geom_row2, 7),
  ROW (gw2k_geom_row3, 7),
  ROW (gw2k_geom_row4, 7),
  ROW (gw2k_geom_row5, 7)
};

static const struct keyboard_geometry gw2k_geom = {
  sizeof (gw2k_geom_rows) / sizeof (struct keyboard_row_geometry),
  gw2k_geom_rows, 6, 3, 3
};

