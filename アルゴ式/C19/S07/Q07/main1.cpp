// 解説AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

struct edge {
    int from, to, weight;
    edge(int fr_, int to_, int wi_) : from(fr_), to(to_), weight(wi_) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> g;
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        g.emplace_back(ui, vi, wi);
    }
    vector<int> dist(n, INF);
    dist[0] = 0;
    for (int i=0; i<n*2; ++i) {
        bool changed = false;
        for (int j=0; j<m; ++j) if (dist[g[j].from]!=INF && dist[g[j].to]>dist[g[j].from]+g[j].weight) {
            if (dist[g[j].from] == -INF) dist[g[j].to] = -INF;
            else {
                if (i == n) dist[g[j].to] = -INF;
                else dist[g[j].to] = dist[g[j].from] + g[j].weight;
            }
            changed = true;
        }
        if (!changed) break;
    }
    if (dist[n-1] == INF) cout << "impossible" << endl;
    else if (dist[n-1] == -INF) cout << "-inf" << endl;
    else cout << dist[n-1] << endl;
    return 0;
}
