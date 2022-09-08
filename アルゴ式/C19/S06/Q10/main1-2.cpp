// 解説AC2

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
    vector<int> deg(n), par(n, -1);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        for (int& ti : g[vi]) if (ti != pi) {
            par[ti] = vi;
            deg[vi]++;
            dfs(dfs, ti, vi);
        }
    };
    dfs(dfs);
    queue<int> que;
    for (int i=0; i<n; ++i) if (deg[i] == 0) que.push(i);
    vector<bool> choosed(n);
    int res = 0;
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        if (!choosed[vi]) {
            choosed[vi] = true;
            if (par[vi] != -1) choosed[par[vi]] = true;
            ++res;
        }
        if (par[vi] != -1) {
            deg[par[vi]]--;
            if (deg[par[vi]] == 0) que.push(par[vi]);
        }
    }
    cout << res << endl;
	return 0;
}
