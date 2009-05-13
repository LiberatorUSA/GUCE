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
 
#ifndef CSTATICRESOURCEPTR_H
#define CSTATICRESOURCEPTR_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _Resource_H__
#include "ogreresource.h"
#define _Resource_H__
#endif /* _Resource_H__ ? */

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
 *      Class that will allow you to pass a local recource as an
 *      Ogre recource. This will allow Ogre to use recources it should
 *      not delete as a recource uppon destruction of the last recource pointer.
 */
class CStaticResourcePtr : public Ogre::ResourcePtr
{        
        public:
        
        CStaticResourcePtr( void )
                : Ogre::ResourcePtr()
        {
        }
        
        CStaticResourcePtr( const CStaticResourcePtr& src )
                : Ogre::ResourcePtr( src )
        {
        }
        
        CStaticResourcePtr( const Ogre::ResourcePtr& src )
                : Ogre::ResourcePtr( src )
        {
        }        
        
        CStaticResourcePtr&
        operator=( const CStaticResourcePtr& src )
        {
                return *this;
        }        
        
        ~CStaticResourcePtr()
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

#endif /* CSTATICRESOURCEPTR_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 05-05-2005 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
