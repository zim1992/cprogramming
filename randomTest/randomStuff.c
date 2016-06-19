#include <stdio.h>
#include <stdlib.h>
void incrimentinal(int *john)
{
	*john = *john +1;
}
int main()
{
	int val = 12;
	printf("The address of val1: %p\n",(void*) &val);
	incrimentinal(&val);
	printf("the val: %d\n", val );
	return 0;
	/*This code is just for testing purposes */
	// for(int count=0;count<studentRec;count++){
	// 	printf("%d\t", stud[count].id);
	// 	incrimenter = 0;
	// 	while(stud[count].name[incrimenter]!='\0')
	// 		printf("%c",stud[count].name[incrimenter++]);
	// 	incrimenter = 0;
	// 	printf("%s", "\t");					
	// 	printf("%d\n", stud[count].age);

	// }
}