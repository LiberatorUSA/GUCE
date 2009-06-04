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

#ifndef __ROOT__
#include "OgreRoot.h"           /* most basic Ogre class */ 
#define __ROOT__
#endif /* __ROOT__ ?  */

#ifndef __RenderSystem_H_
#include <OgreRenderSystem.h>   /* Ogre render system: abstract base */
#define __RenderSystem_H_
#endif /* __RenderSystem_H_ ? */

#ifndef __HardwarePixelBuffer__
#include <OgreHardwarePixelBuffer.h>
#define __HardwarePixelBuffer__
#endif /* __HardwarePixelBuffer__ ? */

#ifndef __SceneManager_H__
#include <OgreSceneManager.h>   /* Ogre scene manager: abstract base */
#define __SceneManager_H__
#endif /* __SceneManager_H__ ? */

#ifndef __Entity_H__
#include <OgreEntity.h>
#define __Entity_H__
#endif /* __Entity_H__ ? */

#ifndef __Camera_H__
#include <OgreCamera.h>         /* base class for Ogre scene cameras */
#define __Camera_H__
#endif /* __Camera_H__ ? */

#ifndef __RenderWindow_H__
#include <OgreRenderWindow.h>   /* Ogre rendering window */
#define __RenderWindow_H__
#endif /* __RenderWindow_H__ ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCE_CORE_CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define GUCE_CORE_CGUCEAPPLICATION_H
#endif /* GUCE_CORE_CGUCEAPPLICATION_H ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_GUI_CGUIMANAGER_H
#include "gucefGUI_CGUIManager.h"
#define GUCEF_GUI_CGUIMANAGER_H
#endif /* GUCEF_GUI_CGUIMANAGER_H ? */

#ifndef GUCE_GUI_CGUIMANAGER_H
#include "CGUIManager.h"
#define GUCE_GUI_CGUIMANAGER_H
#endif /* GUCE_GUI_CGUIMANAGER_H ? */

#include "guceGUI_CMeshViewer.h"

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

CMeshViewer::CMeshViewer( void )
    : CObservingNotifier()        ,
      m_meshViewerForm()          ,
      m_fileOpenDialog( NULL )    ,
      m_sceneManager( NULL )      ,
      m_camera( NULL )            ,
      m_renderTexture()           ,
      m_meshEntity( NULL )        ,
      m_meshEntityNode( NULL )    ,
      m_selectedMesh()            ,
      m_materialDir()             ,
      m_openState( OPEN_NOTHING )
{GUCE_TRACE;

    SubscribeTo( CGUIManager::Instance()                                   ,
                 CGUIManager::GUIInitializedEvent                          ,
                 &TEventCallback( this, &CMeshViewer::OnGUIBackendChange ) );
    SubscribeTo( GUCEF::GUI::CGUIManager::Instance()                       ,
                 GUCEF::GUI::CGUIManager::FormFactoryRegisteredEvent       ,
                 &TEventCallback( this, &CMeshViewer::OnGUIBackendChange ) );
    SubscribeTo( &m_meshViewerForm                                                   ,
                 GUCEF::GUI::CForm::LayoutLoadedEvent                                ,
                 &TEventCallback( this, &CMeshViewer::OnMeshViewerFormLayoutLoaded ) );
}

/*-------------------------------------------------------------------------*/
    
CMeshViewer::~CMeshViewer()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CMeshViewerForm&
CMeshViewer::GetMeshViewerForm( void )
{GUCE_TRACE;

    return m_meshViewerForm;
}

/*-------------------------------------------------------------------------*/
    
GUCEF::GUI::CFileSystemDialog&
CMeshViewer::GetFileOpenDialog( void )
{GUCE_TRACE;

    return *m_fileOpenDialog;
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::SetupOgreScene( void )    
{GUCE_TRACE;

    // Make sure Ogre is initialized
    Ogre::Root* root = Ogre::Root::getSingletonPtr();
    if ( NULL != root )
    {
        // Setup the scene if needed
        if ( NULL == m_sceneManager )
        {
            try
            {
                m_sceneManager = root->createSceneManager( Ogre::ST_GENERIC );
                m_sceneManager->setAmbientLight( Ogre::ColourValue( 0.5, 0.5, 0.5 ) );
                Ogre::SceneNode* wNode = m_sceneManager->createSceneNode( "WorldNode" );
                m_sceneManager->getRootSceneNode()->addChild( wNode );                                      

                m_camera = m_sceneManager->createCamera( "Main" );
                m_camera->setPosition( 0, 10, 500 );
                m_camera->lookAt( 0, 0, 0 );
                m_camera->setNearClipDistance( 5 );

                m_renderTexture = root->getTextureManager()->createManual( "MeshViewer" + GUCEF::CORE::PointerToString( this ) , 
                                                                           "GUI"                                               ,
                                                                           Ogre::TEX_TYPE_2D                                   ,
                                                                           512                                                 ,
                                                                           512                                                 ,
                                                                           0                                                   ,
                                                                           Ogre::PF_R8G8B8                                     ,
                                                                           Ogre::TU_RENDERTARGET                               );
                                                                           
                Ogre::RenderTexture* renderTarget = m_renderTexture->getBuffer()->getRenderTarget();

                Ogre::Viewport* viewPort = renderTarget->addViewport( m_camera );
                viewPort->setOverlaysEnabled( false );
                viewPort->setClearEveryFrame( true );
                viewPort->setBackgroundColour( Ogre::ColourValue::Blue );
            }
            catch ( Ogre::Exception& e )
            {
                GUCEF_ERROR_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CMeshViewer: Exception while setting up the Ogre scene: " + e.getFullDescription() );
            }
        }
        
        // Link the render texture if needed
        COgreGUIRenderContext* renderContext = m_meshViewerForm.GetRenderContext();
        if ( NULL != renderContext )
        {
            if ( renderContext->GetRenderTexture() != m_renderTexture )
            {
                renderContext->SetRenderTexture( m_renderTexture );
            }
        }        
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnGUIBackendChange( GUCEF::CORE::CNotifier* notifier    ,
                                 const GUCEF::CORE::CEvent& eventid  ,
                                 GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    if ( NULL == m_fileOpenDialog )
    {
        //// Check if we want to act based on this event
        //if ( GUCEF::GUI::CGUIManager::FormFactoryRegisteredEvent == eventid )
        //{
        //    const CString& formType = static_cast< GUCEF::GUI::CGUIManager::TKeyContainer* >( eventdata )->GetData();
        //    if ( formType != "FileOpenDialog" )
        //    {
        //        return;
        //    }
        //}
        //
        //// Try to create the form        
        //GUCEF::GUI::CFormFactory& formFactory = GUCEF::GUI::CGUIManager::Instance()->GetFormFactory();
        //m_fileOpenDialog = static_cast< GUCEF::GUI::CFileSystemDialog* >( formFactory.Create( "FileOpenDialog" ) );
        //
        //if ( NULL != m_fileOpenDialog )
        //{
        //    SubscribeTo( m_fileOpenDialog                                                    ,
        //                 GUCEF::GUI::CForm::LayoutLoadedEvent                                ,
        //                 &TEventCallback( this, &CMeshViewer::OnFileOpenDialogLayoutLoaded ) );
        //                 
        //    m_fileOpenDialog->SetAllowedSelection( false, true );        
        //    m_fileOpenDialog->SetAllowMultiSelect( false );
        //}
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnMeshViewerFormLayoutLoaded( GUCEF::CORE::CNotifier* notifier    ,
                                           const GUCEF::CORE::CEvent& eventid  ,
                                           GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    SubscribeTo( m_meshViewerForm.GetOpenMeshFileButton()                           ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                            ,
                 &TEventCallback( this, &CMeshViewer::OnOpenMeshFileButtonPressed ) );
    SubscribeTo( m_meshViewerForm.GetOpenMaterialDirButton()                           ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                               ,
                 &TEventCallback( this, &CMeshViewer::OnOpenMaterialDirButtonPressed ) );
    SubscribeTo( m_meshViewerForm.GetControlCameraButton()                           ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                             ,
                 &TEventCallback( this, &CMeshViewer::OnControlCameraButtonPressed ) );                 
    SubscribeTo( m_meshViewerForm.GetMaterialDirAsMeshDirCheckbox()                           ,
                 GUCEF::GUI::CCheckbox::BoxCheckedEvent                                       ,
                 &TEventCallback( this, &CMeshViewer::OnMaterialDirAsMeshDirCheckboxChecked ) );                                  
    SubscribeTo( m_meshViewerForm.GetCloseButton()                           ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                     ,
                 &TEventCallback( this, &CMeshViewer::OnCloseButtonPressed ) );
    SubscribeTo( m_meshViewerForm.GetShowMeshButton()                         ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                      ,
                 &TEventCallback( this, &CMeshViewer::OnShowMeshButtonPressed ) );
    SubscribeTo( m_meshViewerForm.GetPitchSpinner()                       ,
                 GUCEF::GUI::CSpinner::ValueChangedEvent                  ,
                 &TEventCallback( this, &CMeshViewer::OnMeshPitchChange ) );
    SubscribeTo( m_meshViewerForm.GetYawSpinner()                       ,
                 GUCEF::GUI::CSpinner::ValueChangedEvent                ,
                 &TEventCallback( this, &CMeshViewer::OnMeshYawChange ) );
    SubscribeTo( m_meshViewerForm.GetRollSpinner()                       ,
                 GUCEF::GUI::CSpinner::ValueChangedEvent                 ,
                 &TEventCallback( this, &CMeshViewer::OnMeshRollChange ) );
    SubscribeTo( m_meshViewerForm.GetScaleSpinner()                       ,
                 GUCEF::GUI::CSpinner::ValueChangedEvent                  ,
                 &TEventCallback( this, &CMeshViewer::OnMeshScaleChange ) );                 
    SetupOgreScene();
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::RefreshScene( void )
{GUCE_TRACE;

    // Make sure the scene setup is complete
    SetupOgreScene();

    // Manually force a refresh on the render context (which is actually our texture)
    COgreGUIRenderContext* renderContext = m_meshViewerForm.GetRenderContext();
    if ( NULL != renderContext )
    {
        GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CMeshViewer: Refreshing scene" );
        renderContext->Refresh();
    }     
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnControlCameraButtonPressed( GUCEF::CORE::CNotifier* notifier    ,
                                           const GUCEF::CORE::CEvent& eventid  ,
                                           GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::INPUT::CInputObserverSwitch& inputSwitch = CORE::CGUCEApplication::Instance()->GetInputObserverSwitch();
    //inputSwitch.SetActiveGroup( "MeshViewerScene" );
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnMeshPitchChange( GUCEF::CORE::CNotifier* notifier    ,
                                const GUCEF::CORE::CEvent& eventid  ,
                                GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CSpinner* spinner = m_meshViewerForm.GetPitchSpinner();
    if ( NULL != spinner && NULL != m_meshEntityNode )
    {
        m_meshEntityNode->pitch( Ogre::Degree( spinner->GetValueFloat32() ) );
        RefreshScene();
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnMeshYawChange( GUCEF::CORE::CNotifier* notifier    ,
                              const GUCEF::CORE::CEvent& eventid  ,
                              GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CSpinner* spinner = m_meshViewerForm.GetYawSpinner();
    if ( NULL != spinner && NULL != m_meshEntityNode )
    {
        m_meshEntityNode->yaw( Ogre::Degree( spinner->GetValueFloat32() ) );
        RefreshScene();
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnMeshRollChange( GUCEF::CORE::CNotifier* notifier    ,
                               const GUCEF::CORE::CEvent& eventid  ,
                               GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CSpinner* spinner = m_meshViewerForm.GetRollSpinner();
    if ( NULL != spinner && NULL != m_meshEntityNode )
    {
        m_meshEntityNode->roll( Ogre::Degree( spinner->GetValueFloat32() ) );
        RefreshScene();
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnMeshScaleChange( GUCEF::CORE::CNotifier* notifier    ,
                                const GUCEF::CORE::CEvent& eventid  ,
                                GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CSpinner* spinner = m_meshViewerForm.GetScaleSpinner();
    if ( NULL != spinner && NULL != m_meshEntityNode )
    {
        m_meshEntityNode->scale( Ogre::Vector3( spinner->GetValueFloat32() ) );
        RefreshScene();
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnFileOpenDialogLayoutLoaded( GUCEF::CORE::CNotifier* notifier    ,
                                           const GUCEF::CORE::CEvent& eventid  ,
                                           GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    SubscribeTo( m_fileOpenDialog->GetOkButton()                                  ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                          ,
                 &TEventCallback( this, &CMeshViewer::OnFileOpenDialogSelection ) );
    SubscribeTo( m_fileOpenDialog->GetCancelButton()                                       ,
                 GUCEF::GUI::CButton::ButtonClickedEvent                                   ,
                 &TEventCallback( this, &CMeshViewer::OnFileOpenDialogCloseButtonClicked ) );
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnMaterialDirAsMeshDirCheckboxChecked( GUCEF::CORE::CNotifier* notifier    ,
                                                    const GUCEF::CORE::CEvent& eventid  ,
                                                    GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CEditbox* materialDirEditbox = m_meshViewerForm.GetMaterialDirEditbox();
    if ( NULL != materialDirEditbox )
    {
        CString dir = GUCEF::CORE::StripFilename( m_selectedMesh );
        m_materialDir = dir;
        materialDirEditbox->SetText( dir );
    }
}
                                             
/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnOpenMaterialDirButtonPressed( GUCEF::CORE::CNotifier* notifier    ,
                                             const GUCEF::CORE::CEvent& eventid  ,
                                             GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    m_openState = OPEN_MATERIAL_DIR;
    m_fileOpenDialog->SetAllowedSelection( true, false );
    m_fileOpenDialog->ShowModal();    
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnOpenMeshFileButtonPressed( GUCEF::CORE::CNotifier* notifier    ,
                                          const GUCEF::CORE::CEvent& eventid  ,
                                          GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    m_openState = OPEN_MESH_FILE;
    m_fileOpenDialog->SetAllowedSelection( false, true );
    m_fileOpenDialog->ShowModal();    
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnShowMeshButtonPressed( GUCEF::CORE::CNotifier* notifier    ,
                                      const GUCEF::CORE::CEvent& eventid  ,
                                      GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CListbox* meshListbox = m_meshViewerForm.GetMeshListbox();
    if ( NULL != meshListbox )
    {
        if ( meshListbox->GetFirstSelectedLine( m_selectedMesh ) )
        {
            GUCEF_DEBUG_LOG( GUCEF::CORE::LOGLEVEL_NORMAL, "CMeshViewer: Mesh selected with name \"" + m_selectedMesh + "\"" );
            
            RefreshMaterialListForSelectedMesh();
            
            // detach the mesh from our scene object
            if ( m_meshEntityNode != NULL )
            {
                m_meshEntityNode->detachAllObjects();
            }
            
            // cleanup the entity we already had
            if ( NULL != m_meshEntity )
            {
                m_sceneManager->destroyEntity( m_meshEntity );
            }
            
            // Create an entity to hold our mesh
            m_meshEntity = m_sceneManager->createEntity( "MeshEntity", m_selectedMesh );
            
            if ( m_meshEntityNode == NULL )
            {
                m_meshEntityNode = m_sceneManager->getRootSceneNode()->createChildSceneNode( "MeshEntityNode" );
                
                GUCEF::GUI::CSpinner* spinner = m_meshViewerForm.GetPitchSpinner();
                if ( NULL != spinner )
                {
                    m_meshEntityNode->pitch( Ogre::Degree( spinner->GetValueFloat32() ) );
                }
                spinner = m_meshViewerForm.GetYawSpinner();
                if ( NULL != spinner )
                {
                    m_meshEntityNode->yaw( Ogre::Degree( spinner->GetValueFloat32() ) );
                }
                spinner = m_meshViewerForm.GetRollSpinner();
                if ( NULL != spinner )
                {
                    m_meshEntityNode->roll( Ogre::Degree( spinner->GetValueFloat32() ) );
                }
                spinner = m_meshViewerForm.GetScaleSpinner();
                if ( NULL != spinner )
                {
                    m_meshEntityNode->scale( Ogre::Vector3( spinner->GetValueFloat32() ) );
                }
            }

            // Now we add the entity which has our mesh into the scene by attaching it to our
            // scene node
            m_meshEntityNode->attachObject( m_meshEntity );
            
            // Make sure our camera is initially looking at the mesh
            m_camera->lookAt( m_meshEntityNode->getPosition() );

            // refresh the scene based on what is selected
            RefreshScene();
        }
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::RefreshMaterialListForSelectedMesh( void )
{GUCE_TRACE;

    GUCEF::GUI::CListbox* materialListbox = m_meshViewerForm.GetMaterialListbox();
    if ( NULL != materialListbox )
    {
        // Get a list of materials for this mesh
        CORE::CMeshManager& meshManager = CORE::CGUCEApplication::Instance()->GetMeshManager();
        CORE::CMeshManager::TMaterialNameSet materialNames;
        meshManager.GetMaterialNamesForMesh( m_selectedMesh, materialNames );
        
        // Put the material names in the material list
        materialListbox->Clear();
        CORE::CMeshManager::TMaterialNameSet::iterator i = materialNames.begin();
        while ( i != materialNames.end() )
        {
            materialListbox->AppendLine( (*i) );
            ++i;
        }
    }
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnFileOpenDialogCloseButtonClicked( GUCEF::CORE::CNotifier* notifier    ,
                                                 const GUCEF::CORE::CEvent& eventid  ,
                                                 GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;
    
    m_openState = OPEN_NOTHING;
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnFileOpenDialogSelection( GUCEF::CORE::CNotifier* notifier    ,
                                        const GUCEF::CORE::CEvent& eventid  ,
                                        GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;
    
    switch ( m_openState )
    {
        case OPEN_MESH_FILE :
        {            
            CORE::CMeshManager& meshManager = CORE::CGUCEApplication::Instance()->GetMeshManager();    
            const GUCEF::GUI::CFileSystemDialog::TStringVector& selectedItems = m_fileOpenDialog->GetSelectedItems();
            GUCEF::GUI::CFileSystemDialog::TStringVector::const_iterator i = selectedItems.begin();
            
            while ( i != selectedItems.end() )
            {
                // Build the full path to the file
                CString filePath = m_fileOpenDialog->GetCurrentPath();
                GUCEF::CORE::AppendToPath( filePath, (*i) );
            
                // load the mesh
                CORE::CMeshManager::TMeshMap meshMap;
                meshManager.LoadAllFromFile( filePath, filePath, meshMap, true, "MeshViewer", m_materialDir );
                ++i;
            }
            
            // refresh our list of available meshes
            RefreshMeshList();
            break;
        }
        case OPEN_MATERIAL_DIR :        
        {
            // Set the desired material dir
            const GUCEF::GUI::CFileSystemDialog::TStringVector& selectedItems = m_fileOpenDialog->GetSelectedItems();
            m_materialDir = m_fileOpenDialog->GetCurrentPath();
            GUCEF::CORE::AppendToPath( m_materialDir, *selectedItems.begin() );

            // Update GUI
            GUCEF::GUI::CEditbox* materialDirEditbox = m_meshViewerForm.GetMaterialDirEditbox();
            if ( NULL != materialDirEditbox )
            {
                materialDirEditbox->SetText( m_materialDir );
            }            
            break;
        }
    }
    m_openState = OPEN_NOTHING;
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::ShowModal( void )
{GUCE_TRACE;

    RefreshMeshList();    
    m_meshViewerForm.ShowModal();    
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::Show( void )
{GUCE_TRACE;

    RefreshMeshList();    
    m_meshViewerForm.Show();
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::Hide( void )
{GUCE_TRACE;

    m_meshViewerForm.Hide();
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::OnCloseButtonPressed( GUCEF::CORE::CNotifier* notifier    ,
                                   const GUCEF::CORE::CEvent& eventid  ,
                                   GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    Hide();
}

/*-------------------------------------------------------------------------*/

const CString&
CMeshViewer::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString classTypeName = "GUCE::GUI::CMeshViewer";
    return classTypeName;
}

/*-------------------------------------------------------------------------*/

void
CMeshViewer::RefreshMeshList( void )
{GUCE_TRACE;

    GUCEF::GUI::CListbox* meshListbox = m_meshViewerForm.GetMeshListbox();
    if ( NULL != meshListbox )
    {
        // Obtain a list of loaded meshes from the mesh manager
        CORE::CMeshManager& meshManager = CORE::CGUCEApplication::Instance()->GetMeshManager();
        CORE::CMeshManager::TMeshNameSet meshNameList;
        meshManager.RetieveLoadedMeshList( meshNameList );
        
        // Put the meshes in the mesh list widget
        meshListbox->Clear();
        CORE::CMeshManager::TMeshNameSet::iterator i = meshNameList.begin();
        while ( i != meshNameList.end() )
        {
            meshListbox->AppendLine( (*i) );
            ++i;
        }
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
