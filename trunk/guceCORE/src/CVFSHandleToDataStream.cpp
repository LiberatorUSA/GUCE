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

#ifndef GUCEF_VFS_CVFSHANDLE_H
#include "gucefVFS_CVFSHandle.h"               /* vfs file handle */
#define GUCEF_VFS_CVFSHANDLE_H
#endif /* GUCEF_VFS_CVFSHANDLE_H ? */

#ifndef GUCEF_VFS_CVFS_H
#include "gucefVFS_CVFS.h"
#define GUCEF_VFS_CVFS_H
#endif /* GUCEF_VFS_CVFS_H ? */

#ifndef GUCE_CORE_MACROS_H
#include "guceCORE_macros.h"          /* guceCORE build config and macros */
#define GUCE_CORE_MACROS_H
#endif /* GUCE_CORE_MACROS_H ? */

#include "CVFSHandleToDataStream.h"   /* definition of the class implemented here */

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

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/
