// 学習1回目,自力AC

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n), x(n), y(n), vx(n), vy(n);
    for (int i=0; i<n; ++i) cin >> s[i];
    for (int i=0; i<n; ++i) cin >> x[i];
    for (int i=0; i<n; ++i) cin >> y[i];
    for (int i=0; i<n; ++i) cin >> vx[i];
    for (int i=0; i<n; ++i) cin >> vy[i];
    for (int i=0; i<n; ++i) {
        int res = 0;
        for (int j=0; j<n; ++j) if (s[i]!=s[j] && cross(vx[i]-x[i],vy[i]-y[i],x[j]-x[i],y[j]-y[i])>0) ++res;
        cout << res << endl;
    }
    return 0;
}
