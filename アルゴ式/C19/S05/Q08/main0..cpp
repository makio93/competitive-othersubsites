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
    vector<bool> visited(n), finished(n);
    auto dfs = [&](auto dfs, int vi) -> bool {
        if (visited[vi]) return true;
        visited[vi] = true;
        for (int& ti : g[vi]) if (!finished[ti]) {
            if (dfs(dfs, ti)) return true;
        }
        finished[vi] = true;
        return false;
    };
    bool res = false;
    for (int i=0; i<n; ++i) if (!finished[i]) {
        if (dfs(dfs, i)) {
            res = true;
            break;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
