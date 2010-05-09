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

#ifndef REFAPP_COGREDEBUGOVERLAY_H
#define REFAPP_COGREDEBUGOVERLAY_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#ifndef GUCE_CORE_CWINDOWMANAGER_H
#include "CWindowManager.h"
#define GUCE_CORE_CWINDOWMANAGER_H
#endif /* GUCE_CORE_CWINDOWMANAGER_H ? */

#ifndef __FrameListener_H__
#include "OgreFrameListener.h"
#define __FrameListener_H__
#endif /* __FrameListener_H__ ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class Overlay; class OverlayManager; }

/*-------------------------------------------------------------------------*/

class COgreDebugOverlay : protected Ogre::FrameListener
{
    public:
    
    COgreDebugOverlay( void );
    
    virtual ~COgreDebugOverlay();
              
    const Ogre::Overlay* GetOverlay( void ) const;
    
    void Show( void );
    
    void Hide( void );

    protected:
    
    /** Called when a frame is about to begin rendering.
        @return
            True to go ahead, false to abort rendering and drop
            out of the rendering loop.
    */
    virtual bool frameStarted( const Ogre::FrameEvent& evt );
    
    /** Called just after a frame has been rendered.
        @return
            True to continue with the next frame, false to drop
            out of the rendering loop.
    */
    virtual bool frameEnded( const Ogre::FrameEvent& evt );
    
    private:
    
    COgreDebugOverlay( const COgreDebugOverlay& src );
    COgreDebugOverlay& operator=( const COgreDebugOverlay& src );
    
    bool LinkOverlay( void );
    
    private:
    
    Ogre::Overlay* m_debugOverlay;
    Ogre::OverlayManager* m_overlayManager;
    GUCE::CORE::TWindowContextPtr m_window;
};

/*-------------------------------------------------------------------------*/

#endif /* REFAPP_COGREDEBUGOVERLAY_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 17-03-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/