// 自力AC

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), b(n);
    for (int i=0; i<n; ++i) cin >> x[i] >> b[i];
    map<int, int> xlst;
    for (int i=0; i<n; ++i) {
        xlst[x[i]-b[i]]++;
        xlst[x[i]+b[i]+1]--;
    }
    int nval = 0, li = INF, res = 0;
    for (const auto& pi : xlst) {
        nval += pi.second;
        if (nval == n) { if (li == INF) li = pi.first; }
        else if (li != INF) {
            res = pi.first - li;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
