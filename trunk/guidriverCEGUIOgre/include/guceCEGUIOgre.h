/*
 *  guceCEGUIOgre: glue module for the CEGUI+Ogre GUI backend
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 */

/*
 *      This is the main include header for the guceCEGUIOgre library.
 *      It is an optional part of an engine called GUCE.
 *      All classes in this library have to do with providing a GUI backend
 *      based on CEGUI with Ogre doing the rendering.
 */

#ifndef GUCE_CEGUIOGRE_H
#define GUCE_CEGUIOGRE_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Library build configuration      
 */
#ifndef GUCE_CEGUIOGRE_CONFIG_H
#include "guceCEGUIOgre_config.h"
#define GUCE_CEGUIOGRE_CONFIG_H
#endif /* GUCE_CEGUIOGRE_CONFIG_H ? */

/*
 *      Library specific macros and generic macros
 */
#ifndef GUCE_CEGUIOGRE_MACROS_H
#include "guceCEGUIOgre_macros.h"
#define GUCE_CEGUIOGRE_MACROS_H
#endif /* GUCE_CEGUIOGRE_MACROS_H ? */

/*
 *      Simple types
 */
#ifndef GUCE_CEGUIOGRE_ETYPES_H
#include "guceCEGUIOgre_ETypes.h"
#define GUCE_CEGUIOGRE_ETYPES_H
#endif /* GUCE_CEGUIOGRE_ETYPES_H ? */

/*---------------------------------------------------------------------------/

        C++ includes

/---------------------------------------------------------------------------*/
#ifdef __cplusplus

#ifndef GUCE_CEGUIOGRE_CFORMBACKENDIMP_H
#include "guceCEGUIOgre_CFormBackendImp.h"
#define GUCE_CEGUIOGRE_CFORMBACKENDIMP_H
#endif /* GUCE_CEGUIOGRE_CFORMBACKENDIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CWIDGETIMP_H
#include "guceCEGUIOgre_CWidgetImp.h"
#define GUCE_CEGUIOGRE_CWIDGETIMP_H
#endif /* GUCE_CEGUIOGRE_CWIDGETIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CBUTTONIMP_H
#include "guceCEGUIOgre_CButtonImp.h"
#define GUCE_CEGUIOGRE_CBUTTONIMP_H
#endif /* GUCE_CEGUIOGRE_CBUTTONIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CPUSHBUTTONIMP_H
#include "guceCEGUIOgre_CPushButtonImp.h"
#define GUCE_CEGUIOGRE_CPUSHBUTTONIMP_H
#endif /* GUCE_CEGUIOGRE_CPUSHBUTTONIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CEDITBOXIMP_H
#include "guceCEGUIOgre_CEditboxImp.h"
#define GUCE_CEGUIOGRE_CEDITBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CEDITBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CLISTBOXIMP_H
#include "guceCEGUIOgre_CListboxImp.h"
#define GUCE_CEGUIOGRE_CLISTBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CLISTBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CWINDOWIMP_H
#include "guceCEGUIOgre_CWindowImp.h"
#define GUCE_CEGUIOGRE_CWINDOWIMP_H
#endif /* GUCE_CEGUIOGRE_CWINDOWIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CIMAGEFRAMEIMP_H
#include "guceCEGUIOgre_CImageFrameImp.h"
#define GUCE_CEGUIOGRE_CIMAGEFRAMEIMP_H
#endif /* GUCE_CEGUIOGRE_CIMAGEFRAMEIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CHECKBOXIMP_H
#include "guceCEGUIOgre_CCheckboxImp.h"
#define GUCE_CEGUIOGRE_CHECKBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CHECKBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CLABELIMP_H
#include "guceCEGUIOgre_CLabelImp.h"
#define GUCE_CEGUIOGRE_CLABELIMP_H
#endif /* GUCE_CEGUIOGRE_CLABELIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CCOMBOBOXIMP_H
#include "guceCEGUIOgre_CComboboxImp.h"
#define GUCE_CEGUIOGRE_CCOMBOBOXIMP_H
#endif /* GUCE_CEGUIOGRE_CCOMBOBOXIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CTABCONTROLIMP_H
#include "guceCEGUIOgre_CTabControlImp.h"
#define GUCE_CEGUIOGRE_CTABCONTROLIMP_H
#endif /* GUCE_CEGUIOGRE_CTABCONTROLIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CTABCONTENTPANEIMP_H
#include "guceCEGUIOgre_CTabContentPaneImp.h"
#define GUCE_CEGUIOGRE_CTABCONTENTPANEIMP_H
#endif /* GUCE_CEGUIOGRE_CTABCONTENTPANEIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CSPINNERIMP_H
#include "guceCEGUIOgre_CSpinnerImp.h"
#define GUCE_CEGUIOGRE_CSPINNERIMP_H
#endif /* GUCE_CEGUIOGRE_CSPINNERIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CGRIDVIEWIMP_H
#include "guceCEGUIOgre_CGridViewImp.h"
#define GUCE_CEGUIOGRE_CGRIDVIEWIMP_H
#endif /* GUCE_CEGUIOGRE_CGRIDVIEWIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CFILEOPENDIALOGIMP_H
#include "guceCEGUIOgre_CFileOpenDialogImp.h"
#define GUCE_CEGUIOGRE_CFILEOPENDIALOGIMP_H
#endif /* GUCE_CEGUIOGRE_CFILEOPENDIALOGIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CFILESAVEDIALOGIMP_H
#include "guceCEGUIOgre_CFileSaveDialogImp.h"
#define GUCE_CEGUIOGRE_CFILESAVEDIALOGIMP_H
#endif /* GUCE_CEGUIOGRE_CFILESAVEDIALOGIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CFILESYSTEMDIALOGIMP_H
#include "guceCEGUIOgre_CFileSystemDialogImp.h"
#define GUCE_CEGUIOGRE_CFILESYSTEMDIALOGIMP_H
#endif /* GUCE_CEGUIOGRE_CFILESYSTEMDIALOGIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CRENDERCONTEXTIMP_H
#include "guceCEGUIOgre_CRenderContextImp.h"
#define GUCE_CEGUIOGRE_CRENDERCONTEXTIMP_H
#endif /* GUCE_CEGUIOGRE_CRENDERCONTEXTIMP_H ? */

#ifndef GUCE_CEGUIOGRE_CGUIDRIVER_H
#include "guceCEGUIOgre_CGUIDriver.h"
#define GUCE_CEGUIOGRE_CGUIDRIVER_H
#endif /* GUCE_CEGUIOGRE_CGUIDRIVER_H ? */

#endif /* __cplusplus ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_CEGUIOGRE_EXPORT_C const char* GUCE_CEGUIOGRE_ModuleCompileTimeStamp( void );

/*--------------------------------------------------------------------------*/

#endif /* GUCE_CEGUIOGRE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 21-04-2007 :
       - Made the initial version of the library header.

-----------------------------------------------------------------------------*/
