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
 * @brief       Test case XS::Atomic
 */

#include <XS/Atomic.hpp>

/* SDK version 10.11 solves issues when using a struct with std::atomic */
#if !defined( __APPLE__ ) || defined( MAC_OS_X_VERSION_10_11 )

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>

typedef struct
{
    int x;
    int y;
}
P;

static bool IsP( P p, int x, int y );
static bool IsP( P p, int x, int y )
{
    return p.x == x && p.y == y;
}

/*******************************************************************************
 * Common definitions
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Struct, CTOR )
{
    XS::Atomic< P > a;
    
    ASSERT_TRUE( IsP( a, 0, 0 ) );
}

TEST( XS_Atomic_Trivial_Struct, CTOR_V )
{
    XS::Atomic< P > a{ { 42, 43 } };
    
    ASSERT_TRUE( IsP( a, 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, CCTOR )
{
    XS::Atomic< P > a1{ { 42, 43 } };
    XS::Atomic< P > a2{ a1 };
    
    ASSERT_TRUE( IsP( a1, 42, 43 ) );
    ASSERT_TRUE( IsP( a2, 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, OperatorAssign )
{
    XS::Atomic< P > a1{ { 42, 43 } };
    XS::Atomic< P > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( IsP( a1, 42, 43 ) );
    ASSERT_TRUE( IsP( a2, 42, 43 ) );
    
    #ifdef __clang__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wself-assign-overloaded"
    #endif
    a1 = a1;
    #ifdef __clang__
    #pragma clang diagnostic pop
    #endif
    
    ASSERT_TRUE( IsP( a1, 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, OperatorAssign_V )
{
    XS::Atomic< P > a;
    
    a = { 42, 43 };
    
    ASSERT_TRUE( IsP( a, 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, OperatorCast )
{
    XS::Atomic< P > a{ { 42, 43 } };
    
    ASSERT_TRUE( IsP( static_cast< P >( a ), 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, Load )
{
    XS::Atomic< P > a{ { 42, 43 } };
    
    ASSERT_TRUE( IsP( a, 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, Store )
{
    XS::Atomic< P > a;
    
    a.Store( { 42, 43 } );
    
    ASSERT_TRUE( IsP( a, 42, 43 ) );
}

TEST( XS_Atomic_Trivial_Struct, Swap )
{
    XS::Atomic< P > a1{ { 42, 43 } };
    XS::Atomic< P > a2{ { 44, 45 } };
    
    ASSERT_TRUE( IsP( a1, 42, 43 ) );
    ASSERT_TRUE( IsP( a2, 44, 45 ) );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( IsP( a1, 44, 45 ) );
    ASSERT_TRUE( IsP( a2, 42, 43 ) );
    
    swap( a1, a1 );
    
    ASSERT_TRUE( IsP( a1, 44, 45 ) );
}

#endif
