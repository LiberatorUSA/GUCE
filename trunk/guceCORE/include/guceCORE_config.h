/*
 *  guceCORE: GUCE module providing tie-in functionality between systems
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 */

#ifndef GUCE_CORE_CONFIG_H
#define GUCE_CORE_CONFIG_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_MACROS_H
#include "guce_macros.h"        /* engine wide macros and config flags */
#define GUCE_MACROS_H
#endif /* GUCE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      BUILD DEFINES                                                      //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      If we are building or using a DLL then it is sometimes desireable to
 *      export only C code or perhaps only C++ code. You can do this with the
 *      following defines
 */
#undef GUCE_CORE_EXPORT_CPP_CODE      /* do not change this line */  
#undef GUCE_CORE_EXPORT_C_CODE        /* do not change this line */ 
#define GUCE_CORE_EXPORT_CPP_CODE /* do you want to enable the C++ exports ? */
#define GUCE_CORE_EXPORT_C_CODE   /* do you want to enable the C exports ? */

/*
 *      Wheter to build in debug mode, meaning additional debug info will be
 *      generated run-time. This will howerver slow down program excecution and
 *      use more memory.
 */
#undef GUCE_CORE_DEBUG_MODE     /* do not change this line */ 
/* #define GUCE_CORE_DEBUG_MODE */

/*
 *      Switch for removing/adding the GUCEF namespace.
 */
#undef USE_GUCE_NAMESPACE     /* do not change this line */ 
#define USE_GUCE_NAMESPACE

/*
 *      Switch for removing/adding the CORE namespace.
 */
#undef USE_CORE_NAMESPACE     /* do not change this line */ 
#define USE_CORE_NAMESPACE

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CONFIG_H */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 13-01-2007 :
       - Dinand: Got rid of obsolete defines
- 31-12-2004 :
       - Dinand: Initial version of this file.

-----------------------------------------------------------------------------*/
