// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].insert(bi);
    }
    vector<bool> visited(n);
    vector<int> res;
    auto dfs = [&](auto& dfs, int vi) -> void {
        visited[vi] = true;
        for (const int& ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
        res.push_back(vi);
    };
    for (int i=0; i<n; ++i) if (!visited[i]) dfs(dfs, i);
    reverse(res.begin(), res.end());
    for (int i=0; i<n; ++i) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
