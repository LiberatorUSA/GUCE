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

#ifndef CIWINDOWCONTEXTHANDLER_H
#define CIWINDOWCONTEXTHANDLER_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef CWINDOWCONTEXT_H
#include "CWindowContext.h"
#define CWINDOWCONTEXT_H
#endif /* CWINDOWCONTEXT_H ? */

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

class CWindowManager;
class CWindowManagerAccessProxy;

/*-------------------------------------------------------------------------*/

class GUCE_CORE_EXPORT_CPP CIWindowContextHandler
{
        protected:
        friend class CWindowManager;
        friend class CWindowManagerAccessProxy;
        
        virtual void OnWindowContextCreate( CWindowContext* context ) = 0;        
        
        virtual void OnWindowContextDestroy( CWindowContext* context ) = 0;
        
        virtual void OnWindowContextSize( CWindowContext* context ,
                                          const UInt32 width      ,
                                          const UInt32 height     ) = 0;
        
        virtual void OnWindowContextActivate( CWindowContext* context ,
                                              const bool isactive     ) = 0;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/

#endif /* CIWINDOWCONTEXTHANDLER_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-10-2005 :
        - Initial version

-----------------------------------------------------------------------------*/
