//
//  inputOutput.c
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include "inputOutput.h"


/* Input and output functions */
int getLine(char s[], bool newline){
    int c, i;
    int size = 8 * sizeof(int);
    
    for (i = 0; i < size - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if(newline == true)
        s[i++] = '\n';
    
    s[i] = '\0';
    return i;
    
}

//When enter a tab, move to the next TAB position by patching with blanks
//and return the current position after patching
int detab(char line[], int position){
    
    int patchBlankSpaceCount = TAB - position % TAB;
    
    while(patchBlankSpaceCount > 0) {
        line[position] = ' ';
        putchar(' ');
        --patchBlankSpaceCount;
        ++position;
    }
    --position;
    return position;
    
}

int getNextLine(){
    int c, i;
    extern char line[];
    
    int blankCount = 0;
    for(i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        if(c == '\t'){
            //
            //            int patchBlankSpaceCount = TAB - i % TAB;
            //
            //            while(patchBlankSpaceCount > 0) {
            //                line[i] = ' ';
            //                putchar(' ');
            //                --patchBlankSpaceCount;
            //                ++i;
            //            }
            //            --i;
            i = detab(line, i);
            blankCount = 0;
        } else if (c == ' '){
            if(blankCount < TAB){
                line[i] = c;
                putchar(' ');
                ++blankCount;
            } else {
                //replace TAB # of blank space with TAB in line
                i = i - TAB;
                line[i] = '\t';
                line[i + 1] = '\0';
                putchar(' ');
                blankCount = 0;
                
            }
            
            
        } else {
            line[i] = c;
            putchar(c);
            blankCount = 0;
        }
        
    }
    
    if (c == '\n'){
        while(line[i-1] == ' ' || line[i-1] == '\t')
            --i;
        line[i] = c;
        ++i;
    }
    
    
    line[i] = '\0';
    return i;
    
}