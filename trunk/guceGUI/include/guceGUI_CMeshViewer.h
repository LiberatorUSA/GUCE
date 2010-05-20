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

#ifndef GUCE_GUI_CMESHVIEWER_H
#define GUCE_GUI_CMESHVIEWER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _TextureManager_H__
#include <OgreTextureManager.h>
#define _TextureManager_H__
#endif /* _TextureManager_H__ ? */

#ifndef GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H
#include "gucefCORE_CTEventHandlerFunctor.h"
#define GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H
#endif /* GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H ? */

#ifndef GUCEF_GUI_CFILESYSTEMDIALOG_H
#include "gucefGUI_CFileSystemDialog.h"
#define GUCEF_GUI_CFILESYSTEMDIALOG_H
#endif /* GUCEF_GUI_CFILESYSTEMDIALOG_H ? */

#ifndef GUCE_GUI_CMESHVIEWERFORM_H
#include "guceGUI_CMeshViewerForm.h"
#define GUCE_GUI_CMESHVIEWERFORM_H
#endif /* GUCE_GUI_CMESHVIEWERFORM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class SceneManager; 
                 class RenderTexture; 
                 class Entity;
                 class SceneNode;     }

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

class GUCE_GUI_EXPORT_CPP CMeshViewer : public GUCEF::CORE::CObservingNotifier
{
    public:    
    
    CMeshViewer( void );
    
    virtual ~CMeshViewer();
    
    void Show( void );
    
    void ShowModal( void );
    
    void Hide( void );
    
    CMeshViewerForm& GetMeshViewerForm( void );
    
    GUCEF::GUI::CFileSystemDialog* GetFileOpenDialog( void );
    
    virtual const CString& GetClassTypeName( void ) const;
    
    private:
    
    typedef GUCEF::CORE::CTEventHandlerFunctor< CMeshViewer > TEventCallback;
    
    CMeshViewer( const CMeshViewer& src );
    CMeshViewer& operator=( const CMeshViewer& src );
    
    void OnMeshPitchChange( GUCEF::CORE::CNotifier* notifier           ,
                            const GUCEF::CORE::CEvent& eventid         ,
                            GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnMeshYawChange( GUCEF::CORE::CNotifier* notifier           ,
                            const GUCEF::CORE::CEvent& eventid         ,
                            GUCEF::CORE::CICloneable* eventdata = NULL );
                            
    void OnMeshRollChange( GUCEF::CORE::CNotifier* notifier           ,
                            const GUCEF::CORE::CEvent& eventid         ,
                            GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnMeshScaleChange( GUCEF::CORE::CNotifier* notifier           ,
                            const GUCEF::CORE::CEvent& eventid         ,
                            GUCEF::CORE::CICloneable* eventdata = NULL );
                                                        
    void OnGUIBackendChange( GUCEF::CORE::CNotifier* notifier           ,
                             const GUCEF::CORE::CEvent& eventid         ,
                             GUCEF::CORE::CICloneable* eventdata = NULL );
    
    void OnMeshViewerFormLayoutLoaded( GUCEF::CORE::CNotifier* notifier           ,
                                       const GUCEF::CORE::CEvent& eventid         ,
                                       GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnFileOpenDialogLayoutLoaded( GUCEF::CORE::CNotifier* notifier           ,
                                       const GUCEF::CORE::CEvent& eventid         ,
                                       GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnFileOpenDialogSelection( GUCEF::CORE::CNotifier* notifier           ,
                                    const GUCEF::CORE::CEvent& eventid         ,
                                    GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnFileOpenDialogCloseButtonClicked( GUCEF::CORE::CNotifier* notifier           ,
                                             const GUCEF::CORE::CEvent& eventid         ,
                                             GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnOpenMeshFileButtonPressed( GUCEF::CORE::CNotifier* notifier           ,
                                      const GUCEF::CORE::CEvent& eventid         ,
                                      GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnOpenMaterialDirButtonPressed( GUCEF::CORE::CNotifier* notifier           ,
                                         const GUCEF::CORE::CEvent& eventid         ,
                                         GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnMaterialDirAsMeshDirCheckboxChecked( GUCEF::CORE::CNotifier* notifier           ,
                                                const GUCEF::CORE::CEvent& eventid         ,
                                                GUCEF::CORE::CICloneable* eventdata = NULL );
    
    void OnCloseButtonPressed( GUCEF::CORE::CNotifier* notifier           ,
                               const GUCEF::CORE::CEvent& eventid         ,
                               GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnShowMeshButtonPressed( GUCEF::CORE::CNotifier* notifier           ,
                                  const GUCEF::CORE::CEvent& eventid         ,
                                  GUCEF::CORE::CICloneable* eventdata = NULL );

    void OnControlCameraButtonPressed( GUCEF::CORE::CNotifier* notifier           ,
                                       const GUCEF::CORE::CEvent& eventid         ,
                                       GUCEF::CORE::CICloneable* eventdata = NULL );
                                  
    void RefreshMeshList( void );
    
    void RefreshMaterialListForSelectedMesh( void );
    
    void RefreshScene( void );
    
    void SetupOgreScene( void );
                                      
    private:
        
    enum EOpenState
    {
        OPEN_NOTHING = 0  ,
        OPEN_MESH_FILE    ,
        OPEN_MATERIAL_DIR
    };
        
    CMeshViewerForm m_meshViewerForm;
    GUCEF::GUI::CFileSystemDialog* m_fileOpenDialog;
    Ogre::SceneManager* m_sceneManager;
    Ogre::Camera* m_camera;
    Ogre::TexturePtr m_renderTexture;
    Ogre::Entity* m_meshEntity;
    Ogre::SceneNode* m_meshEntityNode;
    CString m_selectedMesh;
    CString m_materialDir;
    EOpenState m_openState;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_CMESHVIEWER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-04-2007 :
        - Initial implementation

---------------------------------------------------------------------------*/
