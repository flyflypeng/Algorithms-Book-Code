/*
* @Author: woshijpf
* @Date:   2017-01-08 16:05:54
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-08 18:49:37
*/

#include "weighted_quick_union.h"
#include <iostream>

Weighted_Quick_Union::Weighted_Quick_Union(int N): UF(N)
{
	//create an array for contain the tree size of node
	sz = new int[N];
	for (int i = 0; i < N; i++)
		sz[i] = 1;
}

Weighted_Quick_Union::~Weighted_Quick_Union()
{
	delete [] sz;
}

int Weighted_Quick_Union::UF_find(int p)
{
	while (p != id[p])
		p = id[p];
	return p;
}

void Weighted_Quick_Union::UF_union(int p, int q)
{
	int pRoot = UF_find(p);
	int qRoot = UF_find(q);

	if (pRoot == qRoot)
		return;

	if (sz[pRoot] < sz[qRoot])
	{
		id[pRoot] = qRoot;
		sz[qRoot] += sz[pRoot];
	} else {
		id[qRoot] = pRoot;
		sz[pRoot] += sz[qRoot];
	}
	count--;
}

int main() {

	int N;
	std::cin >> N;	//read the number of node
	Weighted_Quick_Union* weighted_quick_union = new Weighted_Quick_Union(N); //create Quick_Find Object

	int p, q;
	while (std::cin >> p >> q)
	{
		if (weighted_quick_union->connected(p, q)) //if two node already connected, then continue
			continue;

		weighted_quick_union->UF_union(p, q);
		std::cout << p << " " << q << std::endl;
	}

	std::cout << weighted_quick_union->getCount() << " components" << std::endl;

	delete weighted_quick_union;

	return 0;
}