// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int sa, ta, sb, tb;
    cin >> sa >> ta >> sb >> tb;
    cout << max(0, min({ ta-sb, tb-sa, ta-sa, tb-sb })) << endl;
	return 0;
}
