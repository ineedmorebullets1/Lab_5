// Варіант 6. Вихід людей з кола (рекурсія)
//
// f(1) = 1
// f(n) = 2*f(n/2) - 1, якщо n парне
// f(n) = 2*f(n/2) + 1, якщо n непарне
 
#include <iostream>
#include <windows.h>
 
using namespace std;
 
// номер людини, що залишилась у колі з n людей
int f(const int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return 2 * f(n / 2) - 1;
    else
        return 2 * f(n / 2) + 1;
}
 
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    cout << "n = "; cin >> n;
 
    if (n < 1)
    {
        cout << "n має бути додатним" << endl;
        return 1;
    }
 
    int x = f(n);                 // перша ітерація
    cout << "Після першої ітерації залишилась людина з номером " << x << endl;
 
    int count = 0;                // кількість повторень після першої ітерації
    while (x != n)                // доки результат не дорівнює кількості людей у раунді
    {
        n = x;                    // у новому раунді стоїть x людей
        x = f(n);
        count++;
    }
 
    cout << "Кількість повторень: " << count << endl;
    cout << "Залишилась людина з номером: " << x << endl;
 
    return 0;
}
 