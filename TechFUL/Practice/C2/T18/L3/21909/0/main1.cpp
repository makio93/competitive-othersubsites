// 解説AC

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

using ll = long long;

const ll mod = 998244353LL;
ll modpow(ll p, ll t) {
    if (!t) return 1;
    ll a = modpow(p, t>>1);
    a = a * a % mod;
    if (t&1) a = a * p % mod;
    return a;
}
ll inv(ll p) { return modpow(p, mod-2); }
vector<ll> fact, ifact;
void init(int n) {
    fact.resize(n+1, 0);
    ifact.resize(n+1, 0);
    fact[0] = 1;
    for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i % mod;
    ifact[n] = inv(fact[n]);
    for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i % mod;
}
ll comb(int n, int k) {
    if (k<0 || k>n) return 0;
    return (fact[n] * ifact[k] % mod * ifact[n-k]) % mod;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    init(2*n+1);
    vector<int> aids;
    for (int i=0; i<n; ++i) if (a[i] != -1) aids.push_back(i);
    int alen = aids.size();
    ll res = 0;
    vector<unordered_map<int, ll>> dp;
    for (int k=0; k<=n; ++k) {
        ll val = 0;
        if (alen == 0) val = (val + comb(n, n-k)) % mod;
        else {
            dp.assign(alen, unordered_map<int, ll>());
            int r11 = a[aids[0]]*2-1, r12 = (k-a[aids[0]]) * 2;
            int p11 = r11 / 2, p12 = r12 / 2;
            if (r11>=0 && r11<=k*2) dp[0][r11] = (dp[0][r11] + comb(aids[0], p11)) % mod;
            if (r12>=0 && r12<=k*2) dp[0][r12] = (dp[0][r12] + comb(aids[0], p12)) % mod;
            for (int i=0; i<alen-1; ++i) {
                int l21 = a[aids[i]]*2-1, l22 = (k-a[aids[i]]) * 2;
                int r21 = a[aids[i+1]]*2-1, r22 = (k-a[aids[i+1]]) * 2;
                int p21l = (l21+1)/2, p21r = r21/2, p22l = l22/2, p22r = r22/2;
                for (const pair<int, int>& lp : { make_pair(l21, p21l), make_pair(l22, p22l) }) if (lp.first>=0 && lp.first<=2*k)
                    for (const pair<int, int>& rp : { make_pair(r21, p21r), make_pair(r22, p22r) }) if (rp.first>=0 && rp.first<=2*k && rp.first>=lp.first)
                        dp[i+1][rp.first] = (dp[i+1][rp.first] + dp[i][lp.first] * comb(aids[i+1]-aids[i]-1, rp.second-lp.second) % mod) % mod;
            }
            int l31 = a[aids[alen-1]]*2-1, l32 = (k-a[aids[alen-1]])*2;
            int p31 = k - (l31+1)/2, p32 = k - l32/2;
            if (l31>=0 && l31<=2*k) val = (val + dp[alen-1][l31] * comb(n-aids[alen-1]-1, p31) % mod) % mod;
            if (l32>=0 && l32<=2*k) val = (val + dp[alen-1][l32] * comb(n-aids[alen-1]-1, p32) % mod) % mod;
        }
        res = (res + val) % mod;
        dp.clear();
    }
    cout << res << endl;
    return 0;
}
