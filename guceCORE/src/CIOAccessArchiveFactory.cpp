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

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#ifndef _ArchiveManager_H__
#include "ogrearchivemanager.h"      /* Ogre archive factory manager */
#define _ArchiveManager_H__
#endif /* _ArchiveManager_H__ ? */

#include "OgreNoMemoryMacros.h" /* Don't use the Ogre memory manager */

#include "CIOAccessArchiveFactory.h" /* definition of the class implemented here */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CIOAccessArchiveFactory* CIOAccessArchiveFactory::g_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CIOAccessArchiveFactory::CIOAccessArchiveFactory( void )
    : m_archiveMap()
{GUCE_TRACE;

    Ogre::ArchiveManager::getSingleton().addArchiveFactory( this );                
}

/*-------------------------------------------------------------------------*/

CIOAccessArchiveFactory::~CIOAccessArchiveFactory()
{GUCE_TRACE;

    m_archiveMap.clear();
}

/*-------------------------------------------------------------------------*/

CIOAccessArchiveFactory* 
CIOAccessArchiveFactory::Instance( void )
{GUCE_TRACE;
        
    if ( !g_instance )
    {
        g_instance = new CIOAccessArchiveFactory();
    }
    return g_instance;
}

/*-------------------------------------------------------------------------*/

void 
CIOAccessArchiveFactory::Deinstance( void )
{GUCE_TRACE;

    delete g_instance;
    g_instance = NULL;
}

/*-------------------------------------------------------------------------*/

const Ogre::String& 
CIOAccessArchiveFactory::getType( void ) const
{GUCE_TRACE;
        
    static Ogre::String aftype = "GUCEF::CORE::CIOAccess";
    return aftype; 
}

/*-------------------------------------------------------------------------*/

Ogre::Archive* 
CIOAccessArchiveFactory::createInstance( const Ogre::String& name )
{GUCE_TRACE;

    CIOAccessArchive* archive = new CIOAccessArchive( name      , 
                                                      getType() );
    m_archiveMap[ name ] = archive;
    return archive;
}

/*-------------------------------------------------------------------------*/

void 
CIOAccessArchiveFactory::destroyInstance( Ogre::Archive* archive )
{GUCE_TRACE;
      
    m_archiveMap.erase( archive->getName().c_str() );
    delete archive;
}

/*-------------------------------------------------------------------------*/

CIOAccessArchiveFactory::TArchiveMap&
CIOAccessArchiveFactory::GetArchiveMap( void )
{GUCE_TRACE;

    return m_archiveMap;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
