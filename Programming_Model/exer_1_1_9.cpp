#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Please input a positive integer: " << endl;
	int data;

	while (cin >> data)
	{
		if (data <= 0)
		{
			cout << "You should input positive interger!" << endl;
			continue;
		}

		string result;
		result = "";
		int s, r;
		s = data;

		while (s != 0)
		{
			r = s % 2;
			if (r == 0)
				result += "0";
			if (r == 1)
				result += "1";
			s = s / 2;
		}

		// reverse the result string
		reverse(result.begin(), result.end());

		cout << "The binary form of " << data << " is: " << result << endl;
	}

	return 0;
}