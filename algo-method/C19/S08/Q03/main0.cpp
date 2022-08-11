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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> u(m), v(m), w(m), ord(m);
    for (int i=0; i<m; ++i) cin >> u[i] >> v[i] >> w[i];
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int li, int ri) -> bool {
        return w[li] < w[ri];
    });
    UnionFind uf(n);
    int res = 0, cnt = 0;
    for (int i=0; i<m; ++i) if (!uf.same(u[ord[i]], v[ord[i]])) {
        res += w[ord[i]];
        uf.unite(u[ord[i]], v[ord[i]]);
        ++cnt;
        if (cnt >= k) break;
    }
    if (cnt < k) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
