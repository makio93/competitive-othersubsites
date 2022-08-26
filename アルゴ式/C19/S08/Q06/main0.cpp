// 自力AC

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

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w-1)), b(h-1, vector<int>(w));
    for (int i=0; i<h; ++i) for (int j=0; j<w-1; ++j) cin >> a[i][j];
    for (int i=0; i<h-1; ++i) for (int j=0; j<w; ++j) cin >> b[i][j];
    vector<tuple<int, int, int>> elst;
    for (int i=0; i<h-1; ++i) for (int j=0; j<w-2; ++j) elst.emplace_back(b[i][j+1], i*(w-1)+j, i*(w-1)+j+1);
    for (int i=0; i<w-1; ++i) for (int j=0; j<h-2; ++j) elst.emplace_back(a[j+1][i], j*(w-1)+i, (j+1)*(w-1)+i);
    for (int i=0; i<h-1; ++i) {
        elst.emplace_back(b[i][0], i*(w-1), (h-1)*(w-1));
        elst.emplace_back(b[i][w-1], i*(w-1)+w-2, (h-1)*(w-1));
    }
    for (int i=0; i<w-1; ++i) {
        elst.emplace_back(a[0][i], i, (h-1)*(w-1));
        elst.emplace_back(a[h-1][i], (h-2)*(w-1)+i, (h-1)*(w-1));
    }
    sort(elst.begin(), elst.end());
    UnionFind uf((h-1)*(w-1)+1);
    int res = 0, elen = elst.size();
    for (int i=0; i<elen; ++i) if (!uf.same(get<1>(elst[i]), get<2>(elst[i]))) {
        res += get<0>(elst[i]);
        uf.unite(get<1>(elst[i]), get<2>(elst[i]));
    }
    cout << res << endl;
	return 0;
}
