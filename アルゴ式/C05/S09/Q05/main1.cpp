// 解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int res = 0;
    for (int i=0; i<n; ++i) if (x&(1<<i)) ++res;
    cout << res << endl;
	return 0;
}
