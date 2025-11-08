#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    for (int i = 0; i < matrix.size(); i++)
    {
      if (binarySearch(matrix[i], target))
        return true;
    }
    return false;
  }

private:
  bool binarySearch(const vector<int> &nums, int target)
  {
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
      int m = l + ((r - l) >> 1);

      if (nums[m] == target)
        return true;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return false;
  }
};

int main()
{
  vector<vector<int>> vec = {{1, 2, 3, 4, 5},
                             {6, 7, 8, 9, 10},
                             {11, 12, 13, 14, 15},
                             {16, 17, 18, 19, 20},
                             {21, 22, 23, 24, 25}};

  Solution *s = new Solution;

  s->searchMatrix(vec, 19);

  return 0;
}