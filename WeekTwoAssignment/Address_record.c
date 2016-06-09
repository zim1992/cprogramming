#include<stdio.h>

typedef struct houseAdressesStruct{
char address1[20],address2[20], city[20], state[20], zip[20];
}RECORD;
int main(){
unsigned i;
RECORD location[10];
printf("You will have to place 10 addresses into the following program");
for(i=0;i<10;i++){
	printf("\nInput address number:%d Address 1:", i+1);
	scanf("%s", location[i].address1);
	printf("\nInput address number:%d Address 2:", i+1);
	scanf("%s", location[i].address2);
	printf("\nInput address number:%d City:", i+1);
	scanf("%s", location[i].city);
	printf("\nInput address number:%d State:", i+1);
	scanf("%s", location[i].state);
	printf("\nInput address number:%d Zip address:", i+1);
	scanf("%s", location[i].zip);
	
	}
	return 0;
}