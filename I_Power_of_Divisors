#include <bits/stdc++.h>

using LL = int64_t;
using ULL = uint64_t;
using PII = std::pair<int, int>;
using PIL = std::pair<int, LL>;
using PLL = std::pair<LL, LL>;
// constexpr int mod = 1e9 + 7;
// constexpr int mod = 998244353;

using namespace std;

int main() {
  LL x;
  cin >> x;
  if (x == 1) {
    cout << "1\n";
  } else {
    int ans = -1;
    for (LL i = 2; i * i * i <= x; ++i) {
      LL cur = 1;
      bool check = true;
      for (LL j = 1; j * j <= i; ++j) {
        if (i % j == 0) {
          if (cur > x / i) {
            check = false;
            break;
          }
          cur *= i;
          if (j * j != i) {
            if (cur > x / i) {
              check = false;
              break;
            }
            cur *= i;
          }
        }
      }
      if (check && cur == x) {
        ans = i;
        break;
      }
    }
    if (ans == -1) {
      LL root = sqrt(x + 0.5);
      if (root * root == x) {
        bool prime = true;
        for (LL i = 2; i * i <= root; ++i) {
          if (root % i == 0) {
            prime = false;
            break;
          }
        }
        if (prime) {
          ans = root;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
