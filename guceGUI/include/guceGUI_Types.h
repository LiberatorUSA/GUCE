/*
 *  gucefGUI: GUCE module providing GUI functionality
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

#ifndef GUCE_GUI_TYPES_H
#define GUCE_GUI_TYPES_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_CORE_ETYPES_H
#include "guceCORE_ETypes.h"   /* GUCE::CORE types are imported */
#define GUCE_CORE_ETYPES_H
#endif /* GUCE_CORE_ETYPES_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CONSTANTS                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Maximum and minimal values for the simple types which we are about to
 *      define.
 */
#define GUCEGUI_INT8MAX     GUCECORE_INT8MAX
#define GUCEGUI_INT8MIN     GUCECORE_INT8MIN
#define GUCEGUI_UINT8MAX    GUCECORE_UINT8MAX
#define GUCEGUI_UINT8MIN    GUCECORE_UINT8MIN
#define GUCEGUI_INT16MAX    GUCECORE_INT16MAX
#define GUCEGUI_INT16MIN    GUCECORE_INT16MIN
#define GUCEGUI_UINT16MAX   GUCECORE_UINT16MAX
#define GUCEGUI_UINT16MIN   GUCECORE_UINT16MIN
#define GUCEGUI_INT32MAX    GUCECORE_INT32MAX
#define GUCEGUI_INT32MIN    GUCECORE_INT32MIN
#define GUCEGUI_UINT32MAX   GUCECORE_UINT32MAX
#define GUCEGUI_UINT32MIN   GUCECORE_UINT32MIN
#define GUCEGUI_FLOAT32MAX  GUCECORE_FLOAT32MAX
#define GUCEGUI_FLOAT32MIN  GUCECORE_FLOAT32MIN

/*--------------------------------------------------------------------------*/

/*
 *  We only have to define types when using C++ due to namespacing 
 *  For C the guceCORE versions are automaticly used in the global namespace
 */
#ifdef __cplusplus
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace GUI {

/*-------------------------------------------------------------------------//
//                                                                         //
//      TYPES                                                              //
//                                                                         //
//-------------------------------------------------------------------------*/

typedef CORE::UInt8 UInt8;    /* 1 byte, unsigned */
typedef CORE::Int8 Int8;      /* 1 byte, signed */

typedef CORE::UInt16 UInt16;   /* 2 bytes, unsigned */
typedef CORE::Int16 Int16;     /* 2 bytes, signed */

typedef CORE::UInt32 UInt32;   /* 4 bytes, unsigned */
typedef CORE::Int32  Int32;    /* 4 bytes, signed */

typedef CORE::Int64 Int64;     /* 8 bytes, signed */
typedef CORE::UInt64 UInt64;   /* 8 bytes, unsigned */

typedef CORE::Float32 Float32;  /* 4 bytes, signed, decimal */
typedef CORE::Float64 Float64;  /* 8 bytes, signed, decimal */

typedef CORE::CString CString;

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*--------------------------------------------------------------------------*/

#endif /* __cplusplus ? */

#endif /* GUCE_GUI_TYPES_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 31-12-2004 :
       - Dinand: Added this section

-----------------------------------------------------------------------------*/