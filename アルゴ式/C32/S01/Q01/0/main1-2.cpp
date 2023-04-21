// 解説AC2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int sa, ta, sb, tb;
    cin >> sa >> ta >> sb >> tb;
    cout << max(0, min(ta,tb)-max(sa,sb)) << endl;
	return 0;
}
