/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the SONY NWS1250 keyboard.
 * By Pavel Rosendorf <prf@jprix.che.wisc.edu>
 *
 * The blank key between "?" and "Shift_R" is physically disabled (you have to
 * open up the keyboard and remove a piece of plastic to enable it) but once
 * you do that it generates keycode 72.
 *
 * The blank key between "Alt" and "Caps" is also physically disabled, and is
 * rather strange once you enable it: it generates the keycodes 79 and 80
 * alternately; that is, it will generate the sequence
 *     79 KeyPress, 79 KeyRelease, 80 KeyPress, 80 KeyRelease
 * if pressed and released twice.
 */

static const KeyCode nws1250_codes [] = {

  /* Row 0 */
  0,
  8, 9, 10, 11, 12,
  13, 14, 15, 16, 17,
  
  /* Row 2 */
  18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,

  /* Row 3 */
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 60,

  /* Row 4 */
  47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,

  /* Row 5 */
  61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,

  /* Row 6 */
  74, 79, 75, 76, 77, 78, 98, 99, 95, 100, 81
};
