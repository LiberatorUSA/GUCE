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
 
#ifndef GUCE_CORE_CIOACCESSTODATASTREAM_H
#define GUCE_CORE_CIOACCESSTODATASTREAM_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/ 

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#ifndef __DataStream_H__ 
#include "OgreDataStream.h"      /* Ogre base class for data streams */
#define __DataStream_H__
#endif /* __DataStream_H__ ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF { namespace CORE { class CIOAccess; } }

/*-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP CIOAccessToDataStream : public Ogre::DataStream
{
    public:
    
    CIOAccessToDataStream( GUCEF::CORE::CIOAccess* access );
    
    virtual ~CIOAccessToDataStream();
    
    virtual size_t read( void* buf    , 
                         size_t count );

    virtual size_t readLine( char* buf                        ,
                             size_t maxCount                  , 
                             const Ogre::String& delim = "\n" );

    virtual size_t skipLine( const Ogre::String& delim = "\n" );

    virtual void skip( long count );

    virtual void seek( size_t pos );

    virtual size_t tell( void ) const;

    virtual bool eof( void ) const;

    virtual void close( void );
    
    protected:

    void SetAccess( GUCEF::CORE::CIOAccess* access );
    
    GUCEF::CORE::CIOAccess* GetAccess( void ) const;
    
    private:
    
    GUCEF::CORE::CIOAccess* m_access;        
    
    private:
    CIOAccessToDataStream( void );                                        /**< not implemented */
    CIOAccessToDataStream( const CIOAccessToDataStream& src );            /**< not implemented */
    CIOAccessToDataStream& operator=( const CIOAccessToDataStream& src ); /**< not implemented */       
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CIOACCESSTODATASTREAM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
