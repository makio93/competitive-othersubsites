// 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    ll res = 0;
    for (int i=1; i<=n; ++i) {
        if (i > m) break;
        for (int j=1; j<=n; ++j) {
            if (i+j > m) break;
            res += min(n, m-(i+j));
        }
    }
    cout << res << endl;
	return 0;
}
