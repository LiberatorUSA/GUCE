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

#ifndef GUCE_GUI_CCONSOLEFORM_H
#define GUCE_GUI_CCONSOLEFORM_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_GUI_CTEXTBOX_H
#include "gucefGUI_CTextbox.h"
#define GUCEF_GUI_CTEXTBOX_H
#endif /* GUCEF_GUI_CTEXTBOX_H ? */

#ifndef GUCEF_GUI_CEDITBOX_H
#include "gucefGUI_CEditbox.h"
#define GUCEF_GUI_CEDITBOX_H
#endif /* GUCEF_GUI_CEDITBOX_H ? */

#ifndef GUCEF_GUI_CFORMEX_H
#include "gucefGUI_CFormEx.h"
#define GUCEF_GUI_CFORMEX_H
#endif /* GUCEF_GUI_CFORMEX_H ? */

#ifndef GUCE_GUI_MACROS_H
#include "guceGUI_macros.h"
#define GUCE_GUI_MACROS_H
#endif /* GUCE_GUI_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace GUI {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCE_GUI_EXPORT_CPP CConsoleForm : public GUCEF::GUI::CFormEx
{
    public:    
    
    CConsoleForm( void );
    
    virtual ~CConsoleForm();
    
    GUCEF::GUI::CEditbox* GetInputEditbox( void );
    
    GUCEF::GUI::CTextbox* GetConsoleTextbox( void );
    
    virtual const CString& GetClassTypeName( void ) const;
    
    protected:
    
    virtual void OnPreLayoutLoad( void );
    
    virtual void OnPostLayoutLoad( void );    
    
    private:
    
    CConsoleForm( const CConsoleForm& src );             /** not implemented */
    CConsoleForm& operator=( const CConsoleForm& src );  /** not implemented */
    
    private:

    GUCEF::GUI::CEditbox* m_inputEditbox;
    GUCEF::GUI::CTextbox* m_consoleTextbox;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_CCONSOLEFORM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-04-2007 :
        - Initial implementation

---------------------------------------------------------------------------*/
