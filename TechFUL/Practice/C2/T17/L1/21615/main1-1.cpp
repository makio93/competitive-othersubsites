// 解説AC1

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    ll bsum = accumulate(b.begin(), b.end(), 0LL);
    vector<vector<ll>> dp(2, vector(2, -LINF)), ndp;
    for (int i=0; i<n; ++i) {
        ndp = dp;
        ndp[1][0] = max(ndp[1][0], bsum*a[i]);
        ndp[1][1] = max(ndp[1][1], dp[0][1]+bsum*a[i]);
        ndp[0][1] = max(ndp[0][1], (ll)m*a[i]);
        ndp[1][1] = max(ndp[1][1], dp[1][0]+(ll)m*a[i]);
        swap(ndp, dp);
    }
    cout << dp[1][1] << endl;
    return 0;
}
