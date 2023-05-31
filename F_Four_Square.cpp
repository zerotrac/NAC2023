#include <bits/stdc++.h>

using LL = int64_t;
using ULL = uint64_t;
using PII = std::pair<int, int>;
using PIL = std::pair<int, LL>;
using PLL = std::pair<LL, LL>;
// constexpr int mod = 1e9 + 7;
// constexpr int mod = 998244353;

using namespace std;

vector<pair<int, int>> v;
vector<int> used;

bool dfs(const vector<pair<int, int>> &v, int idx, int tot, int m, int n) {
  if (idx == tot) {
    return m == 0 || n == 0;
  }
  bool check = false;
  for (int i = 0; i < 4; ++i) {
    if (used[i]) {
      continue;
    }
    if (v[i].first == m && v[i].second <= n) {
      used[i] = true;
      check |= dfs(v, idx + 1, tot, m, n - v[i].second);
      used[i] = false;
    }
    if (v[i].first == n && v[i].second <= m) {
      used[i] = true;
      check |= dfs(v, idx + 1, tot, m - v[i].second, n);
      used[i] = false;
    }
    if (v[i].second == m && v[i].first <= n) {
      used[i] = true;
      check |= dfs(v, idx + 1, tot, m, n - v[i].first);
      used[i] = false;
    }
    if (v[i].second == n && v[i].first <= m) {
      used[i] = true;
      check |= dfs(v, idx + 1, tot, m - v[i].first, n);
      used[i] = false;
    }
  }
  return check;
}

vector<pair<int, int>> cons(const vector<pair<int, int>> &v, int i, int j,
                            int m, int n) {
  vector<pair<int, int>> w;
  for (int k = 0; k < 4; ++k) {
    if (k != i && k != j) {
      w.push_back(v[k]);
    }
  }
  w.emplace_back(m, n);
  return w;
}

int main() {
  int area = 0;
  for (int i = 0; i < 4; ++i) {
    int x, y;
    cin >> x >> y;
    v.emplace_back(x, y);
    used.push_back(0);
    area += x * y;
  }

  int side = sqrt(area + 0.5);
  if (side * side != area) {
    cout << "0\n";
  } else {
    bool ans = dfs(v, 0, 4, side, side);
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        if (v[i].first == v[j].first) {
          vector<pair<int, int>> w =
              cons(v, i, j, v[i].first, v[i].second + v[j].second);
          ans |= dfs(w, 0, 3, side, side);
        }
        if (v[i].first == v[j].second) {
          vector<pair<int, int>> w =
              cons(v, i, j, v[i].first, v[i].second + v[j].first);
          ans |= dfs(w, 0, 3, side, side);
        }
        if (v[i].second == v[j].first) {
          vector<pair<int, int>> w =
              cons(v, i, j, v[i].second, v[i].first + v[j].second);
          ans |= dfs(w, 0, 3, side, side);
        }
        if (v[i].second == v[j].second) {
          vector<pair<int, int>> w =
              cons(v, i, j, v[i].second, v[i].first + v[j].first);
          ans |= dfs(w, 0, 3, side, side);
        }
      }
    }
    cout << (ans ? 1 : 0) << "\n";
  }
  return 0;
}
