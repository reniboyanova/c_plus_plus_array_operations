#include <iostream>

void findSpiralPath(int arr[][5], const int numRows, const int numCols)
{
    int top = 0;
    int bottom = numRows - 1;
    int left = 0;
    int right = numCols - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            std::cout << arr[top][i] << " с индекс: " << top << i << '\n';
        }

        for (int i = top + 1; i <= bottom; i++)
        {
            std::cout << arr[i][right] << " с индекс: " << i << right << '\n';
        }

        if (top < bottom)
        {
            for (int i = right - 1; i >= left; i--)
            {
                std::cout << arr[bottom][i] << " с индекс: " << bottom << i << '\n';
            }
        }

        if (left < right)
        {
            for (int i = bottom - 1; i > top; i--)
            {
                std::cout << arr[i][left] << " с индекс: " << i << left << '\n';
            }
        }

        top++;
        bottom--;
        left++;
        right--;
    }
}

int main()
{
    constexpr int numRows = 4;
    constexpr int numCols = 5;
    int arr[numRows][numCols] = {{1, 2, 3, 4, 5}, {14, 15, 16, 17, 6}, {13, 20, 19, 18, 7}, {12, 11, 10, 9, 8}};
    int num = 1;

    // for (int i = 0; i < numRows; i++)
    // {
    //     for (int j = 0; j < numCols; j++)
    //     {
    //         arr[i][j] = num;
    //         num++;
    //     }
    // }

    findSpiralPath(arr, numRows, numCols);

    return 0;
}
