///*
// *  gucefGUI: GUCE module providing GUI functionality
// *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
// *
// *  This library is free software; you can redistribute it and/or
// *  modify it under the terms of the GNU Lesser General Public
// *  License as published by the Free Software Foundation; either
// *  version 2.1 of the License, or (at your option) any later version.
// *
// *  This library is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// *  Lesser General Public License for more details.
// *
// *  You should have received a copy of the GNU Lesser General Public
// *  License along with this library; if not, write to the Free Software
// *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
// */
//
//#ifndef GUCE_GUI_CGUIEDITOR_H
//#define GUCE_GUI_CGUIEDITOR_H 
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      INCLUDES                                                           //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//#ifndef GUCEF_CORE_CSYSCONSOLECLIENT_H
//#include "CSysConsoleClient.h"
//#define GUCEF_CORE_CSYSCONSOLECLIENT_H
//#endif /* GUCEF_CORE_CSYSCONSOLECLIENT_H ? */
//
//#ifndef GUCEF_CORE_CISYSCONSOLECMDHANDLER_H
//#include "CISysConsoleCmdHandler.h"
//#define GUCEF_CORE_CISYSCONSOLECMDHANDLER_H
//#endif /* GUCEF_CORE_CISYSCONSOLECMDHANDLER_H ? */
//
//#ifndef GUCEF_CORE_COBSERVER_H
//#include "CObserver.h"
//#define GUCEF_CORE_COBSERVER_H
//#endif /* GUCEF_CORE_COBSERVER_H ? */
//
//#ifndef GUCEF_CORE_CDVSTRING_H
//#include "CDVString.h"                   /* string class */
//#define GUCEF_CORE_CDVSTRING_H
//#endif /* GUCEF_CORE_CDVSTRING_H ? */
//
//#ifndef GUCE_GUI_MACROS_H
//#include "guceGUI_macros.h"              /* often used guceGUI macros */
//#define GUCE_GUI_MACROS_H
//#endif /* GUCE_GUI_MACROS_H ? */
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      CLASSES                                                            //
////                                                                         //
////-------------------------------------------------------------------------*/
//
///*
// *      Forward declarations of classes used here 
// */
//namespace CEGUI{ class FrameWindow; 
//                 class Window;   
//                 class MultiColumnList; 
//                 class PushButton; 
//                 class EventArgs; 
//                 class Tree;
//                 class TreeItem;
//               }
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      NAMESPACE                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//namespace GUCE {
//namespace GUI {
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      CLASSES                                                            //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//class CGUICombobox;
//class CGUIKeyValueListWindow;
//
///*-------------------------------------------------------------------------*/
//
//class GUCEGUI_EXPORT_CPP CGUIEditor : public GUCEF::CORE::CObserver              ,
//                                      public GUCEF::CORE::CSysConsoleClient      ,
//                                      public GUCEF::CORE::CISysConsoleCmdHandler
//{
//    public:
//    
//    void Show( void );
//    
//    void Hide( void );
//    
//    static CGUIEditor* Instance( void );
//    
//    static void Deinstance( void );
//
//    protected:
//    
//    virtual bool OnSysConsoleCommand( const CString& path     ,
//                                      const CString& command             ,
//                                      const std::vector< CString >& args ,
//                                      std::vector< CString >& resultdata );    
//
//    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
//                           const GUCEF::CORE::CEvent& eventid         ,
//                           GUCEF::CORE::CICloneable* eventdata = NULL );
//
//    private:
//    
//    CGUIEditor( const CGUIEditor& src );
//    CGUIEditor& operator=( const CGUIEditor& src );
//    CGUIEditor( void );
//    virtual ~CGUIEditor();
//    
//    bool OnWindowSelected( const CEGUI::EventArgs& e );
//    bool OnCloseButtonClick( const CEGUI::EventArgs& e );
//    bool OnWindowPropertyEditButtonClick( const CEGUI::EventArgs& e );
//    bool OnNewWindowButtonClick( const CEGUI::EventArgs& e );
//    void FillWindowTree( CEGUI::Tree* windowTree );
//    void FillWindowTreeSegment( CEGUI::Window* window     ,
//                                CEGUI::TreeItem* treeItem );
//    
//    private:
//    
//    CGUICombobox* m_windowTypeList;
//    CEGUI::PushButton* m_propChangeButton;
//    CEGUI::PushButton* m_newWindowButton;
//    CEGUI::PushButton* m_closeButton;
//    CEGUI::FrameWindow* m_window;
//    CGUIKeyValueListWindow* m_keyValueListWindow;
//    UInt32 m_selectedRow;
//    CEGUI::Window* m_selectedWindow;
//    CEGUI::Tree* m_windowList;
//    static CGUIEditor* g_instance;
//};
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      NAMESPACE                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//} /* namespace GUI */
//} /* namespace GUCE */
//
///*-------------------------------------------------------------------------*/
//
//#endif /* GUCE_GUI_CGUIEDITOR_H ? */
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      Info & Changes                                                     //
////                                                                         //
////-------------------------------------------------------------------------//
//
//- 08-04-2007 :
//        - Initial implementation
//
//---------------------------------------------------------------------------*/