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
    int res = 0;
    auto dfs = [&](auto dfs, int vi) -> void {
        visited[vi] = true;
        for (int ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
    };
    for (int i=0; i<n; ++i) if (!visited[i]) {
        dfs(dfs, i);
        ++res;
    }
    cout << res << endl;
	return 0;
}
