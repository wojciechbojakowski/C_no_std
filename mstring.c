#include "include/mlib.h"
#include "include/mstring.h"

size_t strlen(const char *str){
    size_t len=0;
    while(*str != '\0'){
        len++;
        str++;
    }
    return len;
}