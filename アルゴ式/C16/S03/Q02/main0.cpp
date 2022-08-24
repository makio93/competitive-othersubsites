// 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    ll sum = 0, res = 0;
    for (int i=0; i<n; ++i) sum += a[i];
    for (int i=0; i<n; ++i) res = max(res, sum-a[i]);
    cout << res << endl;
	return 0;
}
