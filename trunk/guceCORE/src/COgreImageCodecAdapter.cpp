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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _Image_H__
#include "OgreImage.h"
#define _Image_H__
#endif /* _Image_H__ ? */

#ifndef __Exception_H_
#include "OgreException.h"
#define __Exception_H_
#endif /* __Exception_H_ ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_CFILEACCESS_H
#include "CFileAccess.h"
#define GUCEF_CORE_CFILEACCESS_H
#endif /* GUCEF_CORE_CFILEACCESS_H ? */

#ifndef GUCEF_CORE_CCODECREGISTRY_H
#include "CCodecRegistry.h"
#define GUCEF_CORE_CCODECREGISTRY_H
#endif /* GUCEF_CORE_CCODECREGISTRY_H ? */

#ifndef GUCE_CORE_COGREDATASTREAMTOIOACCESS_H
#include "COgreDataStreamToIOAccess.h"
#define GUCE_CORE_COGREDATASTREAMTOIOACCESS_H
#endif /* GUCE_CORE_COGREDATASTREAMTOIOACCESS_H ? */

#ifndef GUCEF_IMAGE_CIMGCODEC_H
#include "CIMGCodec.h"
#define GUCEF_IMAGE_CIMGCODEC_H
#endif /* GUCEF_IMAGE_CIMGCODEC_H ? */

#include "COgreImageCodecAdapter.h"

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

COgreImageCodecAdapter::COgreImageCodecAdapter( const CGUCEFCodecPtr& codecPtr )
    : ImageCodec()                ,
      m_gucefCodecPtr( codecPtr )
{GUCE_TRACE;

    assert( m_gucefCodecPtr != NULL );
}

/*-------------------------------------------------------------------------*/

COgreImageCodecAdapter::~COgreImageCodecAdapter()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

Ogre::PixelFormat
COgreImageCodecAdapter::GUCEFPSToOgrePF( GUCEF::IMAGE::TPixelStorageFormat psf     ,
                                         GUCEF::IMAGE::TBuildinDataType biDataType )
{GUCE_TRACE;
    
    // Here we try to convert from the GUCEF pixel format description to that used by Ogre
    // They are not 100% compatible, if we are unable to match them then Ogre::PF_UNKNOWN is returned
    
    switch ( biDataType )
    {
        case GUCEF::MT::DATATYPE_UINT8 :
        case GUCEF::MT::DATATYPE_INT8 :
        {
            switch ( psf )
            {
                case GUCEF::IMAGE::PSF_RGB : return Ogre::PF_BYTE_RGB;
                case GUCEF::IMAGE::PSF_RGBA : return Ogre::PF_BYTE_RGBA;
                case GUCEF::IMAGE::PSF_BGR : return Ogre::PF_BYTE_BGR;
                case GUCEF::IMAGE::PSF_BGRA : return Ogre::PF_BYTE_BGRA;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_RED : return Ogre::PF_L8;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_GREEN : return Ogre::PF_L8;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_BLUE : return Ogre::PF_L8;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_LUMINANCE : return Ogre::PF_L8;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_ALPHA : return Ogre::PF_A8;
                default : return Ogre::PF_UNKNOWN;
            }
        }
        case GUCEF::MT::DATATYPE_FLOAT32 :
        {
            switch ( psf )
            {
                case GUCEF::IMAGE::PSF_RGB : return Ogre::PF_FLOAT32_RGB;
                case GUCEF::IMAGE::PSF_RGBA : return Ogre::PF_FLOAT32_RGBA;
                default : return Ogre::PF_UNKNOWN;
            }
        }
        case GUCEF::MT::DATATYPE_UINT16 :
        case GUCEF::MT::DATATYPE_INT16 :
        {
            switch ( psf )
            {
                case GUCEF::IMAGE::PSF_RGBA : return Ogre::PF_SHORT_RGBA;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_RED : return Ogre::PF_SHORT_L;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_GREEN : return Ogre::PF_SHORT_L;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_BLUE : return Ogre::PF_SHORT_L;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_LUMINANCE : return Ogre::PF_SHORT_L;
                case GUCEF::IMAGE::PSF_SINGLE_CHANNEL_ALPHA : return Ogre::PF_SHORT_L;
                default : return Ogre::PF_UNKNOWN;
            }
        }
        
        default : return Ogre::PF_UNKNOWN;
    } 
}

/*-------------------------------------------------------------------------*/

Ogre::DataStreamPtr
COgreImageCodecAdapter::code( Ogre::MemoryDataStreamPtr& input , 
                              Ogre::Codec::CodecDataPtr& pData ) const
{GUCE_TRACE;

    return Ogre::DataStreamPtr();
}

/*-------------------------------------------------------------------------*/

void
COgreImageCodecAdapter::codeToFile( Ogre::MemoryDataStreamPtr& input ,
                                    const Ogre::String& outFileName  , 
                                    Ogre::Codec::CodecDataPtr& pData ) const
{GUCE_TRACE;

    GUCEF::CORE::CString filePath = GUCEF::CORE::RelativePath( outFileName.c_str() );
    GUCEF::CORE::CFileAccess fileAccess( filePath, "wb" );
    GUCEF::CORE::CIOAccess* fAccess = &fileAccess;
    
    if ( fileAccess.IsValid() )
    {
        Ogre::DataStreamPtr outStream = code( input, pData );
        COgreDataStreamToIOAccess output( outStream );
        fAccess->Write( output );
    }
}

/*-------------------------------------------------------------------------*/

Ogre::Codec::DecodeResult
COgreImageCodecAdapter::decode( const GUCEF::IMAGE::CImage& image )
{GUCE_TRACE;

    if ( image.GetFrameCount() > 0 )
    {
        // Ogre only supports 1 frame or 6, with 6 being a cubemap.
        UInt32 frameCount = image.GetFrameCount();
        frameCount < 6 ? frameCount = 1 : frameCount = 6;

        // Because of the way Ogre stores the pixel data we cannot support a variable number of
        // mipmaps. We will use the lowest number
        UInt32 mipMapCount = GUCECORE_UINT32MAX;
        for ( UInt32 i=0; i<frameCount; ++i )
        {
            const GUCEF::IMAGE::CImage::TFrame& frame = image.GetFrame( i );
            if ( frame.size() < mipMapCount )
            {
                mipMapCount = (UInt32) frame.size();
            }
        }        

        // Get access to the first pixel map in the image
        GUCEF::IMAGE::CImage::TPixelMapPtr pixelMap = image.GetPixelMap();

        // Obtain the pixel format ala Ogre
        GUCEF::IMAGE::TPixelStorageFormat psf = pixelMap->GetPixelStorageFormat();
        GUCEF::IMAGE::TBuildinDataType biDataType = pixelMap->GetPixelComponentDataType();
        Ogre::PixelFormat ogrePixelFormat = GUCEFPSToOgrePF( psf        ,
                                                             biDataType );
        if ( ogrePixelFormat == Ogre::PF_UNKNOWN )
        {
            // Ogre cannot handle this format, we will return a dummy
            // @TODO: call conversion routine
            Ogre::Codec::DecodeResult retValue;
            retValue.first = Ogre::MemoryDataStreamPtr();
            retValue.second = CodecDataPtr( new Ogre::ImageCodec::ImageData() );
            return retValue;
        }

        // Create the Ogre image meta-data object
        Ogre::ImageCodec::ImageData* ogreImageData = new Ogre::ImageCodec::ImageData();
        ogreImageData->format = ogrePixelFormat;
        ogreImageData->width = pixelMap->GetWidthInPixels();
        ogreImageData->height = pixelMap->GetHeightInPixels();
        ogreImageData->depth = 1;
        ogreImageData->num_mipmaps = (Ogre::ushort) mipMapCount-1;
        ogreImageData->size = pixelMap->GetTotalSizeInBytes();
        frameCount == 1 ? ogreImageData->flags = 0 : ogreImageData->flags |= Ogre::IF_CUBEMAP;
        
        // force all frames and mipmaps to the same pixel format
        // Ogre cannot handle variations within the same image definition
        for ( UInt32 i=0; i<frameCount; ++i )
        {
            const GUCEF::IMAGE::CImage::TFrame& frame = image.GetFrame( i );
            for ( UInt32 n=0; n<mipMapCount; ++n )
            {
                pixelMap = image.GetPixelMap( i, n );
                pixelMap->ConvertPixelStorageFormatTo( psf );
                pixelMap->ConvertPixelComponentDataTypeTo( biDataType );
            }
        }

        // Ogre stores the pixel data such that we need to pass all frames at the same mipmap level
        // first before moving to the next mipmap level
        Ogre::MemoryDataStreamPtr output;
        output.bind( new Ogre::MemoryDataStream( image.GetTotalPixelStorageSize() ) );
        UInt32 offset = 0;
        for ( UInt32 i=0; i<mipMapCount; ++i )
        {
            for ( UInt32 n=0; n<frameCount; ++n )
            {
                // Get access to the pixel map
                GUCEF::IMAGE::CImage::TPixelMapPtr pixelMap = image.GetPixelMap( n, i );
                memcpy( ( (UInt8*) output->getPtr() ) + offset ,
                        pixelMap->GetDataPtr()                 ,
                        pixelMap->GetTotalSizeInBytes()        );
            }
        }
        
        // Decode succeeded
        Ogre::Codec::DecodeResult retValue;
        retValue.first = output;
        retValue.second = CodecDataPtr( ogreImageData );
        return retValue;            
    }
    
    // Decode failed
    OGRE_EXCEPT( Ogre::Exception::ERR_INTERNAL_ERROR          , 
				 "Error decoding image"                       , 
				 "GUCE::CORE::COgreImageCodecAdapter::decode" );    
}

/*-------------------------------------------------------------------------*/

Ogre::Codec::DecodeResult
COgreImageCodecAdapter::decode( Ogre::DataStreamPtr& input ) const
{GUCE_TRACE;

    if ( !input.isNull() )
    {
        // We prepare some vars for the decoding process
        COgreDataStreamToIOAccess inputAccess( input );
        inputAccess.Setpos( 0 );
            
        // Decode the input using the image codec utility
        GUCEF::IMAGE::CImage image;
        GUCEF::IMAGE::CIMGCodec imageUtil( m_gucefCodecPtr );
        if ( imageUtil.Decode( inputAccess ,
                               image       ) )
        {
            return decode( image );
        }
    }

    // Decode failed
    OGRE_EXCEPT( Ogre::Exception::ERR_INTERNAL_ERROR          , 
				 "Error decoding image"                       , 
				 "GUCE::CORE::COgreImageCodecAdapter::decode" );
}

/*-------------------------------------------------------------------------*/

Ogre::String
COgreImageCodecAdapter::getType() const
{GUCE_TRACE;

    return m_gucefCodecPtr->GetType().C_String();
}

/*-------------------------------------------------------------------------*/

COgreImageCodecAdapter::CGUCEFCodecPtr
COgreImageCodecAdapter::GetCodecPtr( void )
{GUCE_TRACE;

    return m_gucefCodecPtr;
}

/*-------------------------------------------------------------------------*/

Ogre::String
COgreImageCodecAdapter::magicNumberToFileExt( const char *magicNumberPtr , 
                                              size_t maxbytes            ) const
{GUCE_TRACE;

    // We not support header reading atm
    return Ogre::String();
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/