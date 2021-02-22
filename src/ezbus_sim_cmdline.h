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
#ifndef _CMDLINE_H_
#define _CMDLINE_H_
#include <ezbus_sim.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cmdline
{
    const char*     address;
    int             port;
} cmdline_t;

#define ezbus_sim_cmdline_address(cmdline)    (cmdline)->address
#define ezbus_sim_cmdline_port(cmdline)       (cmdline)->port

extern int ezbus_sim_cmdline_setup  (cmdline_t* cmdline,int argc,char* argv[]);

#ifdef __cplusplus
}
#endif

#endif
