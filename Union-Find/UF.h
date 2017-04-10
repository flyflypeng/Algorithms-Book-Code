class UF {

public:
	UF(int N);
	~UF();
	int getCount();
	bool connected(int p, int q);
	virtual int  UF_find(int p) = 0;
	virtual void UF_union(int p, int q) = 0;

protected:
	int* id; //an array stores the connected component,
	int size; //the size of array is initialized by construct function
	int count; // the number of connected components
};