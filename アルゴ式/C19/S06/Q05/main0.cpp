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
    vector<int> dist1(n, INF), dist2(n, INF);
    auto bfs = [&g](int si, vector<int>& dist) -> void {
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
    };
    bfs(0, dist1);
    int nid = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    bfs(nid, dist2);
    int res = *max_element(dist2.begin(), dist2.end());
    cout << res << endl;
	return 0;
}
