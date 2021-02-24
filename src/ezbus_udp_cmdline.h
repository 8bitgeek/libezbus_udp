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
#ifndef EZBUS_UDP_CMDLINE_H_
#define EZBUS_UDP_CMDLINE_H_
#include <ezbus_udp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cmdline
{
    const char*     address;
    int             port;
    uint32_t        id;
} ezbus_udp_cmdline_t;

#define ezbus_udp_cmdline_address(cmdline)    (cmdline)->address
#define ezbus_udp_cmdline_port(cmdline)       (cmdline)->port
#define ezbus_udp_cmdline_id(cmdline)         (cmdline)->id

extern int ezbus_udp_cmdline_setup(ezbus_udp_cmdline_t* cmdline,int argc,char* argv[]);

#ifdef __cplusplus
}
#endif

#endif
