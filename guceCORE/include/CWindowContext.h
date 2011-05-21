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

#ifndef GUCE_CORE_CWINDOWCONTEXT_H
#define GUCE_CORE_CWINDOWCONTEXT_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_CNOTIFIER_H
#include "CNotifier.h"
#define GUCEF_CORE_CNOTIFIER_H
#endif /* GUCEF_CORE_CNOTIFIER_H ? */

#ifndef GUCEF_CORE_CLONEABLES_H
#include "cloneables.h"
#define GUCEF_CORE_CLONEABLES_H
#endif /* GUCEF_CORE_CLONEABLES_H ? */

#ifndef GUCEF_CORE_CTSHAREDPTR_H
#include "CTSharedPtr.h"
#define GUCEF_CORE_CTSHAREDPTR_H
#endif /* GUCEF_CORE_CTSHAREDPTR_H ? */

#ifndef GUCEF_GUI_CIGUICONTEXT_H
#include "gucefGUI_CIGUIContext.h"
#define GUCEF_GUI_CIGUICONTEXT_H
#endif /* GUCEF_GUI_CIGUICONTEXT_H ? */

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class RenderWindow; }
namespace GUCEF { namespace INPUT { class CInputContext; class CIInputHandler; } }

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class CWindowManager;
class CIWindowContextHandler;

/*-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP CWindowContext : GUCEF::CORE::CNotifier
{        
    public:
    
    static const GUCEF::CORE::CEvent WindowContextSizeEvent;
    static const GUCEF::CORE::CEvent WindowContextActivateEvent;

    typedef GUCEF::CORE::TCloneableBool WindowContextActivateEventData;
    
    static void RegisterEvents( void );
    
    public:
    
    Ogre::RenderWindow* GetOgreWindowPtr( void );
    
    GUCEF::INPUT::CInputContext* GetInputContext( void );
    
    void SetGuiContext( GUCEF::GUI::TGuiContextPtr& context );
    
    GUCEF::GUI::TGuiContextPtr GetGuiContext( void );
    
    UInt32 GetID( void ) const;
    
    bool IsActive( void ) const;
    
    CString GetName( void ) const;
    
    virtual ~CWindowContext();
    
    private:
    friend class CWindowManager;
    
    CWindowContext( Ogre::RenderWindow* window                ,
                    GUCEF::INPUT::CInputContext* inputcontext );
    
    void SetID( const UInt32 id );
    
    void OnWindowContextSize( const UInt32 newWidth  ,
                              const UInt32 newHeight );
    
    private:
    friend class CWindowManagerAccessProxy;
    
    void SetActive( const bool isactive );
    
    private:
    
    CWindowContext( void );                                 /**< cannot be used, need params */
    CWindowContext( const CWindowContext& src );            /**< private because: must be unique */ 
    CWindowContext& operator=( const CWindowContext& src ); /**< private because: must be unique */        
    
    private:
    
    Ogre::RenderWindow* m_window;
    GUCEF::INPUT::CInputContext* m_inputcontext;
    GUCEF::GUI::TGuiContextPtr m_guiContext;
    UInt32 m_id;
    bool m_active;
};

/*-------------------------------------------------------------------------*/

typedef GUCEF::CORE::CTSharedPtr< CWindowContext > TWindowContextPtr;

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CWINDOWCONTEXT_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-10-2005 :
        - Initial version

-----------------------------------------------------------------------------*/
