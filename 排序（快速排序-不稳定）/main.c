#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int array[] = {2,8,2,19,4,3,8,56,7,45,11};
	int i = 0;
	
	QuickSort(array,sizeof(array)/sizeof(array[0]));
	
	for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
	{
		printf("%d ",array[i]);	
	}
	
	return 0;
}
