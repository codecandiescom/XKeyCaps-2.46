/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
 * Jamie Zawinski <jwz@jwz.org>
 * modified by Lorenzo Maria Catucci <lorenzo@info.utovrm.it>
 * This file describes the key surfaces of the italian Microsoft "Natural"
 * keyboard.  It's pretty much the same as pc101-caps.h,
 * except for the additional modifier keys in the bottom row.
 */

static const struct key_strings ms105it_caps [] = {

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
  {"Stamp", "R Sist", 0},
  {"Bloc", "Scorr", 0},
  {"Pausa",  "Interr", 0},

  /* Row 2 */

  {"|", "\\", 0},
  {"!", "1", 0},
  {"\"", "2", 0},
  {"\243", "3", 0},
  {"$", "4", 0},
  {"%", "5", 0},
  {"&", "6", 0},
  {"/", "7", 0},
  {"(", "8", 0},
  {")", "9", 0},
  {"=", "0", 0},
  {"?", "'", 0},
  {"^", "\354", 0},
  {"LeftArrow", 0},
  {"Ins", 0},
  {"Inizio", 0},
  {"Pag", "UpArrow", 0},
  {"Bloc", "Num", 0},
  {"/", 0},
  {"*", 0},
  {"-", 0},

  /* Row 3 */

  {"LeftArrow","RightArrow"},
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
  {"\351", "\350", "["},
  {"*", "+", "]"},
  {"Invio", 0},
  {"Canc", 0},
  {"Fine", 0},
  {"Pag", "DownArrow", 0},
  {"7", "Inizio", 0},
  {"8", "UpArrow", 0},
  {"9", "Pag Su", 0},
  {"+", 0},

  /* Row 4 */

  {"Bloc", "Maius"},
  {"A", 0},
  {"S", 0},
  {"D", 0},
  {"F", 0},
  {"G", 0},
  {"H", 0},
  {"J", 0},
  {"K", 0},
  {"L", 0},
  {"\347", "\362", "@" },
  {"\260", "\340", "#" },
  {"\247", "\372", 0},
  {"4", "LeftArrow", 0},
  {"5", 0},
  {"6", "RightArrow", 0},

  /* Row 5 */

  {"Shift", 0},
  {">", "<", 0},
  {"Z", 0},
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
  {"1", "Fine", 0},
  {"2", "DownArrow", 0},
  {"3", "Pag Giu", 0},
  {"Invio", 0},

  /* Row 6 */

  {"Ctrl", 0},
  {"=/+/", 0},
  {"Alt", 0},
  {" ", 0},
  {"Alt Gr", 0},
  {"=/+/", 0},
  {"##", 0},
  {"Ctrl", 0},
  {"LeftArrow", 0},
  {"DownArrow", 0},
  {"RightArrow", 0},
  {"0", "Ins", 0},
  {".", "Canc", 0}
};
