#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int calculate(string s)
  {

    long long ans = 0;
    long long sign = 1;
    long long num = 0;

    stack<int> st;

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      if (isdigit(s[i]))
      {
        while (isdigit(s[i]))
        {
          num = num * 10 + s[i] - '0';
          i++;
        }
        ans += sign * num;
        num = 0;
        i--;
      }
      else if (s[i] == '+')
      {
        sign = 1;
      }
      else if (s[i] == '-')
      {
        sign = -1;
      }
      else if (s[i] == '(')
      {
        st.push(sign);
        st.push(ans);

        ans = 0;
        num = 0;
        sign = 1;
      }
      else if (s[i] == ')')
      {
        int prev_ans = st.top();
        st.pop();
        int prev_sign = st.top();
        st.pop();

        ans = prev_ans + prev_sign * ans;
      }
    }
    return ans;
  }
};

int main()
{
  string s = "-2147483648";
  Solution *sol = new Solution;
  sol->calculate(s);

  return 0;
}