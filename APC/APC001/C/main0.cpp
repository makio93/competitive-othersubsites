// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, k;
        cin >> n >> k;
        vector<ll> p(n);
        rep(i, n) cin >> p[i];
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }
        vector<ll> vals;
        function<ll(int,int)> dfs = [&](int vi, int pi) -> ll {
            vector<ll> dres;
            for (int ti : g[vi]) if (ti != pi) {
                ll tres = dfs(ti, vi);
                dres.push_back(tres);
            }
            if (dres.empty()) {
                if (vi == 0) vals.push_back(p[vi]);
                return p[vi];
            }
            else {
                sort(dres.rbegin(), dres.rend());
                ll rval = dres[0] + p[vi];
                rep3(i, 1, (int)(dres.size())) vals.push_back(dres[i]);
                if (vi == 0) vals.push_back(rval);
                return rval;
            }
        };
        dfs(0, -1);
        sort(vals.rbegin(), vals.rend());
        int rlen = vals.size(), rcnt = min(rlen, k+1);
        ll res = 0;
        rep(i, rcnt) res += vals[i];
        cout << res << endl;
    }
    return 0;
}
