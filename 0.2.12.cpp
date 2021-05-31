#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

pair<double, double> solve(int a, int b, int c)
{
    pair<double, double> x = {0,0};
    if (a == 0)
        throw exception("Divide by zero exception.");

    double discriminant = pow(b, 2) - 4 * a * c;
    x.first = (-b + 4 * sqrt(discriminant)) / (2 * a);
    x.second = (-b - 4 * sqrt(discriminant)) / (2 * a);

    return x;
}

int main()
{
    //задание 0.2.12
    cout << "ax^2 + bx + c = 0; \t x1, x2 - ?\n\n";

    int a(0), b(0), c(0);
    
    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;
    cout << endl;
    
    try 
    {
        pair<double, double> x = solve(a, b, c);
        cout << "x1 = " << x.first << endl;
        cout << "x2 = " << x.second << "\n\n";
    }
    catch (exception e)
    {
        cout << e.what() << "\n\n";
    }
    

    return 0;
}