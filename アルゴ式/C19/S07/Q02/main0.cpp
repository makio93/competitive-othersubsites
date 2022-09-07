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
    vector<int> dist(n, INF);
    dist[0] = 0;
    for (int i=0; i<n-1; ++i) if (dist[i] != INF) for (auto& tpi : g[i]) 
        dist[tpi.first] = min(dist[tpi.first], dist[i]+tpi.second);
    if (dist[n-1] == INF) cout << -1 << endl;
    else cout << dist[n-1] << endl;
	return 0;
}
