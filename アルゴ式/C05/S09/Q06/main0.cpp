// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, q;
    cin >> n >> x >> q;
    for (int i=0; i<q; ++i) {
        int qi, vi;
        cin >> qi >> vi;
        if (qi == 0) x |= 1 << vi;
        else if (qi == 1) x &= ~(1 << vi);
        else {
            if (x & (1<<vi)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
	return 0;
}
