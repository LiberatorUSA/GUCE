/*
 *  guceGUI: GUCE module providing GUI functionality
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

#ifndef GUCE_GUI_CSETTINGSMENUFORM_H
#define GUCE_GUI_CSETTINGSMENUFORM_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_GUI_CWINDOW_H
#include "gucefGUI_CWindow.h"
#define GUCEF_GUI_CWINDOW_H
#endif /* GUCEF_GUI_CWINDOW_H ? */

#ifndef GUCEF_GUI_CTABCONTROL_H
#include "gucefGUI_CTabControl.h"
#define GUCEF_GUI_CTABCONTROL_H
#endif /* GUCEF_GUI_CTABCONTROL_H ? */

#ifndef GUCE_GUI_CVIDEOSETTINGSFORM_H
#include "guceGUI_CVideoSettingsForm.h"
#define GUCE_GUI_CVIDEOSETTINGSFORM_H
#endif /* GUCE_GUI_CVIDEOSETTINGSFORM_H ? */

#ifndef GUCEF_GUI_CFORMEX_H
#include "gucefGUI_CFormEx.h"
#define GUCEF_GUI_CFORMEX_H
#endif /* GUCEF_GUI_CFORMEX_H ? */

#ifndef GUCE_GUI_MACROS_H
#include "guceGUI_macros.h"
#define GUCE_GUI_MACROS_H
#endif /* GUCE_GUI_MACROS_H ? */

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

class GUCE_GUI_EXPORT_CPP CSettingsMenuForm : public GUCEF::GUI::CFormEx
{
    public:
    
    CSettingsMenuForm( void );
    
    virtual ~CSettingsMenuForm();
    
    GUCEF::GUI::CWindow* GetSettingsWindow( void );
    
    GUCEF::GUI::CButton* GetMenuButton( void );
    
    GUCEF::GUI::CTabControl* GetSettingsTabControl( void );
    
    GUCEF::GUI::CTabContentPane* GetVideoSettingsTabPane( void );
    
    GUCEF::GUI::CTabContentPane* GetAudioSettingsTabPane( void );
    
    GUCEF::GUI::CTabContentPane* GetInputSettingsTabPane( void );
    
    bool SetActiveTab( const UInt32 tabIndex );

    CVideoSettingsForm& GetVideoSettingsForm( void );
    
    virtual const CString& GetClassTypeName( void ) const;

    protected:
    
    virtual void OnPreLayoutLoad( void );
    
    virtual void OnPostLayoutLoad( void );

    /**
     *  @param notifier the notifier that sent the notification
     *  @param eventid the unique event id for an event
     *  @param eventdata optional notifier defined userdata
     */
    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
                           const GUCEF::CORE::CEvent& eventid         ,
                           GUCEF::CORE::CICloneable* eventdata = NULL );
    
    private:
    
    CSettingsMenuForm( const CSettingsMenuForm& src );
    CSettingsMenuForm& operator=( const CSettingsMenuForm& src );
    
    private:
    
    GUCEF::GUI::CWindow* m_settingsWindow;
    GUCEF::GUI::CButton* m_menuButton;
    GUCEF::GUI::CTabControl* m_settingsTabControl;
    GUCEF::GUI::CTabContentPane* m_videoSettingsTabContentPane;
    GUCEF::GUI::CTabContentPane* m_audioSettingsTabContentPane;
    GUCEF::GUI::CTabContentPane* m_inputSettingsTabContentPane;
    CVideoSettingsForm m_videoSettingsForm;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_GUI_CSETTINGSMENUFORM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
