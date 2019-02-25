/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of Gateway 2000
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

static const struct key_strings gw2k_caps [] = {

  /* Row 0 */

  {"F11", 0},
  {"F12", 0},
  {"Esc", 0},
  {"F1", 0},
  {"F2", 0},
  {"F3", 0},
  {"F4", 0},
  {"F5", 0},
  {"F6", 0},
  {"F7", 0},
  {"F8", 0},
  {"F9", 0},
  {"F10", 0},
  {"F11", 0},
  {"F12", 0},
  {"Print", "Screen", 0},
  {"Scroll", "Lock", 0},
  {"Pause", 0},
  {"Program", "Macro", 0},
  {"Suspnd", "Macro", 0},
  {"Repeat", "Rate", 0},
  {"Remap", 0},

  /* Row 2 */

  {"F1", 0},
  {"F2", 0},
  {"~", "`", 0},
  {"!", "1", 0},
  {"@", "2", 0},
  {"#", "3", 0},
  {"$", "4", 0},
  {"%", "5", 0},
  {"^", "6", 0},
  {"&", "7", 0},
  {"*", "8", 0},
  {"(", "9", 0},
  {")", "0", 0},
  {"_", "-", 0},
  {"+", "=", 0},
  {"|", "\\", 0},
  {"Back", "Space", 0},
  {"Insert", 0},
  {"Home", 0},
  {"Page", "Up", 0},
  {"Num", "Lock", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 3 */

  {"F3", 0},
  {"F4", 0},
  {"Tab", 0},
  {"Q", 0},
  {"W", 0},
  {"E", 0},
  {"R", 0},
  {"T", 0},
  {"Y", 0},
  {"U", 0},
  {"I", 0},
  {"O", 0},
  {"P", 0},
  {"{", "[", 0 },
  {"}", "]", 0 },
  {"Enter", 0},
  {"Del", 0},
  {"End", 0},
  {"Page", "Down", 0},
  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "Pg Up", 0},
  {"+", 0},

  /* Row 4 */

  {"F5", 0},
  {"F6", 0},
  {"Caps Lock", 0},
  {"A", 0},
  {"S", 0},
  {"D", 0},
  {"F", 0},
  {"G", 0},
  {"H", 0},
  {"J", 0},
  {"K", 0},
  {"L", 0},
  {":", ";", 0},
  {"\"", "'", 0},
  {" ", "UpArrow", 0},
  {"UpArrow", 0},
  {" ", "UpArrow", 0},
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},

  /* Row 5 */

  {"F7", 0},
  {"F8", 0},
  {"Shift", 0},
  {"Z", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", 0},
  {"<", ",", 0},
  {">", ".", 0},
  {"?", "/", 0},
  {"Shift", 0},
  {"LeftArrow", 0},
  {" ", 0},
  {"RightArrow", 0},
  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "Pg Dn", 0},
  {"Enter", 0},

  /* Row 6 */

  {"F9", 0},
  {"F10", 0},
  {"Ctrl", 0},
  {"*", 0},
  {"Alt", 0},
  {" ", 0},
  {"Alt", 0},
  {"|", "\\"},
  {"Ctrl", 0},
  {"DownArrow", 0},
  {" ", "DownArrow", 0},
  {"DownArrow", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};

