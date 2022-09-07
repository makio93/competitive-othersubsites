// 解説AC

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, weight;
    edge(int fr_, int we_) : from(fr_), weight(we_) {}
};

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        g[vi].emplace_back(ui, wi);
    }
    vector<int> dist(n, INF);
    dist[0] = 0;
    for (int i=1; i<n; ++i) for (auto& fei : g[i]) if (dist[fei.from] != INF)
        dist[i] = min(dist[i], dist[fei.from]+fei.weight);
    if (dist[n-1] == INF) cout << -1 << endl;
    else cout << dist[n-1] << endl;
	return 0;
}
