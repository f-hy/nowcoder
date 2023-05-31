/**
 * @file 图.cc
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
/*
二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和
B，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B
集合，就将这个图称为二分图 。
*/
bool isBipartite_bfs(vector<vector<int>>& graph) {
  // bfs
  vector<int> color(graph.size(), 0);
  int node;
  for (int i = 0; i < graph.size(); ++i) {
    if (!color[i]) {
      queue<int> q;  // 存储边编号
      q.push(i);
      color[i] = 1;
      while (!q.empty()) {
        node = q.front(), q.pop();
        int cnext = (color[node] == 1 ? 2 : 1);  // color negative
        for (int vertex : graph[node]) {         // 相邻顶点
          if (color[vertex] == 0) {              // 相邻顶点未着色
            q.push(vertex);
            color[vertex] = cnext;
          } else if (color[vertex] != cnext)  // 相邻顶点所着色与该顶点冲突
            return false;
        }
      }
    }
  }
  return true;
}
void isBipartite_dfs_(int node, int c, const vector<vector<int>>& graph,
                      vector<int>& color, bool& ans) {
  color[node] = c;
  int cnext = c == 1 ? 2 : 1;
  for (int neighbor : graph[node]) {
    if (!color[neighbor]) {
      isBipartite_dfs_(neighbor, cnext, graph, color, ans);
      if (!ans) return;  // ans==false
    } else if (color[neighbor] != cnext) {
      ans = false;
      return;
    }
  }
}
bool isBipartite_dfs(vector<vector<int>>& graph) {
  vector<int> color(graph.size(), 0);
  bool ans = true;
  for (int i = 0; i < graph.size() && ans; ++i) {
    if (!color[i]) isBipartite_dfs_(i, 1, graph, color, ans);  // 若未着色
  }
  return ans;
}
bool isBipartite(vector<vector<int>>& graph) {
  // return isBipartite_bfs(graph);
  return isBipartite_dfs(graph);
}
bool canFinish_bfs(const int numCourses,
                   const vector<vector<int>>& prerequisites) {
  vector<vector<int>> edges(numCourses);  // 先行课程，要修的课程
  vector<int> indeg(numCourses);          // 要修的课程的入度
  for (const auto& info : prerequisites) {
    edges[info[1]].push_back(info[0]);
    ++indeg[info[0]];
  }
  queue<int> q;  // 已经修完先行课程的课程index
  for (int i = 0; i < numCourses; ++i) {
    if (!indeg[i]) q.push(i);
  }
  int visited = 0, u;  // 已经修完的课程，
  while (!q.empty()) {
    u = q.front(), q.pop(), ++visited;
    for (int v : edges[u]) {
      --indeg[v];
      if (!indeg[v]) q.push(v);
    }
  }
  return visited == numCourses;
}
void canFinish_dfs_(int u, vector<int>& visited, vector<vector<int>>& edges,
                    bool& ans) {
  visited[u] = 1;  // 遍历过
  for (int v : edges[u]) {
    if (!visited[v]) {
      canFinish_dfs_(v, visited, edges, ans);
      if (!ans) return;
    } else if (visited[v] == 1) {  // 形成了环
      ans = false;
      return;
    }
  }
  visited[u] = 2;  // 能遍历完说明未形成环
}
bool canFinish_dfs(const int numCourses,
                   const vector<vector<int>>& prerequisites) {
  vector<vector<int>> edges(numCourses);  // 先行课程，要修的课程
  vector<int> visited(numCourses);        // 0未遍历、1遍历过、2
  bool ans = true;
  for (const auto& info : prerequisites) {
    edges[info[1]].push_back(info[0]);
  }
  for (int i = 0; i < numCourses && ans; ++i) {
    if (!visited[i]) {
      canFinish_dfs_(i, visited, edges, ans);
    }
  }
  return ans;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  // return canFinish_bfs(numCourses, prerequisites);
  return canFinish_dfs(numCourses, prerequisites);
}
vector<int> findOrder_bfs(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> edges(numCourses);
  vector<int> indeg(numCourses, 0);
  vector<int> ans;
  for (const auto& info : prerequisites) {
    edges[info[1]].emplace_back(info[0]);
    ++indeg[info[0]];
  }
  queue<int> q;
  for (int i = 0; i < numCourses; ++i)
    if (!indeg[i]) q.push(i);
  int u;
  while (!q.empty()) {
    u = q.front(), q.pop(), ans.emplace_back(u);
    for (int v : edges[u]) {
      --indeg[v];
      if (!indeg[v]) q.push(v);
    }
  }
  if (ans.size() == numCourses) return ans;
  return {};
}
void findOrder_dfs_(int u, const vector<vector<int>>& edges,
                    vector<int>& visited, vector<int>& ans, bool& noring) {
  visited[u] = 1;  // 将节点标记为「搜索中」
  for (int v : edges[u]) {  // 搜索其相邻节点，只要发现有环，立刻停止搜索
    if (!visited[v]) {  // 如果「未搜索」那么搜索相邻节点
      findOrder_dfs_(v, edges, visited, ans, noring);
      if (!noring) return;
    } else if (visited[v] == 1) {  // 如果「搜索中」说明找到了环
      noring = false;
      return;
    }
  }
  visited[u] = 2;       // 将节点标记为「已完成」
  ans.emplace_back(u);  // 将节点入栈
}
vector<int> findOrder_dfs(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> edges(numCourses);  // 存储有向图
  vector<int> visited(numCourses,
                      0);  // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
  vector<int> ans;  // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
  bool noring = true;  // 判断有向图中是否有环
  for (const auto& info : prerequisites) edges[info[1]].emplace_back(info[0]);
  // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
  for (int i = 0; i < numCourses && noring; ++i) {
    if (!visited[i]) findOrder_dfs_(i, edges, visited, ans, noring);
  }
  if (!noring) return {};
  reverse(ans.begin(), ans.end());
  return ans;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  // return findOrder_bfs(numCourses, prerequisites);
  return findOrder_dfs(numCourses, prerequisites);
}
int Find(vector<int>& parent, const int index) {
  if (parent[index] != index) parent[index] = Find(parent, parent[index]);
  return parent[index];
}
void Union(vector<int>& parent, int index1, int index2) {
  parent[Find(parent, index1)] = Find(parent, index2);
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  vector<int> parent(edges.size() + 1);  // 节点1~n
  for (int i = 1; i <= edges.size(); ++i) parent[i] = i;
  for (auto& edge : edges) {
    if (Find(parent, edge[0]) != Find(parent, edge[1]))
      Union(parent, edge[0], edge[1]);
    else
      return edge;
  }
  return vector<int>{};
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);

  return 0;
}