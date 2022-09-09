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
    vector<bool> choosed(n);
    int res = 0;
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        if (pi!=-1 && (int)(g[vi].size())==1) {
            if (!choosed[pi]) {
                choosed[vi] = choosed[pi] = true;
                ++res;
            }
            return;
        }
        for (int ti : g[vi]) if (ti != pi) dfs(dfs, ti, vi);
        if (pi!=-1 && !choosed[vi] && !choosed[pi]) {
            choosed[vi] = choosed[pi] = true;
            ++res;
        }
    };
    dfs(dfs);
    cout << res << endl;
	return 0;
}
