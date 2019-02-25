/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the DEC LK401 keyboard, via kludgy
 * conditionalizations in lk201-codes.h (since the two keyboards differ
 * only in the last row.)
 */

#define LK401_KLUDGE
#include "lk201-codes.h"
#undef LK401_KLUDGE
