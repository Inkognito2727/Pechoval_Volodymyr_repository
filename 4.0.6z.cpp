#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

struct RectangularParallelepiped
{
    double a, b, h;

    RectangularParallelepiped() : a(0), b(0), h(0) {}
    RectangularParallelepiped(double _a, double _b, double _h) 
    {
        if (_a <= 0 || _b <= 0 || _h <= 0)
        {
            invalid_argument e("Sides cannot be less than 0.\n");
            throw exception(e);
        }
        a = _a;
        b = _b;
        h =_h;
    }

    string showParallelepiped()
    {
        return ("a = " + to_string(a) + ", b = " + to_string(b) + ", h = " + to_string(h));
    }
    double V()
    {
        return a * b * h;
    }
    double baseSquare()
    {
        return a * b;
    }
    double sideSquare()
    {
        return 2 * (a + b) * h;
    }
};

int main()
{
    //задание 4.0.6з
    RectangularParallelepiped p(3, 4, 5);
    cout << p.showParallelepiped() << endl;
    cout << "V = " << p.V() << endl;
    cout << "baseS = " << p.baseSquare() << endl;
    cout << "sideS = " << p.sideSquare() << endl;

    return 0;
}