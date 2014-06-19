//
//  bitwise.c
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "inputOutput.h"
#include "stringUtils.h"
#include "bitwise.h"


/* Bitwise functions */
void patchBinary(char s[]){
    long size = 8 * sizeof(int);
    int i;
    int len = getLength(s);
    
    //patch with 0 if len < size
    if(len < size){
        reverse(s);
        
        for(i = len; i < size; ++i)
            s[i] = '0';
        
        s[i] = '\0';
        reverse(s);
    }
    
}

void addBinary(char s[], char t[], char sum[]){
    int size = 8 * sizeof(int);
    int i;
    int carryOver = 0;
    
    patchBinary(s);
    patchBinary(t);
    
    //    printf("addBinary s=%s\n", s);
    //    printf("addBinary t=%s\n", t);
    
    //    for(i = 0; i < size; i++){
    //        sum[i] = '0';
    //    }
    //    sum[size] = '\0';
    copy(s, sum);
    
    for(i = size - 1; i >= 0; --i){
        int ss = s[i] - '0' + t[i] - '0' + carryOver;
        sum[i] = ss % 2 + '0';
        
        if(ss >= 2)
            carryOver = 1;
        else
            carryOver = 0;
    }
    
    
}

void toBinary(int n, char s[]){
    int size = 8 * sizeof(int);
    int i;
    long longN = n;
    
    if(n < 0)
        longN = (-1l) * n;
    
    if(n == 0){
        for(i = 0; i < size; i++)
            s[i] = '0';
        s[i] = '\0';
        
    }else if(n > 0){
        i = 0;
        do {
            s[i++] = longN % 2 + '0';
        }while(( longN /= 2) > 0);
        s[i] = '\0';
        reverse(s);
        patchBinary(s);
    }else{
        char t1[size + 1], t2[size+1];
        
        i = 0;
        do{
            t1[i++] = longN % 2 + '0';
        }while((longN /= 2) > 0);
        t1[i] = '\0';
        reverse(t1);
        patchBinary(t1);
        
        //get the one complement
        for(i = 0; i < size; i++){
            t1[i]=(t1[i] + 1) % 2 + '0';
        }
        
        //create binary 1
        t2[0] = '1';
        t2[1] = '\0';
        patchBinary(t2);
        
        //two complement = add binary 1 to the one complement
        addBinary(t1, t2, s);
        
    }
    
}

int btoi(char s[]){
    int size = 8 * sizeof(int);
    int sign = 1;
    
    if(s[0] == '1')
        sign = -1;
    
    if(sign > 0){
        int n = 0;
        for(int i = 1; isdigit(s[i]); ++i) {
            n = 2 * n + (s[i] - '0');
        }
        return n;
    } else {
        int i;
        //        int carryOver = -1;
        
        //        for(i = size - 1; i >= 0; --i){
        //            int ss = s[i] - '0' + carryOver;
        //            if(ss >= 0){
        //                s[i] = '0' + ss;
        //                carryOver = 0;
        //            } else {
        //                s[i] = '1';
        //                carryOver = -1;
        //            }
        //        }
        //printf("after add -1 the binary is %s\n", s);
        
        //add -1 to s
        char t[size + 1];
        toBinary(-1, t);
        addBinary(s, t, s);
        
        //get one complement
        for(i = 0; i < size; i++){
            s[i]=(s[i] + 1) % 2 + '0';
        }
        
        long n = 0;
        for(int i = 0; isdigit(s[i]); ++i) {
            
            n = 2l * n + (s[i] - '0');
            
        }
        return (int) (sign * n);
    }
    
    
}


void itoa(int n, char s[]){
    int i, sign;
    long longN = n;
    
    if((sign = n) < 0)
        longN = (-1l) * n;
    i = 0;
    
    do {
        s[i++] = longN % 10 + '0';
    }while(( longN /= 10) > 0);
    
    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

void itoa2(long n, char s[]){
    if(n < 0){
        n = -n;
        s[0] = '-';
        s[1] = '\0';
        char s1[MAXLINE];
        s1[0] = '\0';
        itoa2(n, s1);
        strconcact(s, s1);
        
    } else {
        s[0] = '\0';
        if( n / 10)
            itoa2(n/10, s);
        char s1[MAXLINE];
        s1[0] = n % 10 + '0';
        s1[1] = '\0';
        strconcact(s, s1);
    
    
    }
    
}

void itoa1(int n, int b, char s[]){
    
    int i, sign;
    long longN = n;
    
    if(b == 2)
        toBinary(n,s);
    
    else{
        if((sign = n) < 0)
            longN = (-1l) * n;
        
        i = 0;
        do {
            if(longN % b < 10)
                s[i++] = longN % b + '0';
            else
                s[i++] = 'A' + longN % b - 10;
            
        }while(( longN /= b) > 0);
        
        if(b == 8){
            s[i++] = '0';
        } else if (b == 16){
            s[i++] = 'X';
            s[i++] = '0';
        }
        
        if(sign < 0)
            s[i++] = '-';
        
        s[i] = '\0';
        reverse(s);
    }
    
}


int getbits(int x, int p, int n){
    return (x >> (p + 1 - n)) & (~(~0 << n));
}

int setbits(int x, int p, int n, int y){
    
    char s[MAXLINE];
    //Get the right most n bits of y
    toBinary(y, s);
    printf("setbits y is %s\n", s);
    
    y = (y & (~(~0 << n)));
    toBinary(y, s);
    printf("setbits right most %d bits of y is %s\n", n, s);
    
    //set x p-n to zeros
    toBinary(x, s);
    printf("setbits x is %s\n",s);
    
    
    x = x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))));
    toBinary(x, s);
    printf("setbits x %d-%d to zero is %s\n", p, n, s);
    
    x = x | (y << (p + 1 - n));
    toBinary(x, s);
    printf("setbits x %d-%d to y is %s\n", p, n, s);
    
    return x;
    
    
    
    
}


int invertbits(int x, int p, int n){
    
    char s[MAXLINE];
    //Get the right most n bits of y
    
    //set x p-n to zeros
    toBinary(x, s);
    printf("invertbits x is %s\n",s);
    
    
    x = x ^ ((~(~0 << (p + 1))) & (~0 << (p + 1 -n)));
    toBinary(x, s);
    printf("invertbits x %d-%d inverted is %s\n", p, n, s);
    
    return x;
    
    
}

int rightrot(int x, int n){
    const int SIZE = 8 * sizeof(int);
    
    int newn = n % SIZE;
    
    if(newn > 0)
    {
        int y = (x & (~(~0 << newn))) << (SIZE - newn);
        x = (x >> newn) | y;
        
        return x;
    } else {
        return x;
    }
}

int bitcount(int x)
{
    int b;
    int SIZE = 8 * sizeof(int);
    
    for (b = 0; x != 0; x >>= 1){
        int shift = (SIZE - b) % SIZE;
        if(shift > 0)
            x = x & (~(~0 << shift));
        if (x & 01)
            b++;
    }
    return b;
}

int bitcount2(int x)
{
    int b = 0;
    
    while (x != 0){
        ++b;
        x &= (x - 1);
    }
    
    return b;
}

