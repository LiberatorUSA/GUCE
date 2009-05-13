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

#ifndef GUCE_CORE_CVIDEOSETTINGS_H
#include "guceCORE_CVideoSettings.h"
#define GUCE_CORE_CVIDEOSETTINGS_H
#endif /* GUCE_CORE_CVIDEOSETTINGS_H ? */

#include "guceCORE_CVideoOptions.h"

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

CVideoOptions::CVideoOptions( void )
    : m_displayModes()
{GUCE_TRACE;
    
}

/*-------------------------------------------------------------------------*/
    
CVideoOptions::CVideoOptions( const CVideoOptions& src )
    : m_displayModes( src.m_displayModes )
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CVideoOptions::~CVideoOptions()
{GUCE_TRACE;

}

/*-------------------------------------------------------------------------*/
    
CVideoOptions&
CVideoOptions::operator=( const CVideoOptions& src )
{GUCE_TRACE;

    if ( &src != this )
    {
        m_displayModes = src.m_displayModes;
    }
    return *this;
}

/*-------------------------------------------------------------------------*/

const CVideoOptions::TDisplayModeVector&
CVideoOptions::GetDisplayModes( void ) const
{GUCE_TRACE;

    return m_displayModes;
}

/*-------------------------------------------------------------------------*/

void
CVideoOptions::Clear( void )
{GUCE_TRACE;
    
    m_displayModes.clear();
}

/*-------------------------------------------------------------------------*/

bool
CVideoOptions::RetrieveOptionsFromOS( CVideoOptions& options )
{GUCE_TRACE;

    #ifdef GUCEF_MSWIN_BUILD
    
    UInt32 i=0;
    DEVMODE displayMode;
    memset( &displayMode, 0, sizeof( DEVMODE ) );
    displayMode.dmSize = sizeof( DEVMODE );
    TDisplayMode newMode;
    
    options.Clear();
    while ( TRUE == EnumDisplaySettings( NULL         ,
                                         i            ,
                                         &displayMode ) )
    {
        newMode.widthInPixels = displayMode.dmPelsWidth; 
        newMode.heightInPixels = displayMode.dmPelsHeight;
        newMode.depthInBits = displayMode.dmBitsPerPel;
        newMode.frequency = displayMode.dmDisplayFrequency;
        options.m_displayModes.push_back( newMode );
        ++i;
    } 
    
    return true;
    
    #else
    
    return false;
    
    #endif
}

/*-------------------------------------------------------------------------*/

void
CVideoOptions::GetDisplayModesForResolution( const UInt32 widthInPixels  , 
                                             const UInt32 heightInPixels ,
                                             TDisplayModeVector& modes   ) const
{GUCE_TRACE;

    for ( UInt32 i=0; i<m_displayModes.size(); ++i )
    {
        const TDisplayMode& displayMode = m_displayModes[ i ];
        if ( ( displayMode.widthInPixels == widthInPixels ) &&
             ( displayMode.heightInPixels == heightInPixels ) )
        {
            modes.push_back( displayMode );
        }
    }
}

/*-------------------------------------------------------------------------*/

bool
CVideoOptions::AreSettingsPossible( const CVideoSettings& settings ) const
{GUCE_TRACE;

    UInt32 widthInPixels = settings.GetResolutionWidthInPixels();
    UInt32 heightInPixels = settings.GetResolutionHeightInPixels();
    for ( UInt32 i=0; i<m_displayModes.size(); ++i )
    {
        const TDisplayMode& displayMode = m_displayModes[ i ];
        if ( ( displayMode.widthInPixels == widthInPixels ) &&
             ( displayMode.heightInPixels == heightInPixels ) )
        {
            if ( ( displayMode.depthInBits == settings.GetResolutionDepthInBits() ) &&
                 ( displayMode.frequency == settings.GetFrequency() )                )
            {
                return true;
            }
        }
    }
    return false;    
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
