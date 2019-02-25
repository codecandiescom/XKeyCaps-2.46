/* xkeycaps, Copyright (c) 1994 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the SONY NWS3410 keyboard.
 * Keyboard model NWP-411A
 * By Dirk Jablonowski <jablonowski@zrz.TU-Berlin.DE>
 *
 * The blank key between "?" and "Shift_R" is physically disabled (you have to
 * open up the keyboard and remove a piece of plastic to enable it) but once
 * you do that it generates keycode 72.
 *
 * The blank keys between "Xfer" and "Enter" are also physically disabled,
 * and is rather strange once you enable it:
 * it generates the keycodes 79 and 80 alternately; that is,
 * it will generate the sequence 79 KeyPress, 79 KeyRelease,
 * 80 KeyPress, 80 KeyRelease if pressed and released twice.
 */

static const KeyCode nws3410_codes [] = {

  /* Row 0 */
  8, 9, 10, 11, 12,
  13, 14, 15, 16, 17,
  
  /* Row 2 */
  18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
  82, 83, 84, 85,

  /* Row 3 */
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 60,
  86, 87, 88, 89,

  /* Row 4 */
  47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
  90, 91, 92, 93,

  /* Row 5 */
  61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
  94, 95, 96, 97,

  /* Row 6 */
  74, 75, 76, 77, 78, 79, 80, 81, 98, 99, 100
};
