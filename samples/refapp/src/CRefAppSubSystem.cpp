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

#ifndef __OverlayManager_H__
#include "OgreOverlayManager.h"
#define __OverlayManager_H__
#endif /* __OverlayManager_H__ ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

//#ifndef GUCE_GUI_CGUICONSOLE_H
//#include "guceGUI_CGUIConsole.h"
//#define GUCE_GUI_CGUICONSOLE_H
//#endif /* GUCE_GUI_CGUICONSOLE_H ? */

//#ifndef GUCE_GUI_CGUIEDITOR_H
//#include "guceGUI_CGUIEditor.h"              // temp for testing
//#define GUCE_GUI_CGUIEDITOR_H
//#endif /* GUCE_GUI_CGUIEDITOR_H ? */

#ifndef GUCE_GUI_CGUIMANAGER_H
#include "CGUIManager.h"
#define GUCE_GUI_CGUIMANAGER_H
#endif /* GUCE_GUI_CGUIMANAGER_H ? */

#ifndef REFAPP_COGREDEBUGOVERLAY_H
#include "COgreDebugOverlay.h"
#define REFAPP_COGREDEBUGOVERLAY_H
#endif /* REFAPP_COGREDEBUGOVERLAY_H ? */

#include "CRefAppSubSystem.h"   /* definition of the class implemented here */

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CRefAppSubSystem::CRefAppSubSystem( void )
    : CObservingNotifier() ,
      //m_console( NULL )          ,
      m_debugOverlay( NULL )
{GUCE_TRACE;

    SubscribeTo( GUCE::GUI::CGUIManager::Instance(), GUCE::GUI::CGUIManager::GUIInitializedEvent );
}

/*--------------------------------------------------------------------------*/

CRefAppSubSystem::~CRefAppSubSystem()
{GUCE_TRACE;

    //delete m_console;
    //m_console = NULL;
    
    delete m_debugOverlay;
    m_debugOverlay = NULL;
}

/*--------------------------------------------------------------------------*/

void
CRefAppSubSystem::OnNotify( GUCEF::CORE::CNotifier* notifier                  ,
                            const GUCEF::CORE::CEvent& eventid                ,
                            GUCEF::CORE::CICloneable* eventdata /* = NULL  */ )
{GUCE_TRACE;

    if ( GUCE::GUI::CGUIManager::GUIInitializedEvent == eventid )
    {
        //m_console = new GUCE::GUI::CGUIConsole();
        //m_console->Show();
        
        m_debugOverlay = new COgreDebugOverlay();
        m_debugOverlay->Show();

        //GUCE::GUI::CGUIEditor::Instance()->Show();
    }
}

/*-------------------------------------------------------------------------*/

void
CRefAppSubSystem::OnUpdate( const GUCEF::CORE::UInt64 tickCount               ,
                            const GUCEF::CORE::Float64 updateDeltaInMilliSecs )
{GUCE_TRACE;
  
    try
    {
        if ( !Ogre::Root::getSingletonPtr()->renderOneFrame() )
        {
                GUCE::CORE::CGUCEApplication::Instance()->Stop();
                return;
        }
    }
    catch ( Ogre::Exception& /* e */ )
    {
        GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CRefAppSubSystem::OnUpdate(): Exception during Ogre frame rendering" );
    }
}    
    
/*-------------------------------------------------------------------------*/
