// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> dlst = { stoi("1110111", NULL, 2), stoi("0100100", NULL, 2), stoi("1011101", NULL, 2),
    stoi("1101101", NULL, 2), stoi("0101110", NULL, 2), stoi("1101011", NULL, 2), stoi("1111011", NULL, 2),
    stoi("0100111", NULL, 2), stoi("1111111", NULL, 2), stoi("1101111", NULL, 2) };

int main() {
    int n, m;
    cin >> n >> m;
    cout << (dlst[n]^dlst[m]) << endl;
	return 0;
}
