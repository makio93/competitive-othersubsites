// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int res = 0;
    for (int i=0; i<30; ++i) {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        int nval = (h2 * 60 + m2) - (h1 * 60 + m1);
        if (nval > 8 * 60) nval -= 60;
        else if (nval > 6 * 60) nval -= 45;
        res += nval;
    }
    cout << (res/60) << ' ' << (res%60) << endl;
	return 0;
}
