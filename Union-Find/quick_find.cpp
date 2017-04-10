/*
* @Author: woshijpf
* @Date:   2017-01-08 10:24:46
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-08 16:24:27
*/

#include "quick_find.h"
#include <iostream>

Quick_Find::Quick_Find(int N): UF(N)
{

}

int Quick_Find::UF_find(int p)
{
	return id[p];
}

void Quick_Find::UF_union(int p, int q)
{
	int pID = id[p];
	int qID = id[q];

	// these two nodes are already connected
	if (pID == qID)
		return;

	for (int i = 0; i < size; i++)
	{
		if (id[i] == pID)
			id[i] = qID;
	}
	count--;
}

int main() {

	int N;
	std::cin >> N;	//read the number of node
	Quick_Find* quick_find = new Quick_Find(N); //create Quick_Find Object

	int p, q;
	while (std::cin >> p >> q)
	{
		if (quick_find->connected(p, q)) //if two node already connected, then continue
			continue;

		quick_find->UF_union(p, q);
		std::cout << p << " " << q << std::endl;
	}

	std::cout << quick_find->getCount() << " components" << std::endl;

	delete quick_find;
	return 0;
}