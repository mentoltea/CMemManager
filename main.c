#include <stdio.h>
#include "memmanager.h"

int main() {
    int **a = memloc(100*sizeof(int*));
    
    for (int i=0; i<100; i++) {
        a[i] = memloc(sizeof(int));
        *(a[i]) = i*i*i;
    }
    for (int i=0; i<100; i++) {
        printf("%d\n", *(a[i]));
        memfree(a[i]);
    }
    memfree(a);
    memloc(2*PAGE_SIZE);
    memloc(2*PAGE_SIZE);

    programm_end();return 0;
}
