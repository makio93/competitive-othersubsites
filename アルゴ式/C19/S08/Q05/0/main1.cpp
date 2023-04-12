// 解説AC

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1) {}
    void reset(int n=0) {
        if (n == 0) n = d.size();
        d.assign(n, -1);
    }
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
    int from, to, weight;
    edge(int fr_, int to_, int wi_) : from(fr_), to(to_), weight(wi_) {}
    bool operator<(const edge& re) const { return this->weight < re.weight; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        edges.emplace_back(ui, vi, wi);
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    vector<int> ceids;
    int wsum = 0;
    for (int i=0; i<m; ++i) if (!uf.same(edges[i].from, edges[i].to)) {
        ceids.push_back(i);
        wsum += edges[i].weight;
        uf.unite(edges[i].from, edges[i].to);
    }
    int res = 0;
    for (int id : ceids) {
        uf.reset();
        int twsum = 0;
        for (int i=0; i<m; ++i) if (i!=id && !uf.same(edges[i].from,edges[i].to)) {
            uf.unite(edges[i].from, edges[i].to);
            twsum += edges[i].weight;
        }
        if (uf.size(0)<n || twsum>wsum) ++res;
    }
    cout << res << endl;
	return 0;
}
