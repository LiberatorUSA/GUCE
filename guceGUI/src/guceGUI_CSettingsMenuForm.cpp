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

#include "guceGUI_CSettingsMenuForm.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace GUI {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CSettingsMenuForm::CSettingsMenuForm( void )
    : CFormEx()                             ,
      m_settingsWindow( NULL )              ,
      m_menuButton( NULL )                  ,
      m_settingsTabControl( NULL )          ,
      m_videoSettingsTabContentPane( NULL ) ,
      m_audioSettingsTabContentPane( NULL ) ,
      m_inputSettingsTabContentPane( NULL ) ,
      m_videoSettingsForm()
{GUCE_TRACE;

    SubscribeTo( &m_videoSettingsForm, GUCEF::GUI::CForm::LayoutLoadedEvent );
}

/*-------------------------------------------------------------------------*/
    
CSettingsMenuForm::~CSettingsMenuForm()
{GUCE_TRACE;

}
    
/*-------------------------------------------------------------------------*/

void
CSettingsMenuForm::OnPreLayoutLoad( void )
{GUCE_TRACE;

    if ( NULL != m_settingsWindow ) { UnsubscribeFrom( m_settingsWindow ); m_settingsWindow = NULL; }
    if ( NULL != m_menuButton ) { UnsubscribeFrom( m_menuButton ); m_menuButton = NULL; }
    if ( NULL != m_settingsTabControl ) { UnsubscribeFrom( m_settingsTabControl ); m_settingsTabControl = NULL; }
    if ( NULL != m_videoSettingsTabContentPane ) { UnsubscribeFrom( m_videoSettingsTabContentPane ); m_videoSettingsTabContentPane = NULL; }
    if ( NULL != m_audioSettingsTabContentPane ) { UnsubscribeFrom( m_audioSettingsTabContentPane ); m_audioSettingsTabContentPane = NULL; }
    if ( NULL != m_inputSettingsTabContentPane ) { UnsubscribeFrom( m_inputSettingsTabContentPane ); m_inputSettingsTabContentPane = NULL; }
}

/*-------------------------------------------------------------------------*/

void
CSettingsMenuForm::OnPostLayoutLoad( void )
{GUCE_TRACE;

    m_settingsWindow = static_cast< GUCEF::GUI::CWindow* >( GetWidget( "SettingsWindow" ) );
    m_menuButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "MenuButton" ) );
    m_settingsTabControl = static_cast< GUCEF::GUI::CTabControl* >( GetWidget( "SettingsTabControl" ) );
    m_videoSettingsTabContentPane = static_cast< GUCEF::GUI::CTabContentPane* >( GetWidget( "VideoSettingsTabContentPane" ) );
    m_audioSettingsTabContentPane = static_cast< GUCEF::GUI::CTabContentPane* >( GetWidget( "AudioSettingsTabContentPane" ) );
    m_inputSettingsTabContentPane = static_cast< GUCEF::GUI::CTabContentPane* >( GetWidget( "InputSettingsTabContentPane" ) );
    
    SubscribeTo( m_settingsWindow );
    SubscribeTo( m_menuButton );
    SubscribeTo( m_settingsTabControl );
    SubscribeTo( m_videoSettingsTabContentPane );
    SubscribeTo( m_audioSettingsTabContentPane );
    SubscribeTo( m_inputSettingsTabContentPane );
    
    m_videoSettingsForm.SetParent( m_videoSettingsTabContentPane );
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CButton*
CSettingsMenuForm::GetMenuButton( void )
{GUCE_TRACE;

    return m_menuButton;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CWindow*
CSettingsMenuForm::GetSettingsWindow( void )
{GUCE_TRACE;

    return m_settingsWindow;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CTabControl*
CSettingsMenuForm::GetSettingsTabControl( void )
{GUCE_TRACE;

    return m_settingsTabControl;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CTabContentPane*
CSettingsMenuForm::GetVideoSettingsTabPane( void )
{GUCE_TRACE;

    return m_videoSettingsTabContentPane;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CTabContentPane*
CSettingsMenuForm::GetAudioSettingsTabPane( void )
{GUCE_TRACE;

    return m_audioSettingsTabContentPane;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CTabContentPane*
CSettingsMenuForm::GetInputSettingsTabPane( void )
{GUCE_TRACE;

    return m_inputSettingsTabContentPane;
}

/*-------------------------------------------------------------------------*/

CVideoSettingsForm&
CSettingsMenuForm::GetVideoSettingsForm( void )
{GUCE_TRACE;
    
    return m_videoSettingsForm;
}

/*-------------------------------------------------------------------------*/

bool
CSettingsMenuForm::SetActiveTab( const UInt32 tabIndex )
{GUCE_TRACE;

    if ( NULL != m_settingsTabControl )
    {
        return m_settingsTabControl->SetActiveTab( tabIndex );
    }
    return false;
}

/*-------------------------------------------------------------------------*/

const CString&
CSettingsMenuForm::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString className = "GUCE::GUI::CSettingsMenuForm";
    return className;
}

/*-------------------------------------------------------------------------*/

void
CSettingsMenuForm::OnNotify( GUCEF::CORE::CNotifier* notifier    ,
                             const GUCEF::CORE::CEvent& eventid  ,
                             GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    if ( notifier == &m_videoSettingsForm )
    {
        if ( GUCEF::GUI::CForm::LayoutLoadedEvent == eventid )
        {
            m_videoSettingsForm.SetParent( m_videoSettingsTabContentPane );
        }
    }    
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
