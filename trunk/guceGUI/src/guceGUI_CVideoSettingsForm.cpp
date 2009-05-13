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

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#include "guceGUI_CVideoSettingsForm.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace GUI {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

CVideoSettingsForm::CVideoSettingsForm( void )
    : CFormEx()                      ,
      m_resolutionLabel( NULL )      ,
      m_resolutionCombobox( NULL )   ,
      m_antiAliasingLabel( NULL )    ,
      m_antiAliasingCombobox( NULL ) ,
      m_fullscreenCheckbox( NULL )   ,
      m_vSyncCheckbox( NULL )        ,
      m_applyButton( NULL )          
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CVideoSettingsForm::~CVideoSettingsForm()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

void
CVideoSettingsForm::OnPreLayoutLoad( void )
{GUCE_TRACE;

    if ( NULL != m_resolutionLabel ) { UnsubscribeFrom( m_resolutionLabel ); m_resolutionLabel = NULL; }
    if ( NULL != m_resolutionCombobox ) { UnsubscribeFrom( m_resolutionCombobox ); m_resolutionCombobox = NULL; }
    if ( NULL != m_antiAliasingLabel ) { UnsubscribeFrom( m_antiAliasingLabel ); m_antiAliasingLabel = NULL; }
    if ( NULL != m_antiAliasingCombobox ) { UnsubscribeFrom( m_antiAliasingCombobox ); m_antiAliasingCombobox = NULL; }
    if ( NULL != m_fullscreenCheckbox ) { UnsubscribeFrom( m_fullscreenCheckbox ); m_fullscreenCheckbox = NULL; }
    if ( NULL != m_vSyncCheckbox ) { UnsubscribeFrom( m_vSyncCheckbox ); m_vSyncCheckbox = NULL; }
    if ( NULL != m_applyButton ) { UnsubscribeFrom( m_applyButton ); m_applyButton = NULL; }
}

/*-------------------------------------------------------------------------*/

void
CVideoSettingsForm::OnPostLayoutLoad( void )
{GUCE_TRACE;

    m_resolutionLabel = static_cast< GUCEF::GUI::CLabel* >( GetWidget( "ResolutionLabel" ) );
    m_resolutionCombobox = static_cast< GUCEF::GUI::CCombobox* >( GetWidget( "ResolutionCombobox" ) );
    m_antiAliasingLabel = static_cast< GUCEF::GUI::CLabel* >( GetWidget( "AntiAliasingLabel" ) );
    m_antiAliasingCombobox = static_cast< GUCEF::GUI::CCombobox* >( GetWidget( "AntiAliasingCombobox" ) );
    m_fullscreenCheckbox = static_cast< GUCEF::GUI::CCheckbox* >( GetWidget( "FullscreenCheckbox" ) );
    m_vSyncCheckbox = static_cast< GUCEF::GUI::CCheckbox* >( GetWidget( "vSyncCheckbox" ) );
    m_applyButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "ApplyButton" ) );
    
    SubscribeTo( m_resolutionLabel );
    SubscribeTo( m_resolutionCombobox );
    SubscribeTo( m_antiAliasingLabel );
    SubscribeTo( m_antiAliasingCombobox );
    SubscribeTo( m_fullscreenCheckbox );
    SubscribeTo( m_vSyncCheckbox );
    SubscribeTo( m_applyButton );
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CLabel*
CVideoSettingsForm::GetResolutionLabel( void )
{GUCE_TRACE;

    return m_resolutionLabel;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CCombobox*
CVideoSettingsForm::GetResolutionCombobox( void )
{GUCE_TRACE;

    return m_resolutionCombobox;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CLabel*
CVideoSettingsForm::GetAntiAliasingLabel( void )
{GUCE_TRACE;

    return m_antiAliasingLabel;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CCombobox*
CVideoSettingsForm::GetAntiAliasingCombobox( void )
{GUCE_TRACE;

    return m_antiAliasingCombobox;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CCheckbox*
CVideoSettingsForm::GetFullscreenCheckbox( void )
{GUCE_TRACE;

    return m_fullscreenCheckbox;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CCheckbox*
CVideoSettingsForm::GetVSyncCheckbox( void )
{GUCE_TRACE;

    return m_vSyncCheckbox;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CButton*
CVideoSettingsForm::GetApplyButton( void )
{GUCE_TRACE;

    return m_applyButton;
}

/*-------------------------------------------------------------------------*/

bool
CVideoSettingsForm::SetVideoSettings( const CORE::CVideoSettings& settings )
{GUCE_TRACE;
    
    if ( NULL != m_fullscreenCheckbox ) 
    {
        m_fullscreenCheckbox->SetCheckedState( settings.GetFullscreenState() );
    }
    if ( NULL != m_vSyncCheckbox )
    {
        m_vSyncCheckbox->SetCheckedState( settings.GetVSyncState() );
    }
    if ( NULL != m_antiAliasingCombobox )
    {
        m_antiAliasingCombobox->SetText( GUCEF::CORE::UInt32ToString( settings.GetAntiAliasingFactor() ) );
    }
    if ( NULL != m_resolutionCombobox )
    {
        TDisplayMode displayMode;
        settings.GetDisplayMode( displayMode );
        m_resolutionCombobox->SetText( ParseDisplayMode( displayMode ) );
    }
    return true;
}

/*-------------------------------------------------------------------------*/
    
bool
CVideoSettingsForm::GetVideoSettings( CORE::CVideoSettings& settings ) const
{GUCE_TRACE;
    
    if ( NULL != m_fullscreenCheckbox ) 
    {
        settings.SetFullscreenState( m_fullscreenCheckbox->GetCheckedState() );
    }
    if ( NULL != m_vSyncCheckbox )
    {
        settings.SetVSyncState( m_vSyncCheckbox->GetCheckedState() );
    }
    if ( NULL != m_antiAliasingCombobox )
    {
        CString aaText = m_antiAliasingCombobox->GetText();
        settings.SetAntiAliasingFactor( GUCEF::CORE::StringToUInt32( aaText ) );
    }
    if ( NULL != m_resolutionCombobox )
    {
        CString resText = m_resolutionCombobox->GetText();
        
        TDisplayMode displayMode;
        ParseDisplayModeString( resText, displayMode );
        settings.SetDisplayMode( displayMode );
    }
    return true;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettingsForm::ParseDisplayModeString( const CString& rez        ,
                                            TDisplayMode& displayMode ) const
{GUCE_TRACE;

    CString tmp, resStr( rez );
    resStr = resStr.CutChars( 2, false );
    tmp = resStr.SubstrToChar( '@', false );
    displayMode.frequency = GUCEF::CORE::StringToUInt32( tmp );
    resStr = resStr.CutChars( 1+tmp.Length(), false );
    tmp = resStr.SubstrToChar( 'x', false );
    displayMode.depthInBits = GUCEF::CORE::StringToUInt32( tmp );
    resStr = resStr.CutChars( 1+tmp.Length(), false );
    tmp = resStr.SubstrToChar( 'x', false );
    displayMode.heightInPixels = GUCEF::CORE::StringToUInt32( tmp );
    resStr = resStr.CutChars( 1+tmp.Length(), false );
    displayMode.widthInPixels = GUCEF::CORE::StringToUInt32( resStr );
}

/*-------------------------------------------------------------------------*/

CString
CVideoSettingsForm::ParseDisplayMode( const TDisplayMode& displayMode ) const
{GUCE_TRACE;

    CString resText = GUCEF::CORE::UInt32ToString( displayMode.widthInPixels );
    resText += 'x' + GUCEF::CORE::UInt32ToString( displayMode.heightInPixels );
    resText += 'x' + GUCEF::CORE::UInt32ToString( displayMode.depthInBits );
    resText += '@' + GUCEF::CORE::UInt32ToString( displayMode.frequency ) + "Hz";    
    return resText;
}

/*-------------------------------------------------------------------------*/

bool
CVideoSettingsForm::SetVideoOptions( const CORE::CVideoOptions& options )
{GUCE_TRACE;

    m_videoOptions = options;
    
    if ( NULL != m_resolutionCombobox )
    {
        m_resolutionCombobox->ClearList();
        
        const CORE::CVideoOptions::TDisplayModeVector& modes = options.GetDisplayModes();
        GUCEF::GUI::CCombobox::TStringVector resList;
        for ( UInt32 i=0; i<modes.size(); ++i )
        {
            const CORE::CVideoOptions::TDisplayMode& displayMode = modes[ i ];
            resList.push_back( ParseDisplayMode( displayMode ) );
        }
        
        if ( m_resolutionCombobox->SetListItems( resList ) )
        {
            return true;
        }
    }
    
    return false;
}

/*-------------------------------------------------------------------------*/
    
bool
CVideoSettingsForm::GetVideoOptions( CORE::CVideoOptions& options ) const
{GUCE_TRACE;

    options = m_videoOptions;
    return true;
}

/*-------------------------------------------------------------------------*/

const CString&
CVideoSettingsForm::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString classTypeName = "GUCE::GUI::CVideoSettingsForm";
    return classTypeName;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
