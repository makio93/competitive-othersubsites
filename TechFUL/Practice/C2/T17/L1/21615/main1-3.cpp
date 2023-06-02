// 解説AC3

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    ll bsum = accumulate(b.begin(), b.end(), 0LL);
    cout << max({ a[0]*bsum+(ll)m*a[n-1], a[n-2]*bsum+(ll)m*a[n-1], a[n-1]*bsum+(ll)m*a[n-2] }) << endl;
    return 0;
}
