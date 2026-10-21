#include "pch.h"
#include "CppUnitTest.h"
#define main lab_main
#include "C:\Users\aizen\Documents\lab c++\Lab_5\Lab_5.4\Lab_5.4\Lab_5.4.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    // Незалежний еталон: (k-N)/(k+N) + 1 = 2k/(k+N)
    static double Reference(int N, int M)
    {
        long double p = 1;
        for (int k = N; k <= M; k++)
            p *= (2.0L * k) / (k + N);
        return (double)p;
    }

    TEST_CLASS(UnitTest1)
    {
    public:
        static const int M = 19;
        static constexpr double EPS = 1e-9;

        TEST_METHOD(Factor_EqualsOneWhenKEqualsN)
        {
            Assert::AreEqual(1.0, f(5, 5), EPS);
        }

        TEST_METHOD(Factor_KnownValues)
        {
            Assert::AreEqual(1.5, f(3, 1), EPS);
            Assert::AreEqual(2.0 * 19 / 20, f(19, 1), EPS);
        }

        TEST_METHOD(Iterative_KnownValues)
        {
            Assert::AreEqual(26214.4, P0(1, M), 1e-6);
            Assert::AreEqual(97.1383, P0(5, M), 1e-4);
            Assert::AreEqual(1.0, P0(19, M), EPS);
        }

        TEST_METHOD(DescentIncreasing_P1_MatchesReference)
        {
            for (int N = 1; N <= M; N++)
                Assert::AreEqual(Reference(N, M), P1(N, M, N), 1e-6);
        }

        TEST_METHOD(DescentDecreasing_P2_MatchesReference)
        {
            for (int N = 1; N <= M; N++)
                Assert::AreEqual(Reference(N, M), P2(N, M), 1e-6);
        }

        TEST_METHOD(AscentIncreasing_P3_MatchesReference)
        {
            for (int N = 1; N <= M; N++)
                Assert::AreEqual(Reference(N, M), P3(N, M, N, 1), 1e-6);
        }

        TEST_METHOD(AscentDecreasing_P4_MatchesReference)
        {
            for (int N = 1; N <= M; N++)
                Assert::AreEqual(Reference(N, M), P4(N, M, 1), 1e-6);
        }

        TEST_METHOD(AllFiveMethodsAgree)
        {
            for (int N = 1; N <= M; N++)
            {
                double p0 = P0(N, M);
                Assert::AreEqual(p0, P1(N, M, N), 1e-6);
                Assert::AreEqual(p0, P2(N, M), 1e-6);
                Assert::AreEqual(p0, P3(N, M, N, 1), 1e-6);
                Assert::AreEqual(p0, P4(N, M, 1), 1e-6);
            }
        }

        TEST_METHOD(RecursionBaseCases_EmptyProductIsOne)
        {
            Assert::AreEqual(1.0, P1(19, M, 20), EPS);
            Assert::AreEqual(1.0, P2(5, 4), EPS);
        }
    };
}