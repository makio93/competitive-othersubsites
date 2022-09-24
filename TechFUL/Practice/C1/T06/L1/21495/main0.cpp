// 自力AC

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int res = (s[0] - '0') - count(s.begin(), s.end(), '1');
    cout << res << endl;
    return 0;
}
