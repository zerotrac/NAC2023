#include <bits/stdc++.h>

using LL = int64_t;
using ULL = uint64_t;
using PII = std::pair<int, int>;
using PIL = std::pair<int, LL>;
using PLL = std::pair<LL, LL>;
// constexpr int mod = 1e9 + 7;
// constexpr int mod = 998244353;

using namespace std;

int u[4010], v[4010], w[4010];
int n, m;

inline int bfs(const vector<vector<pair<int, int>>>& g, int st, int ed) {
  vector<int> worst(n, -1);
  queue<int> q;
  worst[st] = m;
  q.push(st);

  while (!q.empty()) {
    int uu = q.front();
    q.pop();
    for (auto&& [vv, ww] : g[uu]) {
      if (worst[vv] != -1) {
        continue;
      }
      q.push(vv);
      worst[vv] = ww;
      if (w[worst[uu]] > w[worst[vv]]) {
        worst[vv] = worst[uu];
      }
    }
  }

  return worst[ed];
}

inline void rmv(vector<vector<pair<int, int>>>& g, int idx) {
  int check = 0;
  int uu = u[idx], vv = v[idx];
  for (int i = 0; i < g[uu].size(); ++i) {
    if (g[uu][i].first == vv) {
      g[uu].erase(g[uu].begin() + i);
      check |= 1;
      break;
    }
  }
  for (int i = 0; i < g[vv].size(); ++i) {
    if (g[vv][i].first == uu) {
      g[vv].erase(g[vv].begin() + i);
      check |= 2;
      break;
    }
  }
}

inline void work() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i];
    --v[i];
  }

  vector<int> used(m);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    used[i] = true;
    g[u[i]].emplace_back(v[i], i);
    g[v[i]].emplace_back(u[i], i);
  }

  // cout << "good" << endl;

  vector<int> id(m);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return w[i] < w[j]; });

  vector<pair<int, int>> ans;
  for (int i = 0; i < m; ++i) {
    int idx = id[i];
    if (used[idx]) {
      continue;
    }
    int worst = bfs(g, u[idx], v[idx]);
    if (w[idx] < w[worst]) {
      ans.emplace_back(worst + 1, idx + 1);
      rmv(g, worst);
      used[worst] = false;
      g[u[idx]].emplace_back(v[idx], idx);
      g[v[idx]].emplace_back(u[idx], idx);
      used[idx] = true;
    }
  }

  cout << ans.size() << "\n";
  for (auto&& [p, q] : ans) {
    cout << p << " " << q << "\n";
  }
}

int main() {
  work();
  return 0;
}
