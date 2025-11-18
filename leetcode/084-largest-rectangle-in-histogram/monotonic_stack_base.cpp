#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int maxArea = 0;
    stack<int> st;

    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++)
    {
      while (!st.empty() && heights[i] < heights[st.top()])
      {
        int h = heights[st.top()];
        st.pop();

        int w = i - st.top() - 1;

        maxArea = max(maxArea, w * h);
      }

      st.push(i);
    }

    return maxArea;
  }
};

int main()
{

  return 0;
}