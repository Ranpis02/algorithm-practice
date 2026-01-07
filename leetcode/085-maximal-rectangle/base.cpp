#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int row = matrix.size(), col = matrix[0].size();

    int ans = 0;
    for (int i = 0; i < row; i++)
    {
      vector<int> heights(col + 2);
      heights[0] = 0;

      for (int j = 0; j < col; j++)
      {
        int h = 0;
        for (int k = i; k >= 0; k--)
        {
          if (matrix[k][j] == '1')
          {
            h++;
          }
          else
            break;
        }
        heights[j + 1] = h;
      }

      heights[col + 1] = 0;

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