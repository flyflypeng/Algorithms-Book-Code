/*
* @Author: woshijpf
* @Date:   2017-01-09 16:52:54
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-09 20:31:34
*/

/*
* @Author: woshijpf
* @Date:   2017-01-09 16:22:55
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-09 16:47:10
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "timeClock.h"

int threeSumFast(std::vector<int>& v)
{
	//首先对向量 v 中数据进行一个排序
	std::sort(v.begin(), v.end());

	int N = v.size();
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			//这里在二叉搜索时，为了避免重复，所以这里就从 v[j] 之后的元素开始搜索
			if (std::binary_search(v.begin() + j + 1, v.end(), -(v[i] + v[j])))
				cnt++;
		}

	return cnt;
}

void readInts(std::vector<int>& v, std::string fileName)
{
	std::ifstream in(fileName);
	int data;
	while (in >> data)
	{
		v.push_back(data);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	readInts(v, argv[1]);

	//create a time to count algorithm run time
	TimeClock timeClock;
	long elapsedTime = 0;

	timeClock.startTimeClock();
	int count = threeSumFast(v);
	elapsedTime = timeClock.stopTimeClock();

	printf("N = %-6lu, elapsedTime = %-6ld, count = %-6d\n", v.size(), elapsedTime, count);
	return 0;
}