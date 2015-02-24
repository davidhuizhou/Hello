//
//  test.c
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include "calc.h"
#include "inputOutput.h"
#include "stringUtils.h"
#include "searchSortUtils.h"
#include "bitwise.h"
#include "test.h"



#define     LOWER   0
#define     UPPER   300
#define     STEP    20

#define     IN      1
#define     OUT     0

#define     aboveTopHistogram       "          "
#define     topHistogram            " ___      "
#define     belowTopHistogram       "|   |     "



/* test functions */
void testBasics(){
    printFahrenheitCelsiusTable();
    printf("4^6 = %d\n", power(4, 6));
    //copyInputOutput();
    //printHistogram();
    printLogestLine();
}


void testBitwise() {
    long size = 8 * sizeof(int);
    char s[size + 1], t[size + 1], sum[size + 1];
    int len;
    
    //    len = getLine(s, false);
    //    printf("len=%d, line is - %s\n", len, s);
    //
    //    len = getLine(t, false);
    //    printf("len=%d, line is - %s\n", len, t);
    //
    //    patchBinary(s);
    //    printf("patched s is %s\n", s);
    //    patchBinary(s);
    //    printf("patched s is %s\n", s);
    //    patchBinary(t);
    //    printf("patched t is %s\n", t);
    //
    //    addBinary(s, t, sum);
    //    printf("sum=%s\n", sum);
    //
    //    toBinary(0, s);
    //    printf("Binary of 0 is %s\n", s);
    //
    //    toBinary(12, s);
    //    printf("Binary of 12 is %s\n", s);
    //
    //    toBinary(-12, t);
    //    printf("Binary of -12 is %s\n", t);
    //
    //    addBinary(s, t, sum);
    //    printf("sum=%s\n", sum);
    //
    //    toBinary(-114, s);
    //    printf("Binary of -114 is %s\n", s);
    //
    //    toBinary(-102, s);
    //    printf("Binary of -102 is %s\n", s);
    //
    //    toBinary(-12, t);
    //    printf("Binary of -12 is %s\n", t);
    //
    //    addBinary(s, t, sum);
    //    printf("sum=%s\n", sum);
    //
    //    printf("s=%d\n", btoi(s));
    //    printf("t=%d\n", btoi(t));
    //    printf("sum=%d\n", btoi(sum));
    //
    //    toBinary(INT_MAX, s);
    //    printf("Binary of INT_MAX is %s\n", s);
    //
    //    printf("%d\n", btoi(s));
    //
    //    toBinary(INT_MIN + 1, s);
    //    printf("Binary of INT_MIN + 1 is %s\n", s);
    //
    //    printf("%d\n", btoi(s));
    //
    //    toBinary(INT_MIN, s);
    //    printf("Binary of INT_MIN is %s\n", s);
    //
    //    printf("%d\n", btoi(s));
    
    itoa(111, s);
    printf("itoa(111)=%s\n", s);
    
    itoa2(111l, s);
    printf("itoa2(111)=%s\n", s);
    
    itoa(0, s);
    printf("itoa(0)=%s\n", s);
    
    itoa2(0l, s);
    printf("itoa2(0)=%s\n", s);
    
    itoa(-12345, s);
    printf("itoa(-12345)=%s\n", s);
    
    itoa2(-12345, s);
    printf("itoa2(-12345)=%s\n", s);
    
    itoa(INT_MAX, s);
    printf("itoa(INT_MAX)=%s\n", s);
    
    itoa2(INT_MAX, s);
    printf("itoa2(INT_MAX)=%s\n", s);
    
    itoa(INT_MIN, s);
    printf("itoa(INT_MIN)=%s\n", s);
    
    itoa2(INT_MIN, s);
    printf("itoa2(INT_MIN)=%s\n", s);
    
    itoa1(17, 2, s);
    printf("itoa1(17, 2)=%s\n", s);
    
    itoa1(17, 8, s);
    printf("itoa1(17, 8)=%s\n", s);
    
    itoa1(17, 10, s);
    printf("itoa1(17, 10)=%s\n", s);
    
    itoa1(17, 16, s);
    printf("itoa1(17, 16)=%s\n", s);
    
    toBinary(1120, s);
    printf("1120 binary=%s\n", s);
    
    int bits = getbits(1120, 10, 7);
    toBinary(bits, s);
    printf("getbits(1120, 10, 7) is%s\n", s);
    
    
    setbits(12345, 7, 4, 77);
    
    invertbits(123, 7, 3);
    
    toBinary(123, s);
    printf("123 binary is %s\n", s);
    printf("123 binary has %d of 1 bits\n", bitcount(123));
    printf("123 binary has %d of 1 bits\n", bitcount2(123));
    
    
    toBinary(rightrot(123, 5), s);
    printf("right(123, 5) is %s\n", s);
    
    toBinary(-123, s);
    printf("-123 binary is %s\n", s);
    printf("-123 binary has %d of 1 bits\n", bitcount(-123));
    printf("-123 binary has %d of 1 bits\n", bitcount2(-123));
    
    
    
}


void testStringFunctions(){
    extern char line[];
    char s[MAXLINE];
    char t[MAXLINE];
    int len;
    //    len = getLine(line, true);
    //    printf("This input is %s\n", line);
    //    printf("isBalanceParentheses is %d\n", isBalanceParentheses(line));
    //
    //    len = getLine(line, true);
    //    printf("The number is %d\n", atoi(line));
    //
    //    len = getLine(line, true);
    //
    //    int i = 0;
    //    while(i < len){
    //        putchar(lower(line[i]));
    //        ++i;
    //    }
    //
    //    len = getLine(line, true);
    //    printf("htoi %d\n", htoi(line));
    
    //    len = getLine(line, true);
    //    squeeze(line, 'c');
    //    printf("%s\n", line);
    
    //    len = getLine(line, true);
    //    len = getLine(s, true);
    //    squeezeMultipleCharacters(line, s);
    //    printf("After squeezeMultipleCharacters the line is-%s\n", line);
    
    //    len = getLine(line, false);
    //    len = getLine(s, false);
    //    strcat(line, s);
    //    printf("strcat=%s\n", line);
    
    //    len = getLine(line, false);
    //    len = getLine(s, false);
    //    printf("position any is %d\n", any(line, s));
    
    //    len = getLine(s, true);
    //    escape(s, t);
    //    printf("%s\n", t);
    printf("Enter a sentence to expend\n");
    len = getLine(s, true);
    
    printf("strlen(s)=%ld\n", strlen(s));
    int n = trim(s);
    printf("After trim strlen(s)=%ld\n", strlen(s));
    
    expend(s, t);
    printf("%s\n", t);
    
    expend("-a-m", t);
    printf("-a-m=%s\n", t);
    
    expend("a-b-c", t);
    printf("a-b-c=%s\n", t);
    
    expend("-a-z", t);
    printf("-a-z=%s\n", t);
    
    expend("a-z0-9", t);
    printf("a-z0-9=%s\n", t);
    
    //    grep();
    //
    //    printf("Enter pattern for strrindex\n");
    //    char pattern[100];
    //    getLine(pattern, false);
    //    printf("Enter a setence for strrindex\n");
    //    getLine(s, false);
    //    printf("strrindex(s, pattern)=%d\n", strrindex(s, pattern));
    
    printf("112.34=%f\n", atof("112.34"));
    printf("112.34e2=%f\n", atof("112.34e2"));
    
    printf("112.34e2=%f\n", atof("112.34e+2"));
    printf("112.34e2=%f\n", atof("112.34e-3"));
    
    double sss = sum();
    printf("The sss is %f\n", sss);
    
    printd(INT_MAX);
    printf("\n");
    
    char s1[] = "abcd";
    char t1[] = "efg";
    
    copy(t1, s1);
    printf("After copy s1 is %s\n", s1);
    
    char *s2 = "abcd";
    char *t2 = "bce";
    printf("strcomp(s2, t2)=%d\n", strcomp(s2, t2));
    printf("strend(s1, t2)=%d\n", strend(s2, t2));
    
}

void testSearchAndSort(){
    //int v[10] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 12};
    int v[10] = {12, 2, 11, 5, 10, 7, 9, 1, 6, 3};
//    shellsort(v, 10);
    qsort(v, 0, 9);
    
    int p = -1;
    
    p = binsearch(1, v, 10);
    printf("binsearch(1, v, 9)=%d\n", p);
    p = binsearch(2, v, 10);
    printf("binsearch(2, v, 9)=%d\n", p);
    p = binsearch(3, v, 10);
    printf("binsearch(3, v, 9)=%d\n", p);
    p = binsearch(4, v, 10);
    printf("binsearch(4, v, 9)=%d\n", p);
    p = binsearch(5, v, 10);
    printf("binsearch(5, v, 9)=%d\n", p);
    p = binsearch(6, v, 10);
    printf("binsearch(6, v, 9)=%d\n", p);
    p = binsearch(7, v, 9);
    printf("binsearch(7, v, 9)=%d\n", p);
    p = binsearch(8, v, 10);
    printf("binsearch(8, v, 9)=%d\n", p);
    p = binsearch(9, v, 10);
    printf("binsearch(9, v, 9)=%d\n", p);
    p = binsearch(10, v, 10);
    printf("binsearch(10, v, 9)=%d\n", p);
    p = binsearch(11, v, 10);
    printf("binsearch(11, v, 9)=%d\n", p);
    
    p = binsearch(-11, v, 10);
    printf("binsearch(-11, v, 9)=%d\n", p);
    p = binsearch(13, v, 10);
    printf("binsearch(13, v, 9)=%d\n", p);
    
    p = binsearch(12, v, 10);
    printf("binsearch(12, v, 9)=%d\n", p);
    
    
    
}

void testCalculator(){
    testGetInt();
    calculator();
}

/* Basic functions */
//print Fahrenheit-Celsius table
void printFahrenheitCelsiusTable()
{
    float fahr, celsius;
    
    fahr = LOWER;
    printf("%4s %7s\n", "fahr", "celsius");
    
    while(fahr <= UPPER) {
        celsius = fahrenheitToCelsius(fahr);
        printf("%4.0f %7.2f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
    
    for (fahr = 0; fahr <= UPPER; fahr = fahr + STEP)
        printf("%4.0f %7.2f\n", fahr, (5.0/9.0) * (fahr - 32));
    
    for(fahr = 300; fahr >= LOWER; fahr = fahr - STEP)
        printf("%4.0f %7.2f\n", fahr, (5.0/9.0) * (fahr - 32));
}

float fahrenheitToCelsius(float fahr){
    return 5.0 * (fahr - 32.0) /9.0;
}

int power(int base, int n){
    int p;
    
    for(p = 1; n >= 1; --n){
        p = p * base;
    }
    
    return p;
}



void printLogestLine() {
    int len;
    extern int max;
    extern char line[], longest[];
    
    max = 0;
    while((len = getNextLine()) > 0)
        
        if(len > max){
            max = len;
            copy(line, longest);
            reverse(line);
            printf("reversed line is - %s\n", line);
        }
    
    if(max > 0)
        printf("\nThe longest line is\n%s\n", longest);
    
}




/* Copy input to output */
void copyInputOutput()
{
    printf("Enter characters\n");
    int c;
    while((c = getchar()) != EOF)
        putchar(c);
}




/* Histogram functions */

//copy input to output and print histogram
void printHistogram()
{
    int c;
    long nc = 0;
    long nl = 0;
    long nb = 0;
    long nt = 0;
    long nw = 0;
    long ndigit[10];
    long nother = 0;
    long nwhite = 0;
    int state = OUT;
    
    //Initialize number of digits to 0
    for (int i = 0; i < 10; i++){
        ndigit[i] = 0;
    }
    
    printf("Please type something:\n");
    while ((c = getchar()) != EOF){
        
        ++nc;
        
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if(c == '\n'){
            ++nl;
            ++nother;
        } else if (c== '\t'){
            ++nt;
            ++nwhite;
            ++nother;
        }else if (c == ' '){
            ++nb;
            ++nwhite;
            ++nother;
        }
        
        if (c == ' ' || c == '\t'  || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
            putchar('\n');
        }
        
        putchar(c);
    }
    
    long max = ndigit[0];
    printf("number of digits:");
    for(int i = 0; i < 10; i++){
        printf("number of %d is %ld\n", i, ndigit[i]);
        if(ndigit[i] > max)
            max = ndigit[i];
    }
    
    printf("The number of characters is %4ld\n", nc);
    printf("The number of lines is %4ld\n", nl);
    printf("The number of tabs is %4ld\n", nt);
    printf("The number of blanks is %4ld\n", nb);
    printf("The number of words is %4ld\n", nw);
    printf("The number of white is %4ld\n", nwhite);
    printf("The number of no digits is %4ld\n", nother);
    
    if(nc > max)
        max = nc;
    else if (nl > max)
        max = nl;
    else if (nt > max)
        max = nt;
    else if (nb > max)
        max = nb;
    else if (nw > max)
        max = nw;
    else if (nwhite > max)
        max = nwhite;
    else if (nother > max)
        max = nother;
    
    printf("The max is %ld\n", max);
    
    
    for (int i = (int) max + 2; i >= -1; i--){
        
        if(i == -1){
            for(int j = 0; j < 190; j++)
                printf("-");
        } else {
            printf("|         ");
            
            for (int j = 0; j < 10; j++){
                printf("%s", getHistogramSection(ndigit[j], i));
            }
            printf("%s", getHistogramSection(nc, i));
            printf("%s", getHistogramSection(nl, i));
            printf("%s", getHistogramSection(nt, i));
            printf("%s", getHistogramSection(nb, i));
            printf("%s", getHistogramSection(nw, i));
            printf("%s", getHistogramSection(nwhite, i));
            printf("%s", getHistogramSection(nother, i));
            
        }
        printf("\n");
        
        
    }
    printf("\n          ");
    printf("zero      ");
    printf("one       ");
    printf("two       ");
    printf("three     ");
    printf("four      ");
    printf("five      ");
    printf("six       ");
    printf("seven     ");
    printf("eight     ");
    printf("nine      ");
    printf("nc        ");
    printf("nl        ");
    printf("nt        ");
    printf("nb        ");
    printf("nw        ");
    printf("nwhite    ");
    printf("nother    ");
    
    
}

char* getHistogramSection (long number, int position) {
    
    if(number == 0 || number < position)
        return aboveTopHistogram;
    else if (number == position)
        return topHistogram;
    else
        return belowTopHistogram;
    
    
}