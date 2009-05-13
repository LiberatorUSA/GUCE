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

#include "OgreNoMemoryMacros.h" /* Don't use the Ogre memory manager */

#ifndef GUCE_CEGUIOGRE_OGRECEGUITEXTURE_H
#include "guceCEGUIOgre_OgreCEGUIRenderer.h"
#define GUCE_CEGUIOGRE_OGRECEGUITEXTURE_H
#endif /* GUCE_CEGUIOGRE_OGRECEGUITEXTURE_H ? */

#ifndef __ROOT__
#include <OgreRoot.h>           /* most basic Ogre class */ 
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

#ifndef __RenderWindow_H__
#include "OgreRenderWindow.h"
#define __RenderWindow_H__
#endif /* __RenderWindow_H__ ? */

#ifndef __Camera_H__
#include <OgreCamera.h>   /* Ogre camera */
#define __Camera_H__
#endif /* __Camera_H__ ? */

#include "OgreNoMemoryMacros.h" /* Don't use the Ogre memory manager */

#ifndef _CEGUISystem_h_
#include "CEGUISystem.h"
#define _CEGUISystem_h_
#endif /* _CEGUISystem_h_ ? */

#ifndef _CEGUILogger_h_
#include "CEGUILogger.h"
#define _CEGUILogger_h_
#endif /* _CEGUILogger_h_ ? */

#ifndef _CEGUISchemeManager_h_
#include "CEGUISchemeManager.h"
#define _CEGUISchemeManager_h_
#endif /* _CEGUISchemeManager_h_ ? */

#ifndef _CEGUISchemeManager_h_
#include "CEGUISchemeManager.h"
#define _CEGUISchemeManager_h_
#endif /* _CEGUISchemeManager_h_ ? */

#include "CEGUIImageset.h"
#include "CEGUIImagesetManager.h"
#include "CEGUITexture.h"
#include "CEGUIWindowManager.h"
#include "CEGUIExceptions.h"
#include "CEGUIFontManager.h"
#include "CEGUIResourceProvider.h"
#include "falagard/CEGUIFalWidgetLookManager.h"

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

#ifndef GUCE_GUI_CGUIMANAGER_H
#include "CGUIManager.h"
#define GUCE_GUI_CGUIMANAGER_H
#endif /* GUCE_GUI_CGUIMANAGER_H ? */

#include "guceCEGUIOgre_CGUIDriver.h"

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
      m_guiRenderer( NULL )   ,
      m_guiSystem( NULL )     ,
      m_renderTexture( NULL ) ,
      m_guiTexture( NULL )    ,
      m_guiWindow( NULL )     ,
      m_guiImageset( NULL )   ,
      m_guiViewport( NULL )   ,
      m_ogreRoot( NULL )      ,
      m_ceguiInput( "GUCE::CEGUIOGRE::CInputCEGUIManipulator" )
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

OgreCEGUIRenderer*
CGUIDriver::GetRenderer( void )
{GUCE_TRACE;

    return m_guiRenderer;
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
        
        delete m_guiRenderer;
        m_guiRenderer = NULL;
        
        m_ogreRoot = NULL;
        m_window = NULL;
        m_guiViewport = NULL;
        m_guiTexture = NULL;
        m_guiWindow = NULL;
        
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
        
        assert( windowContext != NULL );
        m_window = windowContext->GetOgreWindowPtr();                
        assert( m_window );

        // Set the initial logging level of CEGUI       
        #ifdef GUCE_GUI_DEBUG_MODE
        CEGUI::Logger::getSingleton().setLoggingLevel( CEGUI::Insane );        
        #else
        CEGUI::Logger::getSingleton().setLoggingLevel( CEGUI::Informative );
        #endif
        
        /* setup GUI system */ 
        m_guiRenderer = new OgreCEGUIRenderer( windowContext->GetOgreWindowPtr() , 
                                               Ogre::RENDER_QUEUE_OVERLAY        , 
                                               false                             , 
                                               3000                              ,
                                               CORE::CGUCEApplication::Instance()->GetSceneManager() );

        m_guiSystem = new CEGUI::System( m_guiRenderer );
        
        /* Setup the default resource group for the GUI system */
        m_guiSystem->getResourceProvider()->setDefaultResourceGroup( "GUI" );

        /* Setup Render To Texture for GUI now */
        m_ogreRoot = Ogre::Root::getSingletonPtr();
        Ogre::RenderTexture* guiRTTexture = m_ogreRoot->getRenderSystem()->createRenderTexture( "GUITexture"      ,
                                                                                                512               ,
                                                                                                512               ,
                                                                                                Ogre::TEX_TYPE_2D ,
                                                                                                Ogre::PF_R8G8B8   );
        if ( guiRTTexture == NULL )
        {
            GUCEF_SYSTEM_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CGUIDriver: Failed to initialize the GUI system: no render texture" );
            return false;
        }
        
        Ogre::SceneManager* sceneManager = CORE::CGUCEApplication::Instance()->GetSceneManager();
        assert( sceneManager != NULL );
        Ogre::Camera* guiCam = sceneManager->createCamera( "GUICamera" );
        Ogre::SceneNode* camNode = sceneManager->getRootSceneNode()->createChildSceneNode( "GUICameraNode" );
        
        camNode->attachObject( guiCam );
        guiCam->setPosition( 0, 0, 200 );
        //guiCam->setVisible( true );

        m_guiViewport = guiRTTexture->addViewport( guiCam );
        m_guiViewport->setOverlaysEnabled( false );
        m_guiViewport->setClearEveryFrame( true );
        m_guiViewport->setBackgroundColour( Ogre::ColourValue::Black );
            
        // Retrieve CEGUI texture for the RTT
        m_guiTexture = m_guiRenderer->createTexture( (CEGUI::utf8*)"GUITexture", "GUI" );
        m_guiImageset = CEGUI::ImagesetManager::getSingleton().createImageset( (CEGUI::utf8*)"guiImageset", m_guiTexture );
        m_guiImageset->defineImage( (CEGUI::utf8*) "guiImage"                 , 
                                    CEGUI::Point( 0.0f, 0.0f )                , 
                                    CEGUI::Size( m_guiTexture->getWidth()  ,
                                                 m_guiTexture->getHeight() )  , 
                                    CEGUI::Point( 0.0f, 0.0f )                );
        
        m_guiWindow = CEGUI::WindowManager::getSingletonPtr()->createWindow( "DefaultWindow", "root" );
        m_guiSystem->setGUISheet( m_guiWindow );
        m_guiWindow->setVisible( true );
        m_guiWindow->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.0, 0.0 ),CEGUI::UDim( 0.0, 0.0 ) ) );
        m_guiWindow->setSize( CEGUI::UVector2( CEGUI::UDim( 1.0, 0.0 ), CEGUI::UDim( 1.0, 0.0 )));
        m_guiWindow->setVisible( true );

        /* setup our event handler to feed CEGUI with events */
        m_ceguiInput.AquireCEGUILink();
    
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
        m = rootNode.Find( "CEGUI" );

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
            const GUCEF::CORE::CDataNode::TNodeAtt* att1( NULL );
            const GUCEF::CORE::CDataNode::TNodeAtt* att2( NULL );
            const GUCEF::CORE::CDataNode* n( NULL );
            GUCEF::CORE::CDataNode::const_iterator i = m->ConstBegin();
            while ( i != m->ConstEnd() )
            {
                    n = (*i);
                    if ( "LoadScheme" == n->GetName() )
                    {
                            att1 = n->GetAttribute( "name" );
                            att2 = n->GetAttribute( "resourceGroup" );
                            if ( att1 && att2 )
                            {
                                    try 
                                    {
                                            CEGUI::SchemeManager::getSingleton().loadScheme( (CEGUI::utf8*)att1->value.C_String() ,
                                                                                             (CEGUI::utf8*)att2->value.C_String() );
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }
                            }
                    }
                    else
                    if ( "LoadImageSet" == n->GetName() )
                    {
                            att1 = n->GetAttribute( "name" );
                            att2 = n->GetAttribute( "resourceGroup" );
                            if ( att1 && att2 )
                            {
                                    try
                                    {
                                            CEGUI::ImagesetManager::getSingleton().createImageset( (CEGUI::utf8*)att1->value.C_String() ,
                                                                                                   (CEGUI::utf8*)att2->value.C_String() );
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }
                            }                        
                    }
                    else
                    if ( "LoadLookNFeel" == n->GetName() )
                    {
                            att1 = n->GetAttribute( "name" );
                            att2 = n->GetAttribute( "resourceGroup" );
                            if ( att1 && att2 )
                            {
                                    try
                                    {
                                            CEGUI::WidgetLookManager::getSingleton().parseLookNFeelSpecification( (CEGUI::utf8*)att1->value.C_String() ,
                                                                                                                  (CEGUI::utf8*)att2->value.C_String() );
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }                                        
                            }                        
                    }                        
                    else
                    if ( "LoadLayout" == n->GetName() )
                    {
                            const GUCEF::CORE::CDataNode::TNodeAtt* att3( NULL );
                            att1 = n->GetAttribute( "name" );
                            att2 = n->GetAttribute( "resourceGroup" );
                            att3 = n->GetAttribute( "namePrefix" );
                            if ( att1 && att2 )
                            {
                                    try
                                    {       
                                            GUCEF::CORE::CString namePrefixStr;
                                            if ( att3 )
                                            {
                                                    namePrefixStr = att3->value;
                                            }
                                            
                                            CEGUI::WindowManager::getSingleton().loadWindowLayout( (CEGUI::utf8*)att1->value.C_String()   ); /*,
                                                                                                   (CEGUI::utf8*)namePrefixStr.C_String() ,
                                                                                                   (CEGUI::utf8*)att2->value.C_String()   );  */
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }
                            }                                
                    }
                    else
                    if ( "LoadFont" == n->GetName() )
                    {
                            att1 = n->GetAttribute( "name" );
                            att2 = n->GetAttribute( "resourceGroup" );
                            if ( att1 && att2 )
                            {
                                    try
                                    {
                                            CEGUI::FontManager::getSingleton().createFont( (CEGUI::utf8*) att1->value.C_String() ,
                                                                                           (CEGUI::utf8*) att2->value.C_String() );
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }                                        
                            }                        
                    }                        
                    else
                    if ( "DefaultFont" == n->GetName() )
                    {
                            att1 = n->GetAttribute( "name" );
                            if ( att1 )
                            {
                                    try 
                                    {
                                            m_guiSystem->setDefaultFont( att1->value.C_String() );
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }                                        
                            }       
                    }
                    else
                    if ( "DefaultMouseCursor" == n->GetName() )
                    {
                            att1 = n->GetAttribute( "imageSet" );
                            att2 = n->GetAttribute( "imageName" );
                            if ( att1 && att2 )
                            {
                                    try 
                                    {
                                            m_guiSystem->setDefaultMouseCursor( (CEGUI::utf8*) att1->value.C_String() ,
                                                                                (CEGUI::utf8*) att2->value.C_String() );
                                            CEGUI::MouseCursor::getSingleton().setImage( CEGUI::System::getSingleton().getDefaultMouseCursor() );
                                    }
                                    catch ( CEGUI::Exception& e )
                                    {
                                        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CEGUI Exception: " ) + e.getMessage().c_str() );
                                        return false;
                                    }                                        
                            }       
                    }                                                                         
                    ++i;
            }
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

} /* namespace CEGUIOGRE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/
