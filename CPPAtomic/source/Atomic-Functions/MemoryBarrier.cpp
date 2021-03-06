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

#ifdef _WIN32
#include <Windows.h>
#endif

namespace XS
{
    #ifdef MemoryBarrier
    #undef MemoryBarrier /* VisualStudio x64 */
    #endif
    void MemoryBarrier( void )
    {
        #if defined( _WIN64 ) && defined( _M_AMD64 )

        ::__faststorefence();
        
        #elif defined( _WIN32 ) && defined( _M_IX86 )
        
        __asm mfence;

        #elif defined( _WIN32 ) && defined( _M_ARM )

        __asm dmb sy;

        #elif defined( __ARM_ARCH )

        __asm__ __volatile__
        (
            "dmb sy"
        );
        
        #elif defined( __i386__ ) || defined( __x86_64__ )
        
            __asm__ __volatile__
            (
                "mfence"
            );
            
        #else
        
        #error "XS::MemoryBarrier is not implemented for the current target architecture"
        
        #endif
    }
}
