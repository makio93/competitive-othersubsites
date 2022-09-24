// 解説AC2

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    auto calc = [&](auto calc, int id=0) -> int {
        if (isdigit(s[id])) return s[id] - '0';
        else return calc(calc, id+2) + 1;
    };
    cout << calc(calc) << endl;
    return 0;
}
