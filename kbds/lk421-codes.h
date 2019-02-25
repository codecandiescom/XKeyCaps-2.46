/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the DEC LK421 keyboard.
 * By Tom Ivar Helbekkmo <tih@barsoom.nhh.no>
 *
 * The LK421 is really an LK401 that has been shrunk by removing the keypads,
 * and having them doubled on normal keys through the use of a new "Extend"
 * modifier that's local to the keyboard; it is not "visible" to the X clients.
 *
 * This file displays two images of the keyboard, the "normal" one on top,
 * and one containing only the "extended" keyboard at the bottom.  This is
 * necessary because each key has two keycodes...
 */

static const KeyCode lk421_codes [] = {

  /* Row 0 */
  86, 87, 88, 89, 90,
  100, 101, 102, 103, 104,
  167, 169, 170, 168,
  
  /* Row 1 */
  191, 192, 197, 203, 208, 214, 219, 224, 229, 234, 239, 249, 245, 188,

  /* Row 2 */
  190, 193, 198, 204, 209, 215, 220, 225, 230, 235, 240, 250, 246, 247, 201,

  /* Row 3 */
  175, 194, 199, 205, 210, 216, 221, 226, 231, 236, 242, 251, 189,

  /* Row 4 */
  174, 195, 200, 206, 211, 217, 222, 227, 232, 237, 243, 171,

  /* Row 5 */
  177, 172, 212, 178, 173,

  /* Second version: */

  /* Row 7 */
  113, 114, 115, 116, 124,
  125, 128, 129, 130, 131,

  /* Row 8 */
  161, 162, 163, 164, 138, 139, 140,
  
  /* Row 9 */
  157, 158, 159, 160, 141, 142, 143,

  /* Row 10 */
  153, 154, 155, 156,
  149,

  /* Row 11 */
  150, 151, 152, 148,
  176,

  /* Row 12 */
  0, 146
};
