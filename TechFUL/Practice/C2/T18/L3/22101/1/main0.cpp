// 学習1回目,自力AC

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<int> s(m), t(m), u(m);
    for (int i=0; i<m; ++i) cin >> s[i] >> t[i] >> u[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for (int i=0; i<=n; ++i) dp[i][i] = 1LL<<51;
    for (int i=0; i<n; ++i) {
        dp[i][i+1] = 1LL<<a[i];
        if (a[i] == 0) dp[i][i+1] |= 1LL<<51;
    }
    for (int i=2; i<=n; ++i) for (int j=0; j+i<=n; ++j) {
        for (int k=1; k<i; ++k) {
            for (int l=0; l<m; ++l) if ((dp[j][j+k]>>s[l])&(dp[j+k][j+i]>>t[l])&1LL) dp[j][j+i] |= 1LL<<u[l];
            if ((dp[j][j+k]>>51)&1LL) dp[j][j+i] |= dp[j+k][j+i];
            if ((dp[j+k][j+i]>>51)&1LL) dp[j][j+i] |= dp[j][j+k];
        }
        if (dp[j][j+i]&1LL) dp[j][j+i] |= 1LL<<51;
    }
    vector<int> sdp(n+1, INF);
    sdp[0] = 0;
    for (int i=1; i<=n; ++i) for (int j=i-1; j>=0; --j) for (int k=0; k<=51; ++k) if ((dp[j][i]>>k)&1LL) {
        int val = k == 51 ? 0 : k;
        sdp[i] = min(sdp[i], sdp[j]+val);
    }
    cout << sdp[n] << endl;
    return 0;
}
