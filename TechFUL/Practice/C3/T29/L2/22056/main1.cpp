// 解説AC

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
    int n, m;
    cin >> n >> m;
    combination cb(max(n, m));
    vector<vector<mint>> dp(n+1, vector<mint>(m+1));
    dp[0][0] = 1;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
        dp[i][j] += dp[i-1][j-1] * (m-j+1);
        dp[i][j] += dp[i-1][j] * j;
    }
    mint res = 0;
    for (int i=1; i<=m; ++i) {
        if (i == n) res += dp[n][i] * (mint(i).pow(n) - cb.fact[n] + 1);
        else res += dp[n][i] * mint(i).pow(n);
    }
    cout << res.x << endl;
    return 0;
}
