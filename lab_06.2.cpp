#include <iostream>
#include <vector>
#include <iomanip> 

void generateArray(std::vector<int>& arr, int minVal, int maxVal) 
{
    for (int& elem : arr) 
    {
        elem = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(const std::vector<int>& arr) 
{
    for (const int& elem : arr) 
    {
        std::cout << std::setw(5) << elem; 
    }
    std::cout << std::endl;
}

int findMaxOddIndex(const std::vector<int>& arr) 
{
    int maxOdd = INT_MIN;
    int maxOddIndex = -1;

    for (int i = 0; i < arr.size(); ++i) 
    {
        if (arr[i] % 2 != 0 && arr[i] > maxOdd) 
        {
            maxOdd = arr[i];
            maxOddIndex = i;
        }
    }

    return maxOddIndex; 
}

void swapLastWithMaxOdd(std::vector<int>& arr) 
{
    int maxOddIndex = findMaxOddIndex(arr);

    if (maxOddIndex != -1) 
    { 
        std::swap(arr[arr.size() - 1], arr[maxOddIndex]);
    }
}

int main() 
{
    srand(time(0)); 

    const int SIZE = 13;
    const int MIN_VAL = -100;
    const int MAX_VAL = 100;

    std::vector<int> arr(SIZE);

    generateArray(arr, MIN_VAL, MAX_VAL);
    std::cout << "Початковий масив: " << std::endl;
    printArray(arr);

    swapLastWithMaxOdd(arr);

    std::cout << "Модифікований масив: " << std::endl;
    printArray(arr);

    return 0;
}
