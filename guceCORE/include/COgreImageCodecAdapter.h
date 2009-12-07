/*
 *  guceCORE: GUCE module providing tie-in functionality between systems
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
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

#ifndef GUCE_CORE_COGREIMAGECODECADAPTER_H
#define GUCE_CORE_COGREIMAGECODECADAPTER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _ImageCodec_H__
#include "OgreImageCodec.h"      /* Ogre image codec base class */
#define _ImageCodec_H__
#endif /* _ImageCodec_H__ ? */

#ifndef GUCEF_IMAGE_IMAGEDATA_H
#include "imagedata.h"
#define GUCEF_IMAGE_IMAGEDATA_H
#endif /* GUCEF_IMAGE_IMAGEDATA_H ? */

#ifndef GUCEF_IMAGE_CIMAGE_H
#include "CImage.h"
#define GUCEF_IMAGE_CIMAGE_H
#endif /* GUCEF_IMAGE_CIMAGE_H ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#ifndef GUCEF_CORE_CICODEC_H
#include "CICodec.h"             /* GUCEF base class for codecs */
#define GUCEF_CORE_CICODEC_H
#endif /* GUCEF_CORE_CICODEC_H ? */

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
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP COgreImageCodecAdapter : public Ogre::ImageCodec
{
    public:
    typedef GUCEF::CORE::CTSharedPtr< GUCEF::CORE::CICodec > CGUCEFCodecPtr;
    
    COgreImageCodecAdapter( const CGUCEFCodecPtr& codecPtr );

    virtual ~COgreImageCodecAdapter();

    /// @copydoc Codec::code
    virtual Ogre::DataStreamPtr code( Ogre::MemoryDataStreamPtr& input , 
                                      Ogre::Codec::CodecDataPtr& pData ) const;
    
    /// @copydoc Codec::codeToFile
    virtual void codeToFile( Ogre::MemoryDataStreamPtr& input ,
                             const Ogre::String& outFileName  , 
                             Ogre::Codec::CodecDataPtr& pData ) const;

    /// @copydoc Codec::decode
    virtual Ogre::Codec::DecodeResult decode( Ogre::DataStreamPtr& input ) const;
    
    static Ogre::Codec::DecodeResult decode( const GUCEF::IMAGE::CImage& input );

    virtual Ogre::String getType() const;
    
    virtual Ogre::String magicNumberToFileExt( const char *magicNumberPtr , 
                                               size_t maxbytes            ) const;
    
    CGUCEFCodecPtr GetCodecPtr( void );        
    
    private:
    
    COgreImageCodecAdapter( const COgreImageCodecAdapter& src );            /**< not implemented */
    COgreImageCodecAdapter& operator=( const COgreImageCodecAdapter& src ); /**< not implemented */

    static Ogre::PixelFormat GUCEFPSToOgrePF( GUCEF::IMAGE::TPixelStorageFormat psf     ,
                                              GUCEF::IMAGE::TBuildinDataType biDataType );
    
    private:
    
    CGUCEFCodecPtr m_gucefCodecPtr; 
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_COGREIMAGECODECADAPTER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-10-2006 :
        - Initial version

-----------------------------------------------------------------------------*/