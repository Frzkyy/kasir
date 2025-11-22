#include "tools.h"

/*Copy string ke string lain, 
(Pengganti strcpy pada <sting.h>)*/
void strcopy(char tujuan[], const char masukan[]) {
    int i = 0;
    while (masukan[i] != '\0') {
        tujuan[i] = masukan[i];
        i++;
    }
    tujuan[i] = '\0';
}