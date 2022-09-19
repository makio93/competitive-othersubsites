// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<string> tar = { "Fizz", "Buzz" };

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        string str;
        if (i%4 == 0) str += tar[0];
        if (i%6 == 0) str += tar[1];
        if (!str.empty()) cout << str << endl;
        else cout << i << endl;
    }
	return 0;
}
