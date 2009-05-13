/*
 *  gucefGUI: GUCE module providing GUI functionality
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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

#ifndef CAUDIOSETTINGSWINDOW_H
#define CAUDIOSETTINGSWINDOW_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEGUI_MACROS_H
#include "guceGUI_macros.h"              /* often used guceGUI macros */
#define GUCEGUI_MACROS_H
#endif /* GUCEGUI_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Forward declarations of classes used here 
 */
namespace CEGUI{ class FrameWindow; class EventArgs; }

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

class GUCEGUI_EXPORT_CPP CAudioSettingsWindow
{
        private:
        friend class CSettingsWindow;
        
        static CAudioSettingsWindow* Instance( void );
        
        static void Deinstance( void );
        
        void Show( void );
        
        void Hide( void );
        
        private:
        CAudioSettingsWindow( void );       
        ~CAudioSettingsWindow();        
        
        CAudioSettingsWindow( const CAudioSettingsWindow& src );
        CAudioSettingsWindow& operator=( const CAudioSettingsWindow& src );
        
        //bool OnMainMenuButtonClick( const CEGUI::EventArgs& e );
        //bool OnServerListButtonClick( const CEGUI::EventArgs& e );
        //bool OnSettingsButtonClick( const CEGUI::EventArgs& e );
        //bool OnExitButtonClick( const CEGUI::EventArgs& e );        
        
        CEGUI::FrameWindow* _window;
        
        static CAudioSettingsWindow* _instance;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* CAUDIOSETTINGSWINDOW_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 21-05-2005 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
