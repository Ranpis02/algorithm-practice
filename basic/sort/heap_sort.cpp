#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void heapifyDown(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (i != largest)
  {
    swap(arr[i], arr[largest]);
    heapifyDown(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  /**
   * Build heap starting from the last non-leaf node
   */
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapifyDown(arr, n, i);
  }

  /**
   * Sort: Place the largest element at the end one by one
   */
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapifyDown(arr, i, 0); // readjust the arr[0]
  }
}

int main()
{
  int arr[] = {10, 20, 4, 15, 30};
  int n = 5;

  heapSort(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}
