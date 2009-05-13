/*
 *  guceCEGUIOgre: glue module for the CEGUI+Ogre GUI backend
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
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

#include <MyGUI.h>

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

#ifndef GUCEF_CORE_CDATANODE_H
#include "CDataNode.h"
#define GUCEF_CORE_CDATANODE_H
#endif /* GUCEF_CORE_CDATANODE_H ? */

#ifndef GUCE_GUI_CGUIMANAGER_H
#include "CGUIManager.h"
#define GUCE_GUI_CGUIMANAGER_H
#endif /* GUCE_GUI_CGUIMANAGER_H ? */

#ifndef GUCE_CORE_CWINDOWMANAGER_H
#include "CWindowManager.h"
#define GUCE_CORE_CWINDOWMANAGER_H
#endif /* GUCE_CORE_CWINDOWMANAGER_H ? */

#ifndef GUCE_MYGUIOGRE_CMYGUIINPUTADAPTER_H
#include "guceMyGUIOgre_CMyGUIInputAdapter.h"
#define GUCE_MYGUIOGRE_CMYGUIINPUTADAPTER_H
#endif /* GUCE_MYGUIOGRE_CMYGUIINPUTADAPTER_H ? */

#include "guceMyGUIOgre_CGUIDriver.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace MYGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUIDriver* CGUIDriver::g_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUIDriver::CGUIDriver( void )
    : CIGUIDriver()           ,
      m_initialized( false )  ,
      m_window( NULL )        ,
      m_guiSystem( NULL )     ,
      m_inputAdapter( NULL )  ,
      m_guiConfig()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CGUIDriver::~CGUIDriver()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CGUIDriver* 
CGUIDriver::Instance( void )
{GUCE_TRACE;

    if ( NULL == g_instance )
    {
        g_instance = new CGUIDriver();
    }
    return g_instance;
}

/*-------------------------------------------------------------------------*/

void
CGUIDriver::Deinstance( void )
{GUCE_TRACE;

    delete g_instance;
    g_instance = NULL;
}

/*-------------------------------------------------------------------------*/

bool
CGUIDriver::Shutdown( void )
{GUCE_TRACE;

    if ( m_initialized )
    {   
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIDriver: Shutting down CEGUI system" );
        
        delete m_guiSystem;
        m_guiSystem = NULL;
       
        m_window = NULL;        
        m_initialized = false;
        
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIDriver: Shutdown of CEGUI system complete" );
    }
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUIDriver::Initialize( CORE::CWindowManager::TWindowContextPtr windowContext )
{GUCE_TRACE;

    if ( !m_initialized )
    {
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIDriver: Initializing GUI system" );
        
        try
        {
            assert( windowContext != NULL );
            m_window = windowContext->GetOgreWindowPtr();                
            assert( m_window != NULL );
            
            //MyGUI::LogManager::initialise();
            
            m_guiSystem = new MyGUI::Gui();
            m_guiSystem->initialise( m_window, "core.xml", "GUI" );
        }
        catch ( Ogre::Exception& e )
        {
            GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_CRITICAL, "CGUIDriver: Exception while initializing the GUI system: " + e.getFullDescription() );
            return false;
        }            

        /* feed MyGUI with input events */
        m_inputAdapter = new CMyGUIInputAdapter( m_guiSystem );
    
        m_initialized = true;

        /* Apply the loaded configuration (if any exists) */
        if ( LoadConfig( m_guiConfig ) )
        {
            GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIDriver: Successfully initialized the GUI system" );
            return true;
        }
        else
        {
            GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIDriver: Failed to initialize the GUI system" );
            return false;
        }
    }
    
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUIDriver::LoadConfig( const GUCEF::CORE::CDataNode& rootNode )       
{GUCE_TRACE;             

    const GUCEF::CORE::CDataNode* m = NULL;
    
    if ( &m_guiConfig != &rootNode )
    {
        m = rootNode.Find( "MyGUI" );

        if ( m != NULL )
        {
            m_guiConfig.ClearAttributes();
            m_guiConfig.DelSubTree();
            m_guiConfig.Copy( *m );
        }
        else
        {
            return false;
        }
    }
    else
    {
        m = &m_guiConfig;
    }
    
    if ( m_initialized )
    {       

    }
    
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUIDriver::SaveConfig( GUCEF::CORE::CDataNode& tree )
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace MYGUIOGRE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/
