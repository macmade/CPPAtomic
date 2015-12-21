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

/*******************************************************************************
 * Common definitions
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Pointer, CTOR )
{
    XS::Atomic< const char * > a;
    
    ASSERT_TRUE( a == nullptr );
}

TEST( XS_Atomic_Trivial_Pointer, CTOR_V )
{
    XS::Atomic< const char * > a{ "hello, world" };
    
    ASSERT_TRUE( strcmp( a, "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, CCTOR )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ a1 };
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, OperatorAssign )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, OperatorAssign_V )
{
    XS::Atomic< const char * > a;
    
    a = "hello, world";
    
    ASSERT_TRUE( strcmp( a, "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, OperatorCast )
{
    XS::Atomic< const char * > a{ "hello, world" };
    
    ASSERT_TRUE( strcmp( static_cast< const char * >( a ), "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, Load )
{
    XS::Atomic< const char * > a{ "hello, world" };
    
    ASSERT_TRUE( strcmp( a.Load(), "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, Store )
{
    XS::Atomic< const char * > a;
    
    a.Store( "hello, world" );
    
    ASSERT_TRUE( strcmp( a.Load(), "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, Swap )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ "hello, universe" };
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "hello, universe" ) == 0 );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( strcmp( a1, "hello, universe" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "hello, world" ) == 0 );
}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Pointer, PreIncrementOperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    
    a2 = ++a1;
    
    ASSERT_TRUE( strcmp( a1, "ello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "ello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, PreDecrementOperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    
    a2 = ++a1;
    
    ASSERT_TRUE( strcmp( a1, "ello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "ello, world" ) == 0 );
    
    a2 = --a1;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "hello, world" ) == 0 );

}

TEST( XS_Atomic_Trivial_Pointer, PostIncrementOperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    
    a2 = a1++;
    
    ASSERT_TRUE( strcmp( a1, "ello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "hello, world" ) == 0 );
}

TEST( XS_Atomic_Trivial_Pointer, PostDecrementOperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    
    a2 = ++a1;
    
    ASSERT_TRUE( strcmp( a1, "ello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "ello, world" ) == 0 );
    
    a2 = a1--;
    
    ASSERT_TRUE( strcmp( a1, "hello, world" ) == 0 );
    ASSERT_TRUE( strcmp( a2, "ello, world" ) == 0 );

}

TEST( XS_Atomic_Trivial_Pointer, NegationOperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ nullptr };
    
    ASSERT_FALSE( !a1 );
    ASSERT_TRUE(  !a2 ); 
}

TEST( XS_Atomic_Trivial_Pointer, ANDOperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ "hello, universe" };
    XS::Atomic< const char * > a3{ nullptr };
    XS::Atomic< const char * > a4{ nullptr };
    
    ASSERT_TRUE(  a1 && a2 );
    ASSERT_FALSE( a1 && a3 );
    ASSERT_FALSE( a3 && a1 );
    ASSERT_FALSE( a3 && a4 );
}

TEST( XS_Atomic_Trivial_Pointer, ANDOperator_V )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ nullptr };
    
    ASSERT_TRUE(  a1 && "hello, universe" );
    ASSERT_FALSE( a1 && a2 );
    ASSERT_FALSE( a2 && a1 );
    ASSERT_FALSE( a2 && nullptr );
}

TEST( XS_Atomic_Trivial_Pointer, InclusiveOROperator )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ "hello, universe" };
    XS::Atomic< const char * > a3{ nullptr };
    XS::Atomic< const char * > a4{ nullptr };
    
    ASSERT_TRUE(  a1 || a2 );
    ASSERT_TRUE(  a1 || a3 );
    ASSERT_TRUE(  a3 || a1 );
    ASSERT_FALSE( a3 || a4 );
}

TEST( XS_Atomic_Trivial_Pointer, InclusiveOROperator_V )
{
    XS::Atomic< const char * > a1{ "hello, world" };
    XS::Atomic< const char * > a2{ nullptr };
    
    ASSERT_TRUE(  a1 || "hello, universe" );
    ASSERT_TRUE(  a1 || a2 );
    ASSERT_TRUE(  a2 || a1 );
    ASSERT_FALSE( a2 || nullptr );
}

TEST( XS_Atomic_Trivial_Pointer, EqualToOperator )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ "hello, universe" };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p1 };
    XS::Atomic< const char * > a3{ p2 };
    
    ASSERT_TRUE(  a1 == a2 );
    ASSERT_FALSE( a1 == a3 );
}

TEST( XS_Atomic_Trivial_Pointer, EqualToOperator_V )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ "hello, universe" };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    
    ASSERT_TRUE(  a1 == p1 );
    ASSERT_FALSE( a1 == p2 );
}

TEST( XS_Atomic_Trivial_Pointer, NotEqualToOperator )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ "hello, universe" };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p1 };
    XS::Atomic< const char * > a3{ p2 };
    
    ASSERT_FALSE( a1 != a2 );
    ASSERT_TRUE(  a1 != a3 );
}

TEST( XS_Atomic_Trivial_Pointer, NotEqualToOperator_V )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ "hello, universe" };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    
    ASSERT_FALSE( a1 != p1 );
    ASSERT_TRUE(  a1 != p2 );
}

TEST( XS_Atomic_Trivial_Pointer, LessThanOperator )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p1 };
    XS::Atomic< const char * > a3{ p2 };
    
    ASSERT_FALSE( a1 < a2 );
    ASSERT_TRUE(  a1 < a3 );
}

TEST( XS_Atomic_Trivial_Pointer, LessThanOperator_V )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    
    ASSERT_FALSE( a1 < p1 );
    ASSERT_TRUE(  a1 < p2 );
}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOperator )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p1 };
    XS::Atomic< const char * > a3{ p2 };
    
    ASSERT_FALSE( a1 > a2 );
    ASSERT_TRUE(  a3 > a1 );
}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOperator_V )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    
    ASSERT_FALSE( a1 > p2 );
    ASSERT_TRUE(  a2 > p1 );
}

TEST( XS_Atomic_Trivial_Pointer, LessThanOrEqualToOperator )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p1 };
    XS::Atomic< const char * > a3{ p2 };
    
    ASSERT_TRUE(  a1 <= a2 );
    ASSERT_TRUE(  a1 <= a3 );
    ASSERT_FALSE( a3 <= a1 );
}

TEST( XS_Atomic_Trivial_Pointer, LessThanOrEqualToOperator_V )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    
    ASSERT_TRUE(  a1 <= p1 );
    ASSERT_TRUE(  a1 <= p2 );
    ASSERT_FALSE( a2 <= p1 );
}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOrEqualToOperator )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    XS::Atomic< const char * > a3{ p2 };
    
    ASSERT_FALSE( a1 >= a2 );
    ASSERT_TRUE(  a2 >= a1 );
    ASSERT_TRUE(  a2 >= a3 );
}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOrEqualToOperator_V )
{
    const char               * p1{ "hello, world" };
    const char               * p2{ p1 + 1 };
    XS::Atomic< const char * > a1{ p1 };
    XS::Atomic< const char * > a2{ p2 };
    
    ASSERT_FALSE( a1 >= p2 );
    ASSERT_TRUE(  a2 >= p1 );
    ASSERT_TRUE(  a2 >= p2 );
}
