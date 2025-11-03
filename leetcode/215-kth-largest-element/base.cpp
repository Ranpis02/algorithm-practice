#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

/**
 *Solution 01: Use the bubble sort algorithm to extract the K largest elements, then sort them and determine the Kth largest element.
 *
 * Time Complexity: O(N * K + K logK)
 *
 * Solution 02: Build a min-heap using the first K elements and keep its size fixed at K. Then, travsal the remaining elements from K + 1 to N; for each element, if it is larger than the heap's top, remove the top element and insert the current one into the heap.
 */
class BubbleSolution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    if (nums.size() < k || k < 0 || nums.empty())
      throw invalid_argument("Invalid K and empty array!");

    // Extract the K largest elements using bubble sort
    for (int i = 0; i < k; i++)
    {
      for (int j = 0; j < nums.size() - 1 - i; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          swap(nums[j], nums[j + 1]);
        }
      }
    }

    // Select the Kth largest element from the K largest elements
    // Caution: The type of nums.size() is size_t, which is an unsigned integer type. When performing arithmetic operations with signed integers
    vector<int> kLargestElements;
    for (int i = nums.size() - 1; i >= (int)nums.size() - k; i--)
    {
      kLargestElements.push_back(nums[i]);
    }

    sort(kLargestElements.begin(), kLargestElements.end(), greater<int>());

    return kLargestElements[k - 1];
  }
};

class MinHeapSolution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    // 
    return 0;
  }
};

int main()
{
  vector<int> nums = {1};
  BubbleSolution *sol = new BubbleSolution;

  int res = sol->findKthLargest(nums, 1);
  cout << res << endl;

  return 0;
}