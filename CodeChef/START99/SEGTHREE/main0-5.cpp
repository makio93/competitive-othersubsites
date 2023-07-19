// 自力AC

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
        vector<vector<int>> memo(n, vector<int>(3*3, -1));
        function<int(int, int)> f = [&](int vi, int ri) {
            if (memo[vi][ri] != -1) return memo[vi][ri];
            vector<int> b(3);
            b[0] = (a[vi] + ri / 3 % 3) % 3;
            b[1] = (a[vi+1] + ri % 3) % 3;
            int add = (3 - (b[0] + b[1] + a[vi+2]) % 3) % 3, val = add;
            if (vi == n-3) return memo[vi][ri] = val;
            int rval = f(vi+1, ri%3*3+add);
            return memo[vi][ri] = add + rval;
        };
        rep(i, 3*3) res = min(res, f(0, i) + i/3%3 + i%3);
        cout << res << endl;
    }
    return 0;
}
