#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

string solve(int v, int u, int r, int a, int b, int c)
{
    //чтобы узнать количество пересечений нужно решить систему из двух уравнений -
    //круга и прямой. по количеству решений можно судить о количестве пересечений (0/1/2)

    if (b == 0)
    {
        invalid_argument e("Divide by zero.");
        throw exception(e);
    }
    double A = 1 + pow((a/b), 2);
    double B = -2 * v + 2 * a * c / (b * b) + 2 * a * u / b;
    double C = v * v + u * u * +pow(c / b, 2) + 2 * c * u / b - r * r;

    double discriminant = pow(B, 2) - 4 * A * C;
    if (discriminant < 0)
        return "no";
    if (discriminant == 0)
        return "single";
    else
        return "two";
}

int main()
{
    //задание 1.1.10
    int v(0), u(0), r(0);       //параметры круга       (x-v)^2 + (y-u)^2 = r^2
    int a(0), b(0), c(0);       //параметры прямой      ax + by + c = 0

    cout << "(x-v)^2 + (y-u)^2 = r^2\n\n";
    cout << "v = ";
    cin >> v;
    cout << "u = ";
    cin >> u;
    cout << "r = ";
    cin >> r;

    cout << "\nax + by + c = 0\n\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    string howMuch = solve(v, u, r, a, b, c);
    cout << "\n\nLine and circle has " << howMuch << " intersections.\n\n";

    return 0;
}