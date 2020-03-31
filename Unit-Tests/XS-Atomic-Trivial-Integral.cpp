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

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>

#ifdef __clang__
#pragma clang diagnostic ignored "-Wself-assign-overloaded"
#endif

/*******************************************************************************
 * Common definitions
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Integral, CTOR )
{
    XS::Atomic< int > a;
    
    ASSERT_TRUE( a == 0 );
}

TEST( XS_Atomic_Trivial_Integral, CTOR_V )
{
    XS::Atomic< int > a{ 42 };
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, CCTOR )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ a1 };
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorAssign )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 42 );
    
    a1 = a1;
    
    ASSERT_TRUE( a1 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorAssign_V )
{
    XS::Atomic< int > a;
    
    a = 42;
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorCast )
{
    XS::Atomic< int > a{ 42 };
    
    ASSERT_TRUE( static_cast< int >( a ) == 42 );
}

TEST( XS_Atomic_Trivial_Integral, Load )
{
    XS::Atomic< int > a{ 42 };
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, Store )
{
    XS::Atomic< int > a;
    
    a.Store( 42 );
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, Swap )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 43 );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( a1 == 43 );
    ASSERT_TRUE( a2 == 42 );
    
    swap( a1, a1 );
    
    ASSERT_TRUE( a1 == 43 );
}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Integral, AdditionAssignmentOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 += a2;
    
    ASSERT_TRUE( a1 == 52 );
}

TEST( XS_Atomic_Trivial_Integral, AdditionAssignmentOperator_V )
{
    XS::Atomic< int > a{ 42 };
    
    a += 10;
    
    ASSERT_TRUE( a == 52 );
}

TEST( XS_Atomic_Trivial_Integral, SubtractionAssignmentOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 -= a2;
    
    ASSERT_TRUE( a1 == 32 );
}

TEST( XS_Atomic_Trivial_Integral, SubtractionAssignmentOperator_V )
{
    XS::Atomic< int > a{ 42 };
    
    a -= 10;
    
    ASSERT_TRUE( a == 32 );
}

TEST( XS_Atomic_Trivial_Integral, MultiplicationAssignmentOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 *= a2;
    
    ASSERT_TRUE( a1 == 420 );
}

TEST( XS_Atomic_Trivial_Integral, MultiplicationAssignmentOperator_V )
{
    XS::Atomic< int > a{ 42 };
    
    a *= 10;
    
    ASSERT_TRUE( a == 420 );
}

TEST( XS_Atomic_Trivial_Integral, DivisionAssignmentOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 /= a2;
    
    ASSERT_TRUE( a1 == 4 );
}

TEST( XS_Atomic_Trivial_Integral, DivisionAssignmentOperator_V )
{
    XS::Atomic< int > a{ 42 };
    
    a /= 10;
    
    ASSERT_TRUE( a == 4 );
}

TEST( XS_Atomic_Trivial_Integral, ModuloAssignmentOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 %= a2;
    
    ASSERT_TRUE( a1 == 2 );
}

TEST( XS_Atomic_Trivial_Integral, ModuloAssignmentOperator_V )
{
    XS::Atomic< int > a{ 42 };
    
    a %= 10;
    
    ASSERT_TRUE( a == 2 );
}

TEST( XS_Atomic_Trivial_Integral, PreIncrementOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = ++a1;
    
    ASSERT_TRUE( a1 == 43 );
    ASSERT_TRUE( a2 == 43 );
}

TEST( XS_Atomic_Trivial_Integral, PreDecrementOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = --a1;
    
    ASSERT_TRUE( a1 == 41 );
    ASSERT_TRUE( a2 == 41 );
}

TEST( XS_Atomic_Trivial_Integral, PostIncrementOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1++;
    
    ASSERT_TRUE( a1 == 43 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, PostDecrementOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1--;
    
    ASSERT_TRUE( a1 == 41 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, UnaryPlusOperator )
{
    XS::Atomic< int > a1{  42 };
    XS::Atomic< int > a2{ -42 };
    XS::Atomic< int > a3;
    XS::Atomic< int > a4;
    
    a3 = +a1;
    a4 = +a2;
    
    ASSERT_TRUE( a1 ==  42 );
    ASSERT_TRUE( a2 == -42 );
    ASSERT_TRUE( a3 ==  42 );
    ASSERT_TRUE( a4 == -42 );
}

TEST( XS_Atomic_Trivial_Integral, UnaryMinusOperator )
{
    XS::Atomic< int > a1{  42 };
    XS::Atomic< int > a2{ -42 };
    XS::Atomic< int > a3;
    XS::Atomic< int > a4;
    
    a3 = -a1;
    a4 = -a2;
    
    ASSERT_TRUE( a1 ==  42 );
    ASSERT_TRUE( a2 == -42 );
    ASSERT_TRUE( a3 == -42 );
    ASSERT_TRUE( a4 ==  42 );
}

TEST( XS_Atomic_Trivial_Integral, AdditionOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    XS::Atomic< int > a3;
    
    a3 = a1 + a2;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 10 );
    ASSERT_TRUE( a3 == 52 );
}

TEST( XS_Atomic_Trivial_Integral, AdditionOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1 + 10;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 52 );
}

TEST( XS_Atomic_Trivial_Integral, SubtractionOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    XS::Atomic< int > a3;
    
    a3 = a1 - a2;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 10 );
    ASSERT_TRUE( a3 == 32 );
}

TEST( XS_Atomic_Trivial_Integral, SubtractionOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1 - 10;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 32 );
}

TEST( XS_Atomic_Trivial_Integral, MultiplicationOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    XS::Atomic< int > a3;
    
    a3 = a1 * a2;
    
    ASSERT_TRUE( a1 ==  42 );
    ASSERT_TRUE( a2 ==  10 );
    ASSERT_TRUE( a3 == 420 );
}

TEST( XS_Atomic_Trivial_Integral, MultiplicationOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1 * 10;
    
    ASSERT_TRUE( a1 ==  42 );
    ASSERT_TRUE( a2 == 420 );
}

TEST( XS_Atomic_Trivial_Integral, DivisionOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    XS::Atomic< int > a3;
    
    a3 = a1 / a2;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 10 );
    ASSERT_TRUE( a3 ==  4 );
}

TEST( XS_Atomic_Trivial_Integral, DivisionOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1 / 10;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 ==  4 );
}

TEST( XS_Atomic_Trivial_Integral, ModuloOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    XS::Atomic< int > a3;
    
    a3 = a1 % a2;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 10 );
    ASSERT_TRUE( a3 ==  2 );
}

TEST( XS_Atomic_Trivial_Integral, ModuloOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1 % 10;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 ==  2 );
}

TEST( XS_Atomic_Trivial_Integral, NegationOperator )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 1 };
    
    ASSERT_TRUE(  !a1 );
    ASSERT_FALSE( !a2 );
}

TEST( XS_Atomic_Trivial_Integral, ANDOperator )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 0 };
    XS::Atomic< int > a3{ 1 };
    XS::Atomic< int > a4{ 1 };
    
    ASSERT_FALSE( a1 && a2 );
    ASSERT_FALSE( a1 && a3 );
    ASSERT_TRUE(  a3 && a4 );
    ASSERT_FALSE( a3 && a1 );
}

TEST( XS_Atomic_Trivial_Integral, ANDOperator_V )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 1 };
    
    ASSERT_FALSE( a1 && 0 );
    ASSERT_FALSE( a1 && 1 );
    ASSERT_TRUE(  a2 && 1 );
    ASSERT_FALSE( a2 && 0 );
}

TEST( XS_Atomic_Trivial_Integral, InclusiveOROperator )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 0 };
    XS::Atomic< int > a3{ 1 };
    XS::Atomic< int > a4{ 1 };
    
    ASSERT_FALSE( a1 || a2 );
    ASSERT_TRUE(  a1 || a3 );
    ASSERT_TRUE(  a3 || a4 );
    ASSERT_TRUE(  a3 || a1 );
}

TEST( XS_Atomic_Trivial_Integral, InclusiveOROperator_V )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 1 };
    
    ASSERT_FALSE( a1 || 0 );
    ASSERT_TRUE(  a1 || 1 );
    ASSERT_TRUE(  a2 || 1 );
    ASSERT_TRUE(  a2 || 0 );
}

TEST( XS_Atomic_Trivial_Integral, EqualToOperator )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 0 };
    XS::Atomic< int > a3{ 1 };
    XS::Atomic< int > a4{ 1 };
    
    ASSERT_TRUE(  a1 == a2 );
    ASSERT_FALSE( a1 == a3 );
    ASSERT_TRUE(  a3 == a4 );
    ASSERT_FALSE( a3 == a1 );
}

TEST( XS_Atomic_Trivial_Integral, EqualToOperator_V )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 1 };
    
    ASSERT_TRUE(  a1 == 0 );
    ASSERT_FALSE( a1 == 1 );
    ASSERT_TRUE(  a2 == 1 );
    ASSERT_FALSE( a2 == 0 );
}

TEST( XS_Atomic_Trivial_Integral, NotEqualToOperator )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 0 };
    XS::Atomic< int > a3{ 1 };
    XS::Atomic< int > a4{ 1 };
    
    ASSERT_FALSE( a1 != a2 );
    ASSERT_TRUE(  a1 != a3 );
    ASSERT_FALSE( a3 != a4 );
    ASSERT_TRUE(  a3 != a1 );
}

TEST( XS_Atomic_Trivial_Integral, NotEqualToOperator_V )
{
    XS::Atomic< int > a1{ 0 };
    XS::Atomic< int > a2{ 1 };
    
    ASSERT_FALSE( a1 != 0 );
    ASSERT_TRUE(  a1 != 1 );
    ASSERT_FALSE( a2 != 1 );
    ASSERT_TRUE(  a2 != 0 );
}

TEST( XS_Atomic_Trivial_Integral, LessThanOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 10 };
    
    ASSERT_FALSE( a1 < a2 );
    ASSERT_FALSE( a1 < a3 );
    ASSERT_TRUE(  a3 < a1 );
}

TEST( XS_Atomic_Trivial_Integral, LessThanOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    ASSERT_FALSE( a1 < 42 );
    ASSERT_FALSE( a1 < 10 );
    ASSERT_TRUE(  a2 < 42 );
}

TEST( XS_Atomic_Trivial_Integral, GreaterThanOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 10 };
    
    ASSERT_FALSE( a1 > a2 );
    ASSERT_TRUE(  a1 > a3 );
    ASSERT_FALSE( a3 > a1 );
}

TEST( XS_Atomic_Trivial_Integral, GreaterThanOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    ASSERT_FALSE( a1 > 42 );
    ASSERT_TRUE(  a1 > 10 );
    ASSERT_FALSE( a2 > 42 );
}

TEST( XS_Atomic_Trivial_Integral, LessThanOrEqualToOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 10 };
    
    ASSERT_TRUE(  a1 <= a2 );
    ASSERT_FALSE( a1 <= a3 );
    ASSERT_TRUE(  a3 <= a1 );
}

TEST( XS_Atomic_Trivial_Integral, LessThanOrEqualToOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    ASSERT_TRUE(  a1 <= 42 );
    ASSERT_FALSE( a1 <= 10 );
    ASSERT_TRUE(  a2 <= 42 );
}

TEST( XS_Atomic_Trivial_Integral, GreaterThanOrEqualToOperator )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 10 };
    
    ASSERT_TRUE(  a1 >= a2 );
    ASSERT_TRUE(  a1 >= a3 );
    ASSERT_FALSE( a3 >= a1 );
}

TEST( XS_Atomic_Trivial_Integral, GreaterThanOrEqualToOperator_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    ASSERT_TRUE(  a1 >= 42 );
    ASSERT_TRUE(  a1 >= 10 );
    ASSERT_FALSE( a2 >= 42 );
}
