/* xkeycaps, Copyright (c) 1994 Jamie Zawinski <jwz@jwz.org>
 *
 * AGE and IBM have conspired to confuse us all.
 *
 * AGE XoftWare 2.0 is a PC software product, and therefore works with a
 * variety of PC keyboards.  It comes with the vendor id "AGE Logic, Inc."
 *
 * The IBM Xstation 130 X terminal is an IBM hardware product, which comes
 * with "X Station Manager Software 1.4" which is in fact made by AGE.  It
 * has the vendor id "AGE Logic, Inc. Release 090493".  It has a different
 * default keymap than the PC software, though it comes with a PC101 keyboard.
 * This is apparently so that the IBM product ends up with the same default
 * keymap (and keycaps) as the IBM RS6K keyboards.
 *
 * This file describes the default R5 keycodes of the AGE PC software product.
 * By Dan R. Greening <greening@sti.com>.
 */

static const KeyCode xoft2_codes [] = {

  /* Row 0 */
  35,
  120, 121, 122, 123,
  124, 125, 126, 127,
  128, 129, 130, 131,
  0, 153, 27,

  /* Row 2 */
  200, 57, 58, 59, 60, 61, 62, 63, 64, 65, 56, 197, 195, 16,
  53, 44, 41, 
  152, 119, 114, 117,

  /* Row 3 */
  17, 89, 95, 77, 90, 92, 97, 93, 81, 87, 88, 227, 229, 228, 
  54, 43, 42,
  111, 112, 113, 115,
  
  /* Row 4 */
  28, 73, 91, 76, 78, 79, 80, 82, 83, 84, 194, 230, 21,
  108, 109, 110,

  /* Row 5 */
  24, 98, 96, 75, 94, 74, 86, 85, 196, 198, 199, 13, 
  46,
  105, 106, 107, 21,

  /* Row 6 */
  25,
  18, 40, 15,
  14,
  45, 48, 47,
  104, 118
};
