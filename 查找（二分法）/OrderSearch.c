/**************************************************************************
**�ļ�����OrderSearch.c
**���ܣ�˳������ַ�������ع��ܺ���ʵ�� 
**���ߣ���ɶ� 
**QQ�� 1003768663
**���ڣ�2014.10.7
**************************************************************************/ 

/**************************************************************************
**��������OrderSearch
**���ܣ����������ж��ַ�����key ,ÿ��ȡ�м�ֵ���Գƶ��� 
***************************************************************************/ 
int OrderSearch(int *s, int low, int high, int key)
{
	int ret = 0;
	int mid = 0;
	
	if(low<high)
	{
		mid = (low + high)/2;	//���� 
		
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
**��������InterpolationSearch
**���ܣ�����������������ַ�����key��ÿ�β��Գƽ��ж��ֲ���
		����������ܿ��Լ��ٲ��ҵĴ��������ǲ�һ��Ч�ʸߣ���Ϊ�и�������  
***************************************************************************/ 
int InterpolationSearch(int *s, int low, int high, int key)
{
	int ret = 0;
	int mid = 0;
	
	if(low<high)
	{
		float fx = 1.0f * (key - s[low]) / (s[high] + s[low]);	//���Գƶ��� 
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



