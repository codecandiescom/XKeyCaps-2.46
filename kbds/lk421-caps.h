/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the DEC LK421 keyboard.
 * By Tom Ivar Helbekkmo <tih@barsoom.nhh.no>
 *
 * The LK421 is really an LK401 that has been shrunk by removing the keypads,
 * and having them doubled on normal keys through the use of a new "Extend"
 * modifier that's local to the keyboard; it is not "visible" to the X clients.
 *
 * This file displays two images of the keyboard, the "normal" one on top, and
 * one containing only the "extended" keyboard at the bottom.  This is 
 * necessary because each key has two keycodes...
 *
 * The key with ">", "<", and "~" should have "`" in the lower right corner.
 *
 * The keys for brackets and braces look like they're wrong, since the "["
 * and "]" symbols aren't on them, but this is the way the keyboard is made.
 */

static const struct key_strings lk421_caps [] = {

  /* Row 0 */

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
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"UpArrow", 0},
  {"RightArrow", 0},

  /* Row 1 */

  {"~", "`", "ESC"},
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
  {"<X|", 0},

  /* Row 2 */

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
  {"{", 0},
  {"}", 0},
  {"|", "\\", 0},
  {">", "<", "~"},

  /* Row 3 */

  {"Ctrl", 0},
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
  {"Return", 0},

  /* Row 4 */

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

  /* Row 5 */

  {"Com-", "pose", 0},
  {"Alt", "Function", 0},
  {" ", 0},
  {"Alt", "Function", 0},
  {"Compose", "Character", 0},

  /* Row 6 */


  /* Row 7 */

  {"F11", 0},
  {"F12", 0},
  {"F13", 0},
  {"F14", 0},
  {"Help", 0},
  {"Do", 0},
  {"F17", 0},
  {"F18", 0},
  {"F19", 0},
  {"F20", 0},

  /* Row 8 */

  {"PF1", 0},
  {"PF2", 0},
  {"PF3", 0},
  {"PF4", 0},
  {"Find", 0},
  {"Insert", 0},
  {"Remove", 0},

  /* Row 9 */

  {"7", 0},
  {"8", 0},
  {"9", 0},
  {"-", 0},
  {"Select", 0},
  {"Prev", 0},
  {"Next", 0},

  /* Row 10 */

  {"4", 0},
  {"5", 0},
  {"6", 0},
  {",", 0},
  {"Enter", 0},

  /* Row 11 */

  {"1", 0},
  {"2", 0},
  {"3", 0},
  {".", 0},
  {"Lock", 0},

  /* Row 12 */

  {"Ext-", "end", 0},
  {"0", 0}
};
