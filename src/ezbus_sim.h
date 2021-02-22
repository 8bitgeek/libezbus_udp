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
#ifndef _EZBUS_SIM_H_
#define _EZBUS_SIM_H_

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#if !defined(EZBUS_SIM_MAX_MESSAGE_SZ)
    #define EZBUS_SIM_MAX_MESSAGE_SZ    1500
#endif 

#if !defined(EZBUS_SIM_ADDRESS)
    #define EZBUS_SIM_ADDRESS           "224.0.0.1"
#endif

#if !defined(EZBUS_SIM_PORT)
    #define EZBUS_SIM_PORT              8260
#endif

#define ezbus_sim_default_address()     EZBUS_SIM_ADDRESS
#define ezbus_sim_default_port()        EZBUS_SIM_PORT

#endif

