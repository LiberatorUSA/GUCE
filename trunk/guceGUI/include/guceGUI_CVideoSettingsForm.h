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

#ifndef GUCE_GUI_CVIDEOSETTINGSFORM_H
#define GUCE_GUI_CVIDEOSETTINGSFORM_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_GUI_CBUTTON_H
#include "gucefGUI_CButton.h"
#define GUCEF_GUI_CBUTTON_H
#endif /* GUCEF_GUI_CBUTTON_H ? */

#ifndef GUCEF_GUI_CLABEL_H
#include "gucefGUI_CLabel.h"
#define GUCEF_GUI_CLABEL_H
#endif /* GUCEF_GUI_CLABEL_H ? */

#ifndef GUCEF_GUI_CCHECKBOX_H
#include "gucefGUI_CCheckbox.h"
#define GUCEF_GUI_CCHECKBOX_H
#endif /* GUCEF_GUI_CCHECKBOX_H ? */

#ifndef GUCEF_GUI_CCOMBOBOX_H
#include "gucefGUI_CCombobox.h"
#define GUCEF_GUI_CCOMBOBOX_H
#endif /* GUCEF_GUI_CCOMBOBOX_H ? */

#ifndef GUCEF_GUI_CFORMEX_H
#include "gucefGUI_CFormEx.h"
#define GUCEF_GUI_CFORMEX_H
#endif /* GUCEF_GUI_CFORMEX_H ? */

#ifndef GUCE_CORE_CVIDEOSETTINGS_H
#include "guceCORE_CVideoSettings.h"
#define GUCE_CORE_CVIDEOSETTINGS_H
#endif /* GUCE_CORE_CVIDEOSETTINGS_H ? */

#ifndef GUCE_CORE_CVIDEOOPTIONS_H
#include "guceCORE_CVideoOptions.h"
#define GUCE_CORE_CVIDEOOPTIONS_H
#endif /* GUCE_CORE_CVIDEOOPTIONS_H ? */

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

class GUCE_GUI_EXPORT_CPP CVideoSettingsForm : public GUCEF::GUI::CFormEx
{
    public:
    
    typedef CORE::CVideoOptions::TDisplayMode TDisplayMode;
    
    CVideoSettingsForm( void );
    
    virtual ~CVideoSettingsForm();

    GUCEF::GUI::CLabel* GetResolutionLabel( void );
    
    GUCEF::GUI::CCombobox* GetResolutionCombobox( void );
    
    GUCEF::GUI::CLabel* GetAntiAliasingLabel( void );
    
    GUCEF::GUI::CCombobox* GetAntiAliasingCombobox( void );
    
    GUCEF::GUI::CCheckbox* GetFullscreenCheckbox( void );
    
    GUCEF::GUI::CCheckbox* GetVSyncCheckbox( void );
    
    GUCEF::GUI::CButton* GetApplyButton( void );

    virtual const CString& GetClassTypeName( void ) const;
    
    bool SetVideoOptions( const CORE::CVideoOptions& options );
    
    bool GetVideoOptions( CORE::CVideoOptions& options ) const;
    
    bool SetVideoSettings( const CORE::CVideoSettings& settings );
    
    bool GetVideoSettings( CORE::CVideoSettings& settings ) const;

    protected:
    
    virtual void OnPreLayoutLoad( void );
    
    virtual void OnPostLayoutLoad( void );
    
    private:
    
    CVideoSettingsForm( const CVideoSettingsForm& src );
    CVideoSettingsForm& operator=( const CVideoSettingsForm& src );
    
    void ParseDisplayModeString( const CString& rez        ,
                                 TDisplayMode& displayMode ) const;
    
    CString ParseDisplayMode( const TDisplayMode& displayMode ) const;
    
    private:
    
    GUCEF::GUI::CLabel* m_resolutionLabel;
    GUCEF::GUI::CCombobox* m_resolutionCombobox;
    GUCEF::GUI::CLabel* m_antiAliasingLabel;
    GUCEF::GUI::CCombobox* m_antiAliasingCombobox;
    GUCEF::GUI::CCheckbox* m_fullscreenCheckbox;
    GUCEF::GUI::CCheckbox* m_vSyncCheckbox;
    GUCEF::GUI::CButton* m_applyButton;
    CORE::CVideoOptions m_videoOptions;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_GUI_CVIDEOSETTINGSFORM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
