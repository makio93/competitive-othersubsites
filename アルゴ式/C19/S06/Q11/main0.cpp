// 自力AC

#include <bits/stdc++.h>
using namespace std;

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
    vector<int> w(n);
    for (int i=0; i<n; ++i) cin >> w[i];
    vector<vector<int>> dp(n, vector<int>(2));
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        dp[vi][1] = w[vi];
        for (int ti : g[vi]) if (ti != pi) {
            dfs(dfs, ti, vi);
            dp[vi][0] += max(dp[ti][0], dp[ti][1]);
            dp[vi][1] += dp[ti][0];
        }
    };
    dfs(dfs);
    cout << max(dp[0][0], dp[0][1]) << endl;
	return 0;
}
