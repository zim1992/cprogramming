# include <stdio.h>
float arrayA[4];
float arrayB[6];
float arrayC[1];
int arrayAsize;
int arrayBsize;
float arrayMaxSize[1];
float maxArrays(float A[],float B[])
{
	int i;
	float maxValue = A[0];
	arrayAsize = sizeof(A)/sizeof(A[0]);
	for(i =0;i<arrayAsize;i++)
	{
		if(A[i]>maxValue){
			maxValue = A[i];
		}
	}
	arrayBsize = sizeof(B)/sizeof(B[0]);
	int j;
	for(j = 0;j<arrayBsize;j++)
	{
		if(B[j]>maxValue){
			maxValue = B[i];
		}
	
	}
	return maxValue;
}
int main()
{
	int menuVal;
	arrayA[] = {12,15,44,56};
	arrayB[] = {43,12,753,6572,42,38,87};
	
	printf("%s\n","In this program we are going to write a message based on the number you choose to write down.");// introduction messeage
	printf("%s\n","Bellow you can see numbers 1 to 3.\nBy sellecting one of the numbers a sentence will be outputted to the screen\n1\thello how are you doing?\n2\trun assignment in excersize B\n3\tPop goes te wezel");
	scanf("%d",&menuVal);
	if(menuVal<=0){
		printf("%s\n","I had to die because you made me negative\nSTOP your negativity");
		return 0;
	}
	switch(menuVal){
		case 1:
			printf("%s\n", "hello how are you doing?");
			break;
		case 2:
			arrayMax[0] = maxArrays(arrayA[],arrayB[]);
			break;
		case 3:
			printf("%s\n","Pop goes the wezel");
			break;
		default:
			printf("%s\n","YOU FAILED, you didn't type a number between 1 and 3\nYOU DO NOT DESERVE A SECOND CHANCE!!!!!!!\n. .\n\n ^\n~~~");
			break;
	}
	return 0;
}