/*
* @Author: woshijpf
* @Date:   2017-01-08 15:37:10
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-08 15:46:47
*/

#include "quick_union.h"
#include <iostream>

Quick_Union::Quick_Union(int N): UF(N)
{

}

//find the root node id of the current node p
int Quick_Union::UF_find(int p)
{
	while (p != id[p])
		p = id[p];

	return p;
}

void Quick_Union::UF_union(int p, int q)
{
	int pRoot = UF_find(p);
	int qRoot = UF_find(q);

	if (pRoot == qRoot)
		return;

	//if two node's root node is not same, merge the pRoot node into qRoot node
	id[pRoot] = qRoot;
	count--;
}

int main(int argc, char const *argv[])
{
	int N;
	std::cin >> N;	//read the number of node
	Quick_Union* quick_union = new Quick_Union(N); //create Quick_Find Object

	int p, q;
	while (std::cin >> p >> q)
	{
		if (quick_union->connected(p, q)) //if two node already connected, then continue
			continue;

		quick_union->UF_union(p, q);
		std::cout << p << " " << q << std::endl;
	}

	std::cout << quick_union->getCount() << " components" << std::endl;

	delete quick_union;
	return 0;
}