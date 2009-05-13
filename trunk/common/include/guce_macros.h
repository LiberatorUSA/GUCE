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

#ifndef GUCE_MACROS_H
#define GUCE_MACROS_H

/*
 *      Build configuration specific macros for the GUCE engine
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_MACROS_H
#include "gucef_macros.h"      /* GUCEF platform macros, used to derive GUCE settings from */
#define GUCEF_MACROS_H
#endif /* GUCEF_MACROS_H ? */

#ifndef GUCE_CONFIG_H
#include "guce_config.h"      /* GUCE platform build configuration */
#define GUCE_CONFIG_H
#endif /* GUCE_CONFIG_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      GENERAL MACROS                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifdef GUCEF_MSWIN_BUILD
  #define GUCE_MSWIN_BUILD
#else
  #ifdef GUCEF_LINUX_BUILD
    #define GUCE_LINUX_BUILD
  #endif  
#endif

/*-------------------------------------------------------------------------*/

#define GUCE_EXPORT GUCEF_EXPORT
#define GUCE_IMPORT GUCEF_IMPORT

/*-------------------------------------------------------------------------*/

/*
 *      Bit target
 */
#if !( defined(GUCE_32BIT) || defined(GUCE_64BIT) )
    #define GUCE_32BIT
#endif

/*-------------------------------------------------------------------------*/

/*
 *      Change calling convention notation depending on the compiler used.
 *      We simply copy this setting from GUCEF
 */
#undef GUCE_CALLSPEC_C
#undef GUCE_CALLSPEC_STD
#undef GUCE_CALLSPEC_PASCAL
#undef GUCE_CALLSPEC_FAST
#define GUCE_CALLSPEC_C         GUCEF_CALLSPEC_C
#define GUCE_CALLSPEC_STD       GUCEF_CALLSPEC_STD
#define GUCE_CALLSPEC_PASCAL    GUCEF_CALLSPEC_PASCAL
#define GUCE_CALLSPEC_FAST      GUCEF_CALLSPEC_FAST

/*
 *      Macro that switches to the desired calling convention
 *      for GUCE modules. We simply copy this setting from GUCEF
 */
#undef GUCE_CALLSPEC_TYPE
#define GUCE_CALLSPEC_TYPE GUCEF_CALLSPEC_TYPE 

/*
 *      Macro that switches to the desired calling convention
 *      for plugins. We simply copy this setting from GUCEF
 */
#undef GUCE_PLUGIN_CALLSPEC_TYPE
#define GUCE_PLUGIN_CALLSPEC_TYPE GUCEF_PLUGIN_CALLSPEC_TYPE


/*
 *      Macro that switches between a calling convention prefix and
 *      postfix notation for the calling convention macro.
 *      We simply copy this setting from GUCEF
 */
#undef GUCE_CALLSPEC_PREFIX
#undef GUCE_CALLSPEC_SUFFIX
#undef GUCE_PLUGIN_CALLSPEC_PREFIX
#undef GUCE_PLUGIN_CALLSPEC_SUFFIX
#define GUCE_CALLSPEC_PREFIX            GUCEF_CALLSPEC_PREFIX
#define GUCE_CALLSPEC_SUFFIX            GUCEF_CALLSPEC_SUFFIX
#define GUCE_PLUGIN_CALLSPEC_PREFIX     GUCEF_PLUGIN_CALLSPEC_PREFIX
#define GUCE_PLUGIN_CALLSPEC_SUFFIX     GUCEF_PLUGIN_CALLSPEC_SUFFIX

/*-------------------------------------------------------------------------*/

#endif /* GUCE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 30-09-2006 :
       - Dinand: Initial version of this file.

-----------------------------------------------------------------------------*/
