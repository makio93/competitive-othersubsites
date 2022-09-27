// 自力TLE2

#include <iostream>
#include <map>
using namespace std;

using ll = long long;

int main() {
    int t0;
    cin >> t0;
    for (int i0=0; i0<t0; ++i0) {
        ll ai, bi;
        int ci;
        cin >> ai >> bi >> ci;
        ll sval = ai + bi;
        map<tuple<ll, int, int>, int> memo;
        auto calc = [&](auto calc, ll val, int di=0, int ri=0) -> int {
            if (memo.find({ val, di, ri }) != memo.end()) return memo[{ val, di, ri }];
            int rval = di;
            ll bval = sval - val;
            if (val>=(1LL<<di) && bval>=(1LL<<di)) {
                if (ri >= 0) {
                    if (ri < ci-1) rval = max(rval, calc(calc, val-(1LL<<di), di+1, ri+1));
                    rval = max(rval, calc(calc, val+(1LL<<di), di+1, -1));
                }
                else {
                    if (abs(ri) < ci-1) rval = max(rval, calc(calc, val+(1LL<<di), di+1, ri-1));
                    rval = max(rval, calc(calc, val-(1LL<<di), di+1, 1));
                }
            }
            return memo[{ val, di, ri }] = rval;
        };
        int res = calc(calc, ai);
        cout << res << endl;
    }
    return 0;
}
