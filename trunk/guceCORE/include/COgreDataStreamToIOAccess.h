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

#ifndef GUCE_CORE_COGREDATASTREAMTOIOACCESS_H
#define GUCE_CORE_COGREDATASTREAMTOIOACCESS_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _ImageCodec_H__
#include "OgreImageCodec.h"      /* Ogre image codec base class */
#define _ImageCodec_H__
#endif /* _ImageCodec_H__ ? */

#ifndef GUCEF_CORE_CIOACCESS_H
#include "CIOAccess.h"           /* gucefCORE abstract I/O class */
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

/**
 *  Adapter class
 *  It allows you to use an Ogre::DataStreamPtr in places where a 
 *  GUCEF::CORE::CIOAccess is expected.
 */
class GUCE_CORE_EXPORT_CPP COgreDataStreamToIOAccess : public GUCEF::CORE::CIOAccess
{
    public:
    
    COgreDataStreamToIOAccess( const Ogre::DataStreamPtr& dataStream );
    
    virtual ~COgreDataStreamToIOAccess();
    
    /**
     *      open the resource for I/O
     */
    virtual void Open( void );

    /**
     *      close the resource
     */
    virtual void Close( void );

    /**
     *      is the resource opened for reading ?
     */
    virtual bool Opened( void ) const;

    /**
     *      read a line of text
     *      The delimiter is the platform text file line
     *      delimiter.
     */
    virtual GUCEF::CORE::CString ReadLine( void );                                  

    /**
     *      Reads a string from the resource
     */
    virtual GUCEF::CORE::CString ReadString( void );

    /**
     *      Attempts to read the specified number of bytes from the recourse
     */
    virtual UInt32 Read( void *dest      ,
                         UInt32 esize    ,
                         UInt32 elements );
                         
    /**
     *      Attempts to write the specified number of bytes to the recourse
     *      using srcdata as the data source.
     */        
    virtual UInt32 Write( const void* srcdata ,
                          UInt32 esize        ,
                          UInt32 elements     );

    /**
     *      Get the current offset in bytes
     */
    virtual UInt32 Tell( void ) const;

    /**
     *      jump to a different part of the resource
     */
    virtual Int32 Seek( Int32 offset ,
                        Int32 origin );

    /**
     *      jump to the given offset in the resource
     */
    virtual UInt32 Setpos( UInt32 position );

    /**
     *      Read a single character
     */
    virtual char GetChar( void );

    /**
     *      are we at the end of the resource ?
     */
    virtual bool Eof( void ) const;
    
    virtual bool IsReadable( void ) const;
    
    virtual bool IsWriteable( void ) const;             
    
    /**
     *      Is the access to the resource a valid one or
     *      has something gone wrong ?
     */
    virtual bool IsValid( void );
    
    /**
     *  @return returns the size of the resource if possible.
     */
    virtual UInt32 GetSize( void ) const;
    
    virtual void Flush( void );
    
    virtual GUCEF::CORE::CICloneable* Clone( void ) const;
    
    private:
    
    COgreDataStreamToIOAccess( const COgreDataStreamToIOAccess& src );            /**< not implemented */
    COgreDataStreamToIOAccess& operator=( const COgreDataStreamToIOAccess& src ); /**< not implemented */
    
    private:
    
    Ogre::DataStreamPtr m_dataStream;
    bool m_isOpen;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_COGREDATASTREAMTOIOACCESS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-10-2006 :
        - Initial version

-----------------------------------------------------------------------------*/