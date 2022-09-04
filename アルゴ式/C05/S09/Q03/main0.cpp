// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i=0; i<k; ++i) cin >> v[i];
    int res = 0;
    for (int i=0; i<k; ++i) res |= (1 << v[i]);
    cout << res << endl;
	return 0;
}
