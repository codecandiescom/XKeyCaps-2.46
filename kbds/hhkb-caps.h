/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1997
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the Happy Hacking Keyboard.
 * By Christoph Berg <cb@fsinfo.cs.uni-sb.de> 990821.
 * Thanks to Carl Witty <cwitty@ai.mit.edu> (the author of sun5-caps.h).
 *
 * The keys marked with '*' in the upper right generate a different key code
 * when pressed with the 'Fn' key. Those key codes are represented by the
 * upper row and the right block in the window. (These keys do not exist on
 * the Happy Hacking Keyboard, which consists only of the standard alphanumeric
 * block.) Also marked are the keys that have other key codes in windows
 * mode (DIP switch 2 on).
 *
 * By Christoph Berg <cb@fsinfo.cs.uni-sb.de>
 */

static const struct key_strings hhkb_pc_caps [] = {

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
  {"Ins", 0},
  {"Del", 0},

  /* Row 1 */

  {"Esc", 0},
  {"!", "1", "*"},
  {"@", "2", "*"},
  {"#", "3", "*"},
  {"$", "4", "*"},
  {"%", "5", "*"},
  {"^", "6", "*"},
  {"&", "7", "*"},
  {"*", "8", "*"},
  {"(", "9", "*"},
  {")", "0", "*"},
  {"_", "-", "*"},
  {"+", "=", "*"},
  {"|", "\\", "*"},
  {"~", "`", "*"},

  /* Row 2 */

  {"Tab", 0, "*"},	/* different key code only in Windows mode */ 
  {"Q", 0},
  {"W", 0},
  {"E", 0},
  {"R", 0},
  {"T", 0},
  {"Y", 0},
  {"U", 0},
  {"I", 0, "*"},
  {"O", 0, "*"},
  {"P", 0, "*"},
  {"{", "[", "*"},
  {"}", "]", 0},
  {"Back ", "Space", 0},  /* Delete if DIP switch 1 off */
  {"Print", "Screen", 0},
  {"Scroll", "Lock", 0},
  {"Pause", "Break", 0},
  {"UpArrow", 0},
  /* {"BS", 0} include if DIP switch 1 off  */

  /* Row 3 */

  {"Control", 0},
  {"A", 0},
  {"S", 0},
  {"D", 0},
  {"F", 0},
  {"G", 0},
  {"H", 0},
  {"J", 0},
  {"K", 0, "*"},
  {"L", 0, "*"},
  {":", ";", "*"},
  {"\"", "'", "*"},
  {"Return", 0},
  {"Home", 0},
  {"Pg Up", 0},
  {"LeftArrow", 0},
  {"RightArrow", 0},

  /* Row 4 */

  {"Shift", 0},
  {"Z", 0},
  {"X", 0},
  {"C", 0},
  {"V", 0},
  {"B", 0},
  {"N", 0},
  {"M", 0},
  {"<", ",", "*"},
  {">", ".", "*"},
  {"?", "/", "*"},
  {"Shift", 0},
  {"Fn", 0},
  {"End", 0},
  {"Pg Dn", 0},
  {"DownArrow", 0},

  /* Row 5 */

  {"Alt", 0},
  {"<>", 0, "*"},
  {" ", 0},
  {"<>", 0, "*"},
  {"Alt", 0},

  /* These keys are available when DIP switch 2 is on */
  {"Caps", "Lock", 0},	/* Fn + Tab */
  {"Windows", 0},	/* replaces left Meta */
  {"Windows", 0}	/* replaces right Meta */
};
