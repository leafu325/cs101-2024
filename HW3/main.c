#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct lotto {
    int id;
    int number[5];
} lotto_line;


void lotto_writebin(lotto_line lot[], int n,char* dt){

    int file = 1;
    FILE* fp3;
    char filename[20] = "lotto00001.txt";
    while((fp3 = fopen(filename, "r")) != NULL){
        file++;
        sprintf(filename, "lotto%05d.txt", file);
        fclose(fp3);
    }
    file--;

    FILE* fp2 = fopen("record.bin","ab");

    int temp[5] = {45, 45, 45, 45, 45};
    
    fwrite(dt, sizeof(char), strlen(dt), fp2);
    for(int i = 0; i<5 ; i++){
        if(lot[i].number[0] == 45 && lot[i].number[1] == 45)
            fwrite(temp,sizeof(int), 5, fp2);
        else{
            fwrite(lot[i].number,sizeof(int), 5, fp2);
        }
    }
  
    fclose(fp2);
}


void lotto_writefile(lotto_line lot[], int n, int file){

    time_t curtime=time(0);
    char* dt = ctime(&curtime);
    dt[strlen(dt)-1]=0;
    
    char filename[10];
    sprintf(filename, "lotto%05d.txt", file);
    FILE* fp = fopen(filename,"w+");

    fprintf(fp,"=========lotto649=========\n");
    fprintf(fp,"=Lotto No.%05d=\n",file);
    fprintf(fp,"=%s=\n",dt);
    
    int i = 0;
    for(i = 0; i<n ; i++){
        fprintf(fp,"[%d]:",lot[i].id);
        for(int j = 0;j<5;j++){
            fprintf(fp," %02d",lot[i].number[j]);
        }
        fprintf(fp,"\n");
    }
    
    for(; i>=n && i<5 ; i++){
        fprintf(fp,"[%d]:",lot[i].id);
        for(int j = 0;j<5;j++)
            fprintf(fp," --");
        fprintf(fp,"\n");
    }
    fprintf(fp,"=========csie@CGU=========");
    fclose(fp);

    lotto_writebin(lot,n,dt);
}

void record_readfile(int a,int b,int c){
    int file = 1;

    FILE* fp2 = fopen("record.bin", "rb");

    int buffer[5];
    int arraysRead = 0;
    time_t curtime=time(0);
    char* dt = ctime(&curtime);
    dt[strlen(dt)-1]=0;

    printf("\nCongratulation:\n");

    fread(dt, sizeof(char), strlen(dt), fp2);

    while (fread(buffer, sizeof(int), 5, fp2) == 5){

        if(buffer[0]==45&&buffer[1]==45) continue;
        else{
            for (int i = 0; i < 5; i++) {
                if(buffer[i] == a || buffer[i] == b || buffer[i] == c){
                    printf("Lotto No.%05d\n",file);
                    printf("Time: %s\n",dt);
                    printf("Numbers:");
                    for(int j = 0; j < 5; j++){
                        printf("%d ",buffer[j]);
                    }
                    printf("\n");
                    break;
                }
            }
        }
        arraysRead++;

        if(arraysRead%5==0){
            fread(dt, sizeof(char), strlen(dt), fp2);
            dt[strlen(dt)] = '\0';
            file++;
        }

    }

    free(dt);
    fclose(fp2);

    
}

int create_rand_num(int numbers[]){

    for(int i = 0; i < 5; i++) {
        srand(time(NULL));
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
        dashs[i] = '-';
    }
}

void create_lot(lotto_line lot[],int n){
    for(int i = 0;i<n;i++){
        lot[i].id = i + 1;
        create_rand_num(lot[i].number);
    }
    for(int i = n; i<5; i++){
        lot[i].id = i + 1;
        create_dash(lot[i].number);
    }
}

void lot_info(lotto_line lot[] , int n){
    for(int k = 0 ; k<n ; k++) {
        printf("[%d] ", lot[k].id);
        for(int i = 0 ; i < 5 ; i++)
            printf(" %02d", lot[k].number[i]);
        printf("\n");
    }
    for(int k = n; k<5 ; k++){
        printf("[%d] ", lot[k].id);
        for(int i = 0 ; i < 5 ; i++)
            printf(" %c%c", lot[k].number[i], lot[k].number[i]);
        printf("\n");
    }
}

int main(){

    int file = 1;
    FILE* fp3;
    char filename[20] = "lotto00001.txt";
    while((fp3 = fopen(filename, "r")) != NULL){
        file++;
        sprintf(filename, "lotto%05d.txt", file);
        fclose(fp3);
    }

    int n;
    printf("Enter number of lotto lines (0 to check): ");
    scanf("%d",&n);

    if(n==0){
        int a,b,c;
        printf("Enter numbers for winning: ");
        scanf("%d %d %d",&a,&b,&c);
        printf("The numbers for winning are: %d %d %d\n",a,b,c);
        record_readfile(a,b,c);
        return 0;
    }
    else{
        printf("Creating %d lotto lines in %s\n", n, filename);

        lotto_line lot[5];
        create_lot(lot,n);
        lotto_writefile(lot,n,file);
    
        return 0;
    }
}
