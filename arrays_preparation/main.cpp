#include <iostream>
#include <string>
#include <iomanip>

float calculatePrices(const float *prices, size_t sizeOfArr)
{
    float endSum = 0.0;
    const float *begin = prices;
    const float *end = prices + sizeOfArr;
    for (const float *it = begin; it != end; ++it)
    {
        endSum += *it;
    }
    return endSum;
}

unsigned int castingPricesToInt(float *prices, size_t sizeOfArr)
{
    unsigned int priceInInt = 0.0;
    for (size_t i = 0; i < sizeOfArr; i++)
    {
        priceInInt += static_cast<int>(prices[i]);
    }
    return priceInInt;
}

void printMarks(std::string marks[], const int size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << marks[i] << ' ';
    }
}

void sizeOfPointer_or_justArr(int *arr) // SAME AS void fun(int *arr)
{
    unsigned int n = sizeof(arr);
    std::cout << "\nPointer size is: " << n << std::endl;
}

int main()
{
    const int size = 8;
    std::string cars[size] = {"Mazda", "KIA", "BMW", "Subaru", "Masserati", "Bentley", "Mercedes", "Audi"};
    // printMarks(cars, size);

    int *myArr = new int[4];
    myArr[0] = 100;
    myArr[1] = 102;
    myArr[2] = 104;
    myArr[3] = 106;
    try
    {
        for (int i = 0; i < 10; i++)
        {
            if (i >= size)
            {
                throw std::out_of_range("Index out of bounds");
            }
            std::cout << cars[i] << ", ";
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "\nERROR: " << std::endl;
        std::cerr << e.what() << '\n';
    }

    std::cout << "In dynamic array - one element size is: " << sizeof(myArr[0]) << " Size of pointer to this element is: " << sizeof(myArr) << std::endl;
    std::cout << "Size of array is: " << sizeof(myArr) / sizeof(myArr[0]) << " But its not correct, because there are 4 elements!" << std::endl;
    ;

    sizeOfPointer_or_justArr(myArr);

    delete[] myArr;

    int myArr2[3] = {1, 2, 3};
    std::cout << "In static size array - one element size is: " << sizeof(myArr2[0]) << " Size of all ements is: " << sizeof(myArr2) << std::endl;
    std::cout << "Size of array is: " << sizeof(myArr2) / sizeof(myArr2[0]) << std::endl;

    // std::cout << "First element is always a whole array dereferension: " << *cars << std::endl;

    // for (auto &car : cars)
    // {
    //     std::cout << car << ' ';
    // }

    // size_t size;
    // std::cout << "Please insert a size of arr: ";
    // std::cin >> size;

    // float *prices = new float[size];

    // for (size_t i = 0; i < size; i++)
    // {
    //     float current_price = 0.0f;
    //     std::cout << "Insert current price: ";
    //     std::cin >> current_price;
    //     prices[i] = current_price;
    // }

    // std::cout << std::endl;

    // float allPrices = calculatePrices(prices, size);
    // std::cout << "All prices of cars are: " << std::fixed << std::setprecision(2) << allPrices << std::endl;

    // for (size_t i = 0; i < size; i++)
    // {
    //     std::cout << cars[i] << " - $" << prices[i] << std::endl;
    // }

    // std::cout << "Calculation of prices in int: " << castingPricesToInt(prices, size);

    // delete[] prices;

    // int *ptrInt = new int(56);

    // int caculation{64};

    // caculation += *ptrInt;
    // std::cout << "Calculation: " << caculation;

    // delete ptrInt;
}
