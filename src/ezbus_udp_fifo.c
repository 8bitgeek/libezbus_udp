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
#include <ezbus_udp_fifo.h>

static void ezbus_udp_fifo_put_ch(ezbus_udp_fifo_t* fifo,uint8_t ch);
static int  ezbus_udp_fifo_get_ch(ezbus_udp_fifo_t* fifo);

extern bool ezbus_udp_fifo_setup(ezbus_udp_fifo_t* fifo,size_t size)
{
    memset(fifo,0,sizeof(ezbus_udp_fifo_t));
    fifo->size = size > 0 ? size : EZBUS_UDP_FIFO_SZ;
    fifo->buffer=(uint8_t*)malloc(fifo->size);
    return fifo->buffer != NULL;
}

extern void ezbus_udp_fifo_close(ezbus_udp_fifo_t* fifo)
{
    if ( fifo->buffer )
    {
        free(fifo->buffer);
    }
    memset(fifo,0,sizeof(ezbus_udp_fifo_t));
}

extern int ezbus_udp_fifo_put(ezbus_udp_fifo_t* fifo,const void* data,size_t size)
{
    int n;
    uint8_t* p=(uint8_t*)data;
    for(n=0; n < size && !fifo->overflow; n++)
    {
        ezbus_udp_fifo_put_ch(fifo,*p++);
    }
    return n;
}

extern int ezbus_udp_fifo_get(ezbus_udp_fifo_t* fifo,void* data,size_t size)
{
    int n;
    uint8_t* p=(uint8_t*)data;
    fifo->overflow=false;
    for(n=0; n < size; n++)
    {
        int ch = ezbus_udp_fifo_get_ch(fifo);
        
        if ( ch >= 0 )
            *p++ = ch;
        else
            break;
    }
    return n;
}

static void ezbus_udp_fifo_put_ch(ezbus_udp_fifo_t* fifo,uint8_t ch)
{
    fifo->buffer[fifo->head++] = ch;
    
    if ( fifo->head >= fifo->size )
        fifo->head = 0;

    if ( fifo->head == fifo->tail )
    {
        fifo->overflow = true;
    }
}

static int ezbus_udp_fifo_get_ch(ezbus_udp_fifo_t* fifo)
{
    if ( fifo->tail != fifo->head )
    {
        int ch = fifo->buffer[fifo->tail++];

        if ( fifo->tail >= fifo->size )
            fifo->tail = 0;

        return ch;
    }
    return -1;
}
