//Author: Alexander Akimov
//Last upd: 24.03.22 21:43
//CamelCase into snake_case

#include<stdio.h> 
#include<string.h>
#include<unistd.h>

int check(char line[]) //создаем функцию check которая принимает строчку, а возвращает число
{ 
    int capital = 0; 
    int underline = 0; 
    int len = strlen(line); 
 
    if(len == 1 && line[0] == '\n'){return "[empty line:error]\n";} 
 
    for(int i = 0; i < len; i++){  
            if(line[i] == '_'){  
 
                if(i == 0){return "[type:error]\n";} 
 
                underline = 1; 
 
                line[i] = line[i+1] - ('a'-'A');   
 
                for(int j = i+1; j < len; j++){ 
                    line[j] = line[j+1]; 
                } 
 
            } 
 
            else if(line[i] >= 'A' && line[i] <= 'Z'){  
 
                if(i == 0){return "[type:error]\n";} 
 
                capital = 1; 
 
                char buf;
 
                buf = line[i] + 32; 
                line[i] = '_'; 
 
                for(int j = len + 1; j > i+1; j--){ 
                    line[j] = line[j-1]; 
                } 
 
                line[i+1] = buf;  
            } 
    } 
 
    if(underline !^= capital){return "[type:error]\n";} 
    return line; 
} 
 
void main() 
{ 
    char line[100]; 
 
    FILE *inp; 
    FILE *out; 
    inp = fopen("main.txt", "r"); 
    out = fopen("result.txt", "w"); 

    if( access("main.txt", F_OK ) == 0 ) {
    // file exists
        printf(":success\n");
            while (!feof(inp)){ 
            fgets(line, sizeof(line), inp); 
            fprintf(out, check(line));
            }
    } else {
        printf("unable to find main file:error\n");
        return 0;
    // file doesn't exist
    }
    fclose(inp); 
    fclose(out); 
 
} 

