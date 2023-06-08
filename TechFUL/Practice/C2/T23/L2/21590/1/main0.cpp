// 学習1回目,自力AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> dp(m+1);
    int res = 0;
    dp[m] = true;
    for (int i=m; i>=0; --i) if (dp[i]) {
        ++res;
        for (int j=0; j<n; ++j) {
            if (a[j] > i) break;
            dp[i%a[j]] = true;
        }
    }
    cout << res << endl;
    return 0;
}
