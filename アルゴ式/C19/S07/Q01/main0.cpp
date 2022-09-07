// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-2), dist(n, INF);
    for (int i=0; i<n-1; ++i) cin >> a[i];
    for (int i=0; i<n-2; ++i) cin >> b[i];
    dist[0] = 0;
    for (int i=1; i<n; ++i) {
        dist[i] = min(dist[i], dist[i-1]+a[i-1]);
        if (i-2 >= 0) dist[i] = min(dist[i], dist[i-2]+b[i-2]);
    }
    cout << dist[n-1] << endl;
	return 0;
}
