#include <stdio.h>
#include <stdlib.h>
void incrimentinal(int *john)
{
	// int hel = *john;
	// printf("The address of val2: %p\n",(void*) &hel);
	*john = *john +1;
	// printf("the val of hel: %d\n",hel);
}
int main()
{
	int val = 12;
	printf("The address of val1: %p\n",(void*) &val);
	incrimentinal(&val);
	printf("the val: %d\n", val );
	return 0;
}