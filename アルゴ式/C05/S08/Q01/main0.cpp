// 

#include <bits/stdc++.h>
using namespace std;

const vector<string> dlst = { "1110111", "0100100", "1011101", "1101101", 
    "0101110", "1101011", "1111011", "0100111", "1111111", "1101111" };


int main() {
    int n;
    cin >> n;
    cout << bitset<7>(dlst[n]).to_ulong() << endl;
	return 0;
}
