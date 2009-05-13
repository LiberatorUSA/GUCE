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

#include "COgreDataStreamToIOAccess.h"

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

COgreDataStreamToIOAccess::COgreDataStreamToIOAccess( const Ogre::DataStreamPtr& dataStream )
    : CIOAccess()                ,
      m_dataStream( dataStream ) ,
      m_isOpen( true )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

COgreDataStreamToIOAccess::~COgreDataStreamToIOAccess()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

void
COgreDataStreamToIOAccess::Open( void )
{GUCE_TRACE;

    /* n/a for Ogre streams */
}

/*-------------------------------------------------------------------------*/

void
COgreDataStreamToIOAccess::Close( void )
{GUCE_TRACE;

    m_dataStream->close();
    m_isOpen = false;
}

/*-------------------------------------------------------------------------*/

bool
COgreDataStreamToIOAccess::Opened( void ) const
{GUCE_TRACE;

    return m_isOpen;
}

/*-------------------------------------------------------------------------*/

GUCEF::CORE::CString
COgreDataStreamToIOAccess::ReadLine( void )
{GUCE_TRACE;

    return m_dataStream->getLine( false ).c_str();
}

/*-------------------------------------------------------------------------*/

GUCEF::CORE::CString
COgreDataStreamToIOAccess::ReadString( void )
{GUCE_TRACE;

    GUCEF::CORE::CString output;
    char newChar;
    
    while ( 1 == m_dataStream->read( &newChar, 1 ) )
    {
        if ( newChar != '\0' )
        {
            output += newChar;
        }
        else
        {
            return output;
        }
    }
    return output;
}

/*-------------------------------------------------------------------------*/

UInt32
COgreDataStreamToIOAccess::Read( void *dest      ,
                                 UInt32 esize    ,
                                 UInt32 elements )
{GUCE_TRACE;

    // The Ogre API returns the number of bytes read while this API
    // like the stdio API returns the number of elements read, it is
    // thus important that we convert the return value
    UInt32 bytesRead = (UInt32) m_dataStream->read( dest, esize*elements );
    return bytesRead / esize;
}

/*-------------------------------------------------------------------------*/
                         
UInt32
COgreDataStreamToIOAccess::Write( const void* srcdata ,
                                  UInt32 esize        ,
                                  UInt32 elements     )
{GUCE_TRACE;

    // Ogre streams cannot be written to
    return 0;
}

/*-------------------------------------------------------------------------*/

UInt32
COgreDataStreamToIOAccess::Tell( void ) const
{GUCE_TRACE;

    return (UInt32) m_dataStream->tell();
}

/*-------------------------------------------------------------------------*/

Int32
COgreDataStreamToIOAccess::Seek( Int32 offset ,
                                 Int32 origin )
{GUCE_TRACE;

    switch ( origin )
    {
        case SEEK_END :
        {
            m_dataStream->seek( (Int32)m_dataStream->size() - offset );
            return 0;
        }
        case SEEK_CUR :
        {
            m_dataStream->seek( (Int32)m_dataStream->tell() + offset );
            return 0;
        }
        case SEEK_SET :
        {
            m_dataStream->seek( offset );
            return 0;
        }
        default :
        {
            return -1;
        }
    } 
}

/*-------------------------------------------------------------------------*/

UInt32
COgreDataStreamToIOAccess::Setpos( UInt32 position )
{GUCE_TRACE;

    m_dataStream->seek( position ); 
    return 0;
}

/*-------------------------------------------------------------------------*/

char
COgreDataStreamToIOAccess::GetChar( void )
{GUCE_TRACE;

    char readChar = 0;
    m_dataStream->read( &readChar, 1 );
    return readChar;
}

/*-------------------------------------------------------------------------*/

bool
COgreDataStreamToIOAccess::Eof( void ) const
{GUCE_TRACE;

    return m_dataStream->eof();
}

/*-------------------------------------------------------------------------*/
    
bool
COgreDataStreamToIOAccess::IsReadable( void ) const
{GUCE_TRACE;

    return true;
}

/*-------------------------------------------------------------------------*/
    
bool
COgreDataStreamToIOAccess::IsWriteable( void ) const
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/
    
bool
COgreDataStreamToIOAccess::IsValid( void )
{GUCE_TRACE;

    return m_isOpen;
}

/*-------------------------------------------------------------------------*/
    
UInt32
COgreDataStreamToIOAccess::GetSize( void ) const
{GUCE_TRACE;

    return (UInt32) m_dataStream->size();
}

/*-------------------------------------------------------------------------*/

GUCEF::CORE::CICloneable*
COgreDataStreamToIOAccess::Clone( void ) const
{GUCE_TRACE;
    
    // Cannot be cloned
    return NULL;
}

/*-------------------------------------------------------------------------*/

void
COgreDataStreamToIOAccess::Flush( void )
{GUCE_TRACE;

    // no-op: not supported by the Ogre stream
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/