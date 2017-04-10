/*
* @Author: woshijpf
* @Date:   2017-01-09 16:22:55
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-09 20:18:32
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "timeClock.h"

int threeSumCount(std::vector<int>& v)
{
	int N = v.size();
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++)
			{
				if (v[i] + v[j] + v[k] == 0)
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
	int count = threeSumCount(v);
	elapsedTime = timeClock.stopTimeClock();

	printf("N = %-6lu, elapsedTime = %-6ld, count = %-6d\n", v.size(), elapsedTime, count);
	return 0;
}