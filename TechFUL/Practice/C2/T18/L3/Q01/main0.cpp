// 自力AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k), c(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<k; ++i) cin >> b[i];
    for (int i=0; i<n; ++i) cin >> c[i];
    vector<int> dp(k+1, -1);
    dp[0] = 0;
    for (int i=0; i<n; ++i) for (int j=k; j>=0; --j) 
        if (dp[j]!=-1 && j+a[i]<=k) dp[j+a[i]] = max(dp[j+a[i]], dp[j]+1);
    int res = 0;
    for (int i=0; i<=k; ++i) if (dp[i] > 0) res = max(res, b[i-1]+c[dp[i]-1]);
    cout << res << endl;
    return 0;
}
