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

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>

TEST( XS_Atomic_Functions, AtomicIncrement32 )
{
    int32_t i = 0;
    
    ASSERT_EQ( XS::AtomicIncrement32( &i ), 1 );
    ASSERT_EQ( i, 1 );
}

TEST( XS_Atomic_Functions, AtomicIncrement64 )
{
    int64_t i = 0;
    
    ASSERT_EQ( XS::AtomicIncrement64( &i ), 1 );
    ASSERT_EQ( i, 1 );
}

TEST( XS_Atomic_Functions, AtomicDecrement32 )
{
    int32_t i = 0;
    
    ASSERT_EQ( XS::AtomicDecrement32( &i ), -1 );
    ASSERT_EQ( i, -1 );
}

TEST( XS_Atomic_Functions, AtomicDecrement64 )
{
    int64_t i = 0;
    
    ASSERT_EQ( XS::AtomicDecrement64( &i ), -1 );
    ASSERT_EQ( i, -1 );
}

TEST( XS_Atomic_Functions, AtomicAdd32 )
{
    int32_t i = 0;
    
    ASSERT_EQ( XS::AtomicAdd32( 2, &i ), 2 );
    ASSERT_EQ( i, 2 );
}

TEST( XS_Atomic_Functions, AtomicAdd64 )
{
    int64_t i = 0;
    
    ASSERT_EQ( XS::AtomicAdd64( 2, &i ), 2 );
    ASSERT_EQ( i, 2 );
}

TEST( XS_Atomic_Functions, AtomicCompareAndSwap32 )
{
    int32_t i = 0;
    
    ASSERT_FALSE( XS::AtomicCompareAndSwap32( 1, 2, &i ) );
    ASSERT_TRUE(  XS::AtomicCompareAndSwap32( 0, 2, &i ) );
    ASSERT_EQ( i, 2 );
}

TEST( XS_Atomic_Functions, AtomicCompareAndSwap64 )
{
    int64_t i = 0;
    
    ASSERT_FALSE( XS::AtomicCompareAndSwap64( 1, 2, &i ) );
    ASSERT_TRUE(  XS::AtomicCompareAndSwap64( 0, 2, &i ) );
    ASSERT_EQ( i, 2 );
}

TEST( XS_Atomic_Functions, AtomicCompareAndSwapPointer )
{
    void * p = nullptr;
    
    ASSERT_FALSE( XS::AtomicCompareAndSwapPointer( reinterpret_cast< void * >( 1 ), reinterpret_cast< void * >( 2 ), reinterpret_cast< void * volatile * >( &p ) ) );
    ASSERT_TRUE(  XS::AtomicCompareAndSwapPointer( reinterpret_cast< void * >( 0 ), reinterpret_cast< void * >( 2 ), reinterpret_cast< void * volatile * >( &p ) ) );
    ASSERT_EQ( p, reinterpret_cast< void * >( 2 ) );
}

TEST( XS_Atomic_Functions, MemoryBarrier )
{
    XS::MemoryBarrier();
}
