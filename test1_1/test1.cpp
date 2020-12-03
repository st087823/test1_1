#include<iostream>
#include<string>
#include<clocale>
#include <iomanip>
#include <cmath>
using namespace std;


bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

int stringToDouble(string& str)
{
	double number = 0;
	int signum = 1;
	if (str[0] == '-')
	{
		str = str.substr(1);
		signum = -1;
	}
	while (isDigit(str[0]))
	{
		number = 10 * number + str[0] - '0';
		str = str.substr(1);
	}
	if (str[0] != '.' && !empty(str))
	{
		return -2;
	}
	if (str[0] == '.')
	{
		str = str.substr(1);
		double remain = 0;
		while (isDigit(str[0]))
		{
			remain = 10 * remain + str[0] - '0';
			str = str.substr(1);
		}
		if (!empty(str))
		{
			return -2;
		}
		while (remain > 1)
		{
			remain /= 10;
		}
		number += remain;
	}
	number *= signum;
	//cout << "number *= signum;" << number;
	return number;
}


int stringToInt(string& str)
{
	int number = 0;
	int signum = 1;
	if (str[0] == '-')
	{
		str = str.substr(1);
		signum = -1;
	}

	while (isDigit(str[0]))
	{
		number = 10 * number + str[0] - '0';
		str = str.substr(1);
	}
	number *= signum;
	return number;
}

int Valid_x(int x)
{
	if (x <= 1 && x >= -1)
	{
		return 0;
	}
	cout << "������ x" << endl;
	return 1;
}
int Valid_n(int n)
{
	if (0 < n < 10)	return 0;
	cout << "������ n" << endl;
	return 1;
}

long double fact(int N)
{
	if (N < 0) return 0;
	if (N == 0) return 1;
	else return N * fact(N - 1);
}

int ch(double x, int n) {
	double result = 0;
	int i = 0;
	double result = 1;
	int i = 2;

	while (abs(x) > 0.000000001 * fact(i))
	{
		if (i % 2 == 0)
		{
			double factorial = fact(i);
			x = pow(x, i);
			result += x / factorial;
		}
		i++;
	}
	return result;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n = 0;
	double x;
	string str;


	cout << "n �������� ����������" << endl;
	getline(cin, str, '\n');
	n = stringToInt(str);

	cout << "x �����" << endl;
	getline(cin, str, '\n');
	x = stringToDouble(str);

	if (Valid_x(x) == 1 || Valid_n(n) == 1)
	{
		cout << "������ ����� ������" << endl;
		return -1;
	}

	double sum = ch(x, n);
	cout << fixed << setprecision(n) << sum << endl;
	return 0;
}
