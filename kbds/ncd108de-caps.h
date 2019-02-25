/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surface of the NCD N108D keyboard (German
 * layout).  By Andreas Schuch <schuch@physik.uni-kl.de>.
 */

#ifdef VT220_KLUDGE
# define ncd108_caps ncd22_caps
#endif

static const struct key_strings ncd108de_caps [] = {

  /* Row 0 */

  {"F1", 0},
  {"F2", 0},
  {"F3", "Compose Setup", 0},
  {"F4", 0},
  {"F5", "Break", 0},
  {"F6", 0},
  {"F7", 0},
  {"F8", 0},
  {"F9", 0},
  {"F10", 0},
  {"F11", "Esc", 0},
  {"F12", "Backspace", 0},
  {"F13", "Line Feed", 0},
  {"F14", 0},
  {"Help", 0},
  {"Do", 0},
  {"F17", 0},
  {"F18", 0},
  {"F19", 0},
  {"F20", 0},

  /* Row 2 */

  {"\260", "^", "\254"},
  {"!", "1", "\271"},
  {"\"", "2", "\262"},
  {"\247", "3", "\263"},
  {"$", "4", "\274"},
  {"%", "5", "\275"},
  {"&", "6", "\276"},
  {"/", "7", "{"},
  {"(", "8", "["},
  {")", "9", "]"},
  {"=", "0", "}"},
  {"?", "\337", "\\"},
  {0},
  {"<x|", 0},
  {"Find", 0},
  {"Insert", "Here", 0},
  {"Re-", "move", 0},
  {"PF1", 0},
  {"PF2", 0},
  {"PF3", 0},
  {"PF4", 0},

  /* Row 3 */

  {"Tab", 0},
  {"Q", "", "@"},
  {"W", 0},
  {"E", 0},
  {"R", "", "\266"},
  {"T", 0},
  {"Z", "", "\245"},
  {"U", 0},
  {"I", 0},
  {"O", "", "\370"},
  {"P", "", "\376"},
  {"\334", 0 },
  {"*", "+", "~"},
  {"Return", 0},
  {"Select", 0},
  {"Prev", "Screen", 0},
  {"Next", "Screen", 0},
  {"7", 0},
  {"8", 0},
  {"9", 0},
  {"-", 0},

  /* Row 4 */

  {"Ctrl", 0},
  {"Lock", 0},
  {"A", "", "\346"},
  {"S", "", "\337"},
  {"D", "", "\360"},
  {"F", "", "\252"},
  {"G", 0},
  {"H", 0},
  {"J", 0},
  {"K", "", "&"},
  {"L", 0},
  {"\326", "", "\264"},
  {"\304", 0},
  {"'", "#", "`"},
  {"UpArrow", 0},
  {"4", 0},
  {"5", 0},
  {"6", 0},
  {",", 0},

  /* Row 5 */

  {"Shift", 0},
#ifdef VT220_KLUDGE
  {">", "<", 0},
#else /* n108 */
  {">", "<", "|"},
#endif
  {"Y", "", "\253"},
  {"X", "", "\273"},
  {"C", "", "\242"},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", "", "\265"},
#ifdef VT220_KLUDGE
  {",", ",", 0},
  {".", ".", 0},
#else /* n108 */
  {";", ",", "\327"},
  {":", ".", "\267"},
#endif
  {"_", "-", 0},
  {"Shift", 0},
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},
  {"1", 0},
  {"2", 0},
  {"3", 0},
  {"Enter", 0},

  /* Row 6 */

  {"Compose", "Character", 0},
#ifndef VT220_KLUDGE
  {"Alt", 0},
#endif
  {" ", 0},
#ifndef VT220_KLUDGE
  {"Alt", 0},
  {"Compose", "Character", 0},
#endif
  {"0", 0},
  {",", 0}
};

#undef ncd108_caps
