// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

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
    auto bfs = [&](int si) -> pair<int, int> {
        vector<int> dist(n, n);
        queue<int> que;
        dist[si] = 0;
        que.push(si);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int ndi = dist[vi] + 1;
            for (const int& ti : g[vi]) {
                if (dist[ti] <= ndi) continue;
                dist[ti] = ndi;
                que.push(ti);
            }
        }
        pair<int, int> mval = { -1, -1 };
        for (int i=0; i<n; ++i) mval = max(mval, { dist[i], i });
        return mval;
    };
    auto pval = bfs(0);
    pval = bfs(pval.second);
    cout << ((pval.first+1)/2) << endl;
	return 0;
}
