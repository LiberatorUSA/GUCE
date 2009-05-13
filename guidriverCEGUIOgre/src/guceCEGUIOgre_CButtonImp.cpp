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

#ifndef GUCEF_CORE_CTRACER_H
#include "CTracer.h"
#define GUCEF_CORE_CTRACER_H
#endif /* GUCEF_CORE_CTRACER_H ? */

#include "guceCEGUIOgre_CButtonImp.h"

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

CButtonImp::CButtonImp( void )
    : CWidgetImp< GUCEF::GUI::CButton >() ,
      m_button( NULL )
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

CButtonImp::~CButtonImp()
{GUCEF_TRACE;

    m_button = NULL;
}

/*-------------------------------------------------------------------------*/
    
bool
CButtonImp::SetButtonText( const CString& newText )
{GUCEF_TRACE;

    if ( NULL != m_button )
    {
        m_button->setText( newText.C_String() );
    }
    return true;
}

/*-------------------------------------------------------------------------*/
    
bool
CButtonImp::GetButtonText( CString& text ) const
{GUCEF_TRACE;

    if ( NULL != m_button )
    {
        text = m_button->getText().c_str();
    }
    return true;
}

/*-------------------------------------------------------------------------*/

void
CButtonImp::Hook( CEGUI::PushButton* button )
{GUCEF_TRACE;

    m_button = button;
    CWidgetImp< GUCEF::GUI::CButton >::Hook( button );
    
    m_button->subscribeEvent( CEGUI::PushButton::EventClicked                        ,
                              CEGUI::Event::Subscriber( &CButtonImp::OnButtonClick , 
                                                        this                       ) );    

    m_button->subscribeEvent( CEGUI::Window::EventMouseButtonDown                  ,
                              CEGUI::Event::Subscriber( &CButtonImp::OnMouseDown ,
                                                        this                     ) );

    m_button->subscribeEvent( CEGUI::Window::EventMouseButtonUp                   ,
                              CEGUI::Event::Subscriber( &CButtonImp::OnMouseUp  ,
                                                        this                    ) );
}

/*-------------------------------------------------------------------------*/

bool
CButtonImp::OnButtonClick( const CEGUI::EventArgs& e )
{GUCEF_TRACE;

    NotifyObservers( ButtonClickedEvent );
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CButtonImp::OnMouseDown( const CEGUI::EventArgs& e )
{GUCEF_TRACE;

    CWidgetImp< GUCEF::GUI::CButton >::OnMouseDown( e );
    NotifyObservers( ButtonDownEvent );
    return true;
}

/*-------------------------------------------------------------------------*/

bool
CButtonImp::OnMouseUp( const CEGUI::EventArgs& e )
{GUCEF_TRACE;

    CWidgetImp< GUCEF::GUI::CButton >::OnMouseUp( e );
    NotifyObservers( ButtonUpEvent );
    return true;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
