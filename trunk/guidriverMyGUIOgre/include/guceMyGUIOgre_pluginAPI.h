/*
 *  guceMyGUIOgre: glue module for the MyGUI+Ogre GUI backend
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 */

#ifndef GUCE_MYGUIOGRE_PLUGINAPI_H
#define GUCE_MYGUIOGRE_PLUGINAPI_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_ESTRUCTS_H
#include "EStructs.h"
#define GUCEF_CORE_ESTRUCTS_H
#endif /* GUCEF_CORE_ESTRUCTS_H ? */

#ifndef GUCE_MYGUIOGRE_MACROS_H
#include "guceMyGUIOgre_macros.h"
#define GUCE_MYGUIOGRE_MACROS_H
#endif /* GUCE_MYGUIOGRE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace MYGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Prevent C++ name mangling
 */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/

GUCE_MYGUIOGRE_EXPORT_C void GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_Load( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX;

/*--------------------------------------------------------------------------*/

GUCE_MYGUIOGRE_EXPORT_C void GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_Unload( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX;

/*--------------------------------------------------------------------------*/

GUCE_MYGUIOGRE_EXPORT_C void GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_GetVersion( GUCEF::CORE::TVersion* versionInfo ) GUCEF_PLUGIN_CALLSPEC_SUFFIX;

/*--------------------------------------------------------------------------*/

GUCE_MYGUIOGRE_EXPORT_C const char* GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_GetCopyright( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX;

/*--------------------------------------------------------------------------*/

GUCE_MYGUIOGRE_EXPORT_C const char* GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_GetDescription( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX;

/*---------------------------------------------------------------------------*/                 

#ifdef __cplusplus
   }
#endif /* __cplusplus */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace MYGUIOGRE */
}; /* namespace GUCE */

/*--------------------------------------------------------------------------*/

#endif /* GUCE_MYGUIOGRE_PLUGINAPI_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 04-05-2005 :
        - Dinand: Initial version.

-----------------------------------------------------------------------------*/