/*****************************************************************************
* Copyright © 2021 Mike Sharkey <mike@8bitgeek.net>                          *
*                                                                            *
* Permission is hereby granted, free of charge, to any person obtaining a    *
* copy of this software and associated documentation files (the "Software"), *
* to deal in the Software without restriction, including without limitation  *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
* and/or sell copies of the Software, and to permit persons to whom the      *
* Software is furnished to do so, subject to the following conditions:       *
*                                                                            *
* The above copyright notice and this permission notice shall be included in *
* all copies or substantial portions of the Software.                        *
*                                                                            *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        *
* DEALINGS IN THE SOFTWARE.                                                  *
*****************************************************************************/
#ifndef _EZBUS_UDP_FIFO_H_
#define _EZBUS_UDP_FIFO_H_
#include <ezbus_udp.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(EZBUS_UDP_FIFO_SZ)
    #define EZBUS_UDP_FIFO_SZ           (1024*16)
#endif

#if !defined(EZBUS_UDP_FIFO_CHUNK_SZ)
    #define EZBUS_UDP_FIFO_CHUNK_SZ     (1024*2)
#endif

typedef struct fifo
{
    uint8_t*    buffer;
    size_t      size;
    size_t      head;
    size_t      tail;
    bool        overflow;
    uint8_t     chunk[EZBUS_UDP_FIFO_CHUNK_SZ];
} ezbus_udp_fifo_t;

#define ezbus_udp_fifo_overflow(fifo)   fifo->overflow
#define ezbus_udp_fifo_reset(fifo)      {fifo->overflow=false; fifo->head=fifo->tail=0}

extern bool ezbus_udp_fifo_setup  (ezbus_udp_fifo_t* fifo,size_t size);
extern void ezbus_udp_fifo_close  (ezbus_udp_fifo_t* fifo);
extern int  ezbus_udp_fifo_put    (ezbus_udp_fifo_t* fifo,const void* data,size_t size);
extern int  ezbus_udp_fifo_get    (ezbus_udp_fifo_t* fifo,void* data,size_t size);

#ifdef __cplusplus
}
#endif

#endif
