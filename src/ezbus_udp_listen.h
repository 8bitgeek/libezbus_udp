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
#ifndef _EZBUS_UDP_LISTEN_H_
#define _EZBUS_UDP_LISTEN_H_
#include <ezbus_udp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct listen
{
    struct ip_mreq      command;
    socklen_t           sin_len;
    char                message[EZBUS_UDP_MAX_MESSAGE_SZ];
    int                 socket_descriptor;
    struct sockaddr_in  sin;
    struct hostent*     server_host_name;      
} ezbus_udp_listen_t;

extern int  ezbus_udp_listen_setup  (ezbus_udp_listen_t* listen,const char* address,int port);
extern void ezbus_udp_listen_close  (ezbus_udp_listen_t* listen);
extern int  ezbus_udp_listen_recv   (ezbus_udp_listen_t* listen,void* data,size_t size);

#ifdef __cplusplus
}
#endif

#endif
