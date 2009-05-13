/*
* Copyright (C) Dinand Vanvelzen. 2002 - 2007.  All rights reserved.
*
* All source code herein is the property of Dinand Vanvelzen. You may not sell
* or otherwise commercially exploit the source or things you created based on
* the source.
*
* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL DINAND VANVELZEN BE LIABLE FOR ANY SPECIAL, INCIDENTAL, 
* INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER 
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF 
* THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT 
* OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
*/ 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <assert.h>

#ifndef GUCEF_CORE_CDVSTRING_H
#include "CDVString.h"
#define GUCEF_CORE_CDVSTRING_H
#endif /* GUCEF_CORE_CDVSTRING_H ? */

#include "guceCEGUIOgre_CCEGUIToGUCEFLogger.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CCEGUIToGUCEFLogger* CCEGUIToGUCEFLogger::g_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

CCEGUIToGUCEFLogger::CCEGUIToGUCEFLogger( void )
    : Logger()                                             ,
      m_logManager( GUCEF::CORE::CLogManager::Instance() )
{GUCE_TRACE;

    assert( m_logManager != NULL );
}

/*-------------------------------------------------------------------------*/

CCEGUIToGUCEFLogger::~CCEGUIToGUCEFLogger()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CCEGUIToGUCEFLogger*
CCEGUIToGUCEFLogger::Instance( void )
{GUCE_TRACE;

    if ( g_instance == NULL )
    {
        g_instance = new CCEGUIToGUCEFLogger();
    }
    return g_instance;
}

/*-------------------------------------------------------------------------*/

void
CCEGUIToGUCEFLogger::Deinstance( void )
{GUCE_TRACE;

    delete g_instance;
    g_instance = NULL;
}

/*-------------------------------------------------------------------------*/

void
CCEGUIToGUCEFLogger::logEvent( const CEGUI::String& message                      ,
                               CEGUI::LoggingLevel level /* = CEGUI::Standard */ )
{GUCE_TRACE;

    if ( getLoggingLevel() >= level )
    {
        static const GUCEF::CORE::CString logMsgPrefix = "[CEGUI] ";
        m_logManager->Log( GUCEF::CORE::CLogManager::LOG_SYSTEM ,
                           static_cast< Int32 >( level )        ,
                           logMsgPrefix + message.c_str()       );
    }
}

/*-------------------------------------------------------------------------*/

void
CCEGUIToGUCEFLogger::setLogFilename( const CEGUI::String& filename , 
                                     bool append /* = false */     )
{GUCE_TRACE;

    // do nothing
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CEGUIOGRE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/
