/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Pericom X-Line keyboard.
 * It differs from the `sco110' in the codes for some of the special keys.
 * This Pericom gives a vendor ID of 'AGE Logic, Inc.', which is returned by
 * other servers (with utterly different keycodes), just to confuse things 
 * a little more...
 * This seems to be a standard PC keyboard, so I'm imitating the Linux naming,
 * but with 'xline' instead of 'linux'.
 * By Ben Harris <bjh21@cam.ac.uk>.
 */

static const KeyCode xline101_codes [] = {

  /* Row 0 */
  8,
  66, 67, 68, 69,
  70, 71, 72, 73,
  74, 75, 94, 95,
  91, 77, 0,

  /* Row 2 */
  48, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
  97, 98, 99,
  76, 103, 62, 81,

  /* Row 3 */
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 50,
  100, 101, 102,
  78, 79, 80, 85,
  
  /* Row 4 */
  65, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 35,
  82, 83, 84,

  /* Row 5 */
  49, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
  107,
  86, 87, 88, 104,

  /* Row 6 */
  36,
  63, 64, 92,
  96,
  105, 108, 106,
  89, 90
};
