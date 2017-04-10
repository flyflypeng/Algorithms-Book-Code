#include <iostream>
#include <cstdlib>

using namespace std;


class GCD {

public:
	GCD(): layers(0)
	{

	}

	int gcd(int p, int q)
	{
		// we need to ensure p >= q
		if (p < q)
		{
			int temp;
			temp = p;
			p = q;
			q = temp;
		}

		cout << "layer #" << layers++ << ": p = " << p << ", q = " << q << endl;

		int r = p;
		while (r >= q)
		{
			r = r - q;
		}

		if (r == 0)
			return q;
		else
			return gcd(q, r);

	}
private:
	int layers;
};

int main(int argc, char const *argv[])
{
	while (1)
	{
		int p, q;
		cout << "Please input two integer: " << endl;
		cin >> p >> q;

		GCD g;

		int result = g.gcd(p, q);

		cout << "The greatest common divisor between " << p << " and " << q << " is: " << result << endl;
		cout << "-------------------------------------------------------------------------" << endl;

	}
	return 0;
}