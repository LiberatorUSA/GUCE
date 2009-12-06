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

#include "gucef_new_off.h"      /* don't scare Ogre with our memory manager */

#ifndef _ArchiveManager_H__
#include "ogrearchivemanager.h"      /* Ogre archive factory manager */
#define _ArchiveManager_H__
#endif /* _ArchiveManager_H__ ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"         /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#ifndef CGUCEFVFSARCHIVE_H
#include "CGUCEFVFSArchive.h"        /* Ogre archive to gucefVFS adapter */
#define CGUCEFVFSARCHIVE_H
#endif /* CGUCEFVFSARCHIVE_H ? */

#include "CGUCEFVFSArchiveFactory.h" /* definition of the class implemented here */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUCEFVFSArchiveFactory* CGUCEFVFSArchiveFactory::_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUCEFVFSArchiveFactory::CGUCEFVFSArchiveFactory( void )
{
        Ogre::ArchiveManager::getSingleton().addArchiveFactory( this );                
}

/*-------------------------------------------------------------------------*/

CGUCEFVFSArchiveFactory::CGUCEFVFSArchiveFactory( const CGUCEFVFSArchiveFactory& src )
{

}

/*-------------------------------------------------------------------------*/

CGUCEFVFSArchiveFactory::~CGUCEFVFSArchiveFactory()
{

}

/*-------------------------------------------------------------------------*/

void 
CGUCEFVFSArchiveFactory::Instance( void )
{
        
        if ( !_instance )
        {
                _instance = new CGUCEFVFSArchiveFactory();
        }
}

/*-------------------------------------------------------------------------*/

void 
CGUCEFVFSArchiveFactory::Deinstance( void )
{
        
        delete _instance;
}

/*-------------------------------------------------------------------------*/

CGUCEFVFSArchiveFactory&
CGUCEFVFSArchiveFactory::operator=( const CGUCEFVFSArchiveFactory& src )
{
        
        return *this;
}

/*-------------------------------------------------------------------------*/

const Ogre::String& 
CGUCEFVFSArchiveFactory::getType( void ) const
{
        
        static Ogre::String aftype = "gucefVFS";
        return aftype; 
}

/*-------------------------------------------------------------------------*/

Ogre::Archive* 
CGUCEFVFSArchiveFactory::createInstance( const Ogre::String& name )
{
        
        return new CGUCEFVFSArchive( name      , 
                                     getType() );
}

/*-------------------------------------------------------------------------*/

void 
CGUCEFVFSArchiveFactory::destroyInstance( Ogre::Archive* archive )
{
        
        delete archive;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
