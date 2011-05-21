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
 
#ifndef CGUCEFVFSARCHIVEFACTORY_H
#define CGUCEFVFSARCHIVEFACTORY_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#ifndef _ArchiveFactory_H__
#include "OgreArchiveFactory.h"   /* Ogre base class for archive factories */
#define _ArchiveFactory_H__
#endif /* _ArchiveFactory_H__ ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

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

class GUCE_CORE_EXPORT_CPP CGUCEFVFSArchiveFactory : public Ogre::ArchiveFactory
{
        public:                        
        
        virtual const Ogre::String& getType( void ) const;

        virtual Ogre::Archive* createInstance( const Ogre::String& name );    

        virtual void destroyInstance( Ogre::Archive* archive );
        
        private:
        friend class CGUCEApplication;
        
        static void Instance( void );
        static void Deinstance( void );       
        
        private:
        
        CGUCEFVFSArchiveFactory( void );        
        virtual ~CGUCEFVFSArchiveFactory();        
        CGUCEFVFSArchiveFactory( const CGUCEFVFSArchiveFactory& src );
        CGUCEFVFSArchiveFactory& operator=( const CGUCEFVFSArchiveFactory& src );
        
        static CGUCEFVFSArchiveFactory* _instance;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/

#endif /* CGUCEFVFSARCHIVEFACTORY_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-04-2005 :
       - Initial version of this file.

-----------------------------------------------------------------------------*/
