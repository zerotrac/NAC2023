#include <bits/stdc++.h>

using LL = int64_t;
using ULL = uint64_t;
using PII = std::pair<int, int>;
using PIL = std::pair<int, LL>;
using PLL = std::pair<LL, LL>;
// constexpr int mod = 1e9 + 7;
// constexpr int mod = 998244353;

using namespace std;

inline void work() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v, w;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
    w.push_back(0);
  }

  int cur = 0;
  deque<pair<int, int>> rest;
  for (int i = 0; i < n + m - 1; ++i) {
    if (i - m >= 0) {
      cur -= w[i - m];
    }
    if (i < n) {
      rest.emplace_back(i, v[i]);
    }
    while (!rest.empty() && i - rest.front().first >= m) {
      rest.pop_front();
    }
    while (!rest.empty() && cur < k) {
      int diff = k - cur;
      if (rest.back().second <= diff) {
        cur += rest.back().second;
        w[rest.back().first] += rest.back().second;
        rest.pop_back();
      } else {
        rest.back().second -= diff;
        w[rest.back().first] += diff;
        cur = k;
      }
    }
  }
  LL ans = 0;
  for (int o : w) {
    ans += o;
  }
  cout << ans << '\n';
}

int main() {
  work();
  return 0;
}
