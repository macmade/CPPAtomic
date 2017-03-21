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

#ifndef XS_ATOMIC_FUNCTIONS_HPP
#define XS_ATOMIC_FUNCTIONS_HPP

/*
 * Using stdint.h rather than cstdint as exact-width integer types are optional
 */
#include <stdint.h>

namespace XS
{
    /*!
     * @brief       Issues a memory barrier/fence
     * 
     * Currently, this function is implemented for the following
     * architectures:
     *     - ARMv7
     *     - ARM64
     *     - x86
     *     - x86-64
     */
    void MemoryBarrier( void );
    
    /*!
     * @brief       Atomically increments a 32 bits integer value
     * @param       value       The value to increment
     * @return      The incremented value
     */
    int32_t AtomicIncrement32( volatile int32_t * value );
    
    /*!
     * @brief       Atomically increments a 32 bits integer value
     * @param       value       The value to increment
     * @return      The incremented value
     */
    int64_t AtomicIncrement64( volatile int64_t * value );
    
    /*!
     * @brief       Atomically decrements a 64 bits integer value
     * @param       value       The value to decrement
     * @return      The decremented value
     */
    int32_t AtomicDecrement32( volatile int32_t * value );
    
    /*!
     * @brief       Atomically decrements a 64 bits integer value
     * @param       value       The value to decrement
     * @return      The decremented value
     */
    int64_t AtomicDecrement64( volatile int64_t * value );
    
    /*!
     * @brief       Atomically adds to a 32 bits value
     * @param       amount      The amount to add
     * @param       value       The 32 bits value to modify
     * @return      The new value
     */
    int32_t AtomicAdd32( int32_t amount, volatile int32_t * value );
    
    /*!
     * @brief       Atomically adds to a 64 bits value
     * @param       amount      The amount to add
     * @param       value       The 64 bits value to modify
     * @return      The new value
     */
    int64_t AtomicAdd64( int64_t amount, volatile int64_t * value );
    
    /*!
     * @brief       Performs an atomic compare and swap on 32 bits integer values
     * @param       oldValue    The value to compare to (old value)
     * @param       newValue    The value to swap (new value)
     * @param       value       A pointer to the 32 bits integer value to compare and swap
     * @return      True if the comparison was equal and the swap occured, otherwise false
     */
    bool AtomicCompareAndSwap32( int32_t oldValue, int32_t newValue, volatile int32_t * value );
    
    /*!
     * @brief       Performs an atomic compare and swap on 64 bits integer values
     * @param       oldValue    The value to compare to (old value)
     * @param       newValue    The value to swap (new value)
     * @param       value       A pointer to the 64 bits integer value to compare and swap
     * @return      True if the comparison was equal and the swap occured, otherwise false
     */
    bool AtomicCompareAndSwap64( int64_t oldValue, int64_t newValue, volatile int64_t * value );
    
    /*!
     * @brief       Performs an atomic compare and swap on pointer values
     * @param       oldValue    The value to compare to (old value)
     * @param       newValue    The value to swap (new value)
     * @param       value       A pointer to the pointer value to compare and swap
     * @return      True if the comparison was equal and the swap occured, otherwise false
     */
    bool AtomicCompareAndSwapPointer( void * oldValue, void * newValue, void * volatile * value );
}

#endif /* XS_ATOMIC_FUNCTIONS_HPP */
