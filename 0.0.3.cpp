#include <iostream>
#include <string>
using namespace std;


int main()
{
    //задание 0.0.3
    unsigned height = 20;     //размер системы координат в единицах
    unsigned width = height * 2;

    for (size_t i = 0; i <= height; i++)
    {
        for (size_t j = 0; j <= width; j++)
        {
            if (i == height / 2 + 1)
            {
                if (j == width / 2 + 2)
                    cout << '1';
                else if (j == width / 2)
                    cout << '|';
                else
                    cout << ' ';
            }
            else if (i != height / 2)
            {
                if (i == 0)
                {
                    if (j == width / 2)
                        cout << '^';
                    else if (j == width / 2 + 2)
                        cout << 'y';
                    else
                        cout << ' ';
                }
                else if (i == height / 2 - 1 && j == width - 1)
                    cout << 'x';
                else
                {
                    if (j == width / 2)
                        cout << '|';
                    else
                        cout << ' ';
                }
            }
            else
            {
                if (j != width)
                    cout << '-';
                else
                    cout << '>';
            }
        }
        cout << endl;
    }

    return 0;
}