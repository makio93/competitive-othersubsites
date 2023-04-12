// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int ui, vi, wi;
    edge(int ui_, int vi_, int wi_) : ui(ui_), vi(vi_), wi(wi_) {}
    bool operator<(const edge& other) const { return this->wi < other.wi; }
};

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
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        e.emplace_back(ui, vi, wi); 
    }
    sort(e.begin(), e.end());
    UnionFind uf(n);
    vector<int> eids;
    int wval = 0, res = 0;
    for (int i=0; i<m; ++i) {
        if (uf.same(e[i].ui, e[i].vi)) continue;
        uf.unite(e[i].ui, e[i].vi);
        wval += e[i].wi;
        eids.push_back(i);
    }
    for (const int& tei : eids) {
        UnionFind tuf(n);
        int tval = 0;
        for (int i=0; i<m; ++i) if (i != tei) {
            if (tuf.same(e[i].ui, e[i].vi)) continue;
            tuf.unite(e[i].ui, e[i].vi);
            tval += e[i].wi;
        }
        if (!tuf.same(e[tei].ui, e[tei].vi) || tval>wval) ++res;
    }
    cout << res << endl;
	return 0;
}
