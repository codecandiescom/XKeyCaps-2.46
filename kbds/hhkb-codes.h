/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Happy Hacking Keyboard (PC mode).
 * By Christoph Berg <cb@fsinfo.cs.uni-sb.de> 990821.
 */

static const KeyCode hhkb_pc_codes [] = {
  /* Row 0 - function keys */
  67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 95, 96, 106, 107,

  /* Row 1 */
  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 51, 49,

  /* Row 2 */
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 22, /* 107 for Delete */
  111, 78, 110, 98,
  /* 22, BS */
  
  /* Row 3 */
  37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 36,
  97, 99, 100, 102,

  /* Row 4 */
  50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 0, /* Fn */
  103, 105, 104,

  /* Row 5 */
  64, 131, 65, 129, 113,
  66, 115, 116	/* caps lock, windows */
};
