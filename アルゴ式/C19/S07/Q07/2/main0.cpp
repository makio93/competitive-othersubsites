// 学習2回目,自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i=0; i<m; ++i) cin >> u[i] >> v[i] >> w[i];
    vector<int> dist(n, INF);
    dist[0] = 0;
    for (int i=0; i<2*n-1; ++i) for (int j=0; j<m; ++j) if (dist[u[j]] != INF) {
        if (dist[u[j]] == -INF) {
            dist[v[j]] = -INF;
            continue;
        }
        if (dist[v[j]] <= dist[u[j]]+w[j]) continue;
        if (i >= n) {
            dist[v[j]] = -INF;
            continue;
        }
        dist[v[j]] = dist[u[j]] + w[j];
    }
    if (dist[n-1] == INF) cout << "impossible" << endl;
    else if (dist[n-1] == -INF) cout << "-inf" << endl;
    else cout << dist[n-1] << endl;
	return 0;
}
