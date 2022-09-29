// 解説WA

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll LINF = (ll)(1e18);

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
        vector<vector<vector<vector<ll>>>> dp(62, vector<vector<vector<ll>>>(2, vector<vector<ll>>(ci-1, vector<ll>(2, -LINF))));
        int bt = 63 - __builtin_clzll(ai), res = 1;
        dp[0][0][0][0] = dp[0][0][0][1] = 0;
        dp[0][1][0][1] = 1;
        dp[0][1][0][0] = (ai%2==1) ? 1 : -LINF;
        bool fin = false;
        for (int i=1; i<62; ++i) {
            fin = true;
            for (int j=0; j<ci-1; ++j) {
                if (ai&(1LL<<i)) {
                    if (j-1>=0 && dp[i-1][0][j-1][1]!=-LINF && dp[i-1][0][j-1][1]+bi>=(1LL<<(i+1))-1) {
                        dp[i][0][j][0] = max(dp[i][0][j][0], dp[i-1][0][j-1][1]);
                        fin = false;
                    }
                    if (dp[i-1][1][j][1]!=-LINF && dp[i-1][1][j][1]+bi>=(1LL<<(i+1))-1) {
                        dp[i][0][0][0] = max(dp[i][0][0][0], dp[i-1][1][j][1]);
                        fin = false;
                    }
                    if (j-1>=0 && dp[i-1][1][j-1][0]!=-LINF && dp[i-1][1][j-1][0]+(1LL<<i)+bi>=(1LL<<(i+1))-1) {
                        dp[i][1][j][0] = max(dp[i][1][j][0], dp[i-1][1][j-1][0]+(1LL<<i));
                        fin = false;
                    }
                    if (dp[i-1][0][j][0]!=-LINF && dp[i-1][0][j][0]+(1LL<<i)+bi>=(1LL<<(i+1))-1) {
                        dp[i][1][0][0] = max(dp[i][1][0][0], dp[i-1][0][j][0]+(1LL<<i));
                        fin = false;
                    }
                }
                else {
                    if (j-1>=0 && dp[i-1][0][j-1][0]!=-LINF && dp[i-1][0][j-1][0]+bi>=(1LL<<(i+1))-1) {
                        dp[i][0][j][0] = max(dp[i][0][j][0], dp[i-1][0][j-1][0]);
                        fin = false;
                    }
                    if (dp[i-1][1][j][0]!=-LINF && dp[i-1][1][j][0]+bi>=(1LL<<(i+1))-1) {
                        dp[i][0][0][0] = max(dp[i][0][0][0], dp[i-1][1][j][0]);
                        fin = false;
                    }
                }
                if (i < bt) {
                    for (int i2=0; i2<2; ++i2) if (j-1>=0 && dp[i-1][i2][j-1][1]!=-LINF && dp[i-1][i2][j-1][1]+bi>=(1LL<<(i+1))-1) {
                        dp[i][i2][j][1] = max(dp[i][i2][j][1], dp[i-1][i2][j-1][1]);
                        fin = false;
                    }
                    if (dp[i-1][1][j][1]!=-LINF && dp[i-1][1][j][1]+bi>=(1LL<<(i+1))-1) {
                        dp[i][0][0][1] = max(dp[i][0][0][1], dp[i-1][1][j][1]);
                        fin = false;
                    }
                    if (ai&(1LL<<i)) {
                        if (j-1>=0 && dp[i-1][1][j-1][1]!=-LINF && dp[i-1][1][j-1][1]+(1LL<<i)<=ai && dp[i-1][1][j-1][1]+(1LL<<i)+bi>=(1LL<<(i+1))-1) {
                            dp[i][1][j][1] = max(dp[i][1][j][1], dp[i-1][1][j-1][1]+(1LL<<i));
                            fin = false;
                        }
                        if (dp[i-1][0][j][1]!=-LINF && dp[i-1][0][j][1]+(1LL<<i)<=ai && dp[i-1][0][j][1]+(1LL<<i)+bi>=(1LL<<(i+1))-1) {
                            dp[i][1][0][1] = max(dp[i][1][0][1], dp[i-1][0][j][1]+(1LL<<i));
                            fin = false;
                        }
                    }
                    else {
                        if (j-1>=0 && dp[i-1][1][j-1][1]!=-LINF && dp[i-1][1][j-1][1]+(1LL<<i)<=ai && dp[i-1][1][j-1][1]+(1LL<<i)+bi>=(1LL<<(i+1))-1) {
                            dp[i][1][j][1] = max(dp[i][1][j][1], dp[i-1][1][j-1][1]+(1LL<<i));
                            fin = false;
                        }
                        if (dp[i-1][0][j][1]!=-LINF && dp[i-1][0][j][1]+(1LL<<i)<=ai && dp[i-1][0][j][1]+(1LL<<i)+bi>=(1LL<<(i+1))-1) {
                            dp[i][1][0][1] = max(dp[i][1][0][1], dp[i-1][0][j][1]+(1LL<<i));
                            fin = false;
                        }
                    }
                }
            }
            if (fin) break;
            res = max(res, i+1);
        }
        cout << res << endl;
    }
    return 0;
}
