#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    stack<int> st;
    int water = 0;

    for (int i = 0; i < height.size(); i++)
    {
      while (!st.empty() && height[st.top()] < height[i])
      {
        int bottomIdx = st.top();
        st.pop();

        if (st.empty())
          break;

        int rightIdx = i, leftIdx = st.top();

        int w = rightIdx - leftIdx - 1;
        int h = min(height[rightIdx], height[leftIdx]) - height[bottomIdx];

        water += w * h;
      }

      st.push(i);
    }

    return water;
  }
};

int main()
{

  vector<int> nums = {4, 2, 0, 3, 2, 5};
  Solution *s = new Solution;
  s->trap(nums);
  return 0;
}