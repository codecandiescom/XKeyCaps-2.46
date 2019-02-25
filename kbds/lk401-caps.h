/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the key surfaces of the DEC LK401 keyboard,
 * via kludgy conditionalizations in lk201-caps.h (since the two 
 * keyboards differ only in the last two rows.)
 */

#define LK401_KLUDGE
#include "lk201-caps.h"
#undef LK401_KLUDGE
