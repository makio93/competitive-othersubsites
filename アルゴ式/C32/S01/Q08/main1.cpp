// 解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int nval = n, res = n;
    while (nval >= m) {
        nval = nval - m + 1;
        ++res;
    }
    cout << res << endl;
	return 0;
}
