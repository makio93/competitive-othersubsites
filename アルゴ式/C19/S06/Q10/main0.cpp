// 自力WA

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (ll)(1e9);

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
    vector<vector<ll>> dp(n, vector<ll>(2, INF));
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        dp[vi][1] = 0;
        if (vi!=0 && (int)(g[vi].size())==1) return;
        vector<pair<ll, ll>> svals;
        bool ok = true;
        for (int& ti : g[vi]) if (ti != pi) {
            dfs(dfs, ti, vi);
            dp[vi][1] = min(INF, dp[vi][1]+min(dp[ti][0],dp[ti][1]+1));
            svals.emplace_back(dp[ti][0], dp[ti][1]+1);
            if (dp[ti][0]==INF && dp[ti][1]==INF) ok = false;
        }
        if (ok) {
            sort(svals.begin(), svals.end(), [&](auto li, auto ri) -> bool {
                return li.second - li.first < ri.second - ri.first;
            });
            for (int i=0; i<(int)(svals.size()); ++i) {
                if (i == 0) dp[vi][0] = svals[i].second;
                else dp[vi][0] += min(svals[i].first, svals[i].second);
            }
        }
    };
    dfs(dfs);
    cout << dp[0][0] << endl;
	return 0;
}
