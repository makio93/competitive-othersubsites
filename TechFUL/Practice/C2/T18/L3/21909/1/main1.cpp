// 学習1回目,解説AC

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll mod = 998244353LL;
struct mint {
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
struct combination {
    vector<mint> fact, ifact;
    combination(int n) : fact(n+1), ifact(n+1) {
        fact[0] = 1;
        for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k<0 || k>n) return 0;
        return (fact[n] * ifact[k] * ifact[n-k]);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<vector<mint>> dp(n+2, vector<mint>(n*2+1));
    combination cb(n*2+1);
    mint res = 0;
    for (int k=0; k<=n; ++k) {
        dp[0][0] = 1;
        int li = 0;
        vector<int> lids, rids;
        lids.push_back(0);
        while (li < n+1) {
            int ri = li + 1;
            while (ri<n+1 && a[ri-1]==-1) ++ri;
            if (ri == n+1) rids.push_back(k*2);
            else {
                if (a[ri-1]*2-1>=1 && a[ri-1]*2-1<=k*2-1) rids.push_back(a[ri-1]*2-1);
                if (2*k-a[ri-1]*2>=0 && 2*k-a[ri-1]*2<=2*k) rids.push_back(2*k-a[ri-1]*2);
            }
            for (const int& lid : lids) for (const int& rid : rids) if (rid >= lid) dp[ri][rid] = 0;
            for (const int& lid : lids) for (const int& rid : rids) if (rid >= lid) {
                int aval = (rid/2*2 - (lid+1)/2*2) / 2 + 1, bval = aval - 1;
                dp[ri][rid] += dp[li][lid] * cb(ri-li-1, bval);
            }
            li = ri;
            swap(lids, rids);
            rids.clear();
        }
        res += dp[n+1][k*2];
    }
    cout << res.x << endl;
    return 0;
}
