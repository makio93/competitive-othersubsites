// 解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
    }
    for (int i=0; i<n; ++i) sort(g[i].begin(), g[i].end());
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int vi=0) -> void {
        visited[vi] = true;
        cout << vi << ' ';
        for (const int& ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
    };
    dfs(dfs);
	return 0;
}
