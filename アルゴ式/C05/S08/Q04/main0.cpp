// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<char> PC = { 'o', 'g', 'u' }, QC = { 'x', 'w', 'r' };

int main() {
    string x;
    char p, q;
    cin >> x >> p >> q;
    int pid = find(PC.begin(), PC.end(), p) - PC.begin(), qid = find(QC.begin(), QC.end(), q) - QC.begin();
    if ((x[pid]-'0') & (1<<qid)) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
