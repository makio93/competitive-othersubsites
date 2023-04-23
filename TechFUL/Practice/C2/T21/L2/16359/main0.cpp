// 自力AC

#include <iostream>
#include <vector>
using namespace std;

const int INF = (int)(1.5e9);
struct MinSegTree {
    int n;
    vector<int> dat;
    MinSegTree() { init(1); }
    MinSegTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(1e9));
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return (int)(1e9);
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};
struct MaxSegTree {
    int n;
    vector<int> dat;
    MaxSegTree() { init(1); }
    MaxSegTree(int n_) { init(n_); }
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
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    MinSegTree lst(n);
    MaxSegTree rst(n);
    for (int i=0; i<n; ++i) {
        lst.update(i, a[i]);
        rst.update(i, a[i]);
    }
    cin >> q;
    for (int i=0; i<q; ++i) {
        int qi, xi, yi;
        cin >> qi >> xi >> yi;
        if (qi == 1) {
            --xi;
            int rval = rst.query(xi, yi), lval = lst.query(xi, yi);
            cout << (rval-lval) << endl;
        }
        else {
            --xi; --yi;
            swap(a[xi], a[yi]);
            lst.update(xi, a[xi]);
            rst.update(xi, a[xi]);
            lst.update(yi, a[yi]);
            rst.update(yi, a[yi]);
        }
    }
    return 0;
}
