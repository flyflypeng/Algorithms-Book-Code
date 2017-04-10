/*
* @Author: woshijpf
* @Date:   2017-01-12 19:25:17
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-03-13 22:35:58
*/

#include <iostream>
#include "sortFuncSet.h"


template <typename T>
void SortSet<T>::swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
void SortSet<T>::printArrayContent(T a[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";

	std::cout << std::endl;
}


/* 下面所有的排序算法都是按从小到大的顺序排列 */

/* 选择排序：选择排序的基本思想是首先从数组中起始位置开始遍历一遍整个数组，将所有元素中最小的元素交换放置到数组的起始位置，然后接着从
		  数组中第二个元素的位置开始又重新遍历数组中第二个元素之后剩余的数组元素，找出当前最小的数组元素并将其交换放置到数组的第二
		  个位置，以此类推直到数组中剩下最后一个元素为止。
   最坏情况下的时间复杂度：O(n^2)
*/
template <typename T>
void SortSet<T>::selectionSort(T a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//将 a[i] 和 a[i+1...size-1] 中最小的元素交换
		int min_index = i; //最小元素的索引
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}

template <typename T>
void SortSet<T>::selectionSort(T a[], int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		//将 a[i] 和 a[i+1...size-1] 中最小的元素交换
		int min_index = i; //最小元素的索引
		for (int j = i + 1; j <= hi; j++)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}

/* 冒泡排序：冒泡排序会遍历数组若干趟，每一趟都会从数组的头部开始比较相邻两个元素的大小，然后将大的数组元素交换向后移，并通过设置每趟遍历
		  发生了数组元素交换的标志用来判断排序是否完成，如果某趟数组遍历之后，没有发生数组元素交换则说明数组已经有序了。
   最坏情况下的时间复杂度：O(n^2)
*/
template <typename T>
void SortSet<T>::bubbleSort(T a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		bool sorted_flag = true;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				sorted_flag = false;
			}
		}
		//如果冒泡排序中遍历一次数组并没有发生元素交换，则说明整个数组已经有序了
		//就不用接着下一次循环遍历了
		if (sorted_flag)
			break;
	}
}

/* 插入排序：插入排序的基本思想是保证当前待插入元素的左半边数组是有序的，然后将待插入元素插入到它左边的有序的数组中，使得插入新的待插入元素
		   之后，数组左边仍然保持有序。
		   这里我的不是很理解的地方是：将右半边乱序的元素插入到左半边有序的数组中，左半边有序数组插入位置后面的有序的数组元素是怎么移动的呢？

   最坏情况下的时间复杂度：O(n^2)
   平均情况下的时间复杂度：O(n^2/2)
*/
template <typename T>
void SortSet<T>::insertionSort(T a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
		{
			swap(a[j], a[j - 1]);
		}
	}
}

/* 希尔排序：希尔排序的基本思想是从对插入排序的性能分析后进一步改进而来的一种算法，如果一个待排序的序列部分有序（参见《算法》中P158页的定义）
		   那么插入排序的性能就会好很多，所以基于这个思想，希尔排序就是通过一个递减序列来将数组按照一定的间隔值分隔成多个一定间隔的子数组，
		   然后对子数组进行插入排序，当递减序列的间隔值递减到为1时，这次排序就是一次插入排序，整个数组最终也达到了有序状态。

	希尔排序的性能不仅和输入序列的有序性密切相关，而且还和递减序列的选择也十分相关
*/
template <typename T>
void SortSet<T>::shellSort(T a[], int size)
{
	int N = size;
	int h = 1;
	if (h < N / 3)
		h = h * 3 + 1;
	while (h >= 1)
	{
		for (int i = h; i < N; i++)
		{
			for (int j = i; j >= h && a[j] < a[j - 1]; j -= h)
			{
				swap(a[j], a[j - 1]);
			}
		}
		h = h / 3;
	}
}

/* 归并排序：归并排序的基本思想非常简单，就是将两个已经有序的子数组合并成一个更大的有序数组。在归并排序中，通常会使用递归的方式将大的数组
		   递归地分解成更小粒度的数组，然后对这些小粒度的数组进行排序，最后将这些排序好的更小粒度的数组合并成更大的数组，最终得到有序的
		   完整的数组。

	归并排序的时间复杂度为：O(nlgn)
	归并排序还需要使用到额外的存储空间，存储空间的复杂度为：O(n)

*/
template <typename T>
void SortSet<T>::merge(T a[], T aux[], int lo, int mid, int hi)
{
	//实现将 a[lo...mid]和a[mid+1...hi]两个子数组的合并
	//首先，拷贝一份原始数组中的内容到辅助数组aux中

	for (int k = lo; k <= hi; k++)
		aux[k] = a[k];

	// i 指向左半边数组的起始索引位置，j 指向右半边数组的起始索引位置
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)
			a[k] = aux[j++];
		else if (j > hi)
			a[k] = aux[i++];
		else if (aux[j] < aux[i])
			a[k] = aux[j++];
		else
			a[k] = aux[i++];
	}
}

// mergeSort() 函数是一个重载函数
//调用该版本的 mergeSort 函数来递归地进行归并排序
template <typename T>
void SortSet<T>::mergeSort(T a[], T aux[], int lo, int hi)
{
	//递归的返回终止条件
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;
	mergeSort(a, aux, lo, mid);
	mergeSort(a, aux, mid + 1, hi);
	merge(a, aux, lo, mid, hi);
}

/*
 自顶向下递归的归并排序：这种归并排序的思想是将大的数组分解成两个子数组，分别进行递归的排序，最后将两个排序好的子数组合并成一个有序的完整的
 数组
 */
//归并排序初始输入数组时调用的 mergeSort 函数
template <typename T>
void SortSet<T>::mergeSort(T a[], int size)
{
	//一次性分配好需要额外存放的辅助数组空间
	T* aux = new T[size];

	mergeSort(a, aux, 0, size - 1);

	delete[] aux;
}

/*
  自下而上的归并排序：这种归并排序的思想是从最小的子数组（也就是子数组中只有一个元素）开始，两两归并子数组，然后再将合并得到粒度更大的
  子数组继续按照这种方法进行归并，直到归并两个子数组后得到一个完成的数组
 */
template <typename T>
void SortSet<T>::mergeSort_Bu(T a[], int size)
{
	//创建 merge() 函数操作时辅助数组空间
	T* aux = new T[size];

	for (int d = 1; d < size; d += d)
		for (int i = 0; i < size - d; i += (d + d))
		{
			int lo = i;
			int mid = i + d - 1;
			int hi = i + d + d - 1;
			//这里需要处理一下最后一个子数组的长度小于前面子数组长度的问题
			if (hi > size - 1)
				hi = size - 1;
			merge(a, aux, lo, mid, hi);
		}

	delete[] aux;
}

/*
	快速排序：快速排序的基本思想就是首先选定一个数组元素a[lo]，然后通过划分的方法将这个选定的数组成员a[lo]交换到它最终在数组中位置 j，
			而且它还满足三个特性：
			- 对于某个 j，a[j]已经排定
			- a[lo]到a[j-1]中所有的元素都不大于 a[j]
			- a[j+1]到a[hi]中所有的元素都不小于 a[j]
			然后递归地对a[j]左边的子数组进行相同的快速排序操作和对a[j]右边的子数组进行相同的快速排序操作，递归的终结条件就是待排序
			的子数组中只有一个元素。

	快速排序算法的时间复杂度：O(NlgN)
 */
template <typename T>
int SortSet<T>::partition(T a[], int lo, int hi)
{
	int i = lo;
	int j = hi + 1;
	T v = a[lo]; //a[lo] 作为切分元素
	while (true)
	{
		while (a[++i] < v)
			if (i == hi)
				break;
		while (a[--j] > v)
			if (j == lo)
				break;

		if (i >= j)
			break;
		//找到 a[i]>v, a[j]<v 的情况，则两个数组元素交换
		swap(a[i], a[j]);
	}
	// j 的位置是数组从右到左遍历时，第一个小于 a[lo] 值的位置，也就是 a[lo] 值该放置的位置
	swap(a[lo], a[j]);

	return j;
}

template <typename T>
void SortSet<T>::quickSort(T a[], int lo, int hi)
{
	if (hi <= lo)
		return;
	int j = partition(a, lo, hi);
	quickSort(a, lo, j - 1);
	quickSort(a, j + 1, hi);
}

template <typename T>
void SortSet<T>::quickSort(T a[], int size)
{
	//首先随机地打乱输入的数组，提高快速排序的性能（因为快排中切分元素的选择对算法的性能影响很大）

	quickSort(a, 0, size - 1);
}

//快速排序和选择排序相结合的一种排序方法，当快速排序递归到较小的数组时，使用选择排序进行排序处理
template <typename T>
void SortSet<T>::quickSortWithSelection(T a[], int lo, int hi, int M)
{
	if (hi <= (lo + M))
	{
		selectionSort(a, lo, hi);
		return;
	}
	int j = partition(a, lo, hi);
	quickSortWithSelection(a, lo, j - 1, M);
	quickSortWithSelection(a, j + 1, hi, M);
}


template <typename T>
void SortSet<T>::quickSortWithSelection(T a[], int size)
{
	quickSortWithSelection(a, 0, size - 1, 10);
}






