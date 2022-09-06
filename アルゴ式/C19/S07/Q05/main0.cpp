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
    int res = 0;
    while (1) {
        bool fin = true;
        for (int j=0; j<m; ++j) if (d[v[j]] > d[u[j]]+w[j]) {
            d[v[j]] = d[u[j]] + w[j];
            fin = false;
        }
        ++res;
        if (fin) break;
    }
    cout << res << endl;
	return 0;
}
