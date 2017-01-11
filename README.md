CPPAtomic
=========

[![Build Status](https://img.shields.io/travis/macmade/CPPAtomic.svg?branch=master&style=flat)](https://travis-ci.org/macmade/CPPAtomic)
[![Coverage Status](https://img.shields.io/coveralls/macmade/CPPAtomic.svg?branch=master&style=flat)](https://coveralls.io/r/macmade/CPPAtomic?branch=master)
[![Issues](http://img.shields.io/github/issues/macmade/CPPAtomic.svg?style=flat)](https://github.com/macmade/CPPAtomic/issues)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)
![License](https://img.shields.io/badge/license-mit-brightgreen.svg?style=flat)
[![Contact](https://img.shields.io/badge/contact-@macmade-blue.svg?style=flat)](https://twitter.com/macmade)  
[![Donate-Patreon](https://img.shields.io/badge/donate-patreon-yellow.svg?style=flat)](https://patreon.com/macmade)
[![Donate-Gratipay](https://img.shields.io/badge/donate-gratipay-yellow.svg?style=flat)](https://www.gratipay.com/macmade)
[![Donate-Paypal](https://img.shields.io/badge/donate-paypal-yellow.svg?style=flat)](https://paypal.me/xslabs)

About
-----

Replacement of `std::atomic` supporting **non trivially-copyable** types.

### Rationale

C++11 introduced the awesome [`std::atomic`](http://en.cppreference.com/w/cpp/atomic/atomic) template.
Unfortunately, it can only be used with [**non trivially-copyable**](http://en.cppreference.com/w/cpp/concept/TriviallyCopyable) types.

This restricts its usage to primitive types and [POD](http://en.cppreference.com/w/cpp/concept/PODType) types, meaning you can't use `std::atomic` with most C++ classes (user-defined or STL).

**CPPAtomic addresses this issue by providing a new template that can be used with non trivially-copyable types as well ass trivially-copyable types.**

As an example, assuming the following declarations:
    
    struct s
    {
        int x;
    };
    
    class A
    {};
    
    class B
    {
        public:
            
            B( void );
            B( const B & rhs );
    };
    
Here's what will happen with `std::atomic`:
    
    std::atomic< struct s >    s;   /* OK - POD type */
    std::atomic< A >           a;   /* OK - POD type */
    std::atomic< B >           b;   /* Error - Class B is not trivially-copyable */
    std::atomic< std::string > str; /* Error - std::string is not trivially-copyable */

In that example, class `B` is not trivially-copyable due to its copy constructor, so it cannot be used with `std::atomic`.

Using `XS::Atomic` instead, everything will compile and be fine:

    XS::Atomic< struct s >    s;   /* OK */
    XS::Atomic< A >           a;   /* OK */
    XS::Atomic< B >           b;   /* OK */
    XA::Atomic< std::string > str; /* OK */

### Operators

`XS::Atomic` overloads all operators, but uses type traits to enable specific overloads, depending on the type.

For instance, the following is valid, and atomic:

    XS::Atomic< int >          i{ 42 };
    XS::Atomic< unsigned int > u{ 42 };
    
    i++;
    u &= 0xFF;

The following is not (compilation error):

    XS::Atomic< double > d{ 42 };
    
    d &= 0xFF;

Bitwise operations make no sense with floating point value, so such overloads are disabled when using a floating point type.

When using classes, usual operators are also detected using type traits, and available if they are implemented:

    class Foo
    {};
    
    class Bar
    {
        public:
            
            Bar & operator +=( const Bar & rhs );
    };
    
    XS::Atomic< Foo > f;
    XS::Atomic< Bar > b;
    
    f += Foo(); /* Compiler error - Foo has no such operator */
    b += Bar(); /* Bar::operator+= will be used, atomically */

### Initialisation

All `XS::Atomic` objects initialise their values to a default one, using C++11 value initialisation (`{}`)..

As an example, an `XS::Atomic< int >` will default to `0`.
Structure types are zero-initialised as well.
For classes, the default constructor will be used.

### Implementation details

`XS::Atomic` internally ensures locking for all types.
It will use a `std::recursive_mutex`, along with `std::lock_guard` and `std::lock`.

This is necessary in order to allow operations on non trivially-copyable types, as well as operations not implemented by `std::atomic` on primitive types (see section about operators).

You might still prefer `std::atomic` for primitive types, if you're concerned about potential performance issues and if your implementation provides lock-free atomicity.

License
-------

CPPAtomic is released under the terms of the MIT license.

Repository Infos
----------------

    Owner:			Jean-David Gadina - XS-Labs
    Web:			www.xs-labs.com
    Blog:			www.noxeos.com
    Twitter:		@macmade
    GitHub:			github.com/macmade
    LinkedIn:		ch.linkedin.com/in/macmade/
    StackOverflow:	stackoverflow.com/users/182676/macmade
