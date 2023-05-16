// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, y0, m0, d0, x, y1, m1, d1;
    cin >> a >> b >> c >> y0 >> m0 >> d0 >> x >> y1 >> m1 >> d1;
    int val0 = (y0-1) * a * b + (m0-1) * b + (d0-1), val1 = (y1-1) * a * b + (m1-1) * b + (d1-1);
    --x;
    int sub = val1 - val0, res = (x + sub % c + c) % c + 1;
    cout << res << endl;
	return 0;
}
