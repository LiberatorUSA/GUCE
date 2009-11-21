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

#include "guceCEGUIOgre_CPushButtonImp.h"

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

CPushButtonImp::CPushButtonImp( void )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CPushButtonImp::~CPushButtonImp()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
bool
CPushButtonImp::SetButtonText( const CString& newText )
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/
    
bool
CPushButtonImp::GetButtonText( CString& text ) const
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/

void
CPushButtonImp::Hook( CEGUI::PushButton* button )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/