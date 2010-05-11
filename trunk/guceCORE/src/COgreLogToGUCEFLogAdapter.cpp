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

#ifndef GUCEF_CORE_CDVSTRING_H
#include "CDVString.h"
#define GUCEF_CORE_CDVSTRING_H
#endif /* GUCEF_CORE_CDVSTRING_H ? */

#include "COgreLogToGUCEFLogAdapter.h"

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

COgreLogToGUCEFLogAdapter::COgreLogToGUCEFLogAdapter( void )
    : LogListener()                                        ,
      m_logManager( GUCEF::CORE::CLogManager::Instance() ) ,
      m_log( NULL )
{GUCE_TRACE;

    // We create the Ogre log manager before the rest ourselves
    // this way we can redirect logging to GUCEF from the start
    Ogre::LogManager* ogreLogmanager = NULL;
    if ( Ogre::LogManager::getSingletonPtr() == NULL )
    {
        ogreLogmanager = new Ogre::LogManager();
    }
    else
    {
        ogreLogmanager = Ogre::LogManager::getSingletonPtr();
    }        

    Ogre::Log* m_log = ogreLogmanager->createLog( ""   , 
                                                  true , 
                                                  true , 
                                                  true );
    m_log->addListener( this );
}

/*-------------------------------------------------------------------------*/

COgreLogToGUCEFLogAdapter::~COgreLogToGUCEFLogAdapter()
{GUCE_TRACE;

    m_log->removeListener( this );
}

/*-------------------------------------------------------------------------*/

inline
Int32
OgreMsgLvlToGUCEFMsgLvl( Ogre::LogMessageLevel lml ) 
{GUCE_TRACE;

    switch ( lml )
    {
        case Ogre::LML_TRIVIAL: return GUCEF::CORE::LOGLEVEL_BELOW_NORMAL;
        case Ogre::LML_NORMAL: return GUCEF::CORE::LOGLEVEL_NORMAL;
        case Ogre::LML_CRITICAL: return GUCEF::CORE::LOGLEVEL_CRITICAL;
        default:
        {
            return GUCEF::CORE::LOGLEVEL_NORMAL;
        }
    };
}

/*-------------------------------------------------------------------------*/

void
COgreLogToGUCEFLogAdapter::messageLogged( const Ogre::String& message , 
                                          Ogre::LogMessageLevel lml   , 
                                          bool maskDebug              ,
                                          const Ogre::String& logName )
{GUCE_TRACE;

    CString logMessage( "[OGRE] " );
    logMessage += logName.c_str();
    logMessage += message.c_str(); 
    m_logManager->Log( GUCEF::CORE::CLogManager::LOG_SYSTEM ,
                       OgreMsgLvlToGUCEFMsgLvl( lml )       ,
                       logMessage                           );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/