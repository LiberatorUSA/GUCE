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

/*
 *      This is the main include header for the guceCORE library.
 *      It is part of a framework called GUCE.
 *      All classes in this library have to do core framework functionality
 *      and many of the other modules will have a dependancy on this module.
 *      It houses the generic toolkits.
 */

#ifndef GUCECORE_H
#define GUCECORE_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Library build configuration      
 */
#ifndef GUCECORE_CONFIG_H
#include "guceCORE_config.h"
#define GUCECORE_CONFIG_H
#endif /* GUCECORE_CONFIG_H ? */

/*
 *      Library specific macros and generic macros
 */
#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

/*---------------------------------------------------------------------------/

        C++ includes

/---------------------------------------------------------------------------*/
#ifdef __cplusplus

/*
 *      Singleton application class.
 *      Basicly binds the different sub-systems together and provides
 *      additional init and shutdown code.
 */
#ifndef CGUCEAPPLICATION_H
#include "CGUCEApplication.h"
#define CGUCEAPPLICATION_H
#endif /* CGUCEAPPLICATION_H ? */

/*
 *      Adapter class that allows Ogre to use the
 *      CIOAccess class and derived implementations as a DataStream.
 */
#ifndef CIOACCESSTODATASTREAM_H
#include "CIOAccessToDataStream.h"
#define CIOACCESSTODATASTREAM_H
#endif /* CIOACCESSTODATASTREAM_H ? */

/*
 *      Adapter class that allows Ogre to use the
 *      CVFSHandle class as a DataStream.
 */
#ifndef CVFSHANDLETODATASTREAM_H
#include "CVFSHandleToDataStream.h"
#define CVFSHANDLETODATASTREAM_H
#endif /* CVFSHANDLETODATASTREAM_H ? */

/*
 *      Adapter class that allows Ogre to use image codecs
 *      provided by gucefIMAGE
 */
#ifndef GUCE_CORE_COGREIMAGECODECADAPTER_H
#include "COgreImageCodecAdapter.h"
#define GUCE_CORE_COGREIMAGECODECADAPTER_H
#endif /* GUCE_CORE_COGREIMAGECODECADAPTER_H ? */

/*
 *      Class that will allow you to pass a local recource as an
 *      Ogre recource. This will allow Ogre to use recources it should
 *      not delete as a recource uppon destruction of the last recource pointer.
 */
#ifndef CSTATICRESOURCEPTR_H
#include "CStaticResourcePtr.h"
#define CSTATICRESOURCEPTR_H
#endif /* CSTATICRESOURCEPTR_H ? */

/*
 *      Class that will allow you to pass a local recource as an
 *      Ogre DataStream. This will allow Ogre to use recources it should
 *      not delete as a recource uppon destruction of the last recource pointer.
 */
#ifndef CSTATICDATASTREAMEPTR_H
#include "CStaticDataStreamPtr.h"
#define CSTATICDATASTREAMEPTR_H
#endif /* CSTATICDATASTREAMEPTR_H ? */

#ifndef CWINDOWCONTEXT_H
#include "CWindowContext.h"
#define CWINDOWCONTEXT_H
#endif /* CWINDOWCONTEXT_H ? */

#ifndef CWINDOWMANAGER_H
#include "CWindowManager.h"
#define CWINDOWMANAGER_H
#endif /* CWINDOWMANAGER_H ? */

#ifndef MISCUTILS_H
#include "miscutils.h"
#define MISCUTILS_H
#endif /* MISCUTILS_H ? */

#endif /* __cplusplus ? */
/*--------------------------------------------------------------------------*/

#endif /* GUCECORE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 05-05-2005 :
       - Added CStaticResourcePtr
       - Added CStaticDataStreamPtr
- 02-04-2005 :
       - Added CIOAccessToDataStream
       - Added CVFSHandleToDataStream
- 31-12-2004 :
       - Made the initial version of the library header. 

-----------------------------------------------------------------------------*/


 
