//
//  utils.h
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#define     MAXLINE     1000
#define     TAB         4

typedef int bool;
#define true 1
#define false 0

int         max;
char        line[MAXLINE];
char        longest[MAXLINE];


/* Input and output functions */
int getLine(char s[], bool newline);
int detab(char line[], int position);
int getNextLine();
