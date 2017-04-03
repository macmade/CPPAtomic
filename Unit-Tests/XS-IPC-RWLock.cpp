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
 * @brief       
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

#ifdef __clang__
#pragma clang diagnostic ignored "-Wc++98-compat-local-type-template-args"
#endif

#include <XS/IPC/RWLock.hpp>
#include <thread>
#include <atomic>

using namespace testing;

/*
TEST( XS_IPC_RWLock, SingleReader )
{
    XS::IPC::RWLock l;
    
    ASSERT_TRUE( l.TryLockForReading() );
    
    l.UnlockForReading();
}
        
TEST( XS_IPC_RWLock, SingleWriter )
{
    XS::IPC::RWLock l;
    
    ASSERT_TRUE( l.TryLockForWriting() );
    
    l.UnlockForWriting();
}
        
TEST( XS_IPC_RWLock, MultipleReaders_SameThread )
{
    XS::IPC::RWLock l;
    
    ASSERT_TRUE( l.TryLockForReading() );
    ASSERT_TRUE( l.TryLockForReading() );
    
    l.UnlockForReading();
    l.UnlockForReading();
}
        
TEST( XS_IPC_RWLock, MultipleWriters_SameThread )
{
    XS::IPC::RWLock l;
    
    ASSERT_TRUE( l.TryLockForWriting() );
    ASSERT_TRUE( l.TryLockForWriting() );
    
    l.UnlockForWriting();
    l.UnlockForWriting();
}
        
TEST( XS_IPC_RWLock, MultipleReaders_DifferentThreads )
{
    XS::IPC::RWLock     l;
    std::atomic< bool > b( false );
    
    l.LockForReading();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForReading();
            
            l.UnlockForReading();
        }
    )
    .join();
    
    ASSERT_TRUE( b );
    
    l.UnlockForReading();
}
        
TEST( XS_IPC_RWLock, MultipleWriters_DifferentThreads )
{
    XS::IPC::RWLock     l;
    std::atomic< bool > b( false );
    
    l.LockForWriting();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForWriting();
        }
    )
    .join();
    
    ASSERT_FALSE( b );
    
    l.UnlockForWriting();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForWriting();
            
            l.UnlockForWriting();
        }
    )
    .join();
    
    ASSERT_TRUE( b );
}
        
TEST( XS_IPC_RWLock, ReadWrite )
{
    XS::IPC::RWLock     l;
    std::atomic< bool > b( false );
    
    l.LockForReading();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForWriting();
        }
    )
    .join();
    
    ASSERT_FALSE( b );
    
    l.UnlockForReading();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForWriting();
            
            l.UnlockForWriting();
        }
    )
    .join();
    
    ASSERT_TRUE( b );
}
        
TEST( XS_IPC_RWLock, WriteRead )
{
    XS::IPC::RWLock     l;
    std::atomic< bool > b( false );
    
    l.LockForWriting();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForReading();
        }
    )
    .join();
    
    ASSERT_FALSE( b );
    
    l.UnlockForWriting();
    
    std::thread
    (
        [ & ]
        {
            b = l.TryLockForReading();
            
            l.UnlockForReading();
        }
    )
    .join();
    
    ASSERT_TRUE( b );
}
        
TEST( XS_IPC_RWLock, ThrowOnUnownedReadUnlock )
{
    XS::IPC::RWLock l;
    
    ASSERT_THROW( l.UnlockForReading(), std::runtime_error );
}
*/
