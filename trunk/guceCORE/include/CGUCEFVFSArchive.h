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
 
#ifndef CGUCEFVFSARCHIVE_H
#define CGUCEFVFSARCHIVE_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#ifndef _Archive_H__
#include "OgreArchive.h"        /* Ogre base class for archives */
#define _Archive_H__
#endif /* _Archive_H__ ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF { namespace VFS { class CVFS; } }

/*-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP CGUCEFVFSArchive : public Ogre::Archive
{
    public:

    CGUCEFVFSArchive( const Ogre::String& name     , 
                      const Ogre::String& archtype );
                      
    virtual ~CGUCEFVFSArchive();                          

    virtual bool isCaseSensitive( void ) const;

    virtual void load( void );

    virtual void unload( void );

    virtual Ogre::DataStreamPtr open( const Ogre::String& filename ) const;

    virtual Ogre::StringVectorPtr list( bool recursive = true, bool dirs = false );

    virtual Ogre::FileInfoListPtr listFileInfo( bool recursive = true ,
                                                bool dirs = false     );

    virtual Ogre::StringVectorPtr find( const Ogre::String& pattern , 
                                        bool recursive = true       ,
                                        bool dirs = false           );

    virtual Ogre::FileInfoListPtr findFileInfo( const Ogre::String& pattern , 
                                                bool recursive = true       ,
                                                bool dirs = false           );

	virtual bool exists( const Ogre::String& filename );
	
	virtual time_t getModifiedTime( const Ogre::String& filename );
	
	private:
	
    CGUCEFVFSArchive( void );
    CGUCEFVFSArchive( const CGUCEFVFSArchive& src );                        
    CGUCEFVFSArchive& operator=( const CGUCEFVFSArchive& src );	
	
	GUCEF::VFS::CVFS* _vfs;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* CGUCEFVFSARCHIVE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
