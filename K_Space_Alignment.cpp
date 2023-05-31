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
  int n;
  cin >> n;
  vector<int> op(n), scnt(n), tcnt(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char ch : s) {
      if (ch == 's') {
        ++scnt[i];
      } else if (ch == 't') {
        ++tcnt[i];
      } else {
        op[i] = (ch == '{' ? 0 : 1);
      }
    }
  }

  int ans = -1;
  for (int indent = 1; indent <= 1000; ++indent) {
    int trep = 0, cur = 0;
    bool check = true, tfound = false;
    for (int i = 0; i < n; ++i) {
      if (op[i] == 1) {
        cur -= indent;
      }
      if (tfound) {
        if (scnt[i] + tcnt[i] * trep != cur) {
          check = false;
          break;
        }
      } else {
        if (!tcnt[i]) {
          if (scnt[i] != cur) {
            check = false;
            break;
          }
        } else {
          if (cur - scnt[i] <= 0 || (cur - scnt[i]) % tcnt[i] != 0) {
            check = false;
            break;
          }
          trep = (cur - scnt[i]) / tcnt[i];
          tfound = true;
        }
      }
      if (op[i] == 0) {
        cur += indent;
      }
    }
    if (check) {
      ans = (tfound ? trep : 1);
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  work();
  return 0;
}
