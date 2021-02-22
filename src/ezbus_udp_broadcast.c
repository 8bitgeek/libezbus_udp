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
#include <ezbus_udp_broadcast.h>

extern int ezbus_udp_broadcast_setup(broadcast_t* broadcast,const char* address,int port)
{
    memset(broadcast,0,sizeof(broadcast_t));
    broadcast->socket_descriptor = socket(AF_INET,SOCK_DGRAM,0);
    if ( broadcast->socket_descriptor >= 0 )
    {
        broadcast->address.sin_family = AF_INET;
        broadcast->address.sin_addr.s_addr = inet_addr(address);
        broadcast->address.sin_port = htons(port);
    }
    return broadcast->socket_descriptor;
}

extern void ezbus_udp_broadcast_close(broadcast_t* broadcast)
{
    if (broadcast->socket_descriptor >= 0 )
    {
        close(broadcast->socket_descriptor);
    }
    memset(broadcast,0,sizeof(broadcast_t));
    broadcast->socket_descriptor = (-1);
}

extern int ezbus_udp_broadcast_send(broadcast_t* broadcast,const void* data,size_t size)
{
    return sendto(
                    broadcast->socket_descriptor,
                    data,
                    size,
                    0,
                    (struct sockaddr*)&broadcast->address,sizeof(broadcast->address)
                 );
}
