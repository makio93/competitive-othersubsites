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
    vector<int> visited(n);
    auto dfs = [&](auto dfs, int vi=0, int ci=1) -> bool {
        visited[vi] = ci;
        int nci = -ci;
        for (int ti : g[vi]) if (visited[ti] != nci) {
            if (visited[ti]==ci || !dfs(dfs,ti,nci)) return false;
        }
        return true;
    };
    bool res = true;
    for (int i=0; i<n; ++i) if (visited[i] == 0) {
        if (!dfs(dfs, i, 1)) {
            res = false;
            break;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
