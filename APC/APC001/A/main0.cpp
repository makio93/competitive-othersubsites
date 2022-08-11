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
        int p, q, a, b, c;
        cin >> p >> q >> a >> b >> c;
        unordered_set<int> s;
        bool acom = false, pany = false;
        while (1) {
            bool br = false;
            if (s.find((a*p+b)%c) != s.end()) {
                acom = true;
                br = true;
            }
            if (s.find((a*q+b)%c) != s.end()) {
                pany = true;
                br = true;
            }
            if (br) break;
            s.insert((a*p+b)%c);
            s.insert((a*q+b)%c);
            p = (a*p+b)%c;
            q = (a*q+b)%c;
        }
        if (acom && pany) cout << "Draw" << endl;
        else if (!acom) cout << "Acom" << endl;
        else cout << "Pany" << endl;
    }
    return 0;
}
