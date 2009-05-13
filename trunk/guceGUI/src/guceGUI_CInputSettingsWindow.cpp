/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2004.  All rights reserved.
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

#include "CEGUIWindowManager.h"
#include "CEGUIEventArgs.h"
#include "elements/CEGUIFrameWindow.h"
#include "elements/CEGUIPushButton.h"
#include "elements/CEGUICombobox.h"
#include "elements/CEGUIListboxTextItem.h"
//#include "elements/CEGUIStaticText.h"

#ifndef CSTRINGLIST_H
#include "CStringList.h"
#define CSTRINGLIST_H
#endif /* CSTRINGLIST_H ? */

#ifndef CINPUTPROFILEMANAGER_H
#include "CInputProfileManager.h"
#define CINPUTPROFILEMANAGER_H
#endif /* CINPUTPROFILEMANAGER_H ? */

#include "guceGUI_CInputSettingsWindow.h"

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

CInputSettingsWindow* CInputSettingsWindow::_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class ListItem : public CEGUI::ListboxTextItem
{
        public:
	ListItem( const CEGUI::String& text ) 
	        : ListboxTextItem( text )
	{GUCE_TRACE;
		setSelectionBrushImage( (CEGUI::utf8*) "TaharezLook"             , 
		                        (CEGUI::utf8*) "MultiListSelectionBrush" );
	}
	
	virtual ~ListItem()
	{GUCE_TRACE;
	}
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

CInputSettingsWindow::CInputSettingsWindow( void )
        : m_inputProfileManager( GUCEF::INPUT::CInputProfileManager::Instance() )
{GUCE_TRACE;
        /*
         *      Create and config the main MainMenu window that holds the buttons
         */
            
        CEGUI::WindowManager* wmngr = CEGUI::WindowManager::getSingletonPtr();
        _window = (CEGUI::FrameWindow*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/FrameWindow" , 
                                                             (CEGUI::utf8*) "CInputSettingsWindow:Window"  );
                                                             
        wmngr->getWindow( "CSettingsWindow:Window" )->addChildWindow( _window );
        
        _window->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.15f, 0.0f ) ) );
        _window->setSize( CEGUI::UVector2( CEGUI::UDim( 1.0f, 0.0f ), CEGUI::UDim( 0.85f, 0.0f ) ) );
        _window->setText( (CEGUI::utf8*) "Input Settings" );
        _window->setCloseButtonEnabled( false );        
        _window->setVisible( false );
        _window->setDragMovingEnabled( false );
        _window->setSizingEnabled( false );     
        
        /*
         *      Add everything for profile selection
         *
        CEGUI::StaticText* statictext = (CEGUI::StaticText*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/StaticText"                 ,
                                                                                  (CEGUI::utf8*) "CInputSettingsWindow:ProfileSelectText" );
        _window->addChildWindow( statictext );
        
        statictext->setText( (CEGUI::utf8*) "Profile" );
        statictext->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.35f, 0.0f ), CEGUI::UDim( 0.05f, 0.0f ) ) );
        statictext->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.05f, 0.0f ) ) );
        statictext->setFrameEnabled( false );
        statictext->setBackgroundEnabled( false );
        statictext->setHorizontalFormatting( CEGUI::StaticText::WordWrapCentred );
                      */                                                                    
        m_profileList = (CEGUI::Combobox*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Combobox"                 , 
                                                                (CEGUI::utf8*) "CInputSettingsWindow:ProfileCombobox" );
        _window->addChildWindow( m_profileList );
        m_profileList->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.35f, 0.0f ), CEGUI::UDim( 0.1f, 0.0f ) ) );
        m_profileList->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.2f, 0.0f ) ) );
        m_profileList->setReadOnly( true );        

        /*
         *      Add everything for manipulator selection
         *
        statictext = (CEGUI::StaticText*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/StaticText"                     ,
                                                               (CEGUI::utf8*) "CInputSettingsWindow:ManipulatorSelectText" );
        _window->addChildWindow( statictext );
        
        statictext->setText( (CEGUI::utf8*) "Manipulator" );
        statictext->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.18f, 0.0f ) ) );
        statictext->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.5f, 0.0f ) ) );
        statictext->setFrameEnabled( false );
        statictext->setBackgroundEnabled( false );
        statictext->setHorizontalFormatting( CEGUI::StaticText::WordWrapCentred );
          */                                                                                
        m_manipulatorList = (CEGUI::Combobox*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Combobox"                     , 
                                                                    (CEGUI::utf8*) "CInputSettingsWindow:ManipulatorCombobox" );
        _window->addChildWindow( m_manipulatorList );
        m_manipulatorList->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.23f, 0.0f ) ) );
        m_manipulatorList->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.2f, 0.0f ) ) );
        m_manipulatorList->setReadOnly( true );
        
        /*
         *      Add everything for action map selection
         *
        statictext = (CEGUI::StaticText*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/StaticText"                     ,
                                                               (CEGUI::utf8*) "CInputSettingsWindow:ActionMapSelectText" );
        _window->addChildWindow( statictext );
        
        statictext->setText( (CEGUI::utf8*) "Action map" );
        statictext->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.5f, 0.0f ), CEGUI::UDim( 0.18f, 0.0f ) ) );
        statictext->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.05f, 0.0f ) ) );
        statictext->setFrameEnabled( false );
        statictext->setBackgroundEnabled( false );
        statictext->setHorizontalFormatting( CEGUI::StaticText::WordWrapCentred );
                 */                                                                         
        m_actionMapList = (CEGUI::Combobox*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Combobox"                   , 
                                                                  (CEGUI::utf8*) "CInputSettingsWindow:ActionMapCombobox" );
        _window->addChildWindow( m_actionMapList );
        m_actionMapList->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.5f, 0.0f ), CEGUI::UDim( 0.23f, 0.0f ) ) );
        m_actionMapList->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.2f, 0.0f ) ) );
        m_actionMapList->setReadOnly( true );                 

        /*
         *      Add uses text
         *
        statictext = (CEGUI::StaticText*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/StaticText"                   ,
                                                               (CEGUI::utf8*) "CInputSettingsWindow:ManipulatorUsesText" );
        _window->addChildWindow( statictext );
        
        statictext->setText( (CEGUI::utf8*) "uses" );
        statictext->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.35f, 0.0f ), CEGUI::UDim( 0.23f, 0.0f ) ) );
        statictext->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.05f, 0.0f ) ) );
        statictext->setFrameEnabled( false );
        statictext->setBackgroundEnabled( false );
        statictext->setHorizontalFormatting( CEGUI::StaticText::WordWrapCentred );
        */
        LoadInputProfileList();
        LoadInputManipulatorList();
}

/*-------------------------------------------------------------------------*/

CInputSettingsWindow::CInputSettingsWindow( const CInputSettingsWindow& src )
{GUCE_TRACE;
        /* dummy, do not use */
}

/*-------------------------------------------------------------------------*/

CInputSettingsWindow::~CInputSettingsWindow()
{GUCE_TRACE;
        _window->destroy();
}

/*-------------------------------------------------------------------------*/

CInputSettingsWindow* 
CInputSettingsWindow::Instance( void )
{GUCE_TRACE;
        if ( !_instance )
        {
                _instance = new CInputSettingsWindow();
        }
        return _instance;
}

/*-------------------------------------------------------------------------*/

void
CInputSettingsWindow::Deinstance( void )
{GUCE_TRACE;
        delete _instance;
        _instance = NULL;        
}

/*-------------------------------------------------------------------------*/

void 
CInputSettingsWindow::Show( void )
{GUCE_TRACE;
        _window->setVisible( true );
}

/*-------------------------------------------------------------------------*/
        
void 
CInputSettingsWindow::Hide( void )
{GUCE_TRACE;
        _window->setVisible( false );
}

/*-------------------------------------------------------------------------*/

void 
CInputSettingsWindow::LoadInputProfileList( void )
{GUCE_TRACE;
        GUCEF::CORE::CStringList profileList( m_inputProfileManager->GetProfileList() );
        if ( profileList.GetCount() )
        {
                m_profileList->setText( (CEGUI::utf8*) (profileList[ 0 ]).C_String() );
                for ( UInt32 i=0; i<profileList.GetCount(); ++i )
                {
                        m_profileList->addItem( new ListItem( (CEGUI::utf8*) (profileList[ i ]).C_String() ) );
                }
        }
}

/*-------------------------------------------------------------------------*/

void 
CInputSettingsWindow::LoadInputManipulatorList( void )
{GUCE_TRACE;
        GUCEF::CORE::CString profile( m_profileList->getText().c_str() );
        GUCEF::CORE::CStringList manipulatorList( m_inputProfileManager->GetManipulatorList() );
        
        if ( manipulatorList.GetCount() )
        {
                m_manipulatorList->setText( (CEGUI::utf8*) (manipulatorList[ 0 ]).C_String() );
                for ( UInt32 i=0; i<manipulatorList.GetCount(); ++i )
                {
                        m_manipulatorList->addItem( new ListItem( (CEGUI::utf8*) (manipulatorList[ i ]).C_String() ) );
                }
        }        
}

/*-------------------------------------------------------------------------*/

void 
CInputSettingsWindow::LoadInputActionMapList( void )
{
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/
