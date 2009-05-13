/*
 *  guceCEGUIOgre: glue module for the CEGUI+Ogre GUI backend
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
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

#ifndef GUCE_CEGUIOGRE_CEDITBOXIMP_H
#define GUCE_CEGUIOGRE_CEDITBOXIMP_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _CEGUIEditbox_h_
#include "elements/CEGUIEditbox.h"
#define _CEGUIEditbox_h_
#endif /* _CEGUIEditbox_h_ ? */

#ifndef GUCE_CEGUIOGRE_CWIDGETIMP_H
#include "guceCEGUIOgre_CWidgetImp.h"
#define GUCE_CEGUIOGRE_CWIDGETIMP_H
#endif /* GUCE_CEGUIOGRE_CWIDGETIMP_H ? */

#ifndef GUCEF_GUI_CEDITBOX_H
#include "gucefGUI_CEditbox.h"
#define GUCEF_GUI_CEDITBOX_H
#endif /* GUCEF_GUI_CEDITBOX_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCE_CEGUIOGRE_EXPORT_CPP CEditboxImp : public CWidgetImp< GUCEF::GUI::CEditbox >
{
    public:
    
    CEditboxImp( void );
    
    virtual ~CEditboxImp();
    
    virtual bool SetText( const CString& text );
    
    virtual bool GetText( CString& text );
    
    virtual bool SetSelectedText( const CString& text );
    
    virtual bool GetSelectedText( CString& text );
    
    virtual void Clear( void );
    
    void Hook( CEGUI::Editbox* editbox );    
    
    private:
    
    CEditboxImp( const CEditboxImp& src );
    CEditboxImp& operator=( const CEditboxImp& src );
    
    private:
    
    CEGUI::Editbox* m_editbox;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_CEGUIOGRE_CEDITBOXIMP_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
