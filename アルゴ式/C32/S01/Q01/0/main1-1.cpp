// 解説AC1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int sa, ta, sb, tb;
    cin >> sa >> ta >> sb >> tb;
    int res = 0;
    for (int i=0; i<100; ++i) if (i>=sa && i>=sb && i<ta && i<tb) ++res;
    cout << res << endl;
	return 0;
}
