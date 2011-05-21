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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_CLONEABLES_H
#include "cloneables.h"
#define GUCEF_CORE_CLONEABLES_H
#endif /* GUCEF_CORE_CLONEABLES_H ? */

#ifndef GUCEF_INPUT_KEYBOARD_H
#include "gucefINPUT_keyboard.h"
#define GUCEF_INPUT_KEYBOARD_H
#endif /* GUCEF_INPUT_KEYBOARD_H ? */

#ifndef GUCEF_VFS_CVFS_H
#include "gucefVFS_CVFS.h"
#define GUCEF_VFS_CVFS_H
#endif /* GUCEF_VFS_CVFS_H ? */

#include "guceGUI_CConsole.h"

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

CConsole::CConsole( void )
    : CSysConsoleClient() ,
      CObserver()         ,
      m_consoleForm()     ,
      m_inputIterator()   ,
      m_inputList()
{GUCE_TRACE;

    SubscribeTo( &m_consoleForm                                              ,
                 GUCEF::GUI::CForm::LayoutLoadedEvent                        ,
                 &TEventCallback( this, &CConsole::OnConsoleFormLayoutLoaded ) );
}

/*-------------------------------------------------------------------------*/
    
CConsole::~CConsole()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/

CConsoleForm&
CConsole::GetConsoleForm( void )
{GUCE_TRACE;

    return m_consoleForm;
}

/*-------------------------------------------------------------------------*/

void
CConsole::OnConsoleFormLayoutLoaded( GUCEF::CORE::CNotifier* notifier    ,
                                     const GUCEF::CORE::CEvent& eventid  ,
                                     GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    SubscribeTo( m_consoleForm.GetInputEditbox()                             ,
                 GUCEF::GUI::CEditbox::TextEnteredEvent                      ,
                 &TEventCallback( this, &CConsole::OnInputEditboxTextEntered ) );                 
    SubscribeTo( m_consoleForm.GetInputEditbox()                         ,
                 GUCEF::GUI::CEditbox::KeyDownEvent                      ,
                 &TEventCallback( this, &CConsole::OnInputEditboxKeyDown ) );                 
}

/*-------------------------------------------------------------------------*/

void
CConsole::OnInputEditboxTextEntered( GUCEF::CORE::CNotifier* notifier    ,
                                     const GUCEF::CORE::CEvent& eventid  ,
                                     GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;

    GUCEF::GUI::CEditbox* editbox = m_consoleForm.GetInputEditbox();    
    ProcessFunctionInput( editbox->GetText() );  
}

/*-------------------------------------------------------------------------*/

void
CConsole::ShowModal( void )
{GUCE_TRACE;
  
    m_consoleForm.ShowModal();    
}

/*-------------------------------------------------------------------------*/

void
CConsole::Show( void )
{GUCE_TRACE;
    
    m_consoleForm.Show();
}

/*-------------------------------------------------------------------------*/

void
CConsole::Hide( void )
{GUCE_TRACE;

    m_consoleForm.Hide();
}

/*-------------------------------------------------------------------------*/

const CString&
CConsole::GetClassTypeName( void ) const
{GUCE_TRACE;

    static CString classTypeName = "GUCE::GUI::CConsole";
    return classTypeName;
}

/*-------------------------------------------------------------------------*/

void
CConsole::ProcessInput( const CString& input )
{GUCE_TRACE;

    if ( 0 == input.Length() ) return;
    
    CString consoleline( GetPath() );
    consoleline += "> " + input;

    GUCEF::GUI::CTextbox* textbox = m_consoleForm.GetConsoleTextbox();
    GUCEF::GUI::CEditbox* editbox = m_consoleForm.GetInputEditbox();
    
    textbox->AppendLine( consoleline );                
    
    m_inputList.push_back( input );
    m_inputIterator = m_inputList.begin();
    
    editbox->Clear();                                

    if ( input == "hide" )
    {
        Hide();
    }
    else
    if ( input == "clear" )
    {
        textbox->Clear();
        m_inputList.clear();
        m_inputIterator = m_inputList.begin();
    }
    else
    if ( input == "dir" )
    {
        std::vector< CString > dirs( GetDirList() );
        if ( dirs.size() > 0 )
        {
            for ( UInt32 i=0; i<dirs.size(); ++i )
            {
                consoleline = "SYSTEM: DIR> " + dirs[ i ];
                textbox->AppendLine( consoleline );
            }
            textbox->AppendLine( "SYSTEM> end of dir list" );
        }
        else
        {
            textbox->AppendLine( "SYSTEM> no sub-dirs found" );        
        }                                
    }
    else
    if ( input == "list" )
    {
        std::vector< CString > funcs( GetCmdList() );
        if ( funcs.size() > 0 )
        {                                
            for ( UInt32 i=0; i<funcs.size(); ++i )
            {
                consoleline = "SYSTEM: FUNCTION> " + funcs[ i ];
                textbox->AppendLine( consoleline );
            }
            textbox->AppendLine( "SYSTEM> end of function list" );
        }
        else
        {
            textbox->AppendLine( "SYSTEM> no functions found" );        
        }                                               
    }
    else
    if ( input.HasSubstr( "cd ", true ) == 0 )
    {
        CString dirname( input.CutChars( 3, true ) );
        if ( EnterDir( dirname ) )
        {
            textbox->AppendLine( "SYSTEM> entered namespace dir: " + GetPath() );
        }
        else
        {
            textbox->AppendLine( "SYSTEM: ERROR> failed to enter sub-dir: " + dirname );        
        }
    }
    else
    if ( input.HasSubstr( "load ", true ) == 0 )
    {
        // load console commands from the file given using vfs
        GUCEF::VFS::CVFS* vfs = GUCEF::VFS::CVFS::Instance();  
        CString filename( input.CutChars( 5, true ) );
        GUCEF::VFS::CVFS::CVFSHandlePtr handle = vfs->GetFile( filename );
        
        if ( handle != NULL )
        {            
            TStringVector commands;
            GUCEF::CORE::CIOAccess* ioAccess = handle->GetAccess();
            while ( !ioAccess->Eof() )
            {
                commands.push_back( ioAccess->ReadLine() );
            }    
            handle = NULL;

            textbox->AppendLine( "SYSTEM> file loaded,.. executing script" );

            for ( UInt32 i=0; i<commands.size(); ++i ) 
            {
                ProcessInput( commands[ i ] );
            }

            textbox->AppendLine( "SYSTEM> script execution finished" );                                        
        }
        else
        {
            textbox->AppendLine( "SYSTEM: ERROR> file not found" );                                
        }                                
    }
    else
    {
        ProcessFunctionInput( input );
    }         
}

/*-------------------------------------------------------------------------*/

void 
CConsole::ProcessFunctionInput( const CString& input )
{GUCE_TRACE;

    GUCEF::GUI::CTextbox* textbox = m_consoleForm.GetConsoleTextbox();

    /*
     *      Separate the input segments 
     *      and call Execute()
     */
    TStringVector args( input.ParseElements( ' ' ) );
    if ( args.size() > 0 )
    {
        CString funcname( args[ 0 ] );
        args.pop_back();
        TStringVector resultdata;                                 
        if ( Execute( funcname   ,
                      args       ,
                      resultdata ) )
        {
            TStringVector::iterator i = resultdata.begin();
            while ( i != resultdata.end() )
            {
                textbox->AppendLine( *i );
                ++i;
            }
            return;        
        }
        TStringVector::iterator i = resultdata.begin();
        while ( i != resultdata.end() )
        {
            textbox->AppendLine( *i );
            ++i;
        }
        textbox->AppendLine( "SYSTEM: ERROR> Failed to execute function" );                                
    }
}

/*-------------------------------------------------------------------------*/

void 
CConsole::OnReturnData( const TStringVector& data )
{GUCE_TRACE;

    GUCEF::GUI::CTextbox* textbox = m_consoleForm.GetConsoleTextbox();
    if ( NULL != textbox )
    {
        TStringVector::const_iterator i = data.begin();
        while ( i != data.end() )
        {
            textbox->AppendLine( *i );
            ++i;
        }
    }
}

/*-------------------------------------------------------------------------*/

void 
CConsole::OnInputEditboxKeyDown( GUCEF::CORE::CNotifier* notifier    ,
                                 const GUCEF::CORE::CEvent& eventid  ,
                                 GUCEF::CORE::CICloneable* eventdata )
{GUCE_TRACE;
       
    const GUCEF::INPUT::KeyCode keyCode = (GUCEF::INPUT::KeyCode) static_cast< GUCEF::CORE::TCloneableInt32* >( eventdata )->GetData();
    
    switch ( keyCode )
    {
        case GUCEF::INPUT::KEYCODE_UP :
        {
            ++m_inputIterator;
            m_consoleForm.GetInputEditbox()->SetText( (*m_inputIterator) );
        }
        case GUCEF::INPUT::KEYCODE_DOWN :
        {
            --m_inputIterator;
            m_consoleForm.GetInputEditbox()->SetText( (*m_inputIterator) );
        } 
        default :
        {
        }       
    }     
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
