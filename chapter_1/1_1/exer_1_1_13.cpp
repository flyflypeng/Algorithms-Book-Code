#include <iostream>
#include <cstdlib>

using namespace std;

int *p;

int main(int argc, char const *argv[])
{
	int m, n;
	int i, j;


	cout << "Please input the rows and columns of matrix: " << endl;

	cin >> m >> n;

	// allocate the memory space for matrix
	p = new int[m * n];

	cout << "Ok, Please input the elements of matrix: " << endl;

	for (i = 0; i < m * n; i++)
		cin >> p[i];

	cout << "Reverse Matrix: " << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << p[i + j * n] << " ";
		}
		cout << endl;
	}

	// free the array by new
	delete [] p;


	return 0;
}