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
 
#ifndef GUCE_CORE_CIOACCESSARCHIVE_H
#define GUCE_CORE_CIOACCESSARCHIVE_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/ 

#ifndef _Archive_H__
#include "OgreArchive.h"         /* Ogre base class for archives */
#define _Archive_H__
#endif /* _Archive_H__ ? */

#ifndef GUCEF_CORE_CIOACCESS_H
#include "CIOAccess.h"
#define GUCEF_CORE_CIOACCESS_H
#endif /* GUCEF_CORE_CIOACCESS_H ? */

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

class GUCE_CORE_EXPORT_CPP CIOAccessArchive : public Ogre::Archive
{
    public:
    
    CIOAccessArchive( const Ogre::String& name     , 
                      const Ogre::String& archtype );
                      
    virtual ~CIOAccessArchive();
    
    bool AddResource( GUCEF::CORE::CIOAccess& resource ,
                      const CString& filename          );

    bool RemoveResource( GUCEF::CORE::CIOAccess& resource );
    
    bool RemoveResource( const CString& filename );

    void ClearResourceList( void );

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
	
	private:
	typedef std::map< CString, GUCEF::CORE::CIOAccess* > TResourceMap;
	
    TResourceMap m_resourceMap;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE ? */
}; /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CIOACCESSARCHIVE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 12-11-2004 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
