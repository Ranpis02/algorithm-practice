#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Perform a binary search on an ascending sorted array based on recursion.
 *
 * @param a The target array.
 * @param l The left boundary index of search range.
 * @param r The right boundary index of search range.
 * @param target The target value to search for.
 *
 * @return The index of target if found. Otherwise -1.
 */
int binarySearchBaseOnRecursion(int a[], int l, int r, int target)
{
  if (r > l)
    return -1;

  int mid = l + ((r - l) >> 1);

  if (a[mid] == target)
    return mid;
  else if (a[mid] > target)
    return binarySearchBaseOnRecursion(a, l, mid - 1, target);
  else
    return binarySearchBaseOnRecursion(a, mid + 1, r, target);
}

int binarySearchBaseOnIteration(int a[], int n, int target)
{
  int l = 0, r = n - 1;

  while (l <= r)
  {
    int mid = l + ((r - l) >> 1);

    if (a[mid] == target)
      return mid;

    else if (a[mid] > target)
      r = mid - 1;
    else
      l = mid + 1;
  }

  return -1;
}

int main()
{

  int a[] = {1, 2, 3, 4, 5};
  int res = binarySearchBaseOnIteration(a, 5, 5);
  cout << res << endl;

  return 0;
}