#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int partition(int arr[], int left, int right)
{
  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j < right; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[right]);

  return i + 1; // return the correct position of pivot
}

void quickSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
  }
}
int main()
{
  int arr[] = {10, 7, 80, 5, 4};
  quickSort(arr, 0, 4);

  for (int e : arr)
  {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}