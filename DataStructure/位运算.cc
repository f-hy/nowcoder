/**
 * @file 位运算.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-27
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
int hammingDistance(int x, int y) {
  int cnt = 0, z = x ^ y;
  while (z) {
    if (z & 1) ++cnt;
    z >>= 1;
  }
  return cnt;
}
int singleNumber1(vector<int>& nums) {
  int ans = 0;
  for (auto& x : nums) ans ^= x;
  return ans;
}
int missingNumber(vector<int>& nums) {
  int ans = 0;
  for (int i = 0; i < nums.size(); ++i) {
    ans ^= i ^ nums[i];
  }
  ans ^= nums.size();
  return ans;
}
vector<int> singleNumber2(vector<int>& nums) {
  int diff = 0, ans1 = 0, ans2 = 0;
  for (auto& x : nums) diff ^= x;
  diff = diff == INT_MIN ? diff : diff & (-diff);
  for (auto& x : nums) {
    if (x & diff)
      ans1 ^= x;
    else
      ans2 ^= x;
  }
  return {ans1, ans2};
}
uint32_t reverseBits(uint32_t n) {
  uint32_t ans = 0;
  for (int i = 0; i < 32; ++i) {
    ans <<= 1;
    ans |= (n & 1);
    n >>= 1;
  }
  return ans;
}
pii swap(pii p) {
  p.first ^= p.second;
  p.second ^= p.first;
  p.first ^= p.second;
  return p;
}
bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); }
bool isPowerOfFour(int n) { return n > 0 && !(n & (n - 1)) && n % 3 == 1; }
bool hasAlternatingBits(int n) {
  long a = n ^ (n >> 1);
  return !(a & (a + 1));
}
int findComplement(int num) {
  int highbit = 0;
  for (int i = 1; i <= 30; ++i) {
    if (num >= (1 << i))
      highbit = i;
    else
      break;
  }
  int mask = highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1;
  return num ^ mask;
}
int getSum(int a, int b) {
  unsigned int carry;  // 进位结果
  while (b) {
    carry = (unsigned int)(a & b) << 1;  // 需要进位的值
    a ^= b;                              // 无进位求和结果
    b = carry;
  }
  return a;
}
int maxProduct(vector<string>& words) {
  unordered_map<int, int> mp;  // mask,word size
  int mask, ans = 0, tmp;
  for (int i = 0; i < words.size(); i++) {
    mask = 0;
    for (int j = 0; j < words[i].size(); j++) {
      mask |= 1 << (words[i][j] - 'a');
    }                      // 记录字符串各个字母有无情况
    if (mp.count(mask)) {  // 更新mp
      if (words[i].size() > mp[mask]) mp[mask] = words[i].size();
    } else
      mp[mask] = words[i].size();
  }
  unordered_map<int, int>::iterator it = mp.begin(), jt = it;
  for (; it != mp.end(); ++it, jt = it) {
    ++jt;
    for (; jt != mp.end(); ++jt) {
      if (!(it->first & jt->first)) {
        tmp = it->second * jt->second;
        if (ans < tmp) ans = tmp;
      }
    }
  }
  return ans;
}
// x&(x-1)将x的最低位1置0
vector<int> countBits(int n) {
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    ans[i] = ans[i & (i - 1)] + 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  return 0;
}