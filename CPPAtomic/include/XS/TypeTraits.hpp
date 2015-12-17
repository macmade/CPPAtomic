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
 * @brief       Type traits
 */

#ifndef XS_ATOMIC_TRAITS_H
#define XS_ATOMIC_TRAITS_H

#include <type_traits>

#define XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD( _N_, _F_ )                                                    \
    template< typename _T_, typename _R_, typename ... _A_ >                                                \
    class _N_                                                                                               \
    {                                                                                                       \
        private:                                                                                            \
                                                                                                            \
            struct _Y { char _[ 1 ]; };                                                                     \
            struct _N { char _[ 2 ]; };                                                                     \
                                                                                                            \
            template< typename _U_, _U_ > struct _S;                                                        \
                                                                                                            \
            template< typename _C_ > static _Y & _T( _S< _R_ ( _C_::* )( _A_ ... ), &_C_::_F_ > * );        \
            template< typename _C_ > static _N & _T( ... );                                                 \
                                                                                                            \
        public:                                                                                             \
                                                                                                            \
            enum { value = sizeof( _T< _T_ >( 0 ) ) == sizeof( _Y ) };                                      \
    }

#define XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( _N_, _F_ )                                              \
    template< typename _T_, typename _R_, typename ... _A_ >                                                \
    class _N_                                                                                               \
    {                                                                                                       \
        private:                                                                                            \
                                                                                                            \
            struct _Y { char _[ 1 ]; };                                                                     \
            struct _N { char _[ 2 ]; };                                                                     \
                                                                                                            \
            template< typename _U_, _U_ > struct _S;                                                        \
                                                                                                            \
            template< typename _C_ > static _Y & _T( _S< _R_ ( _C_::* )( _A_ ... ) const, &_C_::_F_ > * );  \
            template< typename _C_ > static _N & _T( ... );                                                 \
                                                                                                            \
        public:                                                                                             \
                                                                                                            \
            enum { value = sizeof( _T< _T_ >( 0 ) ) == sizeof( _Y ) };                                      \
    }

namespace XS
{
    namespace TypeTraits
    {
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasSimpleAssignmentOperator,            operator = );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasAdditionAssignmentOperator,          operator += );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasSubtractionAssignmentOperator,       operator -= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasMultiplicationAssignmentOperator,    operator *= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasDivisionAssignmentOperator,          operator /= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasModuloAssignmentOperator,            operator %= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasBitwiseANDAssignmentOperator,        operator &= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasBitwiseORAssignmentOperator,         operator |= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasBitwiseXORAssignmentOperator,        operator ^= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasBitwiseLeftShiftAssignmentOperator,  operator <<= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasBitwiseRightShiftAssignmentOperator, operator >>= );
        
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasPreIncrementOperator,                operator ++ );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasPreDecrementOperator,                operator -- );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasPostIncrementOperator,               operator ++ );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasPostDecrementOperator,               operator -- );
        
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasUnaryPlusOperator,                   operator + );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasUnaryMinusOperator,                  operator - );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasAdditionOperator,                    operator + );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasSubtractionOperator,                 operator - );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasMultiplicationOperator,              operator * );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasDivisionOperator,                    operator / );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasModuloOperator,                      operator % );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasBitwiseNOTOperator,                  operator ~ );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasBitwiseANDOperator,                  operator & );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasBitwiseOROperator,                   operator | );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasBitwiseXOROperator,                  operator ^ );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasBitwiseLeftShiftOperator,            operator << );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasBitwiseRightShiftOperator,           operator >> );
        
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasNegationOperator,                    operator ! );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasANDOperator,                         operator && );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasInclusiveOROperator,                 operator || );
        
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasEqualToOperator,                     operator == );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasNotEqualToOperator,                  operator != );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasLessThanOperator,                    operator < );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasGreaterThanOperator,                 operator > );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasLessThanOrEqualToOperator,           operator <= );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_CONST_METHOD( HasGreaterThanOrEqualToOperator,        operator >= );
        
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasSubscriptOperator,                   operator [] );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasIndirectionOperator,                 operator * );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasAddressOfOperator,                   operator & );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasMemberOfPointerOperator,             operator -> );
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasPointerToMemberOfPointerOperator,    operator ->* );
        
        XS_TYPE_TRAITS_DEF_HAS_PUBLIC_METHOD(       HasFunctionCallOperator,                operator () );
        
        template< typename _T_, typename _R_, typename ... _A_ >
        class HasCommaOperator
        {
            private:
                
                struct _Y { char _[ 1 ]; };
                struct _N { char _[ 2 ]; };
                
                template< typename _U_, _U_ > struct _S;
                
                template< typename _C_ > static _Y & _T( _S< _R_ ( _C_::* )( _A_ ... ), &_C_::_F_ > * );
                template< typename _C_ > static _N & _T( ... );
                
            public:
                
                enum { value = sizeof( _T< _T_ >( 0 ) ) == sizeof( _Y ) };
        };
    }
}

#endif /* XS_ATOMIC_TRAITS_H */
