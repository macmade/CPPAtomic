CPPAtomic
=========

[![Build Status](https://img.shields.io/travis/macmade/CPPAtomic.svg?branch=master&style=flat)](https://travis-ci.org/macmade/CPPAtomic)
[![Coverage Status](https://img.shields.io/coveralls/macmade/CPPAtomic.svg?branch=master&style=flat)](https://coveralls.io/r/macmade/CPPAtomic?branch=master)
[![Issues](http://img.shields.io/github/issues/macmade/CPPAtomic.svg?style=flat)](https://github.com/macmade/PIMPL/issues)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)
![License](https://img.shields.io/badge/license-boost-brightgreen.svg?style=flat)
[![Contact](https://img.shields.io/badge/contact-@macmade-blue.svg?style=flat)](https://twitter.com/macmade)

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

### Implementation details

...

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
