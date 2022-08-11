// 解説AC

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
    int res = 0;
    for (int i=0; i<n; ++i) if (dist[i]<=k && dist[i]%2==k%2) ++res;
    cout << res << endl;
	return 0;
}
