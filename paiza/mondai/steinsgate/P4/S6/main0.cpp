// 自力AC

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i=0; i<m; ++i) {
        int si, ti;
        cin >> si >> ti;
        --si; --ti;
        if (si != ti) g[si].push_back(ti);
    }
    vector<bool> visited(n), finished(n);
    auto dfs = [&](auto dfs, int vi) -> bool {
        visited[vi] = true;
        for (int ti : g[vi]) {
            if (visited[ti]) {
                if (finished[ti]) continue;
                else return false;
            }
            else if (!dfs(dfs, ti)) return false;
        }
        finished[vi] = true;
        return true;
    };
    bool res = false;
    for (int i=0; i<n; ++i) if (!finished[i]) {
        if (!dfs(dfs, i)) {
            res = true;
            break;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
