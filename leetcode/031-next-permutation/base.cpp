#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @brief next permutation
 * 
 * Solution idea:
 * - Step1 : Find the pivot
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