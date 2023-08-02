// 学習2回目,自力AC(ヒント有)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    combination cb(n*2+1);
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int mval = max(0, *max_element(a.begin(), a.end()));
    vector<int> aids;
    for (int i=0; i<n; ++i) if (a[i] != -1) aids.push_back(i);
    int m = aids.size();
    mint res = 0;
    for (int i=mval; i<=n; ++i) {
        int len = i * 2 + 1;
        if (aids.empty()) {
            res += cb(n, i);
            continue;
        }
        vector<mint> dp(len);
        dp[0] = 1;
        {
            vector<int> llst = { 0 }, rlst = { a[aids[0]]*2-1, (i-a[aids[0]])*2 };
            if (rlst[0] == rlst[1]) rlst.pop_back();
            unordered_map<int, mint> ndp;
            for (const int& lv : llst) for (const int& rv : rlst) if (rv >= 0) {
                if (lv > rv || (lv%2 == 1 && lv==rv)) continue;
                int vcnt = rv / 2 - (lv + 1) / 2;
                if (aids[0] < vcnt) continue;
                ndp[rv] += dp[lv] * cb(aids[0], vcnt);
            }
            dp[len-1] = 0;
            for (const int& rv : rlst) if (rv >= 0) dp[rv] = ndp[rv];
        }
        for (int j=0; j<m-1; ++j) {
            vector<int> llst = { a[aids[j]]*2-1, (i-a[aids[j]])*2 }, rlst = { a[aids[j+1]]*2-1, (i-a[aids[j+1]])*2 };
            if (llst[0] == llst[1]) llst.pop_back();
            if (rlst[0] == rlst[1]) rlst.pop_back();
            sort(llst.rbegin(), llst.rend());
            unordered_map<int, mint> ndp;
            for (const int& lv : llst) if (lv >= 0) for (const int& rv : rlst) if (rv >= 0) {
                if (lv > rv || (lv%2 == 1 && lv==rv)) continue;
                int vcnt = rv / 2 - (lv + 1) / 2;
                if (aids[j+1]-aids[j]-1 < vcnt) continue;
                ndp[rv] += dp[lv] * cb(aids[j+1]-aids[j]-1, vcnt);
            }
            dp[len-1] = 0;
            for (const int& rv : rlst) if (rv >= 0) dp[rv] = ndp[rv];
        }
        {
            vector<int> llst = { a[aids[m-1]]*2-1, (i-a[aids[m-1]])*2 }, rlst = { len-1 };
            if (llst[0] == llst[1]) llst.pop_back();
            sort(llst.rbegin(), llst.rend());
            unordered_map<int, mint> ndp;
            for (const int& lv : llst) if (lv >= 0) for (const int& rv : rlst) {
                if (lv > rv || (lv%2 == 1 && lv==rv)) continue;
                int vcnt = rv / 2 - (lv + 1) / 2;
                if (n-aids[m-1]-1 < vcnt) continue;
                ndp[rv] += dp[lv] * cb(n-aids[m-1]-1, vcnt);
            }
            dp[len-1] = 0;
            for (const int& rv : rlst) if (rv >= 0) dp[rv] = ndp[rv];
        }
        res += dp[len-1];
    }
    cout << res.x << endl;
    return 0;
}
