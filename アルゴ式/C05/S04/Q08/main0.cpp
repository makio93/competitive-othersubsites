// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, q;
    cin >> n >> s >> q;
    for (int i=0; i<q; ++i) {
        int qi, x;
        cin >> qi >> x;
        if (qi == 0) s |= 1<<x;
        else if (qi == 1) s &= ~(1<<x);
        else {
            if ((s>>x)&1) cout << "on" << endl;
            else cout << "off" << endl;
        }
    }
	return 0;
}
