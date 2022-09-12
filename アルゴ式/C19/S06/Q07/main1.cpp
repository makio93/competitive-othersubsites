// 解説AC

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
    vector<bool> check(n);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        bool ok = true;
        for (int& ti : g[vi]) if (ti != pi) {
            dfs(dfs, ti, vi);
            if (check[ti]) ok = false;
        }
        if (ok) check[vi] = true;
    };
    dfs(dfs);
    cout << count(check.begin(), check.end(), true) << endl;
	return 0;
}
