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

#ifndef __ROOT__
#include "OgreRoot.h"           /* most basic Ogre class */ 
#define __ROOT__
#endif /* __ROOT__ ?  */

#ifndef __RenderSystem_H_
#include <OgreRenderSystem.h>   /* Ogre render system: abstract base */
#define __RenderSystem_H_
#endif /* __RenderSystem_H_ ? */

#ifndef __SceneManager_H__
#include <OgreSceneManager.h>   /* Ogre scene manager: abstract base */
#define __SceneManager_H__
#endif /* __SceneManager_H__ ? */

#ifndef __Camera_H__
#include <OgreCamera.h>         /* base class for Ogre scene cameras */
#define __Camera_H__
#endif /* __Camera_H__ ? */

#ifndef __RenderWindow_H__
#include <OgreRenderWindow.h>   /* Ogre rendering window */
#define __RenderWindow_H__
#endif /* __RenderWindow_H__ ? */

#ifndef GUCEF_CORE_CTRACER_H
#include "CTracer.h"
#define GUCEF_CORE_CTRACER_H
#endif /* GUCEF_CORE_CTRACER_H ? */

#ifndef GUCEFIMAGE_H
#include "gucefIMAGE.h"         /* GUCEF Image library API */
#define GUCEFIMAGE_H
#endif /* GUCEFIMAGE_H ? */

#ifndef CINPUTCONTROLLER_H
#include "CInputController.h"   /* gucefINPUT main controller */
#define CINPUTCONTROLLER_H
#endif /* CINPUTCONTROLLER_H ? */

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"    /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#ifndef GUCE_CORE_CWINDOWMANAGER_H
#include "CWindowManager.h"
#define GUCE_CORE_CWINDOWMANAGER_H
#endif /* GUCE_CORE_CWINDOWMANAGER_H ? */

#ifndef GUCE_CORE_CWINDOWCONTEXT_H
#include "CWindowContext.h"
#define GUCE_CORE_CWINDOWCONTEXT_H
#endif /* GUCE_CORE_CWINDOWCONTEXT_H ? */

#ifndef CGUCEFVFSARCHIVEFACTORY_H
#include "CGUCEFVFSArchiveFactory.h" /* adapter to allow Ogre to use gucefVFS */   
#define CGUCEFVFSARCHIVEFACTORY_H
#endif /* CGUCEFVFSARCHIVEFACTORY_H ? */

#ifndef GUCE_CORE_CIOACCESSARCHIVEFACTORY_H
#include "CIOAccessArchiveFactory.h"
#define GUCE_CORE_CIOACCESSARCHIVEFACTORY_H
#endif /* GUCE_CORE_CIOACCESSARCHIVEFACTORY_H ? */

#ifndef GUCE_CORE_COGRELOGTOGUCEFLOGCADAPTER_H
#include "COgreLogToGUCEFLogAdapter.h"
#define GUCE_CORE_COGRELOGTOGUCEFLOGCADAPTER_H
#endif /* GUCE_CORE_COGRELOGTOGUCEFLOGCADAPTER_H ? */

#ifndef GUCE_CORE_CVIDEOSETTINGS_H
#include "guceCORE_CVideoSettings.h"
#define GUCE_CORE_CVIDEOSETTINGS_H
#endif /* GUCE_CORE_CVIDEOSETTINGS_H ? */

#include "CGUCEApplication.h"   /* definition of the class implemented here */

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

const GUCEF::CORE::CEvent CGUCEApplication::AppInitEvent = "GUCE::CORE::CGUCEApplication::AppInitEvent";
const GUCEF::CORE::CEvent CGUCEApplication::AppShutdownEvent = "GUCE::CORE::CGUCEApplication::AppShutdownEvent";
const GUCEF::CORE::CEvent CGUCEApplication::VideoSetupCompletedEvent = "GUCE::CORE::CGUCEApplication::VideoSetupCompletedEvent";
const GUCEF::CORE::CEvent CGUCEApplication::VideoShutdownImminentEvent = "GUCE::CORE::CGUCEApplication::VideoShutdownImminentEvent";

CGUCEApplication* CGUCEApplication::_instance = NULL;
GUCEF::MT::CMutex CGUCEApplication::_mutex;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

void
CGUCEApplication::RegisterEvents( void )
{GUCE_TRACE;

    AppInitEvent.Initialize();
    AppShutdownEvent.Initialize();
    VideoSetupCompletedEvent.Initialize();
    VideoShutdownImminentEvent.Initialize();
}

/*-------------------------------------------------------------------------*/

CGUCEApplication*
CGUCEApplication::Instance( void )
{GUCE_TRACE;        
        _mutex.Lock();
        if ( !_instance )
        {
                _instance = new CGUCEApplication();
        }
        _mutex.Unlock();
        return _instance;
}

/*-------------------------------------------------------------------------*/

void 
CGUCEApplication::Deinstance( void )
{GUCE_TRACE;

        _mutex.Lock();
        delete _instance;
        _instance = NULL;
        _mutex.Unlock();        
}

/*-------------------------------------------------------------------------*/

CGUCEApplication::CGUCEApplication( void )
        : GUCEF::CORE::CObservingNotifier()   ,
          GUCEF::CORE::CIConfigurable( true ) ,
          _fatalerror( false )                ,
          _initialized( false )               ,
          m_ogreRoot( NULL )                  ,
          m_windowContext()                   ,
          m_imageCodecMap()                   ,
          m_gucefImageCodecs()                ,
          m_ogreLogAdapter( NULL )            ,
          m_sceneManager( NULL )              ,
          m_meshManager()                     ,
          _gucefapp( NULL )                   ,
          m_inputObserverSwitch()
{GUCE_TRACE;

    RegisterEvents();
    
    _gucefapp = GUCEF::CORE::CGUCEFApplication::Instance();
    
    m_ogreLogAdapter = new COgreLogToGUCEFLogAdapter();
      
    /*
     *      Try and setup Ogre plus the Ogre adapters
     */  
    if ( !SetupOgre() )
    {
            _fatalerror = true;
            return;
    }                        
          
    /*
     *      Make sure nothing went wrong getting 
     *      sub-system instances.
     */       
    if ( ( _gucefapp == NULL )  || 
         ( m_ogreRoot == NULL )  )
    {        
            Stop();
            _fatalerror = true;
            return;
    }
    
    m_inputObserverSwitch.SetActiveGroup( "GUI" );
    
    SubscribeTo( _gucefapp ); 
        
    // Subscribe to codec notifications
    GUCEF::CORE::CCodecRegistry* cRegistry = GUCEF::CORE::CCodecRegistry::Instance();                                                        
    SubscribeTo( &cRegistry->AsNotifier(), GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEvent );
    SubscribeTo( &cRegistry->AsNotifier(), GUCEF::CORE::CTONRegistryEvents::ItemUnregisteredEvent );
    
    // If an image codec family already exists we will link and subscribe to it
    if ( cRegistry->IsRegistered( "ImageCodec" ) )
    {
        m_gucefImageCodecs = cRegistry->Lookup( "ImageCodec" );
        SubscribeTo( &m_gucefImageCodecs->AsNotifier(), GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEvent );
        SubscribeTo( &m_gucefImageCodecs->AsNotifier(), GUCEF::CORE::CTONRegistryEvents::ItemUnregisteredEvent );
    }
}

/*-------------------------------------------------------------------------*/

CGUCEApplication::~CGUCEApplication()
{GUCE_TRACE;
    
    CGUCEFVFSArchiveFactory::Deinstance();
    CIOAccessArchiveFactory::Deinstance();
    
    delete m_ogreLogAdapter;
    m_ogreLogAdapter = NULL;
}

/*-------------------------------------------------------------------------*/

GUCEF::INPUT::CInputObserverSwitch&
CGUCEApplication::GetInputObserverSwitch( void )
{GUCE_TRACE;
    
    return m_inputObserverSwitch;
}

/*-------------------------------------------------------------------------*/

CMeshManager&
CGUCEApplication::GetMeshManager( void )
{GUCE_TRACE;

    return m_meshManager;
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::SetupOgre( void )
{GUCE_TRACE;

    try 
    {
        // Construct the Ogre root object if it does not exist yet
        if ( Ogre::Root::getSingletonPtr() == NULL )
        {
            m_ogreRoot = new Ogre::Root( "\0"          ,
                                         "\0"          ,
                                         "OgreLog.txt" );
        }
        else
        {
            m_ogreRoot = Ogre::Root::getSingletonPtr();
        }
        
        /*
         *  Create and thus register our archive adapter factories
         */                        
        CGUCEFVFSArchiveFactory::Instance();
        CIOAccessArchiveFactory::Instance();
    }
    catch ( Ogre::Exception& )
    {
            _fatalerror = true;
            GUCEF::CORE::ShowErrorMessage( "Fatal error", "Fatal exception while initializing Ogre" );
            return false;
    }
    return true; 
}

/*-------------------------------------------------------------------------*/

void 
CGUCEApplication::Stop( void )
{GUCE_TRACE;
        _gucefapp->Stop();
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::Update( void )
{GUCE_TRACE;
        
    if ( !_fatalerror )
    { 
        _gucefapp->Update();                
    }               
}

/*-------------------------------------------------------------------------*/

#ifdef GUCE_MSWIN_BUILD
int
CGUCEApplication::Main( HINSTANCE hinstance     ,
                        LPSTR lpcmdline         ,
                        int ncmdshow            ,
                        bool run                )
{GUCE_TRACE;

    if ( !_fatalerror )
    {       
        /*
         *      If there where no fatal init errors,..
         *      Call the GUCEF app main to get things started
         */                          
        return _gucefapp->Main( hinstance     ,
                                lpcmdline     ,
                                ncmdshow      ,
                                run           ); 
    }
    return 0;                                        
}
#endif /* GUCE_MSWIN_BUILD ? */

/*-------------------------------------------------------------------------*/

int
CGUCEApplication::main( int argc    ,
                        char** argv ,
                        bool run    )
{GUCE_TRACE;

    return _gucefapp->main( argc ,
                            argv ,
                            run  ); 
}

/*-------------------------------------------------------------------------*/

bool  
CGUCEApplication::SetupOgreRenderSys( const GUCEF::CORE::CDataNode& rootnode                 ,
                                      Ogre::RenderSystem** selectedRenderSystem /* = NULL */ )
{GUCE_TRACE;

    const Ogre::RenderSystemList& rendersyslist = m_ogreRoot->getAvailableRenderers();
    if ( rendersyslist.size() == 0 )
    {
        /*
         *      No rendering systems are available
         *      This is an fatal error
         */
        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "No Ogre renderers are available" ); 
        return false; 
    }

    Ogre::RenderSystem* renderSystem = NULL;
    const GUCEF::CORE::CDataNode* n = rootnode.Find( "RenderSystem" );
    if ( n != NULL )
    {        
        if ( selectedRenderSystem != NULL )
        {
            *selectedRenderSystem = NULL;
        }
        
        const GUCEF::CORE::CDataNode::TKeyValuePair* att;
        att = n->GetAttribute( "name" );
        if ( att )
        {                        
            /*
             *      The user requested a specific render system
             *      Your wish is my command master,...
             */
            GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Desired render system: " + att->second ); 
            for ( UInt32 i=0; i<rendersyslist.size(); ++i )
            {
                GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Available render system: " + GUCEF::CORE::CString( (rendersyslist[ i ])->getName().c_str() ) );
                if ( (rendersyslist[ i ])->getName() == att->second.C_String() )
                {
                    renderSystem = rendersyslist[ i ];
                    break;        
                }          
            }
            if ( renderSystem == NULL )
            {
                /*
                 *      The requested render system could not be found
                 *      This is a fatal error
                 */
                return false; 
            }             
            
            /*
             *      Set the render system in ogre and initialize
             *      the OGRE systems                                 
             */                                     
            m_ogreRoot->setRenderSystem( renderSystem );
            if ( selectedRenderSystem != NULL )
            {
                *selectedRenderSystem = renderSystem;
            }
            return true;                                                              
        }                                
    } 
    
    /*
     *      Setup OGRE using hard coded default settings         
     */
    renderSystem = rendersyslist[ 0 ]; 
    m_ogreRoot->setRenderSystem( renderSystem );
    if ( selectedRenderSystem != NULL )
    {
        *selectedRenderSystem = renderSystem;
    }    
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::SetupWindow( const GUCEF::CORE::CDataNode& rootnode                         ,
                               CWindowManager::TWindowContextPtr* windowsContext /* = NULL */ )
{GUCE_TRACE;

    // Check to make sure we do not already have a primary window
    if ( NULL != m_windowContext ) return false;
    
    try
    {        
        const GUCEF::CORE::CDataNode* n = rootnode.Find( "WindowSettings" );
        if ( n != NULL )
        {                     
            m_windowContext = CWindowManager::Instance()->CreateWindowContext( *n                 ,
                                                                               "GUCE Application" );
            if ( windowsContext != NULL )
            {
                *windowsContext = m_windowContext;
            }
            if (  NULL != m_windowContext )
            {
                return true;
            }
        }
        return false;
    }
    catch ( Ogre::Exception& )
    {
            return false;
    }
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::SetupOgreRecources( const GUCEF::CORE::CDataNode& rootnode )
{GUCE_TRACE;

    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUCEApplication: Setting up Ogre recources" );

    const GUCEF::CORE::CDataNode* n = rootnode.Find( "OgreRecourceGroups" );
    
    if ( n != NULL )
    {
        const GUCEF::CORE::CDataNode* rscnode;                   
        const GUCEF::CORE::CDataNode::TKeyValuePair *att1 = NULL, *att2 = NULL, *att3 = NULL;
        GUCEF::CORE::CDataNode::const_iterator i( n->ConstBegin() );
        while ( i != n->ConstEnd() )
        {
            rscnode = (*i);
            if ( rscnode->GetName() == "OgreRecourceGroup" )
            {
                att1 = rscnode->GetAttribute( "name" );
                att2 = rscnode->GetAttribute( "path" );
                att3 = rscnode->GetAttribute( "type" );
                
                if ( ( att1 != NULL ) && 
                     ( att2 != NULL ) &&
                     ( att3 != NULL )  )
                {
                    try 
                    {
                        // Non-GUCEF systems might not be able to handle relative paths
                        // We will check and convert if needed for such scenarios
                        GUCEF::CORE::CString resNam( att2->second );
                        if ( att3->second != "gucefVFS" )
                        {
                            resNam = GUCEF::CORE::RelativePath( att2->second );
                        }
                        
                        // Now we perform the actual add using Ogre
                        m_ogreRoot->addResourceLocation( resNam.C_String()       , 
                                                         att3->second.C_String() , 
                                                         att1->second.C_String() );
                    }
                    catch ( Ogre::Exception& e )
                    {
                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "Ogre Exception: " ) + e.getFullDescription() );
                    }                                                
                }
            }                                        
            ++i;
        }
        return true;
    }
    
    return false;        
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::SetupOgreScene( CWindowManager::TWindowContextPtr& windowContext ,
                                  Ogre::SceneManager** sceneManager /* = NULL */   ,
                                  Ogre::SceneNode** worldNode       /* = NULL */   ,
                                  Ogre::Camera** camera             /* = NULL */   ,
                                  Ogre::Viewport** viewport         /* = NULL */   )
{GUCE_TRACE;

    m_sceneManager = m_ogreRoot->createSceneManager( Ogre::ST_GENERIC );
    Ogre::SceneNode* wNode = m_sceneManager->createSceneNode( "WorldNode" );
    m_sceneManager->getRootSceneNode()->addChild( wNode );                                      

    Ogre::Camera* cam = m_sceneManager->createCamera( "Main" );
    cam->setPosition( 0, 10, 500 );
    cam->lookAt( 0, 0, 0 );
    cam->setNearClipDistance( 5 );

    Ogre::Viewport* viewPort = windowContext->GetOgreWindowPtr()->addViewport( cam );
    viewPort->setBackgroundColour( Ogre::ColourValue::White );// Ogre::ColourValue( 0, 0, 0 ) );
//    viewPort->setAspectRatio( Ogre::Real( viewport->getActualWidth() ) / Ogre::Real( viewport->getActualHeight() ) );
    
    if ( camera != NULL )
    {
        *camera = cam;
    }
    if ( viewport != NULL )
    {
        *viewport = viewPort;
    }
    if ( sceneManager != NULL )
    {
        *sceneManager = m_sceneManager;
    }
    if ( worldNode != NULL )
    {
        *worldNode = wNode;
    }
        
    return true;
}

/*-------------------------------------------------------------------------*/

Ogre::SceneManager*
CGUCEApplication::GetSceneManager( void )
{GUCE_TRACE;

    return m_sceneManager;
}

/*-------------------------------------------------------------------------*/

CWindowManager::TWindowContextPtr
CGUCEApplication::GetPrimaryWindowContext( void )
{GUCE_TRACE;

    return m_windowContext;
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::SetupOgreVideo( const GUCEF::CORE::CDataNode& rootnode                           ,
                                  Ogre::RenderSystem** renderSystem /* = NULL */                   ,
                                  CWindowManager::TWindowContextPtr* windowContext /* = NULL */    )
{GUCE_TRACE;

    try 
    {        
        /*
         *      Setup the rendering system
         */
        Ogre::RenderSystem* rSystem = NULL; 
        if ( !SetupOgreRenderSys( rootnode ,
                                  &rSystem ) ) return false;
                       
        if ( renderSystem != NULL )
        {
            *renderSystem = rSystem;
        }

        /*
         *  Setup the window
         */                                                            
        CWindowManager::TWindowContextPtr wContext;
        if ( !SetupWindow( rootnode  ,
                           &wContext ) ) return false;              
                         
        // Set default mipmap level (NB some APIs ignore this)
        Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
        
        rSystem->_initRenderTargets();                                                                             
        
        if ( windowContext != NULL )
        {
            *windowContext = wContext;
        }
        
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
        return true;
    }
    catch ( Ogre::Exception& )
    {
        return false;
    }                                    
    
    return true;               
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::AppInitHandler( const GUCEF::CORE::CEvent& event )
{GUCE_TRACE;
        

        try 
        {       
            /*
             *  Link resources
             */
            RegisterGUCEFImageCodecsInOgre();                                            
                
            /*
             *      Startup Ogre
             */
            CWindowManager::TWindowContextPtr windowContext;
            if ( SetupOgreVideo( m_videoSettings ,
                                 NULL            ,
                                 &windowContext  ) )
            {
                if ( SetupOgreScene( windowContext ) )
                {
                    NotifyObservers( VideoSetupCompletedEvent );
                    NotifyObservers( AppInitEvent );
                    return;
                }
            }
            
            // If we get here then we experienced a fatal error during startup
            Stop();
        }
        catch ( Ogre::Exception& e )
        {                
                _fatalerror = true;
                GUCEF::CORE::ShowErrorMessage( "Ogre exception during init: ", e.getFullDescription().c_str() );        
                Stop();
     
        }
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::AppShutdownHandler( const GUCEF::CORE::CEvent& eventid )
{GUCE_TRACE;
        m_ogreRoot->shutdown();
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::ShutdownOgreVideo( void )
{GUCE_TRACE;

    NotifyObservers( VideoShutdownImminentEvent );
    
    Ogre::RenderSystem* renderSystem = m_ogreRoot->getRenderSystem();
    if ( NULL != renderSystem )
    {
        renderSystem->shutdown();
    }
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::OnNotify( GUCEF::CORE::CNotifier* notifier                 ,
                            const GUCEF::CORE::CEvent& eventid               ,
                            GUCEF::CORE::CICloneable* eventdata /* = NULL */ )
{GUCE_TRACE;

    if ( eventid == GUCEF::CORE::CGUCEFApplication::AppInitEvent )
    {
        AppInitHandler( eventid );
        return;
    }
    else
    if ( eventid == GUCEF::CORE::CGUCEFApplication::AppShutdownEvent )
    {        
        NotifyObservers( AppShutdownEvent );
        AppShutdownHandler( eventid );                
        return;
    }
    else
    if ( CWindowManager::PrimaryWindowContextDestroyedEvent == eventid )
    {
        ShutdownOgreVideo();
    }
    else
    if ( eventid == GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEvent )
    {
        if ( notifier == &GUCEF::CORE::CCodecRegistry::Instance()->AsNotifier() )
        {
            // notification that a new registry has been added
            GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEventData* eData = static_cast< GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEventData* >( eventdata );
            if ( eData->GetData() == "ImageCodec" )
            {
                m_gucefImageCodecs = GUCEF::CORE::CCodecRegistry::Instance()->Lookup( "ImageCodec" );
                SubscribeTo( &m_gucefImageCodecs->AsNotifier(), GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEvent );
                SubscribeTo( &m_gucefImageCodecs->AsNotifier(), GUCEF::CORE::CTONRegistryEvents::ItemUnregisteredEvent );

                RegisterGUCEFImageCodecsInOgre();
            }
        }
        else
        if ( m_gucefImageCodecs != NULL )
        {
            if ( notifier == &m_gucefImageCodecs->AsNotifier() )
            {
                // notification that a new image codec has been added
                GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEventData* eData = static_cast< GUCEF::CORE::CTONRegistryEvents::ItemRegisteredEventData* >( eventdata );
                RegisterGUCEFImageCodecInOgre( eData->GetData() );
            }
        }
    }
}

/*-------------------------------------------------------------------------*/

bool 
CGUCEApplication::SaveConfig( GUCEF::CORE::CDataNode& tree )
{GUCE_TRACE;
        /*
         *      There is no way to get a plugin list from OGRE so we have to
         *      be content with building the tree structure.
         */
        GUCEF::CORE::CDataNode* n = tree.Structure( "GUCE%CORE%CGUCEApplication%OGRE%OGREPlugins" ,
                                                    '%'                                           );
        return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::SetupOgrePlugins( const GUCEF::CORE::CDataNode& rootnode )
{GUCE_TRACE;

    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUCEApplication: Setting up Ogre plugins according to config" );
    
    const GUCEF::CORE::CDataNode* n = rootnode.Find( "OGREPlugins" );
    
    if ( n != NULL )
    {
        const GUCEF::CORE::CDataNode::TKeyValuePair* att = n->GetAttribute( "plugindir" );
        if ( !att ) 
        {
            return false;
        }                        
                        
        GUCEF::CORE::CString plugindir( GUCEF::CORE::RelativePath( att->second ) );
        GUCEF::CORE::CString plugin;
        
        GUCEF::CORE::CDataNode::const_iterator i = n->ConstBegin();
        const GUCEF::CORE::CDataNode* c;                
        while ( i != n->ConstEnd() )
        {
            c = (*i);
            if ( c->GetName() == "OGREPlugin" )
            {
                att = c->GetAttribute( "filename" );
                if ( att )
                {
                    plugin = plugindir;
                    AppendToPath( plugin, att->second );
                    try 
                    {
                        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUCEApplication: Attempting to load Ogre plugin from: " + plugin );
                        
                        Ogre::Root::getSingletonPtr()->loadPlugin( plugin.C_String() );        
                    }
                    catch ( Ogre::Exception& )
                    {
                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Failed to load OGRE plugin: " + plugin );
                    }
                }                
            }
            ++i;
        }
        return true;
    }
    return false;
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::RegisterGUCEFImageCodecInOgre( const GUCEF::CORE::CString& codecType )
{GUCE_TRACE;

    // Make sure we dont register the same codec twice
    TImageCodecMap::iterator n = m_imageCodecMap.find( codecType.C_String() );
    if ( n != m_imageCodecMap.end() )
    {
        delete (*n).second;
        m_imageCodecMap.erase( n );
    }

    GUCEF::CORE::CCodecRegistry* cRegistry = GUCEF::CORE::CCodecRegistry::Instance();
    if ( cRegistry->IsRegistered( "ImageCodec" ) )
    {
        // First we get a list of available image codecs
        GUCEF::CORE::CCodecRegistry::TCodecFamilyRegistryPtr codecFamily = cRegistry->Lookup( "ImageCodec" );
        COgreImageCodecAdapter* codec = new COgreImageCodecAdapter( codecFamily->Lookup( codecType ) );
        m_imageCodecMap.insert( std::pair< GUCEF::CORE::CString, COgreImageCodecAdapter* >( codecType, codec ) );
        Ogre::Codec::registerCodec( codec );
            
        GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Registered GUCEF ImageCodec in Ogre: " + codecType );
    }
}

/*-------------------------------------------------------------------------*/

void
CGUCEApplication::RegisterGUCEFImageCodecsInOgre( void )
{GUCE_TRACE;

    GUCEF::CORE::CCodecRegistry* cRegistry = GUCEF::CORE::CCodecRegistry::Instance();
    if ( cRegistry->IsRegistered( "ImageCodec" ) )
    {
        // First we get a list of available image codecs
        GUCEF::CORE::CCodecRegistry::TCodecFamilyRegistryPtr codecFamily = cRegistry->Lookup( "ImageCodec" );
        GUCEF::CORE::CCodecRegistry::TStringList codecList;
        codecFamily->GetList( codecList );
        
        for ( UInt32 i=0; i<codecList.size(); ++i )
        {
            // Make sure we dont register the same codec twice
            GUCEF::CORE::CString& codecName = codecList[ i ];
            TImageCodecMap::iterator n = m_imageCodecMap.find( codecName );
            if ( n != m_imageCodecMap.end() )
            {
                delete (*n).second;
                m_imageCodecMap.erase( n );
            }
            
            COgreImageCodecAdapter* codec = new COgreImageCodecAdapter( codecFamily->Lookup( codecName ) );
            m_imageCodecMap.insert( std::pair< GUCEF::CORE::CString, COgreImageCodecAdapter* >( codecName, codec ) );
            Ogre::Codec::registerCodec( codec );
            
            GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "Registered GUCEF ImageCodec in Ogre: " + codecName );
        }
    }
}

/*-------------------------------------------------------------------------*/

bool 
CGUCEApplication::LoadConfig( const GUCEF::CORE::CDataNode& tree )
{GUCE_TRACE;

    GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_BELOW_NORMAL, "CGUCEApplication: Loading config" );

    const GUCEF::CORE::CDataNode* n = tree.Search( "GUCE%CORE%CGUCEApplication%INPUTDRIVER" ,
                                                   '%'                                      ,
                                                   false                                    );
    if ( n )
    {
            const GUCEF::CORE::CDataNode::TKeyValuePair* att = n->GetAttribute( "module" );
            if ( att ) 
            {
                    GUCEF::CORE::CValueList paramlist;
                    if ( !GUCEF::INPUT::CInputController::Instance()->LoadDriverModule( att->second, paramlist ) )
                    {
                        return false;
                    }
            }                
    }                                                        
    
    n = tree.Search( "GUCE%CORE%CGUCEApplication%OGRE%OGREPlugins" ,
                      '%'                                           ,
                      false                                         );
    if ( n != NULL )
    {                   
        SetupOgrePlugins( *n );                        
    }
    
    n = tree.Search( "GUCE%CORE%CGUCEApplication%OGRE%OgreRecourceGroups" ,
                     '%'                                                  ,
                     false                                                );
    if ( n != NULL )
    {
        SetupOgreRecources( *n );
    }            
    
    n = tree.Search( "GUCE%CORE%CGUCEApplication%VideoSettings" ,
                     '%'                                        ,
                     false                                      );
    if ( n != NULL )
    {
        // Store the video settings for later
        m_videoSettings.Copy( *n );
    }
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CGUCEApplication::ApplyVideoSettings( const CVideoSettings& settings )
{GUCE_TRACE;

    return CWindowManager::Instance()->ApplyVideoSettings( m_windowContext ,
                                                           settings        );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
