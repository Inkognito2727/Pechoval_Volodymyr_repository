#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

double sigmweight(int x)
{
    return x*pow(1+exp(-x), -1);
}

//производная
double derivative(int x)
{
    return 1 / (1 + exp(-x)) + (exp(-x) * x) / pow(1 + exp(-x), 2);
}

int main()
{
    //задание 0.3.6i
    int x = 0;

    cout << "x = ";
    cin >> x;
    
    cout << "\nsigmweight(x) = " << sigmweight(x) << endl;
    cout << "derivative(sigmweight(x)) = " << derivative(x) << "\n\n";

    return 0;
}