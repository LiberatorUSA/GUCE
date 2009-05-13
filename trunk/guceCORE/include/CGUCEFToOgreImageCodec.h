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
 */

#ifndef CGUCFTOOGREIMAGECODEC_H
#define CGUCFTOOGREIMAGECODEC_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#undef PI
#ifndef _ImageCodec_H__
#include "OgreImageCodec.h"     /* Ogre base class for all Image codec implementations */
#define _ImageCodec_H__
#endif /* _ImageCodec_H__ ? */

#include "OgreNoMemoryMacros.h" /* Don't use the Ogre memory manager */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"    /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#ifndef CDVSTRING_H
#include "CDVString.h"
#define CDVSTRING_H
#endif /* CDVSTRING_H ? */ 

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/
            
/**
 *      Basicly an adapter class that allows Ogre to use the gucefIMAGE
 *      library as if it where an Ogre image Codec.    
 */
class EXPORT_CPP CGUCEFToOgreImageCodec : public Ogre::ImageCodec
{        
        public:
        typedef Ogre::Codec::CodecDataPtr TIMGInfoPtr;
        typedef Ogre::Codec::DecodeResult TIMGData;
        
        CGUCEFToOgreImageCodec( UInt32 codecindex                ,
                                UInt32 handlerindex              ,
                                const GUCEF::CORE::CString& fext ,
                                bool load_capability             ,
                                bool save_capability             );
        
        virtual ~CGUCEFToOgreImageCodec();
        
        /**
         *      
         */     
        virtual Ogre::DataStreamPtr 
        code( Ogre::MemoryDataStreamPtr& input , 
              TIMGInfoPtr& pinfo               ) const; 
                  
        /**
         *      
         */               
        virtual TIMGData 
        decode( Ogre::DataStreamPtr& input ) const;
                
        /** 
         *      Encodes image data to a file.
         *
         *      @param input memory chunk containing data to write to file
         *      @param outfilename Filename to output to (extension implies type)
         *      @param pdata ImageData pointer
         */
        virtual void 
        codeToFile( Ogre::MemoryDataStreamPtr& input , 
                    const Ogre::String& outfilename  , 
                    TIMGInfoPtr& pinfo               ) const;
                    
        /**
         *      Returns the type name of the codec as a string
         *
         *      @return the named codec type
         */
        virtual Ogre::String getType( void ) const; 
        
        UInt32 GetGUCEFCodecIndex( void ) const;
        
        UInt32 GetGUCEFHandlerIndex( void ) const;
        
        private:
        CGUCEFToOgreImageCodec( void );                                          /**< dummy, can't use default constructor */ 
        CGUCEFToOgreImageCodec( const CGUCEFToOgreImageCodec& src );             /**< copying doesnt make sense */
        CGUCEFToOgreImageCodec& operator=( const CGUCEFToOgreImageCodec& src );  /**< copying doesnt make sense */     
        
        private:
        bool _load_capability;
        bool _save_capability;          
        UInt32 _codecindex;
        UInt32 _handlerindex;
        Ogre::String _fileext;
};
      
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* CGUCFTOOGREIMAGECODEC_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 31-12-2004 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/