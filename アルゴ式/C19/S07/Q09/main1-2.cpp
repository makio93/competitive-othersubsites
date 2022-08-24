// 解説AC2(ベルマンフォード法)

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
    vector<edge> g(m);
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        g.emplace_back(ui, vi, wi);
    }
    vector<int> dist(n, INF), pre(n, -1);
    dist[0] = 0;
    for (int i=0; i<n; ++i) {
        bool changed = false;
        for (edge ei : g) if (dist[ei.from]!=INF && dist[ei.to]>dist[ei.from]+ei.weight) {
            dist[ei.to] = dist[ei.from] + ei.weight;
            pre[ei.to] = ei.from;
            changed = true;
        }
        if (!changed) break;
    }
    vector<int> path;
    int vi = n-1;
    while (vi != 0) {
        path.push_back(vi);
        vi = pre[vi];
    }
    path.push_back(vi);
    reverse(path.begin(), path.end());
    int len = path.size();
    cout << len << endl;
    for (int i=0; i<len; ++i) cout << path[i] << (i<len-1?' ':'\n');
	return 0;
}
