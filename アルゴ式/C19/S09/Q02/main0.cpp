// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, s, k;
    cin >> n >> s >> k;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<int> col(n);
    auto dfs = [&](auto dfs, int vi, int ci=1) -> bool {
        col[vi] = ci;
        for (int ti : g[vi]) if (col[ti]==ci || (col[ti]==0&&!dfs(dfs,ti,-ci))) return false;
        return true;
    };
    dfs(dfs, s);
    int res = 0;
    if (k < n-1) {
        vector<int> dist(n, INF);
        queue<int> que;
        que.push(s);
        dist[s] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi];
            for (int ti : g[vi]) if (dist[ti] == INF) {
                que.push(ti);
                dist[ti] = di + 1;
            }
        }
        for (int i=0; i<n; ++i) if (dist[i]<=k && ((col[i]==col[s])^(k%2==1))) ++res;
    }
    else for (int i=0; i<n; ++i) if ((col[i]==col[s]) ^ (k%2==1)) ++res;
    cout << res << endl;
	return 0;
}
