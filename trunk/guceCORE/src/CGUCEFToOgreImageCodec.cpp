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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEFIMAGE_H
#include "gucefIMAGE.h"         /* gucefIMAGE library API */
#define GUCEIMAGE_H
#endif /* GUCEIMAGE_H ? */
#undef PI

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#ifndef __Exception_H_
#include "OgreException.h"      /* Ogre Exception class */
#define __Exception_H_
#endif /* __Exception_H_ ? */

#include "OgreNoMemoryMacros.h" /* Don't use the Ogre memory manager */

#ifndef GUCEF_CORE_DVFILEUTILS_H
#include "dvfileutils.h"
#define GUCEF_CORE_DVFILEUTILS_H
#endif /* GUCEF_CORE_DVFILEUTILS_H ? */

#ifndef GUCEF_CORE_DVSTRUTILS_H
#include "dvstrutils.h"
#define GUCEF_CORE_DVSTRUTILS_H
#endif /* GUCEF_CORE_DVSTRUTILS_H ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"    /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#include "CGUCEFToOgreImageCodec.h"    /* definition of the class implemented here */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUCEFToOgreImageCodec::CGUCEFToOgreImageCodec( void )
{
        /* dummy implementation, should never be used */
}

/*-------------------------------------------------------------------------*/

CGUCEFToOgreImageCodec::CGUCEFToOgreImageCodec( UInt32 codecindex                ,
                                                UInt32 handlerindex              ,
                                                const GUCEF::CORE::CString& fext ,
                                                bool load_capability             ,
                                                bool save_capability             )
        : _codecindex( codecindex )                                    ,
          _handlerindex( handlerindex  )                               , 
          _fileext( GUCEF::CORE::Extract_File_Ext( fext.C_String() ) ) ,
          _load_capability( load_capability )                          ,
          _save_capability( save_capability )                                          
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::CGUCEFToOgreImageCodec( UInt32 codecindex, UInt32 handlerindex, const GUCEF::CORE::CString& fext, bool load_capability, bool save_capability )" );
        
       // registerCodec( this );        
}

/*-------------------------------------------------------------------------*/

CGUCEFToOgreImageCodec::CGUCEFToOgreImageCodec( const CGUCEFToOgreImageCodec& src )
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::CGUCEFToOgreImageCodec( const CGUCEFToOgreImageCodec& src )" );
        
        /* dummy implementation, should never be used */
}   

/*-------------------------------------------------------------------------*/

CGUCEFToOgreImageCodec::~CGUCEFToOgreImageCodec()
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::~CGUCEFToOgreImageCodec()" );
        
       // unRegisterCodec( this );
}  

/*-------------------------------------------------------------------------*/
        
CGUCEFToOgreImageCodec& 
CGUCEFToOgreImageCodec::operator=( const CGUCEFToOgreImageCodec& src )
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::operator=( const CGUCEFToOgreImageCodec& src )" );
        
        /* dummy implementation, should never be used */
        return *this;
}

/*-------------------------------------------------------------------------*/

Ogre::DataStreamPtr 
CGUCEFToOgreImageCodec::code( Ogre::MemoryDataStreamPtr& input , 
                              TIMGInfoPtr& pinfo               ) const
{                              
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::code( Ogre::MemoryDataStreamPtr& input , Ogre::CodecDataPtr& pdata ) const" );
        
        OgreGuard( "CGUCEFToOgreImageCodec::code" );

/*
        Except( Ogre::Exception::UNIMPLEMENTED_FEATURE  , 
                "encoding to memory is not implemented" ,
                "CGUCEFToOgreImageCodec::code"          ); */

        OgreUnguard();
        Ogre::DataStreamPtr nullptr;
        return nullptr;
} 

/*-------------------------------------------------------------------------*/ 

void
CGUCEFToOgreImageCodec::codeToFile( Ogre::MemoryDataStreamPtr& input , 
                                    const Ogre::String& outfilename  , 
                                    TIMGInfoPtr& pinfo               ) const
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::codeToFile( Ogre::MemoryDataStreamPtr& input , const Ogre::String& outfilename, Ogre::CodecDataPtr& pdata ) const" );
        
        GUCEF::IMAGE::TImageData imgdata;
                
        GUCEF::IMAGE::CIMGCodecManager::Instance()->SaveImageData( _codecindex         ,
                                                                   _handlerindex       ,
                                                                   outfilename.c_str() ,
                                                                   0                   ,
                                                                   75                  ,
                                                                   &imgdata            );
} 

/*-------------------------------------------------------------------------*/

CGUCEFToOgreImageCodec::TIMGData 
CGUCEFToOgreImageCodec::decode( Ogre::DataStreamPtr& input ) const
{ 
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::decode( Ogre::DataStreamPtr& input ) const" );
        
        Ogre::Codec::CodecDataPtr cd( new Ogre::ImageCodec::ImageData );
        Ogre::MemoryDataStreamPtr mds( new Ogre::MemoryDataStream( NULL, 0, false ) );
        TIMGData data( mds, cd );
        return data; 
}

/*-------------------------------------------------------------------------*/

/**
 *      Returns the type name of the codec as a string
 *
 *      @return the named codec type
 */
Ogre::String 
CGUCEFToOgreImageCodec::getType( void ) const
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::getType( void ) const" );
        
        return _fileext;
}

/*-------------------------------------------------------------------------*/

UInt32 
CGUCEFToOgreImageCodec::GetGUCEFCodecIndex( void ) const
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::GetGUCEFCodecIndex( void ) const" );
        
        return _codecindex;
}

/*-------------------------------------------------------------------------*/
        
UInt32 
CGUCEFToOgreImageCodec::GetGUCEFHandlerIndex( void ) const
{
        DEBUGOUTPUT( "CGUCEFToOgreImageCodec::GetGUCEFHandlerIndex( void ) const" );
        
        return _handlerindex;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END   
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
