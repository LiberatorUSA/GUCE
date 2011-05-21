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
 
#ifndef GUCE_CORE_CVFSHANDLETODATASTREAM_H
#define GUCE_CORE_CVFSHANDLETODATASTREAM_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/ 

#ifndef GUCE_CORE_CIOACCESSTODATASTREAM_H
#include "CIOAccessToDataStream.h"      /* CIOAccess to an Ogre DataStream adapter */
#define GUCE_CORE_CIOACCESSTODATASTREAM_H
#endif /* GUCE_CORE_CIOACCESSTODATASTREAM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF { namespace VFS { class CVFSHandle; } }

/*-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *      Allows Ogre to use gucefVFS handles.
 *      The handled resource will be unloaded when the stream object is destroyed.
 */
class GUCE_CORE_EXPORT_CPP CVFSHandleToDataStream : public CIOAccessToDataStream
{
        public:
        
        typedef GUCEF::VFS::CVFS::CVFSHandlePtr CVFSHandlePtr;
        
        /**
         *      Constructs an Ogre DataStream capable of using an
         *      gucefVFS handle as input.            
         */
        CVFSHandleToDataStream( CVFSHandlePtr& vfshandle  ,
                                bool freeonclose = false  );
        
        CVFSHandleToDataStream( const CVFSHandleToDataStream& src );
        
        /**
         *      Unloads the resource pointed to by the file handle 
         *      given upon construction.
         */
        virtual ~CVFSHandleToDataStream();
        
        virtual void close( void );       
        
        private:        
        CVFSHandlePtr m_fh; 
        bool m_freeonclose;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE ? */
} /* namespace GUCE ? */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_CORE_CVFSHANDLETODATASTREAM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 12-02-2005 :
        - Initial implementation

-----------------------------------------------------------------------------*/
