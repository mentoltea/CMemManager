#include <stdio.h>
#include "memmanager.h"

int main() {
    memloc(PAGE_SIZE);
    memloc(2*PAGE_SIZE);
    int *a = memloc(sizeof(int));
    for (int i=0; i<10; i++) {
        a[i] = i*i;
    }
    for (int i=0; i<10; i++) {
        printf("%d\n", a[i]);
    }

    programm_end();return 0;
}
