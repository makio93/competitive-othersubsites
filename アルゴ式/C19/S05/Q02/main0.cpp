// 自力AC

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
    vector<int> res;
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int vi) -> bool {
        visited[vi] = true;
        res.push_back(vi);
        if (vi == t) return true;
        for (int ti : g[vi]) if (!visited[ti] && dfs(dfs, ti)) return true;
        res.pop_back();
        return false;
    };
    dfs(dfs, s);
    int rlen = res.size();
    cout << rlen << endl;
    for (int i=0; i<rlen; ++i) cout << res[i] << (i<rlen-1?' ':'\n');
	return 0;
}
