/*
 *  guceCORE: GUCE module providing tie-in functionality between systems
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
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

#include <assert.h>

#ifndef __RenderWindow_H__
#include "OgreRenderWindow.h"
#define __RenderWindow_H__
#endif /* __RenderWindow_H__ ? */

#ifndef CINPUTCONTEXT_H
#include "CInputContext.h"
#define CINPUTCONTEXT_H
#endif /* CINPUTCONTEXT_H ? */

#include "CWindowContext.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

const GUCEF::CORE::CEvent CWindowContext::WindowContextSizeEvent = "GUCE::CORE::CWindowContext::WindowContextSizeEvent";
const GUCEF::CORE::CEvent CWindowContext::WindowContextActivateEvent = "GUCE::CORE::CWindowContext::WindowContextActivateEvent";

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CWindowContext::CWindowContext( Ogre::RenderWindow* window                ,
                                GUCEF::INPUT::CInputContext* inputcontext )
        : m_window( window )             ,
          m_inputcontext( inputcontext ) ,
          m_id( 0UL )                    ,
          m_active( false )
{GUCE_TRACE;
        
        assert( window && inputcontext );                
        RegisterEvents();
}

/*-------------------------------------------------------------------------*/                                

CWindowContext::~CWindowContext()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

void
CWindowContext::RegisterEvents( void )
{GUCE_TRACE;

    WindowContextSizeEvent.Initialize();
    WindowContextActivateEvent.Initialize();
}

/*-------------------------------------------------------------------------*/

Ogre::RenderWindow* 
CWindowContext::GetOgreWindowPtr( void )
{GUCE_TRACE;
        return m_window;
}

/*-------------------------------------------------------------------------*/
        
GUCEF::INPUT::CInputContext* 
CWindowContext::GetInputContext( void )
{GUCE_TRACE;

    return m_inputcontext;
}

/*-------------------------------------------------------------------------*/

void
CWindowContext::SetGuiContext( GUCEF::GUI::TGuiContextPtr& context )
{GUCE_TRACE;

    m_guiContext = context;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::TGuiContextPtr
CWindowContext::GetGuiContext( void )
{GUCE_TRACE;

    return m_guiContext;
}

/*-------------------------------------------------------------------------*/

void
CWindowContext::SetID( const UInt32 id )
{GUCE_TRACE;

    m_id = id;
}

/*-------------------------------------------------------------------------*/

UInt32
CWindowContext::GetID( void ) const
{GUCE_TRACE;
        return m_id;
}

/*-------------------------------------------------------------------------*/

void 
CWindowContext::SetActive( const bool isactive )
{GUCE_TRACE;

    if ( m_active != isactive )
    {
        m_active = isactive;
        
        WindowContextActivateEventData eData( isactive );
        NotifyObservers( WindowContextActivateEvent, &eData );
    }
}

/*-------------------------------------------------------------------------*/

bool 
CWindowContext::IsActive( void ) const
{GUCE_TRACE;
    
    return m_active;
}

/*-------------------------------------------------------------------------*/

void
CWindowContext::OnWindowContextSize( const UInt32 newWidth  ,
                                     const UInt32 newHeight )
{GUCE_TRACE;

    NotifyObservers( WindowContextSizeEvent );
}                              

/*-------------------------------------------------------------------------*/

CString
CWindowContext::GetName( void ) const
{GUCE_TRACE;

    return m_window->getName().c_str();
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/
