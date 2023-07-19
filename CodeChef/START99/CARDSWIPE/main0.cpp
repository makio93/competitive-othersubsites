// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
            cin >> a[i];
            a[i]--;
        }
        int res = 0, val = 0;
        vector<bool> check(n);
        rep(i, n) {
            check[a[i]] = !check[a[i]];
            if (check[a[i]]) ++val;
            else --val;
            res = max(res, val);
        }
        cout << res << endl;
    }
    return 0;
}
