#include<stdio.h> 
#include<string.h>

int check(char line[]) 
{ 
    int bolshbukv = 0; 
    int podcherk = 0; 
    int len = strlen(line); 
 
    if(len == 1 && line[0] == '\n'){return "[empty line:error]\n";} 
 
    for(int i = 0; i < len; i++){  
            if(line[i] == '_'){  
 
                if(i == 0){return "[type:error]\n";} 
 
                podcherk = 1; 
 
                line[i] = line[i+1] - ('a'-'A');   
 
                for(int j = i+1; j < len; j++){ 
                    line[j] = line[j+1]; 
                } 
 
            } 
 
            else if(line[i] >= 'A' && line[i] <= 'Z'){  
 
                if(i == 0){return "[type:error]\n";} 
 
                bolshbukv = 1; 
 
                char buf;
 
                buf = line[i] + 32; 
                line[i] = '_'; 
 
                for(int j = len + 1; j > i+1; j--){ 
                    line[j] = line[j-1]; 
                } 
 
                line[i+1] = buf;  
            } 
    } 
 
    if((podcherk && bolshbukv) || (! podcherk && ! bolshbukv)){return "[type:error]\n";} 
    return line; 
} 
 
void main() 
{ 
    char line[100]; 
 
    FILE *inp; 
    FILE *out; 
    inp = fopen("ishodn.txt", "r"); 
    out = fopen("itog.txt", "w"); 

   /* if(!inp){ 
        puts("Файл не обнаружен. Будет создан файл с указанным именем");
        if(!(inp = fopen(ishodn.txt,"wb+")))
            exit(ERR_OPEN_FILE);
    }else
        puts("Файл существует и успешно открыт");
    
    fclose(inp);
 
    return 0;*/
 
    while (!feof(inp)){ 
        fgets(line, sizeof(line), inp); 
        fprintf(out, check(line)); 
    } 
 
    fclose(inp); 
    fclose(out); 
 
} 

