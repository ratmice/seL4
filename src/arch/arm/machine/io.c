/*
 * Copyright 2016, Data61 CSIRO
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(D61_GPL)
 */
#include <config.h>
#include <machine/io.h>

#if defined(CONFIG_DEBUG_BUILD) || defined(CONFIG_PRINTING)
void
putConsoleChar(unsigned char c)
{
    putDebugChar(c);
}
#endif
