// Ubuntu linux 64bit
#include "include/main.h"
#include "include/mlib.h"
#include "include/mio.h"

int main(){

    char inText[11];
    intToASCII(324,inText,10,10);
    print(inText);
    print("\n");
    printnum(540);
    return 0;
}