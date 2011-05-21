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

#include <stdio.h>

#ifndef __Exception_H_
#include "OgreException.h"
#define __Exception_H_
#endif /* __Exception_H_ ? */

#ifndef _ImageCodec_H__
#include "OgreImageCodec.h"
#define _ImageCodec_H__
#endif /* _ImageCodec_H__ ? */

#ifndef _Image_H__
#include "OgreImage.h"
#define _Image_H__
#endif /* _Image_H__ ? */

#ifndef __MATERIALMANAGER_H__
#include "OgreMaterialManager.h"
#define __MATERIALMANAGER_H__
#endif /* __MATERIALMANAGER_H__ ? */

#ifndef _TextureManager_H__
#include "OgreTextureManager.h"
#define _TextureManager_H__
#endif /* _TextureManager_H__ ? */

#ifndef GUCE_CORE_COGREIMAGECODECADAPTER_H
#include "COgreImageCodecAdapter.h"
#define GUCE_CORE_COGREIMAGECODECADAPTER_H
#endif /* GUCE_CORE_COGREIMAGECODECADAPTER_H ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCEF_VFS_CVFS_H
#include "gucefVFS_CVFS.h"
#define GUCEF_VFS_CVFS_H
#endif /* GUCEF_VFS_CVFS_H ? */

#ifndef GUCEF_IMAGE_CIMAGE_H
#include "CImage.h"
#define GUCEF_IMAGE_CIMAGE_H
#endif /* GUCEF_IMAGE_CIMAGE_H ? */

#ifndef CDATANODE_H
#include "CDataNode.h"            /* gucefCORE data storage nodes */
#define CDATANODE_H
#endif /* CDATANODE_H ? */

#ifndef CDSTORECODECREGISTRY_H
#include "CDStoreCodecRegistry.h"
#define CDSTORECODECREGISTRY_H
#endif /* CDSTORECODECREGISTRY_H ? */

#ifndef CMFILEACCESS_H
#include "CMFileAccess.h"
#define CMFILEACCESS_H
#endif /* CMFILEACCESS_H ? */

#ifndef CIOACCESSTODATASTREAM_H
#include "CIOAccessToDataStream.h"
#define CIOACCESSTODATASTREAM_H
#endif /* CIOACCESSTODATASTREAM_H ? */

#ifndef CSTATICDATASTREAMPTR_H
#include "CStaticDataStreamPtr.h"
#define CSTATICDATASTREAMPTR_H
#endif /* CSTATICDATASTREAMPTR_H ? */

#include "miscutils.h"

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

GUCEF::CORE::CString
Create2DTextureMaterialScript( const GUCEF::CORE::CString& materialname ,
                               const GUCEF::CORE::CString& texfilename  )          
{GUCE_TRACE;             

    CString texFilename = texfilename.ReplaceChar( '\\', '/' );
    return "material " + materialname+ "\n" + 
           "{\n" + 
               "technique\n" + 
               "{\n" + 
                   "pass\n" + 
                    "{\n" + 
                        "texture_unit\n" + 
                        "{\n" + 
                            "texture " + texFilename +
                        "\n}" + 
                   "\n}" + 
               "\n}" + 
           "\n}";
}

/*-------------------------------------------------------------------------*/

GUCEF::CORE::CString
Create2DTextureMaterialScript( const GUCEF::CORE::CString& materialname ,
                               const GUCEF::CORE::CString& texfilename  ,
                               Int32 mipmaplevels                       )
{GUCE_TRACE;

    CString mipmaps( "unlimited" );
    if ( mipmaplevels >= 0 ) 
    {
            mipmaps.SetInt( mipmaplevels );
    }                

    CString texFilename = texfilename.ReplaceChar( '\\', '/' );
    return "material " + materialname+ "\n" + 
           "{\n" + 
               "technique\n" + 
               "{\n" + 
                   "pass\n" + 
                    "{\n" + 
                        "texture " + texFilename + " 2d " + mipmaps + 
                        "{\n" + 
                            "texture " + texFilename + 
                        "\n}" + 
                   "\n}" + 
               "\n}" + 
           "\n}";
}

/*-------------------------------------------------------------------------*/

bool
RegisterScriptMaterial( const GUCEF::CORE::CString& script        ,
                        const GUCEF::CORE::CString& resourcegroup )
{GUCE_TRACE;
        
    try
    {        
        GUCEF::CORE::CMFileAccess mfile( script.C_String(), script.Length() );
        CIOAccessToDataStream access( &mfile );
        CStaticDataStreamPtr accessptr( &access );
        Ogre::MaterialManager::getSingletonPtr()->parseScript( accessptr, resourcegroup.C_String() );
        return true;
    }
    catch ( Ogre::Exception& e )
    {
        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Exception in RegisterScriptMaterial() (From Ogre): " + e.getFullDescription() );        
        return false;
    }
    catch ( std::exception& e )
    {
        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "Exception in RegisterScriptMaterial(): " ) + e.what() );
        return false;
    }
}

/*-------------------------------------------------------------------------*/

bool
FindOtherDataTreeStorage( GUCEF::CORE::CString& configfile      ,
                          GUCEF::CORE::CString& filecodec       ,
                          const GUCEF::CORE::CDataNode& tree    ,
                          const GUCEF::CORE::CString& searchstr ,                          
                          char sepchar      /* = '%'  */        ,
                          bool fromcurrent  /* = true */        )
{GUCE_TRACE;
        const GUCEF::CORE::CDataNode* node = tree.Search( searchstr   ,
                                                          sepchar     ,
                                                          fromcurrent );
        if ( node )
        {
                const GUCEF::CORE::CDataNode::TKeyValuePair* att( node->GetAttribute( "file" ) );
                if ( att )
                { 
                        configfile = att->second;
                        att = node->GetAttribute( "filecodec" );
                        if ( att )
                        {
                                filecodec = att->second;
                                return true;
                        }
                }
        }
        return false;        
}

/*-------------------------------------------------------------------------*/

bool
LoadDataTree( GUCEF::CORE::CIOAccess& file          ,
              const GUCEF::CORE::CString& codectype ,
              GUCEF::CORE::CDataNode* rootnode      )
{GUCE_TRACE;

    GUCEF::CORE::CDStoreCodecRegistry* codecRegistry = GUCEF::CORE::CDStoreCodecRegistry::Instance();
    if ( codecRegistry->IsRegistered( codectype ) )
    {
        GUCEF::CORE::CDStoreCodecRegistry::TDStoreCodecPtr codec = codecRegistry->Lookup( codectype );
        if ( NULL != codec )
        {
            if ( codec->BuildDataTree( rootnode ,
                                       &file    ) )
            {
                    return true;        
            }
            return false;                        
        }
        return false;          
    }
    return false;            
}

/*-------------------------------------------------------------------------*/

bool
VFSLoadDataTree( const GUCEF::CORE::CString& file      ,
                 const GUCEF::CORE::CString& codectype ,
                 GUCEF::CORE::CDataNode* rootnode      )
{GUCE_TRACE;
    
    GUCEF::VFS::CVFS* vfs = GUCEF::VFS::CVFS::Instance();                
    GUCEF::VFS::CVFS::CVFSHandlePtr fhndl = vfs->GetFile( file );

    if ( fhndl != NULL )
    {
        if ( LoadDataTree( *fhndl->GetAccess() ,
                           codectype           ,
                           rootnode            ) )
        {
            return true;        
        }
        return false;                        
    }
    return false;
}

/*-------------------------------------------------------------------------*/

bool
VFSLoadOtherDataTree( const GUCEF::CORE::CDataNode& tree    ,
                      GUCEF::CORE::CDataNode& rootnode      ,
                      const GUCEF::CORE::CString& searchstr ,
                      char sepchar                          ,
                      bool fromcurrent                      ,
                      GUCEF::CORE::CString* configfile      ,
                      GUCEF::CORE::CString* filecodec       )
{GUCE_TRACE;
        GUCEF::CORE::CString cfgFile;
        GUCEF::CORE::CString cfgFileCodec;
        if ( FindOtherDataTreeStorage( cfgFile      ,
                                       cfgFileCodec ,
                                       tree         ,
                                       searchstr    ,
                                       sepchar      ,
                                       fromcurrent  ) )
        {
                if ( configfile )
                {
                        *configfile = cfgFile;
                }
                if ( filecodec )
                {
                        *filecodec = cfgFileCodec;       
                }
                return VFSLoadDataTree( cfgFile      ,
                                        cfgFileCodec ,
                                        &rootnode    );
        }
        return false;                                                                                         
}

/*-------------------------------------------------------------------------*/

bool
VFSSaveDataTree( const GUCEF::CORE::CString& file       ,
                 const GUCEF::CORE::CString& codectype  ,
                 const GUCEF::CORE::CDataNode* rootnode )
{GUCE_TRACE;
    
    GUCEF::CORE::CDStoreCodecRegistry* codecRegistry = GUCEF::CORE::CDStoreCodecRegistry::Instance();
    if ( codecRegistry->IsRegistered( codectype ) )
    {
        GUCEF::CORE::CDStoreCodecRegistry::TDStoreCodecPtr codec = codecRegistry->Lookup( codectype );
        if ( NULL != codec )
        {
                GUCEF::VFS::CVFS* vfs = GUCEF::VFS::CVFS::Instance();                
                GUCEF::VFS::CVFS::CVFSHandlePtr fhndl = vfs->GetFile( file      , 
                                                                      "wb"      ,
                                                                      true      );
        
                if ( fhndl != NULL )
                {
                        if ( codec->StoreDataTree( rootnode           ,
                                                   fhndl->GetAccess() ) )
                        {
                                return true;        
                        }
                        return false;                        
                }
                return false;
        }
    }
    return false;    
}

/*-------------------------------------------------------------------------*/

bool
VFSLoadImage( GUCEF::CORE::CString& filename ,
              GUCEF::IMAGE::CImage& image    )
{GUCE_TRACE;

    // try to load the file            
    GUCEF::VFS::CVFS* vfs = GUCEF::VFS::CVFS::Instance();                
    GUCEF::VFS::CVFS::CVFSHandlePtr file = vfs->GetFile( filename );

    if ( NULL != file )
    {
        // Find an image codec using the file extension
        CString fileExt = filename.SubstrToChar( '.', false );

        // we have obtained the file, now try to decode it
        return image.Load( *file->GetAccess() ,
                           fileExt            );
    }
    return false;    
}

/*-------------------------------------------------------------------------*/

Ogre::TexturePtr
ImageToTexture( const CString& textureName        ,
                const CString& resourceGroup      ,
                const GUCEF::IMAGE::CImage& image )
{GUCE_TRACE;

    Ogre::Codec::DecodeResult ogreImageData = COgreImageCodecAdapter::decode( image );
    if ( !ogreImageData.second.isNull() && !ogreImageData.first.isNull() )
    {
        Ogre::ImageCodec::ImageData& imageData = static_cast< Ogre::ImageCodec::ImageData& >(*ogreImageData.second);
        Ogre::Image ogreImage;
        ogreImage.loadDynamicImage( ogreImageData.first->getPtr() ,
                                    imageData.width               ,
                                    imageData.height              ,
                                    imageData.depth               ,
                                    imageData.format              ,
                                    false                         ,
                                    1                             ,
                                    imageData.num_mipmaps         );
        
        return Ogre::TextureManager::getSingletonPtr()->loadImage( textureName   ,
                                                                   resourceGroup ,
                                                                   ogreImage     );
    }
    return Ogre::TexturePtr();
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/
