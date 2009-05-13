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

/*
 *      This file houses a collection of utilty functions that simply 
 *      concatonise common operations to save some effort.
 */

#ifndef GUCE_CORE_MISCUTILS_H
#define GUCE_CORE_MISCUTILS_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"      /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class TexturePtr; }
namespace GUCEF { namespace CORE { class CDataNode; class CIOAccess; }
                  namespace IMAGE { class CImage; } };

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_CORE_EXPORT_CPP GUCEF::CORE::CString
Create2DTextureMaterialScript( const GUCEF::CORE::CString& materialname ,
                               const GUCEF::CORE::CString& texfilename  );
                             
/*-------------------------------------------------------------------------*/

GUCE_CORE_EXPORT_CPP GUCEF::CORE::CString
Create2DTextureMaterialScript( const GUCEF::CORE::CString& materialname ,
                               const GUCEF::CORE::CString& texfilename  ,
                               Int32 mipmaplevels                       );
                             
/*-------------------------------------------------------------------------*/

GUCE_CORE_EXPORT_CPP bool
RegisterScriptMaterial( const GUCEF::CORE::CString& script        ,
                        const GUCEF::CORE::CString& resourcegroup );

/*-------------------------------------------------------------------------*/

/**
 *  Attempts to load a data tree from the file given using the codec type
 *  specified
 */
GUCE_CORE_EXPORT_CPP bool
LoadDataTree( GUCEF::CORE::CIOAccess& file          ,
              const GUCEF::CORE::CString& codectype ,
              GUCEF::CORE::CDataNode* rootnode      );
                        
/*-------------------------------------------------------------------------*/

/**
 *      Attempts to load the given file with the given codec type and
 *      build a data tree from the data in the file. The VFS is used to obtain 
 *      the file.
 */
GUCE_CORE_EXPORT_CPP bool
VFSLoadDataTree( const GUCEF::CORE::CString& file      ,
                 const GUCEF::CORE::CString& codectype ,
                 GUCEF::CORE::CDataNode* rootnode      );
                 
/*-------------------------------------------------------------------------*/

/**
 *      Attempts to find the end-node specified with the search
 *      string query in the given tree. If the node is found 
 *      an attempt will be made to get the attributes
 *      "configfile" and "filecodec". If successfull the retrieved 
 *      attribute values will then be used to load the other 
 *      data tree using VFSLoadDataTree()
 *
 *      @param tree input var: the currently loaded data tree, this is the tree that will be searched
 *      @param rootnode output var: the rootnode that will be assigned the entire newly loaded data tree
 *      @param searchstr the query string used to find the node containg the file info we need
 *      @param sepchar char used to seperate node tags
 *      @param fromcurrent wheter the query structure must start at the given root node
 *      @param configfile output var: if non-NULL it will be assigned the value found for attribute "configfile"
 *      @param filecodec output var: if non-NULL it will be assigned the value found for attribute "filecodec" 
 *
 */
GUCE_CORE_EXPORT_CPP bool
VFSLoadOtherDataTree( const GUCEF::CORE::CDataNode& tree      ,
                      GUCEF::CORE::CDataNode& rootnode        ,
                      const GUCEF::CORE::CString& searchstr   ,
                      char sepchar      = '%'                 ,
                      bool fromcurrent  = true                ,
                      GUCEF::CORE::CString* configfile = NULL ,
                      GUCEF::CORE::CString* filecodec  = NULL );                 

/*-------------------------------------------------------------------------*/

/**
 *      Attempts to save the given data tree to the file with the given path 
 *      with the given codec type. The VFS is used to save the data.
 * 
 *      Note that if a file already exists with the given name it will be overwritten !!!
 */
GUCE_CORE_EXPORT_CPP bool
VFSSaveDataTree( const GUCEF::CORE::CString& file       ,
                 const GUCEF::CORE::CString& codectype  ,
                 const GUCEF::CORE::CDataNode* rootnode );

/*-------------------------------------------------------------------------*/

/**
 *      Attempts to retrieve a filename and codec type string using the
 *      given searchstring and seperation char.
 */
GUCE_CORE_EXPORT_CPP bool
FindOtherDataTreeStorage( GUCEF::CORE::CString& configfile      ,
                          GUCEF::CORE::CString& filecodec       ,
                          const GUCEF::CORE::CDataNode& tree    ,
                          const GUCEF::CORE::CString& searchstr ,                          
                          char sepchar      = '%'               ,
                          bool fromcurrent  = true              );

/*-------------------------------------------------------------------------*/

/**
 *  Attempts to load an image from the file indicated using the VFS
 */
GUCE_CORE_EXPORT_CPP bool
VFSLoadImage( GUCEF::CORE::CString& filename ,
              GUCEF::IMAGE::CImage& image    );

/*-------------------------------------------------------------------------*/

GUCE_CORE_EXPORT_CPP Ogre::TexturePtr
ImageToTexture( const CString& textureName        ,
                const CString& resourceGroup      ,
                const GUCEF::IMAGE::CImage& image );

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_MISCUTILS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 05-05-2005 :
        - Created CreateTextureMaterialScript().

-----------------------------------------------------------------------------*/
