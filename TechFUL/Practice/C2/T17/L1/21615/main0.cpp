// 自力AC

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    partial_sort(a.begin(), a.begin()+2, a.end(), greater<int>());
    ll bsum = accumulate(b.begin(), b.end(), 0LL), res = a[0] * bsum + (ll)m * a[1];
    for (int i=1; i<n; ++i) res = max(res, a[i]*bsum+(ll)m*a[0]);
    cout << res << endl;
    return 0;
}
