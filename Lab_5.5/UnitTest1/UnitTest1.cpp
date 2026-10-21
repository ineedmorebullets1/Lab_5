#include "pch.h"
#include "CppUnitTest.h"
#include <vector>

// Підключаємо ваш файл з програмою, перейменувавши його main,
// щоб він не конфліктував із тестовим проєктом.
// Шлях змініть на свій (відносно цього файлу).
#define main lab_main
#include "C:\Users\aizen\Documents\lab c++\Lab_5\Lab_5.5\Lab_5.5\Lab_5.5.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    // Еталон: пряма симуляція кола (кожна друга людина виходить)
    static int Simulate(int n)
    {
        std::vector<int> c;
        for (int i = 1; i <= n; i++) c.push_back(i);
        size_t i = 0;
        while (c.size() > 1)
        {
            i = (i + 1) % c.size();
            c.erase(c.begin() + i);
        }
        return c[0];
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(F_BaseCase)
        {
            Assert::AreEqual(1, f(1));
        }

        TEST_METHOD(F_SmallKnownValues)
        {
            Assert::AreEqual(1, f(2));
            Assert::AreEqual(3, f(3));
            Assert::AreEqual(1, f(4));
            Assert::AreEqual(3, f(5));
            Assert::AreEqual(7, f(7));
            Assert::AreEqual(5, f(10));
            Assert::AreEqual(19, f(41));
            Assert::AreEqual(73, f(100));
        }

        TEST_METHOD(F_PowerOfTwoGivesOne)
        {
            for (int k = 0; k <= 20; k++)
                Assert::AreEqual(1, f(1 << k));
        }

        TEST_METHOD(F_PowerOfTwoMinusOneIsFixedPoint)
        {
            for (int k = 1; k <= 20; k++)
            {
                int n = (1 << k) - 1;
                Assert::AreEqual(n, f(n));
            }
        }

        TEST_METHOD(F_MatchesSimulation)
        {
            for (int n = 1; n <= 500; n++)
                Assert::AreEqual(Simulate(n), f(n));
        }
    };
}
