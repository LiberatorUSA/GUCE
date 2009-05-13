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
 
#ifndef GUCE_CORE_CIOACCESSARCHIVEFACTORY_H
#define GUCE_CORE_CIOACCESSARCHIVEFACTORY_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _ArchiveFactory_H__
#include "OgreArchiveFactory.h"   /* Ogre base class for archive factories */
#define _ArchiveFactory_H__
#endif /* _ArchiveFactory_H__ ? */

#ifndef GUCE_CORE_CIOACCESSARCHIVE_H
#include "CIOAccessArchive.h"        /* Ogre archive to CIOAccess adapter */
#define GUCE_CORE_CIOACCESSARCHIVE_H
#endif /* GUCE_CORE_CIOACCESSARCHIVE_H ? */

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

class GUCE_CORE_EXPORT_CPP CIOAccessArchiveFactory : public Ogre::ArchiveFactory
{
    public:                        
    
    typedef std::map< CString, CIOAccessArchive* > TArchiveMap;
    
    virtual const Ogre::String& getType( void ) const;

    virtual Ogre::Archive* createInstance( const Ogre::String& name );    

    virtual void destroyInstance( Ogre::Archive* archive );

    TArchiveMap& GetArchiveMap( void );
    
    static CIOAccessArchiveFactory* Instance( void );

    private:
    friend class CGUCEApplication;

    static void Deinstance( void );       
    
    private:
    
    CIOAccessArchiveFactory( void );        
    virtual ~CIOAccessArchiveFactory();        
    CIOAccessArchiveFactory( const CIOAccessArchiveFactory& src );
    CIOAccessArchiveFactory& operator=( const CIOAccessArchiveFactory& src );

    private:
    
    TArchiveMap m_archiveMap;
    
    static CIOAccessArchiveFactory* g_instance;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CORE_CIOACCESSARCHIVEFACTORY_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
