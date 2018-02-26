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

#include <XS/IPC/SharedMemory.hpp>
#include <XS/CrashGuard.hpp>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#endif

#include <mutex>
#include <functional>
#include <vector>

static std::recursive_mutex                   * rmtx        = nullptr;
static std::vector< XS::IPC::SharedMemory * > * memoryAreas = nullptr;

namespace XS
{
    template<>
    class XS::PIMPL::Object< IPC::SharedMemory >::IMPL
    {
        public:
            
            IMPL( void );
            IMPL( key_t key, size_t size );
            IMPL( const IMPL & o );
            ~IMPL( void );
            
            void AcquireMemory( void );
            void ReleaseMemory( void );
            
            void * _p;
            size_t _size;
            
            #ifdef _WIN32
            
            
            
            #else
            
            key_t _key;
            
            #endif
    };
}

#define XS_PIMPL_CLASS XS::IPC::SharedMemory
#include <XS/PIMPL/Object-IMPL.hpp>

namespace XS
{
    namespace IPC
    {
        SharedMemory::SharedMemory( void ):
            XS::PIMPL::Object< SharedMemory >()
        {}
        
        SharedMemory::SharedMemory( int32_t key, size_t size ):
            XS::PIMPL::Object< SharedMemory >( key, size )
        {}
        
        bool SharedMemory::operator ==( const SharedMemory & o ) const
        {
            if( this->impl->_p == nullptr || o.impl->_p == nullptr )
            {
                return false;
            }
            
            if( this->impl->_size != o.impl->_size )
            {
                return false;
            }
            
            if( this->impl->_key != o.impl->_key )
            {
                return false;
            }
            
            return true;
        }
        
        bool SharedMemory::operator !=( const SharedMemory & o ) const
        {
            return !operator ==( o );
        }
        
        void * SharedMemory::Get( void ) const
        {
            return this->impl->_p;
        }
        
        size_t SharedMemory::GetSize( void ) const
        {
            return this->impl->_size;
        }
        
        bool SharedMemory::IsValid( void ) const
        {
            return this->impl->_p != nullptr;
        }
    }
    
    PIMPL::Object< IPC::SharedMemory >::IMPL::IMPL( void ):
        _p( nullptr ),
        _size( 0 ),
        _key( 0 )
    {}
    
    PIMPL::Object< IPC::SharedMemory >::IMPL::IMPL( key_t key, size_t size ):
        _p( nullptr ),
        _size( size ),
        _key( key )
    {
        static std::once_flag once;
        
        std::call_once
        (
            once,
            []
            {
                rmtx        = new std::recursive_mutex();
                memoryAreas = new std::vector< XS::IPC::SharedMemory * >();
                
                XS::CrashGuard::InstallHandler
                (
                    []
                    {
                        for( auto m: *( memoryAreas ) )
                        {
                            m->impl->ReleaseMemory();
                        }
                        
                        memoryAreas->clear();
                    }
                );
            }
        );
        
        this->AcquireMemory();
    }

    PIMPL::Object< IPC::SharedMemory >::IMPL::IMPL( const IMPL & o ):
        _p( nullptr ),
        _size( o._size ),
        _key( o._key )
    {
        this->AcquireMemory();
    }

    PIMPL::Object< IPC::SharedMemory >::IMPL::~IMPL( void )
    {
        this->ReleaseMemory();
    }
    
    #ifdef _WIN32
    
    void PIMPL::Object< IPC::SharedMemory >::IMPL::AcquireMemory( void )
    {}
    
    void PIMPL::Object< IPC::SharedMemory >::IMPL::ReleaseMemory( void )
    {}
    
    #else
    
    void PIMPL::Object< IPC::SharedMemory >::IMPL::AcquireMemory( void )
    {
        int    id;
        void * p;
        
        id = shmget( this->_key, this->_size, IPC_CREAT | 0666 );
        
        if( id < 0 )
        {
            return;
        }
        
        p = shmat( id, NULL, 0 );
        
        if( p == reinterpret_cast< char * >( -1 ) )
        {
            return;
        }
        
        this->_p = p;
    }
    
    void PIMPL::Object< IPC::SharedMemory >::IMPL::ReleaseMemory( void )
    {
        if( this->_p == nullptr )
        {
            return;
        }
        
        if( shmdt( this->_p ) == -1 )
        {
            return;
        }
        
        shmctl( this->_key, IPC_RMID, 0 );
    }
    
    #endif
}
