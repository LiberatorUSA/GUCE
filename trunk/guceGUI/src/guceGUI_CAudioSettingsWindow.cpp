/*
 *  gucefGUI: GUCE module providing GUI functionality
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

#include "CEGUIWindowManager.h"
#include "CEGUIEventArgs.h"
#include "elements/CEGUIFrameWindow.h"
#include "elements/CEGUIPushButton.h"

#include "guceGUI_CAudioSettingsWindow.h"

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

CAudioSettingsWindow* CAudioSettingsWindow::_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

CAudioSettingsWindow::CAudioSettingsWindow( void )
{GUCE_TRACE;
        
        /*
         *      Create and config the main MainMenu window that holds the buttons
         */
            
        CEGUI::WindowManager* wmngr = CEGUI::WindowManager::getSingletonPtr();
        _window = (CEGUI::FrameWindow*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/FrameWindow"      , 
                                                             (CEGUI::utf8*) "CAudioSettingsWindow:Window"  );
                                                             
        wmngr->getWindow( "CSettingsWindow:Window" )->addChildWindow( _window );
        
        _window->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.02f, 0.0f ), CEGUI::UDim( 0.15f, 0.0f ) ) );
        _window->setSize( CEGUI::UVector2( CEGUI::UDim( 1.0f, 0.0f ), CEGUI::UDim( 0.85f, 0.0f ) ) );
        _window->setText( (CEGUI::utf8*) "Audio Settings" );
        _window->setCloseButtonEnabled( false );        
        _window->setVisible( false );
        _window->setDragMovingEnabled( false );
        _window->setSizingEnabled( false );     
}

/*-------------------------------------------------------------------------*/

CAudioSettingsWindow::CAudioSettingsWindow( const CAudioSettingsWindow& src )
{GUCE_TRACE;
        /* dummy, do not use */
}

/*-------------------------------------------------------------------------*/

CAudioSettingsWindow::~CAudioSettingsWindow()
{GUCE_TRACE;
        _window->destroy();
}

/*-------------------------------------------------------------------------*/

CAudioSettingsWindow* 
CAudioSettingsWindow::Instance( void )
{GUCE_TRACE;
        if ( !_instance )
        {
                _instance = new CAudioSettingsWindow();
        }
        return _instance;
}

/*-------------------------------------------------------------------------*/

void
CAudioSettingsWindow::Deinstance( void )
{GUCE_TRACE;
        delete _instance;
        _instance = NULL;        
}

/*-------------------------------------------------------------------------*/

void 
CAudioSettingsWindow::Show( void )
{GUCE_TRACE;
        _window->setVisible( true );
}

/*-------------------------------------------------------------------------*/
        
void 
CAudioSettingsWindow::Hide( void )
{GUCE_TRACE;
        _window->setVisible( false );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/
