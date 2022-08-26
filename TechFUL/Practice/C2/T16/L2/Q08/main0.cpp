// 自力AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), b(n);
    for (int i=0; i<n; ++i) cin >> x[i] >> b[i];
    vector<pair<int, int>> xb(n);
    for (int i=0; i<n; ++i) xb[i] = { x[i], b[i] };
    sort(xb.begin(), xb.end());
    ll nid = xb[0].first + (ll)xb[0].second;
    for (int i=1; i<n; ++i) {
        if (xb[i].first <= nid) nid += xb[i].second;
        else nid = xb[i].first + (ll)xb[i].second;
    }
    cout << nid << endl;
    return 0;
}
