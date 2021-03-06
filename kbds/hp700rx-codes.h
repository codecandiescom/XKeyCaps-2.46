/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the HP 700/RX X terminal keyboard.
 * By Hide Horiuchi <hide@sierra.com>.
 */

static const KeyCode hp700rx_codes [] = {

  /* Row 0 */
  17,
  16, 24, 32, 40,
  48, 56, 64, 72,
  80, 88, 95, 103,
  96, 104, 107,

  /* Row 2 */
  23, 31, 39, 47, 46, 55, 63, 70, 71, 79, 78, 87, 94, 111,
  112, 119, 120,
  127, 128, 135, 141,
	/* Note: the last keycode on the preceeding line (keypad-minus)
	   used to be 129, but Corne Beerse <beerse@ats.nld.alcatel.nl>
	   says that 141 is correct, with HPUX 9.05. */

  /* Row 3 */
  22, 30, 38, 45, 54, 53, 62, 69, 76, 77, 86, 93, 100, 101,
  109, 110, 118,
  117, 126, 134, 133,
  
  /* Row 4 */
  29, 37, 36, 44, 52, 61, 60, 68, 75, 84, 85, 91, 99,
  116, 124, 125,

  /* Row 5 */
  27, 35, 43, 42, 51, 59, 58, 67, 74, 82, 83, 98,
  108,
  114, 123, 131, 130,

  /* Row 6 */
  26,
  34, 50, 66,
  97,
  106, 105, 115,
  121, 122
};
