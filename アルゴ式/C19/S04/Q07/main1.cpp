// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; ++i) cin >> s[i];
    vector<vector<int>> g(h*w);
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) if (s[i][j] == '#') {
        int vi = i * w + j;
        for (int i2=0; i2<4; ++i2) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=h || nj<0 || nj>=w || s[ni][nj]=='.') continue;
            int nvi = ni * w + nj;
            g[vi].push_back(nvi);
        }
    }
    vector<bool> visited(h*w);
    int res = 0;
    auto dfs = [&](auto dfs, int vi) -> void {
        visited[vi] = true;
        for (int ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
    };
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) if (s[i][j]=='#' && !visited[i*w+j]) {
        ++res;
        dfs(dfs, i*w+j);
    }
    cout << res << endl;
	return 0;
}
