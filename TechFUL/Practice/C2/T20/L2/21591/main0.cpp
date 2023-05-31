// 学習1回目,自力AC

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

const int INF = (int)(1e9);

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
    int n;
    cin >> n;
    vector<int> p(n, -1);
    vector<vector<int>> g(n);
    for (int i=1; i<n; ++i) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }
    vector<int> in(n), out(n), depth(n);
    int id = 0;
    function<void(int,int,int)> dfs = [&](int vi, int pi, int di) {
        depth[vi] = di;
        in[vi] = id++;
        for (const int& ti : g[vi]) if (ti != pi) dfs(ti, vi, di+1);
        out[vi] = id++;
    };
    dfs(0, -1, 0);
    SegmentTree st(n*2);
    for (int i=0; i<n; ++i) {
        st.update(in[i], depth[i]);
        st.update(out[i], depth[i]);
    }
    int res = st.query(0, 2*n);
    for (int i=1; i<n; ++i) {
        int mval = st.query(in[i], out[i]+1) - depth[i] + 1;
        mval = max(mval, st.query(0, in[i]));
        mval = max(mval, st.query(out[i]+1, n*2));
        res = min(res, mval);
    }
    cout << res << endl;
    return 0;
}
