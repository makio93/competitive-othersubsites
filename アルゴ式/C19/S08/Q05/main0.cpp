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
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    map<int, vector<pair<int, int>>> elst;
    for (int i=0; i<m; ++i) {
        int wi;
        cin >> u[i] >> v[i] >> wi;
        elst[wi].emplace_back(u[i], v[i]);
    }
    vector<unordered_set<int>> g(n);
    UnionFind uf(n);
    int res = 0;
    vector<pair<int, int>> tlst;
    for (const auto& vpi : elst) {
        for (auto& pi : vpi.second) if (!uf.same(pi.first, pi.second)) tlst.emplace_back(pi.first, pi.second);
        for (auto& pi : tlst) {
            uf.unite(pi.first, pi.second);
            g[pi.first].insert(pi.second);
            g[pi.second].insert(pi.first);
        }
        vector<bool> visited;
        auto is_connected = [&](auto is_connected, int vi, int tar, vector<bool>& visited) -> bool {
            if (vi == tar) return true;
            visited[vi] = true;
            for (const int& ti : g[vi]) if (!visited[ti]) {
                if (is_connected(is_connected, ti, tar, visited)) return true;
            }
            return false;
        };
        for (auto& pi : tlst) {
            g[pi.first].erase(pi.second);
            g[pi.second].erase(pi.first);
            visited.assign(n, false);
            if (!is_connected(is_connected, pi.first, pi.second, visited)) ++res;
            g[pi.first].insert(pi.second);
            g[pi.second].insert(pi.first);
        }
        tlst.clear();
    }
    cout << res << endl;
	return 0;
}
