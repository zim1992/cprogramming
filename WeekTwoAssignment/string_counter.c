#include <stdio.h> 
#include <string.h>
char *stringInput(char string1[50],char string2[50]);

char firstString[50];
char secondString[50];
char newString [50];
int main(){
	printf("Write down a string:");
	scanf("%s",firstString);
	printf("\nNow write down another string:");
	scanf("%s",secondString);
	char *longerString  = stringInput(firstString,secondString);
	printf("\nThe longer string was: %s", longerString);
	return 0;
}
char *stringInput(char string1[],char string2[]){
	unsigned i;
	unsigned j;
	for(i = 0; string1[i] != '\0';i++){
	
	}
	for(j = 0; string2[j] != '\0';j++){
	
	}
	if(i>j)return string1;
	else return string2;
	
	
	
}
