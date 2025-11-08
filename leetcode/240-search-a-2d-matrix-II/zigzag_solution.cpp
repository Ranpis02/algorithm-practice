#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0)
    {
      if (matrix[row][col] == target)
        return true;

      else if (matrix[row][col] < target)
        ++row;
      else
        --col;
    }
    return false;
  }
};

class Solution_2
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int row = matrix.size() - 1, col = 0;
    while (row >= 0 && col < matrix[0].size())
    {
      if (matrix[row][col] == target)
        return true;

      else if (matrix[row][col] < target)
        ++col;
      else
        --row;
    }
    return false;
  }
};
int main()
{
  return 0;
}