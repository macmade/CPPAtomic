/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com
 * @brief       Test case XS::Atomic
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

TEST( XS_Atomic_Trivial_Struct, IsLockFree )
{
    XS::Atomic< P > a;
    
    ASSERT_TRUE( a.IsLockFree() );
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
}
