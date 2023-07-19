// 本番WA1

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
        rep(i, n) cin >> a[i];
        int res = INF;
        rep(i, 3) {
            auto b = a;
            int val = 0, btmp = b[0] + b[1] + b[2];
            b[i] += (3 - btmp % 3) % 3;
            val += (3 - btmp % 3) % 3;
            rep3(j, 3, n) {
                btmp = b[j] + b[j-1] + b[j-2];
                b[j] += (3 - btmp % 3) % 3;
                val += (3 - btmp % 3) % 3;
            }
            res = min(res, val);
        }
        cout << res << endl;
    }
    return 0;
}
