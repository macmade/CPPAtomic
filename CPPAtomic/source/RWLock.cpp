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

#include <XS/RWLock.hpp>
#include <mutex>
#include <stdexcept>

namespace XS
{
    template<>
    class XS::PIMPL::Object< RWLock >::IMPL
    {
        public:
            
            IMPL( void );
            IMPL( const IMPL & o );
            ~IMPL( void );
            
            std::recursive_mutex _rrmtx;
            std::recursive_mutex _wrmtx;
            int64_t              _r;
    };
}

#define XS_PIMPL_CLASS XS::RWLock
#include <XS/PIMPL/Object-IMPL.hpp>

namespace XS
{
    RWLock::RWLock( void ):
        XS::PIMPL::Object< RWLock >()
    {}
    
    void RWLock::LockForReading( void )
    {
        std::lock_guard< std::recursive_mutex > l( this->impl->_rrmtx );
        
        if( this->impl->_r == 0 )
        {
            this->impl->_wrmtx.lock();
        }
        
        this->impl->_r++;
    }
    
    void RWLock::LockForWriting( void )
    {
        this->impl->_wrmtx.lock();
    }
    
    void RWLock::UnlockForReading( void )
    {
        std::lock_guard< std::recursive_mutex > l( this->impl->_rrmtx );
        
        this->impl->_r--;
        
        if( this->impl->_r == 0 )
        {
            this->impl->_wrmtx.unlock();
        }
        else if( this->impl->_r < 0 )
        {
            throw std::runtime_error( "Invalid read unlock - Read lock was not acquired" );
        }
    }
    
    void RWLock::UnlockForWriting( void )
    {
        this->impl->_wrmtx.unlock();
    }
    
    bool RWLock::TryLockForReading( void )
    {
        std::lock_guard< std::recursive_mutex > l( this->impl->_rrmtx );
        bool                                    r;
        
        if( this->impl->_r == 0 )
        {
            r = this->impl->_wrmtx.try_lock();
        }
        else
        {
            r = true;
        }
        
        if( r )
        {
            this->impl->_r++;
        }
        
        return r;
    }
    
    bool RWLock::TryLockForWriting( void )
    {
        return this->impl->_wrmtx.try_lock();;
    }
    
    PIMPL::Object< RWLock >::IMPL::IMPL( void ):
        _r( 0 )
    {}
    
    PIMPL::Object< RWLock >::IMPL::IMPL( const IMPL & o ):
        _r( 0 )
    {
        ( void )o;
    }
    
    PIMPL::Object< RWLock >::IMPL::~IMPL( void )
    {}
}
