#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, m;
vl A;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  A = vl(n);
  for (auto&& a : A) {
    cin >> a;
  }

  auto S = vl(n + 1, 0);
  for (auto i = 1; i <= n; ++i) {
    S[i] = S[i - 1] + A[i - 1];
  }

  auto ct = vl(m, 0);
  for (auto i = 0; i <= n; ++i) {
    ct[S[i] % m] += 1;
  }

  ll ans = 0;
  for (auto i = 0; i < m; ++i) {
    const auto& v = ct[i];
    if (v <= 1) continue;

    ans += (v * (v - 1)) / 2;
  }
  cout << ans;

  return 0;
}