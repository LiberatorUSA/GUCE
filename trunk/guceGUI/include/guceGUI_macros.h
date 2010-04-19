/*
 *  guceGUI: GUCE module providing GUI functionality
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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

#ifndef GUCE_GUI_MACROS_H
#define GUCE_GUI_MACROS_H

/*
 *      Build configuration specific macros.
 *      Also includes the generic macros which are build config independant.
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h" 
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#ifndef GUCE_GUI_TYPES_H
#include "guceGUI_Types.h"         /* simple types */
#define GUCE_GUI_TYPES_H
#endif /* GUCE_GUI_TYPES_H ? */

#ifndef GUCE_GUI_CONFIG_H
#include "guceGUI_config.h"        /* Module build configuration */
#define GUCE_GUI_CONFIG_H
#endif /* GUCE_GUI_CONFIG_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      GENERAL MACROS                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_GUI_DEBUG_MODE
  #if defined( DEBUG ) || defined( _DEBUG ) && !defined( NDEBUG )
    #define GUCE_GUI_DEBUG_MODE
  #endif  
#endif

/*-------------------------------------------------------------------------*/

/* legacy support */
#ifdef GUCEGUI_BUILD_MODULE
  #define GUCE_GUI_BUILD_MODULE
#endif 

/*
 *      Macros for dynamic linking. Use the switches in the
 *      config file to control the export type.
 */
#undef GUCE_GUI_EXPORT 
#ifdef GUCEF_MSWIN_BUILD
  #ifdef GUCE_GUI_BUILD_MODULE
    #define GUCE_GUI_EXPORT GUCEF_EXPORT
  #else
    #define GUCE_GUI_EXPORT GUCEF_IMPORT
  #endif /* GUCE_GUI_BUILD_MODULE ? */
#else
  #define GUCE_GUI_EXPORT   /* Linux does not need an additional directive */
#endif /* GUCEF_MSWIN_BUILD ? */

/*
 *  Are we exporting C++ code ?
 */
#undef GUCE_GUI_EXPORT_CPP
#ifdef GUCE_GUI_EXPORT_CPP_CODE
  #define GUCE_GUI_EXPORT_CPP GUCE_GUI_EXPORT
#else
  #define GUCE_GUI_EXPORT_CPP
#endif /* GUCE_GUI_EXPORT_CPP_CODE ? */

/*
 *  Are we exporting C code ?
 */
#undef GUCE_GUI_EXPORT_C
#ifdef GUCE_GUI_EXPORT_C_CODE
  #define GUCE_GUI_EXPORT_C GUCE_GUI_EXPORT
#else
  #define GUCE_GUI_EXPORT_C
#endif /* GUCE_GUI_EXPORT_C_CODE ? */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_MACROS_H ? */