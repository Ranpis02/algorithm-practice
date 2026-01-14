#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5; // assumed data size
int arr[MAXN];            // original array
int tree[MAXN * 4];       // segment tree array
int lazy[MAXN * 4];       // Store the lazy tags

// Example for supporting point update, range update and range sum query.

/**
 * @brief Auxiliary function: update upwards.
 */
void push_up(int node)
{
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

/**
 * @brief Propagates the lazy tag of the current node to its children.
 *
 * @param node The index of the current segment tree node;
 * @param ln   The length of the left child segment.
 * @param rn   The length of the right child segment.
 */
void push_down(int node, int ln, int rn)
{
  if (lazy[node] != 0)
  {
    lazy[node * 2] += lazy[node];
    tree[node * 2] += lazy[node] * ln;

    lazy[node * 2 + 1] += lazy[node];
    tree[node * 2 + 1] += lazy[node] * rn;

    // clear current lazy tag
    lazy[node] = 0;
  }
}

/**
 * @brief Builds the segment tree.
 *
 * @param node  The index of current segment tree node.
 * @param start The left boundary of current segment.
 * @param end   The right boundary of current segment.
 */
void build(int node, int start, int end)
{
  if (start == end)
  {
    tree[node] = arr[start];
    return;
  }

  int mid = (start + end) / 2;

  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);

  push_up(node);
}

/**
 * @brief Performs a range addition on the segment tree.
 *
 * @param node  The index of current segment tree node.
 * @param start The left boundary of current segment.
 * @param end   The right boundary of current segment.
 * @param L     The left boundary of the update range.
 * @param R     The right boundary of the update range.
 * @param val   The value to be added to each element in the range.
 */
void update_range(int node, int start, int end, int L, int R, int val)
{
  if (L <= start && end <= R)
  {
    lazy[node] += val;
    tree[node] += (end - start + 1) * val;

    return;
  }

  int mid = (start + end) / 2;
  push_down(node, mid - start + 1, end - mid);

  if (L <= mid)
  {
    update_range(node * 2, start, mid, L, R, val);
  }

  if (R > mid)
  {
    update_range(node * 2 + 1, mid + 1, end, L, R, val);
  }

  push_up(node);
}

/**
 * @brief Queries the sum over a given range [L, R].
 *
 * @param node  The index of current segment tree node.
 * @param start The left boundary of current segment.
 * @param end   The right boundary of current segment.
 * @param L     The left boundary of the query range.
 * @param R     The right boundary of the query range.
 *
 * @return The sum of elements in the range [L, R].
 */
int query(int node, int start, int end, int L, int R)
{
  if (L <= start && end <= R)
  {
    return tree[node];
  }

  int mid = (start + end) / 2;
  push_down(node, mid - start + 1, end - mid);

  int sum = 0;
  if (L <= mid)
  {
    sum += query(node * 2, start, mid, L, R);
  }

  if (R > mid)
  {
    sum += query(node * 2 + 1, mid + 1, end, L, R);
  }

  return sum;
}

int main()
{
  for (int i = 1; i <= 10; i++)
  {
    arr[i] = i;
  }

  build(1, 1, 10);

  cout << "The sum of range [3, 5]: " << query(1, 1, 10, 3, 5) << endl;

  update_range(1, 1, 10, 3, 5, 10);

  cout << "The sum of range [3, 5]: " << query(1, 1, 10, 3, 5) << endl;

  return 0;
}