// 学習1回目,解説AC-0

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
    for (int i=0; i<2*n-1; ++i) {
        for (int j=0; j<m; ++j) if (dist[u[j]] != INF) {
            if (dist[u[j]] == -INF) {
                if (dist[v[j]] != -INF) dist[v[j]] = -INF;
            }
            else if (dist[v[j]] > dist[u[j]]+w[j]) {
                if (i < n-1) dist[v[j]] = dist[u[j]] + w[j];
                else dist[v[j]] = -INF;
            }
        }
    }
    if (dist[n-1] == -INF) cout << "-inf" << endl;
    else if (dist[n-1] == INF) cout << "impossible" << endl;
    else cout << dist[n-1] << endl;
	return 0;
}
