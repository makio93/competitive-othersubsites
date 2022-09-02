// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> g(n);
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
    }
    queue<int> que;
    vector<int> pre(n, INF);
    que.push(s);
    pre[s] = -1;
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        for (int ti : g[vi]) if (pre[ti] == INF) {
            que.push(ti);
            pre[ti] = vi;
        }
    }
    vector<int> res;
    int id = t;
    res.push_back(id);
    while (id != s) {
        id = pre[id];
        res.push_back(id);
    }
    reverse(res.begin(), res.end());
    int rlen = res.size();
    cout << rlen << endl;
    for (int i=0; i<rlen; ++i) cout << res[i] << (i<rlen-1?' ':'\n');
	return 0;
}
