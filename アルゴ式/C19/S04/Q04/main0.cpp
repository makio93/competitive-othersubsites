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
    }
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int vi=0) -> void {
        visited[vi] = true;
        for (int& ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
    };
    dfs(dfs);
    int res = count(visited.begin(), visited.end(), false);
    cout << res << endl;
	return 0;
}
