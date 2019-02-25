/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Sun type 5 keyboard,
 * with both OpenWindows and X Consortium R4 and R5 servers.
 * (Note: the X Consortium R6 server has different keycodes!)
 * By Carl Witty <cwitty@ai.mit.edu>.
 *
 * Even though the Type5 and Type5/PC keyboards are physically very
 * similar, their keycodes differ more.
 */

static const KeyCode sun5_codes [] = {

  /* Row 0 */
  125, 22,
  12, 13, 15, 17,
  19, 21, 23, 24,
  25, 14, 16, 18,
  29, 30, 28,
  52, 9, 11, 55,

  /* Row 1 */
  8, 10,
  36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 95, 49,
  51, 59, 103,
  105, 53, 54, 78,

  /* Row 2 */
  32, 33,
  60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 50,
  73, 81, 130,
  75, 76, 77, 132,

  /* Row 3 */
  56, 58,
  83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 96,
  98, 99, 100,

  /* Row 4 */
  79, 80,
  106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117,
  27,
  119, 120, 121, 97,

  /* Row 5 */
  102, 104,
  126, 26, 127, 128, 129, 74, 20,
  31, 34, 35,
  101, 57
};
