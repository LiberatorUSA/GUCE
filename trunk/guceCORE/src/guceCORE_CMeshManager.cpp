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

#ifndef __MeshManager_H__
#include "OgreMeshManager.h"
#define __MeshManager_H__
#endif /* __MeshManager_H__ ? */

#ifndef __SubMesh_H_
#include <OgreSubMesh.h>
#define __SubMesh_H_
#endif /* __SubMesh_H_ ? */

#ifndef __ROOT__
#include <OgreRoot.h>
#define __ROOT__
#endif /* __ROOT__ ? */

#ifndef __MATERIALMANAGER_H__
#include "OgreMaterialManager.h"
#define __MATERIALMANAGER_H__
#endif /* __MATERIALMANAGER_H__ ? */

#include "OgreTextureManager.h"

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCEF_VFS_CVFS_H
#include "gucefVFS_CVFS.h"
#define GUCEF_VFS_CVFS_H
#endif /* GUCEF_VFS_CVFS_H ? */

#ifndef GUCE_CORE_MISCUTILS_H
#include "miscutils.h"
#define GUCE_CORE_MISCUTILS_H
#endif /* GUCE_CORE_MISCUTILS_H ? */

#include "guceCORE_CMeshManager.h"

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

CMeshManager::CMeshManager( void )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CMeshManager::~CMeshManager()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

Ogre::MeshPtr
CMeshManager::CreateDefaultMesh( const CString& meshName      ,
                                 const CString& resourceGroup )
{GUCE_TRACE;

    // First check if we dont already have a mesh with this name
    Ogre::MeshPtr meshPtr = GetMesh( meshName );
    if ( meshPtr.isNull() )
    {
        // Pass on to Ogre mesh manager
        Ogre::MeshManager* meshManager = Ogre::MeshManager::getSingletonPtr();
        return meshManager->createManual( meshName, resourceGroup, this );
    }
    
    return Ogre::MeshPtr();
}

/*-------------------------------------------------------------------------*/

void
CMeshManager::GetMaterialNamesForMesh( const CString& meshName         ,
                                       TMaterialNameSet& materialNames )
{GUCE_TRACE;

    Ogre::MeshPtr meshPtr = GetMesh( meshName );
    if ( !meshPtr.isNull() )
    {
        UInt32 subMeshCount = meshPtr->getNumSubMeshes();
        for ( UInt32 i=0; i<subMeshCount; ++i )
        {
            // Get the material name from the sub mesh
            Ogre::SubMesh* subMesh = meshPtr->getSubMesh( i );
            materialNames.insert( subMesh->getMaterialName().c_str() );
        }
    }
}

/*-------------------------------------------------------------------------*/

bool
CMeshManager::GenerateMeshMaterials( Ogre::MeshPtr mesh            ,
                                     const CString& resourceGroup  ,
                                     const CString& vfsMaterialDir )
{GUCE_TRACE;
    
    // Add a gucefVFS link to the resource group
    Ogre::Root::getSingletonPtr()->addResourceLocation( "" , 
                                                        "gucefVFS"     , 
                                                        resourceGroup  );

    UInt32 subMeshCount = mesh->getNumSubMeshes();
    for ( UInt32 i=0; i<subMeshCount; ++i )
    {
        try
        {
            // Get the material name from the sub mesh
            Ogre::SubMesh* subMesh = mesh->getSubMesh( i );
            CString materialName = subMesh->getMaterialName().c_str();
            
            Ogre::MaterialManager* materialManager = Ogre::MaterialManager::getSingletonPtr();
            Ogre::ResourcePtr resource = materialManager->getByName( materialName );
            if ( resource.isNull() )
            {
                // The material does not exist, try to load it
                CString extention = GUCEF::CORE::ExtractFileExtention( materialName );
                CString materialFilename;
                if ( extention.Length() == 0 )
                {                     
                    GUCEF::VFS::CVFS* vfs = GUCEF::VFS::CVFS::Instance();
                    CString resourcePath;
                    
                    materialFilename = materialName + ".material";
                    resourcePath = vfsMaterialDir;
                    GUCEF::CORE::AppendToPath( resourcePath, materialFilename );
                    if ( !vfs->FileExists( resourcePath ) )
                    {
                        // Unable to load such a material with the given filename
                        // We will try to create a simple material using the material name as a texture
                        // name instead.
                        GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Failed to load material from file \"" + materialFilename + "\"" );
                        Ogre::TextureManager* textureManager = Ogre::TextureManager::getSingletonPtr();
                        
                        bool fileFound = true;
                        materialFilename = materialName + ".dds";
                        resourcePath = vfsMaterialDir;
                        GUCEF::CORE::AppendToPath( resourcePath, materialFilename );                        
                        if ( !vfs->FileExists( resourcePath ) )
                        {
                            materialFilename = materialName + ".png";
                            resourcePath = vfsMaterialDir;
                            GUCEF::CORE::AppendToPath( resourcePath, materialFilename );
                            if ( !vfs->FileExists( resourcePath ) )
                            {
                                materialFilename = materialName + ".jpg";
                                resourcePath = vfsMaterialDir;
                                GUCEF::CORE::AppendToPath( resourcePath, materialFilename );
                                if ( !vfs->FileExists( resourcePath ) )
                                {
                                    materialFilename = materialName + ".gif";
                                    resourcePath = vfsMaterialDir;
                                    GUCEF::CORE::AppendToPath( resourcePath, materialFilename ); 
                                    if ( !vfs->FileExists( resourcePath ) )
                                    {
                                        materialFilename = materialName + ".tga";
                                        resourcePath = vfsMaterialDir;
                                        GUCEF::CORE::AppendToPath( resourcePath, materialFilename );                                
                                        if ( !vfs->FileExists( resourcePath ) )
                                        {
                                            materialFilename = materialName + ".tiff";
                                            resourcePath = vfsMaterialDir;
                                            GUCEF::CORE::AppendToPath( resourcePath, materialFilename );                                
                                            if ( !vfs->FileExists( resourcePath ) )
                                            {
                                                materialFilename = materialName + ".pcx";
                                                resourcePath = vfsMaterialDir;
                                                GUCEF::CORE::AppendToPath( resourcePath, materialFilename );
                                                if ( !vfs->FileExists( resourcePath ) )
                                                {
                                                    fileFound = false;
                                                }                                
                                            }                                            
                                        }                                                                                
                                    }                                                                   
                                }
                            }
                        }
                        
                        if ( fileFound )
                        {
                            GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Succeeded in locating a texture for material \"" + materialName + "\" from file \"" + resourcePath + "\"" );

                            CString materialScript = Create2DTextureMaterialScript( materialName, resourcePath );
                            RegisterScriptMaterial( materialScript, resourceGroup );
                        }
                        else
                        {
                            GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Failed to locate any texture that could be used to create a material with name \"" + materialName + "\"" );
                        }
                    }
                }
                else
                {
                    // the material name has a file extention in it
                    // this allows us to process it directly instead of playing a guessing game
                    resource = materialManager->load( materialName, resourceGroup );
                    if ( resource.isNull() )
                    {
                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Material has the specific filename \"" + materialName + "\" but attempts to load it failed, creating default material" );
                        resource = materialManager->create( materialName, resourceGroup );
                        if ( resource.isNull() )
                        {
                            GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Failed to create a default Material with the name \"" + materialName + "\"" );
                        }
                        else
                        {
                            GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Created default material with name \"" + materialName + "\"" );
                        }
                    }
                    else
                    {
                        GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Loaded material with name \"" + materialName + "\"" );
                    }
                }
            }
            else
            {
                GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Material already exists with name \"" + materialName + "\" thus no reason to generate it" );
            }                
        }
        catch ( Ogre::Exception& e )
        {
            GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Exception while generating material for mesh with name \"" + mesh->getName() + "\" :" + e.getFullDescription() );
            return false;
        }
    }
    return true;
}

/*-------------------------------------------------------------------------*/

Ogre::MeshPtr
CMeshManager::LoadFromFile( const CString& meshName       ,
                            const CString& vfsFilePath    ,
                            const CString& selectedMesh   ,
                            const bool generateMaterials  ,
                            const CString& resourceGroup  ,
                            const CString& vfsMaterialDir )
{GUCE_TRACE;

    CString meshType = GUCEF::CORE::ExtractFileExtention( vfsFilePath ).Lowercase();
    if ( m_meshCodecFactory.IsConstructible( meshType ) )
    {
        GUCEF::VFS::CVFS::CVFSHandlePtr filePtr = GUCEF::VFS::CVFS::Instance()->GetFile( vfsFilePath );
        if ( NULL != filePtr )
        {
            CIMeshCodec* meshCodec = m_meshCodecFactory.Create( meshType );
            if ( NULL != meshCodec )
            {
                Ogre::MeshPtr meshPtr = meshCodec->Decode( meshName, *filePtr->GetAccess(), selectedMesh );
                m_meshCodecFactory.Destroy( meshCodec );
                
                if ( generateMaterials )
                {
                    GenerateMeshMaterials( meshPtr, resourceGroup, vfsMaterialDir );
                }
                
                return meshPtr;
            }
        }
    }
    return Ogre::MeshPtr();
}

/*-------------------------------------------------------------------------*/

void
CMeshManager::LoadAllFromFile( const CString& meshName       ,
                               const CString& vfsFilePath    ,
                               TMeshMap& meshMap             ,
                               const bool generateMaterials  ,
                               const CString& resourceGroup  ,
                               const CString& vfsMaterialDir )
{GUCE_TRACE;

    CString meshType = GUCEF::CORE::ExtractFileExtention( vfsFilePath ).Lowercase();
    if ( m_meshCodecFactory.IsConstructible( meshType ) )
    {
        GUCEF::VFS::CVFS::CVFSHandlePtr filePtr = GUCEF::VFS::CVFS::Instance()->GetFile( vfsFilePath );
        if ( NULL != filePtr )
        {
            CIMeshCodec* meshCodec = m_meshCodecFactory.Create( meshType );
            if ( NULL != meshCodec )
            {
                TMeshMap meshes;
                meshCodec->Decode( meshName, *filePtr->GetAccess(), meshes );
                m_meshCodecFactory.Destroy( meshCodec );
                
                TMeshMap::iterator i = meshes.begin();
                while ( i != meshes.end() )
                {
                    TMeshMapEntry entry;
                    entry.mesh = (*i).second;
                    entry.vfsPath = vfsFilePath;
                    m_meshMap[ (*i).first ] = entry;
                    
                    if ( generateMaterials )
                    {
                        GenerateMeshMaterials( entry.mesh, resourceGroup, vfsMaterialDir );
                    }                    
                    
                    ++i;
                }
                meshMap = meshes;
            }
        }
    }
}

/*-------------------------------------------------------------------------*/

Ogre::MeshPtr
CMeshManager::GetMesh( const CString& meshName )
{GUCE_TRACE;

    TLoadedMeshMap::iterator i = m_meshMap.find( meshName );
    if ( i != m_meshMap.end() )
    {
        return (*i).second.mesh;
    }
    return Ogre::MeshPtr();
}

/*-------------------------------------------------------------------------*/

void
CMeshManager::loadResource( Ogre::Resource* resource )
{GUCE_TRACE;

    // @TODO makeme
}

/*-------------------------------------------------------------------------*/

Ogre::MeshManager*
CMeshManager::GetOgreMeshManager( void )
{GUCE_TRACE;

    return Ogre::MeshManager::getSingletonPtr();
}
    
/*-------------------------------------------------------------------------*/

void
CMeshManager::RegisterMeshCodecFactory( const CString& typeName             ,
                                        TMeshCodecFactory& meshCodecFactory )
{GUCE_TRACE;

    m_meshCodecFactory.RegisterConcreteFactory( typeName, &meshCodecFactory );
    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Registered factory for mesh type \"" + typeName + "\"" );
}

/*-------------------------------------------------------------------------*/
    
void
CMeshManager::UnregisterMeshCodecFactory( const CString& typeName )
{GUCE_TRACE;

    m_meshCodecFactory.UnregisterConcreteFactory( typeName );
    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "MeshManager: Unregistered factory for mesh type \"" + typeName + "\"" );
}

/*-------------------------------------------------------------------------*/

void
CMeshManager::RetieveLoadedMeshList( TMeshNameSet& meshList )
{GUCE_TRACE;

    TLoadedMeshMap::iterator i = m_meshMap.begin();
    while ( i != m_meshMap.end() )
    {
        meshList.insert( (*i).first );
        ++i;
    }
}
            
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/    