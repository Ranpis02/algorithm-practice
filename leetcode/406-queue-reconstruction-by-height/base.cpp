#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Sort the people by height in descending order.
 * If the heights are equal, sort the number of people ahead `k` in ascending order.
 *
 * Ensure that inserting the current person does not invalidate the relative orer of the previously processed people and guarantees that the insertion index is always valid.
 */
class Solution
{
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
  {

    sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
         {
      if(a[0] == b[0]) return a[1] < b[1];

      return a[0] > b[0]; });

    vector<vector<int>> queue;
    for (int i = 0; i < people.size(); i++)
    {
      int swapIdx = people[i][1];
      queue.insert(queue.begin() + swapIdx, people[i]);
    }

    return queue;
  }
};

int main()
{

  return 0;
}