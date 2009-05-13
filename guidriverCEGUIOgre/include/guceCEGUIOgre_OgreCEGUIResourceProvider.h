/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2007.  All rights reserved.
 *
 * All source code herein is the property of Dinand Vanvelzen. You may not sell
 * or otherwise commercially exploit the source or things you created based on
 * the source.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL DINAND VANVELZEN BE LIABLE FOR ANY SPECIAL, INCIDENTAL, 
 * INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER 
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF 
 * THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT 
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
 *
 * Note that this code is a forked version of code made by James '_mental_' O'Sullivan
 */
 
/*
 *  Integrated into the GUCE codebase to be able to garantee compatibility
 *  between Ogre and CEGUI. This version should not be considdered generic
 *  and may be altered to fit the needs of GUCE.
 */

#ifndef GUCE_GUI_OGRECEGUIRESOURCEPROVIDER_H
#define GUCE_GUI_OGRECEGUIRESOURCEPROVIDER_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include "CEGUIResourceProvider.h"
#include "guceGUI_OgreCEGUIRenderer.h"

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

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

class GUCEGUI_EXPORT_CPP OgreCEGUIResourceProvider : public CEGUI::ResourceProvider
{
public:
	/*************************************************************************
		Construction and Destruction
	*************************************************************************/
	OgreCEGUIResourceProvider();

	virtual ~OgreCEGUIResourceProvider() {}

//    void loadInputSourceContainer(const String& filename, InputSourceContainer& output);
    void loadRawDataContainer(const CEGUI::String& filename, CEGUI::RawDataContainer& output, const CEGUI::String& resourceGroup);
    void unloadRawDataContainer(CEGUI::RawDataContainer& output);
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif	/* GUCE_GUI_OGRECEGUIRESOURCEPROVIDER_H ? */
