/* xkeycaps, Copyright (c) 1998, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the IBM ThinkPad 560 keyboard

 * Note: The "Fn" key apparently doesn't deliver events to the X server.
 */

static const KeyCode tp560_codes [] = {
 /* Row 0 */
  9,
  111, 78, 110, 106, 97, 99,

  /* Row 1 */
  67, 68, 69, 70,
  71, 72, 73, 74,
  75, 76, 95, 96,
  107, 103, 105,

  /* Row 2 */
  49, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,

  /* Row 3 */
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
  
  /* Row 4 */
  66, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 51,

  /* Row 5 */
  50, 94, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 

  /* Row 6 */
  0, 37, 64, 65, 113, 109, 98,

  /* ROW 7 */

  100, 104, 102
};
