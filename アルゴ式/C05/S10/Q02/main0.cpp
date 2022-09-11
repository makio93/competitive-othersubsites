// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
	cin >> n >> v;
	vector<int> a(n);
	for (int i=0; i<n; ++i) cin >> a[i];
	bool res = false;
	for (int i=1; i<1<<n; ++i) {
		int sum = 0;
		for (int j=0; j<n; ++j) if (i&(1<<j)) sum += a[j];
		if (sum == v) {
			res = true;
			break;
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
