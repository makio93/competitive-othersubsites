// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<int> deg(n);
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[bi].insert(ai);
        deg[ai]++;
    }
    vector<int> ord;
    queue<int> que;
    for (int i=0; i<n; ++i) if (deg[i] == 0) que.push(i);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        ord.push_back(vi);
        for (const int& ti : g[vi]) {
            deg[ti]--;
            if (deg[ti] == 0) que.push(ti);
        }
    }
    reverse(ord.begin(), ord.end());
    for (int i=0; i<n; ++i) cout << ord[i] << (i<n-1?' ':'\n');
	return 0;
}
