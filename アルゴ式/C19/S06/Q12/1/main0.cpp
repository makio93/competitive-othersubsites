// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353LL;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<vector<ll>> dp(n, vector<ll>(2, 1));
    auto dfs = [&](auto& dfs, int vi=0, int pi=-1) -> void {
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs(dfs, ti, vi);
            dp[vi][1] = dp[vi][1] * dp[ti][0] % mod;
            dp[vi][0] = dp[vi][0] * (dp[ti][0] + dp[ti][1]) % mod;
        }
    };
    dfs(dfs);
    ll res = (dp[0][0] + dp[0][1]) % mod;
    cout << res << endl;
	return 0;
}
