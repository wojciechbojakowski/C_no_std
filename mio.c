
#define SYSWRITE 1
#define SYSREAD 0

#include "include/mio.h"
#include "include/mlib.h"
#include "include/mstring.h"

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

//make it better, safer
char* intToASCII(int value, char* result,unsigned length_of_result, int base){
    if(length_of_result<2){return 0;}
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';

     while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void printnum(int num){
    char tmp[10];
    intToASCII(num,tmp,10,10);
    print(tmp);
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