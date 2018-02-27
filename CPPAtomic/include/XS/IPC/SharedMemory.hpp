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

#ifndef XS_IPC_SHARED_MEMORY_HPP
#define XS_IPC_SHARED_MEMORY_HPP

#include <XS/PIMPL/Object.hpp>
#include <string>
#include <cstdint>

namespace XS
{
    namespace IPC
    {
        class SharedMemory: public XS::PIMPL::Object< SharedMemory >
        {
            public:
                
                using XS::PIMPL::Object< SharedMemory >::impl;
                
                SharedMemory( void );
                SharedMemory( int32_t key, size_t size );
                
                bool operator ==( const SharedMemory & o ) const;
                bool operator !=( const SharedMemory & o ) const;
                
                void * Get( void )     const;
                size_t GetSize( void ) const;
                bool   IsValid( void ) const;
                
                template< typename _T_ >
                _T_ Get( void ) const
                {
                    return reinterpret_cast< _T_ >( this->Get() );
                }
        };
    }
}

#endif /* XS_IPC_SHARED_MEMORY_HPP */
