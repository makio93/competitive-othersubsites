// 解説,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
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
    int t0;
    cin >> t0;
    combination cb((int)(1.5e6)+5);
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ui, vi;
            cin >> ui >> vi;
            --ui; --vi;
            g[ui].push_back(vi);
            g[vi].push_back(ui);
        }
        vector<int> asum(n), chs(n);
        function<void(int, int)> dfs0 = [&](int vi, int pi) {
            asum[vi] += a[vi];
            for (const int& ti : g[vi]) if (ti != pi) {
                dfs0(ti, vi);
                asum[vi] += a[ti];
                chs[vi]++;
            }
        };
        dfs0(0, -1);
        function<pair<mint, ll>(int, int)> dfs1 = [&](int vi, int pi) {
            if (asum[vi] == 0) return make_pair(mint(1), 0LL);
            if (chs[vi] == 0) return make_pair(mint(1), (ll)(a[vi]+1));
            mint val1 = 1, den = cb.ifact[a[vi]];
            ll val2 = 0;
            for (const int& ti : g[vi]) if (ti != pi) {
                auto tval = dfs1(ti, vi);
                val1 *= tval.first;
                val2 += tval.second;
                den *= cb.ifact[tval.second];
            }
            val1 *= cb.fact[val2+a[vi]] * den;
            val2 += a[vi] + 1;
            return make_pair(val1, val2);
        };
        auto rval = dfs1(0, -1);
        cout << rval.first.x << endl;
    }
    return 0;
}
