#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    vector<int> L{1}, R{1}, res; // define two vectors to store the cumulative product of left and right elements

    for (int i = 0; i < nums.size(); i++)
    {
      L.push_back(L[i] * nums[i]);
      R.push_back(R[i] * nums[nums.size() - 1 - i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      res.push_back(L[i] * R[nums.size() - 1 - i]);
    }

    return res;
  }
};

int main()
{
  return 0;
}