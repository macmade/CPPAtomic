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

/* Disabled warnings for GoogleMock */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic push
#if __clang_major__ >= 7
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wused-but-marked-unused"
#pragma clang diagnostic ignored "-Wdeprecated"
#endif

#include <GoogleMock/GoogleMock.h>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <XS/Atomic.hpp>

using namespace testing;

TEST( XS_Atomic_Static, Increment )
{
    int32_t  i32 = 0;
    uint32_t u32 = 0;
    int64_t  i64 = 0;
    uint64_t u64 = 0;
    
    ASSERT_EQ( XS::Atomic< int32_t  >::Increment( &i32 ), static_cast< int32_t  >( 1 ) );
    ASSERT_EQ( XS::Atomic< uint32_t >::Increment( &u32 ), static_cast< uint32_t >( 1 ) );
    ASSERT_EQ( XS::Atomic< int64_t  >::Increment( &i64 ), static_cast< int64_t  >( 1 ) );
    ASSERT_EQ( XS::Atomic< uint64_t >::Increment( &u64 ), static_cast< uint64_t >( 1 ) );
    
    ASSERT_EQ( i32, static_cast< int32_t  >( 1 ) );
    ASSERT_EQ( u32, static_cast< uint32_t >( 1 ) );
    ASSERT_EQ( i64, static_cast< int64_t  >( 1 ) );
    ASSERT_EQ( u64, static_cast< uint64_t >( 1 ) );
}

TEST( XS_Atomic_Static, Decrement )
{
    int32_t  i32 = 0;
    uint32_t u32 = 0;
    int64_t  i64 = 0;
    uint64_t u64 = 0;
    
    ASSERT_EQ( XS::Atomic< int32_t  >::Decrement( &i32 ), static_cast< int32_t  >( -1 ) );
    ASSERT_EQ( XS::Atomic< uint32_t >::Decrement( &u32 ), static_cast< uint32_t >( -1 ) );
    ASSERT_EQ( XS::Atomic< int64_t  >::Decrement( &i64 ), static_cast< int64_t  >( -1 ) );
    ASSERT_EQ( XS::Atomic< uint64_t >::Decrement( &u64 ), static_cast< uint64_t >( -1 ) );
    
    ASSERT_EQ( i32, static_cast< int32_t  >( -1 ) );
    ASSERT_EQ( u32, static_cast< uint32_t >( -1 ) );
    ASSERT_EQ( i64, static_cast< int64_t  >( -1 ) );
    ASSERT_EQ( u64, static_cast< uint64_t >( -1 ) );
}

TEST( XS_Atomic_Static, Add )
{
    int32_t  i32 = 0;
    uint32_t u32 = 0;
    int64_t  i64 = 0;
    uint64_t u64 = 0;
    
    ASSERT_EQ( XS::Atomic< int32_t  >::Add( 2, &i32 ), static_cast< int32_t  >( 2 ) );
    ASSERT_EQ( XS::Atomic< uint32_t >::Add( 2, &u32 ), static_cast< uint32_t >( 2 ) );
    ASSERT_EQ( XS::Atomic< int64_t  >::Add( 2, &i64 ), static_cast< int64_t  >( 2 ) );
    ASSERT_EQ( XS::Atomic< uint64_t >::Add( 2, &u64 ), static_cast< uint64_t >( 2 ) );
    
    ASSERT_EQ( i32, static_cast< int32_t  >( 2 ) );
    ASSERT_EQ( u32, static_cast< uint32_t >( 2 ) );
    ASSERT_EQ( i64, static_cast< int64_t  >( 2 ) );
    ASSERT_EQ( u64, static_cast< uint64_t >( 2 ) );
}

TEST( XS_Atomic_Static, CompareAndSwap )
{
    int32_t  i32 = 0;
    uint32_t u32 = 0;
    int64_t  i64 = 0;
    uint64_t u64 = 0;
    void   * p   = nullptr;
    
    ASSERT_FALSE( XS::Atomic< int32_t  >::CompareAndSwap( 1, 2, &i32 ) );
    ASSERT_FALSE( XS::Atomic< uint32_t >::CompareAndSwap( 1, 2, &u32 ) );
    ASSERT_FALSE( XS::Atomic< int64_t  >::CompareAndSwap( 1, 2, &i64 ) );
    ASSERT_FALSE( XS::Atomic< uint64_t >::CompareAndSwap( 1, 2, &u64 ) );
    ASSERT_FALSE( XS::Atomic< void *   >::CompareAndSwap( reinterpret_cast< void * >( 1 ), reinterpret_cast< void * >( 2 ), reinterpret_cast< void * volatile * >( &p ) ) );
    
    ASSERT_TRUE( XS::Atomic< int32_t  >::CompareAndSwap( 0, 2, &i32 ) );
    ASSERT_TRUE( XS::Atomic< uint32_t >::CompareAndSwap( 0, 2, &u32 ) );
    ASSERT_TRUE( XS::Atomic< int64_t  >::CompareAndSwap( 0, 2, &i64 ) );
    ASSERT_TRUE( XS::Atomic< uint64_t >::CompareAndSwap( 0, 2, &u64 ) );
    ASSERT_TRUE( XS::Atomic< void *   >::CompareAndSwap( reinterpret_cast< void * >( 0 ), reinterpret_cast< void * >( 2 ), reinterpret_cast< void * volatile * >( &p ) ) );
    
    ASSERT_EQ( i32, static_cast< int32_t  >( 2 ) );
    ASSERT_EQ( u32, static_cast< uint32_t >( 2 ) );
    ASSERT_EQ( i64, static_cast< int64_t  >( 2 ) );
    ASSERT_EQ( u64, static_cast< uint64_t >( 2 ) );
    ASSERT_EQ( p, reinterpret_cast< void * >( 2 ) );
}
