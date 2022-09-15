// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> dr = { 0, -1, 0, 1, 0 }, dc = { 0, 0, 1, 0, -1 };

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; ++i) cin >> s[i];
    bool res = false;
    for (int i=0; i<1<<(h*w); ++i) {
        auto t = s;
        for (int j=0; j<h*w; ++j) if (i&(1<<j)) {
            int ri = j / w, ci = j % w;
            for (int i2=0; i2<5; ++i2) {
                int nr = ri + dr[i2], nc = ci + dc[i2];
                if (nr<0 || nr>=h || nc<0 || nc>=w) continue;
                t[nr][nc] = (t[nr][nc] == '#') ? '.' : '#';
            }
        }
        bool ok = true;
        for (int j=0; j<h; ++j) if (t[j] != string(w, '.')) {
            ok = false;
            break;
        }
        if (ok) {
            res = true;
            break;
        }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
