
#define SYSWRITE 1
#define SYSREAD 0

#include "mio.h"
#include "mlib.h"
#include "mstring.h"

void write(unsigned fd, const char *buf, size_t count){
    asm
        (
            "syscall"
            :
            :"a"(SYSWRITE),"D"(fd),"S"(buf),"d"(count)
        );
}

void read(unsigned fd, char *buf, size_t count){
    asm
        (
            "syscall"
            :"=S"(buf)
            :"a"(SYSREAD),"D"(fd),"d"(count)
        );
}

void print(const char *buf){
    write(1,buf,strlen(buf));
}

void scan(char *buf){
    read(0,buf,1);
    while(*buf!='\n'){
        buf++;
        read(0,buf,1);
    }
    *buf='\0';
}

void printf(const char *buf, ...){

}