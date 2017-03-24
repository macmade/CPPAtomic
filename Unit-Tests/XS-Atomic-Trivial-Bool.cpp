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
             
TEST( XS_Atomic_Trivial_Bool, CTOR )
{
    XS::Atomic< bool > a;
    
    ASSERT_TRUE( a == false );
}

TEST( XS_Atomic_Trivial_Bool, CTOR_V )
{
    XS::Atomic< bool > a1{ true };
    XS::Atomic< bool > a2{ false };
    
    ASSERT_TRUE( a1 == true );
    ASSERT_TRUE( a2 == false );
}

TEST( XS_Atomic_Trivial_Bool, CCTOR )
{
    XS::Atomic< bool > a1{ true };
    XS::Atomic< bool > a2{ a1 };
    
    ASSERT_TRUE( a1 == true );
    ASSERT_TRUE( a2 == true );
}

TEST( XS_Atomic_Trivial_Bool, OperatorAssign )
{
    XS::Atomic< bool > a1{ true };
    XS::Atomic< bool > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( a1 == true );
    ASSERT_TRUE( a2 == true );
    
    a1 = a1;
    
    ASSERT_TRUE( a1 == true );
}

TEST( XS_Atomic_Trivial_Bool, OperatorAssign_V )
{
    XS::Atomic< bool > a;
    
    a = true;
    
    ASSERT_TRUE( a == true );
}

TEST( XS_Atomic_Trivial_Bool, OperatorCast )
{
    XS::Atomic< bool > a1{ true };
    XS::Atomic< bool > a2{ false };
    
    ASSERT_TRUE( static_cast< bool >( a1 ) == true );
    ASSERT_TRUE( static_cast< bool >( a2 ) == false );
}

TEST( XS_Atomic_Trivial_Bool, Load )
{
    XS::Atomic< bool > a1{ true };
    XS::Atomic< bool > a2{ false };
    
    ASSERT_TRUE( a1.Load() == true );
    ASSERT_TRUE( a2.Load() == false );
}

TEST( XS_Atomic_Trivial_Bool, Store )
{
    XS::Atomic< bool > a;
    
    a.Store( true );
    
    ASSERT_TRUE( a == true );
}

TEST( XS_Atomic_Trivial_Bool, Swap )
{
    XS::Atomic< bool > a1{ true };
    XS::Atomic< bool > a2{ false };
    
    ASSERT_TRUE( a1 == true );
    ASSERT_TRUE( a2 == false );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( a1 == false );
    ASSERT_TRUE( a2 == true );
    
    swap( a1, a1 );
    
    ASSERT_TRUE( a1 == false );
}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Bool, NegationOperator )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ true };
    
    ASSERT_TRUE(  !a1 );
    ASSERT_FALSE( !a2 );
}

TEST( XS_Atomic_Trivial_Bool, ANDOperator )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ false };
    XS::Atomic< bool > a3{ true };
    XS::Atomic< bool > a4{ true };
    
    ASSERT_FALSE( a1 && a2 );
    ASSERT_FALSE( a1 && a3 );
    ASSERT_TRUE(  a3 && a4 );
    ASSERT_FALSE( a3 && a1 );
}

TEST( XS_Atomic_Trivial_Bool, ANDOperator_V )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ true };
    
    ASSERT_FALSE( a1 && false );
    ASSERT_FALSE( a1 && true );
    ASSERT_TRUE(  a2 && true );
    ASSERT_FALSE( a2 && false );
}

TEST( XS_Atomic_Trivial_Bool, InclusiveOROperator )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ false };
    XS::Atomic< bool > a3{ true };
    XS::Atomic< bool > a4{ true };
    
    ASSERT_FALSE( a1 || a2 );
    ASSERT_TRUE(  a1 || a3 );
    ASSERT_TRUE(  a3 || a4 );
    ASSERT_TRUE(  a3 || a1 );
}

TEST( XS_Atomic_Trivial_Bool, InclusiveOROperator_V )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ true };
    
    ASSERT_FALSE( a1 || false );
    ASSERT_TRUE(  a1 || true );
    ASSERT_TRUE(  a2 || true );
    ASSERT_TRUE(  a2 || false );
}

TEST( XS_Atomic_Trivial_Bool, EqualToOperator )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ false };
    XS::Atomic< bool > a3{ true };
    XS::Atomic< bool > a4{ true };
    
    ASSERT_TRUE(  a1 == a2 );
    ASSERT_FALSE( a1 == a3 );
    ASSERT_TRUE(  a3 == a4 );
    ASSERT_FALSE( a3 == a1 );
}

TEST( XS_Atomic_Trivial_Bool, EqualToOperator_V )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ true };
    
    ASSERT_TRUE(  a1 == false );
    ASSERT_FALSE( a1 == true );
    ASSERT_TRUE(  a2 == true );
    ASSERT_FALSE( a2 == false );
}

TEST( XS_Atomic_Trivial_Bool, NotEqualToOperator )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ false };
    XS::Atomic< bool > a3{ true };
    XS::Atomic< bool > a4{ true };
    
    ASSERT_FALSE( a1 != a2 );
    ASSERT_TRUE(  a1 != a3 );
    ASSERT_FALSE( a3 != a4 );
    ASSERT_TRUE(  a3 != a1 );
}

TEST( XS_Atomic_Trivial_Bool, NotEqualToOperator_V )
{
    XS::Atomic< bool > a1{ false };
    XS::Atomic< bool > a2{ true };
    
    ASSERT_FALSE( a1 != false );
    ASSERT_TRUE(  a1 != true );
    ASSERT_FALSE( a2 != true );
    ASSERT_TRUE(  a2 != false );
}
