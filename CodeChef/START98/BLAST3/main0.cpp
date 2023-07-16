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
        int n;
        string s;
        cin >> n >> s;
        if (n%3 == 1) cout << "YES" << endl;
        else if (n%3 == 2) {
            vector<int> ccnt(26);
            repr(i, n) if (i%3 == 1) ccnt[s[i]-'a']++;
            bool res = false;
            for (int i=0; i<n; i+=3) {
                if (ccnt[s[i]-'a'] > 0) {
                    res = true;
                    break;
                }
                ccnt[s[i+1]-'a']--;
            }
            if (res) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            vector<int> ccnt0(26), ccnt2(26);
            repr(i, n) if (i%3 == 2) ccnt2[s[i]-'a']++;
            bool res = false;
            for (int i=1; i<n; i+=3) {
                ccnt0[s[i-1]-'a']++;
                rep(j, 26) if (ccnt0[j]>0 && ccnt2[j]>0) {
                    res = true;
                    break;
                }
                if (res) break;
                ccnt2[s[i+1]-'a']--;
            }
            if (res) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
