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

#ifndef GUCE_CORE_CIOACCESSTODATASTREAM_H
#include "CIOAccessToDataStream.h"
#define GUCE_CORE_CIOACCESSTODATASTREAM_H
#endif /* GUCE_CORE_CIOACCESSTODATASTREAM_H ? */

#include "CIOAccessArchive.h"

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

CIOAccessArchive::CIOAccessArchive( const Ogre::String& name     , 
                                    const Ogre::String& archtype )
    : Ogre::Archive( name     ,
                     archtype )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
                      
CIOAccessArchive::~CIOAccessArchive()
{GUCE_TRACE;

    ClearResourceList();
}

/*-------------------------------------------------------------------------*/
    
bool
CIOAccessArchive::AddResource( GUCEF::CORE::CIOAccess& resource ,
                               const CString& filename          )
{GUCE_TRACE;

    m_resourceMap[ filename ] = &resource;
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CIOAccessArchive::RemoveResource( GUCEF::CORE::CIOAccess& resource )
{GUCE_TRACE;

    TResourceMap::iterator i = m_resourceMap.begin();
    while ( i != m_resourceMap.end() )
    {
        if ( (*i).second == &resource )
        {
            m_resourceMap.erase( i );
            return true;
        }
        ++i;
    }
    return false;
}
    
/*-------------------------------------------------------------------------*/

bool
CIOAccessArchive::RemoveResource( const CString& filename )
{GUCE_TRACE;

    m_resourceMap.erase( filename );
    return true;
}

/*-------------------------------------------------------------------------*/

void
CIOAccessArchive::ClearResourceList( void )
{GUCE_TRACE;

    m_resourceMap.clear();
}

/*-------------------------------------------------------------------------*/

bool
CIOAccessArchive::isCaseSensitive( void ) const
{GUCE_TRACE;

    return true;
}

/*-------------------------------------------------------------------------*/

void
CIOAccessArchive::load( void )
{GUCE_TRACE;

    // do nothing
}

/*-------------------------------------------------------------------------*/

void
CIOAccessArchive::unload( void )
{GUCE_TRACE;

    // do nothing
}

/*-------------------------------------------------------------------------*/

Ogre::DataStreamPtr
CIOAccessArchive::open( const Ogre::String& filename ) const
{GUCE_TRACE;

    TResourceMap::const_iterator i = m_resourceMap.find( filename.c_str() );
    if ( i != m_resourceMap.end() )
    {
        return Ogre::DataStreamPtr( new CIOAccessToDataStream( (*i).second ) );
    }
    
    return Ogre::DataStreamPtr();
}

/*-------------------------------------------------------------------------*/

Ogre::StringVectorPtr
CIOAccessArchive::list( bool recursive , 
                        bool dirs      )
{GUCE_TRACE;

    Ogre::StringVector* fileList = new Ogre::StringVector();
    TResourceMap::iterator i = m_resourceMap.begin();
    while ( i != m_resourceMap.end() )
    {
        fileList->push_back( (*i).first );
        ++i;
    }
    return Ogre::StringVectorPtr( fileList );    
}

/*-------------------------------------------------------------------------*/

Ogre::FileInfoListPtr
CIOAccessArchive::listFileInfo( bool recursive ,
                                bool dirs      )
{GUCE_TRACE;

    Ogre::FileInfo fileInfo;
    fileInfo.archive = this;
    
    Ogre::FileInfoList* fileInfoList = new Ogre::FileInfoList();
    TResourceMap::iterator i = m_resourceMap.begin();
    while ( i != m_resourceMap.end() )
    {
        fileInfo.basename = fileInfo.filename = (*i).first.C_String();
        fileInfo.compressedSize = fileInfo.uncompressedSize = (size_t) (*i).second->GetSize();
        fileInfoList->push_back( fileInfo );
        ++i;
    }
    return Ogre::FileInfoListPtr( fileInfoList );    
}

/*-------------------------------------------------------------------------*/

Ogre::StringVectorPtr
CIOAccessArchive::find( const Ogre::String& pattern , 
                        bool recursive              ,
                        bool dirs                   )
{GUCE_TRACE;

    // @TODO make this
    return Ogre::StringVectorPtr( new Ogre::StringVector() );
}

/*-------------------------------------------------------------------------*/

Ogre::FileInfoListPtr
CIOAccessArchive::findFileInfo( const Ogre::String& pattern , 
                                bool recursive              ,
                                bool dirs                   )
{GUCE_TRACE;

    // @TODO make this
    return Ogre::FileInfoListPtr( new Ogre::FileInfoList() );
}

/*-------------------------------------------------------------------------*/

bool
CIOAccessArchive::exists( const Ogre::String& filename )
{GUCE_TRACE;

    return m_resourceMap.end() != m_resourceMap.find( filename.c_str() );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE ? */
}; /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/
