// 解説AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    array<int, 2> mval = { 0, 0 };
    for (int i=0; i<n; ++i) {
        int aval = a[i];
        for (int j=0; j<2; ++j) if (mval[j] < aval) swap(mval[j], aval);
    }
    cout << mval[1] << endl;
	return 0;
}
