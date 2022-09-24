// 自力AC

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
        g[bi].push_back(ai);
    }
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int vi=0) -> void {
        visited[vi] = true;
        for (int ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
    };
    dfs(dfs);
    bool res = true;
    for (int i=0; i<n; ++i) if (!visited[i]) {
        res = false;
        break;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
