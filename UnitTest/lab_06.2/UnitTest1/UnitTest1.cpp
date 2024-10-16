#include "pch.h" // ���� ��������������� precompiled header
#include "CppUnitTest.h"
#include <vector>
#include <limits.h> // ��� INT_MIN
#include <sstream>  // ��� ���������� ���������
#include "../lab_06.2/lab_06.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:

        // ���� ��� ������� generateArray
        TEST_METHOD(TestGenerateArray)
        {
            const int SIZE = 13;
            const int MIN_VAL = -100;
            const int MAX_VAL = 100;
            std::vector<int> arr(SIZE);

            generateArray(arr, MIN_VAL, MAX_VAL);

            // ����������, �� �� �������� � ����� ����������� � �������� �������
            for (const int& elem : arr) {
                Assert::IsTrue(elem >= MIN_VAL && elem <= MAX_VAL, L"Element is out of range.");
            }
        }

        // ���� ��� ������� findMaxOddIndex
        TEST_METHOD(TestFindMaxOddIndex)
        {
            std::vector<int> arr = { -9, -2, 15, 4, 3 };

            int expectedIndex = 2; // ��������� �������� ������� = 15, ������ = 2
            int maxOddIndex = findMaxOddIndex(arr);

            Assert::AreEqual(expectedIndex, maxOddIndex, L"Max odd index is incorrect.");

            // ���� ��� ������ ��� �������� ��������
            std::vector<int> arrWithoutOdd = { -2, 4, 6, 8 };
            int noOddIndex = findMaxOddIndex(arrWithoutOdd);

            Assert::AreEqual(-1, noOddIndex, L"No odd elements, index should be -1.");
        }

        // ���� ��� ������� swapLastWithMaxOdd
        TEST_METHOD(TestSwapLastWithMaxOdd)
        {
            std::vector<int> arr = { 10, 5, 7, -4, 3 };
            std::vector<int> expectedArr = { 10, 5, 3, -4, 7 }; // ���� � ������� ���������

            swapLastWithMaxOdd(arr);

            Assert::IsTrue(arr == expectedArr, L"Array was not swapped correctly.");

            // ���� ��� ������ ��� �������� �������� (����������� �� ������� ����)
            std::vector<int> arrWithoutOdd = { 2, 4, 6, 8, 10 };
            std::vector<int> expectedNoChangeArr = arrWithoutOdd;

            swapLastWithMaxOdd(arrWithoutOdd);

            Assert::IsTrue(arrWithoutOdd == expectedNoChangeArr, L"Array without odd elements should not change.");
        }

        
    };
}
