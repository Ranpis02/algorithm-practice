#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//   vector<int> twoSum(vector<int> &numbers, int target)
//   {
//     int n = numbers.size();
//     int pivot = target / 2;
//     int l = lower_bound(numbers.begin(), numbers.end(), pivot) - numbers.begin();

//     int r = l;

//     while (l >= 0 && r < n)
//     {
//       int total = numbers[l] + numbers[r];

//       if (total == target)
//       {
//         if (l != r)
//           return {l + 1, r + 1};
//         else
//         {
//           r++;
//         }
//       }
//       else if (total > target)
//       {
//         l--;
//       }
//       else
//       {
//         r++;
//       }
//     }

//     return {-1, -1};
//   }
// };

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int n = numbers.size();

    int l = 0, r = n - 1;

    while (l < r)
    {
      int total = numbers[l] + numbers[r];

      if (total == target)
      {
        return {l + 1, r + 1};
      }
      else if (total > target)
      {
        r--;
      }
      else
      {
        l++;
      }
    }

    return {-1, -1};
  }
};
int main()
{

  return 0;
}