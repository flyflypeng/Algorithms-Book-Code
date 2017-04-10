#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Log {

public:
	static double ln(int N)
	{
		if (N == 1)
			return 0;
		return ln(N - 1) + log(N);
	}

};

int main(int argc, char const *argv[])
{

	while (1)
	{
		cout << "Please input the number for factorial: " << endl;

		int n;
		cin >> n;

		if (n <= 0)
		{
			cout << "You shoule input a positive value!" << endl;
			continue;
		}

		double result = Log::ln(n);

		cout << "ln(" << n << ") = " << result << endl;
	}

	return 0;
}