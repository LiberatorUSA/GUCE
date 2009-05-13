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
 
#ifndef GUCE_CEGUIOGRE_CINPUTCEGUIMANIPULATOR_H
#define GUCE_CEGUIOGRE_CINPUTCEGUIMANIPULATOR_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_COBSERVER_H
#include "CObserver.h"
#define GUCEF_CORE_COBSERVER_H
#endif /* GUCEF_CORE_COBSERVER_H ? */

#ifndef GUCE_CEGUIOGRE_MACROS_H
#include "guceCEGUIOGRE_macros.h"     /* often used guceCEGUIOGRE macros */
#define GUCE_CEGUIOGRE_MACROS_H
#endif /* GUCE_CEGUIOGRE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace CEGUI { class System; }
namespace GUCEF { namespace INPUT { class CInputController; } }

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

/**
 *      Class that feeds input events into CEGUI for further processing.
 *      basically an adapter between the GUCEF platform and CEGUI
 */
class GUCE_CEGUIOGRE_EXPORT_CPP CInputCEGUIManipulator : public GUCEF::CORE::CObserver
{
    public:
    
    CInputCEGUIManipulator( const GUCEF::CORE::CString& name );                
    
    virtual ~CInputCEGUIManipulator();
    
    virtual const CString& GetClassTypeName( void ) const;
    
    /**
     *      If the GUI system has not yet been initialized at the time 
     *      an instance of this class is constructed then if will be disabled.
     *      You should then call this member function to acquire a link to the 
     *      GUI system after you have initialed it.
     */
    void AquireCEGUILink( void );                                                      
    
    protected:

    virtual void OnNotify( GUCEF::CORE::CNotifier* notifier           ,
                           const GUCEF::CORE::CEvent& eventid         ,
                           GUCEF::CORE::CICloneable* eventdata = NULL );

    private:
    
    CInputCEGUIManipulator( const CInputCEGUIManipulator& src );            /**< not implemented */
    CInputCEGUIManipulator& operator=( const CInputCEGUIManipulator& src ); /**< not implemented */
    
    private:
    
    CEGUI::System* m_guisystem;
    GUCEF::INPUT::CInputController* m_inputController;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CEGUIOGRE */
} /* namespace GUCE */

/*-------------------------------------------------------------------------*/

#endif /* GUCE_CEGUIOGRE_CINPUTCEGUIMANIPULATOR_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 15-10-2007 :
        - Updated to the new event system
- 30-10-2005 :
        - Designed and implemented this class.

-----------------------------------------------------------------------------*/
