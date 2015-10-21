//
//  https://www.codeeval.com/open_challenges/50/
//  StringSubstitution
//
//  Created by Stephan Warren on 1/24/15.
//  Copyright (c) 2015 Stephan Warren. All rights reserved.
//
/*
 
 STRING SUBSTITUTION
 SPONSORING COMPANY:
 
 
 
 CHALLENGE DESCRIPTION:
 
 Credits: This challenge was contributed by Sam McCoy
 Given a string S, and a list of strings of positive length, F1,R1,F2,R2,...,FN,RN, proceed to find in order the occurrences (left-to-right) of Fi in S and replace them with Ri. All strings are over alphabet { 0, 1 }. Searching should consider only contiguous pieces of S that have not been subject to replacements on prior iterations. An iteration of the algorithm should not write over any previous replacement by the algorithm.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Each line in this file is one test case. Each test case will contain a string, then a semicolon and then a list of comma separated strings. E.g.
 
 10011011001;0110,1001,1001,0,10,11
 OUTPUT SAMPLE:
 
 For each line of input, print out the string after substitutions have been made.eg.
 
 11100110
 For the curious, here are the transitions for the above example: 10011011001 => 10100111001 [replacing 0110 with 1001] => 10100110 [replacing 1001 with 0] => 11100110 [replacing 10 with 11]. So the answer is 11100110
 

 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    FILE *file = fopen(argv[1], "r");
    char in[1024];
    char * slipped[26];
    while(fgets(in, 1024, file)) {
//        printf("start in = %s\n", in);
        in[strlen(in) - 1] = '\0';
        strtok(in, ";");
        char * old;
        char scnt = 0;
        while(1) {
            old = strtok(NULL, ",");
            if(old == NULL) {
                break;
            }
            slipped[scnt] = strtok(NULL, ",");
//            printf("old = >%s<, new = >%s<\n", old, slipped[scnt]);
            
            char * ptr;
            while((ptr = strstr(in, old))) {
                *(ptr++) = 'a' + scnt;
                for(unsigned short i = 1; i < strlen(old); i++) *(ptr++) = 'A' + scnt;
//                printf("in = %s\n", in);
            }
            scnt++;
        }
//        printf("%s\n", in);
        char * ptr = in;
        while(*ptr) {
            if(*ptr < 'a') {
                putchar(*ptr);
                ptr++;
            }
            else {
                char last = *ptr - ('a' - 'A');
                printf("%s", slipped[last - 'A']);
                while(*(++ptr) == last);
            }
        }
        printf("\n");
//        printf("\n");
        
        
    }
    return 0;
}
