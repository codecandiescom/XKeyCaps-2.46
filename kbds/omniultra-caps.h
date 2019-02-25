/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of a Northgate OmniKey Ultra
 * keyboard (part number: 560,0020, vendor code: 777, rev 6.04, 18 June 91).
 * By John A. Martin <jam@acm.org>
 */

static const struct key_strings omniultra_caps [] = {

  /* Row 0 */

  {"F11", 0},
  {"F12", 0},
  {"SF1", 0},
  {"SF2", 0},
  {"SF3", 0},
  {"SF4", 0},
  {"SF5", 0},
  {"SF6", 0},
  {"SF7", 0},
  {"SF8", 0},
  {"SF9", 0},
  {"SF10", 0},
  {"SF11", 0},
  {"SF12", 0},
  {"cPL", 0}, /* comma, Period, Lock */
  {"Rate", "Select", 0},
  {"SF", "Select", 0},

  /* Row 2 */

  {"F1", 0},
  {"F2", 0},
  {"Esc", 0},
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
  {"Print", "Screen", 0},
  {"Scroll", "Lock", 0},
  {"Pause", 0},
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
  {"Home", 0},
  {"UpArrow", 0},
  {"Page", "Up", 0},
  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "Pg Up", 0},
  {"+", 0},

  /* Row 4 */

  {"F5", 0},
  {"F6", 0},
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
  {"LeftArrow", 0},
  {"OMNI", 0},
  {"RightArrow",0},
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},
  {"=", 0},

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
  {"|", "\\", 0},
  {"End", 0},
  {"DownArrow", 0},
  {"Page", "Down", 0},
  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "Pg Dn", 0},
  {"Enter", 0},

  /* Row 6 */

  {"F9", 0},
  {"F10",0},
  {"Alt", 0},
  {"~", "`", 0},
  {"Caps", "Lock", 0},
  {" ", 0},
  {"Ctrl", 0},
  {"*", 0},
  {"Alt", 0},
  {"Insert", 0},
  {"Delete", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};
