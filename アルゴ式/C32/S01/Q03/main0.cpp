// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<string> col = { "Black", "White" };

int main() {
    int h, w, p, q;
    cin >> h >> w >> p >> q;
    cout << col[(p+q)%2] << endl;
	return 0;
}
