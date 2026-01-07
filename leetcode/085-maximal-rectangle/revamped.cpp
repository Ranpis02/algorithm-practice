#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int row = matrix.size(), col = matrix[0].size();
    vector<int> heights(col + 2, 0);
    int ans = 0;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (matrix[i][j] == '1')
        {
          heights[j + 1] += 1;
        }
        else
        {
          heights[j + 1] = 0;
        }
      }

      stack<int> st;
      for (int j = 0; j < col + 2; j++)
      {
        while (!st.empty() && heights[j] < heights[st.top()])
        {
          int h = heights[st.top()];
          st.pop();

          int w = j - st.top() - 1;

          ans = max(ans, w * h);
        }

        st.push(j);
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}