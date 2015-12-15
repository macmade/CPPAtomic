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
 * @brief       Replacement of std::atomic supporting non trivially-copyable types
 */

#ifndef XS_ATOMIC_H
#define XS_ATOMIC_H

#include <type_traits>
#include <utility>
#include <atomic>
#include <mutex>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-bind-to-temporary-copy"
#endif

#include <XS/TypeTraits.hpp>

namespace XS
{
    /*!
     * @class           Atomic
     * @abstract        ...
     * @templatefield   _T_     ...
     * @discussion      ...
     */
    template< typename _T_ >
    class Atomic
    {
        private:
            
            typedef std::recursive_mutex    _M_;
            typedef std::lock_guard< _M_ >  _L_;
            
            template< class _U_ > struct TrivialValueIsEqualityComparable:          public std::integral_constant< bool, std::is_same< _U_ , bool >::value || std::is_integral< _U_ >::value || std::is_pointer< _U_ >::value > {};
            template< class _U_ > struct TrivialValueIsArithmetic:                  public std::integral_constant< bool, !std::is_same< _U_ , bool >::value && ( std::is_integral< _U_ >::value || std::is_pointer< _U_ >::value || std::is_floating_point< _U_ >::value ) > {};
            template< class _U_ > struct TrivialValueIsLogical:                     public std::integral_constant< bool, !std::is_same< _U_ , bool >::value && ( std::is_integral< _U_ >::value || std::is_pointer< _U_ >::value ) > {};
            template< class _U_ > struct TrivialValueIsBitwise:                     public std::integral_constant< bool, std::is_integral< _U_ >::value && std::is_unsigned< _U_ >::value > {};
            
            template< class _U_ > struct HasSimpleAssignmentOperator:               public std::integral_constant< bool, ( std::is_trivial<                  _U_ >::value || XS::TypeTraits::HasSimpleAssignmentOperator<              _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasAdditionAssignmentOperator:             public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasAdditionAssignmentOperator<            _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasSubtractionAssignmentOperator:          public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasSubtractionAssignmentOperator<         _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasMultiplicationAssignmentOperator:       public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasMultiplicationAssignmentOperator<      _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasDivisionAssignmentOperator:             public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasDivisionAssignmentOperator<            _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasModuloAssignmentOperator:               public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasModuloAssignmentOperator<              _U_, _U_ &, const _U_ & >::value ) && !std::is_floating_point< _U_ >::value > {};
            template< class _U_ > struct HasBitwiseANDAssignmentOperator:           public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseANDAssignmentOperator<          _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseORAssignmentOperator:            public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseORAssignmentOperator<           _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseXORAssignmentOperator:           public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseXORAssignmentOperator<          _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseLeftShiftAssignmentOperator:     public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseLeftShiftAssignmentOperator<    _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseRightShiftAssignmentOperator:    public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseRightShiftAssignmentOperator<   _U_, _U_ &, const _U_ & >::value ) > {};
            template< class _U_ > struct HasPreIncrementOperator:                   public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasPreIncrementOperator<                  _U_, _U_ &              >::value ) > {};
            template< class _U_ > struct HasPreDecrementOperator:                   public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasPreDecrementOperator<                  _U_, _U_ &              >::value ) > {};
            template< class _U_ > struct HasPostIncrementOperator:                  public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasPostIncrementOperator<                 _U_, _U_,   int         >::value ) > {};
            template< class _U_ > struct HasPostDecrementOperator:                  public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasPostDecrementOperator<                 _U_, _U_,   int         >::value ) > {};
            template< class _U_ > struct HasUnaryPlusOperator:                      public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasUnaryPlusOperator<                     _U_, _U_                >::value ) > {};
            template< class _U_ > struct HasUnaryMinusOperator:                     public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasUnaryMinusOperator<                    _U_, _U_                >::value ) > {};
            template< class _U_ > struct HasAdditionOperator:                       public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasAdditionOperator<                      _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasSubtractionOperator:                    public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasSubtractionOperator<                   _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasMultiplicationOperator:                 public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasMultiplicationOperator<                _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasDivisionOperator:                       public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasDivisionOperator<                      _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasModuloOperator:                         public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasModuloOperator<                        _U_, _U_,   const _U_ & >::value ) && !std::is_floating_point< _U_ >::value > {};
            template< class _U_ > struct HasBitwiseNOTOperator:                     public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseNOTOperator<                    _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseANDOperator:                     public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseANDOperator<                    _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseOROperator:                      public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseOROperator<                     _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseXOROperator:                     public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseXOROperator<                    _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseLeftShiftOperator:               public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseLeftShiftOperator<              _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasBitwiseLightShiftOperator:              public std::integral_constant< bool, ( TrivialValueIsBitwise<            _U_ >::value || XS::TypeTraits::HasBitwiseLightShiftOperator<             _U_, _U_,   const _U_ & >::value ) > {};
            template< class _U_ > struct HasNegationOperator:                       public std::integral_constant< bool, ( TrivialValueIsLogical<            _U_ >::value || XS::TypeTraits::HasNegationOperator<                      _U_, bool               >::value ) > {};
            template< class _U_ > struct HasANDOperator:                            public std::integral_constant< bool, ( TrivialValueIsLogical<            _U_ >::value || XS::TypeTraits::HasANDOperator<                           _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasInclusiveOROperator:                    public std::integral_constant< bool, ( TrivialValueIsLogical<            _U_ >::value || XS::TypeTraits::HasInclusiveOROperator<                   _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasEqualToOperator:                        public std::integral_constant< bool, ( TrivialValueIsEqualityComparable< _U_ >::value || XS::TypeTraits::HasEqualToOperator<                       _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasNotEqualToOperator:                     public std::integral_constant< bool, ( TrivialValueIsEqualityComparable< _U_ >::value || XS::TypeTraits::HasNotEqualToOperator<                    _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasLessThanOperator:                       public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasLessThanOperator<                      _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasGreaterThanOperator:                    public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasGreaterThanOperator<                   _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasLessThanOrEqualToOperator:              public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasLessThanOrEqualToOperator<             _U_, bool,  const _U_ & >::value ) > {};
            template< class _U_ > struct HasGreaterThanOrEqualToOperator:           public std::integral_constant< bool, ( TrivialValueIsArithmetic<         _U_ >::value || XS::TypeTraits::HasGreaterThanOrEqualToOperator<          _U_, bool,  const _U_ & >::value ) > {};
        
        public:

            /*******************************************************************
             * Common definitions
             ******************************************************************/
            
            Atomic( void ): _v{}
            {}
            
            Atomic( _T_ v ): _v{ v }
            {}
            
            Atomic( const Atomic< _T_ > & o ): Atomic< _T_ >( o, _L_( o._m ) )
            {}
            
            Atomic( const Atomic< _T_ > && o ): Atomic< _T_ >( o, _L_( o._m ) )
            {}
            
            ~Atomic( void )
            {}
            
            Atomic< _T_ > & operator =( Atomic< _T_ > o )
            {
                if( this == &o )
                {
                    return *( this );
                }
                
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v = o._v;
                
                return *( this );
            }
            
            Atomic< _T_ > & operator =( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v = v;
                
                return *( this );
            }
            
            operator _T_ ( void ) const
            {
                _L_ l( this->_m );
                
                return this->_v;
            }
            
            _T_ Load( void )
            {
                _L_ l( this->_m );
                
                return this->_v;
            }
            
            void Store( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v = v;
            }
            
            friend void swap( Atomic< _T_ > & o1, Atomic< _T_ > & o2 )
            {
                if( &o1 == &o2 )
                {
                    return;
                }
                
                std::lock( o1._m, o2._m );
                
                _L_ l1( o1._m, std::adopt_lock );
                _L_ l2( o2._m, std::adopt_lock );
                
                using std::swap;
                
                swap( o1._v, o2._v );
            }

            /*******************************************************************
             * Type specific
             ******************************************************************/
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasAdditionAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator +=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v += o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasAdditionAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator +=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v += v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasSubtractionAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator -=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v -= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasSubtractionAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator -=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v -= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasMultiplicationAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator *=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v *= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasMultiplicationAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator *=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v *= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasDivisionAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator /=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v /= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasDivisionAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator /=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v /= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasModuloAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator %=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v %= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasModuloAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator %=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v %= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseANDAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator &=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v &= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseANDAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator &=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v &= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseORAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator |=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v |= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseORAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator |=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v |= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseXORAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator ^=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v ^= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseXORAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator ^=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v ^= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseLeftShiftAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator <<=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v <<= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseLeftShiftAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator <<=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v <<= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseRightShiftAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator >>=( const Atomic< _T_ > & o )
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                this->_v >>= o._v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseRightShiftAssignmentOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator >>=( _T_ v )
            {
                _L_ l( this->_m );
                
                this->_v >>= v;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasPreIncrementOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator ++( void )
            {
                _L_ l( this->_m );
                
                this->_v++;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasPreDecrementOperator< _U_ >::value >::type >
            Atomic< _T_ > & operator --( void )
            {
                _L_ l( this->_m );
                
                this->_v--;
                
                return *( this );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasPostIncrementOperator< _U_ >::value >::type >
            Atomic< _T_ > operator ++( int )
            {
                Atomic< _T_ > a( *( this ) );
                _L_           l( this->_m );
                
                ++this->_v;
                
                return a;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasPostDecrementOperator< _U_ >::value >::type >
            Atomic< _T_ > operator --( int )
            {
                Atomic< _T_ > a( *( this ) );
                _L_           l( this->_m );
                
                --this->_v;
                
                return a;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasUnaryPlusOperator< _U_ >::value >::type >
            Atomic< _T_ > operator +( void ) const
            {
                Atomic< _T_ > a( *( this ) );
                
                a._v = +( a._v );
                
                return a;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasUnaryMinusOperator< _U_ >::value >::type >
            Atomic< _T_ > operator -( void ) const
            {
                Atomic< _T_ > a( *( this ) );
                
                a._v = -( a._v );
                
                return a;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasAdditionOperator< _U_ >::value >::type >
            Atomic< _T_ > operator +( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v + o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasAdditionOperator< _U_ >::value >::type >
            Atomic< _T_ > operator +( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v + v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasSubtractionOperator< _U_ >::value >::type >
            Atomic< _T_ > operator -( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v - o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasSubtractionOperator< _U_ >::value >::type >
            Atomic< _T_ > operator -( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v - v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasMultiplicationOperator< _U_ >::value >::type >
            Atomic< _T_ > operator *( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v * o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasMultiplicationOperator< _U_ >::value >::type >
            Atomic< _T_ > operator *( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v * v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasDivisionOperator< _U_ >::value >::type >
            Atomic< _T_ > operator /( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v / o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasDivisionOperator< _U_ >::value >::type >
            Atomic< _T_ > operator /( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v / v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasModuloOperator< _U_ >::value >::type >
            Atomic< _T_ > operator %( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v % o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasModuloOperator< _U_ >::value >::type >
            Atomic< _T_ > operator %( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v % v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseNOTOperator< _U_ >::value >::type >
            Atomic< _T_ > operator ~( void ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( ~this->_v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseANDOperator< _U_ >::value >::type >
            Atomic< _T_ > operator &( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v & o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseANDOperator< _U_ >::value >::type >
            Atomic< _T_ > operator &( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v & v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseOROperator< _U_ >::value >::type >
            Atomic< _T_ > operator |( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v | o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseOROperator< _U_ >::value >::type >
            Atomic< _T_ > operator |( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v | v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseXOROperator< _U_ >::value >::type >
            Atomic< _T_ > operator ^( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v ^ o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseXOROperator< _U_ >::value >::type >
            Atomic< _T_ > operator ^( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v ^ v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseLeftShiftOperator< _U_ >::value >::type >
            Atomic< _T_ > operator <<( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v << o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseLeftShiftOperator< _U_ >::value >::type >
            Atomic< _T_ > operator <<( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v << v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseLightShiftOperator< _U_ >::value >::type >
            Atomic< _T_ > operator >>( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return Atomic< _T_ >( this->_v >> o._v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasBitwiseLightShiftOperator< _U_ >::value >::type >
            Atomic< _T_ > operator >>( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return Atomic< _T_ >( this->_v >> v );
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasNegationOperator< _U_ >::value >::type >
            bool operator !( void ) const
            {
                _L_ l( this->_m );
                
                return !this->_v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasANDOperator< _U_ >::value >::type >
            bool operator &&( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v && o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasANDOperator< _U_ >::value >::type >
            bool operator &&( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v && v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasInclusiveOROperator< _U_ >::value >::type >
            bool operator ||( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v || o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasInclusiveOROperator< _U_ >::value >::type >
            bool operator ||( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v || v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasEqualToOperator< _U_ >::value >::type >
            bool operator ==( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v == o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasEqualToOperator< _U_ >::value >::type >
            bool operator ==( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v == v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasNotEqualToOperator< _U_ >::value >::type >
            bool operator !=( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v != o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasNotEqualToOperator< _U_ >::value >::type >
            bool operator !=( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v != v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasLessThanOperator< _U_ >::value >::type >
            bool operator <( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v < o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasLessThanOperator< _U_ >::value >::type >
            bool operator <( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v < v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasGreaterThanOperator< _U_ >::value >::type >
            bool operator >( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v > o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasGreaterThanOperator< _U_ >::value >::type >
            bool operator >( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v > v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasLessThanOrEqualToOperator< _U_ >::value >::type >
            bool operator <=( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v <= o._v;}
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasLessThanOrEqualToOperator< _U_ >::value >::type >
            bool operator <=( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v <= v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasGreaterThanOrEqualToOperator< _U_ >::value >::type >
            bool operator >=( const Atomic< _T_ > & o ) const
            {
                std::lock( this->_m, o._m );
                
                _L_ l1( this->_m, std::adopt_lock );
                _L_ l2( o._m,     std::adopt_lock );
                
                return this->_v >= o._v;
            }
            
            template< typename _U_ = _T_, typename = typename std::enable_if< std::is_same< _U_, _T_ >::value && HasGreaterThanOrEqualToOperator< _U_ >::value >::type >
            bool operator >=( _T_ v ) const
            {
                _L_ l( this->_m );
                
                return this->_v >= v;
            }
            
        private:
            
            Atomic( const Atomic< _T_ > & o, const _L_ & l ): _v{ o._v }
            {
                ( void )l;
            }
            
            Atomic( const Atomic< _T_ > && o, const _L_ & l ): _v{ std::move( o._v ) }
            {
                ( void )l;
            }
            
            _T_         _v;
            mutable _M_ _m;
    };
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif /* XS_ATOMIC_H */
