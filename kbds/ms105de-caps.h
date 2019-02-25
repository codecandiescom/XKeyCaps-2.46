/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Microsoft "Natural" keyboard 
 * with German layout (part# 60289).  
 * By Matthias Rabe <rabe@mathematik.uni-bielefeld.de>.
 * It's pretty much the same as pc102de-caps.h, except for the additional 
 * modifier keys in the bottom row.
 */

static const struct key_strings ms105de_caps [] = {

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
  {"Druck", "", "S-Abf"},
  {"Rollen", "DownArrow", 0},
  {"Pause", "", "Untbr"},

  /* Row 2 */

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
  {"Einfg", 0},
  {"Pos1", 0},
  {"Bild", "UpArrow", 0},
  {"Num", "DownArrow", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 3 */

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
  {"Entf", 0},
  {"Ende", 0},
  {"Bild", "DownArrow", 0},
  {"7", "Pos1", 0},
  {"8", "UpArrow", 0},
  {"9", "Bild UpArrow", 0},
  {"+", 0},

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
  {"\326", 0},
  {"\304", 0},
  {"'", "#", 0},
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},

  /* Row 5 */

  {"Shift", 0},
  {">", "< |", 0},
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
  {"UpArrow", 0},
  {"1", "Ende", 0},
  {"2", "DownArrow", 0},
  {"3", "Bild DownArrow", 0},
  {"Enter", 0},

  /* Row 6 */

  {"Strg", 0},
  {"=/+/", 0},
  {"Alt", 0},
  {" ", 0},
  {"Alt Gr", 0},
  {"=/+/", 0},
  {"##", 0},
  {"Strg", 0},
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},
  {"0", "Einfg", 0},
  {",", "Entf", 0}
};
