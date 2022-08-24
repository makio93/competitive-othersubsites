// 解説AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    ll res = 0;
    for (int i=0; i<n; ++i) res += a[i];
    res *= res;
    for (int i=0; i<n; ++i) res -= a[i] * a[i];
    res /= 2;
    cout << res << endl;
	return 0;
}
