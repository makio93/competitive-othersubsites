// 本番WA

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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
            cin >> a[i];
            a[i]--;
        }
        string s(n, 'a');
        bool ok = true;
        rep(i, n) {
            if (i-1 >= 0) {
                while (s.substr(a[i]) < s.substr(a[i-1])) {
                    if (s[a[i]] == 'z') {
                        ok = false;
                        break;
                    }
                    s[a[i]]++;
                }
                if (!ok) break;
            }
        }
        if (ok) cout << s << endl;
        else cout << -1 << endl;
    }
    return 0;
}
