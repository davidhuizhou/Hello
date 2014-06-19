//
//  stringUtils.h
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//
#include "inputOutput.h"

/* Util functions */
//int getLength(char s[]);
int getLength(char *s);
void reverse(char s[]);
void copy(char from[], char to[]);
void strcopy(char *s, char *t);
int strcomp(char *s,  char *t);
int strend(char *s, char *t);

/* String functions */
bool isBalanceParentheses(char line[]);
int atoi(char s[]);
int lower(int c);
int htoi (char s[]);
void squeeze(char s[], int c);
void squeezeMultipleCharacters(char s1[], char s2[]);
void strconcact(char s[], char t[]);
int any(char s1[], char s2[]);
void escape(char s[], char t[]);
void expend(char s[], char t[]);
int trim(char s[]);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);
int grep();
double atof(char s[]);
double sum();
void printd(int n);