#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
  vector<string> ans;

public:
  vector<string> letterCombinations(string digits)
  {
    if (digits.empty())
      return {};

    const string mp[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

    int n = digits.size();
    vector<string> store(n);

    for (int i = 0; i < n; i++)
    {
      store[i] = mp[digits[i] - '0'];
    }

    string combination;
    backtracking(store, combination, n);

    return ans;
  }

  void backtracking(const vector<string> &store, string &combination, int n)
  {
    int layer = combination.size();
    if (n == layer)
    {
      ans.push_back(combination);
      return;
    }

    for (auto &ch : store[layer])
    {
      combination.push_back(ch);
      backtracking(store, combination, n);
      combination.pop_back();
    }
  }
};

int main()
{
  return 0;
}