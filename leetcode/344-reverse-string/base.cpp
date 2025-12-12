#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
      swap(s[i], s[j]);
    }
  }
};

int main()
{
  vector<char> t = {'a', 'm', 'a', 'n', 'a', 'P', ' ', ':', 'l', 'a', 'n', 'a', 'c', ' ', ' ', 'a', ',', 'n', 'a', 'l', 'p', ' ', 'a', ' ', ',', 'n', 'a', 'm', ' ', 'A'};

  Solution *sol = new Solution;
  sol->reverseString(t);

  return 0;
}