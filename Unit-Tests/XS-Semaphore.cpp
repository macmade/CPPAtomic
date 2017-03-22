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

#include <XS/Semaphore.hpp>

using namespace testing;

TEST( XS_Semaphore, UnnamedBinaryTryWait )
{
    XS::Semaphore sem;
    
    ASSERT_TRUE(  sem.TryWait() );
    ASSERT_FALSE( sem.TryWait() );
    
    sem.Signal();
}

TEST( XS_Semaphore, NamedBinaryTryWait )
{
    XS::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::Semaphore sem2( 1, "XS-Test-Semaphore-1" );
    
    ASSERT_TRUE(  sem1.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    
    sem1.Signal();
    
    ASSERT_TRUE(  sem2.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    
    sem2.Signal();
}

TEST( XS_Semaphore, UnnamedTryWait )
{
    XS::Semaphore sem( 2 );
    
    ASSERT_TRUE(  sem.TryWait() );
    ASSERT_TRUE(  sem.TryWait() );
    ASSERT_FALSE( sem.TryWait() );
    
    sem.Signal();
    sem.Signal();
}

TEST( XS_Semaphore, NamedTryWait )
{
    XS::Semaphore sem1( 2, "XS-Test-Semaphore-2" );
    XS::Semaphore sem2( 2, "XS-Test-Semaphore-2" );
    
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

TEST( XS_Semaphore, UnnamedWaitSignal )
{
    XS::Semaphore sem( 1 );
    
    sem.Wait();
    
    ASSERT_FALSE( sem.TryWait() );
    
    sem.Signal();
    
    ASSERT_TRUE( sem.TryWait() );
    
    sem.Signal();
}

TEST( XS_Semaphore, NamedWaitSignal )
{
    XS::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::Semaphore sem2( 1, "XS-Test-Semaphore-1" );
    
    sem1.Wait();
    
    ASSERT_FALSE( sem1.TryWait() );
    ASSERT_FALSE( sem2.TryWait() );
    
    sem1.Signal();
    
    ASSERT_TRUE(  sem2.TryWait() );
    ASSERT_FALSE( sem1.TryWait() );
    
    sem2.Signal();
}

TEST( XS_Semaphore, UnnamedThrowOnInvalidCount )
{
    ASSERT_THROW( XS::Semaphore( 0 ), std::runtime_error );
}

TEST( XS_Semaphore, NamedThrowOnInvalidCount )
{
    ASSERT_THROW( XS::Semaphore( 0, "XS-Test-Semaphore-0" ), std::runtime_error );
}

TEST( XS_Semaphore, IsNamed )
{
    XS::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::Semaphore sem2;
    
    ASSERT_TRUE(  sem1.IsNamed() );
    ASSERT_FALSE( sem2.IsNamed() );
}

TEST( XS_Semaphore, GetName )
{
    XS::Semaphore sem1( 1, "XS-Test-Semaphore-1" );
    XS::Semaphore sem2;
    
    ASSERT_EQ( sem1.GetName(), "/XS-Test-Semaphore-1" );
    ASSERT_EQ( sem2.GetName(), "" );
}
