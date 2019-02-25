/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Apple Standard ADB keyboard
 * for X11R6 server on NetBSD/mac68k.  By Ken Nakata <kenn@remus.rutgers.edu>.
 */

static const struct key_strings macstd_caps [] = {

  /* Row 0 */

  {"Esc", 0},
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
  {"delete", 0},

  {"clear", 0},
  {"=", 0},
  {"/", 0},
  {"*", 0},

  /* Row 1 */

  {"tab", 0},
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

  {"7", 0},
  {"8", 0},
  {"9", 0},
  {"+", 0},

  /* Row 2 */

  {"control", 0},
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
  {"return", 0},

  {"4", 0},
  {"5", 0},
  {"6", 0},
  {"-", 0},

  /* Row 3 */

  {"shift", 0},
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
  {"shift", 0},

  {"1", 0},
  {"2", 0},
  {"3", 0},
  {"enter", 0},

  /* Row 4 */

  {"caps", "lock", 0},
  {"option", 0},
  {"command", 0},
  {"~", "`", 0},
  {" ", 0},
  {"|", "\\", 0},
  {"LeftArrow", 0},
  {"RightArrow", 0},
  {"DownArrow", 0},
  {"UpArrow", 0},

  {"0", 0},
  {".", 0}
};
