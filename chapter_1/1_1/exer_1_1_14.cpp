#include <iostream>
#include <cstdlib>

using namespace std;

class Lg {

public:
	static int lg(int N)
	{
		int count = -1;
		int s = N;

		while (s)
		{
			count++;
			s = s / 2;
		}

		return count;
	}

};

int main(int argc, char const *argv[])
{

	int data;
	cout << "Please input data: " << endl;

	while (cin >> data)
	{

		if (data <= 0 )
		{
			cout << "You should input a positive integer!" << endl;
			exit(EXIT_FAILURE);
		}

		int result = Lg::lg(data);

		cout << "The result is : " << result << endl;
		cout << "Please input data: " << endl;
	}

	return 0;
}