/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994 
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Microsoft "Natural" keyboard
 * (part 58221) with SGI IRIX 5.2.  It is basically the same as  sgi5-codes.h,
 * except for the addition of the three extra keys in the bottom row.
 */

static const KeyCode ms104_sgi5_codes [] = {

  /* Row 0 */
  16,
  15, 23, 31, 39,
  47, 55, 63, 71,
  79, 87, 94, 102,
  95, 103, 106,

  /* Row 2 */
  22, 30, 38, 46, 45, 54, 62, 69, 70, 78, 77, 86, 93, 110,
  111, 118, 119,
  126, 127, 134, 140,

  /* Row 3 */
  21, 29, 37, 44, 53, 52, 61, 68, 75, 76, 85, 92, 99, 100,
  108, 109, 117,
  116, 125, 133, 132,
  
  /* Row 4 */
  28, 36, 35, 43, 51, 60, 59, 67, 74, 83, 84, 90, 98,
  115, 123, 124,

  /* Row 5 */
  26, 34, 42, 41, 50, 58, 57, 66, 73, 81, 82, 97,
  107,
  113, 122, 130, 129,

  /* Row 6 */
  25, 147, 33, 49, 65, 148, 149, 96,
  105, 104, 114,
  120, 121
};
