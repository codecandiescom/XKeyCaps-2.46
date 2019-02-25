/* xkeycaps, Copyright (c) 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the 
 *   Toshiba Libretto 100CT/2.1  (model no. PA1254EA)
 *   Debian GNU/Linux 2.1 (kernel 2.2.9/glibc-2.0.7)
 *   XFree86 3.3.2 (Debian package v3.3.2.3a-11)
 *   NeoMagic Xserver (Debian package v1.1.0-1-1)
 *
 * david arnold <d@pobox.com> september 1999
 */

static const struct key_strings libretto100_caps [] = {

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
  {"PrtSc", 0},
  {"Pause", 0},
  {"Wind", 0},
  {"Menu", 0},

  /* Row 1 */

  {"!", "1", 0},
  {"@", "2", 0},
  {"#", "3", 0},
  {"$", "4", 0},
  {"%", "5", 0},
  {"^", "6", 0},
  {"&", "7", "Home"},
  {"*", "8", "UpArrow"},
  {"(", "9", "PgUp"},
  {")", "0", "*"},
  {"_", "-", 0},
  {"+", "=", 0},
  {"Backspace", 0},


  /* Row 2 */

  {"Tab", 0},
  {"Q", 0},
  {"W", 0},
  {"E", 0},
  {"R", 0},
  {"T", 0},
  {"Y", 0},
  {"U", "", "LeftArrow"},
  {"I", 0},
  {"O", "", "RightArrow"},
  {"P", "", "-"},
  {"{", "[", 0},
  {"}", "]", 0},
  {"|", "\\", 0},

  /* Row 3 */

  {"Caps", "Lock", 0},
  {"A", 0},
  {"S", 0},
  {"D", 0},
  {"F", 0},
  {"G", 0},
  {"H", 0},
  {"J", "", "End"},
  {"K", "", "DownArrow"},
  {"L", "", "PgDn"},
  {":", ";", "+"},
  {"\"", "'", 0},
  {"Enter", 0},

  /* Row 4 */

  {"Shift", 0},
  {"Z", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", "", "Ins"},
  {"<", ",", 0},
  {">", ".", "Del"},
  {"?", "/", "/"},
  {"", "UpArrow", "PgUp"},
  {"Shift", 0},

  /* Row 5 */

  {"Ctrl", 0},
  {"Alt", 0},
  {"~", "`", 0},
  {" ", 0},
  {"Ins", 0},
  {"Del", 0},
  {"Fn", 0},
  {"", "LeftArrow", "Home"},
  {"", "DownArrow", "PgDn"},
  {"", "RightArrow", "End"}
};
