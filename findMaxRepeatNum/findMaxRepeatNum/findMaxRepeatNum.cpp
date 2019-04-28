// findMaxRepeatNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//在一个规模为N的数组a[N]中，所谓主元素就是出现次数大于N / 2的元素，

#include "pch.h"
#include <iostream>
using namespace std;

/*解法1：一是用递归，遍历数组，
	第1步，如果元素的个数是1，算法退出，
	第2步，元素两两比较，如果两个数相同，则删去一个，如果两个数不同，则都删去，
	第3步，重复执行第1步。
	复杂度segma=n+n/2+n/4+...=O(2n)，代码如下：
*/
int findMaxRepeatNum1(int *a, int len)
{
/*待补充*/
	return 0;
}


/* 
解法2：充分利用已知条件出现次数大于N/2。
	首先假设主元素是X，则遍历数组时出现与X相等的元素时，X出现的数目+1，
	不相等时，如果计数值变为1，则这个X可能不是主元素，需要将假定值更改为新出现的元素，
	计数值不为1时，则X出现的数目-1.遍历完后的X就是主元素。
	复杂度为O(n)，其代码如下：
*/
int findMaxRepeatNum2(int *a, int len)
{
	int count = 1;
	int result = 0;

	if (a==NULL || len<0)
	{
		return -1;
	}

	//求出该数组的主元素
	result = a[0];
	
	for (int i=1;i<len;i++)
	{
		if (a[i]==result)
		{
			count++;

		}
		else if(count==1)
		{
			result = a[i];
			count = 1;
		}
		else
		{
			count--;
		}
	}

	//判断对应出现个数是否大于n/2
	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i]==result)
		{
			count++;
		}
	}

	if (count<(len/2))
	{
		return -1;  //表示不存在大于n/2的主元素
	}
	else
		return result;
}


int main()
{
	int a[] = { 2,4,3,3,4,2,4,3,4,};

	int len = sizeof(a) / sizeof(a[0]);

	int num2 = 0;

	num2 = findMaxRepeatNum2(a, len);
	cout << "The Array has the Max repeat num is " << endl;
	cout<< num2 << endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
