//
//  stringUtils.c
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stringUtils.h"


/* Util functions */
//int getLength(char s[]){
//    int i = 0;
//    
//    while(s[i] != '\0')
//        ++i;
//    
//    return i;
//}

int getLength(char *s){
//    int i;
//    
//    for(i = 0; *s != '\0'; s++)
//        i++;
//    
//    return i;
    
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}

void reverse(char s[]){
    //    char temp;
    //    int lo = 0, hi = getLength(s) - 1;
    //
    //    while(lo < hi){
    //        temp = s[lo];
    //        s[lo] = s[hi];
    //        s[hi] = temp;
    //        ++lo;
    //        --hi;
    //    }
    
    int c;
    long i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    
}

void copy(char from[], char to[]){
//    int i = 0;
//    while((to[i] = from[i]) != '\0')
//        ++i;
    strcopy(to, from);
}

void strcopy(char *s, char *t){
    while ((*s++ = *t++) != '\0')
        ;
}

int strcomp(char *s,  char *t){
//    int i;
//    for(i = 0; s[i] == t[i]; i++)
//        if(s[i] == '\0')
//            return 0;
//    return s[i] - t[i];
    
    for( ; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

int strend(char *s, char *t){
    long len1 = strlen(s);
    long len2 = strlen(t);
    
    if(len2 > len1)
        return 0;
    
    for(int i = 0; i < len1 - len2; s++, i++)
        ;
    
    for ( ; *s == *t; s++, t++)
        if(*s == '\0')
            return 1;
 
    
    return 0;
}

/* String functions */
bool isBalanceParentheses(char line[]){
    int count = 0;
    int i = 0;
    
    while(count >= 0 && i < getLength(line)){
        if(line[i] == '{')
            ++count;
        else if (line[i] == '}')
            --count;
        
        ++i;
        
    }
    
    if (count == 0)
        return true;
    else
        return false;
    
    
}

int atoi(char s[]){
    int i, n, sign;
    
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? - 1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    
    //    for (int i = 0; s[i] >='0' && s[i] <= '9';++i){
    for(int i = 0; isdigit(s[i]); ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}

int lower(int c){
    //    if (c >='A' && c<='Z')
    //        return c - ('A' - 'a');
    //    else
    //        return c;
    
    return (c >='A' && c<='Z') ? c - ('A' - 'a') : c;
    
}

int htoi (char s[]){
    int i = 0;
    int len = getLength(s);
    int n = 0;
    
    while (! (isdigit(s[i]) ||  (s[i] >= 'a' && s[i] <= 'f') || ( s[i] >= 'A' && s[i] <='F' )) && i < len)
        ++i;
    
    if(s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')){
        i = i + 2;
        
        
    }else {
        return -1;
    }
    
    while(i < len - 1){
        
        if (isdigit(s[i])){
            n = 16 * n + s[i] - '0';
        } else {
            if(s[i] >= 'a' && s[i] <= 'f')
                n = 16 * n + 10 + s[i] - 'a';
            else if(s[i] >= 'A' && s[i] <= 'F')
                n = 16 * n + 10 + s[i] - 'A';
            else
                return -1;
        }
        
        ++i;
        
        
        
    }
    return n;
    
    
}

void squeeze(char s[], int c){
    int i, j;
    
    for(i = j = 0; s[i] != '\0'; i++){
        if(s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

void squeezeMultipleCharacters(char s1[], char s2[]){
    
    int i, j;
    
    for(i = j = 0; s1[i] != '\0'; i++){
        int k = 0;
        while(s2[k] != '\0'){
            if(s1[i] == s2[k])
                break;
            
            ++k;
        }
        
        if(s2[k] == '\0')
            s1[j++] = s1[i];
        
        
    }
    
    
    s1[j] = '\0';
    
}


void strconcact(char s[], char t[]){
//    int i, j;
//    i = j = 0;
//    while(s[i] != '\0')
//        i++;
//    
//    while((s[i++] = t[j++]) != '\0');
    while(*s++ != '\0')
        ;
    while((*s++ = *t++) != '\0')
        ;
    
}

int any(char s1[], char s2[]){
    int i;
    
    for(i = 0; s1[i] != '\n'  && s1[i] != '\0'; i++){
        int k;
        
        for(k = 0; s2[k] != '\n'  && s2[k] != '\0'; k++){
            if(s1[i] == s2[k])
                return i;
        }
        
    }
    
    return -1;
    
    
}

void escape(char s[], char t[]){
    int i = 0, j =0;
    char c;
    while((c = s[i++]) != '\0'){
        switch(c){
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t' :
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default :
                t[j++] = c;
        }
        
    }
    t[j] = '\0';
}


void expend(char s[], char t[]){
    int i, j;
    i = j = 0;
    
    while(!(isdigit(s[i]) || isalpha(s[i])))
        t[j++] = s[i++];
    
    while (s[i] != '\0'){
        t[j] = s[i];
        
        if((isdigit(s[i]) && s[i+1] == '-' && isdigit(s[i+2]) && s[i+2] > s[i])
           || (isalpha(s[i]) && s[i+1] == '-' && isalpha(s[i+2]) && s[i+2] > s[i])){
            int index = 0;
            while(index < s[i+2] - s[i]){
                j++;
                t[j] = t[j - 1] + 1;
                index++;
            }
            t[j] = s[i+2];
            i += 2;
        }
        i++;
        j++;
    }
}

int trim(char s[]){
    int n;
    for(n = (int)strlen(s) - 1; n>=0; --n)
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return n;
}

int strindex(char s[], char t[]) {
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char s[], char t[]) {
    int i, j, k;
    for(i = (int)strlen(s) - 1; i >= 0; i--){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int grep(){
    char s[MAXLINE];
    char pattern[100];
    
    int found = 0;
    
    printf("Please enter the pattern to grep\n");
    getLine(pattern, false);
    
    printf("Please enter the tests to grep\n");
    
    while(getLine(s, false) > 0)
        if(strindex(s, pattern) >= 0){
            printf("%s\n", s);
            found++;
        }
    return found;
}

double atof(char s[]){
    double val, power;
    int i, sign, sign2, power2;
    
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1 : 1;
    
    if(s[i] == '+' || s[i] == '-')
        i++;
    
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if(s[i] == '.')
        i++;
    
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    if(s[i] == 'e')
        i++;
    
    sign2 = 1;
    
    if(s[i] == '+')
        i++;
    
    if(s[i] == '-'){
        sign2 = -1;
        i++;
    }
    
    for(power2 = 0; isdigit(s[i]); i++)
        power2 = 10 * power2 + (s[i] - '0');
    
    for(int j = 0; j < power2; j++){
        if(sign2 > 0){
            val = val * 10.0;
        } else {
            val = val / 10.0;
        }
    }
    
    return sign * val / power;
}

double sum(){
    double sum;
    char s[MAXLINE];
    printf("Enter numbers to sum\n");
    
    sum = 0.0;
    while(getLine(s, false) > 0){
        sum += atof(s);
    }
    return sum;
}

void printd(int n){
    if (n < 0){
        putchar('-');
        n = -n;
    }
    if(n / 10)
        printd( n /10);
    putchar( n % 10 + '0');
}