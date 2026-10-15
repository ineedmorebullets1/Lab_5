#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\aizen\Documents\lab c++\Lab_5\Lab_5.2\Lab_5.2\Lab_5.2.cpp"   

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5_2Tests
{
    TEST_CLASS(Lab5_2Tests)
    {
    public:

        // A: наступний доданок через попередній, a_n = x^n / n
        TEST_METHOD(A_second_term)
        {
            double a = 0.5;               // a_1 = x
            A(0.5, 2, a);                 // a_2 = 0.5^2 / 2
            Assert::AreEqual(0.125, a, 1e-12);
        }

        TEST_METHOD(A_third_term)
        {
            double a = 0.125;             // a_2
            A(0.5, 3, a);                 // a_3 = 0.5^3 / 3
            Assert::AreEqual(0.125 / 3.0, a, 1e-12);
        }

        // S: перевірка суми і кількості доданків
        TEST_METHOD(S_x_half_eps_big)
        {
            int n = 0;
            double s = 0;
            S(0.5, 0.1, n, s);            // доданки: 0.5, 0.125, 0.041667 (< 0.1, стоп)
            Assert::AreEqual(3, n);
            Assert::AreEqual(-(0.5 + 0.125 + 0.125 / 3.0), s, 1e-9);
        }

        TEST_METHOD(S_x_zero)
        {
            int n = 0;
            double s = 1;
            S(0.0, 0.001, n, s);
            Assert::AreEqual(0.0, s, 1e-12);
            Assert::AreEqual(2, n);       // перший доданок 0, один прохід циклу
        }

        // S порівняно з точним log(1-x)
        TEST_METHOD(S_matches_log_positive_x)
        {
            int n = 0;
            double s = 0;
            S(0.5, 1e-6, n, s);
            Assert::AreEqual(log(1 - 0.5), s, 1e-5);
        }

        TEST_METHOD(S_matches_log_negative_x)
        {
            int n = 0;
            double s = 0;
            S(-0.5, 1e-6, n, s);
            Assert::AreEqual(log(1 + 0.5), s, 1e-5);
        }
    };
}