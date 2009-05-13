/*
 * Copyright (C) Dinand Vanvelzen. 2002 - 2005.  All rights reserved.
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

#include "OgreMovableObject.h"

#include "CInputBasedOgreMObjectManipulator.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

GUCE_NAMESPACE_BEGIN
CORE_NAMESPACE_BEGIN

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

CInputBasedOgreMObjectManipulator::CInputBasedOgreMObjectManipulator( Ogre::MovableObject& movableObject ,
                                                                      const GUCEF::CORE::CString& name   )
        : CInputBasedManipulator( name ) ,
          m_movableObject( &movableObject )
{GUCE_TRACE;
        assert( m_movableObject );
}

/*-------------------------------------------------------------------------*/
        
CInputBasedOgreMObjectManipulator::~CInputBasedOgreMObjectManipulator()
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/

GUCEF::CORE::CString
CInputBasedOgreMObjectManipulator::GetTypeName( void ) const
{GUCE_TRACE;
        return "GUCE::CORE::CInputBasedOgreMObjectManipulator";
}

/*-------------------------------------------------------------------------*/
        
const Ogre::MovableObject& 
CInputBasedOgreMObjectManipulator::GetMovableObject( void ) const
{GUCE_TRACE;
        return *m_movableObject;
}

/*-------------------------------------------------------------------------*/

void 
CInputBasedOgreMObjectManipulator::OnMappedMouseButtonDown( GUCEF::INPUT::CInputContext& context ,
                                                            const UInt32 actionindex             ,
                                                            const UInt32 buttonindex             )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/
        
void 
CInputBasedOgreMObjectManipulator::OnMappedMouseButtonUp( GUCEF::INPUT::CInputContext& context ,
                                                          const UInt32 actionindex             ,
                                                          const UInt32 buttonindex             )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/
        
void 
CInputBasedOgreMObjectManipulator::OnMappedKeyboardKeyDown( GUCEF::INPUT::CInputContext& context ,
                                                            const UInt32 actionindex             ,
                                                            const UInt32 keyindex                )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/
        
void 
CInputBasedOgreMObjectManipulator::OnMappedKeyboardKeyUp( GUCEF::INPUT::CInputContext& context ,
                                                          const UInt32 actionindex             ,
                                                          const UInt32 keyindex                )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/
        
void 
CInputBasedOgreMObjectManipulator::OnMappedDeviceBooleanOn( GUCEF::INPUT::CInputContext& context ,
                                                            const UInt32 actionindex             ,
                                                            const UInt32 deviceid                ,
                                                            const UInt32 stateindex              )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/

void 
CInputBasedOgreMObjectManipulator::OnMappedDeviceBooleanOff( GUCEF::INPUT::CInputContext& context ,
                                                             const UInt32 actionindex             ,
                                                             const UInt32 deviceid                ,
                                                             const UInt32 stateindex              )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------*/
                                         
void 
CInputBasedOgreMObjectManipulator::OnMappedDeviceVariableChanged( GUCEF::INPUT::CInputContext& context ,
                                                                  const UInt32 actionindex             ,
                                                                  const UInt32 deviceid                ,
                                                                  const UInt32 stateindex              ,
                                                                  const Float32 value                  )
{GUCE_TRACE;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
