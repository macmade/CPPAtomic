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

#include <iostream>
#include <string>
#include <unistd.h>
#include <XS/IPC/Semaphore.hpp>
#include <XS/IPC/SharedMemory.hpp>

int main( int argc, const char * argv[] )
{
    int         i;
    std::string arg;
    
    std::cout << "Test-Helper: starting" << std::endl;
    
    for( i = 1; i < argc; i++ )
    {
        arg = argv[ i ];
        
        if( arg == "sleep" )
        {
            {
                unsigned int sec;
                
                if( i >= argc - 1 )
                {
                    std::cout << "Test-Helper: not enough arguments provided for " << arg << std::endl;
                    
                    return -1;
                }
                
                sec = static_cast< unsigned int >( std::stoi( argv[ ++i ] ) );
                
                std::cout << "Test-Helper: sleeping for " << sec << " seconds" << std::endl;
                
                sleep( sec );
            }
        }
        else if( arg == "sem-wait" || arg == "sem-signal" )
        {
            {
                unsigned int count;
                std::string  name;
                
                if( i >= argc - 2 )
                {
                    std::cout << "Test-Helper: not enough arguments provided for " << arg << std::endl;
                    
                    return -1;
                }
                
                count = static_cast< unsigned int >( std::stoi( argv[ ++i ] ) );
                name  = argv[ ++i ];
                
                {
                    XS::IPC::Semaphore sem( count, name );
                    
                    if( arg == "sem-wait" )
                    {
                        std::cout << "Test-Helper: wait on " << name << " (" << count << ")" << std::endl;
                        
                        sem.Wait();
                    }
                    else
                    {
                        std::cout << "Test-Helper: signal on " << name << " (" << count << ")" << std::endl;
                        
                        sem.Signal();
                    }
                }
            }
        }
        else if( arg == "crash" )
        {
            {
                volatile char * p( nullptr );
                
                std::cout << "Test-Helper: crashing..." << std::endl;
                
                *( p ) = 0;
            }
        }
        else if( arg == "mem-write" )
        {
            {
                int          id;
                unsigned int size;
                std::string  str;
                
                if( i >= argc - 3 )
                {
                    std::cout << "Test-Helper: not enough arguments provided for " << arg << std::endl;
                    
                    return -1;
                }
                
                id   = std::stoi( argv[ ++i ] );
                size = static_cast< unsigned int >( std::stoi( argv[ ++i ] ) );
                str  = argv[ ++i ];
                
                {
                    XS::IPC::SharedMemory mem( id, size );
                    
                    if( mem.IsValid() )
                    {
                        strcat( mem.Get< char * >(), str.c_str() );
                    }
                }
            }
        }
    }
    
    std::cout << "Test-Helper: exiting" << std::endl;
    
    return 0;
}
