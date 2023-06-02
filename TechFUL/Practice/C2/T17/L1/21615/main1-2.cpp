// 解説AC2

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    ll bsum = accumulate(b.begin(), b.end(), 0LL), res = -LINF;
    int si = bsum > 0 ? n - 1 : 0;
    for (int i=0; i<n; ++i) {
        int qi = i, pi = si;
        if (qi == pi) {
            if (pi + 1 < n) ++pi;
            else --pi;
        }
        res = max(res, a[pi]*bsum+(ll)m*a[qi]); 
    }
    cout << res << endl;
    return 0;
}
