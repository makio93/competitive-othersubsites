// 解説AC

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return (d[x] = find(d[x]));
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
};

struct edge {
    int from, to, cost;
    edge(int from_, int to_, int cost_) : from(from_), to(to_), cost(cost_) {}
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w-1)), b(h-1, vector<int>(w));
    for (int i=0; i<h; ++i) for (int j=0; j<w-1; ++j) cin >> a[i][j];
    for (int i=0; i<h-1; ++i) for (int j=0; j<w; ++j) cin >> b[i][j];
    int res = 0;
    for (int i=0; i<h; ++i) for (int j=0; j<w-1; ++j) res += a[i][j];
    for (int i=0; i<h-1; ++i) for (int j=0; j<w; ++j) res += b[i][j];
    vector<edge> edges;
    for (int i=0; i<h; ++i) for (int j=0; j<w-1; ++j) edges.emplace_back(i*w+j, i*w+j+1, a[i][j]);
    for (int i=0; i<h-1; ++i) for (int j=0; j<w; ++j) edges.emplace_back(i*w+j, (i+1)*w+j, b[i][j]);
    sort(edges.begin(), edges.end(), [](edge ai, edge bi) -> bool { return ai.cost > bi.cost; });
    UnionFind uf(h*w);
    for (auto& ei : edges) if (!uf.same(ei.from, ei.to)) {
        res -= ei.cost;
        uf.unite(ei.from, ei.to);
    }
    cout << res << endl;
	return 0;
}
