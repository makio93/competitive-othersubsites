// 自力AC

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n*4);
    for (int i=0; i<n*4; ++i) cin >> a[i];
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    k = b.size();
    function<int(int)> pids = [&](int pval) {
        return lower_bound(b.begin(), b.end(), pval) - b.begin();
    };
    vector<int> lcnt(1<<k), rcnt(1<<k);
    for (int i=0; i<1<<(n*2); ++i) if (__builtin_popcount(i) == n) {
        int bi = 0;
        for (int j=0; j<n*2; ++j) if ((i>>j)&1) bi |= 1 << pids(a[j]);
        lcnt[bi]++;
    }
    for (int i=0; i<1<<(n*2); ++i) if (__builtin_popcount(i) == n) {
        int bi = 0;
        for (int j=0; j<n*2; ++j) if ((i>>j)&1) bi |= 1 << pids(a[2*n+j]);
        rcnt[bi]++;
    }
    int res = 0;
    for (int i=0; i<1<<k; ++i) for (int j=0; j<1<<k; ++j) if ((i&j) == 0) res += lcnt[i] * rcnt[j];
    cout << res << endl;
    return 0;
}
