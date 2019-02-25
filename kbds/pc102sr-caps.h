/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1999
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of a swiss french (qwertz) 102 keys 
 * PC-style keyboard.
 * By Martin Ouwehand <Martin.Ouwehand@epfl.ch>
 */

static const struct key_strings pc102sr_caps [] = {

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
  {"PrtSc", "", "SysRq"},
  {"Scroll", "Lock", 0},
  {"Pause", "", "Break"},

  /* Row 2 */

  {"\260", "\247", 0},
  {"+", "1", "\246"},
  {"\"", "2", "@"},
  {"*", "3", "#"},
  {"\347", "4", 0},
  {"%", "5", 0},
  {"&", "6", "\254"},
  {"/", "7", "|"},
  {"(", "8", "\242"},
  {")", "9", 0},
  {"=", "0", 0},
  {"?", "'", "\264"},
  {"`", "^", "~"},
  {"BackSpace", 0},
  {"Insert", 0},
  {"Home", 0},
  {"PgUp", 0},
  {"Num", "Lock", 0},
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
  {"Z", 0},
  {"U", 0},
  {"I", 0},
  {"O", 0},
  {"P", 0},
  {"\374", "\350", "[" },
  {"!", "\250", "]" },
  {"Enter", 0},
  {"Delete", 0},
  {"End", 0},
  {"PgDn", 0},
  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "Pg Up", 0},
  {"+", 0},

  /* Row 4 */

  {"Caps", "Lock", 0},
  {"A", 0},
  {"S", 0},
  {"D", 0},
  {"F", 0},
  {"G", 0},
  {"H", 0},
  {"J", 0},
  {"K", 0},
  {"L", 0},
  {"\366", "\351", 0},
  {"\344", "\340", "{"},
  {"\243", "$", "}"},
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},

  /* Row 5 */

  {"Shift", 0},
  {">", "<", "\\"},
  {"Y", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", 0},
  {";", ",", 0},
  {":", ".", 0},
  {"_", "-", 0},
  {"Shift", 0},
  {"UpArrow", 0},
  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "Pg Dn", 0},
  {"Enter", 0},

  /* Row 6 */

  {"Ctrl", 0},
  {"Alt", 0},
  {" ", 0},
  {"Alt Gr", 0},
  {"Ctrl", 0},
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};