/* xkeycaps, Copyright (c) 1991, 1992, 1993 Jamie Zawinski <jwz@jwz.org>
 *
 * This file describes the keycodes of the NCD VT220 keyboard, via kludgy
 * conditionalizations in ncd108-codes.h (since the two keyboards differ
 * only in the last row.)
 */

#define VT220_KLUDGE
#include "ncd108-codes.h"
#undef VT220_KLUDGE
