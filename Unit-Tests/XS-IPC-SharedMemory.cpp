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
#include <XS/IPC/SharedMemory.hpp>

using namespace testing;

class XS_IPC_SharedMemory: public XS_IPC_TestBase
{
    public:
        
        virtual ~XS_IPC_SharedMemory( void ) = default;
};

TEST_F( XS_IPC_SharedMemory, CTOR )
{
    XS::IPC::SharedMemory mem1;
    
    ASSERT_FALSE( mem1.IsValid() );
    ASSERT_TRUE( mem1.GetSize() == 0 );
    ASSERT_EQ( mem1.Get(), nullptr );
}

TEST_F( XS_IPC_SharedMemory, CCTOR )
{
    XS::IPC::SharedMemory mem1( 666, 1024 );
    XS::IPC::SharedMemory mem2( mem1 );
    
    ASSERT_TRUE( mem1.IsValid() );
    ASSERT_TRUE( mem2.IsValid() );
    ASSERT_EQ( mem1.GetSize(), mem2.GetSize() );
    ASSERT_NE( mem1.Get(), mem2.Get() );
}

TEST_F( XS_IPC_SharedMemory, OperatorEqual )
{
    XS::IPC::SharedMemory mem1;
    XS::IPC::SharedMemory mem2;
    XS::IPC::SharedMemory mem3( 666, 1024 );
    XS::IPC::SharedMemory mem4( 666, 1024 );
    XS::IPC::SharedMemory mem5( 667, 1024 );
    XS::IPC::SharedMemory mem6( 668, 2048 );
    
    ASSERT_FALSE( mem1 == mem2 );
    ASSERT_FALSE( mem1 == mem3 );
    ASSERT_TRUE(  mem3 == mem4 );
    ASSERT_FALSE( mem4 == mem5 );
    ASSERT_FALSE( mem4 == mem6 );
}

TEST_F( XS_IPC_SharedMemory, OperatorNotEqual )
{
    XS::IPC::SharedMemory mem1;
    XS::IPC::SharedMemory mem2;
    XS::IPC::SharedMemory mem3( 666, 1024 );
    XS::IPC::SharedMemory mem4( 666, 1024 );
    
    ASSERT_TRUE(  mem1 != mem2 );
    ASSERT_TRUE(  mem1 != mem3 );
    ASSERT_FALSE( mem3 != mem4 );
}

TEST_F( XS_IPC_SharedMemory, Get )
{
    void                * p;
    XS::IPC::SharedMemory mem( 666, 1024 );
    
    p = mem.Get();
    
    ASSERT_NE( p, nullptr );
    ASSERT_EQ( p, mem.Get< char * >() );
}

TEST_F( XS_IPC_SharedMemory, GetSize )
{
    XS::IPC::SharedMemory mem( 666, 1024 );
    
    ASSERT_TRUE( mem.GetSize() == 1024 );
}

TEST_F( XS_IPC_SharedMemory, IsValid )
{
    XS::IPC::SharedMemory mem( 666, 1024 );
    
    ASSERT_TRUE( mem.IsValid() );
}

TEST_F( XS_IPC_SharedMemory, CrossProcess )
{
    XS::IPC::SharedMemory mem( 666, 1024 );
    
    ASSERT_TRUE( mem.IsValid() );
    
    memset( mem.Get(), 0, mem.GetSize() );
    
    ASSERT_TRUE( strlen( mem.Get< char * >() ) == 0 );
    
    this->RunHelper( "mem-write", { "666", "1024", "\"hello, world\"" } );
    
    ASSERT_TRUE( strcmp( mem.Get< char * >(), "hello, world" ) == 0 );
}
