/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Cherry ErgoPlus keyboard with 
 * German layout.
 * By Berthold Gunreben <gunreben@wvwx01.wifak.uni-wuerzburg.de>
 */

static const struct key_strings chergo_de_caps [] = {

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
  {"Druck", "S-Abf", 0},
  {"Rollen", 0},
  {"Pause", "Untbr", 0},

  /* Row 1 */

  {"F13", 0},
  {"\260", "^", 0},
  {"!", "1", 0},
  {"\"", "2", "\262"},
  {"\247", "3", "\263"},
  {"$", "4", 0},
  {"%", "5", 0},
  {"&", "6", 0},
  {"/", "7", "{"},
  {"(", "8", "["},
  {")", "9", "]"},
  {"=", "0", "}"},
  {"?", "\337", "\\"},
/*  {0}, */
  {"`", "'", 0},
  {"Back ", "Space", 0},
  {"Einfg", 0},
  {"Bild", "upArrow", 0},

  /* Row 2 */

  {"F14", 0},
  {"Tab", 0},
  {"Q", "", "@"},
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
  {"*", "+", "~"},
  {"Enter", 0},
  {"Entf", 0},
  {"Bild", "downArrow" , 0},

  /* Row 3 */

  {"F15", 0},
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
  {"Pos1", 0},
  {"Ende", 0},

  /* Row 4 */

  {"F16", 0},
  {"Shift", 0},
  {">", "<", "|"},
  {"Y", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", "", "\265"},
  {";", ",", 0},
  {":", ".", 0},
  {"_", "-", 0},
  {"Shift", 0},
  {"upArrow", 0},

  /* Row 5 */

  {"F17", 0},
  {"Strg", 0},
  {"Alt", 0},
  {" ", 0},
  {" ", 0},
  {"Alt", "Graph", 0},
  {"Strg", 0},
  {"leftArrow", 0},
  {"downArrow", 0},
  {"rightArrow", 0},
};
