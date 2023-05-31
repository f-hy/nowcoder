/**
 * @file 字符串.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-28
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
bool isAnagram(string s, string t) {
  if (s.length() != t.length()) return false;
  vector<int> table(26, 0);
  for (auto& ch : s) table[ch - 'a']++;
  for (auto& ch : t) {
    table[ch - 'a']--;
    if (table[ch - 'a'] < 0) return false;
  }
  return true;
}
int countSubstrings(string s) {
  int n = s.size();
  string t = "$#";
  for (const char& c : s) {
    t += c;
    t += '#';
  }
  n = t.size();
  t += '!';
  auto f = vector<int>(n);
  int iMax = 0, rMax = 0, ans = 0;
  for (int i = 1; i < n; ++i) {
    // 初始化 f[i]
    f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
    // 中心拓展
    while (t[i + f[i]] == t[i - f[i]]) ++f[i];
    // 动态维护 iMax 和 rMax
    if (i + f[i] - 1 > rMax) {
      iMax = i;
      rMax = i + f[i] - 1;
    }
    // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
    ans += (f[i] / 2);
  }

  return ans;
}
int countBinarySubstrings(string s) {
  int p = 0, last = 0, ans = 0, cnt;
  char c;
  while (p < s.length()) {
    cnt = 0;
    c = s[p];
    while (p < s.length() && s[p] == c) ++p, ++cnt;
    ans += min(cnt, last);
    last = cnt;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  return 0;
}