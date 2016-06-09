# include <stdio.h>
# include <stdlib.h>
void minToMaxSorter(double arrayToBeSorted[],int values)
{
	int counter1, counter2;
	double swapper;
	for(counter1=0; counter1<(values-1);counter1++)
	{
		for(counter2=0;counter2<(values-counter1-1);counter2++)
		{
			if(arrayToBeSorted[counter2]>arrayToBeSorted[counter2+1])
			{
				swapper = arrayToBeSorted[counter2];
				arrayToBeSorted[counter2]=arrayToBeSorted[counter2+1];
				arrayToBeSorted[counter2+1]=swapper;
			}
		}
	}
}
void maxMinMinMaxOrganiser(double arrayMaxMinMinMax[], int quantity, int sort)
{
	double tempArray[10];
	int counter, loopMax;
	for(counter=0;counter<quantity;counter++)
		tempArray[counter]=arrayMaxMinMinMax[counter]; // used to store the values in the order before the main array is reorganised. 
		
	if(sort==1){//max-min
		for(counter=0;counter<(quantity);counter++)			
		{
			if(counter%2==0){
				arrayMaxMinMinMax[counter] = tempArray[quantity-(counter/2)-1];

			}else{
				arrayMaxMinMinMax[counter] = tempArray[counter/2];
			}
		}

	}else{      //min-max
		for(counter=0;counter<(quantity);counter++)			
		{
			if(counter%2==0){
				arrayMaxMinMinMax[counter] = tempArray[counter/2];

			}else{
				arrayMaxMinMinMax[counter] = tempArray[quantity-(counter/2)-1];
			}
		}
	}
}
int main()
{
	double numberArray[10];
	int choose;
	int counter;
	int numberOfValues;
	printf("%s\n", "This program will be used to sort values max-min or min-max\nYou need to first decide whether you want to sort max-min or min-max\n1\tmax-min\n2\tmin-max");
	scanf("%d", &choose);
	while(choose>2){
		printf("%s\n","OPS you made a mistake. We don't understand how you want to sort your values.\nYour options are listed below\n1\tmax-min\n2\tmin-max");
		scanf("%d",&choose);
	}
	printf("%s\n", "How many numbers do you want to sort out. This program can only handle a total of 10 values");
	scanf("%d", &numberOfValues);
	while(numberOfValues>10){
		printf("%s\n","The following program can only sort a set of values which are lower than 10 values\nPlease change the quantity of numbers you are wanting to sort out");
		scanf("%d", &numberOfValues);
	}		
	printf("The amount of values you will be adding is %d below you can start typing\n",numberOfValues);
	for(counter=0;counter<numberOfValues;counter++)
		scanf("%lf",&numberArray[counter]);
	minToMaxSorter(numberArray,numberOfValues);
	maxMinMinMaxOrganiser(numberArray,numberOfValues,choose);
	printf("%s\n", "the final output");
	for(counter=0;counter<numberOfValues;counter++)
		printf("%lf\n", numberArray[counter]);
	return 0;
}