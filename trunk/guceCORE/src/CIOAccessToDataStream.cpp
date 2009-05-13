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

#ifndef CIOACCESS_H
#include "CIOAccess.h"                  /* gucefCORE base class for data streams */ 
#define CIOACCESS_H
#endif /* CIOACCESS_H ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"            /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#include "CIOAccessToDataStream.h"      /* definition of the class implemented here */

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

CIOAccessToDataStream::CIOAccessToDataStream( GUCEF::CORE::CIOAccess* access )
        : m_access( access )
{GUCE_TRACE;

    mSize = 0;
    if ( m_access != NULL )
    {
        mSize = m_access->GetSize();
    }
}

/*--------------------------------------------------------------------------*/

CIOAccessToDataStream::~CIOAccessToDataStream()
{GUCE_TRACE;

        close();
}

/*--------------------------------------------------------------------------*/

size_t 
CIOAccessToDataStream::read( void* buf    , 
                             size_t count )
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        return (size_t) m_access->Read( buf            ,
                                        1              ,
                                        (UInt32) count );
    }
    return 0;
}                             

/*--------------------------------------------------------------------------*/

size_t 
CIOAccessToDataStream::readLine( char* buf                  ,
                                 size_t maxCount            , 
                                 const Ogre::String& delim  )
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        return (size_t) m_access->ReadUntill( buf                  ,
                                              (UInt32)maxCount     ,
                                              delim.c_str()        ,
                                              (UInt32)delim.size() );
    }
    return 0;
}

/*--------------------------------------------------------------------------*/                                  

size_t 
CIOAccessToDataStream::skipLine( const Ogre::String& delim )
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        return (size_t) m_access->SkipUntill( delim.c_str()        ,
                                              (UInt32)delim.size() );     
    }
    return 0;
}

/*--------------------------------------------------------------------------*/

void 
CIOAccessToDataStream::skip( long count )
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        m_access->Setpos( m_access->Tell() + count );
    }
}

/*--------------------------------------------------------------------------*/

void 
CIOAccessToDataStream::seek( size_t pos )
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        m_access->Setpos( (UInt32)pos );
    }
}

/*--------------------------------------------------------------------------*/

size_t 
CIOAccessToDataStream::tell( void ) const
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        return (size_t) m_access->Tell();
    }
    return 0;
}

/*--------------------------------------------------------------------------*/

bool 
CIOAccessToDataStream::eof( void ) const
{GUCE_TRACE;
        
    if ( m_access != NULL )
    {
        return m_access->Eof();
    }
    return true;
}

/*--------------------------------------------------------------------------*/

void 
CIOAccessToDataStream::close( void )
{GUCE_TRACE;

    if ( m_access != NULL )
    {
        m_access->Close();
    }
}

/*--------------------------------------------------------------------------*/

void
CIOAccessToDataStream::SetAccess( GUCEF::CORE::CIOAccess* access )
{GUCE_TRACE;

    m_access = access;
}

/*--------------------------------------------------------------------------*/

GUCEF::CORE::CIOAccess*
CIOAccessToDataStream::GetAccess( void ) const
{GUCE_TRACE;

    return m_access;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
