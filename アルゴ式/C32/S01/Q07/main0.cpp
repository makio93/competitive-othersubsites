// 自力AC

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }

int main() {
    string s;
    cin >> s;
    int cid = s.find('/'), ni = stoi(s.substr(0, cid)), di = stoi(s.substr(cid+1)), g = gcd(ni, di);
    ni /= g;
    di /= g;
    cout << ni << '/' << di << endl;
	return 0;
}
