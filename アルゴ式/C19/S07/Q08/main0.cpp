// 自力AC1

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
    vector<int> dist(n, -INF);
    priority_queue<pair<int, int>> pq;
    dist[0] = 0;
    if (n-1 != 0) pq.emplace(0, 0);
    while (!pq.empty()) {
        auto pi = pq.top(); pq.pop();
        int di = pi.first, vi = pi.second;
        if (dist[vi] != di) continue;
        for (auto pi : g[vi]) {
            int ndi = di + pi.second, ti = pi.first;
            if (dist[ti] >= ndi) continue;
            dist[ti] = ndi;
            if (ti != n-1) pq.emplace(ndi, ti);
        }
    }
    cout << dist[n-1] << endl;
	return 0;
}
