// 解説AC2

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
    vector<int> par(n, -1), deg(n);
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        for (int ti : g[vi]) if (ti != par[vi]) {
            deg[vi]++;
            par[ti] = vi;
            que.push(ti);
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(2));
    queue<int> leaf;
    for (int i=0; i<n; ++i) if (deg[i] == 0) leaf.push(i);
    while (!leaf.empty()) {
        int vi = leaf.front(); leaf.pop();
        dp[vi][0] = dp[vi][1] = 1;
        for (int ti : g[vi]) if (ti != par[vi]) {
            dp[vi][0] = dp[vi][0] * (dp[ti][0] + dp[ti][1]) % mod;
            dp[vi][1] = dp[vi][1] * dp[ti][0] % mod;
        }
        if (par[vi] >= 0) {
            deg[par[vi]]--;
            if (deg[par[vi]] == 0) leaf.push(par[vi]);
        }
    }
    ll res = (dp[0][0] + dp[0][1]) % mod;
    cout << res << endl;
	return 0;
}
