/* xkeycaps, Copyright (c) 1991-1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key labeling of a german amiga keyboard (non-A1000).
 * By Peter Remmers <pitti@tfh-brlin.de>
 */

static const struct key_strings amiga_de_caps [] = {

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

  /* Row 2 */

  {"~", "`", 0},
  {"!", "1", 0},
  {"\"", "2", 0},
  {"\247", "3", 0},
  {"$", "4", 0},
  {"%", "5", 0},
  {"&", "6", 0},
  {"/", "7", 0},
  {"(", "8", 0},
  {")", "9", 0},
  {"=", "0", 0},
  {"?", "\337", 0},
  {"`", "'", 0},
  {"\\", "|", 0},
  {"<-", 0},
  {"Del", 0},
  {"Help", 0},
  {"{", "[", 0},
  {"}", "]", 0},
  {"/", 0},
  {"*", 0},

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
  {"\334", 0 },
  {"*", "+", 0 },
  {"Return", 0},
  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "Pg Up", 0},
  {"-", 0},

  /* Row 4 */

  {"Ctrl", 0},
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
  {"\326", 0},
  {"\304", 0},
  {"^", "#", 0},
  {"UpArrow", 0},
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},
  {"+", 0},
  
  /* Row 5 */

  {"Shift", 0},
  {">", "<", 0},
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
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},
  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "Pg Dn", 0},
  {"Enter", 0},

  /* Row 6 */

  {"Alt", 0},
  {"Amiga", 0},
  {" ", 0},
  {"Amiga", 0},
  {"Alt", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};
