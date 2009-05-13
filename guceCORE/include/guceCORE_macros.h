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

#ifndef GUCE_CORE_MACROS_H
#define GUCE_CORE_MACROS_H

/*
 *      Build configuration specific macros.
 *      Also includes the generic macros which are build config independant.
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_MACROS_H
#include "gucefCORE_macros.h"      /* include platform macros */
#define GUCEF_CORE_MACROS_H
#endif /* GUCEF_CORE_MACROS_H ? */

#ifndef GUCEF_CORE_CTRACER_H
#include "CTracer.h"
#define GUCEF_CORE_CTRACER_H
#endif /* GUCEF_CORE_CTRACER_H ? */

#ifndef GUCE_CORE_CONFIG_H
#include "guceCORE_config.h"      /* Module build configuration */
#define GUCE_CORE_CONFIG_H
#endif /* GUCE_CORE_CONFIG_H ? */

#ifndef GUCE_CORE_ETYPES_H
#include "guceCORE_ETypes.h"      /* often used simple types */
#define GUCE_CORE_ETYPES_H
#endif /* GUCE_CORE_ETYPES_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      GENERAL MACROS                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Auto detection of debug mode
 */
#if defined( _DEBUG ) && !defined( NDEBUG )
  #define GUCE_CORE_DEBUG_MODE
#else
  #undef GUCE_CORE_DEBUG_MODE
#endif /* compiler DEBUG switches */

/*-------------------------------------------------------------------------*/

/*
 *  namespace the TRACE macro for GUCE
 */
#ifdef GUCEF_TRACE
  #define GUCE_TRACE GUCEF_TRACE
#else
  #define GUCE_TRACE  
#endif

/*-------------------------------------------------------------------------*/

/*
 *      Macro for enabling/disabling the GUCE namespace
 */
#undef GUCE_NAMESPACE_BEGIN
#undef GUCE_NAMESPACE_END   
#ifdef USE_GUCE_NAMESPACE
  #define GUCE_NAMESPACE_BEGIN   namespace GUCE {
  #define GUCE_NAMESPACE_END     }
#else
  #define GUCE_NAMESPACE_BEGIN
  #define GUCE_NAMESPACE_END
#endif /* USE_GUCE_NAMESPACE ? */

/*-------------------------------------------------------------------------*/

/*
 *      Macro for enabling/disabling the CORE namespace
 */
#undef CORE_NAMESPACE_BEGIN
#undef CORE_NAMESPACE_END   
#ifdef USE_CORE_NAMESPACE
  #define CORE_NAMESPACE_BEGIN   namespace CORE {
  #define CORE_NAMESPACE_END     }
#else
  #define CORE_NAMESPACE_BEGIN
  #define CORE_NAMESPACE_END
#endif /* USE_CORE_NAMESPACE ? */

/*-------------------------------------------------------------------------*/

/*
 *      Macros for dynamic linking or static linking. Use the switches in the
 *      config file to control the export type.
 */
#undef GUCE_EXPORTSPEC
#ifdef GUCE_CORE_BUILD_MODULE
  #define GUCE_EXPORTSPEC GUCE_EXPORT
#else
  #define GUCE_EXPORTSPEC GUCE_IMPORT
#endif /* BUILD_DLL */

#undef GUCE_CORE_EXPORT_CPP
#ifdef GUCE_CORE_EXPORT_CPP_CODE
  #define GUCE_CORE_EXPORT_CPP GUCE_EXPORTSPEC
#else
  #define GUCE_CORE_EXPORT_CPP
#endif /* EXPORT_CPP_CODE */

#undef GUCE_CORE_EXPORT_C
#ifdef GUCE_CORE_EXPORT_C_CODE
  #define GUCE_CORE_EXPORT_C GUCE_EXPORTSPEC
#else
  #define GUCE_CORE_EXPORT_C
#endif /* GUCE_CORE_EXPORT_C_CODE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_MACROS_H ? */
