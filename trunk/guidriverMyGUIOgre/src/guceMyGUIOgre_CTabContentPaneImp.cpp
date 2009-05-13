///*
// *  guceMyGUIOgre: glue module for the MyGUI+Ogre GUI backend
// *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
// *
// *  This library is free software; you can redistribute it and/or
// *  modify it under the terms of the GNU Lesser General Public
// *  License as published by the Free Software Foundation; either
// *  version 2.1 of the License, or (at your option) any later version.
// *
// *  This library is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
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
//#include "guceMyGUIOgre_CTabContentPaneImp.h"
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      NAMESPACE                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//namespace GUCE {
//namespace MYGUIOGRE {
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      UTILITIES                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//CTabContentPaneImp::CTabContentPaneImp( void )
//    : CWidgetImp< GUCEF::GUI::CTabContentPane >() ,
//      m_tabContentPane( NULL )
//{GUCE_TRACE;
//
//}
//    
///*-------------------------------------------------------------------------*/
//    
//CTabContentPaneImp::~CTabContentPaneImp()
//{GUCE_TRACE;
//
//}
//
///*-------------------------------------------------------------------------*/
//    
//GUCEF::GUI::CTabControl*
//CTabContentPaneImp::GetParentTabControl( void )
//{GUCE_TRACE;
//
//    return NULL;
//}
//
///*-------------------------------------------------------------------------*/
//    
//const CString&
//CTabContentPaneImp::GetClassTypeName( void ) const
//{GUCE_TRACE;
//
//    static const CString classTypeName = "GUCE::CEGUIOGRE::CTabContentPaneImp";
//    return classTypeName;
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CTabContentPaneImp::Hook( CEGUI::Window* tabContentPane )
//{GUCE_TRACE;
//
//    m_tabContentPane = tabContentPane;
//    CWidgetImp< GUCEF::GUI::CTabContentPane >::Hook( tabContentPane );
//}
//    
///*-------------------------------------------------------------------------//
////                                                                         //
////      NAMESPACE                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//}; /* namespace MYGUIOGRE */
//}; /* namespace GUCE */
//
///*-------------------------------------------------------------------------*/
