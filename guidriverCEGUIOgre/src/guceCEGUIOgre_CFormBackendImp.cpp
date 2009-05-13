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

#ifndef _CEGUIWindow_h_
#include "CEGUIWindow.h"
#define _CEGUIWindow_h_
#endif /* _CEGUIWindow_h_ ? */

#ifndef _CEGUIWindowManager_h_
#include "CEGUIWindowManager.h"
#define _CEGUIWindowManager_h_
#endif /* _CEGUIWindowManager_h_ ? */

#ifndef __Exception_H_
#include "OgreException.h"
#define __Exception_H_
#endif /* __Exception_H_ ? */

#ifndef __ROOT__
#include "OgreRoot.h"
#define __ROOT__
#endif /* __ROOT__ ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCE_CORE_CIOACCESSARCHIVEFACTORY_H
#include "CIOAccessArchiveFactory.h"
#define GUCE_CORE_CIOACCESSARCHIVEFACTORY_H
#endif /* GUCE_CORE_CIOACCESSARCHIVEFACTORY_H ? */

#ifndef GUCE_CEGUIOGRE_CBUTTONIMP_H
#include "guceCEGUIOgre_CButtonImp.h"
#define GUCE_CEGUIOGRE_CBUTTONIMP_H
#endif /* GUCE_CEGUIOGRE_CBUTTONIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CEDITBOXIMP_H
#include "guceCEGUIOgre_CEditboxImp.h"
#define GUCE_CEGUIOGRE_CEDITBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CEDITBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CLISTBOXIMP_H
#include "guceCEGUIOgre_CListboxImp.h"
#define GUCE_CEGUIOGRE_CLISTBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CLISTBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CWINDOWIMP_H
#include "guceCEGUIOgre_CWindowImp.h"
#define GUCE_CEGUIOGRE_CWINDOWIMP_H
#endif /* GUCE_CEGUIOGRE_CWINDOWIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CIMAGEFRAMEIMP_H
#include "guceCEGUIOgre_CImageFrameImp.h"
#define GUCE_CEGUIOGRE_CIMAGEFRAMEIMP_H
#endif /* GUCE_CEGUIOGRE_CIMAGEFRAMEIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CHECKBOXIMP_H
#include "guceCEGUIOgre_CCheckboxImp.h"
#define GUCE_CEGUIOGRE_CHECKBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CHECKBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CCOMBOBOXIMP_H
#include "guceCEGUIOgre_CComboboxImp.h"
#define GUCE_CEGUIOGRE_CCOMBOBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CCOMBOBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CTABCONTROLIMP_H
#include "guceCEGUIOgre_CTabControlImp.h"
#define GUCE_CEGUIOGRE_CTABCONTROLIMP_H
#endif /* GUCE_CEGUIOGRE_CTABCONTROLIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CTABCONTENTPANEIMP_H
#include "guceCEGUIOgre_CTabContentPaneImp.h"
#define GUCE_CEGUIOGRE_CTABCONTENTPANEIMP_H
#endif /* GUCE_CEGUIOGRE_CTABCONTENTPANEIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CGRIDVIEWIMP_H
#include "guceCEGUIOgre_CGridViewImp.h"
#define GUCE_CEGUIOGRE_CGRIDVIEWIMP_H
#endif /* GUCE_CEGUIOGRE_CGRIDVIEWIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CLABELIMP_H
#include "guceCEGUIOgre_CLabelImp.h"
#define GUCE_CEGUIOGRE_CLABELIMP_H
#endif /* GUCE_CEGUIOGRE_CLABELIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CSPINNERIMP_H
#include "guceCEGUIOgre_CSpinnerImp.h"
#define GUCE_CEGUIOGRE_CSPINNERIMP_H
#endif /* GUCE_CEGUIOGRE_CSPINNERIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CRENDERCONTEXTIMP_H
#include "guceCEGUIOgre_CRenderContextImp.h"
#define GUCE_CEGUIOGRE_CRENDERCONTEXTIMP_H
#endif /* GUCE_CEGUIOGRE_CRENDERCONTEXTIMP_H ? */

#include "guceCEGUIOgre_CFormBackendImp.h"

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

CFormBackendImp::CFormBackendImp( void )
    : CFormBackend()        ,
      m_widgetMap()         ,
      m_rootWindow( NULL )  ,
      m_widgetNamePrefix()  ,
      m_resourceGroupName() ,
      m_dummyArchive( NULL )
{GUCE_TRACE;

    m_resourceGroupName = "GUCE::CEGUIOGRE::CFormBackendImp::" + GUCEF::CORE::PointerToString( this );
    m_widgetNamePrefix = m_resourceGroupName + '/';    
    
    // provide hacky access to data we get in the CFormBackend API
    Ogre::Root::getSingletonPtr()->addResourceLocation( m_resourceGroupName      , 
                                                        "GUCEF::CORE::CIOAccess" ,
                                                        m_resourceGroupName      );
    m_dummyArchive = (*CORE::CIOAccessArchiveFactory::Instance()->GetArchiveMap().find( m_resourceGroupName )).second;
}

/*-------------------------------------------------------------------------*/
    
CFormBackendImp::~CFormBackendImp()
{GUCE_TRACE;

    Ogre::Root::getSingletonPtr()->removeResourceLocation( m_resourceGroupName, m_resourceGroupName );
    m_dummyArchive = NULL;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CWidget*
CFormBackendImp::CreateAndHookWrapperForWindow( CEGUI::Window* window )
{GUCE_TRACE;

    GUCEF::GUI::CWidget* widgetWrapper = NULL;
    CString typeName( CString( window->getType().c_str() ).SubstrToChar( '/', false ) );
    
    if ( "Button" == typeName )
    {
        widgetWrapper = new CButtonImp();
        static_cast< CButtonImp* >( widgetWrapper )->Hook( static_cast< CEGUI::PushButton* >( window ) );
    }
    else
    if ( "Editbox" == typeName )
    {
        widgetWrapper = new CEditboxImp();
        static_cast< CEditboxImp* >( widgetWrapper )->Hook( static_cast< CEGUI::Editbox* >( window ) );        
    }
    else
    if ( "Listbox" == typeName )
    {
        widgetWrapper = new CListboxImp();
        static_cast< CListboxImp* >( widgetWrapper )->Hook( static_cast< CEGUI::Listbox* >( window ) );        
    }
    else
    if ( "StaticImage" == typeName )
    {
        CString widgetName( CString( window->getName().c_str() ).SubstrToChar( '/', false ) );
        
        if ( widgetName == "RenderContext" )
        {
            widgetWrapper = new CRenderContextImp();
            static_cast< CRenderContextImp* >( widgetWrapper )->Hook( window );
        }
        else
        {
            widgetWrapper = new CImageFrameImp();
            static_cast< CImageFrameImp* >( widgetWrapper )->Hook( window );
        }
    }
    else    
    if ( "StaticText" == typeName )
    {
        widgetWrapper = new CLabelImp();
        static_cast< CLabelImp* >( widgetWrapper )->Hook( window );
    }    
    else    
    if ( "Checkbox" == typeName )
    {
        widgetWrapper = new CCheckboxImp();
        static_cast< CCheckboxImp* >( widgetWrapper )->Hook( static_cast< CEGUI::Checkbox* >( window ) );        
    }
    else    
    if ( "Combobox" == typeName )
    {
        widgetWrapper = new CComboboxImp();
        static_cast< CComboboxImp* >( widgetWrapper )->Hook( static_cast< CEGUI::Combobox* >( window ) );        
    }
    if ( "TabControl" == typeName )
    {
        widgetWrapper = new CTabControlImp();
        static_cast< CTabControlImp* >( widgetWrapper )->Hook( static_cast< CEGUI::TabControl* >( window ) );        
    }        
    else
    if ( "TabContentPane" == typeName )
    {
        widgetWrapper = new CTabContentPaneImp();
        static_cast< CTabContentPaneImp* >( widgetWrapper )->Hook( window );        
    }        
    else        
    if ( "FrameWindow" == typeName )
    {
        widgetWrapper = new CWindowImp();
        static_cast< CWindowImp* >( widgetWrapper )->Hook( static_cast< CEGUI::FrameWindow* >( window ) );        
    }
    else        
    if ( "MultiColumnList" == typeName )
    {
        widgetWrapper = new CGridViewImp();
        static_cast< CGridViewImp* >( widgetWrapper )->Hook( static_cast< CEGUI::MultiColumnList* >( window ) );        
    }
    else        
    if ( "Spinner" == typeName )
    {
        widgetWrapper = new CSpinnerImp();
        static_cast< CSpinnerImp* >( widgetWrapper )->Hook( static_cast< CEGUI::Spinner* >( window ) );        
    }        
    else
    if ( "DefaultWindow" == typeName )
    {
        widgetWrapper = new TBasicWidgetImp();
        static_cast< TBasicWidgetImp* >( widgetWrapper )->Hook( window );
    }
    
    GUCEF_DEBUG_LOG( 0, "Wrapped and hooked GUI widget for CEGUI widget of type " + typeName );
    return widgetWrapper;
}

/*-------------------------------------------------------------------------*/

void
CFormBackendImp::WrapAndHookChildWindows( CEGUI::Window* window )
{GUCE_TRACE;

    GUCEF::GUI::CWidget* widget = NULL;
    CEGUI::Window* childWindow = NULL;
    size_t i=0;
    size_t childCount = window->getChildCount();
    while ( i < childCount )
    {
        childWindow = window->getChildAtIdx( i );
        widget = CreateAndHookWrapperForWindow( childWindow );
        if ( NULL != widget )
        {
            CString localWidgetName = widget->GetName().SubstrToChar( '/', false );
            m_widgetMap[ localWidgetName ] = widget;
        }
        
        WrapAndHookChildWindows( childWindow );
        
        ++i;                       
    }
}

/*-------------------------------------------------------------------------*/

bool
CFormBackendImp::LoadLayout( GUCEF::CORE::CIOAccess& layoutStorage )
{GUCE_TRACE;
    
    CEGUI::Window* rootWindow = NULL;
    CEGUI::WindowManager* wmgr = CEGUI::WindowManager::getSingletonPtr();
    
    GUCEF_DEBUG_LOG( 0, "Starting layout load for a GUI Form" );
    
    try
    {
        // provide hacky access to the given data
        m_dummyArchive->AddResource( layoutStorage, "currentFile" );

        // Now we can load the window layout from the given storage
        // Note that if CEGUI ever provides an interface to do this directly
        // clean up this mess !!!
        rootWindow = wmgr->loadWindowLayout( "currentFile"                  , 
                                             m_widgetNamePrefix.C_String()  ,
                                             m_resourceGroupName.C_String() );     
        m_dummyArchive->ClearResourceList();
    }
    catch ( Ogre::Exception& e )
    {
        GUCEF_ERROR_LOG( 0, CString( "Ogre Exception while attempting to load form layout: " ) + e.getFullDescription().c_str() );
        return false;
    }
    
    // Now that we completed loading lets see what we got from CEGUI
    if ( NULL != rootWindow )
    {
        // Begin by providing a wrapper for the root window
        m_rootWindow = CreateAndHookWrapperForWindow( rootWindow );
        if ( NULL != m_rootWindow )
        {
            CString localWidgetName = m_rootWindow->GetName().SubstrToChar( '/', false );
            m_widgetMap[ localWidgetName ] = m_rootWindow;
            WrapAndHookChildWindows( rootWindow );
            
            // We will directly add the form as a child of the root for now
            CEGUI::Window* globalRootWindow = wmgr->getWindow( "root" );
            if ( NULL != globalRootWindow )
            {
                globalRootWindow->addChildWindow( rootWindow );
                
                GUCEF_DEBUG_LOG( 0, "Successfully loaded a GUI Form layout" );
                return true;                
            }
            else
            {
                GUCEF_ERROR_LOG( 0, "Failed to add form as a child to the global \"root\" window" );    
            }
        }
        rootWindow->hide();
    }

    GUCEF_DEBUG_LOG( 0, "Failed to loaded a GUI Form layout" );
    return false; 
}

/*-------------------------------------------------------------------------*/
    
bool
CFormBackendImp::SaveLayout( GUCEF::CORE::CIOAccess& layoutStorage )
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CWidget*
CFormBackendImp::GetRootWidget( void )
{GUCE_TRACE;

    return m_rootWindow;
}

/*-------------------------------------------------------------------------*/
    
const GUCEF::GUI::CWidget*
CFormBackendImp::GetRootWidget( void ) const
{GUCE_TRACE;

    return m_rootWindow;
}
    
/*-------------------------------------------------------------------------*/

GUCEF::GUI::CWidget*
CFormBackendImp::GetWidget( const CString& widgetName )
{GUCE_TRACE;

    TWidgetMap::iterator i = m_widgetMap.find( widgetName );
    if ( i != m_widgetMap.end() )
    {
        return (*i).second;
    }
    
    return NULL;
}

/*-------------------------------------------------------------------------*/
    
void
CFormBackendImp::GetWidgetVector( const CString& widgetName   ,
                                  TWidgetVector& widgetVector )
{GUCE_TRACE;

    TWidgetMap::iterator i = m_widgetMap.begin();
    while ( i != m_widgetMap.end() )
    {
        widgetVector.push_back( (*i).second );
        ++i;
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
