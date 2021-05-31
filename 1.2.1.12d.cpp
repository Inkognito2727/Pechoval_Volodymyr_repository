#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double a(int i);
double b(int i);
double sum(int n);

int main()
{
	//задание 1.2.1.12д
	cout << "S(n) - ?\n\n";
	
	int n(0);
	cout << "n = ";
	cin >> n;

	cout << "\nS(n) = " << sum(n) << "\n\n";

	return 0;
}



double a(int i)
{
	if (i == 0)
		return 1;
	else
		return (b(i - 1) * a(i - 1));
}

double b(int i)
{
	if (i == 0)
		return 1;
	else
		return (b(i - 1) + a(i - 1));
}

double sum(int n)
{
	double result = 0;

	for (int i = 0; i < n; i++)
		result += (a(i) / (1 + b(i)));

	return result;
}