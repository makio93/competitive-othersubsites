// 解説AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1);
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
    vector<int> alst = a;
    for (int i=0; i<n; ++i) alst.push_back(-a[i]);
    sort(alst.begin(), alst.end());
    alst.erase(unique(alst.begin(), alst.end()), alst.end());
    int alen = alst.size();
    vector<SegmentTree> dp(k*2+1, SegmentTree(alen));
    for (int i=0; i<n; ++i) {
        vector<int> tvals = { (int)(lower_bound(alst.begin(), alst.end(), a[i]) - alst.begin()), 
            (int)(lower_bound(alst.begin(), alst.end(), -a[i]) - alst.begin()) };
        vector<int> mvals = { 0, 0 };
        for (int j=0; j<k*2+1; ++j) {
            for (int i2=0; i2<2; ++i2) mvals[i2] = max(mvals[i2], dp[j].query(0, tvals[i2]));
            dp[j].update(tvals[j%2], mvals[j%2]+1);
        }
    }
    int res = 0;
    for (int i=0; i<k*2+1; ++i) res = max(res, dp[i].query(0, alen));
    cout << res << endl;
    return 0;
}
