// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<char> tar = { '.', 'o', 'x' };

int main() {
    vector<int> x(8);
    for (int i=0; i<8; ++i) cin >> x[i];
    vector<string> res(8, string(8, '.'));
    for (int i=0; i<8; ++i) for (int j=0; j<16; j+=2) res[i][7-j/2] = tar[(x[i]>>j)%4];
    for (int i=0; i<8; ++i) cout << res[i] << endl;
	return 0;
}
