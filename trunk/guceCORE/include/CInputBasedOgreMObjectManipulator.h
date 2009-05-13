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

#ifndef CINPUTBASEDOGREMOBJECTMANIPULATOR_H
#define CINPUTBASEDOGREMOBJECTMANIPULATOR_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCECORE_MACROS_H
#include "guceCORE_macros.h"     /* guceCORE build config and macros */
#define GUCECORE_MACROS_H
#endif /* GUCECORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace Ogre { class MovableObject; }

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

class GUCE_CORE_EXPORT_CPP CInputBasedOgreMObjectManipulator : public GUCEF::INPUT::CInputBasedManipulator
{
        public:
        
        CInputBasedOgreMObjectManipulator( Ogre::MovableObject& movableObject ,
                                           const GUCEF::CORE::CString& name   );        
        
        virtual ~CInputBasedOgreMObjectManipulator();
        
        const Ogre::MovableObject& GetMovableObject( void ) const;
        
        virtual GUCEF::CORE::CString GetTypeName( void ) const;
        
        protected:
        
        virtual void OnMappedMouseButtonDown( GUCEF::INPUT::CInputContext& context ,
                                              const UInt32 actionindex             ,
                                              const UInt32 buttonindex             );
        
        virtual void OnMappedMouseButtonUp( GUCEF::INPUT::CInputContext& context ,
                                            const UInt32 actionindex             ,
                                            const UInt32 buttonindex             );
        
        virtual void OnMappedKeyboardKeyDown( GUCEF::INPUT::CInputContext& context ,
                                              const UInt32 actionindex             ,
                                              const UInt32 keyindex                );
        
        virtual void OnMappedKeyboardKeyUp( GUCEF::INPUT::CInputContext& context ,
                                            const UInt32 actionindex             ,
                                            const UInt32 keyindex                );
        
        virtual void OnMappedDeviceBooleanOn( GUCEF::INPUT::CInputContext& context ,
                                              const UInt32 actionindex             ,
                                              const UInt32 deviceid                ,
                                              const UInt32 stateindex              );
                                        
        virtual void OnMappedDeviceBooleanOff( GUCEF::INPUT::CInputContext& context ,
                                               const UInt32 actionindex             ,
                                               const UInt32 deviceid                ,
                                               const UInt32 stateindex              );
                                         
        virtual void OnMappedDeviceVariableChanged( GUCEF::INPUT::CInputContext& context ,
                                                    const UInt32 actionindex             ,
                                                    const UInt32 deviceid                ,
                                                    const UInt32 stateindex              ,
                                                    const Float32 value                  );        
        
        private:
        
        CInputBasedOgreMObjectManipulator( const CInputBasedOgreMObjectManipulator& src );
        CInputBasedOgreMObjectManipulator& operator=( const CInputBasedOgreMObjectManipulator& src );
        
        private:
        
        Ogre::MovableObject* m_movableObject;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CORE_NAMESPACE_END
GUCE_NAMESPACE_END

/*-------------------------------------------------------------------------*/
          
#endif /* CINPUTBASEDOGREMOBJECTMANIPULATOR_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 06-11-2005 :
        - Initial implementation

-----------------------------------------------------------------------------*/
