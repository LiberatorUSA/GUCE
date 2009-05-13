/*
 *  guceGUI: GUCE module providing GUI functionality
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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
 *  This is the main include header for the guceGUI library.
 *  It is part of an engine called GUCE.
 *  All classes in this library have to do with graphical user interfaces
 */

#ifndef GUCE_GUI_H
#define GUCE_GUI_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Library specific macros and generic macros
 */
#ifndef GUCE_GUI_MACROS_H
#include "guceGUI_macros.h"
#define GUCE_GUI_MACROS_H
#endif /* GUCE_GUI_MACROS_H ? */

/*---------------------------------------------------------------------------/

        C++ includes

/---------------------------------------------------------------------------*/
#ifdef __cplusplus

#ifndef GUCE_GUI_CGUIMANAGER_H
#include "CGUIManager.h"
#define GUCE_GUI_CGUIMANAGER_H
#endif /* GUCE_GUI_CGUIMANAGER_H ? */

#ifndef GUCE_GUI_CCONSOLE_H
#include "guceGUI_CConsole.h"
#define GUCE_GUI_CCONSOLE_H
#endif /* GUCE_GUI_CCONSOLE_H ? */

#ifndef GUCE_GUI_CCONSOLEFORM_H
#include "guceGUI_CConsoleForm.h"
#define GUCE_GUI_CCONSOLEFORM_H
#endif /* GUCE_GUI_CCONSOLEFORM_H ? */

#ifndef GUCE_GUI_CMESHVIEWER_H
#include "guceGUI_CMeshViewer.h"
#define GUCE_GUI_CMESHVIEWER_H
#endif /* GUCE_GUI_CMESHVIEWER_H ? */

#ifndef GUCE_GUI_CMESHVIEWERFORM_H
#include "guceGUI_CMeshViewerForm.h"
#define GUCE_GUI_CMESHVIEWERFORM_H
#endif /* GUCE_GUI_CMESHVIEWERFORM_H ? */

#ifndef GUCE_GUI_COGREGUIRENDERCONTEXT_H
#include "guceGUI_COgreGUIRenderContext.h"
#define GUCE_GUI_COGREGUIRENDERCONTEXT_H
#endif /* GUCE_GUI_COGREGUIRENDERCONTEXT_H ? */

#ifndef GUCE_GUI_CSETTINGSMENUFORM_H
#include "guceGUI_CSettingsMenuForm.h"
#define GUCE_GUI_CSETTINGSMENUFORM_H
#endif /* GUCE_GUI_CSETTINGSMENUFORM_H ? */

#ifndef GUCE_GUI_CVIDEOSETTINGSMENUFORM_H
#include "guceGUI_CVideoSettingsForm.h"
#define GUCE_GUI_CVIDEOSETTINGSMENUFORM_H
#endif /* GUCE_GUI_CVIDEOSETTINGSMENUFORM_H ? */

#endif /* __cplusplus ? */
/*--------------------------------------------------------------------------*/

#endif /* GUCE_GUI_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 13-09-2005 :
       - Initial version.

-----------------------------------------------------------------------------*/
