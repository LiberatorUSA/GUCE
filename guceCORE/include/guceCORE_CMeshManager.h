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
 
#ifndef GUCE_CORE_CMESHMANAGER_H
#define GUCE_CORE_CMESHMANAGER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/ 

#include <map>

#ifndef GUCEF_CORE_CTABSTRACTFACTORY_H
#include "CTAbstractFactory.h"
#define GUCEF_CORE_CTABSTRACTFACTORY_H
#endif /* GUCEF_CORE_CTABSTRACTFACTORY_H ? */

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

class CGUCEApplication;

/*-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP CMeshManager : private Ogre::ManualResourceLoader
{
    public:
    
    typedef GUCEF::CORE::CTFactoryBase< CIMeshCodec > TMeshCodecFactory;
    typedef std::set< CString >                       TMeshNameSet;
    typedef std::set< CString >                       TMaterialNameSet;
    typedef CIMeshCodec::TMeshMap                     TMeshMap;

    Ogre::MeshPtr LoadFromFile( const CString& meshName             ,
                                const CString& vfsFilePath          ,
                                const CString& selectedMesh         ,
                                const bool generateMaterials = true ,
                                const CString& resourceGroup = ""   ,
                                const CString& vfsMaterialDir = ""  );

    void LoadAllFromFile( const CString& meshName             ,
                          const CString& vfsFilePath          ,
                          TMeshMap& meshMap                   ,
                          const bool generateMaterials = true ,
                          const CString& resourceGroup = ""   ,
                          const CString& vfsMaterialDir = ""  );
                          
    bool GenerateMeshMaterials( Ogre::MeshPtr mesh                 ,
                                const CString& resourceGroup = ""  ,
                                const CString& vfsMaterialDir = "" );

    Ogre::MeshPtr GetMesh( const CString& meshName );
    
    Ogre::MeshPtr CreateDefaultMesh( const CString& meshName      ,
                                     const CString& resourceGroup );
    
    void GetMaterialNamesForMesh( const CString& meshName         ,
                                  TMaterialNameSet& materialNames );
    
    Ogre::MeshManager* GetOgreMeshManager( void );
    
    void RetieveLoadedMeshList( TMeshNameSet& meshList );
       
    void RegisterMeshCodecFactory( const CString& typeName             ,
                                   TMeshCodecFactory& meshCodecFactory );
    
    void UnregisterMeshCodecFactory( const CString& typeName );
        
    private:
    friend class CGUCEApplication;
    
    CMeshManager( void );
    virtual ~CMeshManager();

    private:
    
    virtual void loadResource( Ogre::Resource* resource );
    
    private:
    
    CMeshManager( const CMeshManager& src );
    CMeshManager& operator=( const CMeshManager& src );
    
    private:
    typedef GUCEF::CORE::CTAbstractFactory< CString, CIMeshCodec > TAbstractMeshCodecFactory;
    
    struct SMeshMapEntry
    {
        Ogre::MeshPtr mesh;
        CString vfsPath;
    };
    typedef struct SMeshMapEntry TMeshMapEntry;
    
    typedef std::map< CString, TMeshMapEntry > TLoadedMeshMap;
    
    TAbstractMeshCodecFactory m_meshCodecFactory;
    TLoadedMeshMap m_meshMap;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CMESHMANAGER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
