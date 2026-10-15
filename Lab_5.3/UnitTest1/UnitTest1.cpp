#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\aizen\Documents\lab c++\Lab_5\Lab_5.3\Lab_5.3\Lab_5.3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5_3Tests
{
    TEST_CLASS(Lab5_3Tests)
    {
    public:

        // гілка |x| >= 1: (sin x + 1) / (cos^2 x + e^x)
        TEST_METHOD(j_x_one)
        {
            double expected = (sin(1.0) + 1) / (cos(1.0) * cos(1.0) + exp(1.0));
            Assert::AreEqual(expected, j(1), 1e-12);
        }

        TEST_METHOD(j_x_two)
        {
            double expected = (sin(2.0) + 1) / (cos(2.0) * cos(2.0) + exp(2.0));
            Assert::AreEqual(expected, j(2), 1e-12);
        }

        TEST_METHOD(j_x_minus_one)
        {
            // |x| = 1 теж іде в першу гілку
            double expected = (sin(-1.0) + 1) / (cos(-1.0) * cos(-1.0) + exp(-1.0));
            Assert::AreEqual(expected, j(-1), 1e-12);
        }

        // гілка |x| < 1: (1 / cos 2x) * сума ряду
        TEST_METHOD(j_zero)
        {
            // сума = 1 (лише перший доданок), cos 0 = 1
            Assert::AreEqual(1.0, j(0), 1e-12);
        }

        TEST_METHOD(j_half)
        {
            // сума ряду до k = 7 дорівнює cosh(2x) з дуже малою похибкою
            double expected = cosh(1.0) / cos(1.0);
            Assert::AreEqual(expected, j(0.5), 1e-9);
        }

        TEST_METHOD(j_near_border)
        {
            double expected = cosh(1.8) / cos(1.8);
            Assert::AreEqual(expected, j(0.9), 1e-8);
        }

        TEST_METHOD(j_is_even_inside_interval)
        {
            // у гілці |x| < 1 функція парна
            Assert::AreEqual(j(0.5), j(-0.5), 1e-12);
        }
    };
}