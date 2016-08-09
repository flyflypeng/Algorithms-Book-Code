#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class BinarySearch {

public:
	static int binarysearch(vector<int>& a, int key)
	{
		if (a.empty())
		{
			cout << ("Searched vector is empty!") << endl;
			exit(EXIT_FAILURE);
		}

		int lo, hi, mid;
		lo = 0;
		hi = a.size();
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (key < a[mid])
				hi = mid - 1;
			else if (key > a[mid])
				lo = mid + 1;
			else
				return mid;
		}

		return -1;
	}

};

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		cout << "You should input oredered filename!" << endl;
		exit(EXIT_FAILURE);
	}

	std::vector<int> v;

	ifstream input(argv[1]);
	int data;

	while (input >> data)
	{
		v.push_back(data);
	}

	// sort data in vector from small to big
	sort(v.begin(), v.end());

	// call BinarySearch::binarysearch() to process data
	int input_data;
	int result = -1;
	cout << "The followed data is not in Searched Array!" << endl;
	while (cin >> input_data)
	{
		result = BinarySearch::binarysearch(v, input_data);
		if (result == -1 )
		{
			cout << input_data << endl;
		}
	}

	return 0;
}