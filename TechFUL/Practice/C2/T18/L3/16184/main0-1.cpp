// 自力WA1

#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int t0;
    cin >> t0;
    for (int i0=0; i0<t0; ++i0) {
        ll ai, bi;
        int ci;
        cin >> ai >> bi >> ci;
        int res = 0;
        ll x = 1;
        if (ai < bi) swap(ai, bi);
        while (1) {
            ll nsub = 0;
            int scnt = 0;
            while (scnt+1<ci && ai>=(nsub|x)) {
                nsub |= x;
                ++scnt;
                x <<= 1;
            }
            if (scnt == 0) break;
            ai -= nsub;
            bi += nsub;
            res += scnt;
            swap(ai, bi);
        }
        cout << res << endl;
    }
    return 0;
}
