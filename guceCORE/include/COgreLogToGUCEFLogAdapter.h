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

#ifndef GUCE_CORE_COGRELOGTOGUCEFLOGCADAPTER_H
#define GUCE_CORE_COGRELOGTOGUCEFLOGCADAPTER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef __LogManager_H__
#include "OgreLogManager.h"
#define __LogManager_H__
#endif /* __LogManager_H__ ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

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

class GUCE_CORE_EXPORT_CPP COgreLogToGUCEFLogAdapter : public Ogre::LogListener
{
    public:
    
    COgreLogToGUCEFLogAdapter( void );

    virtual ~COgreLogToGUCEFLogAdapter();

/**
    @remarks
        This is called whenever the log recieves a message and is about to write it out
    @param message
        The message to be logged
    @param lml
        The message level the log is using
    @param maskDebug
        If we are printing to the console or not
    @param logName
        the name of this log (so you can have several listeners for different logs, and identify them)
    */
    virtual void messageLogged( const Ogre::String& message , 
                                Ogre::LogMessageLevel lml   , 
                                bool maskDebug              ,
                                const Ogre::String& logName );
    
    private:
    
    COgreLogToGUCEFLogAdapter( const COgreLogToGUCEFLogAdapter& src );            /**< not implemented */
    COgreLogToGUCEFLogAdapter& operator=( const COgreLogToGUCEFLogAdapter& src ); /**< not implemented */
    
    private:
    
    GUCEF::CORE::CLogManager* m_logManager;
    Ogre::Log* m_log;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_COGRELOGTOGUCEFLOGCADAPTER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-10-2006 :
        - Initial version

-----------------------------------------------------------------------------*/