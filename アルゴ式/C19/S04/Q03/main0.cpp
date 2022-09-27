// 自力AC

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
    auto dfs = [&](auto dfs, int vi=0) -> void {
        visited[vi] = true;
        res.push_back(vi);
        for (const int& ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
    };
    dfs(dfs);
    int len = res.size();
    for (int i=0; i<len; ++i) cout << res[i] << (i<len-1?' ':'\n');
	return 0;
}
