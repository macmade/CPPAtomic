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

#include <XS/IPC/Semaphore.hpp>

#ifdef __APPLE__
#include <sys/semaphore.h>
#include <fcntl.h>
#include <mach/mach_init.h>
#include <mach/task.h>
#include <mach/semaphore.h>
#else
#include <Windows.h>
#include <locale>
#include <codecvt>
#endif

#ifndef SEM_NAME_MAX
#define SEM_NAME_MAX    32
#endif

namespace XS
{
    template<>
    class XS::PIMPL::Object< IPC::Semaphore >::IMPL
    {
        public:
            
            IMPL( unsigned int count = 1, std::string name = "" );
            IMPL( const IMPL & o );
            ~IMPL( void );
            
            void CreateSemaphore( void );
            void DeleteSemaphore( void );
            
            unsigned int _count;
            std::string  _name;
            
            #if defined( _WIN32 )
            
            HANDLE _semaphore;
            
            #elif defined( __APPLE__ )
            
            sem_t      * _semp;
            semaphore_t  _semaphore;
            
            #else
            #error "Unsupported platform"
            #endif
    };
}

#define XS_PIMPL_CLASS XS::IPC::Semaphore
#include <XS/PIMPL/Object-IMPL.hpp>

namespace XS
{
    namespace IPC
    {
        /***************************************************************************
         * Common
         **************************************************************************/
        
        Semaphore::Semaphore( unsigned int count, std::string name ):
            XS::PIMPL::Object< Semaphore >( count, name )
        {}
        
        bool Semaphore::IsNamed( void ) const
        {
            return this->impl->_name.length() > 0;
        }
        
        std::string Semaphore::GetName( void ) const
        {
            return this->impl->_name;
        }
        
        /***************************************************************************
         * Windows specific
         **************************************************************************/
        
        #if defined( _WIN32 )
        
        bool Semaphore::TryWait( void )
        {
            return ( WaitForSingleObject( this->impl->_semaphore, 0 ) == WAIT_OBJECT_0 ) ? true : false;
        }
        
        void Semaphore::Wait( void )
        {
            WaitForSingleObject( this->impl->_semaphore, INFINITE );
        }
        
        void Semaphore::Signal( void )
        {
            ReleaseSemaphore( this->impl->_semaphore, 1, nullptr );
        }
        
        /***************************************************************************
         * Apple specific
         **************************************************************************/
        
        #elif defined( __APPLE__ )
        
        bool Semaphore::TryWait( void )
        {
            if( this->IsNamed() )
            {
                return ( sem_trywait( this->impl->_semp ) == 0 ) ? true : false;
            }
            else
            {
                {
                    mach_timespec_t ts;
                    
                    ts.tv_sec  = 0;
                    ts.tv_nsec = 0;
                    
                    return ( semaphore_timedwait( this->impl->_semaphore, ts ) == KERN_SUCCESS ) ? true : false;
                }
            }
        }
        
        void Semaphore::Wait( void )
        {
            if( this->IsNamed() )
            {
                sem_wait( this->impl->_semp );
            }
            else
            {
                semaphore_wait( this->impl->_semaphore );
            }
        }
        
        void Semaphore::Signal( void )
        {
            if( this->IsNamed() )
            {
                sem_post( this->impl->_semp );
            }
            else
            {
                semaphore_signal( this->impl->_semaphore );
            }
        }
        
        #endif
    }
    
    /***************************************************************************
     * Common
     **************************************************************************/
    
    PIMPL::Object< IPC::Semaphore >::IMPL::IMPL( unsigned int count, std::string name ):
        _count( count ),
        _name( name )
    {
        this->CreateSemaphore();
    }

    PIMPL::Object< IPC::Semaphore >::IMPL::IMPL( const IMPL & o ):
        _count( o._count ),
        _name( o._name )
    {
        this->CreateSemaphore();
    }

    PIMPL::Object< IPC::Semaphore >::IMPL::~IMPL( void )
    {
        this->DeleteSemaphore();
    }
    
    /***************************************************************************
     * Windows specific
     **************************************************************************/
    
    #ifdef _WIN32
      
    void PIMPL::Object< IPC::Semaphore >::IMPL::CreateSemaphore( void )
    {
        if( this->_count == 0 )
        {
            throw std::runtime_error( "Cannot initialize a semaphore with zero as count" );
        }
        
        if( this->_name.length() > 0 )
        {
            {
                std::wstring name;
                std::wstring_convert< std::codecvt_utf8_utf16< wchar_t > > converter;

                name             = converter.from_bytes( this->_name );
                this->_semaphore = ::CreateSemaphore( nullptr, static_cast< LONG >( this->_count ), static_cast< LONG >( this->_count ), name.c_str() );
            }
        }
        else
        {
            this->_semaphore = ::CreateSemaphore( nullptr, static_cast< LONG >( this->_count ), static_cast< LONG >( this->_count ), nullptr );
        }
        
        if( this->_semaphore == nullptr )
        {
            throw std::runtime_error( "Error initializing the semaphore object" );
        }
    }
    
    void PIMPL::Object< IPC::Semaphore >::IMPL::DeleteSemaphore( void )
    {
        CloseHandle( this->_semaphore );
    }
    
    /***************************************************************************
     * Apple specific
     **************************************************************************/
    
    #elif defined( __APPLE__ )
        
    void PIMPL::Object< IPC::Semaphore >::IMPL::CreateSemaphore( void )
    {
        if( this->_name.length() > 0 && this->_name[ 0 ] != '/' )
        {
            this->_name = std::string( "/" ) + this->_name;
        }
        
        if( this->_name.length() > SEM_NAME_MAX )
        {
            throw std::runtime_error( std::string( "Cannot initialize a semaphore with a name longer than " + std::to_string( SEM_NAME_MAX ) ) + " characters" );
        }
        
        if( this->_count == 0 )
        {
            throw std::runtime_error( "Cannot initialize a semaphore with zero as count" );
        }
        
        if( this->_name.length() > 0 )
        {
            this->_semp = sem_open( this->_name.c_str(), O_CREAT, S_IRUSR | S_IWUSR, this->_count );
            
            if( this->_semp == nullptr || this->_semp == SEM_FAILED )
            {
                throw std::runtime_error( "Error initializing the semaphore object" );
            }
        }
        else if( semaphore_create( mach_task_self(), &( this->_semaphore ), SYNC_POLICY_FIFO, static_cast< int >( this->_count ) ) != KERN_SUCCESS )
        {
            throw std::runtime_error( "Error initializing the semaphore object" );
        }
    }
    
    void PIMPL::Object< IPC::Semaphore >::IMPL::DeleteSemaphore( void )
    {
        if( this->_name.length() > 0 )
        {
            sem_close( this->_semp );
        }
        else
        {
            semaphore_destroy( mach_task_self(), this->_semaphore );
        }
    }
    
    #endif
}
