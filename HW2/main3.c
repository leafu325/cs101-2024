#include<stdio.h>
#include<string.h>
typedef struct line {
    char text[70];
} line_t;

int main(){ 
    line_t lin[24];
    FILE* fp = fopen("main3.c","rb");
    int i = 0,j;
    do{
        j = 0;
        do{
            fread(&lin[i].text[j],sizeof(char),1,fp);
            j++;
        }while(lin[i].text[j-1] != '\n');
        lin[i].text[j] = '\0';
        i++;
    }while(strstr(lin[i-1].text,"int main()") == NULL);
    printf("%d %s", i,lin[i-1].text);
    fclose(fp);
    return 0;
}