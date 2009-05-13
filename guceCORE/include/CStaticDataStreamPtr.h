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
 
#ifndef GUCE_CORE_CSTATICDATASTREAMPTR_H
#define GUCE_CORE_CSTATICDATASTREAMPTR_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef __DataStream_H__
#include "ogredatastream.h"     /* needed for Ogre DataStreamPtr typedef */
#define __DataStream_H__
#endif /* __DataStream_H__ ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"    /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *      Class that will allow you to pass a local resource as an
 *      Ogre resource. This will allow Ogre to use resources it should
 *      not delete as a resource upon destruction of the last resource pointer.
 */
class CStaticDataStreamPtr : public Ogre::DataStreamPtr
{        
        public:
        
        CStaticDataStreamPtr( void )
                : Ogre::DataStreamPtr()
        {
        }
        
        CStaticDataStreamPtr( const CStaticDataStreamPtr& src )
                : Ogre::DataStreamPtr( src )
        {
        }
        
        CStaticDataStreamPtr( const Ogre::DataStreamPtr& src )
                : Ogre::DataStreamPtr( src )
        {
        }
        
        CStaticDataStreamPtr( Ogre::DataStream* stream )
                : Ogre::DataStreamPtr( stream )
        {
        }
        
        CStaticDataStreamPtr&
        operator=( const CStaticDataStreamPtr& src )
        {
                return *this;
        }                               
        
        ~CStaticDataStreamPtr()
        {
                if ( ( *pUseCount - 1 ) == 0 )
                {
                        pRep = NULL;
                        *pUseCount = 0;
                }        
        }
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CSTATICDATASTREAMPTR_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 05-05-2005 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
