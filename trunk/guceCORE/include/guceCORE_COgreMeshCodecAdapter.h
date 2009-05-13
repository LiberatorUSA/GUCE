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
 
#ifndef GUCE_CORE_COGREMESHCODECADAPTER_H
#define GUCE_CORE_COGREMESHCODECADAPTER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/ 

#ifndef GUCE_CORE_CIMESHCODEC_H
#include "guceCORE_CIMeshCodec.h"
#define GUCE_CORE_CIMESHCODEC_H
#endif /* GUCE_CORE_CIMESHCODEC_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP COgreMeshCodecAdapter : public CIMeshCodec
{
    public:
    
    COgreMeshCodecAdapter( void );
    
    COgreMeshCodecAdapter( const COgreMeshCodecAdapter& src );
    
    virtual ~COgreMeshCodecAdapter();
        
    COgreMeshCodecAdapter& operator=( const COgreMeshCodecAdapter& src );

    virtual Ogre::MeshPtr Decode( const CString& meshName      ,
                                  GUCEF::CORE::CIOAccess& data ,
                                  const CString& selectedMesh  );
    
    virtual void Decode( const CString& meshNamePrefix ,
                         GUCEF::CORE::CIOAccess& data  ,
                         TMeshMap& meshMap             );
                         
    virtual CString GetType( void ) const;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_COGREMESHCODECADAPTER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
