#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE* fp;
	int a[] = {0,1,2};
	char b[] = "ABC";
	float c[] = {1.1,1.2,1.3};
	int ra[sizeof(a)];
	char rb[sizeof(b)];
	float rc[sizeof(c)];
	
	fp = fopen("a.bin","wb+");
	fwrite(a,sizeof(int),3,fp);
	fwrite(b,sizeof(char),3,fp);
	fwrite(c,sizeof(float),3,fp);
	
	fseek(fp, 0 ,SEEK_SET);
	fread(ra, sizeof(int),3,fp);
	fseek(fp, 0 ,SEEK_CUR);
	fread(rb, sizeof(char),3,fp);
	fseek(fp, 0 ,SEEK_CUR);
	fread(rc, sizeof(float),3,fp);
	
	fclose(fp);
	
	for(int i=0;i<3;i++) printf("%d ", ra[i]);
	printf("\n");
	for(int i=0;i<3;i++) printf("%c ", rb[i]);
	printf("\n");
	for(int i=0;i<3;i++) printf("%f ", rc[i]);
	
	return 0;
} 
