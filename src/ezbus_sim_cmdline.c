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
#include <ezbus_sim_cmdline.h>

extern char *optarg;
extern int optind, opterr, optopt;

extern int ezbus_sim_cmdline_setup(cmdline_t* cmdline,int argc, char* argv[])
{
    int opt;

    memset(cmdline,0,sizeof(cmdline_t));
    cmdline->address = ezbus_sim_default_address();
    cmdline->port = ezbus_sim_default_port();

    while ((opt = getopt(argc, argv, "a:p:")) != -1) 
    {
        switch (opt) 
        {
            case 'a':
                cmdline->address = optarg;
                break;
            case 'p':
                cmdline->port = atoi(optarg);
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-a address] [-p port]\n",
                argv[0]);
                return -1;
        }
    }

    if (optind >= argc) 
    {
        fprintf(stderr, "missing argument\n");
        return -1;
    }

    return 0;
}
