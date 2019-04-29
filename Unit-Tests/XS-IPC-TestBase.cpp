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
 * @brief       ...
 */

#include "XS-IPC-TestBase.hpp"
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h>

void XS_IPC_TestBase::SetUp( void )
{
    CFBundleRef  bundle;
    CFURLRef     url;
    CFStringRef  str;
    const char * s;
    std::string  path;
    
    bundle = CFBundleGetBundleWithIdentifier( CFSTR( "com.xs-labs.CPPAtomic-Tests" ) );
    
    if( bundle == nullptr )
    {
        throw std::runtime_error( "Error getting Test-Helper path in bundle" );
    }
    
    url = CFBundleCopyBundleURL( bundle );
    
    if( url == nullptr )
    {
        throw std::runtime_error( "Error getting Test-Helper path in bundle" );
    }
    
    str = CFURLCopyFileSystemPath( url, kCFURLPOSIXPathStyle );
    
    if( str == nullptr )
    {
        throw std::runtime_error( "Error getting Test-Helper path in bundle" );
    }
    
    s = CFStringGetCStringPtr( str, kCFStringEncodingUTF8 );
    
    if( s == nullptr )
    {
        throw std::runtime_error( "Error getting Test-Helper path in bundle" );
    }
    
    path  = s;
    path += "/Contents/MacOS/Test-Helper";
    
    CFRelease( str );
    CFRelease( url );
    
    this->_helperPath = path;
}

void XS_IPC_TestBase::TearDown( void )
{}

void XS_IPC_TestBase::RunHelper( const std::string & command, const std::vector< std::string > & args ) const
{
    this->RunHelper( { { command, args } } );
}

void XS_IPC_TestBase::RunHelper( const std::map< std::string, std::vector< std::string > > & commands ) const
{
    std::string invoke;
    
    invoke  = this->_helperPath;
    
    for( const auto & p: commands )
    {
        invoke += " ";
        invoke += p.first;
        
        for( const auto & a: p.second )
        {
            invoke += " ";
            invoke += a;
        }
    }
    
    system( invoke.c_str() );
}
