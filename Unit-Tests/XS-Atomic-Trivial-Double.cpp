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
#include <cfloat>

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>

#ifdef __clang__
#pragma clang diagnostic ignored "-Wself-assign-overloaded"
#pragma clang diagnostic ignored "-Wfloat-equal"
#endif

static bool DoubleIsEqual( double x, double y );
static bool DoubleIsEqual( double x, double y )
{
    return fabs( x - y ) < DBL_EPSILON;
}

/*******************************************************************************
 * Common definitions
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Double, CTOR )
{
    XS::Atomic< double > a;
    
    ASSERT_TRUE( DoubleIsEqual( a, 0.0 ) );
}

TEST( XS_Atomic_Trivial_Double, CTOR_V )
{
    XS::Atomic< double > a{ 42.0 };
    
    ASSERT_TRUE( DoubleIsEqual( a, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, CCTOR )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ a1 };
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, OperatorAssign )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 42.0 ) );
    
    a1 = a1;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, OperatorAssign_V )
{
    XS::Atomic< double > a;
    
    a = 42.0;
    
    ASSERT_TRUE( DoubleIsEqual( a, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, OperatorCast )
{
    XS::Atomic< double > a{ 42.0 };
    
    ASSERT_TRUE( DoubleIsEqual( static_cast< double >( a ), 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, Load )
{
    XS::Atomic< double > a{ 42.0 };
    
    ASSERT_TRUE( DoubleIsEqual( a.Load(), 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, Store )
{
    XS::Atomic< double > a;
    
    a.Store( 42.0 );
    
    ASSERT_TRUE( DoubleIsEqual( a, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, Swap )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 43.0 };
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 43.0 ) );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( DoubleIsEqual( a1, 43.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 42.0 ) );
    
    swap( a1, a1 );
    
    ASSERT_TRUE( DoubleIsEqual( a1, 43.0 ) );
}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Double, AdditionAssignmentOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    a1 += a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 52.0 ) );
}

TEST( XS_Atomic_Trivial_Double, AdditionAssignmentOperator_V )
{
    XS::Atomic< double > a{ 42.0 };
    
    a += 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a, 52.0 ) );
}

TEST( XS_Atomic_Trivial_Double, SubtractionAssignmentOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    a1 -= a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 32 ) );
}

TEST( XS_Atomic_Trivial_Double, SubtractionAssignmentOperator_V )
{
    XS::Atomic< double > a{ 42.0 };
    
    a -= 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a, 32.0 ) );
}

TEST( XS_Atomic_Trivial_Double, MultiplicationAssignmentOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    a1 *= a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 420.0 ) );
}

TEST( XS_Atomic_Trivial_Double, MultiplicationAssignmentOperator_V )
{
    XS::Atomic< double > a{ 42.0 };
    
    a *= 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a, 420.0 ) );
}

TEST( XS_Atomic_Trivial_Double, DivisionAssignmentOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    a1 /= a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 4.2 ) );
}

TEST( XS_Atomic_Trivial_Double, DivisionAssignmentOperator_V )
{
    XS::Atomic< double > a{ 42.0 };
    
    a /= 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a, 4.2 ) );
}

TEST( XS_Atomic_Trivial_Double, PreIncrementOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = ++a1;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 43.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 43.0 ) );
}

TEST( XS_Atomic_Trivial_Double, PreDecrementOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = --a1;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 41.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 41.0 ) );
}

TEST( XS_Atomic_Trivial_Double, PostIncrementOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1++;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 43.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, PostDecrementOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1--;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 41.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, UnaryPlusOperator )
{
    XS::Atomic< double > a1{  42.0 };
    XS::Atomic< double > a2{ -42.0 };
    XS::Atomic< double > a3;
    XS::Atomic< double > a4;
    
    a3 = +a1;
    a4 = +a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1,  42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, -42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a3,  42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a4, -42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, UnaryMinusOperator )
{
    XS::Atomic< double > a1{  42.0 };
    XS::Atomic< double > a2{ -42.0 };
    XS::Atomic< double > a3;
    XS::Atomic< double > a4;
    
    a3 = -a1;
    a4 = -a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1,  42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, -42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a3, -42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a4,  42.0 ) );
}

TEST( XS_Atomic_Trivial_Double, AdditionOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    XS::Atomic< double > a3;
    
    a3 = a1 + a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 10.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a3, 52.0 ) );
}

TEST( XS_Atomic_Trivial_Double, AdditionOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1 + 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 52.0 ) );
}

TEST( XS_Atomic_Trivial_Double, SubtractionOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    XS::Atomic< double > a3;
    
    a3 = a1 - a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 10.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a3, 32.0 ) );
}

TEST( XS_Atomic_Trivial_Double, SubtractionOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1 - 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 32.0 ) );
}

TEST( XS_Atomic_Trivial_Double, MultiplicationOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    XS::Atomic< double > a3;
    
    a3 = a1 * a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1,  42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2,  10.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a3, 420.0 ) );
}

TEST( XS_Atomic_Trivial_Double, MultiplicationOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1 * 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a1,  42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 420.0 ) );
}

TEST( XS_Atomic_Trivial_Double, DivisionOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    XS::Atomic< double > a3;
    
    a3 = a1 / a2;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2, 10.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a3,  4.2 ) );
}

TEST( XS_Atomic_Trivial_Double, DivisionOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2;
    
    a2 = a1 / 10.0;
    
    ASSERT_TRUE( DoubleIsEqual( a1, 42.0 ) );
    ASSERT_TRUE( DoubleIsEqual( a2,  4.2 ) );
}

TEST( XS_Atomic_Trivial_Double, EqualToOperator )
{
    XS::Atomic< double > a1{ 0.0 };
    XS::Atomic< double > a2{ 0.0 };
    XS::Atomic< double > a3{ 1.0 };
    XS::Atomic< double > a4{ 1.0 };
    
    ASSERT_TRUE(  DoubleIsEqual( a1, a2 ) );
    ASSERT_FALSE( DoubleIsEqual( a1, a3 ) );
    ASSERT_TRUE(  DoubleIsEqual( a3, a4 ) );
    ASSERT_FALSE( DoubleIsEqual( a3, a1 ) );
}

TEST( XS_Atomic_Trivial_Double, EqualToOperator_V )
{
    XS::Atomic< double > a1{ 0.0 };
    XS::Atomic< double > a2{ 1.0 };
    
    ASSERT_TRUE(  DoubleIsEqual( a1, 0.0 ) );
    ASSERT_FALSE( DoubleIsEqual( a1, 1.0 ) );
    ASSERT_TRUE(  DoubleIsEqual( a2, 1.0 ) );
    ASSERT_FALSE( DoubleIsEqual( a2, 0.0 ) );
}

TEST( XS_Atomic_Trivial_Double, NotEqualToOperator )
{
    XS::Atomic< double > a1{ 0.0 };
    XS::Atomic< double > a2{ 0.0 };
    XS::Atomic< double > a3{ 1.0 };
    XS::Atomic< double > a4{ 1.0 };
    
    ASSERT_FALSE( a1 != a2 );
    ASSERT_TRUE(  a1 != a3 );
    ASSERT_FALSE( a3 != a4 );
    ASSERT_TRUE(  a3 != a1 );
}

TEST( XS_Atomic_Trivial_Double, NotEqualToOperator_V )
{
    XS::Atomic< double > a1{ 0.0 };
    XS::Atomic< double > a2{ 1.0 };
    
    ASSERT_FALSE( a1 != 0.0 );
    ASSERT_TRUE(  a1 != 1.0 );
    ASSERT_FALSE( a2 != 1.0 );
    ASSERT_TRUE(  a2 != 0.0 );
}

TEST( XS_Atomic_Trivial_Double, LessThanOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 42.0 };
    XS::Atomic< double > a3{ 10.0 };
    
    ASSERT_FALSE( a1 < a2 );
    ASSERT_FALSE( a1 < a3 );
    ASSERT_TRUE(  a3 < a1 );
}

TEST( XS_Atomic_Trivial_Double, LessThanOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    ASSERT_FALSE( a1 < 42.0 );
    ASSERT_FALSE( a1 < 10.0 );
    ASSERT_TRUE(  a2 < 42.0 );
}

TEST( XS_Atomic_Trivial_Double, GreaterThanOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 42.0 };
    XS::Atomic< double > a3{ 10.0 };
    
    ASSERT_FALSE( a1 > a2 );
    ASSERT_TRUE(  a1 > a3 );
    ASSERT_FALSE( a3 > a1 );
}

TEST( XS_Atomic_Trivial_Double, GreaterThanOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    ASSERT_FALSE( a1 > 42.0 );
    ASSERT_TRUE(  a1 > 10.0 );
    ASSERT_FALSE( a2 > 42.0 );
}

TEST( XS_Atomic_Trivial_Double, LessThanOrEqualToOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 42.0 };
    XS::Atomic< double > a3{ 10.0 };
    
    ASSERT_TRUE(  a1 <= a2 );
    ASSERT_FALSE( a1 <= a3 );
    ASSERT_TRUE(  a3 <= a1 );
}

TEST( XS_Atomic_Trivial_Double, LessThanOrEqualToOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    ASSERT_TRUE(  a1 <= 42.0 );
    ASSERT_FALSE( a1 <= 10.0 );
    ASSERT_TRUE(  a2 <= 42.0 );
}

TEST( XS_Atomic_Trivial_Double, GreaterThanOrEqualToOperator )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 42.0 };
    XS::Atomic< double > a3{ 10.0 };
    
    ASSERT_TRUE(  a1 >= a2 );
    ASSERT_TRUE(  a1 >= a3 );
    ASSERT_FALSE( a3 >= a1 );
}

TEST( XS_Atomic_Trivial_Double, GreaterThanOrEqualToOperator_V )
{
    XS::Atomic< double > a1{ 42.0 };
    XS::Atomic< double > a2{ 10.0 };
    
    ASSERT_TRUE(  a1 >= 42.0 );
    ASSERT_TRUE(  a1 >= 10.0 );
    ASSERT_FALSE( a2 >= 42.0 );
}
