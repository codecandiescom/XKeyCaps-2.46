/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Soft key "Butterfly" keyboard 
 * with German layout.  
 * By Edgar Greuter <edgar@pingu.saar.de>.
 * The actual image on the "Window"-keys is a square with two diagonals.
 * The actual image of the "Menu"-key is a square with an outlined white
 * mouse pointer pointing to the upper left corner.
 * The additional lower curser block has diagonal arrows in its 4 corners.
 */

static const struct key_strings butterflyde_caps [] = {

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
  {"F11", 0},
  {"F12", 0},

  /* Row 2 */

  {"Print", "Screen", "SysRq"},
  {"Scroll", "Lock", 0},
  {"Pause", "", "Break"},
  {"Esc", 0},

  {"\260", "^", 0},
  {"!", "1", 0},
  {"\"", "2 \262", 0},
  {"\247", "3 \263", 0},
  {"$", "4", 0},
  {"%", "5", 0},
  {"&", "6", 0},

  {"/", "7 {", 0},
  {"(", "8 [", 0},
  {")", "9 ]", 0},
  {"=", "0 }", 0},
  {"?", "\337 \\", 0},
  {"`", "'", 0},
  {"Backspace", 0},

  {"Num", "Lock", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 3 */

  {"Insert", 0},
  {"Home", 0},
  {"Page", "Up", 0},
  {"F13", 0},

  {"Tab", 0},
  {"Q", "  @", 0},
  {"W", 0},
  {"E", 0},
  {"R", 0},
  {"T", 0},

  {"Z", 0},
  {"U", 0},
  {"I", 0},
  {"O", 0},
  {"P", 0},
  {"\334", 0},
  {"*", "+ ~", 0},
  {"Enter", 0},

  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "PgUp", 0},
  {"+", 0},

  /* Row 4 */

  {"Delete", 0},
  {"End", 0},
  {"Page", "Down", 0},
  {"F14", 0},

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
  {"\326", 0},
  {"\304", 0},

  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},

  /* Row 5 */

  {"F15", 0},
  {"UpArrow", 0},
  {"F16", 0},
  {"Enter", 0},

  {"Shift", 0},
  {"Y", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},

  {"N", 0},
  {"M", "  \265", 0},
  {";", ",", 0},
  {":", ".", 0},
  {"_", "-", 0},
  {"Shift", 0},

  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "PgDn", 0},
  {"Enter", 0},

  /* Row 6 */

  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},

  {"Ctrl", 0},
  {"Alt", 0},
  {">", "< |", 0},
  {"Window", 0},

  {" ", 0},

  {"Window", 0},
  {"Menu", 0},
  {"'", "#", 0},
  {"Alt Gr", 0},
  {"Ctrl", 0},
  {"0", "Ins", 0},
  {".", "Del", 0},

  /* additional cursor block */
  {"", "UpArrow", 0},
  {"UpArrow", 0},
  {"", "UpArrow", 0},

  {"LeftArrow", 0},
  {"CSC", 0},
  {"RightArrow", 0},

  {"", "DownArrow", 0},
  {"DownArrow", 0},
  {"", "DownArrow", 0},
};
