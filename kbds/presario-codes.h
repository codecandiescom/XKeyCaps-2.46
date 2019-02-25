/* xkeycaps, Copyright (c) 1998, 1999 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Compaq Presario 1655 keyboard
 * on FreeBSD running the "Accelerated X" server from X Inside Inc.
 * By Hans Huebner <hans@huebner.org>
 *
 * Note: The "Fn" key apparently doesn't deliver events to the X server.
 */

static const KeyCode presario_codes [] = {
  /* Row 1 */
  9, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 95, 96, 92, 78, 127, 129,

  /* Row 2 */
  49, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 135,

  /* Row 3 */
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 51, 119,
  
  /* Row 4 */
  66, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 36, 134,

  /* Row 5 */
  50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 130,

  /* Row 6 */
  0, 37, 120, 64, 94, 65, 131, 122, 121, 126, 128,

  /* ROW 7 */

  118, 93, 133
};
