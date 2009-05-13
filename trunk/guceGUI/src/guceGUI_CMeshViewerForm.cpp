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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#include "guceGUI_CMeshViewerForm.h"

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

CMeshViewerForm::CMeshViewerForm( void )
    : CFormEx()                              ,
      m_openMeshFileButton( NULL )           ,
      m_openMaterialDirButton( NULL )        ,
      m_controlCameraButton( NULL )          ,
      m_materialDirEditbox( NULL )           ,
      m_materialDirAsMeshDirCheckbox( NULL ) ,
      m_materialListbox( NULL )              ,
      m_closeButton( NULL )                  ,
      m_showButton( NULL )                   ,
      m_pitchSpinner( NULL )                 ,
      m_yawSpinner( NULL )                   ,
      m_rollSpinner( NULL )                  ,
      m_scaleSpinner( NULL )                 ,
      m_meshListbox( NULL )                  ,
      m_renderContext( NULL )     
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CMeshViewerForm::~CMeshViewerForm()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

void
CMeshViewerForm::OnPreLayoutLoad( void )
{GUCE_TRACE;

    CFormEx::OnPreLayoutLoad();

    m_openMeshFileButton = NULL;
    m_openMaterialDirButton = NULL;
    m_controlCameraButton = NULL;
    m_materialDirEditbox = NULL;
    m_materialDirAsMeshDirCheckbox = NULL;
    m_materialListbox = NULL;
    m_closeButton = NULL;
    m_showButton = NULL;
    m_pitchSpinner = NULL;
    m_yawSpinner = NULL;
    m_rollSpinner = NULL;
    m_scaleSpinner = NULL;
    m_meshListbox = NULL;
    m_renderContext = NULL;
}

/*-------------------------------------------------------------------------*/

void
CMeshViewerForm::OnPostLayoutLoad( void )
{GUCE_TRACE;

    CFormEx::OnPostLayoutLoad();
    
    m_openMeshFileButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "OpenMeshFileButton" ) );
    m_openMaterialDirButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "OpenMaterialDirButton" ) );
    m_controlCameraButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "ControlCameraButton" ) );
    m_materialDirEditbox = static_cast< GUCEF::GUI::CEditbox* >( GetWidget( "MaterialDirEditbox" ) );
    m_materialDirAsMeshDirCheckbox = static_cast< GUCEF::GUI::CCheckbox* >( GetWidget( "MaterialDirAsMeshDirCheckbox" ) );
    m_materialListbox = static_cast< GUCEF::GUI::CListbox* >( GetWidget( "MaterialListbox" ) );
    m_closeButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "CloseButton" ) );
    m_showButton = static_cast< GUCEF::GUI::CButton* >( GetWidget( "ShowMeshButton" ) );
    m_pitchSpinner = static_cast< GUCEF::GUI::CSpinner* >( GetWidget( "PitchSpinner" ) );
    m_yawSpinner = static_cast< GUCEF::GUI::CSpinner* >( GetWidget( "YawSpinner" ) );
    m_rollSpinner = static_cast< GUCEF::GUI::CSpinner* >( GetWidget( "RollSpinner" ) );
    m_scaleSpinner = static_cast< GUCEF::GUI::CSpinner* >( GetWidget( "ScaleSpinner" ) );
    m_meshListbox = static_cast< GUCEF::GUI::CListbox* >( GetWidget( "MeshListbox" ) );
    m_renderContext = static_cast< COgreGUIRenderContext* >( GetWidget( "RenderContext" ) );
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CListbox*
CMeshViewerForm::GetMaterialListbox( void )
{GUCE_TRACE;
    
    return m_materialListbox;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CCheckbox*
CMeshViewerForm::GetMaterialDirAsMeshDirCheckbox( void )
{GUCE_TRACE;

    return m_materialDirAsMeshDirCheckbox;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CEditbox*
CMeshViewerForm::GetMaterialDirEditbox( void )
{GUCE_TRACE;

    return m_materialDirEditbox;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CButton*
CMeshViewerForm::GetOpenMeshFileButton( void )
{GUCE_TRACE;

    return m_openMeshFileButton;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CButton*
CMeshViewerForm::GetOpenMaterialDirButton( void )
{GUCE_TRACE;

    return m_openMaterialDirButton;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CButton*
CMeshViewerForm::GetControlCameraButton( void )
{GUCE_TRACE;

    return m_controlCameraButton;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CButton*
CMeshViewerForm::GetCloseButton( void )
{GUCE_TRACE;

    return m_closeButton;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CButton*
CMeshViewerForm::GetShowMeshButton( void )
{GUCE_TRACE;

    return m_showButton;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CSpinner*
CMeshViewerForm::GetPitchSpinner( void )
{GUCE_TRACE;

    return m_pitchSpinner;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CSpinner*
CMeshViewerForm::GetYawSpinner( void )
{GUCE_TRACE;

    return m_yawSpinner;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CSpinner*
CMeshViewerForm::GetRollSpinner( void )
{GUCE_TRACE;

    return m_rollSpinner;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CSpinner*
CMeshViewerForm::GetScaleSpinner( void )
{GUCE_TRACE;

    return m_scaleSpinner;
}

/*-------------------------------------------------------------------------*/

GUCEF::GUI::CListbox*
CMeshViewerForm::GetMeshListbox( void )
{GUCE_TRACE;

    return m_meshListbox;
}

/*-------------------------------------------------------------------------*/

COgreGUIRenderContext*
CMeshViewerForm::GetRenderContext( void )
{GUCE_TRACE;

    return m_renderContext;
}

/*-------------------------------------------------------------------------*/

const CString&
CMeshViewerForm::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString classTypeName = "GUCE::GUI::CMeshViewerForm";
    return classTypeName;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
