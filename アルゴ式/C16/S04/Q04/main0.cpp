// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> x(n), sum(n+1);
    for (int i=0; i<n; ++i) cin >> x[i];
    for (int i=0; i<n; ++i) sum[i+1] = sum[i] + x[i];
    pair<int, int> mval = { -1, -1 };
    for (int i=0; i+d<=n; ++i) mval = max(mval, { sum[i+d]-sum[i], i });
    cout << mval.second << '~' << (mval.second+d-1) << endl;
	return 0;
}
