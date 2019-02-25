/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the DEC LK201 and LK401 keyboards.
 * By Tom Ivar Helbekkmo <tih@barsoom.nhh.no> and jwz.
 */

#ifdef LK401_KLUDGE
# define lk201_codes lk401_codes
#endif

static const KeyCode lk201_codes [] = {

  /* Row 0 */
  86, 87, 88, 89, 90,
  100, 101, 102, 103, 104,
  113, 114, 115, 116,
  124, 125,
  128, 129, 130, 131,

  /* Row 2 */
  191, 192, 197, 203, 208, 214, 219, 224, 229, 234, 239, 249, 245, 188,
  138, 139, 140,
  161, 162, 163, 164,

  /* Row 3 */
  190, 193, 198, 204, 209, 215, 220, 225, 230, 235, 240, 250, 246,
  189,
  141, 142, 143,
  157, 158, 159, 160,

  /* Row 4 */
  175, 176, 194, 199, 205, 210, 216, 221, 226, 231, 236, 242, 251, 247,
  170,
  153, 154, 155, 156,

  /* Row 5 */
  174, 201, 195, 200, 206, 211, 217, 222, 227, 232, 237, 243, 171,
  167, 169, 168,
  150, 151, 152, 149,
  
  /* Row 6 */
#ifdef LK401_KLUDGE
  177, 172, 212, 178, 173,
#else /* LK201 */
  177, 212,
#endif
  146, 148
};

#undef lk201_codes
