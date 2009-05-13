/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2007.  All rights reserved.
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

#ifndef GUCE_H
#define GUCE_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_H
#include "gucef.h"                /* main GUCEF platform include */
#define GUCEF_H
#endif /* GUCEF_H ? */

#ifndef GUCE_CONFIG_H
#include "guce_config.h"          /* GUCEF engine build configuration */
#define GUCE_CONFIG_H
#endif /* GUCE_CONFIG_H ? */

#ifndef GUCE_MACROS_H
#include "guce_macros.h"          /* GUCEF engine macro's */
#define GUCE_MACROS_H
#endif /* GUCEF_MACROS_H ? */

#ifndef GUCE_CORE_H
#include "guceCORE.h"             /* GUCEF engine CORE module */
#define GUCE_CORE_H
#endif /* GUCE_CORE_H ? */

#ifndef GUCE_GUI_H
#include "guceGUI.h"              /* GUCE engine GUI module */
#define GUCE_GUI_H
#endif /* GUCE_GUI_H ? */

#ifndef GUCE_MULTIPLAY_H
//#include "guceMULTIPLAY.h"      /* GUCE engine MULTIPLAY module */
#define GUCE_MULTIPLAY_H
#endif /* GUCE_MULTIPLAY_H ? */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-01-2007 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/