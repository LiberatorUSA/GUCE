/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2005.  All rights reserved.
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

#ifndef GUCE_GUI_CGUIMANAGER_H
#define GUCE_GUI_CGUIMANAGER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_COBSERVINGNOTIFIER_H
#include "CObservingNotifier.h"
#define GUCEF_CORE_COBSERVINGNOTIFIER_H
#endif /* GUCEF_CORE_COBSERVINGNOTIFIER_H ? */

#ifndef GUCE_GUI_CIGUIDRIVER_H
#include "guceGUI_CIGUIDriver.h"
#define GUCE_GUI_CIGUIDRIVER_H
#endif /* GUCE_GUI_CIGUIDRIVER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Forward declarations of classes used here 
 */
namespace Ogre { class RenderWindow; class RenderTexture; class Root; }
namespace CEGUI { class System; class Window; class Texture; class Imageset; }
namespace GUCEF { namespace CORE { class CDataNode; } }

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

class GUCE_GUI_EXPORT_CPP CGUIManager : public GUCEF::CORE::CObservingNotifier ,
                                        public GUCEF::CORE::CIConfigurable
{
    public:
    
    static const GUCEF::CORE::CEvent GUIInitializedEvent;
    
    static void RegisterEvents( void );
    
    public:
    
    static CGUIManager* Instance( void );
    
    virtual bool LoadConfig( const GUCEF::CORE::CDataNode& rootNode );
    
    virtual bool SaveConfig( GUCEF::CORE::CDataNode& tree );
    
    void RegisterGUIDriver( const CString& driverName ,
                            CIGUIDriver& driver       );

    void UnregisterGUIDriver( const CString& driverName );
    
    const CString& GetSelectedDriverName( void ) const;
    
    virtual const CString& GetClassTypeName( void ) const;

    protected:

    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
                           const GUCEF::CORE::CEvent& eventid         ,
                           GUCEF::CORE::CICloneable* eventdata = NULL );
    
    private:
    friend class CGUCEGUIModule;
    
    static void Deinstance( void );
    
    private:
    
    CGUIManager( void );
    CGUIManager( const CGUIManager& src );
    virtual ~CGUIManager();
    CGUIManager& operator=( const CGUIManager& src );
    
    bool Init( CORE::CWindowManager::TWindowContextPtr windowContext );
    
    void ShutdownGUISystems( void );
    
    private:
    
    typedef std::map< CString, CIGUIDriver* >   TDriverMap;
    
    static CGUIManager* m_instance;
    
    bool m_initialized;                         /**< flag for manager initialization */
    TDriverMap m_drivers;
    CString m_selectedDriverName;
    GUCEF::CORE::CDataNode m_guiConfig;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} // namespace GUI
} // namespace GUCE

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_CGUIMANAGER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 20-01-2006 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
