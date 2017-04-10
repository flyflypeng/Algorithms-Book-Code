#include "UF.h"

class Quick_Union: public UF {

public:
	Quick_Union(int N);
	virtual int  UF_find(int p);
	virtual void UF_union(int p, int q);
};