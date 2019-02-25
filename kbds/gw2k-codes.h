/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes for the Gateway 2000
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

static const KeyCode gw2k_codes [] = {
  /* Row 0 */
  95, 96,
  9,
  67, 68, 69, 70,
  71, 72, 73, 74,
  75, 76, 95, 96,
  111, 78, 110,
  0, 0, 0, 0,

  /* Row 2 */
  67, 68,
  49, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 51, 22,
  106, 97, 99,
  77, 112, 63, 82,

  /* Row 3 */
  69, 70,
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
  107, 103, 105,
  79, 80, 81, 86,
  
  /* Row 4 */
  71, 72,
  66, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,

  		/* the first and third keys on this line are diogonal up arrows that*/
  98, 98, 98, 	/* generate two codes each when pressed: 98+100 for the first, */
  		/* and 98+102 for the third (in that order).  I don't know what to*/
		/* do about this, so I put the first keycode that gets generated.  -JS*/
  83, 84, 85,

  /* Row 5 */
  73, 74,
  50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
  100, 65, 102,
  87, 88, 89, 108,

  /* Row 6 */
  75, 76,
  37, 63,
  64, 65, 113,
  51, 109,
  104, 104, 104,  /* Same problem here as above.  The first and third are diagonal down keys*/
  90, 91
};

