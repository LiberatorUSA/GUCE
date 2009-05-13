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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCE_CORE_CWINDOWCONTEXT_H
#include "CWindowContext.h"
#define GUCE_CORE_CWINDOWCONTEXT_H
#endif /* GUCE_CORE_CWINDOWCONTEXT_H ? */

#ifndef GUCE_CORE_CWINDOWMANAGER_H
#include "CWindowManager.h"
#define GUCE_CORE_CWINDOWMANAGER_H
#endif /* GUCE_CORE_CWINDOWMANAGER_H ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

#include "CGUIManager.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
GUI_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

const GUCEF::CORE::CEvent CGUIManager::GUIInitializedEvent = "GUCE::GUI::CGUIManager::GUIInitializedEvent";
CGUIManager* CGUIManager::m_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUIManager::CGUIManager( void )
        : CIConfigurable( true ) ,
          m_initialized( false ) ,
          m_drivers()            ,
          m_selectedDriverName() ,
          m_guiConfig()
{GUCE_TRACE;

    RegisterEvents();    
    SubscribeTo( CORE::CGUCEApplication::Instance() );
}

/*-------------------------------------------------------------------------*/

CGUIManager::~CGUIManager()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

 const CString&
 CGUIManager::GetClassTypeName( void ) const
 {GUCE_TRACE;
 
    static const CString typeName = "GUCE::GUI::CGUIManager";
    return typeName;
 }

/*-------------------------------------------------------------------------*/

CGUIManager* 
CGUIManager::Instance( void )
{GUCE_TRACE;

    if ( !m_instance )
    {
        m_instance = new CGUIManager();
    }
    return m_instance;
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::Deinstance( void )
{GUCE_TRACE;

    delete m_instance;
    m_instance = NULL;
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::RegisterEvents( void )
{GUCE_TRACE;

    GUIInitializedEvent.Initialize();   
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::ShutdownGUISystems( void )
{GUCE_TRACE;

    if ( m_initialized )
    {   
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Shutting down GUI system" );

        TDriverMap::iterator i = m_drivers.find( m_selectedDriverName );
        if ( i != m_drivers.end() )
        {
            CIGUIDriver* driver = (*i).second;
            driver->Shutdown();
        }
                
        m_initialized = false;
        
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Shutdown of GUI system complete" );
    }
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::OnNotify( GUCEF::CORE::CNotifier* notifier                  ,
                       const GUCEF::CORE::CEvent& eventid                ,
                       GUCEF::CORE::CICloneable* eventdata /* = NULL  */ )
{GUCE_TRACE;

    if ( CORE::CGUCEApplication::VideoSetupCompletedEvent == eventid )
    {
        if ( !Init( CORE::CGUCEApplication::Instance()->GetPrimaryWindowContext() ) )
        {
            // If the GUI module is used the GUI initialization is considered critical.
            // Failure is a terminal error
            CORE::CGUCEApplication::Instance()->Stop();
        }
    }
    else
    if ( CORE::CGUCEApplication::VideoShutdownImminentEvent == eventid )
    {
        ShutdownGUISystems();
    }
}

/*-------------------------------------------------------------------------*/

bool
CGUIManager::Init( CORE::CWindowManager::TWindowContextPtr windowContext )
{GUCE_TRACE;

    if ( !m_initialized )
    {
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Initializing GUI system" );

        /* Apply the loaded configuration (if any exists) */
        if ( LoadConfig( m_guiConfig ) )
        {
            TDriverMap::iterator i = m_drivers.find( m_selectedDriverName );
            if ( i != m_drivers.end() )
            {
                GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Using driver with name " + m_selectedDriverName );
                
                CIGUIDriver* driver = (*i).second;
                //if ( driver->LoadConfig( m_guiConfig ) )
                {
                    if ( driver->Initialize( windowContext ) )
                    {
                        m_initialized = true;
                        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Successfully initialized the GUI system" );
                        NotifyObservers( GUIInitializedEvent );
                        return true;
                    }
                    else
                    {
                        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to initialize the GUI system driver" );
                    }
                }
               // else
                {
                    //GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to load the GUI system driver config" );
                }
            }
            else
            {
                GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to locate the configured GUI system driver" );
            }            
        }
        else
        {
            GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to load the GUI system config" );
            return false;
        }
    }
    
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUIManager::LoadConfig( const GUCEF::CORE::CDataNode& rootNode )       
{GUCE_TRACE;             

    const GUCEF::CORE::CDataNode* m = NULL;
    
    if ( &m_guiConfig != &rootNode )
    {
        m = rootNode.Search( "GUCE%GUI" ,
                             '%'        ,
                             false      );

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
    
    if ( !m_initialized )
    {       
        m = m_guiConfig.Find( "CGUIManager" );
        m_selectedDriverName = m->GetAttributeValue( "Driver" );
    }
    
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUIManager::SaveConfig( GUCEF::CORE::CDataNode& tree )
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::RegisterGUIDriver( const CString& driverName ,
                                CIGUIDriver& driver       )
{GUCE_TRACE;

    m_drivers[ driverName ] = &driver;
    
    if ( m_selectedDriverName.IsNULLOrEmpty() )
    {
        m_selectedDriverName = driverName;
    }
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::UnregisterGUIDriver( const CString& driverName )
{GUCE_TRACE;

    TDriverMap::iterator i = m_drivers.find( driverName );
    if ( i != m_drivers.end() )
    {
        m_drivers.erase( i );
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUI_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
