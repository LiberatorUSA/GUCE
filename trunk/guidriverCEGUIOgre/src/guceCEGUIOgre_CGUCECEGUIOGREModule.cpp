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

#ifndef GUCEF_GUI_CGUIMANAGER_H
#include "gucefGUI_CGUIManager.h"
#define GUCEF_GUI_CGUIMANAGER_H
#endif /* GUCEF_GUI_CGUIMANAGER_H ? */

#ifndef GUCE_GUI_CGUIMANAGER_H
#include "CGUIManager.h"
#define GUCE_GUI_CGUIMANAGER_H
#endif /* GUCE_GUI_CGUIMANAGER_H ? */

#ifndef GUCE_CEGUIOGRE_H
#include "guceCEGUIOgre.h"
#define GUCE_CEGUIOGRE_H
#endif /* GUCE_CEGUIOGRE_H ? */

#include "guceCEGUIOgre_CGUCECEGUIOGREModule.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      TYPES                                                              //
//                                                                         //
//-------------------------------------------------------------------------*/

typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CFormBackend, CFormBackendImp > TFormBackendFactory;

typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, TBasicWidgetImp >    TWidgetFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CWindowImp >         TWindowFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CButtonImp >         TButtonFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CPushButtonImp >     TPushButtonFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CEditboxImp >        TEditboxFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CListboxImp >        TListboxFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CImageFrameImp >     TImageFrameFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CCheckboxImp >       TCheckboxFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CLabelImp >          TLabelFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CComboboxImp >       TComboboxFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CTabControlImp >     TTabControlFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CTabContentPaneImp > TTabContentPaneFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CGridViewImp >       TGridViewFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CSpinnerImp >        TSpinnerFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CWidget, CRenderContextImp >  TRenderContextFactory;

typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CForm, CFileOpenDialogImp >   TFileOpenDialogFactory;
typedef GUCEF::CORE::CTFactory< GUCEF::GUI::CForm, CFileSaveDialogImp >   TFileSaveDialogFactory;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

bool
CGUCECEGUIOGREModule::Load( void )
{GUCE_TRACE;

    // Register all widgets at the GUCEF level
    GUCEF::GUI::CGUIManager& guiManager = *GUCEF::GUI::CGUIManager::Instance();
    GUCEF::GUI::CWidgetFactory& widgetFactory = guiManager.GetWidgetFactory();
    GUCEF::GUI::CFormFactory& formFactory = guiManager.GetFormFactory();
    
    guiManager.SetFormBackendFactory( new TFormBackendFactory() );
    
    widgetFactory.RegisterConcreteFactory( "Widget", new TWidgetFactory() );
    widgetFactory.RegisterConcreteFactory( "Window", new TWindowFactory() );
    widgetFactory.RegisterConcreteFactory( "Button", new TButtonFactory() );
    widgetFactory.RegisterConcreteFactory( "PushButton", new TPushButtonFactory() );
    widgetFactory.RegisterConcreteFactory( "Editbox", new TEditboxFactory() );
    widgetFactory.RegisterConcreteFactory( "Listbox", new TListboxFactory() );
    widgetFactory.RegisterConcreteFactory( "ImageFrame", new TImageFrameFactory() );
    widgetFactory.RegisterConcreteFactory( "Checkbox", new TCheckboxFactory() );
    widgetFactory.RegisterConcreteFactory( "Label", new TLabelFactory() );
    widgetFactory.RegisterConcreteFactory( "Combobox", new TComboboxFactory() );
    widgetFactory.RegisterConcreteFactory( "TabControl", new TTabControlFactory() );
    widgetFactory.RegisterConcreteFactory( "TabContentPane", new TTabContentPaneFactory() );
    widgetFactory.RegisterConcreteFactory( "GridView", new TGridViewFactory() );
    widgetFactory.RegisterConcreteFactory( "Spinner", new TSpinnerFactory() );
    widgetFactory.RegisterConcreteFactory( "RenderContext", new TRenderContextFactory() );
    
    formFactory.RegisterConcreteFactory( "FileOpenDialog", new TFileOpenDialogFactory );
    formFactory.RegisterConcreteFactory( "FileSaveDialog", new TFileSaveDialogFactory );

    // Register the GUI Driver at the GUCE level
    GUCE::GUI::CGUIManager& ogreGuiManager = *GUCE::GUI::CGUIManager::Instance();
    ogreGuiManager.RegisterGUIDriver( "CEGUIOgre", *CGUIDriver::Instance() );
    
    return true;
}

/*-------------------------------------------------------------------------*/
    
bool
CGUCECEGUIOGREModule::Unload( void )
{GUCE_TRACE;

    // Unregister all widgets at the GUCEF level
    GUCEF::GUI::CGUIManager& guiManager = *GUCEF::GUI::CGUIManager::Instance();
    GUCEF::GUI::CWidgetFactory& widgetFactory = guiManager.GetWidgetFactory();
    GUCEF::GUI::CFormFactory& formFactory = guiManager.GetFormFactory();
    
    formFactory.UnregisterConcreteFactory( "FileOpenDialog" );
    formFactory.UnregisterConcreteFactory( "FileSaveDialog" );

    widgetFactory.UnregisterConcreteFactory( "Widget" );
    widgetFactory.UnregisterConcreteFactory( "Window" );
    widgetFactory.UnregisterConcreteFactory( "Button" );
    widgetFactory.UnregisterConcreteFactory( "PushButton" );
    widgetFactory.UnregisterConcreteFactory( "Editbox" );
    widgetFactory.UnregisterConcreteFactory( "Listbox" );
    widgetFactory.UnregisterConcreteFactory( "ImageFrame" );
    widgetFactory.UnregisterConcreteFactory( "Checkbox" );
    widgetFactory.UnregisterConcreteFactory( "Label" );
    widgetFactory.UnregisterConcreteFactory( "Combobox" );
    widgetFactory.UnregisterConcreteFactory( "TabControl" );
    widgetFactory.UnregisterConcreteFactory( "TabContentPane" );
    widgetFactory.UnregisterConcreteFactory( "GridView" );
    widgetFactory.UnregisterConcreteFactory( "Spinner" );
    widgetFactory.UnregisterConcreteFactory( "RenderContext" );

    GUCEF::GUI::CFormBackendFactory* formBackendFactory = guiManager.GetFormBackendFactory();
    guiManager.SetFormBackendFactory( NULL );
    delete formBackendFactory;

    // Unregister the GUI Driver at the GUCE level
    GUCE::GUI::CGUIManager& ogreGuiManager = *GUCE::GUI::CGUIManager::Instance();
    ogreGuiManager.UnregisterGUIDriver( "CEGUIOgre" );    
    CGUIDriver::Deinstance();
    
    return true;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
