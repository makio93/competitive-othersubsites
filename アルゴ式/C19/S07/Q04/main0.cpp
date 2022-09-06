// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i=0; i<m; ++i) cin >> u[i] >> v[i] >> w[i];
    vector<int> d(n, INF);
    d[0] = 0;
    for (int i=0; i<m; ++i) d[v[i]] = min(d[v[i]], d[u[i]]+w[i]);
    for (int i=0; i<n; ++i) cout << d[i] << endl;
	return 0;
}
