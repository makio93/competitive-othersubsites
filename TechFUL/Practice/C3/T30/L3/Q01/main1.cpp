// 解説AC

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const ll mod = (ll)(1e9) + 7;
ll modpow(ll a, ll p) {
    ll r = 1, q = a;
    while (p) {
        if (p%2) r = r * q % mod;
        q = q * q % mod;
        p /= 2;
    }
    return r;
}
ll modinv(ll a) {
    return modpow(a, mod-2);
}
vector<ll> fact, ifact, luc, fib;
void cbinit(int n) {
    fact.assign(n+1, 1); ifact.assign(n+1, 1);
    luc.assign(n+1, 0); fib.assign(n+1, 0);
    for (int i=1; i<=n; ++i) {
        fact[i] = fact[i-1] * i % mod;
        ifact[i] = modinv(fact[i]);
    }
    luc[0] = 2;
    luc[1] = 1;
    for (int i=2; i<=n; ++i) luc[i] = (luc[i-1] + luc[i-2]) % mod;
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2; i<=n; ++i) fib[i] = (fib[i-1] + fib[i-2]) % mod;
}
ll cb(ll a, ll b) {
    if (b > a) return 0;
    return fact[a] * ifact[a-b] % mod * ifact[b] % mod;
}

int main() {
    int n, m;
    cin >> n >> m;
    cbinit(n);
    if (n == 0) {
        cout << modinv(m - 1) << endl;
        return 0;
    }
    ll res = m * modinv(modpow(5, n/2)) % mod;
    if (n%2 == 0) {
        ll cval = (n/2%2 == 0) ? 1 : -1;
        ll dval = (((n/2%2 == 0) ? 1 : -1) - m + mod) % mod;
        ll sum = cval * modinv(dval) % mod * cb(n, n/2) % mod;
        for (int i=0; i<=n/2; ++i) {
            ll aval = (i%2 == 0) ? (2 * m % mod) : (mod - 2*m%mod) % mod;
            aval = (aval - luc[n-2*i] + mod) % mod;
            ll bval = (i%2 == 1) ? (m * luc[n-2*i] % mod) : (mod - m*luc[n-2*i]%mod) % mod;
            bval = (bval + (ll)m * m + 1 + mod) % mod;
            ll val = aval * modinv(bval) % mod * cb(n, i) % mod;
            sum = (sum + val) % mod;
        }
        res = res * sum % mod;
    }
    else {
        ll sum = 0;
        for (int i=0; i<=n/2; ++i) {
            ll aval = fib[n-2*i];
            ll bval = (i%2 == 1) ? (m * luc[n-2*i] % mod) : (mod - m*luc[n-2*i]%mod) % mod;
            bval = (bval + (ll)m * m - 1 + mod) % mod;
            ll val = aval * modinv(bval) % mod * cb(n, i) % mod;
            sum = (sum + val) % mod;
        }
        res = res * sum % mod;
    }
    cout << res << endl;
    return 0;
}
