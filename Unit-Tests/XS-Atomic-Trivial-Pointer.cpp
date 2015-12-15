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

TEST( XS_Atomic_Trivial_Pointer, AdditionAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, AdditionAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, SubtractionAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, SubtractionAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, MultiplicationAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, MultiplicationAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, DivisionAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, DivisionAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, ModuloAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, ModuloAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseANDAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseANDAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseORAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseORAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseXORAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseXORAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseLeftShiftAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseLeftShiftAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseRightShiftAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseRightShiftAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, PreIncrementOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, PreDecrementOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, PostIncrementOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, PostDecrementOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, UnaryPlusOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, UnaryMinusOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, AdditionOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, AdditionOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, SubtractionOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, SubtractionOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, MultiplicationOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, MultiplicationOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, DivisionOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, DivisionOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, ModuloOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, ModuloOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseANDOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseANDOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseOROperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseOROperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseXOROperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseXOROperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseLeftShiftOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseLeftShiftOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseLightShiftOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, BitwiseLightShiftOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, NegationOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, ANDOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, ANDOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, InclusiveOROperator )
{}

TEST( XS_Atomic_Trivial_Pointer, InclusiveOROperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, EqualToOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, EqualToOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, NotEqualToOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, NotEqualToOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, LessThanOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, LessThanOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, LessThanOrEqualToOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, LessThanOrEqualToOperator_V )
{}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOrEqualToOperator )
{}

TEST( XS_Atomic_Trivial_Pointer, GreaterThanOrEqualToOperator_V )
{}
