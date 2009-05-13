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

#ifndef GUCE_CEGUIOGRE_CWIDGETIMP_H
#define GUCE_CEGUIOGRE_CWIDGETIMP_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef _CEGUIWindow_h_
#include "CEGUIWindow.h"
#define _CEGUIWindow_h_
#endif /* _CEGUIWindow_h_ ? */

#ifndef _CEGUIExceptions_h_
#include "CEGUIExceptions.h"
#define _CEGUIExceptions_h_
#endif /* _CEGUIExceptions_h_ ? */

#ifndef GUCEF_CORE_CSTDOSTREAMADAPTER_H
#include "CSTDOStreamAdapter.h"
#define GUCEF_CORE_CSTDOSTREAMADAPTER_H
#endif /* GUCEF_CORE_CSTDOSTREAMADAPTER_H ? */

#ifndef GUCEF_GUI_CWIDGET_H
#include "gucefGUI_CWidget.h"
#define GUCEF_GUI_CWIDGET_H  
#endif /* GUCEF_GUI_CWIDGET_H ? */

#ifndef GUCE_CEGUIOGRE_MACROS_H
#include "guceCEGUIOGRE_macros.h"     /* often used guceCEGUIOGRE macros */
#define GUCE_CEGUIOGRE_MACROS_H
#endif /* GUCE_CEGUIOGRE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CEGUIOGRE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      TEMPLATES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *  Generic widget API glue for the CEGUI/Ogre backend
 *  Implements the glue to CEGUI at the CWidget level
 */
template < class BaseClass >
class CWidgetImp : public BaseClass
{
    public:
    
    typedef GUCEF::GUI::CWidget::TWidgetSet TWidgetSet;
    
    CWidgetImp( void );
    
    virtual ~CWidgetImp();
    
    virtual bool ShowModal( void );
    
    virtual bool SetVisibility( const bool isVisible );
    
    virtual bool IsVisible( void ) const;
    
    virtual bool SetEnabled( const bool isEnabled );
     
    virtual bool IsEnabled( void ) const;
    
    virtual bool SetPosition( const GUCEF::GUI::CUVector& newPos );
    
    virtual bool GetPosition( GUCEF::GUI::CUVector& pos );
    
    virtual bool SetSize( const GUCEF::GUI::CUVector& newSize );
    
    virtual bool GetSize( GUCEF::GUI::CUVector& size ) const;
    
    virtual bool SetWidth( const GUCEF::GUI::CUDim& newWidth );
    
    virtual bool GetWidth( GUCEF::GUI::CUDim& width );
    
    virtual bool SetHeight( const GUCEF::GUI::CUDim& newHeight );
    
    virtual bool GetHeight( GUCEF::GUI::CUDim& height );    
    
    virtual bool SetParentWidget( GUCEF::GUI::CWidget* parentWidget );
    
    virtual GUCEF::GUI::CWidget* GetParentWidget( void );
    
    virtual GUCEF::GUI::CWidget* GetChildWidget( const CString& widgetName );
    
    virtual bool GetChildWidgetSet( TWidgetSet& childSet );
    
    virtual CString GetName( void ) const;
    
    virtual bool SetPropertyValue( const CString& widgetProperty ,
                                   const CString& propertyValue  );

    virtual bool GetPropertyValue( const CString& widgetProperty ,
                                   CString& propertyValue        ) const;

    virtual bool SetProperties( const GUCEF::CORE::CValueList& list );

    virtual bool GetProperties( GUCEF::CORE::CValueList& list ) const;
    
    virtual bool HasProperty( const CString& widgetProperty ) const;
    
    virtual bool LoadProperties( GUCEF::CORE::CIOAccess& propertyStorage );
    
    virtual bool SaveProperties( GUCEF::CORE::CIOAccess& propertyStorage ) const;
    
    virtual void Hook( CEGUI::Window* window );
    
    CEGUI::UDim ConvertDim( const GUCEF::GUI::CUDim& src ) const;
    
    GUCEF::GUI::CUDim ConvertDim( const CEGUI::UDim& src ) const;
    
    CEGUI::UVector2 ConvertVector( const GUCEF::GUI::CUVector& src ) const;
    
    GUCEF::GUI::CUVector ConvertVector( const CEGUI::UVector2& src ) const;

    virtual const CString& GetClassTypeName( void ) const;

    protected:
    
    virtual bool OnMouseDown( const CEGUI::EventArgs& e );
    
    virtual bool OnMouseUp( const CEGUI::EventArgs& e );
    
    CEGUI::Window* GetCEGUIWindow( void );
    
    private:
    
    CWidgetImp( const CWidgetImp& src );
    CWidgetImp& operator=( const CWidgetImp& src );
    
    private:
    
    CEGUI::Window* m_window;
};

/*-------------------------------------------------------------------------*/

/**
 *  Dummy class used to gain access to CEGUI window properties
 */
class CWindowDataAccessor : public CEGUI::Window
{
    public:
    
    typedef std::vector< CEGUI::Window* > CEGUIChildList;
        
    CEGUIChildList& GetChildList( void );
    
    private:
    
    CWindowDataAccessor( void );
    CWindowDataAccessor( const CWindowDataAccessor& src );
    ~CWindowDataAccessor();
    CWindowDataAccessor& operator=( const CWindowDataAccessor& src );
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      TYPES                                                              //
//                                                                         //
//-------------------------------------------------------------------------*/

typedef CWidgetImp< GUCEF::GUI::CWidget > TBasicWidgetImp;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

template < class BaseClass >
CWidgetImp< BaseClass >::CWidgetImp( void )
    : BaseClass()      ,
      m_window( NULL )
{GUCE_TRACE;


}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
CWidgetImp< BaseClass >::~CWidgetImp()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::ShowModal( void )
{GUCE_TRACE;

    m_window->setModalState( true );
    m_window->show();
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
void
CWidgetImp< BaseClass >::Hook( CEGUI::Window* window )
{GUCE_TRACE;

    m_window = window;
    m_window->setUserData( this );
    SetImplementationPtr( m_window );
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
const CString&
CWidgetImp< BaseClass >::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString typeName = "GUCE::CEGUIOGRE::CWidgetImp< BaseClass >";
    return typeName;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
CEGUI::Window*
CWidgetImp< BaseClass >::GetCEGUIWindow( void )
{GUCE_TRACE;

    return m_window;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
GUCEF::GUI::CWidget*
CWidgetImp< BaseClass >::GetChildWidget( const CString& widgetName )
{GUCE_TRACE;

    CEGUI::Window* childWidget = NULL;
    
    try
    {
        childWidget = m_window->getChild( widgetName.C_String() );
    }
    catch ( CEGUI::Exception& )
    {
        return NULL;
    }
    
    return static_cast< CWidget* >( childWidget->getUserData() );
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
CString
CWidgetImp< BaseClass >::GetName( void ) const
{GUCE_TRACE;

    if ( NULL != m_window )
    {
        return m_window->getName().c_str();
    }
    return CString();
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
CEGUI::UDim
CWidgetImp< BaseClass >::ConvertDim( const GUCEF::GUI::CUDim& src ) const
{GUCE_TRACE;

    return CEGUI::UDim( src.GetRelativeValue(), src.GetPixelValue() );
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
CEGUI::UVector2
CWidgetImp< BaseClass >::ConvertVector( const GUCEF::GUI::CUVector& src ) const
{GUCE_TRACE;

    return CEGUI::UVector2( ConvertDim( src.GetX() ), ConvertDim( src.GetY() ) );
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
GUCEF::GUI::CUDim
CWidgetImp< BaseClass >::ConvertDim( const CEGUI::UDim& src ) const
{GUCE_TRACE;

    return GUCEF::GUI::CUDim( src.d_scale, src.d_offset );    
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
GUCEF::GUI::CUVector
CWidgetImp< BaseClass >::ConvertVector( const CEGUI::UVector2& src ) const
{GUCE_TRACE;

    return GUCEF::GUI::CUVector( ConvertDim( src.d_x ), ConvertDim( src.d_y ) );
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetVisibility( const bool isVisible )
{GUCE_TRACE;

    m_window->setVisible( isVisible );
    if ( !isVisible )
    {
        m_window->setModalState( false );
    }
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::IsVisible( void ) const
{GUCE_TRACE;

    return m_window->isVisible();
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetEnabled( const bool isEnabled )
{GUCE_TRACE;

    m_window->setEnabled( isEnabled );
    return true;
}

/*-------------------------------------------------------------------------*/
     
template < class BaseClass >
bool
CWidgetImp< BaseClass >::IsEnabled( void ) const
{GUCE_TRACE;

    return !m_window->isDisabled();
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetPosition( const GUCEF::GUI::CUVector& newPos )
{GUCE_TRACE;

    m_window->setPosition( ConvertVector( newPos ) );
    return true;
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetPosition( GUCEF::GUI::CUVector& pos )
{GUCE_TRACE;

    pos = ConvertVector( m_window->getPosition() );
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetSize( const GUCEF::GUI::CUVector& newSize )
{GUCE_TRACE;

    m_window->setSize( ConvertVector( newSize ) );
    return true;
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetSize( GUCEF::GUI::CUVector& size ) const
{GUCE_TRACE;

    size = ConvertVector( m_window->getSize() );
    return true;
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetWidth( const GUCEF::GUI::CUDim& newWidth )
{GUCE_TRACE;

    m_window->setWidth( ConvertDim( newWidth ) );    
    return true;
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetWidth( GUCEF::GUI::CUDim& width )
{GUCE_TRACE;

    width = ConvertDim( m_window->getWidth() );
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >    
bool
CWidgetImp< BaseClass >::SetHeight( const GUCEF::GUI::CUDim& newHeight )
{GUCE_TRACE;

    m_window->setHeight( ConvertDim( newHeight ) );    
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetHeight( GUCEF::GUI::CUDim& height )
{GUCE_TRACE;

    height = ConvertDim( m_window->getHeight() );
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetParentWidget( GUCEF::GUI::CWidget* parentWidget )
{GUCE_TRACE;

    // First make sure we are no longer attached to another parent window
    if ( NULL != m_window )
    {
        if ( NULL != m_window->getParent() )
        {
            m_window->getParent()->removeChildWindow( m_window );
        }
    }

    // Check if we have received a new parent
    if ( NULL != parentWidget )
    {
        // Try to get access to the implementation
        CEGUI::Window* newParent = static_cast< CEGUI::Window* >( parentWidget->GetImplementationPtr() );
        if ( NULL != newParent )
        {
            // Set the new parent
            newParent->addChildWindow( m_window );
            return true;
        }
    }
    return false;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
GUCEF::GUI::CWidget*
CWidgetImp< BaseClass >::GetParentWidget( void )
{GUCE_TRACE;

    CEGUI::Window* parent = m_window->getParent();
    if ( NULL != parent )
    {
        return static_cast< CWidget* >( parent->getUserData() );
    }
    return NULL;
}
    
/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetChildWidgetSet( TWidgetSet& childSet )
{GUCE_TRACE;

    const CWindowDataAccessor::CEGUIChildList& children = static_cast< CWindowDataAccessor* >( m_window )->GetChildList();
    CWindowDataAccessor::CEGUIChildList::const_iterator i = children.begin();
    while ( i != children.end() )
    {
        GUCEF::GUI::CWidget* wrapWindow = static_cast< CWidget* >( (*i)->getUserData() );
        if ( NULL != wrapWindow )
        {
            childSet.insert( wrapWindow );
        }
        ++i;
    }
    return true;
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetPropertyValue( const CString& widgetProperty ,
                                           const CString& propertyValue  )
{GUCE_TRACE;

    try
    {
        m_window->setProperty( widgetProperty.C_String() ,
                               propertyValue.C_String()  );
        return true;
    }
    catch ( CEGUI::UnknownObjectException& )
    {
        return false;
    }
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetPropertyValue( const CString& widgetProperty ,
                                           CString& propertyValue        ) const
{GUCE_TRACE;

    try
    {
        propertyValue = m_window->getProperty( widgetProperty.C_String() ).c_str();
        return true;
    }
    catch ( CEGUI::UnknownObjectException& )
    {
        return false;
    }
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::SetProperties( const GUCEF::CORE::CValueList& list )
{GUCE_TRACE;

    bool success = true;
    for ( UInt32 i=0; i < list.GetCount(); ++i )
    {
        try
        {
            m_window->setProperty( list.GetKey( i ).C_String()   ,
                                   list.GetValue( i ).C_String() );
        }
        catch ( CEGUI::UnknownObjectException& )
        {
            success = false;
        }
    }
    return success;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::GetProperties( GUCEF::CORE::CValueList& list ) const
{GUCE_TRACE;

    CEGUI::PropertySet::Iterator i = m_window->getPropertyIterator();
    while ( !i.isAtEnd() )
    {   
        CEGUI::Property* property = (*i);
        try
        { 
            list.Set( property->getName().c_str()                          ,
                      m_window->getProperty( property->getName() ).c_str() ); 
        }
        catch ( CEGUI::UnknownObjectException& )
        {
        }
        
        ++i;
    }
    return true;
}
    
/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::HasProperty( const CString& widgetProperty ) const
{GUCE_TRACE;

    return m_window->isPropertyPresent( widgetProperty.C_String() );
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::LoadProperties( GUCEF::CORE::CIOAccess& propertyStorage )
{GUCE_TRACE;

    // not supported
    return false;
}

/*-------------------------------------------------------------------------*/
    
template < class BaseClass >
bool
CWidgetImp< BaseClass >::SaveProperties( GUCEF::CORE::CIOAccess& propertyStorage ) const
{GUCE_TRACE;

    GUCEF::CORE::CSTDOStreamAdapter outputAccess( propertyStorage );
    CEGUI::XMLSerializer encoder( outputAccess );
    m_window->writeXMLToStream( encoder );
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::OnMouseDown( const CEGUI::EventArgs& e )
{GUCEF_TRACE;

    NotifyObservers( MouseDownEvent );
    return true;
}

/*-------------------------------------------------------------------------*/

template < class BaseClass >
bool
CWidgetImp< BaseClass >::OnMouseUp( const CEGUI::EventArgs& e )
{GUCEF_TRACE;

    NotifyObservers( MouseUpEvent );
    return true;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CEGUIOGRE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCE_CEGUIOGRE_CWIDGETIMP_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
