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

TEST( XS_Atomic_Trivial_Bitwise, CTOR )
{
    XS::Atomic< unsigned int > a;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 0 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, CTOR_V )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, CCTOR )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ a1 };
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, OperatorAssign )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 42 ) );
    
    a1 = a1;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, OperatorAssign_V )
{
    XS::Atomic< unsigned int > a;
    
    a = 42;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, OperatorCast )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    ASSERT_TRUE( static_cast< unsigned int >( a ) == 42 );
}

TEST( XS_Atomic_Trivial_Bitwise, Load )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    ASSERT_TRUE( a.Load() == 42 );
}

TEST( XS_Atomic_Trivial_Bitwise, Store )
{
    XS::Atomic< unsigned int > a;
    
    a.Store( 42 );
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, Swap )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 43 };
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 43 ) );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 43 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 42 ) );
}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Bitwise, AdditionAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    a1 += a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 52 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, AdditionAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    a += 10;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 52 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, SubtractionAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    a1 -= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 32 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, SubtractionAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    a -= 10;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 32 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, MultiplicationAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    a1 *= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 420 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, MultiplicationAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    a *= 10;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 420 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, DivisionAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    a1 /= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 4 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, DivisionAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    a /= 10;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 4 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, ModuloAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    a1 %= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 2 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, ModuloAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 42 };
    
    a %= 10;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 2 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseANDAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x06 };
    
    a1 &= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x04 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x06 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseANDAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 0x05 };
    
    a &= 0x06;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 0x04 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseORAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x06 };
    
    a1 |= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x07 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x06 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseORAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 0x05 };
    
    a |= 0x06;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 0x07 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseXORAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x06 };
    
    a1 ^= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x03 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x06 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseXORAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 0x05 };
    
    a ^= 0x06;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 0x03 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseLeftShiftAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x02 };
    
    a1 <<= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x14 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x02 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseLeftShiftAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 0x05 };
    
    a <<= 0x02;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 0x14 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseRightShiftAssignmentOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x02 };
    
    a1 >>= a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x01 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x02 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseRightShiftAssignmentOperator_V )
{
    XS::Atomic< unsigned int > a{ 0x05 };
    
    a >>= 0x02;
    
    ASSERT_TRUE( a == static_cast< unsigned int >( 0x01 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, PreIncrementOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = ++a1;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 43 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 43 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, PreDecrementOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = --a1;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 41 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 41 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, PostIncrementOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1++;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 43 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, PostDecrementOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1--;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 41 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, UnaryPlusOperator )
{
    XS::Atomic< unsigned int > a1{  42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = +a1;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, AdditionOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 + a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 10 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 52 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, AdditionOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 + static_cast< unsigned int >( 10 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 52 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, SubtractionOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 - a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 10 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 32 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, SubtractionOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 - static_cast< unsigned int >( 10 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 32 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, MultiplicationOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 * a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >(  42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >(  10 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 420 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, MultiplicationOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 * static_cast< unsigned int >( 10 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >(  42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 420 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, DivisionOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 / a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 10 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >(  4 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, DivisionOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 / static_cast< unsigned int >( 10 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >(  4 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, ModuloOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 % a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 10 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >(  2 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, ModuloOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 % static_cast< unsigned int >( 10 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >(  2 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseNOTOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2;
    
    a2 = ~a1;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0xFFFFFFFA ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseANDOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x06 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 & a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x06 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 0x04 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseANDOperator_V )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 & static_cast< unsigned int >( 0x06 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x04 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseOROperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x06 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 | a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x06 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 0x07 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseOROperator_V )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 | static_cast< unsigned int >( 0x06 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x07 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseXOROperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x06 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 ^ a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x06 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 0x03 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseXOROperator_V )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 ^ static_cast< unsigned int >( 0x06 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x03 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseLeftShiftOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x02 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 << a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x02 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 0x14 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseLeftShiftOperator_V )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 << static_cast< unsigned int >( 0x02 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x14 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseRightShiftOperator )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2{ 0x02 };
    XS::Atomic< unsigned int > a3;
    
    a3 = a1 >> a2;
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x02 ) );
    ASSERT_TRUE( a3 == static_cast< unsigned int >( 0x01 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, BitwiseRightShiftOperator_V )
{
    XS::Atomic< unsigned int > a1{ 0x05 };
    XS::Atomic< unsigned int > a2;
    
    a2 = a1 >> static_cast< unsigned int >( 0x02 );
    
    ASSERT_TRUE( a1 == static_cast< unsigned int >( 0x05 ) );
    ASSERT_TRUE( a2 == static_cast< unsigned int >( 0x01 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, NegationOperator )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 1 };
    
    ASSERT_TRUE(  !a1 );
    ASSERT_FALSE( !a2 );
}

TEST( XS_Atomic_Trivial_Bitwise, ANDOperator )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 0 };
    XS::Atomic< unsigned int > a3{ 1 };
    XS::Atomic< unsigned int > a4{ 1 };
    
    ASSERT_FALSE( a1 && a2 );
    ASSERT_FALSE( a1 && a3 );
    ASSERT_TRUE(  a3 && a4 );
    ASSERT_FALSE( a3 && a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, ANDOperator_V )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 1 };
    
    ASSERT_FALSE( a1 && 0 );
    ASSERT_FALSE( a1 && 1 );
    ASSERT_TRUE(  a2 && 1 );
    ASSERT_FALSE( a2 && 0 );
}

TEST( XS_Atomic_Trivial_Bitwise, InclusiveOROperator )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 0 };
    XS::Atomic< unsigned int > a3{ 1 };
    XS::Atomic< unsigned int > a4{ 1 };
    
    ASSERT_FALSE( a1 || a2 );
    ASSERT_TRUE(  a1 || a3 );
    ASSERT_TRUE(  a3 || a4 );
    ASSERT_TRUE(  a3 || a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, InclusiveOROperator_V )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 1 };
    
    ASSERT_FALSE( a1 || 0 );
    ASSERT_TRUE(  a1 || 1 );
    ASSERT_TRUE(  a2 || 1 );
    ASSERT_TRUE(  a2 || 0 );
}

TEST( XS_Atomic_Trivial_Bitwise, EqualToOperator )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 0 };
    XS::Atomic< unsigned int > a3{ 1 };
    XS::Atomic< unsigned int > a4{ 1 };
    
    ASSERT_TRUE(  a1 == a2 );
    ASSERT_FALSE( a1 == a3 );
    ASSERT_TRUE(  a3 == a4 );
    ASSERT_FALSE( a3 == a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, EqualToOperator_V )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 1 };
    
    ASSERT_TRUE(  a1 == static_cast< unsigned int >( 0 ) );
    ASSERT_FALSE( a1 == static_cast< unsigned int >( 1 ) );
    ASSERT_TRUE(  a2 == static_cast< unsigned int >( 1 ) );
    ASSERT_FALSE( a2 == static_cast< unsigned int >( 0 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, NotEqualToOperator )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 0 };
    XS::Atomic< unsigned int > a3{ 1 };
    XS::Atomic< unsigned int > a4{ 1 };
    
    ASSERT_FALSE( a1 != a2 );
    ASSERT_TRUE(  a1 != a3 );
    ASSERT_FALSE( a3 != a4 );
    ASSERT_TRUE(  a3 != a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, NotEqualToOperator_V )
{
    XS::Atomic< unsigned int > a1{ 0 };
    XS::Atomic< unsigned int > a2{ 1 };
    
    ASSERT_FALSE( a1 != static_cast< unsigned int >( 0 ) );
    ASSERT_TRUE(  a1 != static_cast< unsigned int >( 1 ) );
    ASSERT_FALSE( a2 != static_cast< unsigned int >( 1 ) );
    ASSERT_TRUE(  a2 != static_cast< unsigned int >( 0 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, LessThanOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 42 };
    XS::Atomic< unsigned int > a3{ 10 };
    
    ASSERT_FALSE( a1 < a2 );
    ASSERT_FALSE( a1 < a3 );
    ASSERT_TRUE(  a3 < a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, LessThanOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    ASSERT_FALSE( a1 < static_cast< unsigned int >( 42 ) );
    ASSERT_FALSE( a1 < static_cast< unsigned int >( 10 ) );
    ASSERT_TRUE(  a2 < static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, GreaterThanOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 42 };
    XS::Atomic< unsigned int > a3{ 10 };
    
    ASSERT_FALSE( a1 > a2 );
    ASSERT_TRUE(  a1 > a3 );
    ASSERT_FALSE( a3 > a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, GreaterThanOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    ASSERT_FALSE( a1 > static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE(  a1 > static_cast< unsigned int >( 10 ) );
    ASSERT_FALSE( a2 > static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, LessThanOrEqualToOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 42 };
    XS::Atomic< unsigned int > a3{ 10 };
    
    ASSERT_TRUE(  a1 <= a2 );
    ASSERT_FALSE( a1 <= a3 );
    ASSERT_TRUE(  a3 <= a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, LessThanOrEqualToOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    ASSERT_TRUE(  a1 <= static_cast< unsigned int >( 42 ) );
    ASSERT_FALSE( a1 <= static_cast< unsigned int >( 10 ) );
    ASSERT_TRUE(  a2 <= static_cast< unsigned int >( 42 ) );
}

TEST( XS_Atomic_Trivial_Bitwise, GreaterThanOrEqualToOperator )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 42 };
    XS::Atomic< unsigned int > a3{ 10 };
    
    ASSERT_TRUE(  a1 >= a2 );
    ASSERT_TRUE(  a1 >= a3 );
    ASSERT_FALSE( a3 >= a1 );
}

TEST( XS_Atomic_Trivial_Bitwise, GreaterThanOrEqualToOperator_V )
{
    XS::Atomic< unsigned int > a1{ 42 };
    XS::Atomic< unsigned int > a2{ 10 };
    
    ASSERT_TRUE(  a1 >= static_cast< unsigned int >( 42 ) );
    ASSERT_TRUE(  a1 >= static_cast< unsigned int >( 10 ) );
    ASSERT_FALSE( a2 >= static_cast< unsigned int >( 42 ) );
}
