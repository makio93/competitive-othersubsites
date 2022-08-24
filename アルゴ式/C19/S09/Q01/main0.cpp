// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<int> col(n);
    auto dfs = [&](auto dfs, int vi=0, int ci=1) -> bool {
        col[vi] = ci;
        for (int ti : g[vi]) if (col[ti]==ci || (col[ti]==0&&!dfs(dfs,ti,-ci))) return false;
        return true;
    };
    if (dfs(dfs)) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
