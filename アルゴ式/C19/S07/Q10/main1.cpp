// 解説AC

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
    vector<int> dist(n, INF);
    vector<bool> fin(n);
    dist[0] = 0;
    bool finish = false;
    while (!finish) {
        finish = true;
        pair<int, int> mval = { INF, -1 };
        for (int i=0; i<n; ++i) if (!fin[i] && dist[i]!=INF) mval = min(mval, { dist[i], i });
        if (mval.second != -1) {
            finish = false;
            int di = mval.first, vi = mval.second;
            fin[vi] = true;
            for (auto tpi : g[vi]) if (dist[tpi.first] > di+tpi.second) dist[tpi.first] = di+tpi.second; 
        }
    }
    for (int i=0; i<n; ++i) cout << dist[i] << endl;
	return 0;
}
