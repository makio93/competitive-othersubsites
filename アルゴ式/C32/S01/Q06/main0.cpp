// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> fc;
    for (int i=0; i<n; ++i) {
        string fi;
        int ci;
        cin >> fi >> ci;
        fc[fi] = ci;
    }
    int res = 0;
    for (int i=0; i<m; ++i) {
        string xi;
        cin >> xi;
        res += fc[xi];
    }
    cout << res << endl;
	return 0;
}
