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
 
/*
 *  Integrated into the GUCE codebase to be able to garantee compatibility
 *  between Ogre and CEGUI. This version should not be considdered generic
 *  and may be altered to fit the needs of GUCE.
 */
 
#ifndef GUCE_CEGUIOGRE_OGRECEGUITEXTURE_H
#define GUCE_CEGUIOGRE_OGRECEGUITEXTURE_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include "CEGUIBase.h"
#include "CEGUIRenderer.h"
#include "CEGUITexture.h"

#ifndef GUCE_CEGUIOGRE_OGRECEGUIRENDERER_H
#include "guceCEGUIOgre_OgreCEGUIRenderer.h"
#define GUCE_CEGUIOGRE_OGRECEGUIRENDERER_H
#endif /* GUCE_CEGUIOGRE_OGRECEGUIRENDERER_H ? */

#ifndef GUCE_GUI_MACROS_H
#include "guceGUI_macros.h"     /* guceCORE build config and macros */
#define GUCE_GUI_MACROS_H
#endif /* GUCE_GUI_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/*!
\brief
	Texture class that is created by OgreCEGUIRenderer objects
*/
class GUCEGUI_EXPORT_CPP OgreCEGUITexture : public CEGUI::Texture
{
private:
	/*************************************************************************
		Friends (to allow construction and destruction)
	*************************************************************************/
	friend	CEGUI::Texture* OgreCEGUIRenderer::createTexture(void);
	friend	CEGUI::Texture* OgreCEGUIRenderer::createTexture(const CEGUI::String& filename, const CEGUI::String& resourceGroup);
	friend	CEGUI::Texture* OgreCEGUIRenderer::createTexture(float size);
	friend	void	 OgreCEGUIRenderer::destroyTexture(CEGUI::Texture* texture);


	/*************************************************************************
		Construction & Destruction (by Renderer object only)
	*************************************************************************/
public:	
	
	OgreCEGUITexture(CEGUI::Renderer* owner);
	virtual ~OgreCEGUITexture();
	
	/*!
	\brief
		Returns the current pixel width of the texture

	\return
		ushort value that is the current width of the texture in pixels
	*/
	virtual	CEGUI::ushort	getWidth(void) const		{return d_width;}


	/*!
	\brief
		Returns the current pixel height of the texture

	\return
		ushort value that is the current height of the texture in pixels
	*/
	virtual	CEGUI::ushort	getHeight(void) const		{return d_height;}


	/*!
	\brief
		Loads the specified image file into the texture.  The texture is resized as required to hold the image.

	\param filename
		The filename of the image file that is to be loaded into the texture

	\return
		Nothing.
	*/
	virtual void	loadFromFile(const CEGUI::String& filename, const CEGUI::String& resourceGroup);


	/*!
	\brief
		Loads (copies) an image in memory into the texture.  The texture is resized as required to hold the image.

	\param buffPtr
		Pointer to the buffer containing the image data

	\param buffWidth
		Width of the buffer (in pixels as specified by \a pixelFormat )

	\param buffHeight
		Height of the buffer (in pixels as specified by \a pixelFormat )

    \param pixelFormat
        PixelFormat value describing the format contained in \a buffPtr

	\return
		Nothing.
	*/
    virtual void loadFromMemory( const void* buffPtr, CEGUI::uint buffWidth, CEGUI::uint buffHeight, CEGUI::Texture::PixelFormat pixelFormat = CEGUI::Texture::PF_RGBA);

	/*!
	\brief
		Return a pointer to the internal Ogre::Texture object

	\return
		Pointer to the Ogre::Texture object currently being used by this Texture object
	*/
	Ogre::TexturePtr	getOgreTexture(void) const;


	/*!
	\brief
		set the size of the internal Ogre texture.  Previous Ogre texture is lost.

	\param size
		pixel size of the new internal texture.  This will be rounded up to a power of 2.

	\return
		Nothing.
	*/
	void	setOgreTextureSize(CEGUI::uint size);


	/*!
	\brief
		Set the internal Ogre::TexturePtr object.

	\param texture
		Reference to an Ogre::TexturePtr object that is to be used by this Texture object.

	\return
		Nothing.
	*/
	void	setOgreTexture(Ogre::TexturePtr& texture);


private:
	/*************************************************************************
		Implementation Functions
	*************************************************************************/
	// safely free Ogre::Texture texture (can be called multiple times with no ill effect)
	void	freeOgreTexture(void);

	// return a Ogre::string that contains a unique name.
	Ogre::String	getUniqueName(void);


	/*************************************************************************
		Implementation Data
	*************************************************************************/
	static	CEGUI::uint32          d_texturenumber;	//!< Counter used to provide unique texture names.

	Ogre::TexturePtr		d_ogre_texture;		//!< The 'real' texture.

	CEGUI::ushort					d_width;			//!< cached width of the texture
	CEGUI::ushort					d_height;			//!< cached height of the texture

	bool	d_isLinked;		//!< True if we are linked to a texture we did not actually create.
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif	/* GUCE_CEGUIOGRE_OGRECEGUITEXTURE_H ? */
