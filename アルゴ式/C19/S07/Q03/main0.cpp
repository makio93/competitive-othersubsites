// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        g[ui].emplace_back(vi, wi);
    }
    for (int i=0; i<n; ++i) {
        pair<int, int> mval = { INF, -1 };
        for (auto& tpi : g[i]) mval = min(mval, { tpi.second, tpi.first });
        cout << mval.second << endl;
    }
	return 0;
}
