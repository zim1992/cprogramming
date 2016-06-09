#include<stdio.h>
#include<stdlib.h>
typedef struct identification{
int identificationNumber;
char identificationChar[20];
}rec;
rec* addFirstElement(rec *ptr);
rec* addNewElement(rec *ptr,int *x);
void printEvenRecords(rec *ptr,int x);
void printOddRecords(rec *ptr,int x);

int main(){
	rec* ptr = malloc(sizeof(rec));
	int x = 0;
	int check = 0;
	ptr = addFirstElement(ptr);
	do{
		ptr = addNewElement(ptr,&x);
		printf("\nDo you want to add a new record to your existing record press\n1\t to add more data\n2\t exit\n3\tprint all even data\n4\tto print all odd data\n");
		scanf("%d",&check);
		if(check == 3){
			printEvenRecords(ptr, x);
			printf("\nDo you want to add a new record\n1\tYes\n2\tNo\n");
			scanf("%d",&check);
		}
		if(check == 4){
			printOddRecords(ptr, x);
			printf("\nDo you want to add a new record\n1\tYes\n2\tNO\n");
			scanf("%d",&check);
		}
	}while(check !=2);
	
	return 0;
}
rec* addFirstElement(rec *ptr){
printf("\nIn this program you will be able to add element to a record\n first add the Id number: ");
	scanf("%d",&ptr[0].identificationNumber);
	printf("\nNow add a sentence: ");
	scanf("%s",ptr[0].identificationChar);
	return ptr;

}
rec* addNewElement(rec *ptr,int *x){
	*x++;
	realloc(ptr,*x*sizeof(rec));
	printf("\nadd a new Id number: ");
	scanf("%d",&ptr[*x].identificationNumber);
	printf("\nNow add a sentence: ");
	scanf("%s",ptr[*x].identificationChar);
	return ptr;

}
void printEvenRecords(rec *ptr, int x){
	int i = 0;
	for(i = 0;i<=x;i++){
		if(ptr[i].identificationNumber%2 == 0){
		printf("\nID number:%d and the string:%s\n",ptr[i].identificationNumber,ptr[i].identificationChar);	
		}
	}
}
void printOddRecords(rec *ptr, int x){
int i = 0;
	for(i = 0;i<=x;i++){
		if(ptr[i].identificationNumber%2 != 0){
		printf("\nID number:%d and the string:%s\n",ptr[i].identificationNumber,ptr[i].identificationChar);	
		}
	}
}