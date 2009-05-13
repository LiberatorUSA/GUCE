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
///*-------------------------------------------------------------------------//
////                                                                         //
////      INCLUDES                                                           //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//#include "CEGUIWindowManager.h"
//#include "CEGUIWindowFactoryManager.h"
//#include "CEGUIWindowFactory.h"
//#include "CEGUIEventArgs.h"
//#include "CEGUIExceptions.h"
//#include "elements/CEGUIListboxItem.h"
//#include "elements/CEGUIPushButton.h"
//#include "elements/CEGUICombobox.h"
//#include "elements/CEGUIFrameWindow.h"
//#include "elements/CEGUIMultiColumnList.h"
//#include "elements/CEGUIMultiLineEditbox.h"
//#include "elements/CEGUIEditbox.h"
//#include "elements/CEGUITree.h"
//
//#ifndef CGUIEDITBOX_H
//#include "CGUIEditbox.h"
//#define CGUIEDITBOX_H
//#endif /* CGUIEDITBOX_H ? */
//
//#ifndef GUCE_GUI_CGUICOMBOBOX_H
//#include "CGUICombobox.h"
//#define GUCE_GUI_CGUICOMBOBOX_H
//#endif /* GUCE_GUI_CGUICOMBOBOX_H ? */
//
//#ifndef GUCE_GUI_CGUIKEYVALUELISTWINDOW_H
//#include "guceGUI_CGUIKeyValueListWindow.h"
//#define GUCE_GUI_CGUIKEYVALUELISTWINDOW_H
//#endif /* GUCE_GUI_CGUIKEYVALUELISTWINDOW_H ? */
//
//#ifndef GUCEF_CORE_CLOGMANAGER_H
//#include "CLogManager.h"
//#define GUCEF_CORE_CLOGMANAGER_H
//#endif /* GUCEF_CORE_CLOGMANAGER_H ? */
//
//#include "guceGUI_CGUIEditor.h"
//
//        // TEST
//     //   #include "guceGUI_CGUIFileOpenDialog.h"
//     //   #include "guceGUI_CVFSInfoProvider.h"
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
////      GLOBAL VARS                                                        //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//CGUIEditor* CGUIEditor::g_instance = NULL;
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      CLASSES                                                            //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//CGUIEditor::CGUIEditor( void )
//    : m_windowTypeList( NULL )     ,
//      m_window( NULL )             ,
//      m_newWindowButton( NULL )    ,
//      m_closeButton( NULL )        ,
//      m_propChangeButton( NULL )   ,
//      m_keyValueListWindow( NULL ) ,
//      m_selectedRow( 0 )           ,
//      m_selectedWindow( NULL )     ,
//      m_windowList( NULL )
//{GUCE_TRACE;
//
//    CEGUI::WindowManager* wmngr = CEGUI::WindowManager::getSingletonPtr();
//    m_window = (CEGUI::FrameWindow*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/FrameWindow" , 
//                                                          (CEGUI::utf8*) "CGUIEditor:Window"       );
//
//    wmngr->getWindow( "root" )->addChildWindow( m_window );
//
//    m_window->setPosition( CEGUI::UVector2( CEGUI::UDim( -0.5f, 0.0f ), CEGUI::UDim( -0.5f, 0.0f ) ) );
//    m_window->setSize( CEGUI::UVector2( CEGUI::UDim( 0.3f, 0.0f ), CEGUI::UDim( 0.5f, 0.0f ) ) );
//    m_window->setCloseButtonEnabled( true );        
//    m_window->setVisible( true );
//    m_window->setDragMovingEnabled( true );
//    m_window->setSizingEnabled( true );        
//    m_window->setTitleBarEnabled( true );
//    //m_window->setSizingBorderThickness( 0.0f );   
//    m_window->setAlwaysOnTop( true );
//    m_window->setClippedByParent( false );
//
//    m_window->subscribeEvent( CEGUI::FrameWindow::EventCloseClicked                     ,
//                              CEGUI::Event::Subscriber( &CGUIEditor::OnCloseButtonClick , 
//                                                        this                            ) );
//   
//    m_windowTypeList = new CGUICombobox( "CGUIEditor:Window"         ,
//                                         "CGUIEditor:WindowTypeList" );
//    
//    CEGUI::WindowFactoryManager* winFacMan = CEGUI::WindowFactoryManager::getSingletonPtr();
//    CEGUI::WindowFactoryManager::WindowFactoryIterator i = winFacMan->getIterator();
//    while ( !i.isAtEnd() )
//    {   
//        const CEGUI::WindowFactory* fac = *i;
//        m_windowTypeList->AddItem( fac->getTypeName().c_str() );        
//        ++i;
//    }
//    
//    CEGUI::Combobox* windowTypeListWidget = m_windowTypeList->GetCombobox();
//    windowTypeListWidget->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.04f, 0.0f ), CEGUI::UDim( 0.04f, 0.0f ) ) );
//    windowTypeListWidget->setSize( CEGUI::UVector2( CEGUI::UDim( 0.92f, 0.0f ), CEGUI::UDim( 0.35f, 0.0f ) ) );    
//    windowTypeListWidget->setReadOnly( true );
//    windowTypeListWidget->setVisible( false );
//    
//    m_windowList = (CEGUI::Tree*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Tree" ,
//                                                       (CEGUI::utf8*) "CGUIEditor:WindowTree" );      
//    m_window->addChildWindow( m_windowList );
//    m_windowList->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.04f, 0.0f ), CEGUI::UDim( 0.04f, 0.0f ) ) );
//    m_windowList->setSize( CEGUI::UVector2( CEGUI::UDim( 0.92f, 0.0f ), CEGUI::UDim( 0.85f, 0.0f ) ) );    
//    m_windowList->setMultiselectEnabled( false );
//    m_windowList->setVisible( true );       
//    m_windowList->show();
//    FillWindowTree( m_windowList );
//    m_windowList->subscribeEvent( CEGUI::Tree::EventSelectionChanged                      ,
//                                  CEGUI::Event::Subscriber( &CGUIEditor::OnWindowSelected ,
//                                                            this                          ) );
//
//    m_propChangeButton = (CEGUI::PushButton*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Button"              , 
//                                                                   (CEGUI::utf8*) "CGUIEditor:PropertyChangeButton" );
//    m_window->addChildWindow( m_propChangeButton );
//    m_propChangeButton->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.04f, 0.0f ), CEGUI::UDim( 0.89f, 0.0f ) ) );
//    m_propChangeButton->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.07f, 0.0f ) ) );
//    m_propChangeButton->setText( (CEGUI::utf8*) "Edit" ); 
//    
//    m_propChangeButton->subscribeEvent( CEGUI::PushButton::EventClicked                                        ,
//                                        CEGUI::Event::Subscriber( &CGUIEditor::OnWindowPropertyEditButtonClick , 
//                                                                  this                                         ) );     
//
//    m_newWindowButton = (CEGUI::PushButton*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Button"         , 
//                                                                  (CEGUI::utf8*) "CGUIEditor:NewWindowButton" );
//    m_window->addChildWindow( m_newWindowButton );
//    m_newWindowButton->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.3f, 0.0f ), CEGUI::UDim( 0.89f, 0.0f ) ) );
//    m_newWindowButton->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.07f, 0.0f ) ) );
//    m_newWindowButton->setText( (CEGUI::utf8*) "New" ); 
//    
//    m_newWindowButton->subscribeEvent( CEGUI::PushButton::EventClicked                               ,
//                                       CEGUI::Event::Subscriber( &CGUIEditor::OnNewWindowButtonClick , 
//                                                                 this                                ) );
//
//    m_closeButton = (CEGUI::PushButton*) wmngr->createWindow( (CEGUI::utf8*) "TaharezLook/Button"     , 
//                                                              (CEGUI::utf8*) "CGUIEditor:CloseButton" );
//    m_window->addChildWindow( m_closeButton );
//    m_closeButton->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.6f, 0.0f ), CEGUI::UDim( 0.89f, 0.0f ) ) );
//    m_closeButton->setSize( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.07f, 0.0f ) ) );
//    m_closeButton->setText( (CEGUI::utf8*) "Close" );
//
//    m_closeButton->subscribeEvent( CEGUI::PushButton::EventClicked                           ,
//                                   CEGUI::Event::Subscriber( &CGUIEditor::OnCloseButtonClick , 
//                                                             this                            ) );
//        
//    m_keyValueListWindow = new CGUIKeyValueListWindow( "root"                            ,
//                                                       "CGUIEditor:WindowPropertyEditor" );
//    SubscribeTo( m_keyValueListWindow, CGUIKeyValueListWindow::OkPressedEvent );
//    
//    std::vector< CString > args;
//    RegisterCmd( "GUCE\\GUI\\CGUIEditor" ,
//                 "Show"                  ,
//                 args                    ,
//                 this                    );
//}
//
///*-------------------------------------------------------------------------*/
//    
//CGUIEditor::~CGUIEditor()
//{GUCE_TRACE;
//
//    m_window->destroy();
//    
//    delete m_keyValueListWindow;
//    m_keyValueListWindow = NULL;
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CGUIEditor::FillWindowTreeSegment( CEGUI::Window* window     ,
//                                   CEGUI::TreeItem* treeItem )
//{GUCE_TRACE;
//
//    CEGUI::TreeItem* nextTreeItem = new CEGUI::TreeItem( window->getName() );
//    treeItem->addItem( nextTreeItem );
//    
//    for ( UInt32 i=0; i<window->getChildCount(); ++i )
//    {
//        FillWindowTreeSegment( window->getChildAtIdx( i ) , 
//                               nextTreeItem               );
//    }
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CGUIEditor::FillWindowTree( CEGUI::Tree* windowTree )
//{GUCE_TRACE;
//
//#if 1
//
//    CEGUI::Window* w = CEGUI::WindowManager::getSingletonPtr()->getWindow( "root" );
//    if ( NULL != w )
//    {
//        CEGUI::TreeItem* treeItem = new CEGUI::TreeItem( w->getName() );
//        windowTree->addItem( treeItem );
//        
//        for ( UInt32 i=0; i<w->getChildCount(); ++i )
//        {
//            FillWindowTreeSegment( w->getChildAtIdx( i ) , 
//                                   treeItem              );
//        }
//    }
//
//#else
//    
//    CEGUI::WindowManager::WindowIterator n = CEGUI::WindowManager::getSingletonPtr()->getIterator();
//    while ( !n.isAtEnd() )
//    {   
//        CEGUI::Window* window = *n;
//        if ( NULL != window )
//        {
//            CEGUI::Window* parentWindow = window->getParent();
//            if ( window->getName().length() > 0 )
//            { 
//                CEGUI::TreeItem* treeItem = new CEGUI::TreeItem( window->getName() );
//                assert( NULL != treeItem );
//                
//                if ( NULL != parentWindow )
//                {
//                    CEGUI::TreeItem* parentEntry = m_windowList->findFirstItemWithText( parentWindow->getName() );
//                    if ( NULL != parentEntry )
//                    {
//                        // Add a child node to an existing parent node
//                        parentEntry->addItem( treeItem );
//                    }
//                    else
//                    {
//                        // the parent has not yet been added to the tree so we have to 
//                        // loop back to the root get the window stack first
//                        CEGUI::Window* w = parentWindow;
//                        std::vector< CEGUI::Window* > windowStack;
//                        while ( NULL != w )
//                        {
//                            windowStack.push_back( w );
//                            w = w->getParent();
//                        }
//                        
//                        // now that we have the window stack we can add the nodes as needed
//                        std::vector< CEGUI::Window* >::iterator i = windowStack.begin();
//                        while ( i != windowStack.end() )
//                        {
//                            CEGUI::TreeItem* ti = m_windowList->findFirstItemWithText( (*i)->getName() );
//                            if ( NULL == ti )
//                            {
//                                CEGUI::TreeItem* parentTreeItem = new CEGUI::TreeItem( (*i)->getName() );
//                                if ( i == windowStack.begin() )
//                                {
//                                    // Special case: the root node must be added to the window tree
//                                    // object itself which cannot be done trough a transparent API
//                                    windowTree->addItem( parentTreeItem );
//                                    parentEntry = parentTreeItem;
//                                }
//                                else
//                                {
//                                    parentEntry->addItem( parentTreeItem );
//                                }
//                            }
//                            else
//                            {
//                                parentEntry = ti;
//                            }
//                            ++i;
//                        }
//                    }
//                }
//                else
//                {
//                    // Add top-most node
//                    windowTree->addItem( treeItem );
//                }
//            }
//        }
//        ++n;
//    }
//        
//#endif    
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CGUIEditor::Show( void )
//{GUCE_TRACE;
//
//    m_window->show();
//    
//    // Make sure this window does not fall behind other 'always on top' windows
//    m_window->moveToFront();
//}
//
///*-------------------------------------------------------------------------*/
//
//CGUIEditor*
//CGUIEditor::Instance( void )
//{GUCE_TRACE;
//
//    if ( g_instance == NULL )
//    {
//        g_instance = new CGUIEditor();
//    }
//    return g_instance;
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CGUIEditor::Deinstance( void )
//{GUCE_TRACE;
//
//    delete g_instance;
//    g_instance = NULL;
//}
//
///*-------------------------------------------------------------------------*/
//
//bool
//CGUIEditor::OnSysConsoleCommand( const CString& path                ,
//                                 const CString& command             ,
//                                 const std::vector< CString >& args ,
//                                 std::vector< CString >& resultdata )
//{GUCE_TRACE;
//
//    if ( command == "Show" )
//    {
//        Show();
//        return true;
//    }
//    
//    return false;
//}
//
///*-------------------------------------------------------------------------*/
//
//bool
//CGUIEditor::OnWindowSelected( const CEGUI::EventArgs& e )
//{GUCE_TRACE;
//
//
//    return true;
//}
//
///*-------------------------------------------------------------------------*/
//
//bool
//CGUIEditor::OnWindowPropertyEditButtonClick( const CEGUI::EventArgs& e )
//{GUCE_TRACE;
///*                                 
//    CEGUI::ListboxItem* entry = m_widgetPropertyList->GetList()->getFirstSelectedItem();
//    if ( entry != NULL )
//    {
//        m_selectedRow = m_widgetPropertyList->GetList()->getItemRowIndex( entry );
//        m_keyValueWindow->SetKey( m_widgetPropertyList->GetText( 0, m_selectedRow ) );
//        m_keyValueWindow->SetValue( m_widgetPropertyList->GetText( 1, m_selectedRow ) );
//        m_keyValueWindow->ShowModal();
//    }
//    return true;
//    
//    */
//    
//    m_keyValueListWindow->Clear();
//    
//    CEGUI::WindowManager* wmngr = CEGUI::WindowManager::getSingletonPtr();
//    CEGUI::TreeItem* treeEntry = m_windowList->getFirstSelectedItem();
//    if ( treeEntry != NULL )
//    {
//        try
//        {
//            m_selectedWindow = wmngr->getWindow( treeEntry->getText() ); 
//            
//            CEGUI::PropertySet::Iterator i = m_selectedWindow->getPropertyIterator();
//            
//            UInt32 n=0;
//            while ( !i.isAtEnd() )
//            {   
//                CEGUI::Property* property = *i; 
//                m_keyValueListWindow->AppendText( 0, property->getName().c_str() ); 
//                m_keyValueListWindow->SetText( 1, n, m_selectedWindow->getProperty( property->getName() ).c_str() );
//                ++i; ++n;
//            }
//            
//            m_keyValueListWindow->ShowModal();
//        }
//        catch ( CEGUI::UnknownObjectException& e )
//        {
//            GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CGUIEditor::OnWindowSelected(): CEGUI::UnknownObjectException " ) + e.getMessage().c_str() );
//        }    
//    }
//    return true;    
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CGUIEditor::Hide( void )
//{GUCE_TRACE;
//
//    m_window->setModalState( false );
//    m_window->hide();
//}
//
///*-------------------------------------------------------------------------*/
//
//bool
//CGUIEditor::OnCloseButtonClick( const CEGUI::EventArgs& e )
//{GUCE_TRACE;
//
//    Hide();
//    return true;
//}
//
///*-------------------------------------------------------------------------*/
//
//bool
//CGUIEditor::OnNewWindowButtonClick( const CEGUI::EventArgs& e )
//{GUCE_TRACE;
//                   // test code
//    //CGUIFileSystemDialog* test = new CGUIFileOpenDialog( m_window->getName().c_str() );
//    //CVFSInfoProvider* fsip = new CVFSInfoProvider();
//    //test->SetFileSystemInfoProvider( fsip );
//    //test->ShowModal();
//    return true;
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CGUIEditor::OnNotify( GUCEF::CORE::CNotifier* notifier                 ,
//                      const GUCEF::CORE::CEvent& eventid               ,
//                      GUCEF::CORE::CICloneable* eventdata /* = NULL */ )
//{GUCE_TRACE;
//
//    if ( eventid == CGUIKeyValueListWindow::OkPressedEvent )
//    {
//        // See if we have a selected window 
//        // this should always succeed
//        if ( NULL != m_selectedWindow )
//        {
//            // First we grab the new values
//            GUCEF::CORE::CValueList values;
//            m_keyValueListWindow->GetValueList( values );
//            
//            // now we try to set them
//            for ( UInt32 i=0; i<values.GetCount(); ++i )
//            {
//                try
//                {
//                    CString key( values.GetKey( i ) );
//                    CString value( values.GetValue( i ) );
//                    if ( key.Length() > 0   &&
//                         value.Length() > 0  )
//                    { 
//                        m_selectedWindow->setProperty( key.C_String()   , 
//                                                       value.C_String() );
//                    }
//                }
//                catch ( CEGUI::UnknownObjectException& e )
//                {
//                    GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, CString( "CGUIEditor::OnNotify( OkPressedEvent ): CEGUI::UnknownObjectException " ) + e.getMessage().c_str() );
//                }
//            }
//        }
//    }
//}
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