/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2005.  All rights reserved.
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
 * Note that this code is a forked version of code made by Paul D Turner
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <OgreTextureManager.h>
#include "CEGUISystem.h"
#include "CEGUIExceptions.h"
#include "guceGUI_OgreCEGUITexture.h"
#include "guceGUI_OgreCEGUIRenderer.h"

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


/*************************************************************************
	Static data definition / initialisation
*************************************************************************/
CEGUI::uint32 OgreCEGUITexture::d_texturenumber		= 0;


/*************************************************************************
	Constructor
*************************************************************************/
OgreCEGUITexture::OgreCEGUITexture(CEGUI::Renderer* owner) :
	CEGUI::Texture(owner)
{
	d_ogre_texture.setNull();
	d_isLinked = false;
}


/*************************************************************************
	Destructor
*************************************************************************/
OgreCEGUITexture::~OgreCEGUITexture()
{
	freeOgreTexture();
}


/*************************************************************************
	Loads the specified image file into the texture.  The texture is
	resized as required to hold the image.	
*************************************************************************/
void OgreCEGUITexture::loadFromFile(const CEGUI::String& filename, const CEGUI::String& resourceGroup)
{
	// unload old ogre texture
	freeOgreTexture();

	// create / load a new ogre texture from the specified image
	try
	{
		Ogre::TextureManager& textureManager = Ogre::TextureManager::getSingleton();

		// see if texture already exists
		Ogre::TexturePtr ogreTexture = (Ogre::TexturePtr)textureManager.getByName(filename.c_str());

		if (!ogreTexture.isNull())
		{
			// texture already exists, so create a 'linked' texture (ensures texture is not destroyed twice)
			d_ogre_texture = ogreTexture;
			d_isLinked = true;
		}
		// texture does not already exist, so load it in
		else
		{
            CEGUI::String orpGroup;
            if (resourceGroup.empty())
            {
                const CEGUI::String& defGrp = CEGUI::System::getSingleton().getResourceProvider()->getDefaultResourceGroup();
                orpGroup = defGrp.empty() ? Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str() : defGrp;
            }
            else
            {
                orpGroup = resourceGroup;
            }

			d_ogre_texture = Ogre::TextureManager::getSingleton().load(filename.c_str(), orpGroup.c_str(), Ogre::TEX_TYPE_2D, 0, 1.0f);
			d_isLinked = false;
		}

	}
	catch(Ogre::Exception e)
	{
		throw CEGUI::RendererException((CEGUI::utf8*)"Failed to create Texture object from file '" + filename + "'. Additional Information:\n" + e.getFullDescription().c_str());
	}

	// if we got a pointer cache some details
	if (!d_ogre_texture.isNull())
	{
		d_width		= (CEGUI::ushort) d_ogre_texture->getWidth();
		d_height	= (CEGUI::ushort) d_ogre_texture->getHeight();
	}
	// no texture from image so throw.
	else
	{
		throw CEGUI::RendererException((CEGUI::utf8*)"Failed to create Texture object from file '" + filename + "'.  Ogre returned a NULL pointer.");
	}

}

Ogre::TexturePtr
OgreCEGUITexture::getOgreTexture( void ) const
{
    return d_ogre_texture;
}


/*************************************************************************
	Loads (copies) an image in memory into the texture.  The texture is
	resized as required to hold the image.	
*************************************************************************/

void _byteSwap(unsigned char* b, int n)
{
    register int i = 0;
    register int j = n-1;
    while (i<j)
    {
        std::swap(b[i], b[j]);
        i++, j--;
    }
}
#define byteSwap(x) _byteSwap((unsigned char*) &x,sizeof(x))

void OgreCEGUITexture::loadFromMemory(const void* buffPtr, CEGUI::uint buffWidth, CEGUI::uint buffHeight, CEGUI::Texture::PixelFormat pixelFormat)
{

	// get rid of old texture
	freeOgreTexture();

	// wrap input buffer with an Ogre DataChunk
    CEGUI::uint32 bytesize = ((buffWidth * sizeof(CEGUI::uint32)) * buffHeight);

#if OGRE_ENDIAN == OGRE_ENDIAN_BIG
    CEGUI::uint32* swappedBuffer = new CEGUI::uint32[bytesize/4];
    memcpy(swappedBuffer, buffPtr, bytesize);

    for (int i=0; i < bytesize/4; i++)
        byteSwap(swappedBuffer[i]);

    Ogre::DataStreamPtr odc(new Ogre::MemoryDataStream(static_cast<void*>(swappedBuffer), bytesize, false));
#else
	Ogre::DataStreamPtr odc(new Ogre::MemoryDataStream(const_cast<void*>(buffPtr), bytesize, false));
#endif

	Ogre::PixelFormat ogrePF = Ogre::PF_UNKNOWN;
	switch ( pixelFormat )
	{
	    case CEGUI::Texture::PF_RGB :
	    {
	        ogrePF = Ogre::PF_R8G8B8;
	        break;
	    }
	    case CEGUI::Texture::PF_RGBA :
	    {
	        ogrePF = Ogre::PF_R8G8B8A8;
	        break;
	    }
	    default :
	    {
	        assert( 0 );
	        break;
	    }	    
    }
	
	// try to create a Ogre::Texture from the input data                                                                
    d_ogre_texture = Ogre::TextureManager::getSingleton().loadRawData(getUniqueName(), "General", odc, buffWidth, buffHeight, pixelFormat == CEGUI::Texture::PF_RGB ? Ogre::PF_R8G8B8 : Ogre::PF_A8R8G8B8, Ogre::TEX_TYPE_2D, 0, 1.0f );
    
	// if we got a pointer cache some details
	if (!d_ogre_texture.isNull())
	{
		d_width		= (CEGUI::ushort) d_ogre_texture->getWidth();
		d_height	= (CEGUI::ushort) d_ogre_texture->getHeight();
	}
	// no texture from memory so throw.
	else
	{
		throw CEGUI::RendererException((CEGUI::utf8*)"Failed to create Texture object from memory:  Ogre returned a NULL Ogre::Texture pointer.");
	}

}


/*************************************************************************
	set the size of the internal Ogre texture.  Previous Ogre texture
	is lost.	
*************************************************************************/
void OgreCEGUITexture::setOgreTextureSize(CEGUI::uint size)
{
	// unload any current Ogre::Texture
	freeOgreTexture();

	// Try to create an empty texture of the given size
	d_ogre_texture = Ogre::TextureManager::getSingleton().createManual(getUniqueName(), "General", Ogre::TEX_TYPE_2D, size, size, 0, Ogre::PF_A8R8G8B8, Ogre::TU_DEFAULT);

	// if we got a pointer cache some details
	if (!d_ogre_texture.isNull())
	{
		d_width		= (CEGUI::ushort) d_ogre_texture->getWidth();
		d_height	= (CEGUI::ushort) d_ogre_texture->getHeight();
	}
	// no texture so throw.
	else
	{
		throw CEGUI::RendererException((CEGUI::utf8*)"Failed to create texture of specified size: Ogre::Texture creation failed.");
	}

}


/*************************************************************************
	safely free Ogre::Texture texture (can be called multiple times with
	no ill effect)
*************************************************************************/
void OgreCEGUITexture::freeOgreTexture(void)
{
	if ((!d_ogre_texture.isNull()) && !d_isLinked)
	{
		Ogre::TextureManager::getSingleton().remove(d_ogre_texture->getHandle());
	}
	d_ogre_texture.setNull();
}


/*************************************************************************
	return a Ogre::string that contains a unique name.	
*************************************************************************/
Ogre::String OgreCEGUITexture::getUniqueName(void)
{
	Ogre::String str;

#ifdef CEGUI_USEOLDOGRESTRING
	str << "_cegui_ogre_" << d_texturenumber;
#else
	Ogre::StringUtil::StrStreamType strstream;
	strstream << "_cegui_ogre_" << d_texturenumber;
	str = strstream.str();
#endif

	++d_texturenumber;

	return str;
}


/*************************************************************************
	Set the internal Ogre::Texture object.
*************************************************************************/
void OgreCEGUITexture::setOgreTexture(Ogre::TexturePtr& texture)
{
	freeOgreTexture();

	d_ogre_texture = texture;
	d_width	 = (CEGUI::ushort) d_ogre_texture->getWidth();
	d_height = (CEGUI::ushort) d_ogre_texture->getHeight();
	d_isLinked = true;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
