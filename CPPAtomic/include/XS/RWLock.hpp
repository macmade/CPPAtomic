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

#ifndef XS_RW_LOCK_HPP
#define XS_RW_LOCK_HPP

#include <XS/PIMPL/Object.hpp>

namespace XS
{
    class RWLock: public XS::PIMPL::Object< RWLock >
    {
        public:
            
            using XS::PIMPL::Object< RWLock >::impl;
            
            RWLock( void );
            
            RWLock( const RWLock & o )      = delete;
            RWLock( RWLock && o )           = delete;
            RWLock & operator =( RWLock o ) = delete;
            
            void LockForReading( void );
            void LockForWriting( void );
            void UnlockForReading( void );
            void UnlockForWriting( void );
            bool TryLockForReading( void );
            bool TryLockForWriting( void );
    };
}

#endif /* XS_RW_LOCK_HPP */
