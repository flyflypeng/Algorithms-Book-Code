#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{

	if (argc != 4)
	{
		cout << "You should input 3 arguments from standard input!" << endl;
		exit(EXIT_FAILURE);
	}

	int v1 = atoi(argv[1]);
	int v2 = atoi(argv[2]);
	int v3 = atoi(argv[3]);

	if ((v1 == v2) && (v2 == v3))
	{
		cout << "equal" << endl;
	} else {
		cout << "not equal" << endl;
	}

	return 0;
}