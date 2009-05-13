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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_CTFACTORY_H
#include "CTFactory.h"
#define GUCEF_CORE_CTFACTORY_H
#endif /* GUCEF_CORE_CTFACTORY_H ? */

#ifndef CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define CGUCEAPPLICATION_H
#endif /* CGUCEAPPLICATION_H ? */

#ifndef CWINDOWMANAGER_H
#include "CWindowManager.h"
#define CWINDOWMANAGER_H
#endif /* CWINDOWMANAGER_H ? */

#ifndef GUCE_CORE_CMESHMANAGER_H
#include "guceCORE_CMeshManager.h"
#define GUCE_CORE_CMESHMANAGER_H
#endif /* GUCE_CORE_CMESHMANAGER_H ? */

#ifndef GUCE_CORE_COGREMESHCODECADAPTER_H
#include "guceCORE_COgreMeshCodecAdapter.h"
#define GUCE_CORE_COGREMESHCODECADAPTER_H
#endif /* GUCE_CORE_COGREMESHCODECADAPTER_H ? */

#include "CGUCECOREModule.h"  /* definition of the class implemented here */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      TYPES                                                              //
//                                                                         //
//-------------------------------------------------------------------------*/

typedef GUCEF::CORE::CTFactory< CIMeshCodec, COgreMeshCodecAdapter > TOgreMeshCodecFactory;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

bool 
CGUCECOREModule::Load( void )
{GUCE_TRACE;

    CGUCEApplication::RegisterEvents();
    CWindowManager::RegisterEvents();
    CWindowContext::RegisterEvents();
    
    CGUCEApplication::Instance();
    CWindowManager::Instance();
    
    CGUCEApplication::Instance()->GetMeshManager().RegisterMeshCodecFactory( "mesh", *(new TOgreMeshCodecFactory()) ); 
    
    return true;
}

/*-------------------------------------------------------------------------*/
        
bool 
CGUCECOREModule::Unload( void )
{GUCE_TRACE;
         
    CGUCEApplication::Instance()->GetMeshManager().UnregisterMeshCodecFactory( "mesh" );
    
    CGUCEApplication::Deinstance();
    CWindowManager::Deinstance();
    return true;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
