#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef struct lotto {
    int id;
    int number[5];
} lotto_line;
void lotto_writefile(lotto_line lot[], int n){
    time_t curtime=time(0);
    char t[100];
    strcpy(t,ctime(&curtime));
    FILE* fp = fopen("lotto.txt","wb+");
    fprintf(fp,"========lotto649========\n");
    fprintf(fp,"%s",t);
    int i = 0;
    for(i = 0; i<n ; i++){
        fprintf(fp,"[%d]:",lot[i].id);
        for(int j = 0;j<5;j++)
            fprintf(fp," %02d",lot[i].number[j]);
        fprintf(fp,"\n");
    }
    for(i ; i>=n && i<5 ; i++){
        fprintf(fp,"[%d]:",lot[i].id);
        for(int j = 0;j<5;j++)
            fprintf(fp," %s","--");
        fprintf(fp,"\n");
    }
    fprintf(fp,"========csie@CGU========");
    fclose(fp);
}
int create_rand_num(int numbers[]){
    for(int i = 0; i < 5; i++) {
        numbers[i] = (rand()%69+1); 
        for(int j = 0; j < i; j++) {
            if(numbers[i] == numbers[j]) {
                i--; 
                break;
            }
        }
    }
}
void create_dash(int dashs[]){
    for(int i = 0; i<5 ; i++){
        dashs[i] = 45;
    }
}
void create_lot(lotto_line lot[],int n){
    int i = 0;
    for(i = 0;i<n;i++){
        lot[i].id = i + 1;
        create_rand_num(lot[i].number);
    }
    for(i; i>=n && i<5;i++){
        lot[i].id = i+1;
        create_dash(lot[i].number);
    }
}
void lot_info(lotto_line lot[] , int n){
    int k = 0;
    for(k = 0 ; k<n ; k++) {
        printf("[%d] ", lot[k].id);
        for(int i = 0 ; i < 5 ; i++)
            printf(" %02d", lot[k].number[i]);
        printf("\n");
    }
    for(k;k>=n && k<5;k++){
        printf("[%d] ", lot[k].id);
        for(int i = 0 ; i < 5 ; i++)
            printf(" %c%c", lot[k].number[i], lot[k].number[i]);
        printf("\n");
    }
}
int main(){
    int n,k;
    printf("text");
    scanf("%d",&n);
    printf("text %d text\n",n);

    lotto_line lot[5];
    create_lot(lot,n);
    lot_info(lot,n);

    lotto_writefile(lot,n);

    return 0;
}