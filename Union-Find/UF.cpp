/*
* @Author: woshijpf
* @Date:   2017-01-05 20:56:08
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-08 11:01:09
*/

#include <iostream>
#include "UF.h"

UF::UF(int N)
{
	//create and initialize the id array
	size = N;
	count = N;
	id = new int[N];
	for (int i = 0; i < N; i++)
		id[i] = i;
}

UF::~UF()
{
	//destroy the id array that we allocated by new operator
	delete [] id;
}

int UF::getCount()
{
	return count;
}

bool UF::connected(int p, int q)
{
	return UF_find(p) == UF_find(q);
}