#include "pch.h" // Якщо використовується precompiled header
#include "CppUnitTest.h"
#include <vector>
#include <limits.h> // Для INT_MIN
#include <sstream>  // Для тестування виведення
#include "../lab_06.2/lab_06.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:

        // Тест для функції generateArray
        TEST_METHOD(TestGenerateArray)
        {
            const int SIZE = 13;
            const int MIN_VAL = -100;
            const int MAX_VAL = 100;
            std::vector<int> arr(SIZE);

            generateArray(arr, MIN_VAL, MAX_VAL);

            // Перевіряємо, що всі елементи в масиві знаходяться в заданому діапазоні
            for (const int& elem : arr) {
                Assert::IsTrue(elem >= MIN_VAL && elem <= MAX_VAL, L"Element is out of range.");
            }
        }

        // Тест для функції findMaxOddIndex
        TEST_METHOD(TestFindMaxOddIndex)
        {
            std::vector<int> arr = { -9, -2, 15, 4, 3 };

            int expectedIndex = 2; // Найбільший непарний елемент = 15, індекс = 2
            int maxOddIndex = findMaxOddIndex(arr);

            Assert::AreEqual(expectedIndex, maxOddIndex, L"Max odd index is incorrect.");

            // Тест для масиву без непарних елементів
            std::vector<int> arrWithoutOdd = { -2, 4, 6, 8 };
            int noOddIndex = findMaxOddIndex(arrWithoutOdd);

            Assert::AreEqual(-1, noOddIndex, L"No odd elements, index should be -1.");
        }

        // Тест для функції swapLastWithMaxOdd
        TEST_METHOD(TestSwapLastWithMaxOdd)
        {
            std::vector<int> arr = { 10, 5, 7, -4, 3 };
            std::vector<int> expectedArr = { 10, 5, 3, -4, 7 }; // Обмін з останнім елементом

            swapLastWithMaxOdd(arr);

            Assert::IsTrue(arr == expectedArr, L"Array was not swapped correctly.");

            // Тест для масиву без непарних елементів (модифікації не повинно бути)
            std::vector<int> arrWithoutOdd = { 2, 4, 6, 8, 10 };
            std::vector<int> expectedNoChangeArr = arrWithoutOdd;

            swapLastWithMaxOdd(arrWithoutOdd);

            Assert::IsTrue(arrWithoutOdd == expectedNoChangeArr, L"Array without odd elements should not change.");
        }

        
    };
}
