/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Gateway 2000 keyboard for
 * Windows 95.
 *
 * Like the Microsoft "Natural" Keyboard, this keyboard also unfortunately
 * does not generate keycodes for the new modifier keys in the bottom row
 * (the "Microsoft" and "Menu" keys), and thus cannot be bound.
 */

static const KeyCode gw2kn_codes [] = {

  /* Row 0 */
  117, 
  119, 120, 121, 122,
  123, 124, 125, 126,
  127, 128, 129, 130,
  131, 132, 133,

  /* Row 2 */
  
  8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22,
  82, 87, 92,
  97, 102, 107, 112,

  /* Row 3 */
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
  83, 88, 93,
  98, 103, 108, 113,
  
  /* Row 4 */
  37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 50,
  99, 104, 109,

  /* Row 5 */
  51, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 64,
  90,
  100, 105, 110, 115,

  /* Row 6 */
  65, 0, 67, 68, 69, 0, 0, 71,
  86, 91, 96,
  106, 111
};
