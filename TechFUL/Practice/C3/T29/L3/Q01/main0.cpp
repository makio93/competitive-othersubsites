// 自力AC

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    int blen = 1;
    ll btmp = 1;
    while (btmp < n) {
        ++blen;
        btmp <<= 1;
    }
    vector<vector<vector<ll>>> dp(blen+2, vector<vector<ll>>(2, vector<ll>(2)));
    dp[blen+1][1][1] = 1;
    for (int i=blen; i>=0; --i) {
        if ((n>>i)&1) {
            if ((k>>i)&1) {
                dp[i][1][0] += dp[i+1][1][1] + dp[i+1][1][0];
                dp[i][0][1] += dp[i+1][1][1] + dp[i+1][0][1];
                dp[i][0][0] += dp[i+1][1][0] + dp[i+1][0][1] + dp[i+1][0][0] * 2;
            }
            else {
                dp[i][1][0] += dp[i+1][1][0];
                dp[i][0][1] += dp[i+1][0][1];
                dp[i][0][0] += dp[i+1][0][0] * 2;
            }
        }
        else {
            if ((k>>i)&1) {
                dp[i][1][1] += dp[i+1][1][1];
                dp[i][1][0] += dp[i+1][1][0];
                dp[i][0][1] += dp[i+1][0][1];
                dp[i][0][0] += dp[i+1][1][1] + dp[i+1][1][0] + dp[i+1][0][1] + dp[i+1][0][0] * 2;
            }
            else {
                dp[i][1][1] += dp[i+1][1][1];
                dp[i][1][0] += dp[i+1][1][0];
                dp[i][0][1] += dp[i+1][0][1];
                dp[i][0][0] += dp[i+1][0][0] * 2;
            }
        }
    }
    ll res = 0;
    for (int i1=0; i1<2; ++i1) for (int i2=0; i2<2; ++i2) res += dp[0][i1][i2];
    cout << res << endl;
    return 0;
}
