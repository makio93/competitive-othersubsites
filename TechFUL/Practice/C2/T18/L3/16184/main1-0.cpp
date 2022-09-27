// 解説WA

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int t0;
    cin >> t0;
    for (int i0=0; i0<t0; ++i0) {
        ll ai, bi;
        int ci;
        cin >> ai >> bi >> ci;
        if (ai==0 || bi==0) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<vector<vector<ll>>>> dp(62, vector<vector<vector<ll>>>(2, vector<vector<ll>>(ci-1, vector<ll>(2))));
        int res = 1;
        dp[0][0][0][0] = dp[0][0][0][1] = 0;
        dp[0][1][0][1] = 1;
        dp[0][1][0][0] = (ai & 1LL);
        for (int i=1; i<62; ++i) {
            bool ok = ((1LL<<(i+1)) <= ai);
            for (int k=1; k<ci-1; ++k) {
                if ((1LL<<(i+1)) <= ai) {
                    dp[i][0][k][1] = max(dp[i][0][k][1], dp[i-1][0][k-1][1]);
                    dp[i][1][k][1] = max(dp[i][1][k][1], dp[i-1][1][k-1][1]+(1LL<<i));
                }
                dp[i][0][k][0] = max(dp[i][0][k][0], dp[i-1][0][k-1][0]);
                if (dp[i][0][k][0]+bi >= (1LL<<(i+1))-1) ok = true;
                dp[i][1][k][0] = max(dp[i][1][k][0], dp[i-1][1][k-1][0]);
                if (ai&(1LL<<i)) dp[i][1][k][0] = max(dp[i][1][k][0], dp[i-1][1][k-1][0]+(1LL<<i));
                if (dp[i][1][k][0]+bi >= (1LL<<(i+1))-1) ok = true;
            }
            for (int k=0; k<ci-1; ++k) {
                if ((1LL<<(i+1)) <= ai) {
                    dp[i][0][0][1] = max(dp[i][0][0][1], dp[i-1][1][k][1]);
                    dp[i][1][0][1] = max(dp[i][1][0][1], dp[i-1][0][k][1]);
                }
                dp[i][0][0][0] = max(dp[i][0][0][0], dp[i][1][k][0]);
                if (dp[i][0][0][0]+bi >= (1LL<<(i+1))-1) ok = true;
                dp[i][1][0][0] = max(dp[i][1][0][0], dp[i][0][k][0]);
                if (ai&(1LL<<i)) dp[i][1][0][0] = max(dp[i][1][0][0], dp[i][0][k][0]+(1LL<<i));
                if (dp[i][1][0][0]+bi >= (1LL<<(i+1))-1) ok = true;
            }
            if (ok) res = max(res, i+1);
            else break;
        }
        cout << res << endl;
    }
    return 0;
}
