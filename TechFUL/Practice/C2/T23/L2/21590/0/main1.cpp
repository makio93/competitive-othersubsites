// 解説AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<bool> dp(m+1);
    dp[m] = true;
    for (int i=0; i<n; ++i) for (int j=m; j>=0; --j) dp[j%a[i]] = dp[j%a[i]] || dp[j];
    cout << count(dp.begin(), dp.end(), true) << endl;
    return 0;
}
