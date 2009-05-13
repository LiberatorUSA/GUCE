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

#ifndef CVFSHANDLE_H
#include "CVFSHandle.h"               /* vfs file handle */
#define CVFSHANDLE_H
#endif /* CVFSHANDLE_H ? */

#ifndef CVFS_H
#include "CVFS.h"                     /* singleton vfs access */
#define CVFS_H
#endif /* CVFS_H ? */

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"          /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

#include "CVFSHandleToDataStream.h"   /* definition of the class implemented here */

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

CVFSHandleToDataStream::CVFSHandleToDataStream( CVFSHandlePtr& vfshandle       ,
                                                bool freeonclose /* = false */ )
        : CIOAccessToDataStream( vfshandle->GetAccess() ) ,
          m_fh( vfshandle )                               ,
          m_freeonclose( freeonclose )
          
{GUCE_TRACE;

        mName = vfshandle->GetFilename().C_String();
}

/*-------------------------------------------------------------------------*/

CVFSHandleToDataStream::~CVFSHandleToDataStream()
{GUCE_TRACE;

    close();
    
    // Important: we must disable access because the resource may no longer
    // be available due to unloading as a result of the file handle being released
    // at this class level
    SetAccess( NULL );
}

/*-------------------------------------------------------------------------*/

void 
CVFSHandleToDataStream::close( void )
{GUCE_TRACE;

    CIOAccessToDataStream::close();
    
    if ( m_freeonclose )
    {
        m_fh = NULL;
        
        // Important: we must disable access because the resource may no longer
        // be available due to unloading as a result of the file handle being released
        // at this class level
        SetAccess( NULL );                                          
    }                
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCEF_NAMESPACE_END

/*-------------------------------------------------------------------------*/
