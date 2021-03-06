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

#include "guceGUI_CIGUIDriver.h"

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

const CString CIGUIDriver::HasGuceInterfaceDriverProperty = "hasGuceInterface";

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CIGUIDriver::CIGUIDriver( void )
    : GUCEF::GUI::CGUIDriver()
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/

CIGUIDriver::CIGUIDriver( const CIGUIDriver& src )
    : GUCEF::GUI::CGUIDriver( src )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
        
CIGUIDriver::~CIGUIDriver()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CIGUIDriver&
CIGUIDriver::operator=( const CIGUIDriver& src )
{GUCE_TRACE;

    return *this;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/
