#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <cmath>
using namespace std;


int main() 
{
    //задание 7
    string A(""), B(""), C("");
    double a(0), b(0), c(0);

    //маскированный ввод трех чисел
    while (true)
    {
        cout << "A (xxx.xxx):\t";
        getline(cin, A);

        if (A.size() != 7 || !isdigit(A[0]) || !isdigit(A[1]) || !isdigit(A[2]) || A[3] != '.' || !isdigit(A[4]) || !isdigit(A[5]) || !isdigit(A[6]))
            continue;
        a = stod(A);
        break;
    }
    while (true)
    {
        cout << "B (xxExxx):\t";
        getline(cin, B);

        if (B.size() != 6 || !isdigit(B[0]) || !isdigit(B[1]) || B[2] != 'E' || !isdigit(B[3]) || !isdigit(B[4]) || !isdigit(B[5]))
            continue;
        b = stod(B);
        break;
    }
    while (true)
    {
        cout << "C (xxx.xxxx):\t";
        getline(cin, C);

        if (C.size() != 8 || !isdigit(C[0]) || !isdigit(C[1]) || !isdigit(C[2]) || C[3] != '.' || !isdigit(C[4]) || !isdigit(C[5]) || !isdigit(C[6]) || !isdigit(C[7]))
            continue;
        c = stod(C);
        break;
    }

    double h = 3 / (1/a + 1/b + 1/c);
        
    cout << "Harmonical average in scientic output:\t" << scientific << h << endl;
    cout << "Harmonical average in default output:\t" << h << endl;

    return 0;
}