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

#ifndef GUCE_CEGUIOGRE_CBUTTONIMP_H
#define GUCE_CEGUIOGRE_CBUTTONIMP_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _CEGUIPushButton_h_
#include "elements/CEGUIPushButton.h"
#define _CEGUIPushButton_h_
#endif /* _CEGUIPushButton_h_ ? */

#ifndef GUCE_CEGUIOGRE_CWIDGETIMP_H
#include "guceCEGUIOgre_CWidgetImp.h"
#define GUCE_CEGUIOGRE_CWIDGETIMP_H
#endif /* GUCE_CEGUIOGRE_CWIDGETIMP_H ? */

#ifndef GUCEF_GUI_CBUTTON_H
#include "gucefGUI_CButton.h"
#define GUCEF_GUI_CBUTTON_H
#endif /* GUCEF_GUI_CBUTTON_H ? */

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

class GUCE_CEGUIOGRE_EXPORT_CPP CButtonImp : public CWidgetImp< GUCEF::GUI::CButton >
{
    public:
       
    CButtonImp( void );
    
    virtual ~CButtonImp();
    
    virtual bool SetButtonText( const CString& newText );
    
    virtual bool GetButtonText( CString& text ) const;
    
    virtual void Hook( CEGUI::PushButton* window );
    
    protected:
    
    virtual bool OnMouseDown( const CEGUI::EventArgs& e );
    
    virtual bool OnMouseUp( const CEGUI::EventArgs& e );
    
    virtual bool OnButtonClick( const CEGUI::EventArgs& e );    
    
    private:
    
    CButtonImp( const CButtonImp& src );
    CButtonImp& operator=( const CButtonImp& src );
    
    private:
    
    CEGUI::PushButton* m_button;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_CEGUIOGRE_CBUTTONIMP_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
