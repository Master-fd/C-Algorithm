/*********************************************************************
**文件名：QuickSort.c 
**功能：快速排序各功能函数实现 
**作者：朱飞东
**QQ: 1003768663
**日期：2014.10.7
**********************************************************************/ 


#include "QuickSort.h"


void Swap(int array[], int i, int j)
{
    int temp = array[i];
    
    array[i] = array[j];
    
    array[j] = temp;
}
/**********************************************************************
**函数名：QuickSort
**原理：每次选择第一个，然后按照比他小和比他大划分到两边，再次对着两边再次划分，
		不断重复，到最后即可完成排序
		最高效率O(n*logn) 
**********************************************************************/ 
int partition(int *s, int low, int high)
{
	int pv = s[low];
	
	while(low<high)
	{
		while((low<high) && (s[high]>=pv))		//直到右边的小于中间值，跳出交换 
		{
			high--;
		}	
		Swap(s, low, high);
		
		while((low<high) && (s[low]<=pv))	//直到左边小于中间值，跳出交换 
		{
			low++;	
		}

		 Swap(s, low, high);
	}
	
	return low;  //此时low=high,也就是中间值的位置 
}
void QSort(int *s, int low, int high)
{
	if(low<high)
	{	
		int pv = partition(s, low, high);
		
		QSort(s, low, pv-1);
		QSort(s, pv+1, high);
	}
}

void QuickSort(int *s, int len)
{
	QSort(s, 0, len-1);
}






