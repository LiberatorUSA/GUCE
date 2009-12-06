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
 
#ifndef GUCE_CORE_CWINDOWMANAGER_H
#define GUCE_CORE_CWINDOWMANAGER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef __ROOT__
#include <OgreRoot.h>           /* needed for Ogre::NameValuePairList */
#define __ROOT__
#endif /* __ROOT__ ? */

#ifndef GUCEF_CORE_CTSHAREDPTR_H
#include "CTSharedPtr.h"
#define GUCEF_CORE_CTSHAREDPTR_H
#endif /* GUCEF_CORE_CTSHAREDPTR_H ? */

#ifndef GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H
#include "gucefCORE_CTEventHandlerFunctor.h"
#define GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H
#endif /* GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H ? */

#ifndef GUCEF_CORE_CTDYNAMICDESTRUCTORBASE_H
#include "CTDynamicDestructorBase.h"
#define GUCEF_CORE_CTDYNAMICDESTRUCTORBASE_H
#endif /* GUCEF_CORE_CTDYNAMICDESTRUCTORBASE_H ? */

#ifndef GUCEF_CORE_COBSERVINGNOTIFIER_H
#include "CObservingNotifier.h"
#define GUCEF_CORE_COBSERVINGNOTIFIER_H
#endif /* GUCEF_CORE_COBSERVINGNOTIFIER_H ? */

#ifndef CWINDOWCONTEXT_H
#include "CWindowContext.h"     /* the context for a single window */
#define CWINDOWCONTEXT_H
#endif /* CWINDOWCONTEXT_H ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF { namespace CORE { class CDataNode; } }

/*-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class CVideoSettings;

/*-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP CWindowManager : public GUCEF::CORE::CObservingNotifier                         ,
                                            private GUCEF::CORE::CTDynamicDestructorBase< CWindowContext >
{
    public:
    typedef GUCEF::CORE::CTSharedPtr< CWindowContext > TWindowContextPtr;
    
    static const GUCEF::CORE::CEvent PrimaryWindowContextCreatedEvent;
    static const GUCEF::CORE::CEvent PrimaryWindowContextDestroyedEvent;
    static const GUCEF::CORE::CEvent WindowContextCreatedEvent;
    static const GUCEF::CORE::CEvent WindowContextDestroyedEvent;
    
    typedef GUCEF::CORE::CTCloneableObj< TWindowContextPtr >    TWindowContextCreatedEventData;
    typedef GUCEF::CORE::CTCloneableObj< TWindowContextPtr >    TWindowContextDestroyedEventData;
    
    static void RegisterEvents( void );
    
    public:
    
    static CWindowManager* Instance( void );
    
    TWindowContextPtr CreateWindowContext( const CString& title  ,
                                           const UInt32 width    ,
                                           const UInt32 height   ,
                                           const bool fullscreen );

    TWindowContextPtr CreateWindowContext( const GUCEF::CORE::CDataNode& config ,
                                           const CString& title = ""            );

    TWindowContextPtr CreateWindowContext( const CString& title                         ,
                                           const CVideoSettings& settings               ,
                                           const Ogre::NameValuePairList* params = NULL );

    TWindowContextPtr CreateWindowContext( const CString& title                  ,
                                           const UInt32 width                    ,
                                           const UInt32 height                   ,
                                           const bool fullscreen                 ,
                                           const Ogre::NameValuePairList& params );
    
    void DestroyWindowContext( TWindowContextPtr& windowContext );
    
    bool ApplyVideoSettings( TWindowContextPtr& windowContext ,
                             const CVideoSettings& settings   );
    
    protected:
    
    /**
     *  Event callback member function.
     *
     *  Note: Do NOT  forget to call this class's implementation
     *  from your descending class or you will break the event 
     *  forwarding mechanism.
     *
     *  @param notifier the notifier that sent the notification
     *  @param eventid the unique event id for an event
     *  @param eventdata optional notifier defined userdata
     */
    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
                           const GUCEF::CORE::CEvent& eventid         ,
                           GUCEF::CORE::CICloneable* eventdata = NULL );    
    
    private:
    
    virtual void DestroyObject( CWindowContext* context );
    
    void DestroyWindowContextImp( CWindowContext* windowContext );
    
    CWindowManager( void );
    CWindowManager( const CWindowManager& src );
    virtual ~CWindowManager();
    CWindowManager& operator=( const CWindowManager& src );        

    private:
    friend class CGUCECOREModule;
    
    static void Deinstance( void );
    
    private:
    
    void OnPulse( GUCEF::CORE::CNotifier* notifier           ,
                  const GUCEF::CORE::CEvent& eventid         ,
                  GUCEF::CORE::CICloneable* eventdata = NULL );
    
    private:
    typedef std::vector< TWindowContextPtr > TWindowList;
    typedef GUCEF::CORE::CTEventHandlerFunctor< CWindowManager > TEventCallback;
    
    static CWindowManager* m_instance;
    
    TWindowList m_windowlist;
    void* m_osWindowLink;
    bool m_busyChangingVideoSettings;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CWINDOWMANAGER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
