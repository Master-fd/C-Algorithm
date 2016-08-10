#include <stdio.h>
#include <stdlib.h>
#include "DLQueue.h"



int main(int argc, char *argv[]) 
{
    TDLQueue* queue = DLQueue_Create();
    int a[10] = {0};
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        DLQueue_Append(queue, a + i);
    }
    
    printf("Header: %d\n", *(int*)DLQueue_Header(queue));
    printf("Length: %d\n", DLQueue_Length(queue));
    

    while( DLQueue_Length(queue) > 0 )
    {
        printf("Retrieve: %d\n", *(int*)DLQueue_Retrieve(queue));
    }
    
    DLQueue_Destroy(queue);
    
	return 0;
}



