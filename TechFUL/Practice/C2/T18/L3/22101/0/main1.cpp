// 解説AC

#include <iostream>
#include <vector>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), s(m), t(m), u(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> s[i] >> t[i] >> u[i];
    vector<vector<vector<bool>>> f(n+1, vector<vector<bool>>(n+1, vector<bool>(51)));
    for (int i=0; i<n; ++i) f[i][i+1][a[i]] = true;
    for (int k=2; k<=n; ++k) for (int l=0; l+k<=n; ++l) {
        int r = l + k;
        for (int c=l+1; c<r; ++c) {
            for (int i=0; i<m; ++i) f[l][r][u[i]] = f[l][r][u[i]] || (f[l][c][s[i]] && f[c][r][t[i]]);
            for (int i=0; i<=50; ++i) f[l][r][i] = f[l][r][i] || ((f[l][c][0]&&f[c][r][i]) || (f[l][c][i]&&f[c][r][0]));
        }
    }
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for (int i=1; i<=n; ++i) for (int j=0; j<i; ++j) for (int k=0; k<=50; ++k) if (f[j][i][k]) dp[i] = min(dp[i], dp[j]+k);
    cout << dp[n] << endl;
    return 0;
}
