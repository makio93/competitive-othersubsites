// 解説AC

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to, weight;
    edge(int fr_, int to_, int we_) : from(fr_), to(to_), weight(we_) {}
};

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i=0; i<m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        g[ui].emplace_back(ui, vi, wi);
    }
    for (int i=0; i<n; ++i) {
        pair<int, int> mval = { INF, -1 };
        for (auto& ei : g[i]) mval = min(mval, { ei.weight, ei.to });
        cout << mval.second << endl;
    }
	return 0;
}
