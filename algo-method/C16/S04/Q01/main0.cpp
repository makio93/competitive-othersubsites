// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n), sum(n+1);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) sum[i+1] += sum[i] + a[i];
    cin >> q;
    for (int i=0; i<q; ++i) {
        int ki;
        cin >> ki;
        cout << sum[ki] << endl;
    }
    return 0;
}
