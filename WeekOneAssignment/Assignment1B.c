#include <stdio.h>
// Initialises the variables and methods
float arrayC[1];
int arrayAsize;
int arrayBsize;
float arrayMaxSize[1];
void maxArrays(float A[],float B[]);
int main()
{
	float arrayA[4] = {12,15,44,56};
	float arrayB[6] = {43,12,753,6572,42,38};
	float arrayMax[0] = maxArrays(arrayA,arrayB); // calls the method maxArrays and stores the maximum value in the the array ArrayMax 
}
// accepts arrays of different sizes and finds the largest value.
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