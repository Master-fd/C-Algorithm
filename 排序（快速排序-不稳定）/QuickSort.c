/*********************************************************************
**�ļ�����QuickSort.c 
**���ܣ�������������ܺ���ʵ�� 
**���ߣ���ɶ�
**QQ: 1003768663
**���ڣ�2014.10.7
**********************************************************************/ 


#include "QuickSort.h"


void Swap(int array[], int i, int j)
{
    int temp = array[i];
    
    array[i] = array[j];
    
    array[j] = temp;
}
/**********************************************************************
**��������QuickSort
**ԭ��ÿ��ѡ���һ����Ȼ���ձ���С�ͱ����󻮷ֵ����ߣ��ٴζ��������ٴλ��֣�
		�����ظ�������󼴿��������
		���Ч��O(n*logn) 
**********************************************************************/ 
int partition(int *s, int low, int high)
{
	int pv = s[low];
	
	while(low<high)
	{
		while((low<high) && (s[high]>=pv))		//ֱ���ұߵ�С���м�ֵ���������� 
		{
			high--;
		}	
		Swap(s, low, high);
		
		while((low<high) && (s[low]<=pv))	//ֱ�����С���м�ֵ���������� 
		{
			low++;	
		}

		 Swap(s, low, high);
	}
	
	return low;  //��ʱlow=high,Ҳ�����м�ֵ��λ�� 
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






