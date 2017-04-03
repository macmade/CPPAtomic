/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @brief       ...
 */

#include <XS/IPC/RWLock.hpp>
#include <XS/IPC/Semaphore.hpp>
#include <XS/IPC/SharedMemory.hpp>

namespace XS
{
    template<>
    class XS::PIMPL::Object< IPC::RWLock >::IMPL
    {
        public:
            
            IMPL( void );
            IMPL( const IMPL & o );
            ~IMPL( void );
            
            IPC::Semaphore    _rsem;
            IPC::Semaphore    _wsem;
            IPC::SharedMemory _r;
    };
}

#define XS_PIMPL_CLASS XS::IPC::RWLock
#include <XS/PIMPL/Object-IMPL.hpp>

namespace XS
{
    namespace IPC
    {
        RWLock::RWLock( void ):
            XS::PIMPL::Object< RWLock >()
        {}
        
        void RWLock::LockForReading( void )
        {}
        
        void RWLock::LockForWriting( void )
        {}
        
        void RWLock::UnlockForReading( void )
        {}
        
        void RWLock::UnlockForWriting( void )
        {}
        
        bool RWLock::TryLockForReading( void )
        {
            return false;
        }
        
        bool RWLock::TryLockForWriting( void )
        {
            return false;
        }
    }
    
    PIMPL::Object< IPC::RWLock >::IMPL::IMPL( void )
    {}
    
    PIMPL::Object< IPC::RWLock >::IMPL::IMPL( const IMPL & o )
    {
        ( void )o;
    }
    
    PIMPL::Object< IPC::RWLock >::IMPL::~IMPL( void )
    {}
}
