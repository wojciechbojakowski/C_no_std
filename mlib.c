// Ubuntu linux 64bit

#include "include/mlib.h"
#include "include/main.h"
#include "include/mio.h"

void sysExit(int errcode){
    asm volatile(
        "syscall"
        :
        :"a"(SYSEXIT),"D"(errcode)
    );
}

processError(int code){
    if(code == 0){
        print("\nProgram finished successfully :)\n");
    }else{
        print("\nProgram finished with error :( \n");
        print(code);
        print("\n");
    }
}

void _start(){
    processError(main());
    sysExit(12);
}