template<typename T> class SortSet {
public:
	static void swap(T& a, T& b);
	static void printArrayContent(T a[], int size);
	static void merge(T a[], T aux[], int lo, int mid, int hi);
	static int partition(T a[], int lo, int hi);

	static void selectionSort(T a[], int size);
	static void selectionSort(T a[], int lo, int hi);
	static void bubbleSort(T a[], int size);
	static void insertionSort(T a[], int size);
	static void shellSort(T a[], int size);
	static void mergeSort(T a[], int size);
	static void mergeSort(T a[], T aux[], int lo, int hi);
	static void mergeSort_Bu(T a[], int size);
	static void quickSort(T a[], int size);
	static void quickSort(T a[], int lo, int hi);
	static void quickSortWithSelection(T a[], int size);
	static void quickSortWithSelection(T a[], int lo, int hi, int M);
};