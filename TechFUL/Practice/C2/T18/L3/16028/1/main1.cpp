// 学習1回目,解説AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)(2e9);
struct SegmentTree {
    int n;
    vector<int> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, 0);
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return 0;
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<int> dict;
    for (int i=0; i<n; ++i) {
        dict.push_back(a[i]);
        dict.push_back(-a[i]);
    }
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());
    int m = dict.size();
    vector<SegmentTree> dp(2*k+1, SegmentTree(m));
    for (int i=0; i<n; ++i) for (int j=2*k; j>=0; --j) {
        int val = j % 2 == 0 ? a[i] : -a[i], id = lower_bound(dict.begin(), dict.end(), val) - dict.begin();
        dp[j].update(id, max(dp[j].query(0, id)+1, dp[j].query(id, id+1)));
        if (j-1 < 0) continue;
        dp[j].update(id, max(dp[j-1].query(0, id)+1, dp[j].query(id, id+1)));
    }
    int res = 0;
    for (int i=0; i<2*k+1; ++i) res = max(res, dp[i].query(0, m));
    cout << res << endl;
    return 0;
}
