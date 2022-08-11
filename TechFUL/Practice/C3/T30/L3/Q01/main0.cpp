// 自力WA

#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

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

int main() {
    int n, m;
    cin >> n >> m;
    double tar = pow((1.0+sqrt(5.0))/2.0, (double)n);
    double mt = floor(tar / (double)mod) * mod + m;
    if (mt <= tar) mt += mod;
    mint fib = 1, pf1 = 0, pf2 = 0;
    double dfib = 1.0, dpf1 = 0.0, dpf2 = 0.0;
    mint res = 0;
    int ri = 1;
    while (abs(pow(dfib,(double)n)/pow(mt,(double)ri)) > 1e-9) {
        res += mint(fib).pow(n) / mint(m).pow(ri);
        pf2 = pf1; pf1 = fib; fib = pf1 + pf2;
        dpf2 = dpf1; dpf1 = dfib; dfib = dpf1 + dpf2;
        ++ri;
    }
    cout << res.x << endl;
    return 0;
}
