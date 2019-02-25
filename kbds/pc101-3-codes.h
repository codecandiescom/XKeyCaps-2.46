/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of a "Maxi-Switch 2192004" 101 key
 * PC-style keyboard under Linux with XFree86 2.0.
 * This differs from the keyboard we know as `pc101' in the placement
 * of the "\ and |" key.
 *
 * Note that the keypad keycodes are only generated when NumLock is on.
 * They generate different keycodes (the arrow keys, etc) otherwise.
 *
 * By Jamie Zawinski <jwz@jwz.org>
 */

static const KeyCode pc101_3_codes [] = {

  /* Row 0 */
  9, 
  67, 68, 69, 70,
  71, 72, 73, 74,
  75, 76, 95, 96,
  111, 78, 110,

  /* Row 2 */
  
  49, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  106, 97, 99,
  77, 112, 63, 82,

  /* Row 3 */
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
  107, 103, 105,
  79, 80, 81, 86,
  
  /* Row 4 */
  66, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
  83, 84, 85,

  /* Row 5 */
  50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 51,
  98,
  87, 88, 89, 108,

  /* Row 6 */
  37,
  64, 65, 113,
  109,
  100, 104, 102,
  90, 91
};
