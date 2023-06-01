// 学習1回目,自力WA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)(2e9);

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<pair<int, int>> dp(n, { INF, INF });
    for (int i=0; i<k*2+1; ++i) for (int j=0; j<n; ++j) {
        int val = i % 2 == 0 ? a[i] : -a[i];
        auto itr = lower_bound(dp.begin(), dp.end(), make_pair(val, i), [](auto lv, auto rv) -> bool { return lv.first <= rv.first; });
        if (itr->second >= i) *itr = make_pair(val, i);
    }
    int res = 0;
    for (int i=0; i<n; ++i) if (dp[i] != make_pair(INF, INF)) res = i + 1;
    cout << res << endl;
    return 0;
}
