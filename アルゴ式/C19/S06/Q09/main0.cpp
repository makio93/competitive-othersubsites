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
    vector<bool> covered(n);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        if (pi!=-1 && (int)(g[vi].size())==1) {
            covered[pi] = true;
            return;
        }
        for (int& ti : g[vi]) if (ti != pi) dfs(dfs, ti, vi);
        if (!covered[vi] && pi!=-1) covered[pi] = true;
    };
    dfs(dfs);
    int res = count(covered.begin(), covered.end(), true);
    cout << res << endl;
	return 0;
}
