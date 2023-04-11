// 自力AC

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length(), bcnt = 0, lval = n, rval = 0;
    for (int i=0; i<n; ++i) {
        if (s[i] == '[') ++bcnt;
        else if (s[i] == ']') --bcnt;
        else if (s[i] != '-') {
            lval = min(lval, bcnt);
            rval = max(rval, bcnt);
        }
    }
    cout << (rval-lval) << endl;
    return 0;
}
