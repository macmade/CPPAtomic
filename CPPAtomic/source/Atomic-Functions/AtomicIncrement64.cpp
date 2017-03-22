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

#include <XS/Atomic-Functions.hpp>

#if defined( _WIN32 )

#include <Windows.h>
#include <Winnt.h>

#elif defined( __APPLE__ )

#include <libkern/OSAtomic.h>

#endif

namespace XS
{
    int64_t AtomicIncrement64( volatile int64_t * value )
    {
        #if defined( _WIN32 )
        
        return InterlockedIncrement64( reinterpret_cast< volatile LONGLONG * >( value ) );

        #elif defined( __APPLE__ )
        
        return OSAtomicIncrement64( value );

        #elif __has_builtin( __sync_add_and_fetch )
        
        return __sync_add_and_fetch( value, 1 );
        
        #else
        
        #error "XS::Atomic::Increment64 is not implemented for the current platform"
        
        #endif
    }
}
