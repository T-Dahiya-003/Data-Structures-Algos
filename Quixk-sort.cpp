// It works on the idea that all the elements before it are smaller and all the elements after it are greater
// It's a Divide and Conquer Algorithm
// Divide the problems into sub porblems
// Sole the sub problems by calling it recursivley until it's solved (Conquer)
// Combine the sub problems to get the result

// Approach
// Make the pivot at the first element and take two variables i and j, i look for the greater elemnents and j for smaller elements
// Run the loop until i becomes greater than j
// Partitoning Procedure
// Take the first element as the pivot and allot i and j variables, search for the elemnt greater than pivot as i, similiarly for th k check for the lement that are gsmaller than pivot
// If i becomes greater than j we'll get the point where partitioned happened then interchnage the jth value with pivot
// This is called Partioning Point, we'll get two arrays one that's smaller than pivot and other greater than pivot
// Now apply Quick sort on both of those arrays

// Impoortant points
// Elements if they are in ascending or descending will take O(N^2) time, thsi is also the worst case time for the Quick Sort
// At the best case when the partition happens in the middle then time complexity is O(NLogN)
// Avearge time is said to be O(NLogN)
// The difference between selection sort and Quick sort is that in the selection sort we are selecting position and finsing elemnt for that posiiton
// whereas in Quick Sort we are selecting element and finsing position for it

// 50(pivot, i), 70, 60, 90, 40, 80, 10, 20, 30(j)
// 50, 30, 60(i), 90, 40, 80, 10, 20(j), 70
// 50, 30, 20, 90(i), 40, 80, 10(j), 60, 70
// 50, 30, 20, 10, 40, 80, 90, 60, 70
// 50, 30, 20, 10, 40(I), 80(j), 90, 60, 70
// 50, 30, 20, 10, 40(j), 80(i), 90, 60, 70
// Now swap the pivot with j
// (40, 30, 20, 10), (50), (80, 90, 60, 70)
// Now apply Quick Sort on low to j then another Quick Sort for j+1 to high
// Code

#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = Partition(arr, low, high);
        QuickSort(arr, low, j);
        QuickSort(arr, j + 1, high);
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT32_MAX};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n);
    PrintArray(arr, n);
    return 0;
}