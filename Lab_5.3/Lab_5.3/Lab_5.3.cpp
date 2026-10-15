// Лабораторна робота № 5.3, Варіант 6
// z(k) = j(k) + j^2(k-1) + 2*j(1)
//
// j(x) = (sin x + 1) / (cos^2 x + e^x),             |x| >= 1
// j(x) = 1/cos(2x) * sum_{k=0..7} 2^(2k) x^(2k) / (2k)!,  |x| < 1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double j(const double x);

int main()
{
    double kp, kk;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n  = "; cin >> n;

    double dk = (kk - kp) / n;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(8) << "k" << "  |"
        << setw(12) << "z" << "  |" << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        double k = kp + i * dk;
        double z = j(k) + pow(j(k - 1), 2) + 2 * j(1);

        cout << "|" << setw(8) << setprecision(3) << k << "  |"
            << setw(12) << setprecision(5) << z << "  |" << endl;
    }
    cout << "---------------------------" << endl;

    return 0;
}

double j(const double x)
{
    if (abs(x) >= 1)
        return (sin(x) + 1) / (cos(x) * cos(x) + exp(x));
    else
    {
        double S = 0;
        int i = 0;
        double a = 1;                 // перший доданок: (2x)^0 / 0! = 1
        S = a;
        do
        {
            i++;
            // a_i = a_(i-1) * (2x)^2 / ((2i-1) * 2i)
            double R = 4 * x * x / ((2 * i - 1) * (2 * i));
            a *= R;
            S += a;
        } while (i < 7);
        return S / cos(2 * x);
    }
}