/******************************************************************************
**文件名：fibonacci.c 
**功能：用递归实现斐波拉契数列 
**作者：朱飞东 
**QQ：1003768663
**日期：2014.9.23
*******************************************************************************/
 
#include <stdio.h>

int fibonacci(int n)
{
	if( n > 1 )
    {      
       
	   return fibonacci(n-1) + fibonacci(n-2); 
    }
    else if( n == 1 )
    {
        return 1;
    }
    else if( n == 0 )
    {
        return 0;
    }
}

int main()
{
    int i = 0;
    
    for(i=1; i<=10; i++)
    {
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));
    }
    printf("fibonaccisum = %d\n",fibonacci(5));
    return 0;
}
