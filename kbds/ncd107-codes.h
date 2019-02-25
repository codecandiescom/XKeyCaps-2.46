/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the NCD 107 keyboard
 * By Ronan Waide <waider@cork.cig.mot.com>
 */

static const KeyCode ncd107_codes [] = {

  /* Row 0 */
  130, 8,
  135, 15, 23, 31, 39, 47, 55, 63, 71, 79, 86, 94, 81, 92,
  87, 95, 93, 118,
  
  /* Row 1 */
  131, 40,
  14, 22, 30, 38, 37, 46, 54, 61, 62, 70, 69, 78, 85, 123,
  103, 119, 126, 132,
  
  /* Row 2 */
  129, 72,
  13, 21, 29, 36, 45, 44, 53, 60, 67, 68, 77, 84, 91, 90,
  108, 117, 125, 124,

  /* Row 3 */
  133, 104,  
  20, 28, 27, 35, 43, 52, 51, 59, 66, 75, 76, 82, 102, /* end of RET key */
  107, 115, 116, /* end of KP_Add */
  
  /* Row 4 */
  134, 9,
  18, 26, 34, 33, 42, 50, 49, 58, 65, 73, 74, 19, 89,
  105, 114, 122, 121,
  
  /* Row 5 */
  16, /* other half of HELP */
  17, 88, 25, 41, 57, 32, 48,
  112, 113
};
