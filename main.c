// Ubuntu linux 64bit

#include "mlib.h"
#include "mio.h"

void _start(){
    write(1,"Hello world",11);
    sysExit(12);
}