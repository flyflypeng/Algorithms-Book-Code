#include "UF.h"

class Quick_Find: public UF {

public:
	Quick_Find(int N);
	virtual int  UF_find(int p);
	virtual void UF_union(int p, int q);
};