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
 
#ifndef GUCE_CEGUIOGRE_OGRECEGUIRENDERER_H
#define GUCE_CEGUIOGRE_OGRECEGUIRENDERER_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include "CEGUIBase.h"
#include "CEGUIRenderer.h"
#include "CEGUITexture.h"

#include <OgreRenderQueueListener.h>
#include <OgreSceneManagerEnumerator.h>
#include <OgreTextureUnitState.h>

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

/*************************************************************************
	Forward refs
*************************************************************************/
class OgreCEGUITexture;
class OgreCEGUIRenderer;


/*!
\brief
	RenderQueueListener based class used to hook into the ogre rendering system
*/
class GUCEGUI_EXPORT_CPP CEGUIRQListener : public Ogre::RenderQueueListener
{
public:
	CEGUIRQListener(OgreCEGUIRenderer* renderer, Ogre::uint8 queue_id, bool post_queue)
	{
		d_renderer		= renderer;
		d_queue_id		= queue_id;
		d_post_queue	= post_queue;
	}

	virtual ~CEGUIRQListener() {}

	virtual void	renderQueueStarted(Ogre::uint8 id, const Ogre::String& invocation, bool& skipThisQueue);
	virtual void	renderQueueEnded(Ogre::uint8 id, const Ogre::String& invocation, bool& repeatThisQueue);

	// methods for adjusting target queue settings
	void	setTargetRenderQueue(Ogre::uint8 queue_id)		{d_queue_id = queue_id;}
	void	setPostRenderQueue(bool post_queue)		{d_post_queue = post_queue;}

private:
	/*************************************************************************
		Implementation Data
	*************************************************************************/
	OgreCEGUIRenderer*				d_renderer;		//!< CEGUI renderer object for Ogre.
	Ogre::uint8	d_queue_id;		//!< ID of the queue that we are hooked into
	bool						d_post_queue;	//!< true if we render after everything else in our queue.
};


/*!
\brief
	Renderer class to interface with Ogre engine.
*/
class GUCEGUI_EXPORT_CPP OgreCEGUIRenderer : public CEGUI::Renderer
{
public:
	/*!
	\brief
		Constructor for renderer class that uses Ogre for rendering. Note that if
		you use this option you must call setTargetSceneManager before rendering.

	\param window
		Pointer to an Ogre::RenderWindow object.

	\param queue_id
		Ogre::uint8 value that specifies where the GUI should appear in the ogre rendering output.

	\param post_queue
		set to true to have GUI rendered after render queue \a queue_id, or false to have the GUI rendered before render queue
		\a queue_id.

	\param max_quads
		Obsolete.  Set to 0.

	*/
	OgreCEGUIRenderer(Ogre::RenderWindow* window,
		Ogre::uint8 queue_id = Ogre::RENDER_QUEUE_OVERLAY,
		bool post_queue = false, CEGUI::uint max_quads = 0);


	/*!
	\brief
		Constructor for renderer class that uses Ogre for rendering.

	\param window
		Pointer to an Ogre::RenderWindow object.

	\param queue_id
		Ogre::uint8 value that specifies where the GUI should appear in the ogre rendering output.

	\param post_queue
		set to true to have GUI rendered after render queue \a queue_id, or false to have the GUI rendered before render queue
		\a queue_id.

	\param max_quads
		Obsolete.  Set to 0.

	\param scene_manager
		Pointer to an Ogre::SceneManager object that is to be used for GUI rendering.
	*/
	OgreCEGUIRenderer(Ogre::RenderWindow* window, Ogre::uint8 queue_id, bool post_queue, CEGUI::uint max_quads, Ogre::SceneManager* scene_manager);


	/*!
	\brief
		Destructor for Ogre renderer.
	*/
	virtual ~OgreCEGUIRenderer(void);



	// add's a quad to the list to be rendered
	virtual	void	addQuad(const CEGUI::Rect& dest_rect, float z, const CEGUI::Texture* tex, const CEGUI::Rect& texture_rect, const CEGUI::ColourRect& colours, CEGUI::QuadSplitMode quad_split_mode);

	// perform final rendering for all queued renderable quads.
	virtual	void	doRender(void);

	// clear the queue
	virtual	void	clearRenderList(void);


	/*!
	\brief
		Enable or disable the queueing of quads from this point on.

		This only affects queueing.  If queueing is turned off, any calls to addQuad will cause the quad to be rendered directly.  Note that
		disabling queueing will not cause currently queued quads to be rendered, nor is the queue cleared - at any time the queue can still
		be drawn by calling doRender, and the list can be cleared by calling clearRenderList.  Re-enabling the queue causes subsequent quads
		to be added as if queueing had never been disabled.

	\param setting
		true to enable queueing, or false to disable queueing (see notes above).

	\return
		Nothing
	*/
	virtual void	setQueueingEnabled(bool setting)		{d_queueing = setting;}


	// create an empty texture
	virtual	CEGUI::Texture*	createTexture(void);

	// create a texture and load it with the specified file.
	virtual	CEGUI::Texture*	createTexture(const CEGUI::String& filename, const CEGUI::String& resourceGroup = "General");

	// create a texture and set it to the specified size
	virtual	CEGUI::Texture*	createTexture(float size);

    // create an OGRE resource provider.
    virtual CEGUI::ResourceProvider* createResourceProvider(void);

	// destroy the given texture
	virtual	void		destroyTexture(CEGUI::Texture* texture);

	// destroy all textures still active
	virtual void		destroyAllTextures(void);


	/*!
	\brief
		Return whether queueing is enabled.

	\return
		true if queueing is enabled, false if queueing is disabled.
	*/
	virtual bool	isQueueingEnabled(void) const	{return d_queueing;}


	/*!
	\brief
	Return the current width of the display in pixels

	\return
	float value equal to the current width of the display in pixels.
	*/
	virtual float	getWidth(void) const		{return d_display_area.getWidth();}


	/*!
	\brief
	Return the current height of the display in pixels

	\return
	float value equal to the current height of the display in pixels.
	*/
	virtual float	getHeight(void) const		{return d_display_area.getHeight();}


	/*!
	\brief
	Return the size of the display in pixels

	\return
	Size object describing the dimensions of the current display.
	*/
	virtual CEGUI::Size	getSize(void) const			{return d_display_area.getSize();}


	/*!
	\brief
	Return a Rect describing the screen

	\return
	A Rect object that describes the screen area.  Typically, the top-left values are always 0, and the size of the area described is
	equal to the screen resolution.
	*/
	virtual CEGUI::Rect	getRect(void) const			{return d_display_area;}


	/*!
	\brief
		Return the maximum texture size available

	\return
		Size of the maximum supported texture in pixels (textures are always assumed to be square)
	*/
	virtual	CEGUI::uint	getMaxTextureSize(void) const		{return 2048;}		// TODO: Change to proper value


	/*!
	\brief
		Return the horizontal display resolution dpi

	\return
		horizontal resolution of the display in dpi.
	*/
	virtual	CEGUI::uint	getHorzScreenDPI(void) const	{return 96;}


	/*!
	\brief
		Return the vertical display resolution dpi

	\return
		vertical resolution of the display in dpi.
	*/
	virtual	CEGUI::uint	getVertScreenDPI(void) const	{return 96;}


	/*!
	\brief
		Set the scene manager to be used for rendering the GUI.

		The GUI system will be unhooked from the current scene manager and attached to what ever
		is specified here.

	\param scene_manager
		Pointer to an Ogre::SceneManager object that is the new target Ogre::SceneManager to be
		used for GUI rendering.

	\return
		Nothing.
	*/
	void	setTargetSceneManager(Ogre::SceneManager* scene_manager);


	/*!
	\brief
		Set the target render queue for GUI rendering.

	\param queue_id
		Ogre::uint8 value specifying the render queue that the GUI system should attach to.

	\param post_queue
		- true to specify that the GUI should render after everything else in render queue \a queue_id.
		- false to specify the GUI should render before everything else in render queue \a queue_id.

	\return
		Nothing.
	*/
	void	setTargetRenderQueue(Ogre::uint8 queue_id, bool post_queue);


	/*!
	\brief
		Create a texture from an existing Ogre::TexturePtr object.

	\note
		If you want to use an Ogre::RenderTexture (for putting rendered output onto Gui elements or other
		advanced techniques), you can get the Ogre::TexturePtr to be used by calling Ogre::TextureManager::getByName()
		passing the name returned from Ogre::RenderTexture::getName() (and casting the result as necessary).

	\param texture
		pointer to an Ogre::TexturePtr object to be used as the basis for the new CEGUI::Texture

	\return
		Pointer to the newly created CEGUI::TexturePtr object.
	*/
	CEGUI::Texture*	createTexture(Ogre::TexturePtr& texture);


	/*!
	\brief
	Set the size of the display in pixels.

	You do not have to call this method under normal operation as the system
	will automatically extract the size from the current view port.

	\note
	This method will cause the EventDisplaySizeChanged event to fire if the
	display size has changed.

	\param sz
	Size object describing the size of the display.

	\return
	Nothing.
	*/
	void	setDisplaySize(const CEGUI::Size& sz);


private:
	/************************************************************************
		Implementation Constants
	************************************************************************/
	static const size_t    VERTEX_PER_QUAD;						 //!< number of vertices per quad
	static const size_t    VERTEX_PER_TRIANGLE;					 //!< number of vertices for a triangle
    static const size_t    VERTEXBUFFER_INITIAL_CAPACITY;		 //!< initial capacity of the allocated vertex buffer
    static const size_t    UNDERUSED_FRAME_THRESHOLD;            //!< number of frames to wait before shrinking buffer

	/*************************************************************************
	    Implementation Structs & classes
	*************************************************************************/
	/*!
	\brief
		structure used for all vertices.
	*/
	struct QuadVertex {
		float x, y, z;			//!< The position for the vertex.
		Ogre::RGBA diffuse;		//!< colour of the vertex
		float tu1, tv1;			//!< texture coordinates
	};

	/*!
	\brief
		structure holding details about a quad to be drawn
	*/
	struct QuadInfo
	{
		Ogre::TexturePtr		texture;
		CEGUI::Rect				position;
		float				z;
		CEGUI::Rect				texPosition;
        CEGUI::uint32		        topLeftCol;
        CEGUI::uint32		        topRightCol;
        CEGUI::uint32		        bottomLeftCol;
        CEGUI::uint32		        bottomRightCol;

        CEGUI::QuadSplitMode		splitMode;

		bool operator<(const QuadInfo& other) const
		{
			// this is intentionally reversed.
			return z > other.z;
		}
	};


	/*************************************************************************
	    Implementation Methods
	*************************************************************************/
	// setup states etc
	void	initRenderStates(void);

	// sort quads list according to texture
	void	sortQuads(void);

	// render a quad directly to the display
	void	renderQuadDirect(const CEGUI::Rect& dest_rect, float z, const CEGUI::Texture* tex, const CEGUI::Rect& texture_rect, const CEGUI::ColourRect& colours, CEGUI::QuadSplitMode quad_split_mode);

	// convert colour value to whatever the Ogre render system is expecting.
    CEGUI::uint32    colourToOgre(const CEGUI::colour& col) const;

	// perform main work of the constructor.  This does everything except the final hook into the render system.
	void	constructor_impl(Ogre::RenderWindow* window, Ogre::uint8 queue_id, bool post_queue, CEGUI::uint max_quads);


	/*************************************************************************
	    Implementation Data
	*************************************************************************/
	CEGUI::Rect				d_display_area;

	typedef std::multiset<QuadInfo>		QuadList;
	QuadList d_quadlist;
	bool	 d_queueing;		//!< setting for queueing control.

	// Ogre specific bits.
	Ogre::Root*					d_ogre_root;		//!< pointer to the Ogre root object that we attach to
	Ogre::RenderSystem*			d_render_sys;		//!< Pointer to the render system for Ogre.
	Ogre::uint8	d_queue_id;			//!< ID of the queue that we are hooked into
	Ogre::TexturePtr			d_currTexture;		//!< currently set texture;
	Ogre::RenderOperation		d_render_op;		//!< Ogre render operation we use to do our stuff.
	Ogre::HardwareVertexBufferSharedPtr	d_buffer;	//!< vertex buffer to queue sprite rendering
    size_t d_underused_framecount;                  //!< Number of frames elapsed since buffer utilization was above half the capacity
    Ogre::RenderOperation		d_direct_render_op;		//!< Renderop for cursor
	Ogre::HardwareVertexBufferSharedPtr	d_direct_buffer;	//!< Renderop for cursor
	Ogre::SceneManager*			d_sceneMngr;		//!< The scene manager we are hooked into.
	Ogre::LayerBlendModeEx		d_colourBlendMode;	//!< Controls colour blending mode used.
	Ogre::LayerBlendModeEx		d_alphaBlendMode;	//!< Controls alpha blending mode used.
	Ogre::TextureUnitState::UVWAddressingMode d_uvwAddressMode;

	CEGUIRQListener*			d_ourlistener;
	bool						d_post_queue;		//!< true if we render after everything else in our queue.
	size_t						d_bufferPos;		//!< index into buffer where next vertex should be put.
	bool						d_sorted;			//!< true when data in quad list is sorted.
	CEGUI::Point						d_texelOffset;		//!< Offset required for proper texel mapping.

	std::list<OgreCEGUITexture*> d_texturelist;		//!< List used to track textures.
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif	/* GUCE_CEGUIOGRE_OGRECEGUIRENDERER_H ? */