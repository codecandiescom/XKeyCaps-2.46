/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Kinesis Model 120 Keyboard.
 */

static const struct key_strings kinesis_caps [] = {

  /* Row 0 */

  {"Esc", 0},
  {"F1", 0},
  {"F2", 0},
  {"F3", 0},
  {"F4", 0},
  {"F5", 0},
  {"F6", 0},
  {"F7", "Data", 0},
  {"F8", "Delay", 0},

  {"F9", "Repeat", 0},
  {"F10", "Disable", 0},
  {"F11", "Macro", 0},
  {"F12", "Remap", 0},
  {"Print", "Scrn", "SysRq"},
  {"Scroll", "Lock", 0},
  {"Pause", "", "Break"},
  {"Keypad", 0},
  {"Program", 0},

  /* Row 2 */

  {"+", "=", 0},
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
  {"|", "\\", 0},

  /* Row 4 */

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

  /* Row 6 */

  {"~", "`", 0},
  {"Insert", 0},
  {"LeftArrow", 0},
  {"RightArrow", 0},

  {"UpArrow", 0},
  {"DownArrow", 0},
  {"{", "[", 0},
  {"}", "]", 0},

  /* Row 7 */

  {"Ctrl", 0},
  {"Alt", 0},
  {"Alt", 0},
  {"Ctrl", 0},

  /* Row 8 */

  {"Back", "Space", 0},
  {"Delete", 0},
  {"Home", 0},
  {"Page", "Up", 0},
  {"Enter", 0},
  {"Space", 0},

  /* Row 9 */

  {"End", 0},
  {"Page", "Down", 0}
};
