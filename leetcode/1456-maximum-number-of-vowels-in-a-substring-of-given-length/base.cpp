#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int n = s.size();
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    int ans = 0;

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
      if (st.count(s[i]))
      {
        cnt++;
      }
    }

    ans = max(ans, cnt);

    for (int i = k; i < n; i++)
    {
      if (st.count(s[i - k]))
        cnt--;
      if (st.count(s[i]))
        cnt++;

      ans = max(ans, cnt);
    }

    return ans;
  }
};

int main()
{

  return 0;
}