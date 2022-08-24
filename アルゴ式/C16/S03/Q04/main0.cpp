// 自力AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << ((ll)sum*sum) << endl;
	return 0;
}
