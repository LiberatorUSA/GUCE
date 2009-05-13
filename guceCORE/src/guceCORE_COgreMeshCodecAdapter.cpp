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

#ifndef __MeshSerializer_H__
#include "OgreMeshSerializer.h"
#define __MeshSerializer_H__
#endif /* __MeshSerializer_H__ ? */

#ifndef GUCE_CORE_CIOACCESSTODATASTREAM_H
#include "CIOAccessToDataStream.h"
#define GUCE_CORE_CIOACCESSTODATASTREAM_H
#endif /* GUCE_CORE_CIOACCESSTODATASTREAM_H ? */

#ifndef GUCE_CORE_CMESHMANAGER_H
#include "guceCORE_CMeshManager.h"
#define GUCE_CORE_CMESHMANAGER_H
#endif /* GUCE_CORE_CMESHMANAGER_H ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

#ifndef GUCE_CORE_CSTATICDATASTREAMPTR_H
#include "CStaticDataStreamPtr.h"
#define GUCE_CORE_CSTATICDATASTREAMPTR_H
#endif /* GUCE_CORE_CSTATICDATASTREAMPTR_H ? */

#include "guceCORE_COgreMeshCodecAdapter.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

COgreMeshCodecAdapter::COgreMeshCodecAdapter( void )
    : CIMeshCodec()
{GUCE_TRACE;

}
    
/*-------------------------------------------------------------------------*/

COgreMeshCodecAdapter::COgreMeshCodecAdapter( const COgreMeshCodecAdapter& src )
    : CIMeshCodec( src )
{GUCE_TRACE;

}
    
/*-------------------------------------------------------------------------*/

COgreMeshCodecAdapter::~COgreMeshCodecAdapter()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
        
COgreMeshCodecAdapter& 
COgreMeshCodecAdapter::operator=( const COgreMeshCodecAdapter& src )
{GUCE_TRACE;

    return *this;
}

/*-------------------------------------------------------------------------*/

Ogre::MeshPtr
COgreMeshCodecAdapter::Decode( const CString& meshName      ,
                               GUCEF::CORE::CIOAccess& data ,
                               const CString& selectedMesh  )
{GUCE_TRACE;

    // We will ignore the 'selectedMesh' parameter

    try
    {
        // Prepare data
        Ogre::MeshSerializer serializer;
        CIOAccessToDataStream stream( &data ); 
        CStaticDataStreamPtr streamPtr( &stream );
        Ogre::MeshPtr meshPtr = CGUCEApplication::Instance()->GetMeshManager().CreateDefaultMesh( meshName, "" );
                
        // Load the Ogre mesh from the stream
        serializer.importMesh( streamPtr, meshPtr.getPointer() );

        /* check all submeshes to see if their materials should be
           updated.  If the submesh has texture aliases that match those
           found in the current material then a new material is created using
           the textures from the submesh.
        */
        meshPtr->updateMaterialForAllSubMeshes();
        
        return meshPtr;
    }
    catch ( Ogre::Exception& )
    {
        return Ogre::MeshPtr();
    }
}

/*-------------------------------------------------------------------------*/
    
void
COgreMeshCodecAdapter::Decode( const CString& meshNamePrefix ,
                               GUCEF::CORE::CIOAccess& data  ,
                               TMeshMap& meshMap             )
{GUCE_TRACE;

    Ogre::MeshPtr meshPtr = Decode( meshNamePrefix ,
                                    data           ,
                                    ""             );
    if ( !meshPtr.isNull() )
    {
        meshMap[ meshNamePrefix ] = meshPtr;
    }
}

/*-------------------------------------------------------------------------*/
                         
CString
COgreMeshCodecAdapter::GetType( void ) const
{GUCE_TRACE;

    return "mesh";
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
