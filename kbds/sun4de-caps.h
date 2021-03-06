/* xkeycaps, Copyright (c) 1994, 1995, 1996 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Sun type 4 German keyboard
 * By Johannes Schmidt-Fischer <jsf@ifconnection.de>
 */

static const struct key_strings sun4de_caps [] = {

  /* Row 0 */

  {"Stop", "L1", 0},
  {"Again", "L2", 0},
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
  {"{", "[", "\253"},
  {"}", "]", "\273"},
  {"Del", 0},
  {"Pause", "R1", 0},
  {"PrSc", "R2", 0},
  {"Scroll", "Lock", 0},
  {"Num", "Lock", 0},

  /* Row 1 */

  {"Props", "L3", 0},
  {"Undo", "L4", 0},
  {"Esc", 0},
  {"!", "1", 0},
  {"\"", "2", "\262"},
  {"\247", "3", "\263"},
  {"$", "4", 0},
  {"%", "5", 0},
  {"&", "6", 0},
  {"/", "7", "\260"},
  {"(", "8", "`"},
  {")", "9", "'"},
  {"=", "0", "|"},
  {"?", "\337", "\\"},
  {"`", "'", 0},
  {"Backspace", 0},
  {"=", "R4", 0},
  {"/", "R5", 0},
  {"*", "R6", 0},
  {"-", 0},

  /* Row 2 */

  {"Front", "L5", 0},
  {"Copy", "L6", 0},
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
  {"\334", 0},
  {"*", "+", "~"},
  {"Return", 0},
  {"7", "Home", 0},
  {"8", "UpArrow", 0},
  {"9", "PgUp", 0},
  {"+", 0},

  /* Row 3 */

  {"Open", "L7", 0},
  {"Paste", "L8", 0},
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
  {"^", "#", "@"},
  {"4", "LeftArrow", 0},
  {"5", "R11", 0},
  {"6", "RightArrow", 0},

  /* Row 4 */

  {"Find", "L9", 0},
  {"Cut", "L10", 0},
  {"Shift", 0},
  {">", "<", 0},
  {"Y", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", "\265", 0},
  {";", ",", 0},
  {":", ".", 0},
  {"_", "-", 0},
  {"Shift", 0},
  {"Line ", "Feed", 0},
  {"1", "End", 0},
  {"2", "DownArrow", 0},
  {"3", "PgDn", 0},
  {"Enter", 0},

  /* Row 5 */

  {"Help", 0},
  {"Ctrl", 0},
  {"Alt", "Graph", 0},
  {"<>", 0},
  {" ", 0},
  {"<>", 0},
  {"Com ", "pose", 0},
  {"Alt", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};
