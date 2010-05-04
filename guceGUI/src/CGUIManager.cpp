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

#ifndef GUCEF_GUI_CGUIMANAGER_H
#include "gucefGUI_CGUIManager.h"
#define GUCEF_GUI_CGUIMANAGER_H
#endif /* GUCEF_GUI_CGUIMANAGER_H ? */

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

namespace GUCE {
namespace GUI {

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
    SubscribeTo( GUCEF::GUI::CGUIManager::Instance() );
}

/*-------------------------------------------------------------------------*/

CGUIManager::~CGUIManager()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

const CString&
CGUIManager::GetSelectedDriverName( void ) const
{GUCE_TRACE;

    return m_selectedDriverName; 
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
    
    if ( GUCEF::GUI::CGUIManager::DriverRegisteredEvent == eventid )
    {
        // Check if the registered driver has a GUCE interface so we can use it
        // at this level. First get the information about the driver
        CString& driverName = static_cast< GUCEF::CORE::TCloneableString* >( eventdata )->GetData();
        GUCEF::GUI::CGUIDriver* basicGucefDriver = GUCEF::GUI::CGUIManager::Instance()->GetGuiDriver( driverName );        
        
        // Now get the property telling us whether its GUCE capable
        CString hasGuceInterfaceStr = basicGucefDriver->GetDriverProperty( CIGUIDriver::HasGuceInterfaceDriverProperty );
        if ( ( hasGuceInterfaceStr.Length() > 0 )                &&
             ( GUCEF::CORE::StringToBool( hasGuceInterfaceStr ) ) )
        {        
            // The newly registered driver is GUCE compatible/capable
            // We register it here for use
            CIGUIDriver& guceDriver = *static_cast< CIGUIDriver* >( basicGucefDriver );
            RegisterGUIDriver( driverName, guceDriver );
        }
    }
    else
    if ( GUCEF::GUI::CGUIManager::DriverUnregisteredEvent == eventid )
    {
        // In case the driver is registered at a GUCE level let's unregister it
        CString& driverName = static_cast< GUCEF::CORE::TCloneableString* >( eventdata )->GetData();
        UnregisterGUIDriver( driverName );
    }
    else
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
CGUIManager::Init( CORE::TWindowContextPtr& windowContext )
{GUCE_TRACE;

    if ( !m_initialized )
    {
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Initializing GUI system" );

        // Apply the loaded configuration (if any exists)
        if ( LoadConfig( m_guiConfig ) )
        {
            if ( m_drivers.size() == 0 )
            {
                GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Cannot initialize GUI system because no driver is available" ); 
                return false;
            }
            if ( m_selectedDriverName.Length() == 0 )
            {
                GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: No GUI driver specified in config: Using first available driver" ); 
                m_selectedDriverName = (*m_drivers.begin()).first;
            }
            
            TDriverMap::iterator i = m_drivers.find( m_selectedDriverName );
            if ( i != m_drivers.end() )
            {
                GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Using driver with name " + m_selectedDriverName );
                
                CIGUIDriver* driver = (*i).second;
                if ( driver->LoadConfig( m_guiConfig ) )
                {
                    if ( driver->Initialize( windowContext ) )
                    {
                        m_initialized = true;
                        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Successfully initialized the GUI system" );
                        
                        TGUIInitializedEventData eData( windowContext );
                        NotifyObservers( GUIInitializedEvent, &eData );
                        return true;
                    }
                    else
                    {
                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to initialize the GUI system driver" );
                    }
                }
                else
                {
                    GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to load the GUI system driver config" );
                }
            }
            else
            {
                GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to locate the configured GUI system driver" );
            }            
        }
        else
        {
            GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIManager: Failed to load the GUI system config" );
            return false;
        }
    }
    
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUIManager::LoadConfig( const GUCEF::CORE::CDataNode& rootNode )       
{GUCE_TRACE;             

    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_BELOW_NORMAL, "GUCE::GUI::CGUCEApplication: Loading config" );
    
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
        if ( 0 != m )
        {
            m_selectedDriverName = m->GetAttributeValue( "Driver" );
        }
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

    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "GUCE CGUIManager: registering GUI driver: " + driverName );
    
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
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "GUCE CGUIManager: unregistering GUI driver: " + driverName );        
        m_drivers.erase( i );
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} // namespace GUI
} // namespace GUCE

/*-------------------------------------------------------------------------*/
