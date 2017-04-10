#include "UF.h"

class Weighted_Quick_Union: public UF {

public:
	Weighted_Quick_Union(int N);
	~Weighted_Quick_Union();
	virtual int  UF_find(int p);
	virtual void UF_union(int p, int q);

private:
	int* sz; //the tree contained the node size
};