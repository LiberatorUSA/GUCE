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
 
#include "CEGUIExceptions.h"
#include <OgreArchiveManager.h>

#include "guceGUI_OgreCEGUIResourceProvider.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace GUI {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

    OgreCEGUIResourceProvider::OgreCEGUIResourceProvider() : ResourceProvider()
    {
        // set deafult resource group for Ogre
        d_defaultResourceGroup = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str();
    }

//    void OgreResourceProvider::loadInputSourceContainer(const String& filename, InputSourceContainer& output)
//   {
//        Ogre::DataStreamPtr input = Ogre::ResourceGroupManager::getSingleton().openResource(filename.c_str());
//
//		if (input.isNull())
//		{
//			throw InvalidRequestException((utf8*)
//				"Scheme::Scheme - Filename supplied for Scheme loading must be valid");
//		}
//
//       XERCES_CPP_NAMESPACE_USE
//        size_t buffsz = input->size();
//        unsigned char* mem = reinterpret_cast<unsigned char*>(XMLPlatformUtils::fgArrayMemoryManager->allocate(buffsz));
//        memcpy(mem, input.getPointer()->getAsString().c_str(), buffsz);
//        InputSource* mInputSource = new MemBufInputSource(mem, buffsz, filename.c_str(), true);
//        input.setNull();
//
//       output.setData(mInputSource);
//    }

    void OgreCEGUIResourceProvider::loadRawDataContainer(const CEGUI::String& filename, CEGUI::RawDataContainer& output,  const CEGUI::String& resourceGroup)
    {
        CEGUI::String orpGroup;
        if (resourceGroup.empty())
            orpGroup = d_defaultResourceGroup.empty() ? Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str() : d_defaultResourceGroup;
        else
            orpGroup = resourceGroup;

        Ogre::DataStreamPtr input = Ogre::ResourceGroupManager::getSingleton().openResource(filename.c_str(), orpGroup.c_str());

		if (input.isNull())
		{
            throw CEGUI::InvalidRequestException((CEGUI::utf8*)
                "OgreCEGUIResourceProvider::loadRawDataContainer - Unable to open resource file '" + filename + (CEGUI::utf8*)"' in resource group '" + orpGroup + (CEGUI::utf8*)"'.");
        }

		 
		// when copying the string buffer we want to include the null terminator.
		// Only TinyXML makes use of the null terminator to determine if end of buffer has been reached.
		// The other XML parsers that can be used in CEGUI use the buffer size which does not include the null terminator.
        unsigned char* mem = new unsigned char[ input->size()+1 ];
        input->read( mem, input->size() );
        mem[ input->size() ] = '\0';

        output.setData( mem );
        output.setSize( input->size() );
    }

	void OgreCEGUIResourceProvider::unloadRawDataContainer(CEGUI::RawDataContainer& data)
	{
		if (data.getDataPtr())
		{
			delete[] data.getDataPtr();
			data.setData(0);
			data.setSize(0);
		}
	}
	
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUI */

/*-------------------------------------------------------------------------*/
