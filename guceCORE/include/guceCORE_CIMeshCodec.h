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
 
#ifndef GUCE_CORE_CIMESHCODEC_H
#define GUCE_CORE_CIMESHCODEC_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/ 

#include <vector>

#ifndef __Mesh_H__
#include "OgreMesh.h"
#define __Mesh_H__
#endif /* __Mesh_H__ ? */

#ifndef GUCEF_CORE_CTABSTRACTFACTORY_H
#include "CTAbstractFactory.h"
#define GUCEF_CORE_CTABSTRACTFACTORY_H
#endif /* GUCEF_CORE_CTABSTRACTFACTORY_H ? */

#ifndef GUCEF_CORE_CIOACCESS_H
#include "CIOAccess.h"
#define GUCEF_CORE_CIOACCESS_H
#endif /* GUCEF_CORE_CIOACCESS_H ? */

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

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

class GUCE_CORE_EXPORT_CPP CIMeshCodec
{
    public:
    
    typedef std::map< CString, Ogre::MeshPtr > TMeshMap;

    CIMeshCodec( void );
    
    CIMeshCodec( const CIMeshCodec& src );
    
    virtual ~CIMeshCodec();
        
    CIMeshCodec& operator=( const CIMeshCodec& src );

    virtual Ogre::MeshPtr Decode( const CString& meshName      ,
                                  GUCEF::CORE::CIOAccess& data ,
                                  const CString& selectedMesh  ) = 0;
    
    virtual void Decode( const CString& meshNamePrefix ,
                         GUCEF::CORE::CIOAccess& data  ,
                         TMeshMap& meshMap             ) = 0;
                         
    virtual CString GetType( void ) const = 0;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CIMESHCODEC_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
