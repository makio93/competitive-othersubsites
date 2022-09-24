// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> g(n);
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
    }
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int vi) -> bool {
        visited[vi] = true;
        if (vi == t) return true;
        for (int ti : g[vi]) if (!visited[ti]) {
            if (dfs(dfs, ti)) return true;
        }
        return false;
    };
    if (dfs(dfs, s)) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
