#include <iostream>
#include <cmath>

using namespace std;

// множник добутку (дійсне ділення!)
double f(const int k, const int N)
{
    return (1. * (k - N)) / (k + N) + 1;
}

// 0) ітераційний спосіб (для контролю)
double P0(const int N, const int M)
{
    double p = 1;
    for (int k = N; k <= M; k++)
        p *= f(k, N);
    return p;
}

// 1) рекурсивний спуск, параметр k зростає
double P1(const int N, const int M, const int k)
{
    if (k > M)
        return 1;
    else
        return f(k, N) * P1(N, M, k + 1);
}

// 2) рекурсивний спуск, параметр k спадає
double P2(const int N, const int k)
{
    if (k < N)
        return 1;
    else
        return f(k, N) * P2(N, k - 1);
}

// 3) рекурсивний підйом, параметр k зростає
double P3(const int N, const int M, const int k, double t)
{
    t = t * f(k, N);
    if (k >= M)
        return t;
    else
        return P3(N, M, k + 1, t);
}

// 4) рекурсивний підйом, параметр k спадає
double P4(const int N, const int k, double t)
{
    t = t * f(k, N);
    if (k <= N)
        return t;
    else
        return P4(N, k - 1, t);
}

int main()
{
    const int M = 19;   // верхня межа добутку
    int N;
    cout << "N = "; cin >> N;

    if (N < 1 || N > M)
    {
        cout << "N має бути в межах від 1 до " << M << endl;
        return 1;
    }

    cout << "(iter)         P0 = " << P0(N, M) << endl;
    cout << "(rec up ++)    P1 = " << P1(N, M, N) << endl;
    cout << "(rec up --)    P2 = " << P2(N, M) << endl;
    cout << "(rec down ++)  P3 = " << P3(N, M, N, 1) << endl;
    cout << "(rec down --)  P4 = " << P4(N, M, 1) << endl;

    return 0;
}
