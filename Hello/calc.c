//
//  calc.c
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include "stringUtils.h"
#include "calc.h"

#define     MAXOP   100 /* max size of operand or operator */
#define     NUMBER  '0' /* signal that a number was found */
#define     MAXVAL 100 /* maximum depth of val stack */
#define     BUFSIZE 100

static int getop(char []);
static void push(double);
static double pop(void);

static int getch(void);
static void ungetch(int);
int getint(int *pn);
int getdouble(double *pd);
void testGetInt();

void calculator();

static int sp = 0; /* next free stack position */
static double val[MAXVAL]; /* value stack */

/* Calculator function */
void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


static char buf[BUFSIZE];  /* buffer for ungetch */
static int  bufp = 0;      /* next free position in buf */

/* get a (possibly pushed back) character */
int getch (void) {
    return (bufp > 0)? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch (int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c, sign;
    while (isspace(c = getch())) /* skip the white spaces */
        ;
    
    if(!isdigit(c) && c != EOF && c != '+'  && c != '-'){
//        ungetch(c);
        *pn = 0;
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    
    if ( c == '+' || c == '-')
        c = getch();
    
    if(!isdigit(c)){
//        ungetch(c);
        *pn = 0;
        return 0;
    }
    
    for(*pn = 0; isdigit(c);c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
//    if(c != EOF)
//        ungetch(c);
    return c;
    
}

/* getint: get next integer from input into *pn */
int getdouble(double *pd){
    int c, sign, sign2, power2;
    double power;
    
    while (isspace(c = getch())) /* skip the white spaces */
        ;
    
    if(!isdigit(c) && c != EOF && c != '+'  && c != '-'){
        //ungetch(c);
        *pd = 0.0;
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if ( c == '+' || c == '-')
        c = getch();
    
    if(!isdigit(c)){
        //  ungetch(c);
        *pd = 0.0;
        return 0;
    }
    
    for(*pd = 0.0; isdigit(c); c = getch())
        *pd = 10.0 * *pd + 1.0 * (c - '0');
    
    power = 1.0;
    power2 = 0;
    
    if(c == '.') {
        c = getch();
        
        if(!isdigit(c)){
            //  ungetch(c);
            *pd = 0.0;
            return 0;
        }
        
        for(power = 1.0; isdigit(c); c = getch()){
            *pd = 10.0 * *pd + 1.0 * (c - '0');
            power *= 10.0;
        }
        
        printf("power=%f\n", power);
        
    }
    
    if(c == 'e') {
        c = getch();
        
        sign2 = 1;
        
        if(c == '+'){
            c = getch();
        } else if(c == '-'){
            sign2 = -1;
            c = getch();
        } else if (!isdigit(c)){
            *pd = 0.0;
            return 0;
        }
        
        for(power2 = 0; isdigit(c); c = getch())
            power2 = 10 * power2 + (c - '0');
        
        printf("power2=%d\n", power2);
        
        for(int j = 0; j < power2; j++){
            if(sign2 > 0)
                *pd = *pd * 10.0;
            else
                *pd = *pd / 10.0;
        }
    }
    
    
    printf("power=%f\n", power);
    *pd = sign * *pd / power;
    
    return c;
    
    
}

/* getop: get next operator or numeric operan */
int getop(char s[]){
    int i, c;
    
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    
    if(!isdigit(c) && c != '.'){
        if(c == '-'){
            i = 0;
            while(isdigit((s[++i]) = c = getch()))
                ;
            
            if(i > 1){  /* it is negative number */
                if(c == '.') /* collect fraction part */
                    while (isdigit(s[++i] = c = getch()))
                        ;
                s[i] = '\0';
                if(c != EOF)
                    ungetch(c);
                return NUMBER;
            } else {
                s[i] = '\0';
                if(c != EOF)
                    ungetch(c);
                
                return '-';
            }
        }
        return c;           /* not a number */
    }
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    if(c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
    
}

void testGetInt(){
    int n, array[5], getint(int *), getdouble(double *);
    double darray[5];
    printf("Enter 5 integers into array\n");
    for (n = 0; n < 5 && getint(&array[n]) != EOF; n++){
        printf("array[%d]=%d\n", n, array[n]);
    }
    
    printf("Enter 5 doubles into darray\n");
    for(n = 0; n < 5 && getdouble(&darray[n]) != EOF; n++){
        printf("darray[%d]=%f\n", n, darray[n]);
    }
    

}

void calculator(){
    printf("Please enter numbers to calculator E.g. 1 2 + 3 - 4 *\n");
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknow command %s\n", s);
                break;
        }
    }
}
