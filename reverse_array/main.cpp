#include <iostream>
#include <unordered_set>
#include <set>

int *reverse_arr(int arr[], const int size)
{
    // int *new_arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        std::swap(arr[i], arr[size - 1 - i]);
        // int temp = arr[i];
        // arr[i] = arr[size - 1 - i];
        // arr[size - 1 - i] = temp;
    }

    return arr;
}

void find_min_and_max(int arr[], int size, int &min, int &max)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
}

bool ifSubarrayOfArr(int arr[], int arr2[], int size, int sizeOfSub)
{
    int begin = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == *arr2)
        {
            begin = i;
            break;
        }
    }
    int subArr = 0;
    int Size2 = sizeOfSub;
    while (Size2 > 0)
    {
        if (arr[begin + subArr] == arr2[subArr])
        {
            subArr += 1;
        }
        Size2--;
    }

    return subArr == sizeOfSub;
}

std::unordered_set<int> unionTwoArrays(int arr[], int arr2[], int size, int sizeSub)
{
    std::unordered_set<int> unOrdSet;
    while (size)
    {
        unOrdSet.insert(arr[--size]);
    }
    while (sizeSub)
    {
        unOrdSet.insert(arr2[--sizeSub]);
    }

    return unOrdSet;
}

void findSearchingNumber(int arr[], int size, int n)
{
    int mover = 0;
    std::set<int> indexes;
    while (n)
    {
        if (mover == size)
            break;
        if (*(arr + mover) <= n)
        {
            n -= *(arr + mover);
            indexes.insert(mover);
        }
        mover++;
    }
    for (int num : indexes)
    {
        std::cout << num << ' ';
    }
}

void binarySearchImplementation(int arr[], int size, int searchingNum)
{
    int left = 0;
    int right = size - 1;
    int middle = (right - left) / 2;
    while (middle != right)
    {
        if (searchingNum == arr[middle])
        {
            std::cout << "We find searching num at index: " << middle << " and it is: " << arr[middle];
        }
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 45, 67};
    int sub[7] = {5, 4, 12, 1, 2, 3, 67};
    findSearchingNumber(sub, 7, 15);

    // bool isSub = ifSubarrayOfArr(arr, sub, 5, 7);

    // std::cout << "Is is sub arr: " << isSub << std::endl;

    // std::unordered_set<int> unionOfTwoArrs = unionTwoArrays(arr, sub, 5, 3);

    // for (int num : unionOfTwoArrs)
    // {
    //     std::cout << num << ' ';
    // }
    // std::cout << std::endl;
    // // int *reversed = reverse_arr(arr, 5);

    // // for (int i = 0; i < 5; i++)
    // // {
    // //     std::cout << reversed[i] << ' ';
    // // }
    // int numForSearch = 15;

    // int min = arr[0];
    // int max = arr[0];

    // find_min_and_max(arr, 5, min, max);

    // std::cout << "min= " << min << " and max= " << max;

    return 0;
}