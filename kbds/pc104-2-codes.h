/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1997
 *  Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of a generic 104 key PC keyboard
 * on NetBSD with Xfree86 3.x.  This is based on file "linux102-codes.h",
 * as modified by Steven Winikoff, 1997/04/23.
 */

static const KeyCode pc104_2_codes [] = {
  /* Row 0 */
  9,
  67, 68, 69, 70,
  71, 72, 73, 74,
  75, 76, 95, 96,
  92, 78, 127,

  /* Row 2 */
  49, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  131, 135, 119,
  77, 125, 63, 82,

  /* Row 3 */
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 51,
  129, 130, 134,
  79, 80, 81, 86,
  
  /* Row 4 */
  66, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 36,
  83, 84, 85,

  /* Row 5 */
  50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 
  128,
  87, 88, 89, 124,

  /* Row 6 */
  37, 120,
  64, 65, 122, 121, 126,
  123,
  118, 93, 133,
  90, 91 
};
