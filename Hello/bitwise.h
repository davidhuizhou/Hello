//
//  bitwise.h
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

/* Bitwise functions */
void patchBinary(char s[]);
void addBinary(char s[], char t[], char sum[]);
void toBinary(int n, char s[]);
int btoi(char s[]);
void itoa(int n, char s[]);
void itoa1(int n, int b, char s[]);
void itoa2(long n, char s[]);
int getbits(int x, int p, int n);
int setbits(int x, int p, int n, int y);
int invertbits(int x, int p, int n);
int rightrot(int x, int n);
int bitcount(int x);
int bitcount2(int x);