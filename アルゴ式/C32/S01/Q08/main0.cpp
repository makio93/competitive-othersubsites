// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int res = n;
    while (n >= m) {
        res += n / m;
        n = n / m + n % m;
    }
    cout << res << endl;
	return 0;
}
