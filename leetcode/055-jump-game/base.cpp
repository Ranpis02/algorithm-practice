#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    // Cover index range
    int cover = 0;
    for (int i = 0; i <= cover; i++)
    {
      cover = max(cover, i + nums[i]);

      if (cover >= (nums.size() - 1))
        return true;
    }

    return false;
  }
};

int main()
{

  return 0;
}