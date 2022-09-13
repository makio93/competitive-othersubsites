// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    for (int i=0; i<n; ++i) cin >> w[i];
    int res = INF;
    for (int i=1; i<1<<n; ++i) {
        vector<bool> used(26);
        for (int j=0; j<n; ++j) if (i&(1<<j)) for (char& ci : w[j]) used[ci-'a'] = true;
        if (find(used.begin(), used.end(), false) == used.end()) res = min(res, __builtin_popcount(i));
    }
    cout << (res==INF ? -1 : res) << endl;
	return 0;
}
