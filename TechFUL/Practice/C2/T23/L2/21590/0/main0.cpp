// 本番AC

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> dist(m+1, INF);
    queue<int> que;
    dist[m] = 0;
    que.push(m);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        int di = dist[vi], ndi = di + 1;
        for (int i=0; i<n; ++i) {
            if (a[i] > vi) break;
            int nvi = vi % a[i];
            if (dist[nvi] <= ndi) continue;
            dist[nvi] = ndi;
            que.push(nvi);
        }
    }
    int res = 0;
    for (int i=0; i<=m; ++i) if (dist[i] != INF) ++res;
    cout << res << endl;
    return 0;
}
