// Ubuntu linux 64bit

#include "mlib.h"

void sysExit(int errcode){
    asm volatile(
        "syscall"
        :
        :"a"(SYSEXIT),"D"(errcode)
    );
}