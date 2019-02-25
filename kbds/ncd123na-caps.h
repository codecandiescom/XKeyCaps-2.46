/* xkeycaps, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the NCD-123NA keyboard.
 * By Vladimir Alexiev <vladimir@cs.ualberta.ca>.
 * Based on the NCD123-UX keyboard by John Palmieri <palmieri@math.mit.edu>.
 *
 * NOTE: "NA" might mean "North American" (who knows...)
 * In that case it might be appropriate to rename ncd123-* to ncd123ux-*, 
 * and call this set of files simply ncd123-*.
 */

static const struct key_strings ncd123na_caps [] = {

  /* Row 0 */

  {"Help", 0},
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
  {"Print", "Screen", "Sys Rq"},
  {"Scroll", "Lock", 0},
  {"Pause", "Break", 0},
  {"Mute", 0},
  {"Vol Dn", 0},
  {"Vol Up", 0},
  {"Setup", 0},

  /* Row 1 */

  {"Stop", 0},
  {"Again", 0},
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
  {"Back ", "Space", 0},
  {"Insert", 0},
  {"Home", 0},
  {"Page", "Up", 0},
  {"Num", "Lock", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 2 */

  {"Props", 0},
  {"Undo", 0},
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
  {"Del", 0},
  {"End", 0},
  {"Page", "Down", 0},
  {"7", "Home", 0},
  {"8", "upArrow", 0},
  {"9", "PgUp", 0},
  {"+", 0},

  /* Row 3 */

  {"Front", 0},
  {"Copy", 0},
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
  {"Enter", 0},
  {0},
  {0},
  {0}, 
  {"4", "leftArrow", 0},
  {"5", 0},
  {"6", "rightArrow", 0},

  /* Row 4 */

  {"Open", 0},
  {"Paste", 0},
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
  {0},
  {"upArrow", 0},
  {0},
  {"1", "End", 0},
  {"2", "downArrow", 0},
  {"3", "PgDn", 0},
  {"Enter", 0},

  /* Row 5 */

  {"Find", 0},
  {"Cut", 0},
  {"Control", 0},
  {"Alt", 0},
  {"<>", 0},
  {" ", 0},
  {"<>", 0},
  {"Com-", "pose", 0},
  {"Alt", "Graph", 0},
  {"leftArrow", 0},
  {"downArrow", 0},
  {"rightArrow", 0},
  {"0", "Ins", 0},
  {".", "Del", 0}
};
