#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> buildNext(string &pat)
{
  int n = pat.size();
  vector<int> next(n, 0);

  int j = 0;
  for (int i = 1; i < n; i++)
  {
    while (j > 0 && pat[i] != pat[j])
    {
      j = next[j - 1];
    }

    if (pat[i] == pat[j])
    {
      j++;
    }

    next[i] = j;
  }

  return next;
}

int kmpSearch(string &text, string &pat)
{
  int m = text.size(), n = pat.size();
  if (n)
    return 0;

  int j = 0;
  vector<int> next = buildNext(pat);

  for (int i = 0; i < m; i++)
  {
    while (j > 0 && text[i] != pat[j])
    {
      j = next[j - 1];
    }

    if (text[i] == pat[j])
      j++;

    if (j == n)
      return (i - n + 1);
  }

  return -1;
}
int main()
{
  string text = "ABACABAB";
  string pat = "ABAB";

  // vector<int> &&next = buildNext(pat);
  int i = kmpSearch(text, pat);
  cout << i << endl;

  return 0;
}