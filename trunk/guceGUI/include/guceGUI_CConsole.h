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

#ifndef GUCE_GUI_CCONSOLE_H
#define GUCE_GUI_CCONSOLE_H 

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_CSYSCONSOLECLIENT_H
#include "CSysConsoleClient.h"
#define GUCEF_CORE_CSYSCONSOLECLIENT_H
#endif /* GUCEF_CORE_CSYSCONSOLECLIENT_H ? */

#ifndef GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H
#include "gucefCORE_CTEventHandlerFunctor.h"
#define GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H
#endif /* GUCEF_CORE_CTEVENTHANDLERFUNCTOR_H ? */

#ifndef GUCE_GUI_CCONSOLEFORM_H
#include "guceGUI_CConsoleForm.h"
#define GUCE_GUI_CCONSOLEFORM_H
#endif /* GUCE_GUI_CCONSOLEFORM_H ? */

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

class GUCE_GUI_EXPORT_CPP CConsole : public GUCEF::CORE::CSysConsoleClient ,
                                            GUCEF::CORE::CObserver
{
    public:    
    
    CConsole( void );
    
    virtual ~CConsole();

    void Show( void );
    
    void ShowModal( void );
    
    void Hide( void );
    
    CConsoleForm& GetConsoleForm( void );
    
    virtual const CString& GetClassTypeName( void ) const;   
    
    private:
    
    typedef GUCEF::CORE::CTEventHandlerFunctor< CConsole > TEventCallback;
    
    CConsole( const CConsole& src );             /** not implemented */
    CConsole& operator=( const CConsole& src );  /** not implemented */

    void OnConsoleFormLayoutLoaded( GUCEF::CORE::CNotifier* notifier    ,
                                    const GUCEF::CORE::CEvent& eventid  ,
                                    GUCEF::CORE::CICloneable* eventdata );

    void OnInputEditboxTextEntered( GUCEF::CORE::CNotifier* notifier    ,
                                    const GUCEF::CORE::CEvent& eventid  ,
                                    GUCEF::CORE::CICloneable* eventdata );

    void OnInputEditboxKeyDown( GUCEF::CORE::CNotifier* notifier    ,
                                const GUCEF::CORE::CEvent& eventid  ,
                                GUCEF::CORE::CICloneable* eventdata );

    void ProcessInput( const CString& input );
    
    void ProcessFunctionInput( const CString& input );
    
    void OnReturnData( const TStringVector& data );
    
    private:

    CConsoleForm m_consoleForm;
    TStringVector::iterator m_inputIterator;
    TStringVector m_inputList;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace GUI */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_GUI_CCONSOLE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-04-2007 :
        - Initial implementation

---------------------------------------------------------------------------*/
