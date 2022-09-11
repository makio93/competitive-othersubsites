// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int res = 0;
    for (int i=0; i<n; ++i) if (x&(1<<i)) res += a[i];
    cout << res << endl;
	return 0;
}
