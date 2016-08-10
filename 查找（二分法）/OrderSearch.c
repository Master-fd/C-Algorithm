/**************************************************************************
**文件名：OrderSearch.c
**功能：顺序表，二分法查找相关功能函数实现 
**作者：朱飞东 
**QQ： 1003768663
**日期：2014.10.7
**************************************************************************/ 

/**************************************************************************
**函数名：OrderSearch
**功能：对有序表进行二分法查找key ,每次取中间值，对称二分 
***************************************************************************/ 
int OrderSearch(int *s, int low, int high, int key)
{
	int ret = 0;
	int mid = 0;
	
	if(low<high)
	{
		mid = (low + high)/2;	//二分 
		
		if(key == s[mid])	
		{
			ret = mid;	
		}
		else
		{
			if(s[low] < s[mid])
			{
				OrderSearch(s, low, mid-1, key);
			}
			else
			{
				OrderSearch(s, mid+1, high, key);
			}
		}
	}
	
	return ret;
}

/**************************************************************************
**函数名：InterpolationSearch
**功能：对有序表进行特殊二分法查找key，每次不对称进行二分查找
		这个方法可能可以减少查找的次数，但是不一定效率高，因为有浮点运算  
***************************************************************************/ 
int InterpolationSearch(int *s, int low, int high, int key)
{
	int ret = 0;
	int mid = 0;
	
	if(low<high)
	{
		float fx = 1.0f * (key - s[low]) / (s[high] + s[low]);	//不对称二分 
		mid = (int)(low + fx * (s[high] - s[low]));
		
		if(key == s[mid])	
		{
			ret = mid;	
		}
		else
		{
			if(s[low] < s[mid])
			{
				OrderSearch(s, low, mid-1, key);
			}
			else
			{
				OrderSearch(s, mid+1, high, key);
			}
		}
	}
	
	return ret;
}



