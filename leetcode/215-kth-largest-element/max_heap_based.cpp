#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    int n = nums.size();
    int cnt = 1;

    if (k > n)
      throw "The k is illegal";

    for (int i = n / 2 - 1; i >= 0; i--)
    {
      heapify(nums, n, i);
    }

    for (int i = n - 1; i >= n - k + 1; i--)
    {
      swap(nums[0], nums[i]);
      heapify(nums, i, 0);
    }

    return nums[0];
  }

  void heapify(vector<int> &nums, int n, int i)
  {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
    {
      largest = left;
    }

    if (right < n && nums[right] > nums[largest])
    {
      largest = right;
    }

    if (i != largest)
    {
      swap(nums[i], nums[largest]);
      heapify(nums, n, largest);
    }
  }
};

int main()
{
  vector nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};

  Solution *s = new Solution;
  int k = 4;
  cout << s->findKthLargest(nums, k) << endl;

  return 0;
}