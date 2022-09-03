// 自力AC

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
    vector<int> d(n, INF);
    d[0] = 0;
    bool res = false;
    for (int i=0; i<n; ++i) {
        bool changed = false;
        for (int j=0; j<m; ++j) if (d[g[j].from]!=INF && d[g[j].to]>d[g[j].from]+g[j].weight) {
            changed = true;
            d[g[j].to] = d[g[j].from] + g[j].weight;
            if (i == n-1) res = true;
        }
        if (!changed) break;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
