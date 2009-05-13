/*
 *  guceCEGUIOgre: glue module for the CEGUI+Ogre GUI backend
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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

#ifndef _CEGUISystem_h_
#include "CEGUISystem.h"
#define _CEGUISystem_h_
#endif /* _CEGUISystem_h_ ? */

#ifndef GUCEF_INPUT_CKEYSTATECHANGEDEVENTDATA_H
#include "gucefINPUT_CKeyStateChangedEventData.h"
#define GUCEF_INPUT_CKEYSTATECHANGEDEVENTDATA_H
#endif /* GUCEF_INPUT_CKEYSTATECHANGEDEVENTDATA_H ? */

#ifndef GUCEF_INPUT_CMOUSEBUTTONEVENTDATA_H
#include "gucefINPUT_CMouseButtonEventData.h"
#define GUCEF_INPUT_CMOUSEBUTTONEVENTDATA_H
#endif /* GUCEF_INPUT_CMOUSEBUTTONEVENTDATA_H ? */

#ifndef GUCEF_INPUT_CMOUSEMOVEDEVENTDATA_H
#include "gucefINPUT_CMouseMovedEventData.h"
#define GUCEF_INPUT_CMOUSEMOVEDEVENTDATA_H
#endif /* GUCEF_INPUT_CMOUSEMOVEDEVENTDATA_H ? */

#ifndef GUCEF_INPUT_CINPUTCONTROLLER_H
#include "CInputController.h"
#define GUCEF_INPUT_CINPUTCONTROLLER_H
#endif /* GUCEF_INPUT_CINPUTCONTROLLER_H ? */

#ifndef GUCE_GUI_MACROS_H
#include "guceGUI_macros.h"              /* often used guceGUI macros */
#define GUCE_GUI_MACROS_H
#endif /* GUCE_GUI_MACROS_H ? */

#include "guceCEGUIOgre_CInputCEGUIManipulator.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

inline CEGUI::MouseButton 
ConvertButtonIndexToCEGui( const UInt32 buttonindex )
{GUCE_TRACE;

    switch ( buttonindex )
    {
        case 0:
        {
            return CEGUI::LeftButton;
        }                        
        case 1:
        {
            return CEGUI::RightButton;
        }                        
        case 2:
        {
            return CEGUI::MiddleButton;
        }        
        case 3:
        {
            return CEGUI::X1Button;
        }                        
        case 4:
        {
            return CEGUI::X2Button;
        }                
        default:
        {
            return CEGUI::LeftButton;
        }                        
    }
}

/*-------------------------------------------------------------------------*/

CInputCEGUIManipulator::CInputCEGUIManipulator( const CString& name )
    : GUCEF::CORE::CObserver()                                        ,
      m_guisystem( CEGUI::System::getSingletonPtr() )                 ,
      m_inputController( GUCEF::INPUT::CInputController::Instance() )
{GUCE_TRACE;

    SubscribeTo( m_inputController );
}

/*-------------------------------------------------------------------------*/

CInputCEGUIManipulator::~CInputCEGUIManipulator()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
const CString&
CInputCEGUIManipulator::GetClassTypeName( void ) const
{GUCE_TRACE;

    static const CString classTypeName = "GUCE::CEGUIOGRE::CInputCEGUIManipulator";
    return classTypeName;
}

/*-------------------------------------------------------------------------*/

void
CInputCEGUIManipulator::AquireCEGUILink( void )
{GUCE_TRACE;

    m_guisystem = CEGUI::System::getSingletonPtr();
}

/*-------------------------------------------------------------------------*/

void
CInputCEGUIManipulator::OnNotify( GUCEF::CORE::CNotifier* notifier                 ,
                                  const GUCEF::CORE::CEvent& eventid               ,
                                  GUCEF::CORE::CICloneable* eventdata /* = NULL */ )
{GUCE_TRACE;

    if ( NULL != m_guisystem )
    {
        if ( GUCEF::INPUT::CMouse::MouseButtonEvent == eventid )
        {
            GUCEF::INPUT::CMouseButtonEventData* eData = static_cast< GUCEF::INPUT::CMouseButtonEventData* >( eventdata );
            if ( eData->GetPressedState() )
            {
                m_guisystem->injectMouseButtonDown( ConvertButtonIndexToCEGui( eData->GetButtonIndex() ) );
            }
            else
            {
                m_guisystem->injectMouseButtonUp( ConvertButtonIndexToCEGui( eData->GetButtonIndex() ) );
            }
            return;
        }
        if ( GUCEF::INPUT::CMouse::MouseMovedEvent == eventid )
        {
            GUCEF::INPUT::CMouseMovedEventData* eData = static_cast< GUCEF::INPUT::CMouseMovedEventData* >( eventdata );
            m_guisystem->injectMousePosition( (float) eData->GetXPos() ,
                                              (float) eData->GetYPos() );
            return;
        }
        if ( GUCEF::INPUT::CKeyboard::KeyStateChangedEvent == eventid )
        {
            GUCEF::INPUT::CKeyStateChangedEventData* eData = static_cast< GUCEF::INPUT::CKeyStateChangedEventData* >( eventdata );
            if ( eData->GetKeyPressedState() )
            {
                UInt32 unicode = 0;
                GUCEF::INPUT::CKeyboard& keyboard = m_inputController->GetKeyboard( eData->GetDeviceID() );
                if ( keyboard.GetUnicodeForKeyCode( eData->GetKeyCode()             ,
                                                    eData->GetKeyModPressedStates() ,
                                                    unicode                         ) )
                {
                    m_guisystem->injectChar( unicode );
                }
                
                // The CEGUI scancode values are the same as those used by gucefINPUT
                // as such a simple cast is sufficient to perform the translation
                m_guisystem->injectKeyDown( (CEGUI::uint32) eData->GetKeyCode() );
            }
            else
            {
                // The CEGUI scancode values are the same as those used by gucefINPUT
                // as such a simple cast is sufficient to perform the translation
                m_guisystem->injectKeyUp( (CEGUI::uint32) eData->GetKeyCode() );
            }                
            return;
        }
    }
    
    if ( GUCEF::INPUT::CInputController::MouseAttachedEvent == eventid )
    {
        Int32 deviceID = static_cast< GUCEF::INPUT::CInputController::TMouseAttachedEventData* >( eventdata )->GetData();
        GUCEF::INPUT::CMouse& mouse = m_inputController->GetMouse( deviceID );
        SubscribeTo( &mouse );
    }
    if ( GUCEF::INPUT::CInputController::KeyboardAttachedEvent == eventid )
    {
        Int32 deviceID = static_cast< GUCEF::INPUT::CInputController::TKeyboardAttachedEventData* >( eventdata )->GetData();
        GUCEF::INPUT::CKeyboard& keyboard = m_inputController->GetKeyboard( deviceID );
        SubscribeTo( &keyboard );
    }
}
                                                    
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CEGUIOGRE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/


