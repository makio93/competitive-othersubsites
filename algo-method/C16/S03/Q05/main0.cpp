// 自力AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<int> rsum(n+1);
    for (int i=n-1; i>=0; --i) rsum[i] = rsum[i+1] + a[i];
    ll res = 0;
    for (int i=0; i<n; ++i) res += (ll)a[i] * rsum[i+1];
    cout << res << endl;
	return 0;
}
