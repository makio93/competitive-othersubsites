// 自力AC

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int res = 0;
    for (int i=0; i<n; ++i) {
        if (s[i] == 'f') ++res;
        if (isdigit(s[i])) res += s[i] - '0';
    }
    cout << res << endl;
    return 0;
}
