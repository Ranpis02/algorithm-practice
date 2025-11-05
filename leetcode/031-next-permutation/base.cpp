#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @brief next permutation
 *
 * Key Concept: Lexicographical Order && Greedy based local exchange
 * Approach:
 * 1. keep the longest prefix unchanged
 * 2. make the smallest necessary change to the suffix to get the next larger sequence
 * 
 * Step: 
 * 1. 从右开始扫描第一个递减的元素，即找到第一个 nums[i] < nums[i + 1] 的元素索引 i
 * 2. 从右边序列中找到最小的大于 nums[i] 的元素，然后交换
 * 3. 将 nums[i] 右边的序列进行倒置
 * 
 * Example: [1, 2, 3, 6, 5, 4]
 * 1. find the first decreasing element nums[i]: 3
 * 2. find the smallest element to the right of nums[i] that is greater than nums[i]: 4
 * 3. swap them: [1, 2, (4), 6, 5, (3)]
 * 4. reverse the sequence to the right of nums[i]:  [1, 2, 4, 3, 5, 6]
 */
using namespace std;
class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    if (nums.size() < 1)
      return;

    int pivot = nums.size() - 1;
    while (pivot > 0 && nums[pivot] <= nums[pivot - 1])
    {
      pivot--;
    }

    if (pivot > 0)
    {
      int i = nums.size() - 1;

      while (i >= pivot && nums[i] <= nums[pivot - 1])
        i--;

      swap(nums[i], nums[pivot - 1]);
    }

    reverse(nums.begin() + pivot, nums.end());
  }
};
int main()
{
  Solution *sol = new Solution;
  vector<int> v = {5, 1, 1};

  sol->nextPermutation(v);
  for (int n : v)
  {
    cout << n << " ";
  }
  cout << endl;

  return 0;
}