/*
* @Author: woshijpf
* @Date:   2017-03-02 11:10:28
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-03-13 22:31:22
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <ctime>
#include "sortFuncSet.cpp"
#include "timeClock.h"

using namespace std;

double algTimeCount(string alg, double* a, int size)
{
	TimeClock timer;
	timer.startTimeClock();

	if (alg == "Selection")
		SortSet<double>::selectionSort(a, size);
	if (alg == "Bubble")
		SortSet<double>::bubbleSort(a, size);
	if (alg == "Insertion")
		SortSet<double>::insertionSort(a, size);
	if (alg == "Shell")
		SortSet<double>::shellSort(a, size);
	if (alg == "Merge")
		SortSet<double>::mergeSort(a, size);
	if (alg == "Quick")
		SortSet<double>::quickSort(a, size);
	if (alg == "QuickSelection")
		SortSet<double>::quickSort(a, size);

	double total_milliSeconds = timer.stopTimeClock();
	return total_milliSeconds;
}

double sortCompare(string alg1, string alg2, int N, int Repe)
{
	double alg1_total = 0.00;
	double alg2_total = 0.00;

	static default_random_engine e;
	static uniform_real_distribution<double> u(0, 1);

	//创建排序算法所需的随机数组
	double* randomInput_1 = new double[N];
	double* randomInput_2 = new double[N];
	// int* randomInput_1 = new int[N];
	// int* randomInput_2 = new int[N];

	for (int i = 0; i < Repe; i++)
	{
		for (int j = 0; j < N; j++)
		{
			randomInput_1[j] = u(e);
			// randomInput_1[j] = N - j;
			randomInput_2[j] = randomInput_1[j];
		}

		alg1_total += algTimeCount(alg1, randomInput_1, N);
		alg2_total += algTimeCount(alg2, randomInput_2, N);
	}

	cout << "alg1: " << alg1 << ", time_total = " << alg1_total << "\n";
	cout << "alg2: " << alg2 << ", time_total = " << alg2_total << "\n";


	//输出两个排序算法花费时间之比
	cout << "For " << N << " random ints array\n";
	cout << alg1 << " is " << setprecision(2) << alg2_total / alg1_total << " times faster than " << alg2 << "\n";

	//删除动态创建的随机数组
	delete[] randomInput_1;
	delete[] randomInput_2;

	return alg2_total / alg1_total;
}

//测试排序函数的效果
void test(int N)
{
	//创建随机生成的待排序数组
	int* random_int_array = new int[N];
	default_random_engine e_int(time(0)); //为随机数引擎设置随机种子
	uniform_int_distribution<unsigned> u_int(0, 100);

	for (int i = 0; i < N; i++)
		random_int_array[i] = u_int(e_int);

	//输出随机生成的数组内容
	std::cout << "The array content before sort: ";
	SortSet<int>::printArrayContent(random_int_array, N);

	// 选择排序测试
	// SortSet<int>::selectionSort(random_int_array, N);

	// 冒泡排序测试
	// SortSet<int>::bubbleSort(random_int_array, N);

	// 插入排序测试
	// SortSet<int>::insertionSort(random_int_array, N);

	// 希尔排序测试
	// SortSet<int>::shellSort(random_int_array, N);

	// 归并排序测试
	// 自顶向下的归并排序函数
	//SortSet<int>::mergeSort(random_int_array, N);
	// 自下而上的归并排序函数
	//SortSet<int>::mergeSort_Bu(random_int_array, N);

	// 快速排序测试
	// 普通的快速排序方法
	//SortSet<int>::quickSort(random_int_array, N);
	// 快速排序中当递归到小数组时使用选择排序的方法
	SortSet<int>::quickSortWithSelection(random_int_array, N);

	std::cout << "The array content after sort: ";
	SortSet<int>::printArrayContent(random_int_array, N);


	delete[] random_int_array;
}

int main(int argc, char const *argv[])
{
	string alg1(argv[1]);
	string alg2(argv[2]);

	int N = stoi(argv[3]);
	int R = stoi(argv[4]);

cout << "argv[1] = " << alg1 << ", argv[2] = " << alg2 << ", argv[3] = " << N << ", argv[4] = " << R << "\n";

	sortCompare(alg1, alg2, N, R);

	// test(50);

	return 0;
}


