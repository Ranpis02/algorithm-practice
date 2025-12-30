#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int k = 0;
    int change[3] = {0};

    for (int &bill : bills)
    {
      if (bill == 5)
      {
        change[0]++;
      }
      else if (bill == 10)
      {
        change[1]++;
        if (change[0] <= 0)
          return false;
        change[0]--;
      }
      else
      {
        change[2]++;

        if (change[0] && change[1])
        {
          change[0]--;
          change[1]--;
        }
        else if (change[0] >= 3)
        {
          change[0] -= 3;
        }
        else
        {
          return false;
        }
      }
    }

    return true;
  }
};

int main()
{
  return 0;
}