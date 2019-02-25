/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the NCD X terminal N108 and VT220
 * keyboards.  These keyboards differ only in that the N108 has three 
 * additional keys in the bottom row.
 */

#ifdef VT220_KLUDGE
# define ncd108_codes ncd220_codes
#endif

static const KeyCode ncd108_codes [] = {

  /* Row 0 */
  16, 15, 23, 31, 39,
  47, 55, 63, 71, 79,
  10, 11, 12, 80,
  81, 127,
  128, 129, 130, 131,

  /* Row 2 */
  14, 22, 30, 38, 37, 46, 54, 61, 62, 70, 69, 78, 85, 102,
  110, 103, 100,
  8, 118, 95, 87,

  /* Row 3 */
  13, 21, 29, 36, 45, 44, 53, 60, 67, 68, 77, 84, 91,
  90,
  101, 111, 109,
  108, 117, 125, 132,

  /* Row 4 */
  17, 20, 28, 27, 35, 43, 52, 51, 59, 66, 75, 76, 82, 83,
  99,
  107, 115, 116, 124,

  /* Row 5 */
  18, 9, 26, 34, 33, 42, 50, 49, 58, 65, 73, 74, 89,
  97, 96, 106,
  105, 114, 122, 121,
  
  /* Row 6 */
#ifdef VT220_KLUDGE
       25, 41,
#else /* n108 */
  119, 25, 41, 57, 120,
#endif
  112, 113
};

#undef ncd108_codes
