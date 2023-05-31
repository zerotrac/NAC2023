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
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    LL n, d;
    cin >> n >> d;
    // (d+1)^x >= n
    int l = 0, r = 80, x = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      LL cur = 1;
      bool check = false;
      for (int i = 0; i < mid; ++i) {
        if (cur > n / (d + 1)) {
          check = true;
          break;
        }
        cur *= (d + 1);
      }
      if (cur >= n) {
        check = true;
      }
      if (check) {
        x = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << x << "\n";
  }
}

int main() {
  work();
  return 0;
}
