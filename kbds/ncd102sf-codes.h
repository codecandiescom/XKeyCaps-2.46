/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the NCD N102 Swedish/Finnish
 * keyboard.  By Pekka Nikander <pnr@innopoli.ajk.tele.fi>
 */

static const KeyCode ncd102sf_codes [] = {

  /* Row 0 */
  8,
  16, 15, 23, 31,
  39, 47, 55, 63,
  71, 79, 86, 94,
  87, 95, 98,

  /* Row 2 */
  14, 22, 30, 38, 37, 46, 54, 61, 62, 70, 69, 78, 85, 102,
  103, 110, 111,
  118, 119, 126, 123,

  /* Row 3 */
  13, 21, 29, 36, 45, 44, 53, 60, 67, 68, 77, 84, 91,
  90,
  100, 101, 109,
  108, 117, 125, 124,

  /* Row 4 */
  20, 28, 27, 35, 43, 52, 51, 59, 66, 75, 76, 82, 83,
  107, 115, 116,

  /* Row 5 */
  18, 19, 26, 34, 33, 42, 50, 49, 58, 65, 73, 74, 89,
  99,
  105, 114, 122, 121,

  /* Row 6 */
  17,
  25, 41, 0,	/* "Alt Gr" key generates no keycode (should be 57?) */
  88,
  97, 96, 106,
  112, 113
};
