// 学習1回目,解説AC

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;

ll modpow(ll a, ll b) {
    ll p = 1, q = a;
    for (int i=0; i<63; ++i) {
        if (b & (1LL<<i)) p = p * q % mod;
        q = q * q % mod;
    }
    return p;
}
ll modinv(ll a) { return modpow(a, mod-2); }

vector<ll> fact, ifact, fib, luc;
void init(int n) {
    fib.assign(n+1, 0); luc.assign(n+1, 0);
    for (int i=0; i<=n; ++i) {
        if (i == 0) fib[i] = 0;
        else if (i == 1) fib[i] = 1;
        else if (i == 2) fib[i] = 1;
        else fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }
    for (int i=0; i<=n; ++i) {
        if (i == 0) luc[i] = 2;
        else if (i == 1) luc[i] = 1;
        else luc[i] = (luc[i-1] + luc[i-2]) % mod;
    }
    fact.assign(n+1, 0); ifact.assign(n+1, 0);
    for (int i=0; i<=n; ++i) {
        if (i == 0) fact[i] = 1;
        else fact[i] = fact[i-1] * i % mod;
    }
    for (int i=n+1; i>=1; --i) {
        if (i-1 == n) ifact[n] = modinv(fact[n]);
        else ifact[i-1] = ifact[i] * i % mod;
    }
}
ll choose(int n, int k) {
    if (k<0 || k>n) return 0;
    return (fact[n] * ifact[k] % mod * ifact[n-k]) % mod;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    ll res = 0;
    if (n%2 == 0) {
        for (int i=0,sk=1; i<=n/2; ++i,sk*=-1) {
            ll aval = (m * luc[n-2*i] % mod + (-2 * sk + mod) % mod) % mod * choose(n, i) % mod;
            ll bval = (m * (ll)m % mod - (m * (ll)sk + mod) % mod * luc[n-2*i] % mod + mod + 1) % mod;
            res = (res + aval * modinv(bval) % mod) % mod;
        }
        int sp = (n/2%2 == 0) ? 1 : -1;
        ll cval = choose(n, n/2) % mod * modinv((sp+mod-m+mod)%mod) % mod;
        res = (res + cval) % mod;
        res = res * modinv(modpow(5, n/2)) % mod;
    }
    else {
        for (int i=0,sk=1; i<=n/2; ++i,sk*=-1) {
            ll aval = fib[n-2*i] * choose(n, i) % mod;
            ll bval = (m * (ll)m % mod - (m * (ll)sk + mod) % mod * luc[n-2*i] % mod + mod * 2 - 1) % mod;
            res = (res + aval * modinv(bval) % mod) % mod;
        }
        res = res * m % mod * modinv(modpow(5, n/2)) % mod;
    }
    cout << res << endl;
    return 0;
}
