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
             
TEST( XS_Atomic_Trivial_NonTrivial, CTOR )
{}

TEST( XS_Atomic_Trivial_NonTrivial, CTOR_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, CCTOR )
{}

TEST( XS_Atomic_Trivial_NonTrivial, OperatorAssign )
{}

TEST( XS_Atomic_Trivial_NonTrivial, OperatorAssign_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, OperatorCast )
{}

TEST( XS_Atomic_Trivial_NonTrivial, Load )
{}

TEST( XS_Atomic_Trivial_NonTrivial, Store )
{}

TEST( XS_Atomic_Trivial_NonTrivial, Swap )
{}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_NonTrivial, AdditionAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, AdditionAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseORAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseORAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXORAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXORAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseRightShiftAssignmentOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseRightShiftAssignmentOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, PreIncrementOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, PreDecrementOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, PostIncrementOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, PostDecrementOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, UnaryPlusOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, UnaryMinusOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, AdditionOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, AdditionOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseOROperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseOROperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXOROperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXOROperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLightShiftOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLightShiftOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, NegationOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, ANDOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, ANDOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, InclusiveOROperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, InclusiveOROperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, EqualToOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, EqualToOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, NotEqualToOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, NotEqualToOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOrEqualToOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOrEqualToOperator_V )
{}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOrEqualToOperator )
{}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOrEqualToOperator_V )
{}
