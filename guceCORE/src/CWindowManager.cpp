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

#include <assert.h>

#ifndef __ROOT__
#include <OgreRoot.h>           /* most basic Ogre class */ 
#define __ROOT__
#endif /* __ROOT__ ?  */

#ifndef __RenderSystem_H_
#include <OgreRenderSystem.h>   /* Ogre render system: abstract base */
#define __RenderSystem_H_
#endif /* __RenderSystem_H_ ? */

#ifndef __MATERIALMANAGER_H__
#include <OgreMaterialManager.h>
#define __MATERIALMANAGER_H__
#endif /* __MATERIALMANAGER_H__ ? */

#ifndef __RenderWindow_H__
#include <OgreRenderWindow.h>   /* Ogre rendering window */
#define __RenderWindow_H__
#endif /* __RenderWindow_H__ ? */

#ifndef CINPUTCONTROLLER_H
#include "CInputController.h"   /* platform input context controller */
#define CINPUTCONTROLLER_H
#endif /* CINPUTCONTROLLER_H ? */

#ifndef CVALUELIST_H
#include "CValueList.h"          /* key-value combo list */ 
#define CVALUELIST_H
#endif /* CVALUELIST_H ? */

#ifndef CDATANODE_H
#include "CDataNode.h"           /* data storage tree*/ 
#define CDATANODE_H
#endif /* CDATANODE_H ? */

#ifndef DVSTRUTILS_H
#include "dvstrutils.h"
#define DVSTRUTILS_H
#endif /* DVSTRUTILS_H ? */

#ifndef DVOSWRAP_H
#include "dvoswrap.h"
#define DVOSWRAP_H
#endif /* DVOSWRAP_H ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

#ifndef CIWINDOWCONTEXTHANDLER_H
#include "CIWindowContextHandler.h"     /* interface class for a window context event handler */
#define CIWINDOWCONTEXTHANDLER_H
#endif /* CIWINDOWCONTEXTHANDLER_H ? */

#ifndef GUCE_CORE_CVIDEOSETTINGS_H
#include "guceCORE_CVideoSettings.h"
#define GUCE_CORE_CVIDEOSETTINGS_H
#endif /* GUCE_CORE_CVIDEOSETTINGS_H ? */

#include "CWindowManager.h"      /* definition of the class implemented here */

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#ifdef GUCE_MSWIN_BUILD
  #ifndef GUCEF_CORE_CWNDMSGHOOKNOTIFIER_H
  #include "CWndMsgHookNotifier.h"
  #define GUCEF_CORE_CWNDMSGHOOKNOTIFIER_H
  #endif /* GUCEF_CORE_CWNDMSGHOOKNOTIFIER_H ? */
#endif

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

const GUCEF::CORE::CEvent CWindowManager::PrimaryWindowContextCreatedEvent = "GUCE::CORE::CWindowManager::PrimaryWindowContextCreatedEvent";
const GUCEF::CORE::CEvent CWindowManager::PrimaryWindowContextDestroyedEvent = "GUCE::CORE::CWindowManager::PrimaryWindowContextDestroyedEvent";
const GUCEF::CORE::CEvent CWindowManager::WindowContextCreatedEvent = "GUCE::CORE::CWindowManager::WindowContextCreatedEvent";
const GUCEF::CORE::CEvent CWindowManager::WindowContextDestroyedEvent = "GUCE::CORE::CWindowManager::WindowContextDestroyedEvent";

CWindowManager* CWindowManager::m_instance = NULL;
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CWindowManager::CWindowManager( void )
    : CObservingNotifier()                 ,
      m_windowlist()                       ,
      m_osWindowLink( NULL )               ,
      m_busyChangingVideoSettings( false )
{GUCE_TRACE;

    RegisterEvents();
    
    SubscribeTo( &GUCEF::CORE::CGUCEFApplication::Instance()->GetPulseGenerator() ,
                 GUCEF::CORE::CPulseGenerator::PulseEvent                         ,
                 &TEventCallback( this, &CWindowManager::OnPulse )                );
    
    #ifdef GUCEF_MSWIN_BUILD
    GUCEF::CORE::CWndMsgHookNotifier* wndMsgNotifier = new GUCEF::CORE::CWndMsgHookNotifier();
    m_osWindowLink = wndMsgNotifier; 
    SubscribeTo( wndMsgNotifier );
    #endif /* GUCEF_MSWIN_BUILD ? */
}

/*-------------------------------------------------------------------------*/

CWindowManager::~CWindowManager()
{GUCE_TRACE;

    #ifdef GUCEF_MSWIN_BUILD
    delete static_cast< GUCEF::CORE::CWndMsgHookNotifier* >( m_osWindowLink );
    m_osWindowLink = NULL;
    #endif /* GUCEF_MSWIN_BUILD ? */
}

/*-------------------------------------------------------------------------*/

CWindowManager* 
CWindowManager::Instance( void )
{GUCE_TRACE;
        if ( !m_instance )
        {
                m_instance = new CWindowManager();
        }
        return m_instance;
}

/*-------------------------------------------------------------------------*/

void
CWindowManager::Deinstance( void )
{GUCE_TRACE;
        delete m_instance;
        m_instance = NULL;
}

/*-------------------------------------------------------------------------*/

void
CWindowManager::RegisterEvents( void )
{GUCE_TRACE;

    PrimaryWindowContextCreatedEvent.Initialize();
    PrimaryWindowContextDestroyedEvent.Initialize();
    WindowContextCreatedEvent.Initialize();
    WindowContextDestroyedEvent.Initialize();
}

/*-------------------------------------------------------------------------*/

void
CWindowManager::OnPulse( GUCEF::CORE::CNotifier* notifier                 ,
                         const GUCEF::CORE::CEvent& eventid               ,
                         GUCEF::CORE::CICloneable* eventdata /* = NULL */ )
{GUCE_TRACE;
    
    // Decode and treat the messages
    // as long as the application is running
    #ifdef GUCEF_MSWIN_BUILD
    MSG Msg;
    while( 0 != PeekMessage( &Msg, NULL, 0, 0, PM_REMOVE ) )
    {
        DispatchMessage( &Msg );
    }
    #endif /* GUCEF_MSWIN_BUILD ? */ 
}

/*-------------------------------------------------------------------------*/

void
CWindowManager::OnNotify( GUCEF::CORE::CNotifier* notifier                 ,
                          const GUCEF::CORE::CEvent& eventid               ,
                          GUCEF::CORE::CICloneable* eventdata /* = NULL */ )
{GUCE_TRACE;

    CObservingNotifier::OnNotify( notifier  ,
                                  eventid   ,
                                  eventdata );

    #ifdef GUCEF_MSWIN_BUILD
    if ( notifier == m_osWindowLink )
    {
        if ( GUCEF::CORE::CWndMsgHookNotifier::WindowActivationEvent == eventid )
        {
            GUCEF::CORE::CWndMsgHookNotifier::SWindowActivationEventData& eData = static_cast< GUCEF::CORE::CWndMsgHookNotifier::TWindowActivationEventData* >( eventdata )->GetData();
            CWindowContext* context = static_cast< CWindowContext* >( eData.userData );
            
            if ( context != NULL )
            {
                context->SetActive( eData.windowActiveState );                              
            }
        }
        else
        if ( GUCEF::CORE::CWndMsgHookNotifier::WindowSizeEvent == eventid )
        {
            GUCEF::CORE::CWndMsgHookNotifier::SWindowSizeEventData& eData = static_cast< GUCEF::CORE::CWndMsgHookNotifier::TWindowSizeEventData* >( eventdata )->GetData();
            CWindowContext* context = static_cast< CWindowContext* >( eData.userData );        
            
            if ( context != NULL )
            {
                context->SetActive( eData.windowVisible );                        
                context->OnWindowContextSize( eData.windowWidth  ,
                                              eData.windowHeight );

            }            
        }
        else
        if ( GUCEF::CORE::CWndMsgHookNotifier::WindowDestroyEvent == eventid )
        {
            void* userData = static_cast< GUCEF::CORE::CWndMsgHookNotifier::TWindowDestroyEventData* >( eventdata )->GetData();
            CWindowContext* context = static_cast< CWindowContext* >( userData );
            DestroyWindowContextImp( context );
        }
    }
    #endif /* GUCEF_MSWIN_BUILD ? */
}

/*-------------------------------------------------------------------------*/
        
CWindowManager::TWindowContextPtr
CWindowManager::CreateWindowContext( const GUCEF::CORE::CDataNode& params       ,
                                     const CString& title          /* = "" */   )
{GUCE_TRACE;

    try
    {        
        /*
         *      Attempt to get all the info for the preferred window setup
         */                
        const GUCEF::CORE::CDataNode* n = params.Find( "WindowSettings" );
        if ( n )
        {
            const GUCEF::CORE::CDataNode::TKeyValuePair* att;
            UInt32 width( 640 ), height( 480 );
            bool fullscreen( false );                        
            
            att = n->GetAttribute( "width" );
            if ( att ) width = att->second.GetInt();
            att = n->GetAttribute( "height" );        
            if ( att ) height = att->second.GetInt();
            att = n->GetAttribute( "fullscreen" );
            if ( att ) fullscreen = GUCEF::CORE::String_To_Boolint( att->second.C_String() ) == 1;
            
            const GUCEF::CORE::CDataNode::TKeyValuePair* att2;
            const GUCEF::CORE::CString name( "name" );
            const GUCEF::CORE::CString value( "value" );
            Ogre::NameValuePairList valuelist;
            const GUCEF::CORE::CDataNode* cn;
            GUCEF::CORE::CDataNode::const_iterator i = n->ConstBegin();
            while ( i != n->ConstEnd() )
            {
                cn = (*i);
                if ( cn->GetName() == "WindowSetting" )
                {
                    att = cn->GetAttribute( name );
                    if ( att )
                    {
                        att2 = cn->GetAttribute( value );
                        if ( att2 )
                        {
                                valuelist[ att->second.C_String() ] = att2->second.C_String();
                        }        
                    }
                }
                ++i;
            }
            if ( title.Length() > 0 )
            {
                valuelist[ "title" ] = title.C_String();
            }                                        
                                    
            return CreateWindowContext( title         ,
                                        width         ,
                                        height        ,
                                        fullscreen    ,                                                       
                                        valuelist     );                                          
        }
        return NULL;
    }
    catch ( Ogre::Exception& )
    {
            return NULL;
    }                
}

/*-------------------------------------------------------------------------*/

CWindowManager::TWindowContextPtr 
CWindowManager::CreateWindowContext( const CString& title ,
                                     const UInt32 width   ,
                                     const UInt32 height  ,
                                     bool fullscreen      )
{GUCE_TRACE;
        
        Ogre::NameValuePairList valuelist;
        return CreateWindowContext( title         ,
                                    width         ,
                                    height        ,
                                    fullscreen    ,
                                    valuelist     );
}

/*-------------------------------------------------------------------------*/

CWindowManager::TWindowContextPtr 
CWindowManager::CreateWindowContext( const CString& title                  ,
                                     const UInt32 width                    ,
                                     const UInt32 height                   ,
                                     const bool fullscreen                 ,
                                     const Ogre::NameValuePairList& params )
{GUCE_TRACE;
    try
    {                        
        Ogre::RenderWindow* window( NULL );
        Ogre::Root* ogreroot = Ogre::Root::getSingletonPtr();
        if ( m_windowlist.empty() )
        {
                ogreroot->initialise( false );                                                
        }                                
        window = ogreroot->getRenderSystem()->_createRenderWindow( title.C_String() , 
                                                                   width            ,
                                                                   height           ,
                                                                   fullscreen       ,
                                                                   &params          );    
        window->setAutoUpdated( true );                               
        
        /*
         *      Now we create an input context that can be linked to the window
         */
        GUCEF::CORE::CValueList inputparams;
        
        #ifdef GUCE_MSWIN_BUILD
        
        // For MS Windows we will add the window handle to the input context parameters
        UInt32 whandle = 0;
        window->getCustomAttribute( "WINDOW", &whandle );
        inputparams.Set( "WINDOW" , GUCEF::CORE::UInt32ToString( whandle ) );
        
        #endif /* GUCE_MSWIN_BUILD ? */
        
        inputparams.Set( "WINDOW_WIDTH", GUCEF::CORE::UInt32ToString( window->getWidth() ) );
        inputparams.Set( "WINDOW_HEIGHT", GUCEF::CORE::UInt32ToString( window->getHeight() ) );
        
        GUCEF::INPUT::CInputContext* icontext( GUCEF::INPUT::CInputController::Instance()->CreateContext( inputparams ) );                        
        if ( NULL == icontext )
        {
                ogreroot->getRenderSystem()->destroyRenderWindow( window->getName() );                        
                return NULL;
        }
        
        /*
         *      Now last but not least we create our window context and fill in the data
         */
        TWindowContextPtr wcontext( new CWindowContext( window          ,
                                                        icontext        ) ,
                                    this                                  );
                        
        if ( m_windowlist.empty() || window->isPrimary() )
        {
            #ifdef GUCE_MSWIN_BUILD
            // Set handle to the primary window
            GUCEF::CORE::GUCEFSetEnv( "WINDOW", GUCEF::CORE::UInt32ToString( whandle ).C_String() );
            #endif /* GUCE_MSWIN_BUILD ? */
                            
            Ogre::MaterialManager::getSingletonPtr()->initialise();
        }
        
        /*
         *      For MS Windows we should set the HWND env var
         *      and proxy the msg handling so we can trap
         *      WM_ACTIVATE
         */
        #ifdef GUCE_MSWIN_BUILD 
        static_cast< GUCEF::CORE::CWndMsgHookNotifier* >( m_osWindowLink )->Hook( (const HWND) whandle, wcontext.GetPointer() );
        #endif /* GUCE_MSWIN_BUILD ? */

        //@todo: shove in empty slot or change mechanism
        m_windowlist.push_back( wcontext );
        wcontext->SetID( (UInt32)m_windowlist.size()-1 );                
        
        TWindowContextCreatedEventData eData( wcontext );
        if ( window->isPrimary() )
        {
            NotifyObservers( PrimaryWindowContextCreatedEvent, &eData );
        }
        NotifyObservers( WindowContextCreatedEvent, &eData );
        
        return wcontext; 
    }                                                                              
    catch ( Ogre::Exception& )
    {
            return NULL;
    }                               
}

/*-------------------------------------------------------------------------*/

CWindowManager::TWindowContextPtr 
CWindowManager::CreateWindowContext( const CString& title                  ,
                                     const CVideoSettings& settings        ,
                                     const Ogre::NameValuePairList* params )
{GUCE_TRACE;

    Ogre::NameValuePairList xtraParams;
    if ( NULL != params )
    {
        xtraParams = *params;
    }
    
    xtraParams[ "vsync" ] = GUCEF::CORE::BoolToString( settings.GetVSyncState() );
    xtraParams[ "FSAA" ] = GUCEF::CORE::UInt32ToString( settings.GetAntiAliasingFactor() );
    return CreateWindowContext( title                                  ,
                                settings.GetResolutionWidthInPixels()  ,
                                settings.GetResolutionHeightInPixels() ,
                                settings.GetFullscreenState()          ,
                                xtraParams                             );
}

/*-------------------------------------------------------------------------*/

void
CWindowManager::DestroyWindowContext( TWindowContextPtr& windowContext )
{GUCE_TRACE;

    // If there is only 1 outstanding reference left the destroy will be called
    // when the shared pointer is no longer referenced. Thats why we need this check
    if ( windowContext.GetReferenceCount() > 1 )
    {
        DestroyWindowContextImp( windowContext.GetPointer() );
    }

    windowContext = NULL;
}

/*-------------------------------------------------------------------------*/

void
CWindowManager::DestroyWindowContextImp( CWindowContext* windowContext )
{GUCE_TRACE;

    Ogre::RenderWindow* renderWindow = windowContext->GetOgreWindowPtr();
    
    #ifdef GUCE_MSWIN_BUILD 
    UInt32 whandle;
    renderWindow->getCustomAttribute( "WINDOW", &whandle );
    static_cast< GUCEF::CORE::CWndMsgHookNotifier* >( m_osWindowLink )->Unhook( (const HWND)whandle );
    #endif /* GUCE_MSWIN_BUILD ? */
    
    // Make sure Ogre is not referencing a window we want to destroy
    Ogre::Root::getSingletonPtr()->detachRenderTarget( renderWindow->getName() ); 
    
    // Remove the context from our administration
    TWindowContextPtr wcPtr = m_windowlist[ windowContext->GetID() ];
    TWindowList::iterator n = m_windowlist.begin();
    for ( UInt32 i=0; i<windowContext->GetID(); ++i ) { ++n; } 
    m_windowlist.erase( n );
    
    // Notify that we are about to destroy the window context and everything linked to it
    TWindowContextCreatedEventData eData( wcPtr );
    if ( renderWindow->isPrimary() )
    {
        NotifyObservers( PrimaryWindowContextDestroyedEvent, &eData );
    }
    NotifyObservers( WindowContextDestroyedEvent, &eData );

    // Perform the actual cleanup
    renderWindow->destroy();
    GUCEF::INPUT::CInputController::Instance()->DestroyContext( &windowContext->GetInputContext() );
    delete windowContext;
    
    // Check if this was the last application window
    if ( m_windowlist.empty() && !m_busyChangingVideoSettings )
    {
        // Terminate the application
        CGUCEApplication::Instance()->Stop();
    }    
}
        
/*-------------------------------------------------------------------------*/        
        
void 
CWindowManager::DestroyObject( CWindowContext* context )
{GUCE_TRACE;
        
    DestroyWindowContextImp( context );
}

/*-------------------------------------------------------------------------*/

bool
CWindowManager::ApplyVideoSettings( TWindowContextPtr& windowContext ,
                                    const CVideoSettings& settings   )
{GUCE_TRACE;

    if ( NULL == windowContext ) return false;

    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Applying video settings" );
    Ogre::RenderWindow* renderWindow = windowContext->GetOgreWindowPtr();
    
    // Get the current settings for the given window
    CVideoSettings currentSettings;
    CVideoSettings::RetrieveSettingsFromRenderWindow( *renderWindow, currentSettings );
    
    // Check if the alteration requires us to recreate the window
    if ( ( currentSettings.GetAntiAliasingFactor() != settings.GetAntiAliasingFactor() )       ||
         ( currentSettings.GetVSyncState() != settings.GetVSyncState() )                       ||
         ( currentSettings.GetResolutionDepthInBits() != settings.GetResolutionDepthInBits() ) ||
         ( currentSettings.GetFrequency() != settings.GetFrequency() )                          )
    {
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Application of video settings requires recreation of the given window" );
        
        // We have to recreate the window for the changes to take effect
        CString windowName = windowContext->GetName();
        m_busyChangingVideoSettings = true;
        DestroyWindowContext( windowContext );
        windowContext = CreateWindowContext( windowName, settings );
        m_busyChangingVideoSettings = false;
        return windowContext != NULL;
    }
    else
    {
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Application of video settings can be done directly" );
        
        // The alterations can be performed directly using the Ogre API
        if ( currentSettings.GetFullscreenState() != settings.GetFullscreenState() )
        {
            renderWindow->setFullscreen( settings.GetFullscreenState()          ,
                                         settings.GetResolutionWidthInPixels()  ,
                                         settings.GetResolutionHeightInPixels() );
        }
        else        
        if ( ( currentSettings.GetResolutionWidthInPixels() != settings.GetResolutionWidthInPixels() )   ||
             ( currentSettings.GetResolutionHeightInPixels() != settings.GetResolutionHeightInPixels() )  )
        {
            renderWindow->resize( settings.GetResolutionWidthInPixels()  ,
                                  settings.GetResolutionHeightInPixels() );
        }

        return true;        
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
