/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2005.  All rights reserved.
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

#ifndef GUCE_GUI_CONFIG_H
#define GUCE_GUI_CONFIG_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      BUILD DEFINES                                                      //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Wheter to build in debug mode, meaning additional debug info will be
 *      generated run-time. This will howerver slow down program excecution and
 *      use more memory.
 */
#undef GUCE_GUI_DEBUG_MODE     /* do not change this line */ 
/* #define GUCE_GUI_DEBUG_MODE */

/*
 *      Switch for removing/adding the GUCEF namespace.
 */
#undef USE_GUCE_NAMESPACE     /* do not change this line */ 
#define USE_GUCE_NAMESPACE

/*
 *      Switch for removing/adding the CORE namespace.
 */
#undef USE_GUI_NAMESPACE     /* do not change this line */ 
#define USE_GUI_NAMESPACE

#define GUCEGUI_EXPORT_CPP_CODE
#define GUCEGUI_EXPORT_C_CODE

/*
 *      Switch that activates or deactivates the module memory manager.
 *      This is a debugging tool that will allow you to search for
 *      memory leaks and bounds violations. 
 */
#undef ACTIVATE_MEMORY_MANAGER  /* do not change this line */
//#define ACTIVATE_MEMORY_MANAGER

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_CONFIG_H */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 31-12-2004 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
 
