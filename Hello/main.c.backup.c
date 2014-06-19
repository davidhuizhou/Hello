//
//  main.c
//  Hello
//
//  Created by Hui Zhou on 11/27/12.
//  Copyright (c) 2012 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define LOWER -200.0
#define UPPER 300.0
#define STEP 20

#define INBLANK 1
#define OUTBLANK 0

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXLINE 1000 /* maximum input line size */



int max;
char line[MAXLINE];
char longest[MAXLINE];
enum boolean {NO, YES};

void printFahrenheitCelsiusTable(float, float, float);
void copyInput();
void countCharacters();
void countLines();
void countBlanks();
void replaceWithSingleBlank();
void replaceBlanks();
void countWords();
void countDigits();
void characterCount();
int power (int m, int n);
int getNextline(void);
void copy(void);
void printLogestLine(void);
int getLength(char[]);
int removeTrailingBlanks(char line[]);
void reverseString(char s[]);
void replaceTabs(int);
int getLeft(char[]);
int getRight(char[], int);
void removeLeftRight(char[], int, int);
enum boolean isParenthesesBalanced(char[]);
int atoi(char[]);
int lower(int c);
int htoi(char[]);
void squeeze(char [], int );
void strcat1(char [], char []);
void squeeze1(char[], char []);
unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
unsigned invertbits(unsigned, int, int);
unsigned rightrot(unsigned, int);
unsigned getMask1(int, int);
unsigned getMask0(int, int);
void printBitsOfUnsigned(unsigned);
int bitcount(unsigned);
int bitcount1(unsigned);
void expend(char [], char []);
void itoa(int, char []);
void itoa1(long, char [], int);
int strindex(char [], char []);
int rstrindex(char [], char []);
int getNextLine2(char [], int );
void findAllMatchingLines(char []);
double atof(char []);
void sum();







int main1(int argc, const char * argv[])
{
    extern char line[];
    

    printf("Hello, World,\tthis\tis great!\n\n");
    //printFahrenheitCelsiusTable(LOWER, UPPER, STEP);
    
    //copyInput();
    //countCharacters();
    //countLines();
    //countBlanks();
    //replaceWithSingleBlank();
    //replaceBlanks();
    //countWords();
    //countDigits();
    //characterCount();
    
    //int i;
    //for(i = 0; i < 10; ++i)
    //    printf("%10.0d %10.0d %10.0d\n", i, power(2, i), power(-3, i));
    
    
    //printLogestLine();
    //replaceTabs(4);
    
    int len;
//    len = getNextLine();
//    printf("isParenthesesBalanced returns %d\n", isParenthesesBalanced(line));
//    
//    len = getNextLine();
//    printf("%d\n", atoi(line));
    
    
//    len = getNextLine();
//    
//    int i = 0;
//    while(i < len){
//        putchar(lower(line[i]));
//        ++i;
//    }
    
//    len = getNextLine();
//    
//    printf("%d\n", htoi(line));
    
//    len = getNextLine();
//    squeeze(line, 'c');
//    
//    printf("%s\n", line);
//    char s[] = "ab cd efg";
//    strcat1(s, "hijklmn");
//    
//    printf("%s\n", s);
//
//    len = getNextLine();
//    char t[] = {'a', 'b', '\0'};
//   
//    squeeze1(line, "abc");
//    printf("%s\n", line);
    
    unsigned value = 123;
    printBitsOfUnsigned(value);
    
    unsigned value1 = getbits(123, 8, 7);
    printBitsOfUnsigned(value1);
    
    unsigned value2 = 1234567;
    unsigned value3 = 123;
    unsigned value4 = setbits(value2, 11, 5, value3);
    printBitsOfUnsigned(value4);
    
    
    unsigned value5 = invertbits(value4, 11, 18);
    printBitsOfUnsigned(value5);
    
    unsigned value6 = rightrot(value5, 7);
    printBitsOfUnsigned(value6);
    
    unsigned value7 = rightrot(value5, 32);
    printBitsOfUnsigned(value7);
    
    
    int count = bitcount(value7);
    printf("The count=%d\n", count);
    
    count = bitcount1(value7);
    printf("The count=%d\n", count);
    
    char line1[MAXLINE];
    expend("-a-m", line1);
    printf("%s\n", line1);
    
    char line2[MAXLINE];
    expend("a-b-c", line2);
    printf("%s\n", line2);
    
    char line3[MAXLINE];
    itoa(123456789, line3);
    printf("%s\n", line3);
    
    char line4[MAXLINE];
    itoa1(123456789, line4, 10);
    printf("%s\n", line4);
    
    
    char line5[MAXLINE];
    itoa1(0X1235ABCD678, line5, 16);
    printf("%s\n", line5);
    
    //findAllMatchingLines("love");
    
    printf("left index = %d, right index = %d\n", strindex("I love you so much my love", "love"), rstrindex("I love you so much my love", "love"));
    
   
    printf("%s=%.6f and  %.6f\n", "12345.67", atof("12345.67"), 1234567 / 100.0);
    
    sum();
    return 0;
}

void printFahrenheitCelsiusTable(float lower, float upper, float step){
    float fahr, celsius;
    //    fahr = LOWER;
    //
    //    printf("Fahrenheit\tCelsius\n");
    //
    //    while(fahr <= upper){
    //        celsius = (5.0/9.0) * (fahr - 32);
    //        printf("%10.0f\t%7.1f\n", fahr, celsius);
    //        fahr = fahr + step;
    //    }
    
    printf("Fahrenheit\tCelsius\n");
    
    for (fahr = lower; fahr <= upper; fahr += step){
        printf("%10.0f\t%7.1f\n", fahr, (5.0/9.0) * (fahr - 32));
    }
}

void copyInput(){
    int c;
    
    c = getchar();
    
    while ( c != EOF){
        
        putchar(c);
        
        
        c = getchar();
        
    }
    
    printf("%d == EOF is %d\n", c, (c == EOF));
    printf("EOF = %d\n", EOF);
    
}

void countCharacters(){
    
    double nc = 0.0;
    
    int c;
    
    c = getchar();
    c = getchar();
    
    while ( c != EOF){
        
        ++nc;
        
        
        c = getchar();
        
    }
    
    //for (nc = 0; getchar() != EOF; ++nc)
    //    ;
    printf("countCharacters got %.0f of characters\n", nc);

    
}

void countLines(){
    int c, nl;
    
    nl = 0;
    
    while((c=getchar()) != EOF){
        if(c=='\n')
            ++nl;
    }
    
    printf("Line count is %d\n", nl);
}

void countBlanks(){
    int c, nb, nt, nl;
    
    nb = 0;
    nt = 0;
    nl = 0;
    
    while ((c = getchar()) != EOF){
        if( c == ' '){
            ++nb;
        } else if( c == '\t'){
            ++nt;
        } else if (c == '\n'){
            ++nl;
        }
    }
    
    printf("nb=%d, nt=%d, nl=%d\n", nb, nt, nl);
}

void replaceWithSingleBlank(){
    int c, state;
    state = OUTBLANK;
    
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t'){
            if (state == OUTBLANK){
                state = INBLANK;
                putchar(' ');
                
            }
        }else {
            state = OUTBLANK;
            putchar(c);
        }
        
    }
    
}

void replaceBlanks(){
    int c;
    
    while((c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }else if(c == '\b'){
            putchar('\\');
            putchar('b');
        }else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        }else
            putchar(c);
    }
}

void countWords(){
    
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    
    state = OUT;

    
    while ((c = getchar()) != EOF){
        ++nc;
        
        
        if(c == '\n')
            ++nl;
        
        if (c ==' ' || c == '\n' || c== '\t'){
            state = OUT;
        }else {
            
            if (state == OUT){
                putchar('\n');
                state = IN;
                ++nw;
            }
            putchar(c);
        }

        
    }
    
    printf("\nnl=%d nw=%d nc=%d\n", nl, nw, nc);
    
}

void countDigits(){
    int c, i, nwhite, nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    for(i = 0; i < 10; i++){
        ndigit[i] = 0;
    }
    
    while((c=getchar()) != EOF)
        if(c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    
    printf("digits = ");
    for(i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d other = %d\n", nwhite, nother);
    
    
    for (int i = 10; i >= 0; i--){
        printf("|");
        
        for(int j = 0; j < 10; j++){
            if(i == 0)
                printf("_");
            
            else if(i <= ndigit[j])
                printf("|");
            else
                printf(" ");
        }
        
        printf("\n");
    }
    
    
    
    
    
}


void characterCount(){
    int c, i, nwhite, nother;
    int nCharacters[26];
    
    nwhite = nother = 0;
    for(i = 0; i < 26; i++){
        nCharacters[i] = 0;
    }
    
    while((c=getchar()) != EOF)
        if(c >= 'a' && c <= 'z')
            ++nCharacters[c - 'a'];
        else if (c >= 'A' && c <= 'Z')
            ++nCharacters[c - 'A'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    
    printf("nCharacters = ");
    for(i = 0; i < 26; ++i)
        printf(" %d", nCharacters[i]);
    
    printf(", white space = %d other = %d\n", nwhite, nother);
    
    
    for (int i = 20; i >= 0; i--){
        printf("|");
        
        for(int j = 0; j < 26; j++){
            if(i == 0)
                printf("_");
            
            else if(i <= nCharacters[j])
                printf("|");
            else
                printf(" ");
        }
        
        printf("\n");
    }
    
    
    
    
    
}

int power(int base, int n){
    int p;
    
    
    for(p = 1; n > 0; --n)
        p = p * base;
    
    return p;
}

int getNextLine(void){
    int c, i;
    extern char line[];
    
    for (i = 0; i < MAXLINE -1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n'){
        line[i] = c;
        ++i;
        
    }
    
    line[i] = '\0';
    return i;
        
    
    
}

int getNextLine2(char s[], int lim){
    int c, i;
    
    i = 0;
    
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if(c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
    
    return i;
    
}

void copy(){
    int i;
    extern char line[], longest[];
    
    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}

void printLogestLine(void){
    int len;
    extern int max;
    extern char line[];
    extern char longest[];
    
    max = 0;
    while((len = getNextLine()) > 0){
        int newlen = removeTrailingBlanks(line);
        
        if(newlen > max){
            max = newlen;
            copy();
            
            
        }
        
        
        
        if(newlen > 0){
            printf("\n%d %s", newlen, line);
            reverseString(line);
            printf("\n%d %s\n", newlen, line);
        }
    }
    
    if(max > 0){
        printf("\nThe longest line is: %s", longest);
    }
    
    
}

int getLength(char s[]){
    int i = 0;
    
    while(s[i] != '\0')
        i++;
    
    return i;
}

int removeTrailingBlanks(char line[]){
    int len = getLength(line);
    int i;
  
    line[len - 1] = '\0';
    for(i = len - 2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i){
        if(i >= 0)
            line[i] = '\0';
        
    }
    
    
    line[i + 1] = '\n';
    return i + 1;
    
}

void reverseString(char s[]){
    int len = getLength(s);
    int i = 0, j = len - 1;
    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
    
    
    
}

void replaceTabs(int tabSpace){
    int c;
    int count = 0;
    
    //boolean inSpace = false;
    //int countOfSpace = 0;
    
    while ((c = getchar()) != EOF){
        
        
        //printf("count=%d\n", count);
        
        
        
        if(c=='\t'){
            
            int patchCount = tabSpace - (count % tabSpace);
            //printf("patchCount=%d\n", patchCount);
            
            
            for(int i = 0; i < patchCount; i++){
                putchar(' ');
                ++count;
            }
        }else if(c == '\b'){
            
            
        }else{
            putchar(c);
            ++count;
            
            
        }
        
        if(c == '\n')
            count = 0;
        
    }
    
}

//Get the last index of {
int getLeft(char s[]){
    int len = getLength(s);
    int left = len - 2;
    
    while(s[left] != '{' && left >= 0)
        --left;
    
    
    return left;
    
}

//Get the first } starting from left
int getRight(char s[], int left){
    int len = getLength(s);
    int right = left + 1;
    
    while(s[right] != '}' && right <= len - 2)
        ++right;
    
    if(s[right] != '}')
        return -1;
    
    return right;
    
}

//Remove the { at left and } at right
void removeLeftRight(char s[], int left, int right){
    int i = right;
    int j = left;
    int len = getLength(s);
    
    while (i < len){
        s[i] = s[i + 1];
        ++i;
    }
    
    len = len - 1;
    while(j < len){
        s[j] = s[j+1];
        ++j;
    }
    
}

enum boolean isParenthesesBalanced(char s[]){
    
    
    int len = getLength(s);
    printf("len is %d\n", len);
    
    if(len < 1)
        return NO;
    
    
    int left = getLeft(s);
    int right = getRight(s, left);
    printf("left is %d, right is %d\n", left, right);
    
    if(left == -1 && right == -1)
        return YES;
    else if(left == -1 && right >= 0)
        return NO;
    else if(right == -1 && left >= 0)
        return NO;
    else if(left >= right){
        return YES;
    }else{
        removeLeftRight(s, left, right);
        printf("%s\n", s);
        
        
        return isParenthesesBalanced(s);
        
    }
}

int atoi(char s[]){
    
    int i, n;
    
    n = 0;
    
    for(i = 0; s[i] >='0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    
    return n;
}

int lower(int c){
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int htoi(char s[]){
    int i, n, m;
    
    n = 0;
    m = 0;
    
    for(i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <='f') || (s[i] >= 'A' && s[i] <= 'F'); ++i){
        if(s[i] >= '0' && s[i] <= '9')
            m = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            m = s[i] - 'a' + 10;
        else
            m = s[i] - 'A' + 10;
        
        printf("m=%d\n", m);
        
        n = 16 * n + m;
        
    }
    
    return n;
    
}

void squeeze(char s[], int c){
    int i, j;
    
    for(i = j = 0; s[i] != '\0'; i++) {
        if(s[i] != c)
            s[j++] = s[i];
        
    }
    
    s[j] = '\0';
}

void strcat1(char s[], char t[]){
    int i, j;
    i = j = 0;
    
    while(s[i] != '\0')
        i++;
    
    while((s[i++] = t[j++]) != '\0')
        ;
    

}

void squeeze1(char s[], char t[]){
    
    printf("s[]=%s\n", s);
    int i, j, k;
    
    for(i = j = 0; s[i] != '\0'; i++){
        
        enum boolean isEqual = NO;
        
        printf("i=%d, s[i]=%c\n", i, s[i]);
        
        for(k = 0; t[k] != '\0'; k++){
            if(s[i] == t[k]){
                isEqual = YES;
                break;
            }
            
        }
        
        printf("isEqual=%d\n", isEqual);
        if(isEqual != YES)
            s[j++] = s[i];
        
    }
    s[j] = '\0';
    
    
}

//Get the bits starting from p to right and n bits
unsigned getbits(unsigned x, int p, int n){
    
    if(n <= p)
        return (x >> (p - n)) & ~(~0 << n);
    else
        return (x & ~(~0 << n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    
    printf("x=\n");
    printBitsOfUnsigned(x);
    
    printf("y=\n");
    printBitsOfUnsigned(y);
    
    unsigned MASK1 = getMask0(p, n);
    printf("MASK1=\n");
    printBitsOfUnsigned(MASK1);
    
    unsigned MASK2 = (y & getMask1(n, n)) << (p - n);
    printf("MASK2=\n");
    printBitsOfUnsigned(MASK2);
    
    return (x & MASK1) | MASK2;
    

    
}
//invert bits start from p for n bits
unsigned invertbits(unsigned x, int p, int n){
    
    unsigned revertedX = ~x;
    unsigned MASK1 = getMask1(p, n);
    revertedX = revertedX & MASK1;
    
    
    unsigned MASK2 = getMask0(p, n);
    return (x & MASK2) | revertedX;
    
    
    
    
    
}

unsigned rightrot(unsigned x, int n){

    const int SIZE = 8 * sizeof(unsigned);
    
    int newn = n % SIZE;
    
    if(newn > 0)
    {
    
        unsigned MASK1 = getMask1(n % SIZE, n % SIZE);
        unsigned MASK2 = (x & MASK1) << (SIZE - n % SIZE);
        printf("MASK2=\n");
        printBitsOfUnsigned(MASK2);
        
        
        unsigned value2 = x >> (n % SIZE);
        
        return value2 | MASK2;
    } else {
        return x;
    }
}

//Get the MASK 1 start from p with n digits
unsigned getMask1(int p, int n){
    if(n <= p)
        return (~(~0 << n)) << (p - n);
    else
        return (~(~0 << n));
    
}

unsigned getMask0(int p, int n){
    return ~(getMask1(p, n));
}

void printBitsOfUnsigned(unsigned value){
    const int SHIFT = 8 * sizeof(unsigned) - 1;
    
    //printf("SHIFT = %d\n", SHIFT);
    const unsigned MASK = 1 << SHIFT;
    
    unsigned value1 = value;
    value1 <<= 25;
    //printf("value & MASK = %d\n", value1 & MASK);
    
    if(0)
        printf("It is true\n");
    
    for (int i = 1; i <= SHIFT + 1; i++){
        
        
        if(value & MASK)
            putchar('1');
        else
            putchar('0');
        
        value <<= 1;
        
        if(i % 8 == 0)
            putchar(' ');
    }
    
    putchar('\n');
    
    
}


int bitcount(unsigned x){
    int b;
    
    for(b = 0; x != 0; x >>= 1){
        if (x & 01)
            b++;
    }
    
    return b;
    
        
    
}

int bitcount1(unsigned x){
    int b = 1;
    
    if(x == 0)
        return 0;
    
    while((x &= (x - 1)) != 0)
        b++;
    
    return b;
        
}



void expend(char s[], char t[]){
    int i, j;
    i = j = 0;
    
    while (!(isdigit(s[i]) || isalpha(s[i])))
        t[j++]=s[i++];
    
    while(s[i] != '\0'){
        t[j] = s[i];
        
        
        if((isdigit(s[i]) && s[i+1] == '-' && s[i + 2] != '\0'  && isdigit(s[i+2]) && s[i + 2] > s[i])
           || (isalpha(s[i]) && s[i+1] == '-' && s[i + 2] != '\0'  && isalpha(s[i+2]) && s[i + 2] > s[i])) {
            
            
            int index1 = 0;
            while(index1 < s[i+2] - s[i]){
                j++;
                t[j] = t[j - 1] + 1;
                index1++;
                
            }
            t[j] = s[i+2];
            i += 2;
            
        }
        i++;
        j++;
        
        
        
    }
    
    
}

void itoa(int n, char s[]){
    int i, sign;
    
    if((sign = n) < 0)
        n = -n;
    
    do{
        s[i++] = n % 10 + '0';
    }while ((n /= 10) > 0);
    
    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverseString(s);
}


void itoa1(long n, char s[], int b){
    int i = 0;
    long sign;
    
    if((sign = n) < 0)
        n = -n;
    
    do{
      
         printf("%lu---%lu\n", n % b, n /b);
        
        if(n % b < 10)
            s[i++] = n % b + '0';
        else if( n % b >= 10)
            s[i++] = 'A' + (n % b - 10);
        
       
            
    }while ((n /= b) > 0);
    
    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverseString(s);
}


int strindex(char s[], char t[]){
    int i, j, k;
    
    for(i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
    
}

int rstrindex(char s[], char t[]){
    int i, j, k;
    int len1 = getLength(s);
    int len2 = getLength(t);
    
    if(len1 >= len2){
        for(i = len1 - len2; s[i] != '\0'; i--){
            for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
                ;
            
            if(k > 0 && t[k] == '\0')
                return i;
        }
    }
    
    return -1;
    
}

void findAllMatchingLines(char pattern[]){
    
    int found = 0;
    char line[MAXLINE];
 
    while(getNextLine2(line, MAXLINE) > 0){
        if(strindex(line, pattern) >= 0){
            printf("%s\n", line);
            found++;
        }
    }
    printf("Total %d of lines match the pattern %s\n", found, pattern);
}

double atof(char s[]){
    double val, power, depower = 1.0;
    int i, sign, epower, esign;
    
    for(i = 0; isspace(s[i]); i++) //skip white space
        ;
    
    sign = (s[i] == '-')? -1 : 1;
    
    if(s[i] == '+' || s[i] =='-')
        i++;
    
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    
    if(s[i] == '.')
        i++;
    
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    if(s[i] == 'e' || s[i]  == 'E')
        i++;
    
    esign = (s[i] == '-')? -1 : 1;
    
    
    if(s[i] == '+' || s[i] =='-')
        i++;
    
    for(epower = 0; isdigit(s[i]); i++)
        epower = 10 * epower + (s[i] - '0');

    
    while(epower > 0){
        depower *= 10.0;
        epower--;
        
    }
    
    if(esign > 0)
        return sign * val * depower / power;
    else
        return sign * val / (depower * power);
    
}

void sum(){
    double sum;
    char line[MAXLINE];
    
    sum = 0;
    while(getNextLine2(line, MAXLINE) > 0){
        printf("\t%.6f\n", sum += atof(line));
    }
    
    
}


#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */


int gettop(char []);
void push(double);
double pop(void);

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0; /* nex free stack position */
double val[MAXVAL]; /* value stack */


/* push: push f onto value stack */
void push(double f){
    
    
}






































