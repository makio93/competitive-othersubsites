// 自力AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
struct edge {
    int from, to, weight;
    edge(int fr=-1, int to=-1, int wi=0) : from(fr), to(to), weight(wi) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> g(n);
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        g.emplace_back(ui, vi, wi);
    }
    vector<int> dist(n, -INF);
    dist[0] = 0;
    for (int i=0; i<n; ++i) {
        bool changed = false;
        for (edge& ei : g) if (dist[ei.from]!=-INF && dist[ei.to]<dist[ei.from]+ei.weight) {
            dist[ei.to] = dist[ei.from]+ei.weight;
            changed = true;
        }
        if (!changed) break;
    }
    cout << dist[n-1] << endl;
	return 0;
}
