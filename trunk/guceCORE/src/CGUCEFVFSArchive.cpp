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

#ifndef DVCPPSTRINGUTILS_H 
#include "dvcppstringutils.h"           /* Needed for AppendToPath() */
#define DVCPPSTRINGUTILS_H
#endif /* DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCEF_CORE_CSTRINGLIST_H
#include "CStringList.h"
#define GUCEF_CORE_CSTRINGLIST_H
#endif /* GUCEF_CORE_CSTRINGLIST_H ? */

#ifndef CVFS_H
#include "CVFS.h"                       /* singleton for VFS access */
#define CVFS_H                   
#endif /* CVFS_H ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"            /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#include "CGUCEFVFSArchive.h"           /* definition of the class implemented here */

#ifndef CVFSHANDLETODATASTREAM_H
#include "CVFSHandleToDataStream.h"     /* gucefVFS handle to Ogre DataStream adapter */
#define CVFSHANDLETODATASTREAM_H
#endif /* CVFSHANDLETODATASTREAM_H ? */

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

CGUCEFVFSArchive::CGUCEFVFSArchive( const Ogre::String& name     , 
                                    const Ogre::String& archtype )
        : Ogre::Archive( name     ,
                         archtype )            ,
          _vfs( GUCEF::VFS::CVFS::Instance() )
{GUCE_TRACE;
        
}                                    

/*-------------------------------------------------------------------------*/

CGUCEFVFSArchive::~CGUCEFVFSArchive()
{GUCE_TRACE;
        
        unload();
}

/*-------------------------------------------------------------------------*/

bool 
CGUCEFVFSArchive::isCaseSensitive( void ) const
{GUCE_TRACE;
        
        return true;
}

/*-------------------------------------------------------------------------*/

void 
CGUCEFVFSArchive::load( void )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
        
void 
CGUCEFVFSArchive::unload( void )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

Ogre::DataStreamPtr 
CGUCEFVFSArchive::open( const Ogre::String& filename, bool readOnly ) const
{GUCE_TRACE;
        
    GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUCEFVFSArchive: request to open file: " +  filename );
    
    GUCEF::CORE::CString path( mName.c_str() );
    GUCEF::CORE::AppendToPath( path, filename.c_str() ); 
    
    const char* mode = readOnly ? "rb" : "rw";
    GUCEF::VFS::CVFS::CVFSHandlePtr fh = _vfs->GetFile( path, mode );
    if ( fh != NULL )
    {                                                    
            CVFSHandleToDataStream* stream = new CVFSHandleToDataStream( fh );
            return Ogre::DataStreamPtr( stream );
    }
    return Ogre::DataStreamPtr();                
}

/*-------------------------------------------------------------------------*/

Ogre::StringVectorPtr 
CGUCEFVFSArchive::list( bool recursive          , 
                        bool dirs /* = false */ )
{GUCE_TRACE;
        
    Ogre::StringVector* strvec( new Ogre::StringVector() );
    Ogre::StringVectorPtr ptr( strvec );
    GUCEF::VFS::CVFS::TStringSet list;
    _vfs->GetList( list, mName.c_str(), recursive, false );
    GUCEF::VFS::CVFS::TStringSet::iterator i = list.begin();
    while ( i != list.end() )
    {
        strvec->push_back( (*i) );
        ++i;
    }                        
    return ptr;
}

/*-------------------------------------------------------------------------*/

Ogre::FileInfoListPtr 
CGUCEFVFSArchive::listFileInfo( bool recursive          ,
                                bool dirs /* = false */ )
{GUCE_TRACE;
        
    Ogre::FileInfoList* fileInfoList = new Ogre::FileInfoList;
    return Ogre::FileInfoListPtr( fileInfoList );
}

/*-------------------------------------------------------------------------*/

Ogre::StringVectorPtr 
CGUCEFVFSArchive::find( const Ogre::String& pattern , 
                        bool recursive              ,
                        bool dirs /* = false */     )
{GUCE_TRACE;
                        
    Ogre::StringVector* strvec( new Ogre::StringVector() );
    Ogre::StringVectorPtr ptr( strvec );
    GUCEF::VFS::CVFS::TStringSet list;
    _vfs->GetList( list, mName.c_str(), recursive, false, pattern.c_str() );
    GUCEF::VFS::CVFS::TStringSet::iterator i = list.begin();
    while ( i != list.end() )
    {
        strvec->push_back( (*i) );
        ++i;
    }                        
    return ptr;
}

/*-------------------------------------------------------------------------*/                        

Ogre::FileInfoListPtr 
CGUCEFVFSArchive::findFileInfo( const Ogre::String& pattern , 
                                bool recursive              ,
                                bool dirs /* = false */     )
{GUCE_TRACE;
    
    Ogre::FileInfoList* fileInfoList = new Ogre::FileInfoList();
    GUCEF::VFS::CVFS::TStringSet list;
    _vfs->GetList( list, mName.c_str(), recursive, true, pattern.c_str() );
    GUCEF::VFS::CVFS::TStringSet::iterator i = list.begin();
    while ( i != list.end() )
    {
        Ogre::FileInfo fileInfo;
        fileInfo.archive = this;
        fileInfo.filename = (*i);
        fileInfo.path = GUCEF::CORE::StripFilename( (*i) );
        fileInfo.basename = GUCEF::CORE::ExtractFilename( (*i) );
        fileInfo.uncompressedSize = _vfs->GetFileSize( (*i) );
        fileInfo.compressedSize = fileInfo.uncompressedSize;
        fileInfoList->push_back( fileInfo );
        ++i;
    }
    return Ogre::FileInfoListPtr( fileInfoList );
}

/*-------------------------------------------------------------------------*/                                

bool 
CGUCEFVFSArchive::exists( const Ogre::String& filename )
{GUCE_TRACE;
        
    GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUCEFVFSArchive: request if file exists: " +  filename );        
    return _vfs->FileExists( filename.c_str() );
}

/*-------------------------------------------------------------------------*/

time_t
CGUCEFVFSArchive::getModifiedTime( const Ogre::String& filename )
{GUCE_TRACE;

    GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUCEFVFSArchive: request for file modification time: " +  filename );    
    return _vfs->GetFileModificationTime( filename.c_str() );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
