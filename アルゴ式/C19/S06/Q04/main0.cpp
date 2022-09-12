// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    auto bfs = [&g](int si) -> int {
        vector<int> dist(g.size(), INF);
        queue<int> que;
        dist[si] = 0;
        que.push(si);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (int& ti : g[vi]) if (dist[ti] > ndi) {
                dist[ti] = ndi;
                que.push(ti);
            }
        }
        return *max_element(dist.begin(), dist.end());
    };
    int res = 0;
    for (int i=0; i<n; ++i) res = max(res, bfs(i));
    cout << res << endl;
	return 0;
}
