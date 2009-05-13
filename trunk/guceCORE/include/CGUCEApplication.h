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

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#define GUCE_CORE_CGUCEAPPLICATION_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <map>

#ifndef GUCEFMT_H
#include "gucefMT.h"            /* gucefMT library API */
#define GUCEFMT_H
#endif /* GUCEFMT_H ? */

#ifndef GUCEFCORE_H
#include "gucefCORE.h"          /* gucefCORE library API */
#define GUCEFCORE_H
#endif /* GUCEFCORE_H ? */ 

#ifndef GUCEF_INPUT_CINPUTOBSERVERSWITCH_H
#include "gucefINPUT_CInputObserverSwitch.h"
#define GUCEF_INPUT_CINPUTOBSERVERSWITCH_H
#endif /* GUCEF_INPUT_CINPUTOBSERVERSWITCH_H ? */

#ifndef GUCE_CORE_CWINDOWMANAGER_H
#include "CWindowManager.h"
#define GUCE_CORE_CWINDOWMANAGER_H
#endif /* GUCE_CORE_CWINDOWMANAGER_H ? */

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"    /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#ifndef GUCEF_CORE_CCODECREGISTRY_H
#include "CCodecRegistry.h"
#define GUCEF_CORE_CCODECREGISTRY_H
#endif /* GUCEF_CORE_CCODECREGISTRY_H ? */

#ifndef GUCE_CORE_COGREIMAGECODECADAPTER_H
#include "COgreImageCodecAdapter.h"
#define GUCE_CORE_COGREIMAGECODECADAPTER_H
#endif /* GUCE_CORE_COGREIMAGECODECADAPTER_H ? */

#ifndef GUCE_CORE_CMESHMANAGER_H
#include "guceCORE_CMeshManager.h"
#define GUCE_CORE_CMESHMANAGER_H
#endif /* GUCE_CORE_CMESHMANAGER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class Root; 
                 class RenderSystem; 
                 class SceneManager; 
                 class Camera;       
                 class Viewport;      
                 class SceneNode;    }
                 
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class CVideoSettings;
class CWindowContext;
class COgreLogToGUCEFLogAdapter;

/*-------------------------------------------------------------------------*/

/**
 *      One of the most important GUCE classes. It ties the different systems
 *      into each other. The application cycle is represented with a single 
 *      generic interface trough Main(), Update() and Stop().
 *
 *      Dispatches the following event:
 *       - "GUCE::CORE::CGUCEApplication::AppInitEvent"
 *              Signals that, following an initialization on the GUCEF level,
 *              the GUCE application is now initialized.
 *              It is now safe to use the OGRE and GUCEF facilities. 
 */
class GUCE_CORE_EXPORT_CPP CGUCEApplication : public GUCEF::CORE::CObservingNotifier ,
                                              public GUCEF::CORE::CIConfigurable   
{
    public:

    static const GUCEF::CORE::CEvent AppInitEvent;
    static const GUCEF::CORE::CEvent AppShutdownEvent;
    static const GUCEF::CORE::CEvent VideoSetupCompletedEvent;
    static const GUCEF::CORE::CEvent VideoShutdownImminentEvent;
    
    static void RegisterEvents( void );
    
    public:
    
    static CGUCEApplication* Instance( void );              

    #ifdef GUCE_MSWIN_BUILD
    /**
     *      main function of your GUCE Application. Should be called from 
     *      your application's entry point function. This version is for
     *      Microsoft Windows applications that use WinMain as there entry
     *      point.
     *
     *      @param hinstance process instance handle
     *      @param lpcmdline command line application arguments
     *      @param ncmdshow win32 specific info
     *      @param run Whether or not you want the Main() to return or take over application control.      
     *      @return Application error code, usually ignored by Windows.
     */        
    int Main( HINSTANCE hinstance     ,
              LPSTR lpcmdline         ,
              int ncmdshow            ,
              bool run                );
              
    #endif
    
    /**
     *      main function of your GUCE Application. Should be called from 
     *      your application's entry point function.
     *
     *      @param argc the number of application command line arguments
     *      @param argv command line application arguments
     *      @param run Whether or not you want the Main() to return or take over application control.      
     *      @return Application error code / success value
     */
    int main( int argc    ,
              char** argv ,
              bool run    );

    void Update( void );

    void Stop( void );

    virtual ~CGUCEApplication();
    
    /**
     *      Attempts to store the given tree in the file
     *      given according to the method of the codec meta data
     *
     *      @param tree the data tree you wish to store
     *      @return whether storing the tree was success full
     */
    virtual bool SaveConfig( GUCEF::CORE::CDataNode& tree );
                                
    /**
     *      Attempts to load data from the given file to the 
     *      root node given. The root data will be replaced 
     *      and any children the node may already have will be deleted.
     *
     *      @param treeroot pointer to the node that is to act as root of the data tree
     *      @return whether building the tree from the given file was successfull.
     */                                    
    virtual bool LoadConfig( const GUCEF::CORE::CDataNode& treeroot );
    
    bool SetupOgreRenderSys( const GUCEF::CORE::CDataNode& rootnode           ,
                             Ogre::RenderSystem** selectedRenderSystem = NULL );
    
    bool SetupWindow( const GUCEF::CORE::CDataNode& rootnode                   ,
                      CWindowManager::TWindowContextPtr* windowsContext = NULL );
    
    bool SetupOgreScene( CWindowManager::TWindowContextPtr& windowContext ,
                         Ogre::SceneManager** sceneManager = NULL         ,
                         Ogre::SceneNode** worldNode       = NULL         ,
                         Ogre::Camera** camera             = NULL         ,
                         Ogre::Viewport** viewport         = NULL         );

    bool SetupOgreVideo( const GUCEF::CORE::CDataNode& rootnode                  ,
                         Ogre::RenderSystem** renderSystem = NULL                ,
                         CWindowManager::TWindowContextPtr* windowContext = NULL );
    
    bool SetupOgreRecources( const GUCEF::CORE::CDataNode& rootnode );
    
    bool SetupOgrePlugins( const GUCEF::CORE::CDataNode& rootnode );
    
    Ogre::SceneManager* GetSceneManager( void );
    
    CWindowManager::TWindowContextPtr GetPrimaryWindowContext( void );
    
    bool ApplyVideoSettings( const CVideoSettings& settings );
    
    CMeshManager& GetMeshManager( void );
    
    GUCEF::INPUT::CInputObserverSwitch& GetInputObserverSwitch( void );
    
    protected:
        
    /**
     *  Event callback member function.
     *  Implement this in your descending class to handle
     *  notification events.
     *
     *  @param notifier the notifier that sent the notification
     *  @param eventid the unique event id for an event
     *  @param eventdata optional notifier defined userdata
     */
    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
                           const GUCEF::CORE::CEvent& eventid         ,
                           GUCEF::CORE::CICloneable* eventdata = NULL );
    
    private:
    friend class CGUCECOREModule;
    
    static void Deinstance( void );                             

    private:

    typedef std::map< GUCEF::CORE::CString, COgreImageCodecAdapter* > TImageCodecMap;
    
    CGUCEApplication( void );                         /**< initializes sub-systems */
    CGUCEApplication( const CGUCEApplication& src );  /**< not implemented */
    CGUCEApplication& operator=( const CGUCEApplication& src ); /**< not implemented */
    
    bool SetupOgre( void );                                      /**< Sets up Ogre and connects the adapters */
    void ShutdownOgreVideo( void );                              /**< shutdown the video subsystem */
    void AppInitHandler( const GUCEF::CORE::CEvent& event );     /**< Handler for application init events */
    void AppShutdownHandler( const GUCEF::CORE::CEvent& event ); /**< Handler for application shutdown events */
    void RegisterGUCEFImageCodecsInOgre( void );
    void RegisterGUCEFImageCodecInOgre( const GUCEF::CORE::CString& codecType );
    
    GUCEF::CORE::CDataNode m_videoSettings;
    GUCEF::CORE::CGUCEFApplication* _gucefapp;   /**< pointer to the GUCEF Application class for easy access */
    Ogre::Root* m_ogreRoot;                      /**< pointer to the Ogre Root class for easy access */
    Ogre::SceneManager* m_sceneManager;
    COgreLogToGUCEFLogAdapter* m_ogreLogAdapter; /**< adapter for Ogre logging redirection to GUCEF logging */
    bool _fatalerror;                            /**< flag for fatal init errors */
    bool _initialized;                           /**< flag to indicate if everything is initialized */ 
    CWindowManager::TWindowContextPtr m_windowContext;
    TImageCodecMap m_imageCodecMap;
    GUCEF::CORE::CCodecRegistry::TCodecFamilyRegistryPtr m_gucefImageCodecs;
    CMeshManager m_meshManager;
    GUCEF::INPUT::CInputObserverSwitch m_inputObserverSwitch;
    
    static CGUCEApplication* _instance;
    static GUCEF::MT::CMutex _mutex;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 12-11-2004 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
 