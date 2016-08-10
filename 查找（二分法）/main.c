#include <stdio.h>
#include <stdlib.h>
#include "OrderSearch.h"


int main(int argc, char *argv[]) 
{
	int array[10]={1,2,3,4,6,7,8,9,10,11};
	int key = 6;
	int aa = 0;
	
	aa = OrderSearch(array, 0, 9, key);
	aa = InterpolationSearch(array, 0, 9, key);
	printf("key = %d, num = %d", array[aa], aa);
	
	
	return 0;
}
