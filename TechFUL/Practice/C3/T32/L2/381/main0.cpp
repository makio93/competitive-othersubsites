// 自力AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n), x(n), y(n), vx(n), vy(n);
    for (int i=0; i<n; ++i) cin >> s[i];
    for (int i=0; i<n; ++i) cin >> x[i];
    for (int i=0; i<n; ++i) cin >> y[i];
    for (int i=0; i<n; ++i) cin >> vx[i];
    for (int i=0; i<n; ++i) cin >> vy[i];
    vector<int> res(n);
    for (int i=0; i<n; ++i) {
        int dx = vx[i] - x[i], dy = vy[i] - y[i];
        for (int j=0; j<n; ++j) if (s[i] != s[j]) {
            int tx = x[j] - x[i], ty = y[j] - y[i];
            if (dx*ty-dy*tx > 0) res[i]++;
        }
    }
    for (int i=0; i<n; ++i) cout << res[i] << endl;
    return 0;
}
