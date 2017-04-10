#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Evaluate {

public:
	Evaluate(string str): expr(str) {}

	double calculate()
	{
		stack<double> vals;
		stack<string> ops;

		double v1, v2;
		double temp;
		string s, op;

		istringstream is(expr);

		// every op or val is separated by whitespace, so we can use istringstream to read
		while (is >> s)
		{
			if (s == "(")
				;
			else if (s == "+")
				ops.push(s);
			else if (s == "-")
				ops.push(s);
			else if (s == "*")
				ops.push(s);
			else if (s == "/")
				ops.push(s);
			else if (s == "sqrt")
				ops.push(s);
			else if (s == ")")
			{
				v1 = vals.top();
				vals.pop();

				op = ops.top();
				ops.pop();

				if (op == "+")
				{
					v2 = vals.top();
					vals.pop();
					temp = v2 + v1;
					vals.push(temp);
				}
				else if (op == "-")
				{
					v2 = vals.top();
					vals.pop();
					temp = v2 - v1;
					vals.push(temp);
				}
				else if (op == "*")
				{
					v2 = vals.top();
					vals.pop();
					temp = v2 * v1;
					vals.push(temp);
				}
				else if (op == "/")
				{
					v2 = vals.top();
					vals.pop();
					temp = v2 / v1;
					vals.push(temp);
				}
				else if (op == "sqrt")
				{
					temp = sqrt(v1);
					vals.push(temp);
				}
			}
			else {
				vals.push(stod(s));
			}
		}

		// if (!vals.empty())
		// {
		// 	cout << "test: vals.top() == " << vals.top() << endl;
		// }
		// if (!ops.empty())
		// {
		// 	cout << "test: ops.top() == " << ops.top() << endl;
		// }

		while (!ops.empty())
		{
			v1 = vals.top();
			vals.pop();

			op = ops.top();
			ops.pop();

			if (op == "+")
			{
				v2 = vals.top();
				vals.pop();
				temp = v2 + v1;
				vals.push(temp);
			}
			else if (op == "-")
			{
				v2 = vals.top();
				vals.pop();
				temp = v2 - v1;
				vals.push(temp);
			}
			else if (op == "*")
			{
				v2 = vals.top();
				vals.pop();
				temp = v2 * v1;
				vals.push(temp);
			}
			else if (op == "/")
			{
				v2 = vals.top();
				vals.pop();
				temp = v2 / v1;
				vals.push(temp);
			}
			else if (op == "sqrt")
			{
				temp = sqrt(v1);
				vals.push(temp);
			}
		}

		double result = vals.top();
		vals.pop();

		return result;
	}

private:
	string expr;

};

int main(int argc, char const *argv[])
{
	string input_expr;
	Evaluate* eva;
	cout << "Please input expression and symbols should be separated by whitespace: " << endl;
	while (getline(cin, input_expr))
	{
		eva = new Evaluate(input_expr);
		double result = eva->calculate();
		cout << "The result of this expression is: " << result << endl;
		delete eva;
		cout << "Please input expression and symbols should be separated by whitespace: " << endl;
	}

	return 0;
}