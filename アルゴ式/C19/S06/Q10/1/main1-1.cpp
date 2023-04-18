// 学習1回目,解説AC1

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
    vector<bool> checked(n);
    int res = 0;
    auto dfs = [&](auto& dfs, int vi=0, int pi=0) -> void {
        for (const auto ti : g[vi]) if (ti != pi) dfs(dfs, ti, vi);
        if (!checked[vi]) {
            checked[vi] = checked[pi] = true;
            ++res;
        }
    };
    dfs(dfs);
    cout << res << endl;
	return 0;
}
