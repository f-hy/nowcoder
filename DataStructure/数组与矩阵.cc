/**
 * @file 数组与矩阵.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-29
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
 * @copyright Copyright (c) 2023
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define file(x)                  \
  freopen(#x ".in", "r", stdin); \
  freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)

void moveZeroes(vector<int>& nums) {
  int cur = 0, i;  // cur统计当前已知非0数数
  for (i = 0; i < nums.size(); ++i)
    if (nums[i]) nums[cur++] = nums[i];
  for (i = cur; i < nums.size(); i++) nums[i] = 0;
}
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct ListNode_cmp {
  bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<ListNode*, vector<ListNode*>, ListNode_cmp> pq;
  for (ListNode* list : lists)
    if (list) pq.emplace(list);
  ListNode *h = new ListNode(), *t = h, *node;
  while (!pq.empty()) {
    node = pq.top(), pq.pop();
    t->next = node, t = t->next;
    if (node->next) pq.emplace(node->next);
  }
  return h->next;
}
int kthSmallest_merge(vector<vector<int>>& matrix, int k) {
  struct point {
    int val, x, y;
    point() : val(0), x(0), y(0) {}
    point(int val, int x, int y) : val(val), x(x), y(y) {}
    bool operator>(const point& a) const { return this->val > a.val; }
  };
  priority_queue<point, vector<point>, greater<point>> pq;
  for (int i = 0; i < matrix.size(); ++i) pq.emplace(matrix[i][0], i, 0);
  point p;
  for (int i = 0; i < k - 1; ++i) {
    p = pq.top(), pq.pop();
    if (p.y != matrix.size() - 1)
      pq.emplace(matrix[p.x][p.y + 1], p.x, p.y + 1);
  }
  return pq.top().val;
}
bool kthSmallest_check(const vector<vector<int>>& matrix, int mid,
                       int k) {  // 不大于mid的数的个数不小于k？
  int i = matrix.size() - 1, j = 0, num = 0;
  while (i >= 0 && j < matrix.size()) {
    if (matrix[i][j] <= mid) {
      num += i + 1;
      j++;
    } else
      i--;
  }  // 不大于mid的数梯形分布
  return num >= k;
}
int kthSmallest_binary_search(vector<vector<int>>& matrix, int k) {
  int left = matrix[0][0], right = matrix[matrix.size() - 1][matrix.size() - 1];
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (kthSmallest_check(matrix, mid, k))
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
  // return kthSmallest_merge(matrix, k);
  return kthSmallest_binary_search(matrix, k);
}
vector<int> findErrorNums_set(vector<int>& nums) {
  vector<int> idx(nums.size() + 1), ans(2);
  for (int i = 1; i <= nums.size(); ++i) idx[i] = i;
  for (int i = 0; i < nums.size(); ++i) {
    if (!idx[nums[i]])
      ans[0] = nums[i];
    else
      idx[nums[i]] = 0;
  }
  for (int i = 1; i <= nums.size(); ++i)
    if (idx[i]) {
      ans[1] = idx[i];
      break;
    }
  return ans;
}
vector<int> findErrorNums_bit(vector<int>& nums) {
  int xr = nums[0] ^ nums.size();
  for (int i = 1; i < nums.size(); ++i) xr ^= nums[i] ^ i;
  int lowbit = xr & (-xr);  // x、y最低不同位
  vector<int> ans(2, 0);
  for (int& x : nums)
    if (x & xr)
      ans[0] ^= x;
    else
      ans[1] ^= x;
  for (int i = 1; i <= nums.size(); ++i)
    if (i & lowbit)
      ans[0] ^= i;
    else
      ans[1] ^= i;
  for (int x : nums)
    if (x == ans[0]) {
      ans[0] ^= ans[1];
      ans[1] ^= ans[0];
      ans[0] ^= ans[1];
      break;
    }
  return ans;
}
vector<int> findErrorNums(vector<int>& nums) {
  // return findErrorNums_set(nums);
  // return findErrorNums_bit(nums);
  int xr = nums[0] ^ nums.size();
  for (int i = 1; i < nums.size(); ++i) xr ^= nums[i] ^ i;
  int lowbit = xr & (-xr);
  int num1 = 0, num2 = 0;
  for (int& num : nums) {
    if ((num & lowbit) == 0)
      num1 ^= num;
    else
      num2 ^= num;
  }
  for (int i = 1; i <= nums.size(); i++) {
    if ((i & lowbit) == 0)
      num1 ^= i;
    else
      num2 ^= i;
  }
  for (int num : nums) {
    if (num == num1) {
      return vector<int>{num1, num2};
    }
  }
  return vector<int>{num2, num1};
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  return 0;
}