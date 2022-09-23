// 自力AC

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i) cin >> a[i] >> b[i];
    int lval = 0, rval = (int)(1e8);
    while (rval-lval > 1) {
        int cval = lval + (rval-lval) / 2;
        vector<vector<int>> g(n);
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            if ((ll)(a[i]-a[j])*(a[i]-a[j])+(ll)(b[i]-b[j])*(b[i]-b[j]) <= (ll)(cval*2)*(cval*2)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        vector<bool> finished(n), visited(n);
        auto dfs = [&](auto dfs, int vi, int pi=-1) -> bool {
            visited[vi] = true;
            for (const int& ti : g[vi]) if (ti!=pi && !finished[ti]) {
                if (visited[ti] || dfs(dfs,ti,vi)) return true;
            }
            finished[vi] = true;
            return false;
        };
        bool ok = false;
        for (int i=0; i<n; ++i) if (!finished[i]) {
            if (dfs(dfs, i)) {
                ok = true;
                break;
            }
        }
        if (ok) rval = cval;
        else lval = cval;
    }
    cout << (lval+1) << endl;
    return 0;
}
