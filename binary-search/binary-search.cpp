// binary-search.cpp : This file will contain code that uses binary search to find an element in a given array.
//

#include <iostream>
#include <array>

///---------------------------------------------------------------------
/// binary search function using recursion
/// arr is the array being passed
/// low is the lowest value in the array
/// high is the highest value in the array
/// x is value that we need to find at some position in the array
/// ---------------------------------------------------------------------
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid]) // x will be on the right side of the array.
        {
            return binarySearch(arr, mid + 1, high, x);
        }
        else if (x < arr[mid]) // x will be on the left side of the array.
        {
            return binarySearch(arr, low, mid - 1, x);
        }

    }

    return -1;
}

int main()
{
    int myArray[] = { 3, 4, 5, 6, 7, 8, 9 };
    int x = 7;
    int high = sizeof(myArray) / sizeof(myArray[0]);
    int low = 0;

    int result = binarySearch(myArray, low, high, x);

    if (result == -1)
        std::cout << "Result not found" << std::endl;
    else
        std::printf("Element is found at index %d", result);

    return 0;
}

