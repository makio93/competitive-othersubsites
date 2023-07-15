// 学習3回目,自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i=0; i<m; ++i) cin >> u[i] >> v[i] >> w[i];
    vector<int> dists(n, INF);
    dists[0] = 0;
    for (int i=0; i<n*2-1; ++i) {
        bool is_update = false;
        for (int j=0; j<m; ++j) {
            if (dists[u[j]] == INF || dists[v[j]] <= dists[u[j]]+w[j]) continue;
            is_update = true;
            if (i >= n) dists[v[j]] = -INF;
            else dists[v[j]] = dists[u[j]] + w[j];
        }
        if (i == n && !is_update) break;
    }
    if (dists[n-1] == INF) cout << "impossible" << endl;
    else if (dists[n-1] == -INF) cout << "-inf" << endl;
    else cout << dists[n-1] << endl;
	return 0;
}
