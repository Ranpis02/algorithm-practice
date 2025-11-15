#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Sort a set of data in the range [0, 1)
 *
 * @param nums A vector of `double` type numbers to be sorted, assume to be in the range of [0, 1)
 */
void bucketSort(vector<double> &nums)
{
  int len = nums.size();
  if (len <= 0)
    return;

  vector<vector<double>> buckets(10, vector<double>{});

  for (double &val : nums)
  {
    int bucketIndex = int(val * 10);

    buckets[bucketIndex].push_back(val);
  }

  int index = 0;
  for (auto &bucket : buckets)
  {
    sort(bucket.begin(), bucket.end());

    for (double val : bucket)
    {
      nums[index++] = val;
    }
  }
}
int main()
{
  vector<double> nums = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.0, 0.99};

  bucketSort(nums);

  for (double val : nums)
  {
    cout << val << " ";
  }

  cout << endl;
  return 0;
}