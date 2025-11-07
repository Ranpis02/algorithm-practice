#include <iostream>
#include <vector>
using namespace std;

int first_equal_solution(const vector<int> &nums, int target)
{
  int l = 0, r = nums.size();

  while (l < r)
  {
    int mid = l + ((r - l) >> 1);

    if (nums[mid] < target)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }

    if (l < nums.size() && nums[l] == target)
      return l;
    else
      return -1;
  }
}

int main()
{

  return 0;
}