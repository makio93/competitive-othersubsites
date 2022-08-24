// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> d(n), sum(n);
    for (int i=1; i<n; ++i) cin >> d[i];
    for (int i=1; i<n; ++i) sum[i] += sum[i-1] + d[i];
    cin >> q;
    for (int i=0; i<q; ++i) {
        int li, ri;
        cin >> li >> ri;
        cout << (sum[ri]-sum[li]) << endl;
    }
	return 0;
}
