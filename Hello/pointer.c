//
//  pointer.c
//  Hello
//
//  Created by Hui Zhou on 6/8/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>

#define ALLOCSIZE 10000  /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char * alloc(int n) {/*return pointer to n characters */
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
    
    
}

void afree(char *p) { /* free storage pointed by p */
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE){
        allocp = p;
    }
}

