// バチャ本番AC

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
        vector<int> abc(3);
        rep(i, 3) cin >> abc[i];
        bool ok = false;
        rep(i, 3) {
            int b = abc[i], a = 1;
            rep(j, 3) if (j != i) a *= abc[j];
            if (a%b == 0) {
                cout << a << ' ' << b << endl;
                ok = true;
                break;
            }
        }
        if (!ok) cout << -1 << endl;
    }
    return 0;
}
