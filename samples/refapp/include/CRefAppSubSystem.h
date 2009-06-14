/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2007.  All rights reserved.
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

#ifndef REFAPP_CREFAPPSUBSYSTEM_H
#define REFAPP_CREFAPPSUBSYSTEM_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#ifndef GUCEF_CORE_COBSERVINGNOTIFIER_H
#include "CObservingNotifier.h"
#define GUCEF_CORE_COBSERVINGNOTIFIER_H
#endif /* GUCEF_CORE_COBSERVINGNOTIFIER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class Overlay; }
class COgreDebugOverlay;

/*-------------------------------------------------------------------------*/

class CRefAppSubSystem : public GUCEF::CORE::CObservingNotifier
{
    public:
    
    CRefAppSubSystem( void );
    
    virtual ~CRefAppSubSystem();
    
    /**
     *  Event callback member function.
     *
     *  @param notifier the notifier that sent the notification
     *  @param eventid the unique event id for an event
     *  @param eventdata optional notifier defined user data
     */
    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
                           const GUCEF::CORE::CEvent& eventid         ,
                           GUCEF::CORE::CICloneable* eventdata = NULL );    
                           
    protected:
    
    virtual void OnUpdate( const GUCEF::CORE::UInt64 tickCount               ,
                           const GUCEF::CORE::Float64 updateDeltaInMilliSecs );    

    private:
    
    CRefAppSubSystem( const CRefAppSubSystem& src );
    CRefAppSubSystem& operator=( const CRefAppSubSystem& src );
    
    private:
    
    //GUCE::GUI::CGUIConsole* m_console;
    COgreDebugOverlay* m_debugOverlay;
};

/*-------------------------------------------------------------------------*/

#endif /* REFAPP_CREFAPPSUBSYSTEM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 14-01-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/