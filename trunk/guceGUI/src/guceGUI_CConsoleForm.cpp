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

#include "guceGUI_CConsoleForm.h"

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

CConsoleForm::CConsoleForm( void )
    : CFormEx()                ,
      m_inputEditbox( NULL )   ,
      m_consoleTextbox( NULL )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CConsoleForm::~CConsoleForm()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

void
CConsoleForm::OnPreLayoutLoad( void )
{GUCE_TRACE;

    CFormEx::OnPreLayoutLoad();

    m_inputEditbox = NULL;
    m_consoleTextbox = NULL;
}

/*-------------------------------------------------------------------------*/

void
CConsoleForm::OnPostLayoutLoad( void )
{GUCE_TRACE;

    CFormEx::OnPostLayoutLoad();
    
    m_inputEditbox = static_cast< GUCEF::GUI::CEditbox* >( GetWidget( "InputEditbox" ) );
    m_consoleTextbox = static_cast< GUCEF::GUI::CTextbox* >( GetWidget( "ConsoleTextbox" ) );
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CEditbox*
CConsoleForm::GetInputEditbox( void )
{GUCE_TRACE;
    
    return m_inputEditbox;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CTextbox*
CConsoleForm::GetConsoleTextbox( void )
{GUCE_TRACE;

    return m_consoleTextbox;
}

/*-------------------------------------------------------------------------*/

const CString&
CConsoleForm::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString classTypeName = "GUCE::GUI::CConsoleForm";
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
