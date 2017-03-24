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

#include <XS/Atomic-Functions.hpp>
#include <XS/IPC/Semaphore.hpp>
#include <CoreFoundation/CoreFoundation.h>
#include <string>
#include <thread>
#include <unistd.h>

using namespace testing;

class XS_IPC_Semaphore: public Test
{
    private:
        
        std::string _helperPath;
        
    public:
        
        virtual ~XS_IPC_Semaphore( void ) = default;
        
        virtual void SetUp( void )
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
        
        virtual void TearDown( void )
        {}
        
        void RunHelper( const std::string & command, const std::vector< std::string > & args ) const
        {
            this->RunHelper( { { command, args } } );
        }
        
        void RunHelper( const std::map< std::string, std::vector< std::string > > & commands ) const
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
};

TEST_F( XS_IPC_Semaphore, UnnamedBinaryTryWait )
{
    XS::IPC::Semaphore sem;
    
    ASSERT_TRUE(  sem.TryWait() );
    ASSERT_FALSE( sem.TryWait() );
    
    sem.Signal();
}

TEST_F( XS_IPC_Semaphore, NamedBinaryTryWait )
{
    XS::IPC::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::IPC::Semaphore sem2( 1, "XS-Test-Semaphore-1" );
    
    ASSERT_TRUE(  sem1.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    
    sem1.Signal();
    
    ASSERT_TRUE(  sem2.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    
    sem2.Signal();
}

TEST_F( XS_IPC_Semaphore, UnnamedTryWait )
{
    XS::IPC::Semaphore sem( 2 );
    
    ASSERT_TRUE(  sem.TryWait() );
    ASSERT_TRUE(  sem.TryWait() );
    ASSERT_FALSE( sem.TryWait() );
    
    sem.Signal();
    sem.Signal();
}

TEST_F( XS_IPC_Semaphore, NamedTryWait )
{
    XS::IPC::Semaphore sem1( 2, "XS-Test-Semaphore-2" );
    XS::IPC::Semaphore sem2( 2, "XS-Test-Semaphore-2" );
    
    ASSERT_TRUE(  sem1.TryWait() );
    ASSERT_TRUE(  sem1.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    
    sem1.Signal();
    
    ASSERT_TRUE(  sem2.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    
    sem1.Signal();
    sem2.Signal();
}

TEST_F( XS_IPC_Semaphore, UnnamedWaitSignal )
{
    XS::IPC::Semaphore sem( 1 );
    
    sem.Wait();
    
    ASSERT_FALSE( sem.TryWait() );
    
    sem.Signal();
    
    ASSERT_TRUE( sem.TryWait() );
    
    sem.Signal();
}

TEST_F( XS_IPC_Semaphore, NamedWaitSignal )
{
    XS::IPC::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::IPC::Semaphore sem2( 1, "XS-Test-Semaphore-1" );
    
    sem1.Wait();
    
    ASSERT_FALSE( sem1.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    
    sem1.Signal();
    
    ASSERT_TRUE(  sem2.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    
    sem2.Signal();
}

TEST_F( XS_IPC_Semaphore, UnnamedThrowOnInvalidCount )
{
    ASSERT_THROW( XS::IPC::Semaphore( 0 ), std::runtime_error );
}

TEST_F( XS_IPC_Semaphore, NamedThrowOnInvalidCount )
{
    ASSERT_THROW( XS::IPC::Semaphore( 0, "XS-Test-Semaphore-0" ), std::runtime_error );
}

TEST_F( XS_IPC_Semaphore, IsNamed )
{
    XS::IPC::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::IPC::Semaphore sem2;
    
    ASSERT_TRUE(  sem1.IsNamed() );
    ASSERT_FALSE( sem2.IsNamed() );
}

TEST_F( XS_IPC_Semaphore, GetName )
{
    XS::IPC::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::IPC::Semaphore sem2;
    
    ASSERT_EQ( sem1.GetName(), "/XS-Test-Semaphore-1" );
    ASSERT_EQ( sem2.GetName(), "" );
}

TEST_F( XS_IPC_Semaphore, CrossProcess )
{
    XS::IPC::Semaphore sem( 1, "XS-Test-Semaphore-1" );
    
    this->RunHelper( "sem-wait", { "1", sem.GetName() } );
    ASSERT_FALSE( sem.TryWait() );
    
    this->RunHelper( "sem-signal", { "1", sem.GetName() } );
    ASSERT_TRUE( sem.TryWait() );
    
    {
        std::atomic< bool > started( false );
        std::atomic< bool > exited( false );
        std::thread         t
        (
            [ & ]
            {
                started = true;
                
                this->RunHelper( "sem-wait", { "1", sem.GetName() } );
                
                exited = true;
            }
        );
        
        sleep( 1 );
        ASSERT_TRUE( started );
        sleep( 1 );
        ASSERT_FALSE( exited );
        sem.Signal();
        t.join();
        ASSERT_TRUE( exited );
    }
    
    sem.Signal();
    
    this->RunHelper( { { "sem-wait", { "1", sem.GetName() } }, { "crash", {} } } );
    ASSERT_TRUE( sem.TryWait() );
    sem.Signal();
}
