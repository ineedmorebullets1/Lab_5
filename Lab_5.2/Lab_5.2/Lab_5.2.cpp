// Лабораторна робота № 5.2, Варіант 6
// ln(1-x) = -(x + x^2/2 + x^3/3 + ...), -1 <= x < 1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "    |"
        << setw(10) << "ln(1-x)" << "  |"
        << setw(7) << "S" << "     |"
        << setw(5) << "n" << "  |"
        << endl;
    cout << "---------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "  |"
            << setw(10) << setprecision(5) << log(1 - x) << "  |"
            << setw(10) << setprecision(5) << s << "  |"
            << setw(5) << n << "  |"
            << endl;

        x += dx;
    }
    cout << "---------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 1;
    double a = x;      // перший доданок: x^1 / 1
    s = -a;            // сума береться зі знаком "мінус"
    do {
        n++;
        A(x, n, a);
        s -= a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    // a_n = a_(n-1) * x * (n-1) / n
    a = a * x * (n - 1) / n;
}