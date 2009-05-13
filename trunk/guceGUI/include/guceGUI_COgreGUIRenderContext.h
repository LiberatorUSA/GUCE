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

#ifndef GUCE_GUI_COGREGUIRENDERCONTEXT_H
#define GUCE_GUI_COGREGUIRENDERCONTEXT_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _TextureManager_H__
#include <OgreTextureManager.h>
#define _TextureManager_H__
#endif /* _TextureManager_H__ ? */

#ifndef GUCEF_GUI_CRENDERCONTEXT_H
#include "gucefGUI_CRenderContext.h"
#define GUCEF_GUI_CRENDERCONTEXT_H
#endif /* GUCEF_GUI_CRENDERCONTEXT_H ? */

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

class GUCE_GUI_EXPORT_CPP COgreGUIRenderContext : public GUCEF::GUI::CRenderContext
{    
    public:
    
    COgreGUIRenderContext( void );
    
    virtual ~COgreGUIRenderContext();
    
    virtual bool SetRenderTexture( Ogre::TexturePtr texture );
    
    virtual Ogre::TexturePtr GetRenderTexture( void );
    
    private:
    
    COgreGUIRenderContext( const COgreGUIRenderContext& src );
    COgreGUIRenderContext& operator=( const COgreGUIRenderContext& src );
    
    private:
    
    Ogre::TexturePtr m_renderTexture;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_GUI_COGREGUIRENDERCONTEXT_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
