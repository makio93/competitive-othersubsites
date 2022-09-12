// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n), v(n);
    for (int i=0; i<n; ++i) cin >> w[i];
    for (int i=0; i<n; ++i) cin >> v[i];
    int res = 0;
    for (int i=0; i<1<<n; ++i) {
        int vsum = 0, wsum = 0;
        for (int j=0; j<n; ++j) if (i&(1<<j)) {
            vsum += v[j];
            wsum += w[j];
        }
        if (wsum <= m) res = max(res, vsum);
    }
    cout << res << endl;
	return 0;
}
