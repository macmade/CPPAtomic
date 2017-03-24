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

class Foo
{
    public:
        
        Foo( void )
        {
            this->ConstructorCalled = true;
        }
        
        Foo( const Foo & o ):
            ConstructorCalled( o.ConstructorCalled ),
            CopyConstructorCalled( o.CopyConstructorCalled ),
            MoveConstructorCalled( o.MoveConstructorCalled ),
            SimpleAssignmentOperatorCalled( o.SimpleAssignmentOperatorCalled ),
            AdditionAssignmentOperatorCalled( o.AdditionAssignmentOperatorCalled ),
            SubtractionAssignmentOperatorCalled( o.SubtractionAssignmentOperatorCalled ),
            MultiplicationAssignmentOperatorCalled( o.MultiplicationAssignmentOperatorCalled ),
            DivisionAssignmentOperatorCalled( o.DivisionAssignmentOperatorCalled ),
            ModuloAssignmentOperatorCalled( o.ModuloAssignmentOperatorCalled ),
            BitwiseANDAssignmentOperatorCalled( o.BitwiseANDAssignmentOperatorCalled ),
            BitwiseORAssignmentOperatorCalled( o.BitwiseORAssignmentOperatorCalled ),
            BitwiseXORAssignmentOperatorCalled( o.BitwiseXORAssignmentOperatorCalled ),
            BitwiseLeftShiftAssignmentOperatorCalled( o.BitwiseLeftShiftAssignmentOperatorCalled ),
            BitwiseRightShiftAssignmentOperatorCalled( o.BitwiseRightShiftAssignmentOperatorCalled ),
            PreIncrementOperatorCalled( o.PreIncrementOperatorCalled ),
            PreDecrementOperatorCalled( o.PreDecrementOperatorCalled ),
            PostIncrementOperatorCalled( o.PostIncrementOperatorCalled ),
            PostDecrementOperatorCalled( o.PostDecrementOperatorCalled ),
            UnaryPlusOperatorCalled( o.UnaryPlusOperatorCalled ),
            UnaryMinusOperatorCalled( o.UnaryMinusOperatorCalled ),
            AdditionOperatorCalled( o.AdditionOperatorCalled ),
            SubtractionOperatorCalled( o.SubtractionOperatorCalled ),
            MultiplicationOperatorCalled( o.MultiplicationOperatorCalled ),
            DivisionOperatorCalled( o.DivisionOperatorCalled ),
            ModuloOperatorCalled( o.ModuloOperatorCalled ),
            BitwiseNOTOperatorCalled( o.BitwiseNOTOperatorCalled ),
            BitwiseANDOperatorCalled( o.BitwiseANDOperatorCalled ),
            BitwiseOROperatorCalled( o.BitwiseOROperatorCalled ),
            BitwiseXOROperatorCalled( o.BitwiseXOROperatorCalled ),
            BitwiseLeftShiftOperatorCalled( o.BitwiseLeftShiftOperatorCalled ),
            BitwiseRightShiftOperatorCalled( o.BitwiseRightShiftOperatorCalled ),
            NegationOperatorCalled( o.NegationOperatorCalled ),
            ANDOperatorCalled( o.ANDOperatorCalled ),
            InclusiveOROperatorCalled( o.InclusiveOROperatorCalled ),
            EqualToOperatorCalled( o.EqualToOperatorCalled ),
            NotEqualToOperatorCalled( o.NotEqualToOperatorCalled ),
            LessThanOperatorCalled( o.LessThanOperatorCalled ),
            GreaterThanOperatorCalled( o.GreaterThanOperatorCalled ),
            LessThanOrEqualToOperatorCalled( o.LessThanOrEqualToOperatorCalled ),
            GreaterThanOrEqualToOperatorCalled( o.GreaterThanOrEqualToOperatorCalled )
        {
            ( void )o;
            
            this->CopyConstructorCalled = true;
        }
        
        Foo( const Foo && o )
        {
            ( void )o;
            
            this->MoveConstructorCalled = true;
        }
        
        Foo & operator =( const Foo & o )
        {
            ( void )o;
            
            this->SimpleAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator +=( const Foo & o )
        {
            ( void )o;
            
            this->AdditionAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator -=( const Foo & o )
        {
            ( void )o;
            
            this->SubtractionAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator *=( const Foo & o )
        {
            ( void )o;
            
            this->MultiplicationAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator /=( const Foo & o )
        {
            ( void )o;
            
            this->DivisionAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator %=( const Foo & o )
        {
            ( void )o;
            
            this->ModuloAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator &=( const Foo & o )
        {
            ( void )o;
            
            this->BitwiseANDAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator |=( const Foo & o )
        {
            ( void )o;
            
            this->BitwiseORAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator ^=( const Foo & o )
        {
            ( void )o;
            
            this->BitwiseXORAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator <<=( const Foo & o )
        {
            ( void )o;
            
            this->BitwiseLeftShiftAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator >>=( const Foo & o )
        {
            ( void )o;
            
            this->BitwiseRightShiftAssignmentOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator ++( void )
        {
            this->PreIncrementOperatorCalled = true;
            
            return *( this );
        }
        
        Foo & operator --( void )
        {
            this->PreDecrementOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator ++( int )
        {
            this->PostIncrementOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator --( int )
        {
            this->PostDecrementOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator +( void ) const
        {
            this->UnaryPlusOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator -( void ) const
        {
            this->UnaryMinusOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator +( const Foo & o ) const
        {
            ( void )o;
            
            this->AdditionOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator -( const Foo & o ) const
        {
            ( void )o;
            
            this->SubtractionOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator *( const Foo & o ) const
        {
            ( void )o;
            
            this->MultiplicationOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator /( const Foo & o ) const
        {
            ( void )o;
            
            this->DivisionOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator %( const Foo & o ) const
        {
            ( void )o;
            
            this->ModuloOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator ~( void ) const
        {
            this->BitwiseNOTOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator &( const Foo & o ) const
        {
            ( void )o;
            
            this->BitwiseANDOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator |( const Foo & o ) const
        {
            ( void )o;
            
            this->BitwiseOROperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator ^( const Foo & o ) const
        {
            ( void )o;
            
            this->BitwiseXOROperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator <<( const Foo & o ) const
        {
            ( void )o;
            
            this->BitwiseLeftShiftOperatorCalled = true;
            
            return *( this );
        }
        
        Foo operator >>( const Foo & o ) const
        {
            ( void )o;
            
            this->BitwiseRightShiftOperatorCalled = true;
            
            return *( this );
        }
        
        bool operator !( void ) const
        {
            this->NegationOperatorCalled = true;
            
            return false;
        }
        
        bool operator &&( const Foo & o ) const
        {
            ( void )o;
            
            this->ANDOperatorCalled = true;
            
            return false;
        }
        
        bool operator ||( const Foo & o ) const
        {
            ( void )o;
            
            this->InclusiveOROperatorCalled = true;
            
            return false;
        }
        
        bool operator ==( const Foo & o ) const
        {
            ( void )o;
            
            this->EqualToOperatorCalled = true;
            
            return false;
        }
        
        bool operator !=( const Foo & o ) const
        {
            ( void )o;
            
            this->NotEqualToOperatorCalled = true;
            
            return false;
        }
        
        bool operator <( const Foo & o ) const
        {
            ( void )o;
            
            this->LessThanOperatorCalled = true;
            
            return false;
        }
        
        bool operator >( const Foo & o ) const
        {
            ( void )o;
            
            this->GreaterThanOperatorCalled = true;
            
            return false;
        }
        
        bool operator <=( const Foo & o ) const
        {
            ( void )o;
            
            this->LessThanOrEqualToOperatorCalled = true;
            
            return false;
        }
        
        bool operator >=( const Foo & o ) const
        {
            ( void )o;
            
            this->GreaterThanOrEqualToOperatorCalled = true;
            
            return false;
        }
        
        mutable bool ConstructorCalled                          = false;
        mutable bool CopyConstructorCalled                      = false;
        mutable bool MoveConstructorCalled                      = false;
        mutable bool SimpleAssignmentOperatorCalled             = false;
        mutable bool AdditionAssignmentOperatorCalled           = false;
        mutable bool SubtractionAssignmentOperatorCalled        = false;
        mutable bool MultiplicationAssignmentOperatorCalled     = false;
        mutable bool DivisionAssignmentOperatorCalled           = false;
        mutable bool ModuloAssignmentOperatorCalled             = false;
        mutable bool BitwiseANDAssignmentOperatorCalled         = false;
        mutable bool BitwiseORAssignmentOperatorCalled          = false;
        mutable bool BitwiseXORAssignmentOperatorCalled         = false;
        mutable bool BitwiseLeftShiftAssignmentOperatorCalled   = false;
        mutable bool BitwiseRightShiftAssignmentOperatorCalled  = false;
        mutable bool PreIncrementOperatorCalled                 = false;
        mutable bool PreDecrementOperatorCalled                 = false;
        mutable bool PostIncrementOperatorCalled                = false;
        mutable bool PostDecrementOperatorCalled                = false;
        mutable bool UnaryPlusOperatorCalled                    = false;
        mutable bool UnaryMinusOperatorCalled                   = false;
        mutable bool AdditionOperatorCalled                     = false;
        mutable bool SubtractionOperatorCalled                  = false;
        mutable bool MultiplicationOperatorCalled               = false;
        mutable bool DivisionOperatorCalled                     = false;
        mutable bool ModuloOperatorCalled                       = false;
        mutable bool BitwiseNOTOperatorCalled                   = false;
        mutable bool BitwiseANDOperatorCalled                   = false;
        mutable bool BitwiseOROperatorCalled                    = false;
        mutable bool BitwiseXOROperatorCalled                   = false;
        mutable bool BitwiseLeftShiftOperatorCalled             = false;
        mutable bool BitwiseRightShiftOperatorCalled            = false;
        mutable bool NegationOperatorCalled                     = false;
        mutable bool ANDOperatorCalled                          = false;
        mutable bool InclusiveOROperatorCalled                  = false;
        mutable bool EqualToOperatorCalled                      = false;
        mutable bool NotEqualToOperatorCalled                   = false;
        mutable bool LessThanOperatorCalled                     = false;
        mutable bool GreaterThanOperatorCalled                  = false;
        mutable bool LessThanOrEqualToOperatorCalled            = false;
        mutable bool GreaterThanOrEqualToOperatorCalled         = false;
        
        unsigned int NumberOfCalls( void )
        {
            unsigned int i = 0;
            
            /*
            if( ConstructorCalled                           ) { i++; };
            if( CopyConstructorCalled                       ) { i++; };
            if( MoveConstructorCalled                       ) { i++; };
            */
            if( SimpleAssignmentOperatorCalled              ) { i++; };
            if( AdditionAssignmentOperatorCalled            ) { i++; };
            if( SubtractionAssignmentOperatorCalled         ) { i++; };
            if( MultiplicationAssignmentOperatorCalled      ) { i++; };
            if( DivisionAssignmentOperatorCalled            ) { i++; };
            if( ModuloAssignmentOperatorCalled              ) { i++; };
            if( BitwiseANDAssignmentOperatorCalled          ) { i++; };
            if( BitwiseORAssignmentOperatorCalled           ) { i++; };
            if( BitwiseXORAssignmentOperatorCalled          ) { i++; };
            if( BitwiseLeftShiftAssignmentOperatorCalled    ) { i++; };
            if( BitwiseRightShiftAssignmentOperatorCalled   ) { i++; };
            if( PreIncrementOperatorCalled                  ) { i++; };
            if( PreDecrementOperatorCalled                  ) { i++; };
            if( PostIncrementOperatorCalled                 ) { i++; };
            if( PostDecrementOperatorCalled                 ) { i++; };
            if( UnaryPlusOperatorCalled                     ) { i++; };
            if( UnaryMinusOperatorCalled                    ) { i++; };
            if( AdditionOperatorCalled                      ) { i++; };
            if( SubtractionOperatorCalled                   ) { i++; };
            if( MultiplicationOperatorCalled                ) { i++; };
            if( DivisionOperatorCalled                      ) { i++; };
            if( ModuloOperatorCalled                        ) { i++; };
            if( BitwiseNOTOperatorCalled                    ) { i++; };
            if( BitwiseANDOperatorCalled                    ) { i++; };
            if( BitwiseOROperatorCalled                     ) { i++; };
            if( BitwiseXOROperatorCalled                    ) { i++; };
            if( BitwiseLeftShiftOperatorCalled              ) { i++; };
            if( BitwiseRightShiftOperatorCalled             ) { i++; };
            if( NegationOperatorCalled                      ) { i++; };
            if( ANDOperatorCalled                           ) { i++; };
            if( InclusiveOROperatorCalled                   ) { i++; };
            if( EqualToOperatorCalled                       ) { i++; };
            if( NotEqualToOperatorCalled                    ) { i++; };
            if( LessThanOperatorCalled                      ) { i++; };
            if( GreaterThanOperatorCalled                   ) { i++; };
            if( LessThanOrEqualToOperatorCalled             ) { i++; };
            if( GreaterThanOrEqualToOperatorCalled          ) { i++; };
            
            return i;
        }
};

/*******************************************************************************
 * Common definitions
 ******************************************************************************/
             
TEST( XS_Atomic_Trivial_NonTrivial, CTOR )
{
    XS::Atomic< Foo > a;
    
    ASSERT_TRUE( a.Load().ConstructorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 0 );
}

TEST( XS_Atomic_Trivial_NonTrivial, CTOR_V )
{
    XS::Atomic< Foo > a{ Foo() };
    
    ASSERT_TRUE( a.Load().ConstructorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 0 );
}

TEST( XS_Atomic_Trivial_NonTrivial, CCTOR )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2{ a1 };
    
    ASSERT_TRUE( a2.Load().CopyConstructorCalled );
    ASSERT_TRUE( a2.Load().NumberOfCalls() == 0 );
}

TEST( XS_Atomic_Trivial_NonTrivial, OperatorAssign )
{
    {
        XS::Atomic< Foo > a1;
        XS::Atomic< Foo > a2;
        
        a1 = a2;
        
        ASSERT_TRUE( a1.Load().SimpleAssignmentOperatorCalled );
        ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
    }
    
    {
        XS::Atomic< Foo > a1;
        
        a1 = a1;
        
        ASSERT_TRUE( a1.Load().SimpleAssignmentOperatorCalled );
        ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
    }
}

TEST( XS_Atomic_Trivial_NonTrivial, OperatorAssign_V )
{
    XS::Atomic< Foo > a;
    
    a = Foo();
    
    ASSERT_TRUE( a.Load().SimpleAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, OperatorCast )
{
    Foo                 f;
    XS::Atomic< Foo & > a{ f };
    
    ASSERT_TRUE( &( static_cast< Foo & >( a ) ) == &f );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 0 );
}

TEST( XS_Atomic_Trivial_NonTrivial, Load )
{
    Foo                 f;
    XS::Atomic< Foo & > a{ f };
    
    ASSERT_TRUE( &( a.Load() ) == &f );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 0 );
}

TEST( XS_Atomic_Trivial_NonTrivial, Store )
{
    Foo                 f1;
    Foo                 f2;
    XS::Atomic< Foo & > a{ f1 };
    
    ASSERT_FALSE( a.Load().SimpleAssignmentOperatorCalled );
    
    a.Store( f2 );
    
    ASSERT_TRUE( a.Load().SimpleAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, Swap )
{
    Foo                 f1;
    Foo                 f2;
    XS::Atomic< Foo & > a1{ f1 };
    XS::Atomic< Foo & > a2{ f2 };
    
    ASSERT_FALSE( a1.Load().SimpleAssignmentOperatorCalled );
    ASSERT_FALSE( a2.Load().SimpleAssignmentOperatorCalled );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( a1.Load().SimpleAssignmentOperatorCalled );
    ASSERT_TRUE( a2.Load().SimpleAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
    ASSERT_TRUE( a2.Load().NumberOfCalls() == 1 );
}

/*******************************************************************************
 * Type specific
 ******************************************************************************/

TEST( XS_Atomic_Trivial_NonTrivial, AdditionAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 += a2;
    
    ASSERT_TRUE( a1.Load().AdditionAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, AdditionAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a += Foo();
    
    ASSERT_TRUE( a.Load().AdditionAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 -= a2;
    
    ASSERT_TRUE( a1.Load().SubtractionAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a -= Foo();
    
    ASSERT_TRUE( a.Load().SubtractionAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 *= a2;
    
    ASSERT_TRUE( a1.Load().MultiplicationAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a *= Foo();
    
    ASSERT_TRUE( a.Load().MultiplicationAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 /= a2;
    
    ASSERT_TRUE( a1.Load().DivisionAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a /= Foo();
    
    ASSERT_TRUE( a.Load().DivisionAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 %= a2;
    
    ASSERT_TRUE( a1.Load().ModuloAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a %= Foo();
    
    ASSERT_TRUE( a.Load().ModuloAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 &= a2;
    
    ASSERT_TRUE( a1.Load().BitwiseANDAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a &= Foo();
    
    ASSERT_TRUE( a.Load().BitwiseANDAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseORAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 |= a2;
    
    ASSERT_TRUE( a1.Load().BitwiseORAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseORAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a |= Foo();
    
    ASSERT_TRUE( a.Load().BitwiseORAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXORAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 ^= a2;
    
    ASSERT_TRUE( a1.Load().BitwiseXORAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXORAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a ^= Foo();
    
    ASSERT_TRUE( a.Load().BitwiseXORAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 <<= a2;
    
    ASSERT_TRUE( a1.Load().BitwiseLeftShiftAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftAssignmentOperator_V )
{
    XS::Atomic< Foo > a;

    a <<= Foo();
    
    ASSERT_TRUE( a.Load().BitwiseLeftShiftAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseRightShiftAssignmentOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 >>= a2;
    
    ASSERT_TRUE( a1.Load().BitwiseRightShiftAssignmentOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseRightShiftAssignmentOperator_V )
{
    XS::Atomic< Foo > a;
    
    a >>= Foo();
    
    ASSERT_TRUE( a.Load().BitwiseRightShiftAssignmentOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, PreIncrementOperator )
{
    XS::Atomic< Foo > a;
    
    ++a;
    
    ASSERT_TRUE( a.Load().PreIncrementOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, PreDecrementOperator )
{
    XS::Atomic< Foo > a;
    
    --a;
    
    ASSERT_TRUE( a.Load().PreDecrementOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, PostIncrementOperator )
{
    XS::Atomic< Foo > a;
    
    a++;
    
    ASSERT_TRUE( a.Load().PostIncrementOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, PostDecrementOperator )
{
    XS::Atomic< Foo > a;
    
    a--;
    
    ASSERT_TRUE( a.Load().PostDecrementOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, UnaryPlusOperator )
{
    XS::Atomic< Foo > a;
    
    +a;
    
    ASSERT_TRUE( a.Load().UnaryPlusOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, UnaryMinusOperator )
{
    XS::Atomic< Foo > a;
    
    -a;
    
    ASSERT_TRUE( a.Load().UnaryMinusOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, AdditionOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 + a2;
    
    ASSERT_TRUE( a1.Load().AdditionOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, AdditionOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 + Foo();
    
    ASSERT_TRUE( a1.Load().AdditionOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 - a2;
    
    ASSERT_TRUE( a1.Load().SubtractionOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, SubtractionOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 - Foo();
    
    ASSERT_TRUE( a1.Load().SubtractionOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 * a2;
    
    ASSERT_TRUE( a1.Load().MultiplicationOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, MultiplicationOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 * Foo();
    
    ASSERT_TRUE( a1.Load().MultiplicationOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 / a2;
    
    ASSERT_TRUE( a1.Load().DivisionOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, DivisionOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 / Foo();
    
    ASSERT_TRUE( a1.Load().DivisionOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 % a2;
    
    ASSERT_TRUE( a1.Load().ModuloOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, ModuloOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 % Foo();
    
    ASSERT_TRUE( a1.Load().ModuloOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseNOTOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = ~a1;
    
    ASSERT_TRUE( a1.Load().BitwiseNOTOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 & a2;
    
    ASSERT_TRUE( a1.Load().BitwiseANDOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseANDOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 & Foo();
    
    ASSERT_TRUE( a1.Load().BitwiseANDOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseOROperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 | a2;
    
    ASSERT_TRUE( a1.Load().BitwiseOROperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseOROperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 | Foo();
    
    ASSERT_TRUE( a1.Load().BitwiseOROperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXOROperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 ^ a2;
    
    ASSERT_TRUE( a1.Load().BitwiseXOROperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseXOROperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 ^ Foo();
    
    ASSERT_TRUE( a1.Load().BitwiseXOROperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 << a2;
    
    ASSERT_TRUE( a1.Load().BitwiseLeftShiftOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseLeftShiftOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 << Foo();
    
    ASSERT_TRUE( a1.Load().BitwiseLeftShiftOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseRightShiftOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    XS::Atomic< Foo > a3;
    
    a3 = a1 >> a2;
    
    ASSERT_TRUE( a1.Load().BitwiseRightShiftOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, BitwiseRightShiftOperator_V )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a2 = a1 >> Foo();
    
    ASSERT_TRUE( a1.Load().BitwiseRightShiftOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, NegationOperator )
{
    XS::Atomic< Foo > a;
    
    !a;
    
    ASSERT_TRUE( a.Load().NegationOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, ANDOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 && a2;
    
    ASSERT_TRUE( a1.Load().ANDOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, ANDOperator_V )
{
    XS::Atomic< Foo > a;
    
    a && Foo();
    
    ASSERT_TRUE( a.Load().ANDOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, InclusiveOROperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    a1 || a2;
    
    ASSERT_TRUE( a1.Load().InclusiveOROperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, InclusiveOROperator_V )
{
    XS::Atomic< Foo > a;
    
    a || Foo();
    
    ASSERT_TRUE( a.Load().InclusiveOROperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, EqualToOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    if( a1 == a2 )
    {}
    
    ASSERT_TRUE( a1.Load().EqualToOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, EqualToOperator_V )
{
    XS::Atomic< Foo > a;
    
    if( a == Foo() )
    {}
    
    ASSERT_TRUE( a.Load().EqualToOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, NotEqualToOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    if( a1 != a2 )
    {}
    
    ASSERT_TRUE( a1.Load().NotEqualToOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, NotEqualToOperator_V )
{
    XS::Atomic< Foo > a;
    
    if( a != Foo() )
    {}
    
    ASSERT_TRUE( a.Load().NotEqualToOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    if( a1 < a2 )
    {}
    
    ASSERT_TRUE( a1.Load().LessThanOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOperator_V )
{
    XS::Atomic< Foo > a;
    
    if( a < Foo() )
    {}
    
    ASSERT_TRUE( a.Load().LessThanOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    if( a1 > a2 )
    {}
    
    ASSERT_TRUE( a1.Load().GreaterThanOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOperator_V )
{
    XS::Atomic< Foo > a;
    
    if( a > Foo() )
    {}
    
    ASSERT_TRUE( a.Load().GreaterThanOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOrEqualToOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    if( a1 <= a2 )
    {}
    
    ASSERT_TRUE( a1.Load().LessThanOrEqualToOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, LessThanOrEqualToOperator_V )
{
    XS::Atomic< Foo > a;
    
    if( a <= Foo() )
    {}
    
    ASSERT_TRUE( a.Load().LessThanOrEqualToOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOrEqualToOperator )
{
    XS::Atomic< Foo > a1;
    XS::Atomic< Foo > a2;
    
    if( a1 >= a2 )
    {}
    
    ASSERT_TRUE( a1.Load().GreaterThanOrEqualToOperatorCalled );
    ASSERT_TRUE( a1.Load().NumberOfCalls() == 1 );
}

TEST( XS_Atomic_Trivial_NonTrivial, GreaterThanOrEqualToOperator_V )
{
    XS::Atomic< Foo > a;
    
    if( a >= Foo() )
    {}
    
    ASSERT_TRUE( a.Load().GreaterThanOrEqualToOperatorCalled );
    ASSERT_TRUE( a.Load().NumberOfCalls() == 1 );
}
