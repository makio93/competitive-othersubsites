// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<char> tar = { 'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O' };

int main() {
    string s;
    cin >> s;
    for (char& ci : s) {
        if (find(tar.begin(), tar.end(), ci) != tar.end()) {
            if (isupper(ci)) ci = '#';
            else ci = '?';
        }
        else if (isupper(ci)) ci = '!';
    }
    cout << s << endl;
	return 0;
}
