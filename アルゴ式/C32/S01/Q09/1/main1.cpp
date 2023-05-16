// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, y0, m0, d0, x, y1, m1, d1;
    cin >> a >> b >> c >> y0 >> m0 >> d0 >> x >> y1 >> m1 >> d1;
    function<int(int,int,int)> days = [a,b,c](int yi, int mi, int di) {
        return (yi-1) * a * b + (mi-1) * b + (di-1);
    };
    int val0 = days(y0, m0, d0), val1 = days(y1, m1, d1);
    --x;
    int sub = val1 - val0, res = (x + sub % c + c) % c + 1;
    cout << res << endl;
	return 0;
}
