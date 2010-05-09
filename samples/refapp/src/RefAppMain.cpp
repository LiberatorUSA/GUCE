/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2007.  All rights reserved.
 *
 * All source code herein is the property of Dinand Vanvelzen. You may not sell
 * or otherwise commercially exploit the source or things you created based on
 * the source.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL DINAND VANVELZEN BE LIABLE FOR ANY SPECIAL, INCIDENTAL, 
 * INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER 
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF 
 * THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT 
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCE_H
#include "guce.h"       /* main GUCE engine include */
#define GUCE_H
#endif /* GUCE_H ? */

#ifndef REFAPP_CREFAPPSUBSYSTEM_H
#include "CRefAppSubSystem.h"
#define REFAPP_CREFAPPSUBSYSTEM_H
#endif /* REFAPP_CREFAPPSUBSYSTEM_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *  Dummy class to get around allocations when obtaining info from the exception object
 *  If we crashed due to some memory allocation problem then we don't want to perform any
 *  allocations that are not absolutely required
 */
class CAccessOgreException : public Ogre::Exception
{
        public:
        
        inline const Ogre::String& GetFile( void ) const
        {
                return file;
        }
        
        inline const Ogre::String& GetFullDescription( void ) const
        {
                return description;
        }        
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Application entry point
 */
#ifdef GUCEF_MSWIN_BUILD

int __stdcall
WinMain( HINSTANCE hinstance     ,
         HINSTANCE hprevinstance ,
         LPSTR lpcmdline         ,
         int ncmdshow            )

#else

int __stdcall
main( const char* argv[] ,
      int argc           )

#endif

{GUCE_TRACE;

    #ifdef GUCE_CORE_DEBUG_MODE
    //GUCEF::CORE::GUCEF_LogStackToStdOut();
    //GUCEF::CORE::GUCEF_SetStackLogging( 1 );
    #endif /* GUCE_CORE_DEBUG_MODE ? */
                
    try 
    {
        GUCEF::CORE::CLogManager* logManager = GUCEF::CORE::CLogManager::Instance();
        
        GUCEF::CORE::CString logFilename = GUCEF::CORE::RelativePath( "$CURWORKDIR$" );
        GUCEF::CORE::AppendToPath( logFilename, "GU_MG.txt" );
        GUCEF::CORE::CFileAccess logFileAccess( logFilename, "w" );
        
        GUCEF::CORE::CStdLogger logger( logFileAccess );
        #ifdef GUCE_CORE_DEBUG_MODE
        logger.SetMinimalLogLevel( GUCEF::CORE::LOGLEVEL_NORMAL );
        #endif /* GUCE_CORE_DEBUG_MODE ? */
        logManager->AddLogger( &logger ); 

        #if defined( GUCEF_MSWIN_BUILD ) && defined( GUCE_CORE_DEBUG_MODE )
        GUCEF::CORE::CMSWinConsoleLogger consoleOut;
        consoleOut.SetMinimalLogLevel( GUCEF::CORE::LOGLEVEL_NORMAL );
        logManager->AddLogger( &consoleOut );
        #endif /* GUCEF_MSWIN_BUILD && GUCE_CORE_DEBUG_MODE ? */
        
        logManager->FlushBootstrapLogEntriesToLogs();
        
        /*
         *      Get some pointers to system components
         */
        GUCEF::CORE::CConfigStore* configStore = GUCEF::CORE::CConfigStore::Instance();
        GUCEF::CORE::CDStoreCodecPluginManager* dataStorageCodecMan = GUCEF::CORE::CDStoreCodecPluginManager::Instance();        
        GUCE::CORE::CGUCEApplication::Instance();
        GUCE::GUI::CGUIManager::Instance();

        #if defined( GUCEF_MSWIN_BUILD )
        GUCEF::CORE::CMsWin32ConsoleWindow win32Console;
        win32Console.ConsoleWindowCreate();
	    win32Console.Show();
        #endif
         
        // Load data store codec's so we can load config
        GUCEF::CORE::CDStoreCodecPluginManager* dstoreCodecPluginManager = GUCEF::CORE::CDStoreCodecPluginManager::Instance();
        dstoreCodecPluginManager->LoadAll( GUCEF::CORE::RelativePath( "$MODULEDIR$" ) );
        
        CRefAppSubSystem* refAppSubSys = new CRefAppSubSystem();

        /*
         *      Load the configuration
         */ 
        configStore->SetConfigFile( "$MODULEDIR$\\RefAppConfig.xml" );                
        if ( configStore->LoadConfig() )
        {
            /*
             *      Start the Application
             */
            #ifdef GUCE_MSWIN_BUILD
            
            int retval = GUCE::CORE::CGUCEApplication::Instance()->Main( hinstance     ,
                                                                         lpcmdline     ,
                                                                         ncmdshow      ,
                                                                         true          );
            #else
            
            int retval = GUCE::CORE::CGUCEApplication::Instance()->main( argv ,
                                                                         argc ,
                                                                         true );            
            
            #endif
            
            /*
             *      Save the configuration changes
             */                                                                             
            configStore->SaveConfig( "RefAppConfig" );  
            
            delete refAppSubSys;
            return retval;                                                                  
        }
        else
        {
            GUCEF::CORE::CString msg( "Failed to load application configuration\n" );
            msg += "Unable to load \"" + configStore->GetConfigFile() + "\" using codec " + configStore->GetCodec();
            GUCEF::CORE::ShowErrorMessage( "Startup error" ,
                                           msg.C_String()  );           
        }
        
    }    
    catch ( GUCEF::CORE::CException& e )
    {
        #ifdef GUCE_CORE_DEBUG_MODE
        GUCEF::CORE::GUCEF_PrintCallstack();
        GUCEF::CORE::GUCEF_DumpCallstack( "CallstackDump.txt" );
        #endif /* GUCE_CORE_DEBUG_MODE ? */
            
        GUCEF::CORE::CString msg( "GUCEF exception during program execution\n\n" );
        msg += "file: " + GUCEF::CORE::CString( e.GetOriginFile() ) + "\n" + "line: " + GUCEF::CORE::Int32ToString( e.GetOriginLineNr() );
        
        GUCEF::CORE::ShowErrorMessage( "Unhandled GUCEF exception" ,
                                       msg.C_String()              );                  
    }    
    catch( Ogre::Exception& e )
    {
        #ifdef GUCE_CORE_DEBUG_MODE
        GUCEF::CORE::GUCEF_PrintCallstack();
        GUCEF::CORE::GUCEF_DumpCallstack( "CallstackDump.txt" );
        #endif /* GUCE_CORE_DEBUG_MODE ? */
        
        CAccessOgreException& ea = static_cast<CAccessOgreException&>( e );
        
        GUCEF::CORE::CString msg( "Ogre exception during program execution\n\n" );
        msg += "file: " + ea.GetFile() + "\n" + "line: " + GUCEF::CORE::Int32ToString( e.getLine() ) + "\ndescription: " + ea.GetFullDescription();
        
        GUCEF::CORE::ShowErrorMessage( "Unhandled Ogre exception" ,
                                       msg.C_String()             );        
    }                                                                                
    catch( std::bad_alloc& e )
    {
        #ifdef GUCE_CORE_DEBUG_MODE
        GUCEF::CORE::GUCEF_PrintCallstack();
        GUCEF::CORE::GUCEF_DumpCallstack( "CallstackDump.txt" );
        #endif /* GUCE_CORE_DEBUG_MODE ? */
        
        GUCEF::CORE::CString msg( "Memory allocation failure during program execution\n\n" + GUCEF::CORE::CString( e.what() ) );
        GUCEF::CORE::ShowErrorMessage( "Unhandled STL bad_alloc exception" ,
                                       msg.C_String()                      );    
    }
    catch( std::exception& e )
    {
        #ifdef GUCE_CORE_DEBUG_MODE
        GUCEF::CORE::GUCEF_PrintCallstack();
        GUCEF::CORE::GUCEF_DumpCallstack( "CallstackDump.txt" );
        #endif /* GUCE_CORE_DEBUG_MODE ? */
        
        GUCEF::CORE::CString msg( "STL exception during program execution\n\n" + GUCEF::CORE::CString( e.what() ) );
        GUCEF::CORE::ShowErrorMessage( "Unhandled STL exception" ,
                                       msg.C_String()            );        
    }    
    catch ( ... )
    {
        #ifdef GUCE_CORE_DEBUG_MODE
        GUCEF::CORE::GUCEF_PrintCallstack();
        GUCEF::CORE::GUCEF_DumpCallstack( "CallstackDump.txt" );
        #endif /* GUCE_CORE_DEBUG_MODE ? */
        
        GUCEF::CORE::ShowErrorMessage( "Unknown exception"                                                                 ,
                                       "Unhandled exception during program execution, the application will now terminate"  );
    }
    return 1;                                                                                                                              
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 13-01-2007
        - Dinand: Initial version

-----------------------------------------------------------------------------*/