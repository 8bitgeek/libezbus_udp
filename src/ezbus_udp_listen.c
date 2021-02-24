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
#include <ezbus_udp_listen.h>

extern int ezbus_udp_listen_setup(ezbus_udp_listen_t* listen,const char* address,int port)
{
    bool okay=false;
    int loop=1;

    memset(listen,0,sizeof(ezbus_udp_listen_t));
    
    if ( (listen->server_host_name = gethostbyname(address)) != NULL )
    {
        bzero(&listen->sin,sizeof(listen->sin));
        listen->sin.sin_family = AF_INET;
        listen->sin.sin_addr.s_addr = htonl(INADDR_ANY);
        listen->sin.sin_port = htons(port);

        if ( (listen->socket_descriptor = socket(PF_INET,SOCK_DGRAM,0)) >= 0 )
        {
            if ( setsockopt(listen->socket_descriptor,SOL_SOCKET,SO_REUSEADDR,&loop,sizeof(loop)) >= 0 )
            {
                if ( bind(listen->socket_descriptor,(struct sockaddr*)&listen->sin,sizeof(listen->sin)) >= 0 )
                {
                    /* Allow loopback broadcast */
                    if ( setsockopt(listen->socket_descriptor,IPPROTO_IP,IP_MULTICAST_LOOP,&loop,sizeof(loop)) >= 0 )
                    {
                        /* Join the broadcast group */
                        listen->command.imr_multiaddr.s_addr = inet_addr(address);
                        listen->command.imr_interface.s_addr = htonl(INADDR_ANY);
                        if ( listen->command.imr_multiaddr.s_addr >= 0 )
                        {
                            if ( setsockopt(listen->socket_descriptor,IPPROTO_IP,IP_ADD_MEMBERSHIP,&listen->command,sizeof(listen->command)) < 0 )
                            {
                                okay=true;
                            }
                            else
                            {
                                perror("setsockopt:IP_ADD_MEMBERSHIP");
                            }
                        }
                        else
                        {
                            perror("multicast address invalid");
                        }
                    }
                    else
                    {
                        perror("setsockopt:IP_MULTICAST_LOOP");
                    }
                }
                else
                {
                    perror("bind");
                }
            }
            else
            {
                perror("setsockopt:SO_REUSEADDR");
            }
        }
        else
        {
            perror("socket");
        }
    }
    else
    {
        perror("gethostbyname");
    }

    if ( !okay )
    {
        ezbus_udp_listen_close(listen);
    }

    return listen->socket_descriptor;
}

extern void ezbus_udp_listen_close(ezbus_udp_listen_t* listen)
{
    if ( listen->socket_descriptor >= 0 )
    {
        setsockopt(listen->socket_descriptor,IPPROTO_IP,IP_DROP_MEMBERSHIP,&listen->command,sizeof(listen->command));
        close(listen->socket_descriptor);
    }
    memset(listen,0,sizeof(ezbus_udp_listen_t));
    listen->socket_descriptor = (-1);
}

extern int ezbus_udp_listen_recv(ezbus_udp_listen_t* listen,void* message,size_t size)
{
    return recvfrom(listen->socket_descriptor,message,size,0,(struct sockaddr*)&listen->sin,&listen->sin_len);
}
