// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int y0, m0, d0, x;
    cin >> y0 >> m0 >> d0 >> x;
    int y1, m1, d1;
    cin >> y1 >> m1 >> d1;
    int val0 = y0 * a * b + m0 * b + d0, val1 = y1 * a * b + m1 * b + d1;
    int res = (x + (val1 - val0) % c + c) % c;
    if (res == 0) res += c;
    cout << res << endl;
	return 0;
}
