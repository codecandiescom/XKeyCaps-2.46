/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the HCL eXceed PC X-server keyboard.
 * By Grant McDorman <ohcscc!grendel!grant@uunet.ca>
 *
 * MAJOR PROBLEM: The server has DIFFERENT keycodes for the keypad, depending
 * on whether it's in NumLock state or not.  (Strange but true.)  This file
 * does not deal with that.
 */

static const KeyCode hclpc_codes [] = {

  /* Row 0 */
  8,
  66, 67, 68, 69,
  70, 71, 72, 73,
  74, 75, 94, 95,
  108, 77, 109,

  /* Row 2 */
  48, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
  97, 100, 104,
  0, 107, 62, 81,

  /* Row 3 */
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 50,
  98, 101, 105,
  110, 113, 117, 85,
  
  /* Row 4 */
  65, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 35,
  111, 114, 118,

  /* Row 5 */
  49, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
  102,
  112, 115, 119, 96,

  /* Row 6 */
  36,
  63, 64, 91,
  92,
  99, 103, 106,
  116, 120,

  /* Row 8 */
  78, 79, 80, 85,
  
  /* Row 9 */
  82, 83, 84,

  /* Row 10 */
  86, 87, 88, 96,

  /* Row 11 */
  89, 90
};
