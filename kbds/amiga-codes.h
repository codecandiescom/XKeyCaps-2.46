/* xkeycaps, Copyright (c) 1991-1998 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of an Amiga (Non-A1000,German) keyboard
 * on Linux with Xfree68.  By Peter Remmers <pitti@tfh-berlin.de>
 */

static const KeyCode amiga_codes [] = {
  /* Row 0 */
  77,  /*  ESC  */
  88, 89, 90, 91, 92, /* F1 - F5  */
  93, 94, 95, 96, 97, /* F6 - F10 */

  /* Row 2
  `  1   2   3   4   5   6   7   8   9   0   ß   '   \  <- */
  8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 73,
  78, 103, /* Del  Help */
  98, 99, 100, 101, /*  [  ]  /  *  */

  /* Row 3
  Tab  Q   W   E   R   T   Y   U   I   O   P   Ü   + */
  74, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
  76, 69, 70, 71, 82,  /* Return KP7 KP8 KP9 KP- */
  
  /* Row 4 
  Ctl Caps   A   S   D   F   G   H   J   K   L   Ö   Ä   # */
  107, 106, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
  84, 53, 54, 55, 102,  /* Up KP4 KP5 KP6 KP+  */

  /* Row 5 
  LSHF LT   Y   X   C   V   B   N   M   ,   .   -  RSHF */
  104, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 105,
  87, 85, 86, 37, 38, 39, 75,  /* Left Down Right KP1 KP2 KP3 KPENT */

  /* Row 6
  LALT LAMI SPC RAMI RALT KP0 KP. */
  108, 110, 72, 111, 109, 23, 68 
};
