#include <stdio.h>
#include "memmanager.h"



int main() {
    //prealloc_end(96);
    prealloc_end(512);
    int **a = memnew(10*sizeof(int**));
    
    for (int i=0; i<10; i++) {
        a[i] = memloc(sizeof(int*));
        *(a[i]) = i*i*i;
    }
    page_info(0);

    for (int i=0; i<10; i++) {
        printf("%d\n", *(a[i]));
        memfree(a[i]);
    }

    page_info(0);

    for (int i=0; i<10; i++) {
        a[i] = memloc(sizeof(int*));
        *(a[i]) = -i*i;
    }

    page_info(0);
    for (int i=0; i<10; i++) {
        printf("%d\n", *(a[i]));
        memfree(a[i]);
    }
    memfree(a);

    page_info(0);
    programm_end();return 0;
}
