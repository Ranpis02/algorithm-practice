#include <iostream>
#include <queue>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    deque<int> dq; // store indexes
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
      // Pop the elements with indexes outside the window's bound.
      while (!dq.empty() && dq.front() <= i - k)
      {
        dq.pop_front();
      }

      // Maintain a decreasing order in deque: remove all elements smaller than the current one.
      while (!dq.empty() && nums[dq.back()] <= nums[i])
      {
        dq.pop_back();
      }

      dq.push_back(i);

      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }

    return ans;
  }
};

int main()
{

  return 0;
}