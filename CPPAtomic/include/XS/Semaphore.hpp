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

#ifndef XS_SEMAPHORE_HPP
#define XS_SEMAPHORE_HPP

#include <XS/PIMPL/Object.hpp>
#include <string>

namespace XS
{
    class Semaphore: public XS::PIMPL::Object< Semaphore >
    {
        public:
            
            using XS::PIMPL::Object< Semaphore >::impl;
            
            Semaphore( unsigned int count = 1, std::string name = "" );
            
            Semaphore( const Semaphore & o )      = delete;
            Semaphore( Semaphore && o )           = delete;
            Semaphore & operator =( Semaphore o ) = delete;
            
            bool TryWait( void );
            void Wait( void );
            void Signal( void );
            
            bool        IsNamed( void ) const;
            std::string GetName( void ) const;
    };
}

#endif /* XS_SEMAPHORE_HPP */
