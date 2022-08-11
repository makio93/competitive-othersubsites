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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto pi = pq.top(); pq.pop();
        int di = pi.first, vi = pi.second;
        if (dist[vi] != di) continue;
        for (auto tpi : g[vi]) if (dist[tpi.first] > di+tpi.second) {
            dist[tpi.first] = di + tpi.second;
            pq.emplace(di+tpi.second, tpi.first);
        }
    }
    for (int i=0; i<n; ++i) cout << dist[i] << endl;
	return 0;
}
