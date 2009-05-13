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

#ifndef GUCE_GUI_CMESHVIEWERFORM_H
#define GUCE_GUI_CMESHVIEWERFORM_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_GUI_CFILESYSTEMDIALOG_H
#include "gucefGUI_CFileSystemDialog.h"
#define GUCEF_GUI_CFILESYSTEMDIALOG_H
#endif /* GUCEF_GUI_CFILESYSTEMDIALOG_H ? */

#ifndef GUCEF_GUI_CSPINNER_H
#include "gucefGUI_CSpinner.h"
#define GUCEF_GUI_CSPINNER_H
#endif /* GUCEF_GUI_CSPINNER_H ? */

#ifndef GUCEF_GUI_CLISTBOX_H
#include "gucefGUI_CListbox.h"
#define GUCEF_GUI_CLISTBOX_H
#endif /* GUCEF_GUI_CLISTBOX_H ? */

#ifndef GUCEF_GUI_CEDITBOX_H
#include "gucefGUI_CEditbox.h"
#define GUCEF_GUI_CEDITBOX_H
#endif /* GUCEF_GUI_CEDITBOX_H ? */

#ifndef GUCEF_GUI_CCHECKBOX_H
#include "gucefGUI_CCheckbox.h"
#define GUCEF_GUI_CCHECKBOX_H
#endif /* GUCEF_GUI_CCHECKBOX_H ? */

#ifndef GUCE_GUI_COGREGUIRENDERCONTEXT_H
#include "guceGUI_COgreGUIRenderContext.h"
#define GUCE_GUI_COGREGUIRENDERCONTEXT_H
#endif /* GUCE_GUI_COGREGUIRENDERCONTEXT_H ? */

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

class GUCE_GUI_EXPORT_CPP CMeshViewerForm : public GUCEF::GUI::CFormEx
{
    public:    
    
    CMeshViewerForm( void );
    
    virtual ~CMeshViewerForm();
    
    GUCEF::GUI::CButton* GetOpenMeshFileButton( void );
    
    GUCEF::GUI::CButton* GetOpenMaterialDirButton( void );
    
    GUCEF::GUI::CEditbox* GetMaterialDirEditbox( void );
    
    GUCEF::GUI::CListbox* GetMaterialListbox( void );
    
    GUCEF::GUI::CCheckbox* GetMaterialDirAsMeshDirCheckbox( void );
    
    GUCEF::GUI::CButton* GetCloseButton( void );
    
    GUCEF::GUI::CButton* GetShowMeshButton( void );
    
    GUCEF::GUI::CButton* GetControlCameraButton( void );
    
    GUCEF::GUI::CSpinner* GetPitchSpinner( void );
    
    GUCEF::GUI::CSpinner* GetYawSpinner( void );
    
    GUCEF::GUI::CSpinner* GetRollSpinner( void );
    
    GUCEF::GUI::CSpinner* GetScaleSpinner( void );
    
    GUCEF::GUI::CListbox* GetMeshListbox( void );
    
    COgreGUIRenderContext* GetRenderContext( void );
    
    virtual const CString& GetClassTypeName( void ) const;
    
    protected:
    
    virtual void OnPreLayoutLoad( void );
    
    virtual void OnPostLayoutLoad( void );    
    
    private:
    
    CMeshViewerForm( const CMeshViewerForm& src );
    CMeshViewerForm& operator=( const CMeshViewerForm& src );
    
    private:

    GUCEF::GUI::CButton* m_openMeshFileButton;
    GUCEF::GUI::CButton* m_openMaterialDirButton;
    GUCEF::GUI::CButton* m_controlCameraButton;
    GUCEF::GUI::CEditbox* m_materialDirEditbox;
    GUCEF::GUI::CCheckbox* m_materialDirAsMeshDirCheckbox;
    GUCEF::GUI::CListbox* m_materialListbox;
    GUCEF::GUI::CButton* m_closeButton;
    GUCEF::GUI::CButton* m_showButton;
    GUCEF::GUI::CSpinner* m_pitchSpinner;
    GUCEF::GUI::CSpinner* m_yawSpinner;
    GUCEF::GUI::CSpinner* m_rollSpinner;
    GUCEF::GUI::CSpinner* m_scaleSpinner;
    GUCEF::GUI::CListbox* m_meshListbox;
    COgreGUIRenderContext* m_renderContext;    
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_CMESHVIEWERFORM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-04-2007 :
        - Initial implementation

---------------------------------------------------------------------------*/
