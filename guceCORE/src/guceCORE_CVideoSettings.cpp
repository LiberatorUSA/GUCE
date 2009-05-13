/*
 *  guceCORE: GUCE module providing tie-in functionality between systems
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
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

#include "guceCORE_CVideoSettings.h"

#ifndef __Exception_H_
#include "OgreException.h"
#define __Exception_H_
#endif /* __Exception_H_ ? */

#ifndef __RenderWindow_H__
#include "OgreRenderWindow.h"
#define __RenderWindow_H__
#endif /* __RenderWindow_H__ ? */

#ifdef GUCEF_MSWIN_BUILD
#include <windows.h>
#endif /* GUCEF_MSWIN_BUILD ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCE {
namespace CORE {
         
/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

CVideoSettings::CVideoSettings( void )
    : CIConfigurable()          ,
      m_isFullscreen( false )   ,
      m_hasVSync( false )       ,
      m_antiAliasingFactor( 0 ) ,
      m_displayMode()
{GUCE_TRACE;

    m_displayMode.depthInBits = 32;
    m_displayMode.frequency = 60;
    m_displayMode.widthInPixels = 800;
    m_displayMode.heightInPixels = 600;
}

/*-------------------------------------------------------------------------*/
    
CVideoSettings::CVideoSettings( const CVideoSettings& src )
    : CIConfigurable()                                 ,
      m_isFullscreen( src.m_isFullscreen )             ,
      m_hasVSync( src.m_hasVSync )                     ,
      m_antiAliasingFactor( src.m_antiAliasingFactor ) ,
      m_displayMode( src.m_displayMode )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CVideoSettings::~CVideoSettings()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CVideoSettings&
CVideoSettings::operator=( const CVideoSettings& src )
{GUCE_TRACE;

    if ( &src != this )
    {
        m_isFullscreen = src.m_isFullscreen;
        m_hasVSync = src.m_hasVSync;
        m_antiAliasingFactor = src.m_antiAliasingFactor;
        m_displayMode = src.m_displayMode;
    }
    return *this;
}

/*-------------------------------------------------------------------------*/
    
void
CVideoSettings::SetFullscreenState( const bool isFullscreen )
{GUCE_TRACE;

    m_isFullscreen = isFullscreen;
}

/*-------------------------------------------------------------------------*/
    
bool
CVideoSettings::GetFullscreenState( void ) const
{GUCE_TRACE;

    return m_isFullscreen;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetVSyncState( const bool hasVSync )
{GUCE_TRACE;

    m_hasVSync = hasVSync;
}

/*-------------------------------------------------------------------------*/
    
bool
CVideoSettings::GetVSyncState( void ) const
{GUCE_TRACE;

    return m_hasVSync;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetResolutionWidthInPixels( const UInt32 widthInPixels )
{GUCE_TRACE;

    m_displayMode.widthInPixels = widthInPixels;
}

/*-------------------------------------------------------------------------*/

UInt32
CVideoSettings::GetResolutionWidthInPixels( void ) const
{GUCE_TRACE;

    return m_displayMode.widthInPixels;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetResolutionHeightInPixels( const UInt32 heightInPixels )
{GUCE_TRACE;

    m_displayMode.heightInPixels = heightInPixels;
}

/*-------------------------------------------------------------------------*/

UInt32
CVideoSettings::GetResolutionHeightInPixels( void ) const
{GUCE_TRACE;

    return m_displayMode.heightInPixels;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetResolutionDepthInBits( const UInt32 depthInBits )
{GUCE_TRACE;

    m_displayMode.depthInBits = depthInBits;
}

/*-------------------------------------------------------------------------*/

UInt32
CVideoSettings::GetResolutionDepthInBits( void ) const
{GUCE_TRACE;

    return m_displayMode.depthInBits;
}

/*-------------------------------------------------------------------------*/
    
void
CVideoSettings::SetResolution( const UInt32 widthInPixels  ,
                               const UInt32 heightInPixels ,
                               const UInt32 depthInPixels  )
{GUCE_TRACE;

    m_displayMode.widthInPixels = widthInPixels;
    m_displayMode.heightInPixels = heightInPixels;
    m_displayMode.depthInBits = depthInPixels;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::GetResolution( UInt32& widthInPixels  ,
                               UInt32& heightInPixels ,
                               UInt32& depthInPixels  )
{GUCE_TRACE;

    widthInPixels = m_displayMode.widthInPixels;
    heightInPixels = m_displayMode.heightInPixels;
    depthInPixels = m_displayMode.depthInBits;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetAntiAliasingFactor( const UInt32 newFactor )
{GUCE_TRACE;

    m_antiAliasingFactor = newFactor;
}

/*-------------------------------------------------------------------------*/
    
UInt32
CVideoSettings::GetAntiAliasingFactor( void ) const
{GUCE_TRACE;

    return m_antiAliasingFactor;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetFrequency( const UInt32 frequency )
{GUCE_TRACE;

    m_displayMode.frequency = frequency;
}

/*-------------------------------------------------------------------------*/

UInt32
CVideoSettings::GetFrequency( void ) const
{GUCE_TRACE;

    return m_displayMode.frequency;
}

/*-------------------------------------------------------------------------*/

bool
CVideoSettings::SaveConfig( GUCEF::CORE::CDataNode& tree )
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/
                                                                   
bool
CVideoSettings::LoadConfig( const GUCEF::CORE::CDataNode& treeroot )
{GUCE_TRACE;

    return false;
}

/*-------------------------------------------------------------------------*/

void
CVideoSettings::SetDisplayMode( const TDisplayMode& displayMode )
{
    m_displayMode = displayMode;
}

/*-------------------------------------------------------------------------*/
    
void
CVideoSettings::GetDisplayMode( TDisplayMode& displayMode ) const
{
    displayMode = m_displayMode;
}

/*-------------------------------------------------------------------------*/

bool
CVideoSettings::RetrieveSettingsFromOS( CVideoSettings& settings )
{GUCE_TRACE;

    #ifdef GUCEF_MSWIN_BUILD
    
    DEVMODE displayMode;
    memset( &displayMode, 0, sizeof( DEVMODE ) );
    displayMode.dmSize = sizeof( DEVMODE );
    TDisplayMode currentMode;
    
    if ( TRUE == EnumDisplaySettings( NULL                  ,
                                      ENUM_CURRENT_SETTINGS ,
                                      &displayMode          ) )
    {
        currentMode.widthInPixels = displayMode.dmPelsWidth; 
        currentMode.heightInPixels = displayMode.dmPelsHeight;
        currentMode.depthInBits = displayMode.dmBitsPerPel;
        currentMode.frequency = displayMode.dmDisplayFrequency;
        settings.SetDisplayMode( currentMode );
        
        return true;
    }     
    return false;
    
    #else
    
    return false;
    
    #endif
}

/*-------------------------------------------------------------------------*/

bool
CVideoSettings::RetrieveSettingsFromRenderWindow( Ogre::RenderWindow& renderWindow ,
                                                  CVideoSettings& settings         )
{GUCE_TRACE;

    try
    {
        settings.SetResolutionWidthInPixels( renderWindow.getWidth() );
        settings.SetResolutionHeightInPixels( renderWindow.getHeight() );
        settings.SetResolutionDepthInBits( renderWindow.getColourDepth() );
        settings.SetFullscreenState( renderWindow.isFullScreen() );
        
        bool hasVSync = false;
        renderWindow.getCustomAttribute( "vsync", &hasVSync );
        settings.SetVSyncState( hasVSync );
        
        UInt32 fsaaFactor = 0;
        renderWindow.getCustomAttribute( "FSAA", &fsaaFactor );
        settings.SetAntiAliasingFactor( fsaaFactor );

        UInt32 displayFrequency = 0;
        renderWindow.getCustomAttribute( "displayFrequency", &displayFrequency );
        settings.SetFrequency( displayFrequency );
        
        return true;
    }
    catch ( Ogre::Exception& )
    {
        return false;
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
