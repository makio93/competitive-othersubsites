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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int av = a*2 + b, bv = x*2 + y;
    if (av > bv) cout << "Messi" << endl;
    else if (av < bv) cout << "Ronaldo" << endl;
    else cout << "Equal" << endl;
    return 0;
}
