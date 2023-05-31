/**
 * @file test.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-25
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

int main() {
  ios::sync_with_stdio(false);
  // file(data);
  vector<int> v(10);
  v.emplace_back(2);
  v.push_back(3);
  for (auto &x : v) cout << x << ' ';
  return 0;
}