/*****************************************************************************
对于一个自然数N，用大于1小于N的各个自然数都去除一下N，如果都除不尽，则N为素数，否则N为合数。
改进:
第一，对于一个自然数N，只要能被一个非1非自身的数整除，它就肯定不是素数，所以不必再用其他的数去除。
第二，对于N来说，只需用小于N的素数去除就可以了。例如，如果N能被15整除，实际?上就能被3和5整除，
	如果N不能被3和5整除，那么N也决不会被15整除。
第三，对于N来说，不必用从2到N一1的所有素数去除，只需用小于等于√N(根号N)的所有素数去除就可以了。
这一点可以用反证法来证明：
如果N是合数，则一定存在大于1小于N的整数d1和d2，使得N=d1×d2。?如果d1和d2均大于√N，
则有：N＝d1×d2>√N×√N＝N。?而这是不可能的，所以，d1和d2中必有一个小于或等于√N。
基于上述分析，设计算法如下：?
(1)用2，3，5，7逐个试除N的方法求出100以内的所有素数。
(2)用100以内的所有素数逐个试除的方法求出10000以内的素数。
首先，将2，3，5，7分别存放在a[1]、a[2]、a[3]、a[4]中，以后每求出一个素数，
只要不大于100，就依次存放在A数组中的一个单元?中。当我们求100—10000之间的素数时，
可依次用a[1]－a[2]的素数去试除N，这个范围内的素数可以不保存，直接打印。
*******************************************************************************/

/*********************************************************************************
**文件名：main.c
**功能：找出素数测试函数 
**作者：朱飞东 
**QQ ：1003768663
**日期：2014.10.8
*********************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	int *s = NULL;
	
	PriNum10000();
	
	return 0;
}
