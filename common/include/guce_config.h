/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2006.  All rights reserved.
 *
 * All source code herein is the property of Dinand Vanvelzen. You may not sell
 * or otherwise commercially exploit the source or things you created based on
 * the source.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL DINAND VANVELZEN BE LIABLE FOR ANY SPECIAL, INCIDENTAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF
 * THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 *  This header contains build switches relative to the entire GUCE platform
 */

#ifndef GUCE_CONFIG_H
#define GUCE_CONFIG_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CONFIG_H
#include "gucef_config.h"       /* include for deriving some flags from GUCEF */
#define GUCEF_CONFIG_H
#endif /* GUCEF_CONFIG_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      BUILD DEFINES                                                      //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *  In this section you can define some flags that influence the building process
 *  Note that usually it is best not to do this but to let the autodetection
 *  macros in guce_macros.h set the flags for you 
 */

/*-------------------------------------------------------------------------*/

/*
 *      Target platform selection switches
 *      By default autodetects
 */
// #define GUCE_LINUX_BUILD
// #define GUCE_MSWIN_BUILD

/*-------------------------------------------------------------------------*/

/*
 *      Switches for setting of the calling convention used
 *      Defaults to CALLSPEC_C
 */
// #define GUCE_USE_CALLSPEC_C
// #define GUCE_USE_CALLSPEC_STD
// #define GUCE_USE_CALLSPEC_PASCAL
// #define GUCE_USE_CALLSPEC_FAST

// #define GUCE_USE_PLUGIN_CALLSPEC_C
// #define GUCE_USE_PLUGIN_CALLSPEC_STD
// #define GUCE_USE_PLUGIN_CALLSPEC_PASCAL
// #define GUCE_USE_PLUGIN_CALLSPEC_FAST

/*-------------------------------------------------------------------------*/

/*
 *      Switches for manually setting the bit target
 *      Default is 32bit, may be able to autodetect
 */
// #define GUCE_32BIT
// #define GUCE_64BIT

/*-------------------------------------------------------------------------*/

/*
 *      Debug mode
 */
// #define GUCE_DEBUG_MODE
// #define GUCE_DEBUG_VERBOSE

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CONFIG_H */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 30-09-2006 :
       - Dinand: Initial version of this file.

-----------------------------------------------------------------------------*/
