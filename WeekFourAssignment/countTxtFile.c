#include <stdio.h>

int main (){
	FILE *txtFile;
	int x;
	size_t nread;
	txtFile = fopen("fileForTexCounter.txt","r");
	if(txtFile!=NULL){
		fseek(txtFile,0,SEEK_END);
		x = ftell(txtFile);
		printf("The file has %d charicters",x);
		fclose(txtFile);
	}else{
		printf("The file did not open");
	}
	
	return 0;
}