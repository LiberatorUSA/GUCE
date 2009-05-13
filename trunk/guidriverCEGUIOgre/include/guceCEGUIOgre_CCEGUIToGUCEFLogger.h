/*
 *  guceGUI: GUCE module providing GUI functionality
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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

#ifndef GUCE_CEGUIOGRE_CCEGUITOGUCEFLOGGER_H
#define GUCE_CEGUIOGRE_CCEGUITOGUCEFLOGGER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _CEGUILogger_h_
#include "CEGUILogger.h"         /* CEGUI base class for it's logging functionality */
#define _CEGUILogger_h_
#endif /* _CEGUILogger_h_ ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCE_CEGUIOGRE_MACROS_H
#include "guceCEGUIOGRE_macros.h"     /* often used guceCEGUIOGRE macros */
#define GUCE_CEGUIOGRE_MACROS_H
#endif /* GUCE_CEGUIOGRE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *  Adapter class that redirects all CEGUI logging to the GUCEF log manager
 */ 
class GUCE_CEGUIOGRE_EXPORT_CPP CCEGUIToGUCEFLogger : public CEGUI::Logger
{
    public:
    
    static CCEGUIToGUCEFLogger* Instance( void );

    /*!
    \brief
        Add an event to the log.

    \param message
        String object containing the message to be added to the event log.

    \param level
        LoggingLevel for this message.  If \a level is greater than the current set logging level, the message is not logged.

    \return
        Nothing
    */
    virtual void logEvent( const CEGUI::String& message                , 
                           CEGUI::LoggingLevel level = CEGUI::Standard );

    /*!
    \brief
        The Log output is determined in GUCEF and this function is a non-operation

    \param filename
        Name of the file to put log messages.

    \param append
        - true if events should be added to the end of the current file.
        - false if the current contents of the file should be discarded.
     */
    virtual void setLogFilename( const CEGUI::String& filename , 
                                 bool append = false           );
    
    private:
    friend class CGUCEGUIModule;
    
    static void Deinstance( void );

    private:
    
    CCEGUIToGUCEFLogger( void );
    CCEGUIToGUCEFLogger( const CCEGUIToGUCEFLogger& src );
    CCEGUIToGUCEFLogger& operator=( const CCEGUIToGUCEFLogger& src );
    virtual ~CCEGUIToGUCEFLogger();
    
    private:
    
    GUCEF::CORE::CLogManager* m_logManager;
    static CCEGUIToGUCEFLogger* g_instance;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CEGUIOGRE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CEGUIOGRE_CGUICONSOLE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 17-02-2007 :
        - Dinand: Designed and implemented this class.

-----------------------------------------------------------------------------*/