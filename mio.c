
#define SYSWRITE 1
#define SYSREAD 0

#include "mio.h"
#include "mlib.h"

void write(unsigned fd, const char *buf, size_t count){
    asm
        (
            "syscall"
            :
            :"a"(SYSWRITE),"D"(fd),"S"(buf),"d"(count)
        );
}

void print(const char *buf){

}