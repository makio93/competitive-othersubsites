// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; ++i) cin >> s[i];
    int res = 0;
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) if (s[i][j] == '#') {
        ++res;
        queue<pair<int, int>> que;
        que.emplace(i, j);
        s[i][j] = '.';
        while (!que.empty()) {
            auto pi = que.front(); que.pop();
            int vi = pi.first, vj = pi.second;
            for (int i2=0; i2<4; ++i2) {
                int ni = vi + di[i2], nj = vj + dj[i2];
                if (ni<0 || ni>=h || nj<0 || nj>=w || s[ni][nj]=='.') continue;
                que.emplace(ni, nj);
                s[ni][nj] = '.';
            }
        }
    }
    cout << res << endl;
	return 0;
}
