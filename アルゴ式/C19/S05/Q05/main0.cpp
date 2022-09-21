// 自力AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<int> visited(n);
    queue<int> que;
    bool res = true;
    for (int i=0; i<n; ++i) if (visited[i] == 0) {
        visited[i] = 1;
        que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int ci = visited[vi], nci = -ci;
            for (int ti : g[vi]) {
                if (visited[ti] == ci) {
                    res = false;
                    break;
                }
                if (visited[ti] == nci) continue;
                visited[ti] = nci;
                que.push(ti);
            }
            if (!res) break;
        }
        if (!res) break;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
