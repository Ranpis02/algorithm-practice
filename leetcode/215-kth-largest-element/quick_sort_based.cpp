#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    int res = quickSelect(nums, k);

    return res;
  }

private:
  int quickSelect(vector<int> &nums, int k)
  {
    vector<int> big, small, equal;

    int n = nums.size();

    // Select an element randomly
    srand(time(0));
    int pivotIndex = rand() % n;

    int pivot = nums[pivotIndex];

    for (int i = 0; i < n; i++)
    {
      if (nums[i] < pivot)
        small.push_back(nums[i]);
      else if (nums[i] > pivot)
        big.push_back(nums[i]);
      else
        equal.push_back(nums[i]);
    }

    if (big.size() >= k)
      return quickSelect(big, k);
    else if (big.size() + equal.size() < k)
      return quickSelect(small, k - big.size() - equal.size());
    else
      return pivot;
  }
};

int main()
{
  // new Solution

  return 0;
}
