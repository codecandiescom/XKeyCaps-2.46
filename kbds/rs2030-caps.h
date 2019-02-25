/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the MIPS RS-2030 keyboard.
 * By Cliff Marcellus (cliff@phys.ucalgary.ca)
 * This is just like pc101-caps.h except Control and Caps-Lock are swapped.
 */

static const struct key_strings rs2030_caps [] = {

  /* Row 0 */

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
  {"Print ", "Scrn", 0},
  {"Scroll", "Lock", 0},
  {"Pause", 0},

  /* Row 2 */

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
  {"Backspace", 0},
  {"Insert", 0},
  {"Home", 0},
  {"Page", "Up", 0},
  {"Num ", "Lock", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 3 */

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
  {"{", "[", 0},
  {"}", "]", 0},
  {"|", "\\", 0},
  {"Delete", 0},
  {"End", 0},
  {"Page", "Down", 0},
  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "PgUp", 0},
  {"+", 0},

  /* Row 4 */

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
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},

  /* Row 5 */

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
  {"UpArrow", 0},
  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "PgDn", 0},
  {"Enter", 0},

  /* Row 6 */

  {"Caps", "Lock", 0},
  {"Alt", 0},
  {" ", 0},
  {"Alt", 0},
  {"Ctrl", 0},
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};
