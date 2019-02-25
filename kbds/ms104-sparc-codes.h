/* xkeycaps, Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996
 * Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the Microsoft "Natural" keyboard
 * (part 58221) with Solaris 2.5/OpenWindows 3.5 running on a SparcStation
 * via the Sun Interface Converter (part # 370-2068-01).
 *
 * Contributed by Barry Warsaw <bwarsaw@python.org>
 *
 * Unfortunately, the new modifier keys in the bottom row (the "Microsoft"
 * and "Menu" keys) do not generate keycodes on a SparcStation, and thus
 * cannot be bound.  They do however generate keycodes on an x86 system.
 */

static const KeyCode ms104_sparc_codes [] = {

  /* Row 0 */
  36, 
  12, 13, 15, 17, 19,
  21, 23, 24, 25, 14, 16, 18,
  29, 30, 28,

  /* Row 2 */
  
  49, 37, 38, 39, 40, 41, 42,
  43, 44, 45, 46, 47, 48, 50,
  51, 59, 103,
  105, 53, 54, 78,

  /* Row 3 */
  60, 61, 62, 63, 64, 65,
  66, 67, 68, 69, 70, 71, 72, 95,
  73, 81, 130,
  75, 76, 77, 132,
  
  /* Row 4 */
  126, 84, 85, 86, 87, 88,
  89, 90, 91, 92, 93, 94, 96,
  98, 99, 100,

  /* Row 5 */
  106, 107, 108, 109, 110, 111,
  112, 113, 114, 115, 116, 117,
  27,
  119, 120, 121, 97,

  /* Row 6 */
  83, 0, 26, 128, 20, 0, 0, 129,
  31, 34, 35,
  101, 57,
};
